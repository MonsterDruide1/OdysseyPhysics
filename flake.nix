{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
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
          libx11
          libxrandr
          libxinerama
          libxcursor
          libxi
          libffi
          pkgs.wayland
          pkgs.wayland-scanner
          pkgs.libxkbcommon
          pkgs.libGL

          rustToolchain
          (python313.withPackages (python-pkgs: [
            python-pkgs.toml
            python-pkgs.gymnasium
          ]))
          openssl
          libclang
          ncurses5
        ];
        LD_LIBRARY_PATH = "${pkgs.lib.makeLibraryPath buildInputs}";
        LIBCLANG_PATH = "${pkgs.libclang.lib}/lib";
      };
    };
  };
}
