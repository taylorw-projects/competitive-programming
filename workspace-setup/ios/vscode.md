# Visual Studio Code Setup

## build keybinds
Enter the following in your `keybindings.json`:
```json
[
    {
        "key": "ctrl+cmd+c",
        "command": "workbench.action.toggleCenteredLayout"
    },
    {
        "key": "ctrl+cmd+shift+alt+c",
        "command": "workbench.action.terminal.sendSequence",
        "args": {
            "text": "g++ -std=c++17 -O2 -Wall ${file} -o ${fileBasenameNoExtension}.exe\r"
        }
    },
    {
        "key": "ctrl+cmd+shift+alt+o",
        "command": "workbench.action.terminal.sendSequence",
        "args": {
            "text": "./${fileBasenameNoExtension}.exe > output.txt\r"
        }
    },
    {
        "key": "ctrl+cmd+shift+alt+r",
        "command": "workbench.action.terminal.sendSequence",
        "args": {
            "text": "./${fileBasenameNoExtension}.exe\r"
        }
    },
    {
        "key": "ctrl+cmd+shift+alt+i",
        "command": "workbench.action.terminal.sendSequence",
        "args": {
            "text": "./${fileBasenameNoExtension}.exe < input.txt\r"
        }
    },
    {
        "key": "ctrl+cmd+shift+alt+b",
        "command": "workbench.action.terminal.sendSequence",
        "args": {
            "text": "./${fileBasenameNoExtension}.exe < input.txt > output.txt\r"
        }
    }
]
```

This will bind `super+c, o, r, i, b` to compile, run with output, run, run with input, or both.
Additionally, we will be able to center the view of the editor with `ctrl+cmd+c`. This will
allow us to very quickly build and run our submission without having to manually type out the
optimized build command every time we want to build our submission.

## Extensions
Here's a list of extensions that I use when writing code for competitive programming:

1. Clang-tidy
2. clangd
3. Code Runner
4. Vim (Optional)

When installing `clangd`, the installation may or may not properly install the `clangd` language
server. If it does not install the language server correctly, the following steps will properly
install it and add it to the path:

1. Go to [https://clangd.llvm.org/installation.html] and download the version for the Mac OS X
2. After installation, we will need to add the language server to our path. In the `.zshrc`, add
the following:
```
export PATH="/usr/local/opt/llvm/bin:$PATH"
```
3. Restart VSCode, and the language server should be enabled for our Visual Studio Code client.
