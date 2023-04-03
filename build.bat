{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "build Photoshop plugin",
            "command": "${workspaceFolder}/build.bat",
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
