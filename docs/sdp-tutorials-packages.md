# QNX SDP 8.0 Demos and Tutorials Packages
You can find two optional packages with QNX SDP 8.0: 
* **QNX SDP 8.0 Screen Demos and Tutorials Source Code**: com.qnx.qnx800.target.screen.demos_tutorials.source
* **QNX SDP 8.0 WFD-Server Demos and Tutorials Source Code**: com.qnx.qnx800.target.screen.wfd_server.demos_tutorials.source

This packages contains source code of C program demos. You can install them with the following command:

```bash
$HOME/qnx/qnxsoftwarecenter/qnxsoftwarecenter_ctl -installPackage com.qnx.qnx800.target.screen.demos_tutorials.source,com.qnx.qnx800.target.screen.wfd_server.demos_tutorials.source -myqnx.user $QNX_USER -myqnx.password $QNX_PASSWORD
```

## QNX SDP 8.0 Screen Demos and Tutorials Source Code
This package contains several demos and tutorials related to the [**QNX Screen Graphics Subsystem**](https://www.qnx.com/developers/docs/7.0.0/index.html#com.qnx.doc.screen/topic/manual/cscreen_about.html) (lists below). To access to this files you will need to uncompress an archive file first.

```bash
cd $HOME/qnx/qnx800/source
tar xvf src-screen-examples-4.0.2.tgz
code src
```

### Demos

| Name          | Description |
|---------------|-------------|
| gles2-gears   | The ```gles2-gears``` binary is a command-line tool that can be used to confirm that screen is running, and that all necessary drivers for OpenGL ES 2.x are in place, and can start successfully ([ref.](https://www.qnx.com/developers/docs/8.0/com.qnx.doc.screen/topic/manual/gles2-gears.html)).<br><br>Included in the [Raspberry Pi 4 QNX 8.0 Quick Start Target Image](https://gitlab.com/qnx/quick-start-images/raspberry-pi-qnx-8.0-quick-start-image#included-samples). |
| sharewin      | The ```sharewin``` binary is a command-line application that demonstrates how to share content between windows. This application creates five windows. However, only four windows are visible, and these four windows each share the window buffer of the remaining invisible window ([ref.](https://www.qnx.com/developers/docs/8.0/com.qnx.doc.screen/topic/manual/sharewin.html)).<br><br>Included in the [Raspberry Pi 4 QNX 8.0 Quick Start Target Image](https://gitlab.com/qnx/quick-start-images/raspberry-pi-qnx-8.0-quick-start-image), but not documented. |
| vcapture-demo | Demo application for video capture. |
| vkcube        | The ```vkcube``` binary is a command-line tool that confirms that Vulkan is running on Screen and has all the necessary drivers. It demonstrates Vulkan's 3D rendering by displaying a rotating cube ([ref.](https://www.qnx.com/developers/docs/8.0/com.qnx.doc.screen/topic/manual/vkcube.html)).<br><br>Included in the [Raspberry Pi 4 QNX 8.0 Quick Start Target Image](https://gitlab.com/qnx/quick-start-images/raspberry-pi-qnx-8.0-quick-start-image#included-samples). |

### Tutorials

| Name          | Description |
|---------------|-------------|
| events        | The ```events``` binary is used to demonstrate how events are handled ([ref.](https://www.qnx.com/developers/docs/8.0/com.qnx.doc.screen/topic/manual/events_binary.html)).<br><br>Included in the [Raspberry Pi 4 QNX 8.0 Quick Start Target Image](https://gitlab.com/qnx/quick-start-images/raspberry-pi-qnx-8.0-quick-start-image), but not documented. |
| sw-vsync      | The sw-vsync binary is a command-line tool that can be used to confirm that screen is running, and software rendering can be used ([ref.](https://www.qnx.com/developers/docs/8.0/com.qnx.doc.screen/topic/manual/sw-vsync.html)).<br><br>Included in the [Raspberry Pi 4 QNX 8.0 Quick Start Target Image](https://gitlab.com/qnx/quick-start-images/raspberry-pi-qnx-8.0-quick-start-image), but not documented. |
| win-manager   | The ```win-manager``` binary demonstrates basic functinalities that a window manager must support ([ref.](https://www.qnx.com/developers/docs/7.0.0/index.html#com.qnx.doc.screen/topic/manual/win-manager.html)). |
| win-vsync     | The ```win-vsync``` binary is a command-line application that demonstrates using multiple windows in a hierarchy ([ref.](https://www.qnx.com/developers/docs/8.0/com.qnx.doc.screen/topic/manual/win-vsync.html)).<br><br>Included in the [Raspberry Pi 4 QNX 8.0 Quick Start Target Image](https://gitlab.com/qnx/quick-start-images/raspberry-pi-qnx-8.0-quick-start-image), but not documented.

## QNX SDP 8.0 WFD-Server Demos and Tutorials Source Code

This package contains several demos related to the **OpenWF Display Server** (lists below). To access to this files you will need to uncompress an archive file first.

```bash
cd $HOME/qnx/qnx800/source
tar xvf src-wfd-server-examples-4.0.2.tgz
code src
```

| Name          | Description |
|---------------|-------------|
| wfd-demo      | Demo application that uses wfd-server to initialize display and show an image/animation. |
| wfd-power-mode | Demo application that sets a power mode on a port (ensure graphics.conf enables power control). |
| wfd-screenshot | Demo application that uses wfd-server to write the contents of a port to memory and write out as a bmp file. |
| wfd-server-info | Provides the information about the configuration of the the WFD system. |
| wfd-writeback | Demo application that uses wfd-server to writeback contents of a port to memory. |