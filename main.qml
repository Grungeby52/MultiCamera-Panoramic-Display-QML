// Copyright (C) 2020 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

import QtQuick
import QtQuick3D
import QtQuick3D.Effects
import QtQuick3D.Helpers
import QtQuick.Controls
import QtQuick.Layouts
Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Quick Items Example")

    SplitView {
        id: splitView
        anchors.fill: parent

        View3D {
            width: 1920
            height: 1080
            anchors.fill: parent
            SplitView.fillHeight: true
            SplitView.fillWidth: true
            SplitView.minimumWidth: splitView.width * 0.5
            environment: SceneEnvironment {
                property bool enableEffects: false
                antialiasingMode: SceneEnvironment.MSAA
                antialiasingQuality: SceneEnvironment.High
                id: sceneEnv
                lightProbe: Texture {

                }
                effects: enableEffects ? [bloom, scurveTonemap] : []
                backgroundMode: SceneEnvironment.SkyBox
                SCurveTonemap {
                    id: scurveTonemap
                }
                HDRBloomTonemap {
                    id: bloom
                }
            }

            OrbitCameraController {
                origin: originNode
                camera: cameraNode
            }
            Node {
                id: originNode

                PerspectiveCamera {
                    id: cameraNode
                    z: 600
                    clipNear: 1
                    clipFar: 10000
                    eulerRotation.y: 0

                }
            }

            DirectionalLight {
                eulerRotation: Qt.vector3d(-135, -110, 0)
                brightness: 1
            }

            SpotLight {
                position: Qt.vector3d(0, 500, 600)
                eulerRotation.x: -45
                brightness: 30
            }


            // Cameras //
            Node {
                position: Qt.vector3d(0, 0, 0)
                eulerRotation.y: 0

                Item {
                    width: 640
                    height: 480
                    anchors.centerIn: parent
                    Image{
                        id: opencvImage
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                        property bool counter: false
                        visible: true
                        source: "image://live_0/image"
                        asynchronous: false
                        cache: false

                        function reload()
                        {
                            counter = !counter
                            source = "image://live_0/image?id=" + counter
                        }
                    }
                }
            }

            Node {
                position: Qt.vector3d(595, 0, 160)
                eulerRotation.y: -30

                Item {
                    width: 640
                    height: 480
                    anchors.centerIn: parent

                    Image{
                        id: opencvImage2
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                        property bool counter: false
                        visible: true
                        source: "image://live_0/image"
                        asynchronous: false
                        cache: false

                        function reload()
                        {
                            counter = !counter
                            source = "image://live_0/image?id=" + counter
                        }

                    }
                }
            }

            Node {
                position: Qt.vector3d(-595, 0, 160)
                eulerRotation.y: 30

                Item {
                    width: 640
                    height: 480
                    anchors.centerIn: parent

                    Image{
                        id: opencvImage3
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                        property bool counter: false
                        visible: true
                        source: "image://live_0/image"
                        asynchronous: false
                        cache: false

                        function reload()
                        {
                            counter = !counter
                            source = "image://live_0/image?id=" + counter
                        }

                    }
                }
            }

            Node {
                position: Qt.vector3d(-1000, 0, 600)
                eulerRotation.y: 60

                Item {
                    width: 640
                    height: 480
                    anchors.centerIn: parent

                    Image{
                        id: opencvImage4
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                        property bool counter: false
                        visible: true
                        source: "image://live_0/image"
                        asynchronous: false
                        cache: false

                        function reload()
                        {
                            counter = !counter
                            source = "image://live_0/image?id=" + counter
                        }

                    }
                }
            }

            Node {
                position: Qt.vector3d(1000, 0, 600)
                eulerRotation.y: -60

                Item {
                    width: 640
                    height: 480
                    anchors.centerIn: parent

                    Image{
                        id: opencvImage5
                        anchors.fill: parent
                        fillMode: Image.PreserveAspectFit
                        property bool counter: false
                        visible: true
                        source: "image://live_0/image"
                        asynchronous: false
                        cache: false

                        function reload()
                        {
                            counter = !counter
                            source = "image://live_0/image?id=" + counter
                        }

                    }
                }
            }

            Connections{
                target: liveImageProvider_0

                function onImageChanged()
                {
                    opencvImage.reload()
                    opencvImage2.reload()
                    opencvImage3.reload()
                    opencvImage4.reload()
                    opencvImage5.reload()

                    console.log("--------")

                }

            }
            Slider {
                       id: slider
                       from: 0
                       to: 360
                       value: 0
                       stepSize: 1
                       width: 1000

                       // Sliderın değeri değiştiğinde yapılacak işlem
                       onValueChanged: {
                           cameraNode.eulerRotation.y = cameraNode.eulerRotation.y + slider.value
                       }
            }
        }
    }
}
