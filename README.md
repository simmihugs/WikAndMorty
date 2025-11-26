# Wik(i) and Morty

This is a little project to start understand how to use 
Qt and [rickandmortyapi](https://rickandmortyapi.com/) for 
a simple galerie and perhabs wiki for characters form rick 
and morty show.

## Todos
UI Loading and Disabling Interaction
How to show a loading indicator/spinner (QProgressDialog, QMovie with GIF, or QBusyIndicator in QtQuick)

How to disable UI elements or the whole window during loading (setEnabled(false) on widgets or using an overlay)

Using asynchronous network requests and updating UI on completion signals

Displaying Character Tiles
How to show an image and title together in a tile-like widget (custom widget combining QLabel for text and images)

Loading images from URLs asynchronously (QNetworkAccessManager or QPixmap::loadFromData)

Layout managers (QVBoxLayout, QHBoxLayout, QGridLayout) for arranging tiles and other widgets

UI Navigation and Pages
Page switching inside your window (QStackedWidget or similar) for toggling between preview and full wiki page

Using scrollable views (QScrollArea) to display long wiki pages or text content

Handling button clicks for navigation (signal and slots)

User Input and Search
Input forms and buttons (QLineEdit and QPushButton)

Connecting search button signals to your search logic

Displaying search results dynamically (could reuse the tile widget)
