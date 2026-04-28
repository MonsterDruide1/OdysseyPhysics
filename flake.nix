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
      devShells.default = pkgs.pkgsCross.aarch64-multiplatform.stdenv.mkDerivation {
    name = "cross-dev";
        nativeBuildInputs = with pkgs; [
          cmake
          ninja
          rustToolchain
          (python313.withPackages (python-pkgs: [
            python-pkgs.toml
            python-pkgs.gymnasium
          ]))
        ];

        buildInputs = with pkgs; [
          pkgsCross.aarch64-multiplatform.libx11
          pkgsCross.aarch64-multiplatform.libXrandr
          pkgsCross.aarch64-multiplatform.libXinerama
          pkgsCross.aarch64-multiplatform.libXcursor
          pkgsCross.aarch64-multiplatform.libXi
          pkgsCross.aarch64-multiplatform.libffi
          pkgsCross.aarch64-multiplatform.openssl
          pkgsCross.aarch64-multiplatform.libGL
          pkgsCross.aarch64-multiplatform.wayland
          pkgsCross.aarch64-multiplatform.libxkbcommon
          pkgsCross.aarch64-multiplatform.glibc
          pkgsCross.aarch64-multiplatform.linuxHeaders
        ];

        shellHook = ''
          unset LD_LIBRARY_PATH
        '';
        /*buildInputs = with pkgs; [
          cmake
          ninja
          #clang
          #llvmPackages_20.clang-unwrapped
          pkgsCross.aarch64-multiplatform.pkg-config
          pkgsCross.aarch64-multiplatform.binutils
          pkgsCross.aarch64-multiplatform.libx11
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

          pkgsCross.aarch64-multiplatform.buildPackages.gcc
          pkgsCross.aarch64-multiplatform.glibc
          #pkgsCross.aarch64-multiplatform.stdenv
          pkgsCross.aarch64-multiplatform.glibc.dev
          pkgsCross.aarch64-multiplatform.linuxHeaders
        ];
        LD_LIBRARY_PATH = "${pkgs.lib.makeLibraryPath buildInputs}";
        LIBCLANG_PATH = "${pkgs.libclang.lib}/lib";*/
      };
    };
  };
}
