{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.11";
    flake-parts.url = "github:hercules-ci/flake-parts";
    systems.url = "github:nix-systems/default";
    rust-overlay.url = "github:oxalica/rust-overlay";
  };

  outputs = inputs: inputs.flake-parts.lib.mkFlake { inherit inputs; } {
    systems = import inputs.systems;
    perSystem = { config, self', inputs', pkgs, system, ... }: let
      overlays = [ (import inputs.rust-overlay) ];
      pkgs = import inputs.nixpkgs {
        inherit system overlays;
      };
      rustToolchain = pkgs.pkgsBuildHost.rust-bin.fromRustupToolchainFile ./rust-toolchain.toml;
    in {
      _module.args.pkgs = import inputs.nixpkgs {
        config.allowUnfree = true;
      };
      devShells.default = pkgs.mkShell rec {
        buildInputs = with pkgs; [
          cmake
          ninja
          clang
          pkg-config
          xorg.libX11
          xorg.libXrandr
          xorg.libXinerama
          xorg.libXcursor
          xorg.libXi
          libffi
          pkgs.wayland
          pkgs.libxkbcommon
          pkgs.libGL

          rustToolchain
          (python3.withPackages (python-pkgs: [
            python-pkgs.toml
            python-pkgs.gymnasium
          ]))
          openssl
          libclang
          ncurses5
          ncurses6
        ];
        LD_LIBRARY_PATH = "${pkgs.lib.makeLibraryPath buildInputs}";
        LIBCLANG_PATH = "${pkgs.libclang.lib}/lib";
      };
    };
  };
}
