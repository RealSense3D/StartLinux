import QtQuick 2.0

Item {
    id: root
    width: bg.width; height: bg.height
    Image{
        id: bg
        source: "assets/black-bg.png"
    }

    Column{
        id: column
        spacing: 8
        anchors.centerIn: parent
        MySquare{  }
        MySquare{
            color: "green"
            width: 96
        }
        MySquare{
            color: "blue"
        }
        MySquare{
            color: "white"
            width: 48 * 3
        }
    }

    Row{
        id: row
        spacing: 8
//        anchors.centerIn: parent
        anchors.top: column.bottom
        MySquare{  }
        MySquare{
            color: "green"
            width: 96
        }
        MySquare{
            color: "blue"
        }
        MySquare{
            color: "white"
            width: 48 * 3
        }
    }
    Grid{
        id: grid
        columns: 2
//        rows: 2
//        layoutDirection: Qt.RightToLeft
        columnSpacing: 8
        rowSpacing: 8
        anchors.left: column.right
        anchors.top: column.top
        MySquare{  }
        MySquare{
            color: "green"
            width: 96
        }
        MySquare{
            color: "blue"
        }
        MySquare{
            color: "orange"
        }
        MySquare{
            color: "white"
            width: 20
            height: 48 * 3 + 8
        }
    }

    Flow{
        id: flow
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20
        MySquare{  }
        MySquare{
            color: "green"
            width: 96
        }
        MySquare{
            color: "blue"
        }
        MySquare{
            color: "orange"
        }
    }
}
