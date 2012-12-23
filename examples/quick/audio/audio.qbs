import qbs.base 1.0
import "../QuickExample.qbs" as QuickExample

QuickExample {
    type: "application"
    destination: "examples/audio"

    files: [
        appViewerPath + "main.cpp"
    ]

    Group {
        fileTags: "install"
        qbs.installPrefix: destination
        files: "qml"
    }
}