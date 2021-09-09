# Symboli Loader

> _Eclipse first, the rest nowhere._

Symboli Loader is the generic plugin loader on Windows mimicking as `version.dll`.

## Build

Open `symboli_loader.sln` and build it.
Of course you can use `msbuild` :

```bat
MSBuild -p:Configuration=Release
```

## Usage

1. Put Symboli Loader binary (`version.dll`) on DLL search directory.
1. Create the directory named `symboli_loader` next to Symboli Loader binary (`version.dll`).
1. Create the directory named same as execution binary you want to custom under the `symboli_loader` directory.
1. Put your plugins with `.symboli` extension.

As an example, the file layout is as follows:

- `C:\example\`
    - `binary.exe`
    - `version.dll` (Symboli Loader)
    - `symboli_loader\`
        - `binary.exe\` (This is directory named as same as the execution binary)
            - `plugin.symboli`

## License

MIT
