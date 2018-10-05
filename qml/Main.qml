import QtQuick 2.4
import QtQuick.Layouts 1.1
import Ubuntu.Components 1.3
import FarkleBackend 1.0

MainView {
    id: root
    objectName: 'mainView'
    applicationName: 'farkle.arc676'
    automaticOrientation: true

    width: units.gu(45)
    height: units.gu(75)

    Page {
        anchors.fill: parent

        header: PageHeader {
            id: header
            title: i18n.tr('Farkle')
        }

        Column {
            id: dieColumn
	    width: parent.width / 3
	    anchors {
	    	top: header.bottom
		left: parent.left
	    }

	    Row {
	    	id: dieRow
		spacing: 10

		Column {
		    id: leftDieColumn
		    spacing: 10

		    Image {
		    	source: "dice/1.png"
		    }

		    Image {
		    	source: "dice/2.png"
		    }

		    Image {
		    	source: "dice/3.png"
		    }
		}

		Column {
		    id: rightDieColumn
		    spacing: 10

		    Image {
		    	source: "dice/4.png"
		    }

		    Image {
		    	source: "dice/5.png"
		    }

		    Image {
		    	source: "dice/6.png"
		    }
		}
	    }
        }

        Column {
            id: controlsColumn
	    width: parent.width / 3
	    anchors {
	    	top: header.bottom
		left: dieColumn.right
	    }

	    Button {
	    	id: rollButton
		width: parent.width
		text: i18n.tr('Roll')
		onClicked: FarkleBackend.startGame(1, 1)
	    }

	    Button {
	    	id: selButton
		width: parent.width
		text: i18n.tr('Confirm selection')
		onClicked: FarkleBackend.confirmSelection()
	    }

	    Button {
	    	id: bankButton
		width: parent.width
		text: i18n.tr('Bank')
		onClicked: FarkleBackend.bank()
	    }

	    ListView {
	    	id: selectionsTable
		width: parent.width
	    }
        }

        Column {
            id: leaderboardColumn
	    width: parent.width / 3
	    anchors {
	    	top: header.bottom
		left: controlsColumn.right
	    }

	    ListView {
	    	id: leaderboardTable
		width: parent.width
	    }
        }
    }
}
