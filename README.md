# Artemis Qt

[Artemis Qt](https://github.com/wjbeckett/artemis) is an enhanced cross-platform client for NVIDIA GameStream and [Apollo](https://github.com/ClassicOldSong/Apollo)/[Sunshine](https://github.com/LizardByte/Sunshine) servers. It brings the advanced features from [Artemis Android](https://github.com/ClassicOldSong/moonlight-android) to desktop platforms.

## 🙏 Attribution

Artemis Qt is built upon the excellent foundation of [**Moonlight Qt**](https://github.com/moonlight-stream/moonlight-qt) by the [Moonlight Team](https://github.com/moonlight-stream). We extend our sincere gratitude to the original developers for creating such a robust and well-architected streaming client.

**Key Credits:**
- **Core streaming technology** - [Moonlight Qt](https://github.com/moonlight-stream/moonlight-qt)
- **Enhanced features inspiration** - [Artemis Android](https://github.com/ClassicOldSong/moonlight-android) by [ClassicOldSong](https://github.com/ClassicOldSong)
- **Server compatibility** - [Apollo](https://github.com/ClassicOldSong/Apollo) and [Sunshine](https://github.com/LizardByte/Sunshine) projects

[![Build Status](https://github.com/wjbeckett/artemis/workflows/Build%20Artemis%20Qt/badge.svg)](https://github.com/wjbeckett/artemis/actions)
[![Downloads](https://img.shields.io/github/downloads/wjbeckett/artemis/total)](https://github.com/wjbeckett/artemis/releases)

## 💖 Support the Project

If you find Artemis Qt useful and want to support continued development, you can:

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/wjbeckett)

Your support helps cover development time, testing on multiple platforms, and keeping the project maintained. Every contribution, no matter how small, is greatly appreciated! 🙏

**Other ways to support:**
- ⭐ **Star the repository** to show your appreciation
- 🐛 **Report bugs** and help improve the experience for everyone
- 🔄 **Share Artemis** with other gamers and streamers
- 💻 **Contribute code** or documentation improvements

## ✨ Artemis Features

Artemis Qt includes all the features of Moonlight Qt, plus these enhanced capabilities:

### 🎯 Phase 1 (Foundation) - Complete
- **📋 Clipboard Sync** - Seamlessly sync clipboard content between client and server - ✅ **COMPLETE**
- **⚡ Server Commands** - Execute custom commands on the Apollo/Sunshine server - ✅ **COMPLETE**
- **🔐 OTP Pairing** - One-Time Password pairing for enhanced security - ✅ **COMPLETE**
- **🎮 Quick Menu** - In-stream overlay menu for easy access to controls - ✅ **COMPLETE**

### 🎮 Phase 2 (Client Controls) - Complete
- **🖥️ Fractional Refresh Rate** - Client-side control for custom refresh rates (e.g., 90Hz, 120Hz) - ✅ **COMPLETE**
- **📐 Resolution Scaling** - Client-side resolution scaling for better performance - ✅ **COMPLETE**
- **🖼️ Virtual Display Control** - Choose whether to use virtual displays - ✅ **COMPLETE**

### 🆕 Phase 3 (UUID & Modern Features) - Complete
- **🆔 UUID-Based App Launching** - Modern app identification system for Apollo/Sunshine servers - ✅ **COMPLETE**
- **🔄 Automatic Fallback** - Seamlessly falls back to legacy app IDs when UUIDs unavailable - ✅ **COMPLETE**
- **🎨 Visual Rebranding** - Official Artemis icons and art:// protocol compatibility with Apollo Android - ✅ **COMPLETE**
- **🚀 Development Builds** - Automated development builds with changelogs for all platforms - ✅ **COMPLETE**

### 🚀 Phase 4 (Advanced) - In Progress
- **📱 App Ordering** - Custom app ordering without compatibility mode
- **🔍 Permission Viewing** - View and manage server-side permissions - ✅ **COMPLETE**
- **🎯 Input-Only Mode** - Stream input without video for remote control scenarios

## 🎮 Perfect for Steam Deck

Artemis Qt is specifically optimized for handheld gaming devices like the Steam Deck:

- **Embedded Mode** - Optimized UI for handheld devices
- **GPU-Optimized Rendering** - Efficient rendering for lower-power GPUs
- **Touch-Friendly Interface** - Designed for touch and gamepad navigation
- **Power Efficient** - Optimized for battery life
- **Gamepad Shortcuts** - Built-in gamepad combinations for quick access to features

## 🎮 Keyboard and Gamepad Shortcuts

### Quick Menu Toggle

**Keyboard:** `Ctrl + Alt + Shift + \`

**Gamepad:** `Select + L1 + R1 + Y`

> **💡 Pro Tip:** The Quick Menu provides instant access to clipboard sync, server commands, streaming controls, and more - all without leaving your game!

### Other Shortcuts

**Keyboard Shortcuts** (All require `Ctrl + Alt + Shift` prefix):
- `\` - **Toggle Quick Menu** (NEW!)
- `Q` - Quit stream
- `E` - Quit stream and exit application
- `S` - Toggle performance stats overlay
- `X` - Toggle fullscreen
- `M` - Toggle mouse capture mode
- `Z` - Toggle input capture
- `C` - Toggle cursor visibility
- `V` - Paste clipboard text
- `L` - Toggle pointer region lock
- `D` - Minimize window

**Gamepad Shortcuts:**
- `Select + L1 + R1 + Y` - **Toggle Quick Menu** (NEW!)
- `Start + Select + L1 + R1` - Quit stream
- `Select + L1 + R1 + X` - Toggle performance stats overlay
- Long press `Start` - Toggle mouse emulation mode

> **Note:** The Quick Menu provides easy access to clipboard sync, server commands, and other streaming controls during your session.

## 📥 Downloads
All downloads are available in [Releases](https://github.com/wjbeckett/artemis/releases) 

### �️ Platform Support

**Windows:**
- **x64 (Intel/AMD)** - Full support with MSI installer and portable ZIP
- **ARM64** - ✨ **NEW!** Native support for Windows on ARM devices (Surface Pro X, Copilot+ PCs, etc.)

**macOS:**
- **Universal Binary** - Native support for both Intel and Apple Silicon Macs

**Linux:**
- **x64 AppImage** - Universal Linux package for x64 systems
- **x64 Flatpak** - Sandboxed package available via Flathub
- **Steam Deck** - Optimized builds for Valve's handheld gaming device

### �🍎 macOS Installation Notes
Development builds may show "Artemis.app is damaged" due to macOS security features. To fix this:

**Option 1 (Recommended):**
```bash
# Remove quarantine attributes
xattr -cr /path/to/Artemis.app
```

**Option 2:**
1. Go to **System Preferences** > **Security & Privacy** > **General**
2. Click **"Allow Anyway"** when prompted about Artemis
3. Try launching the app again

This is normal for development builds and doesn't indicate actual damage to the application.  

> **🔥 Latest Development Features:**
> - **🖥️ Windows ARM64 Support** - Native builds for Windows on ARM devices
> - **🎮 Enhanced Quick Menu** - New keyboard (`Ctrl+Alt+Shift+\`) and gamepad shortcuts (`Select+L1+R1+Y`)
> - Permission viewing from the client
> - Complete Artemis rebranding with official icons and art:// protocol support
> - UUID-based app launching for modern Apollo/Sunshine servers
> - Enhanced error handling and logging
> - Improved compatibility with latest server versions

## 🎮 Moonlight Features (Inherited)
 - Hardware accelerated video decoding on Windows, Mac, and Linux
 - H.264, HEVC, and AV1 codec support (AV1 requires Sunshine and a supported host GPU)
 - YUV 4:4:4 support (Sunshine only)
 - HDR streaming support
 - 7.1 surround sound audio support
 - 10-point multitouch support (Sunshine only)
 - Gamepad support with force feedback and motion controls for up to 16 players
 - Support for both pointer capture (for games) and direct mouse control (for remote desktop)
 - Support for passing system-wide keyboard shortcuts like Alt+Tab to the host

## 🛠️ Building from Source

### Quick Start
```bash
# Clone the repository
git clone https://github.com/wjbeckett/artemis.git
cd artemis

# Run the development setup script
chmod +x scripts/setup-dev.sh
./scripts/setup-dev.sh

# The script will install dependencies and build the project
```

### Manual Build Requirements

#### All Platforms
- **Qt 6.7+** (Qt 6.8+ recommended)
- **FFmpeg 4.0+**
- **SDL2** and **SDL2_ttf**
- **OpenSSL**
- **Opus codec**

#### Platform-Specific Requirements

**Windows:**
- Visual Studio 2022 with MSVC
- 7-Zip (for packaging)

**macOS:**
- Xcode 14+
- Homebrew: `brew install qt6 ffmpeg opus sdl2 sdl2_ttf create-dmg`

**Linux:**
```bash
# Ubuntu/Debian
sudo apt install qt6-base-dev qt6-declarative-dev libqt6svg6-dev \
  qml6-module-qtquick-controls qml6-module-qtquick-templates \
  qml6-module-qtquick-layouts libegl1-mesa-dev libgl1-mesa-dev \
  libopus-dev libsdl2-dev libsdl2-ttf-dev libssl-dev \
  libavcodec-dev libavformat-dev libswscale-dev libva-dev \
  libvdpau-dev libxkbcommon-dev wayland-protocols libdrm-dev

# Fedora/RHEL
sudo dnf install qt6-qtbase-devel qt6-qtdeclarative-devel \
  qt6-qtsvg-devel openssl-devel SDL2-devel SDL2_ttf-devel \
  ffmpeg-devel libva-devel libvdpau-devel opus-devel \
  pulseaudio-libs-devel alsa-lib-devel libdrm-devel
```

### Build Commands
```bash
# Initialize submodules
git submodule update --init --recursive

# Configure and build
qmake6 moonlight-qt.pro CONFIG+=release
make -j$(nproc)  # Linux
make -j$(sysctl -n hw.ncpu)  # macOS
nmake  # Windows
```

## 🎮 Features Comparison

| Feature | Moonlight Qt | Artemis Qt |
|---------|--------------|------------|
| GameStream/Sunshine Support | ✅ | ✅ |
| Hardware Video Decoding | ✅ | ✅ |
| HDR Streaming | ✅ | ✅ |
| 7.1 Surround Sound | ✅ | ✅ |
| Multi-touch Support | ✅ | ✅ |
| **Clipboard Sync** | ❌ | ✅ |
| **Server Commands** | ❌ | ✅ |
| **OTP Pairing** | ❌ | ✅  |
| **Quick Menu** | ❌ | ✅ |
| **Fractional Refresh Rates** | ❌ | ✅ |
| **Resolution Scaling** | ❌ | ✅ |
| **Virtual Display Control** | ❌ | ✅ |
| **UUID-Based App Launching** | ❌ | ✅ |
| **Development Builds** | ❌ | ✅ |
| **Permission Viewing** | ❌ | ✅ |
| **Custom App Ordering** | ❌ | 📋 |
| **Input-Only Mode** | ❌ | 📋 |

Legend: ✅ Available, 🚧 In Development, 📋 Planned

## 🆕 What's New

### Recent Improvements
- **�️ Windows ARM64 Support** - ✨ **NEW!** Native ARM64 builds for Windows on ARM devices (Surface Pro X, Copilot+ PCs)
- **🎮 Enhanced Quick Menu** - Improved keyboard shortcut (`Ctrl+Alt+Shift+\`) and gamepad combo (`Select+L1+R1+Y`)
- **�🔍 Permission Viewing** - View server-side permissions for clients
- **Complete Visual Rebranding** - Official Artemis icons and branding from Apollo developer, art:// protocol support
- **UUID-Based App Launching** - Modern app identification system that works seamlessly with Apollo/Sunshine servers
- **🔄 Smart Fallback System** - Automatically uses legacy app IDs when UUIDs aren't available
- **🔐 OTP Pairing** - Enhanced security with One-Time Password authentication
- **🚀 Automated Development Builds** - Get the latest features with automatic changelogs for all platforms
- **📋 Better Error Handling** - Improved logging and error messages for troubleshooting

### What's Coming Next
- **📱 Custom App Ordering** - Organize your game library exactly how you want
- **🎯 Input-Only Mode** - Remote control without video streaming for lightweight scenarios

### Development Process
We now have **automated development builds** that:
- 🔄 Build automatically on every development push
- 📋 Generate detailed changelogs from commit messages
- 🎯 Support all platforms (Windows, macOS, Linux, AppImage, Flatpak, Steam Deck)
- ⚡ Let you test new features immediately

Want to help test new features? Check out our [development releases](https://github.com/wjbeckett/artemis/releases?q=prerelease%3Atrue)!

## 🤝 Contributing

We welcome contributions! Here's how to get started:

1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature/amazing-feature`
3. **Make your changes** and test thoroughly
4. **Commit your changes**: `git commit -m 'Add amazing feature'`
5. **Push to the branch**: `git push origin feature/amazing-feature`
6. **Open a Pull Request**

### Development Guidelines
- Follow the existing code style
- Add tests for new features
- Update documentation as needed
- Test on multiple platforms when possible

## 🔗 Related Projects

- **[Artemis Android](https://github.com/ClassicOldSong/moonlight-android)** - The original Artemis for Android
- **[Apollo Server](https://github.com/ClassicOldSong/Apollo)** - Enhanced GameStream server
- **[Moonlight Qt](https://github.com/moonlight-stream/moonlight-qt)** - The upstream project
- **[Sunshine](https://github.com/LizardByte/Sunshine)** - Open-source GameStream server

## 📄 License

This project is licensed under the GPL v3 License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **[ClassicOldSong](https://github.com/ClassicOldSong)** - Creator of Artemis Android and Apollo server
- **[Moonlight Team](https://github.com/moonlight-stream)** - For the excellent foundation
- **[LizardByte](https://github.com/LizardByte)** - For the Sunshine server
- **All contributors** who help make this project better

---

**Made with ❤️ for the gaming community**




-------------------------------------
Translated Report (Full Report Below)
-------------------------------------

Process:               Artemis [50263]
Path:                  /Applications/Artemis.app/Contents/MacOS/Artemis
Identifier:            com.artemis_desktop.Artemis
Version:               0.5.6 (0.5.6)
Code Type:             ARM-64 (Native)
Parent Process:        launchd [1]
User ID:               501

Date/Time:             2026-06-12 20:07:40.6779 +0700
OS Version:            macOS 12.3.1 (21E258)
Report Version:        12
Anonymous UUID:        3684DFE2-4AED-594F-AF5D-0F8A722EAF54

Sleep/Wake UUID:       917908B3-666A-46EA-A15C-FF7958F4E359

Time Awake Since Boot: 360000 seconds
Time Since Wake:       45 seconds

System Integrity Protection: enabled

Crashed Thread:        4  Dispatch queue: CA::Context

Exception Type:        EXC_CRASH (SIGABRT)
Exception Codes:       0x0000000000000000, 0x0000000000000000
Exception Note:        EXC_CORPSE_NOTIFY

Application Specific Information:
Artemis(50263,0x16d903000) malloc: Heap corruption detected, free list is damaged at 0x600002010360
*** Incorrect guard value: 36170086411599872
abort() called


Thread 0::  Dispatch queue: com.apple.main-thread
0   libsystem_kernel.dylib        	       0x1ae4d08d0 mach_msg_trap + 8
1   libsystem_kernel.dylib        	       0x1ae4d0d40 mach_msg + 76
2   CoreFoundation                	       0x1ae5dac1c __CFRunLoopServiceMachPort + 372
3   CoreFoundation                	       0x1ae5d90cc __CFRunLoopRun + 1180
4   CoreFoundation                	       0x1ae5d8490 CFRunLoopRunSpecific + 600
5   HIToolbox                     	       0x1b71f8dd8 RunCurrentEventLoopInMode + 292
6   HIToolbox                     	       0x1b71f8b54 ReceiveNextEventCommon + 564
7   HIToolbox                     	       0x1b71f8908 _BlockUntilNextEventMatchingListInModeWithFilter + 72
8   AppKit                        	       0x1b1137b2c _DPSNextEvent + 860
9   AppKit                        	       0x1b1136424 -[NSApplication(NSEvent) _nextEventMatchingEventMask:untilDate:inMode:dequeue:] + 1328
10  AppKit                        	       0x1b11285f0 -[NSApplication run] + 596
11  libqcocoa.dylib               	       0x105bf7adc 0x105be0000 + 96988
12  QtCore                        	       0x106441884 QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) + 596
13  QtCore                        	       0x106438078 QCoreApplication::exec() + 144
14  Artemis                       	       0x10284ff3c main + 8396
15  dyld                          	       0x102d35088 start + 516

Thread 1:
0   libsystem_pthread.dylib       	       0x1ae509078 start_wqthread + 0

Thread 2:: Thread (pooled)
0   libsystem_kernel.dylib        	       0x1ae4d4290 __psynch_cvwait + 8
1   libsystem_pthread.dylib       	       0x1ae50e83c _pthread_cond_wait + 1236
2   QtCore                        	       0x1065ccc28 0x1063a4000 + 2264104
3   QtCore                        	       0x1065ccaa0 QWaitCondition::wait(QMutex*, QDeadlineTimer) + 108
4   QtCore                        	       0x1065c6a64 0x1063a4000 + 2239076
5   QtCore                        	       0x1065be7b4 0x1063a4000 + 2205620
6   libsystem_pthread.dylib       	       0x1ae50e26c _pthread_start + 148
7   libsystem_pthread.dylib       	       0x1ae50908c thread_start + 8

Thread 3:: SDLTimer
0   libsystem_kernel.dylib        	       0x1ae4d4290 __psynch_cvwait + 8
1   libsystem_pthread.dylib       	       0x1ae50e83c _pthread_cond_wait + 1236
2   SDL2                          	       0x102ec8fc8 0x102de4000 + 937928
3   SDL2                          	       0x102e13e30 0x102de4000 + 196144
4   SDL2                          	       0x102e075ec 0x102de4000 + 144876
5   SDL2                          	       0x102e03a38 0x102de4000 + 129592
6   SDL2                          	       0x102e06b6c 0x102de4000 + 142188
7   libsystem_pthread.dylib       	       0x1ae50e26c _pthread_start + 148
8   libsystem_pthread.dylib       	       0x1ae50908c thread_start + 8

Thread 4 Crashed::  Dispatch queue: CA::Context
0   libsystem_kernel.dylib        	       0x1ae4d8db8 __pthread_kill + 8
1   libsystem_pthread.dylib       	       0x1ae50dee0 pthread_kill + 288
2   libsystem_c.dylib             	       0x1ae448340 abort + 168
3   libsystem_malloc.dylib        	       0x1ae32a8c0 malloc_vreport + 552
4   libsystem_malloc.dylib        	       0x1ae33fc84 malloc_zone_error + 100
5   libsystem_malloc.dylib        	       0x1ae31cb70 nanov2_allocate_from_block + 568
6   libsystem_malloc.dylib        	       0x1ae31c18c nanov2_allocate + 128
7   libsystem_malloc.dylib        	       0x1ae31c0a8 nanov2_malloc + 64
8   libsystem_malloc.dylib        	       0x1ae339748 _malloc_zone_malloc + 156
9   CoreFoundation                	       0x1ae576c94 -[__NSArrayM insertObject:atIndex:] + 264
10  QuartzCore                    	       0x1b547277c layer_composited(_CAImageQueue*, void*, unsigned int) + 360
11  QuartzCore                    	       0x1b54725cc CAImageQueueDidComposite + 240
12  QuartzCore                    	       0x1b54724b0 _XImageQueueDidComposite + 52
13  QuartzCore                    	       0x1b54b97b0 invocation function for block in CA::Context::client_port() + 232
14  libdispatch.dylib             	       0x1ae34a1c8 _dispatch_client_callout + 20
15  libdispatch.dylib             	       0x1ae34d670 _dispatch_continuation_pop + 500
16  libdispatch.dylib             	       0x1ae3608e0 _dispatch_source_invoke + 1596
17  libdispatch.dylib             	       0x1ae351784 _dispatch_lane_serial_drain + 376
18  libdispatch.dylib             	       0x1ae352404 _dispatch_lane_invoke + 392
19  libdispatch.dylib             	       0x1ae35cc98 _dispatch_workloop_worker_thread + 648
20  libsystem_pthread.dylib       	       0x1ae50a360 _pthread_wqthread + 288
21  libsystem_pthread.dylib       	       0x1ae509080 start_wqthread + 8

Thread 5:: QQmlThread
0   libsystem_kernel.dylib        	       0x1ae4d8ed0 poll + 8
1   QtCore                        	       0x1065bcd04 qt_safe_poll(pollfd*, unsigned int, QDeadlineTimer) + 76
2   QtCore                        	       0x1065c09c4 QEventDispatcherUNIX::processEvents(QFlags<QEventLoop::ProcessEventsFlag>) + 904
3   QtCore                        	       0x106441884 QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>) + 596
4   QtCore                        	       0x106529594 QThread::exec() + 332
5   QtCore                        	       0x1065be7b4 0x1063a4000 + 2205620
6   libsystem_pthread.dylib       	       0x1ae50e26c _pthread_start + 148
7   libsystem_pthread.dylib       	       0x1ae50908c thread_start + 8

Thread 6:: Thread (pooled)
0   libsystem_kernel.dylib        	       0x1ae4d4290 __psynch_cvwait + 8
1   libsystem_pthread.dylib       	       0x1ae50e83c _pthread_cond_wait + 1236
2   QtCore                        	       0x1065ccc28 0x1063a4000 + 2264104
3   QtCore                        	       0x1065ccaa0 QWaitCondition::wait(QMutex*, QDeadlineTimer) + 108
4   QtCore                        	       0x1065c6a64 0x1063a4000 + 2239076
5   QtCore                        	       0x1065be7b4 0x1063a4000 + 2205620
6   libsystem_pthread.dylib       	       0x1ae50e26c _pthread_start + 148
7   libsystem_pthread.dylib       	       0x1ae50908c thread_start + 8

Thread 7:
0   libsystem_pthread.dylib       	       0x1ae509078 start_wqthread + 0

Thread 8:: CM Delayed Flush Thread
0   libsystem_kernel.dylib        	       0x1ae4d4290 __psynch_cvwait + 8
1   libsystem_pthread.dylib       	       0x1ae50e83c _pthread_cond_wait + 1236
2   QtCore                        	       0x1065ccb6c 0x1063a4000 + 2263916
3   QtCore                        	       0x1065ccaa0 QWaitCondition::wait(QMutex*, QDeadlineTimer) + 108
4   Artemis                       	       0x102870cf4 DelayedFlushThread::run() + 140
5   QtCore                        	       0x1065be7b4 0x1063a4000 + 2205620
6   libsystem_pthread.dylib       	       0x1ae50e26c _pthread_start + 148
7   libsystem_pthread.dylib       	       0x1ae50908c thread_start + 8

Thread 9:: com.apple.CFSocket.private
0   libsystem_kernel.dylib        	       0x1ae4db5b8 __select + 8
1   CoreFoundation                	       0x1ae6051fc __CFSocketManager + 644
2   libsystem_pthread.dylib       	       0x1ae50e26c _pthread_start + 148
3   libsystem_pthread.dylib       	       0x1ae50908c thread_start + 8

Thread 10:: Polling thread for PC-Ryzen3300X
0   libsystem_kernel.dylib        	       0x1ae4d408c __semwait_signal + 8
1   libsystem_c.dylib             	       0x1ae3dcfbc nanosleep + 220
2   QtCore                        	       0x1065bed1c QThread::msleep(unsigned long) + 96
3   Artemis                       	       0x102874d04 0x102840000 + 216324
4   QtCore                        	       0x1065be7b4 0x1063a4000 + 2205620
5   libsystem_pthread.dylib       	       0x1ae50e26c _pthread_start + 148
6   libsystem_pthread.dylib       	       0x1ae50908c thread_start + 8

Thread 11:: CVDisplayLink
0   libsystem_kernel.dylib        	       0x1ae4d4290 __psynch_cvwait + 8
1   libsystem_pthread.dylib       	       0x1ae50e868 _pthread_cond_wait + 1280
2   CoreVideo                     	       0x1b5b9bb9c CVDisplayLink::waitUntil(unsigned long long) + 324
3   CoreVideo                     	       0x1b5b9aecc CVDisplayLink::runIOThread() + 488
4   libsystem_pthread.dylib       	       0x1ae50e26c _pthread_start + 148
5   libsystem_pthread.dylib       	       0x1ae50908c thread_start + 8

Thread 12:: com.apple.NSEventThread
0   libsystem_kernel.dylib        	       0x1ae4d08d0 mach_msg_trap + 8
1   libsystem_kernel.dylib        	       0x1ae4d0d40 mach_msg + 76
2   CoreFoundation                	       0x1ae5dac1c __CFRunLoopServiceMachPort + 372
3   CoreFoundation                	       0x1ae5d90cc __CFRunLoopRun + 1180
4   CoreFoundation                	       0x1ae5d8490 CFRunLoopRunSpecific + 600
5   AppKit                        	       0x1b12a46f4 _NSEventThread + 196
6   libsystem_pthread.dylib       	       0x1ae50e26c _pthread_start + 148
7   libsystem_pthread.dylib       	       0x1ae50908c thread_start + 8

Thread 13:: Thread (pooled)
0   libsystem_kernel.dylib        	       0x1ae4d4290 __psynch_cvwait + 8
1   libsystem_pthread.dylib       	       0x1ae50e83c _pthread_cond_wait + 1236
2   QtCore                        	       0x1065ccc28 0x1063a4000 + 2264104
3   QtCore                        	       0x1065ccaa0 QWaitCondition::wait(QMutex*, QDeadlineTimer) + 108
4   QtCore                        	       0x1065c6a64 0x1063a4000 + 2239076
5   QtCore                        	       0x1065be7b4 0x1063a4000 + 2205620
6   libsystem_pthread.dylib       	       0x1ae50e26c _pthread_start + 148
7   libsystem_pthread.dylib       	       0x1ae50908c thread_start + 8


Thread 4 crashed with ARM Thread State (64-bit):
    x0: 0x0000000000000000   x1: 0x0000000000000000   x2: 0x0000000000000000   x3: 0x0000000000000000
    x4: 0x0000000000000000   x5: 0x0000000000000000   x6: 0x0000000000000001   x7: 0x0000000109bd0028
    x8: 0x2033c1e178073306   x9: 0x2033c1e015970306  x10: 0xcccccccccccccccd  x11: 0x000000000000000a
   x12: 0x0000000000000000  x13: 0x0000000000000035  x14: 0x0000000036600000  x15: 0x0000000206cb9020
   x16: 0x0000000000000148  x17: 0x000000020837b640  x18: 0x0000000000000000  x19: 0x0000000000000006
   x20: 0x000000016d903000  x21: 0x0000000000004103  x22: 0x000000016d9030e0  x23: 0x0000000109bd0000
   x24: 0x0000000000000000  x25: 0x0000000000000000  x26: 0x000000016d5bfc69  x27: 0x000000016d903000
   x28: 0x0000000000000037   fp: 0x000000016d902240   lr: 0x00000001ae50dee0
    sp: 0x000000016d902220   pc: 0x00000001ae4d8db8 cpsr: 0x40001000
   far: 0x0000000109bd4000  esr: 0x56000080  Address size fault

Binary Images:
       0x1ae4cf000 -        0x1ae506fff libsystem_kernel.dylib (*) <1d7b3b8e-75a1-34ea-aa52-9f7c23155c55> /usr/lib/system/libsystem_kernel.dylib
       0x1ae556000 -        0x1aea9bfff com.apple.CoreFoundation (6.9) <8e1809ff-f5b1-3d9e-be15-f2e7b1d8ce51> /System/Library/Frameworks/CoreFoundation.framework/Versions/A/CoreFoundation
       0x1b71c5000 -        0x1b74f8fff com.apple.HIToolbox (2.1.1) <4a1d1f30-c79d-3502-b51f-9792adbd8e06> /System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/HIToolbox.framework/Versions/A/HIToolbox
       0x1b10f6000 -        0x1b1fadfff com.apple.AppKit (6.9) <153590c1-624c-38fb-8ffb-ba751bccbd16> /System/Library/Frameworks/AppKit.framework/Versions/C/AppKit
       0x105be0000 -        0x105c87fff libqcocoa.dylib (*) <e0c9df08-e11b-3eb7-83f8-4436b4970a70> /Applications/Artemis.app/Contents/PlugIns/platforms/libqcocoa.dylib
       0x1063a4000 -        0x106843fff org.qt-project.QtCore (6.8) <a1e0f1f5-b0bb-3371-87a5-5dd3ae408cd9> /Applications/Artemis.app/Contents/Frameworks/QtCore.framework/Versions/A/QtCore
       0x102840000 -        0x102b13fff com.artemis_desktop.Artemis (0.5.6) <4461c454-7474-3a7e-a4b5-7efc7ed07b98> /Applications/Artemis.app/Contents/MacOS/Artemis
       0x102d30000 -        0x102d8ffff dyld (*) <fbb89662-e6f2-3434-b542-f75185ac5e74> /usr/lib/dyld
       0x1ae507000 -        0x1ae513fff libsystem_pthread.dylib (*) <cee8bc77-6923-34d9-89a3-6f8f7279605e> /usr/lib/system/libsystem_pthread.dylib
       0x102de4000 -        0x102f27fff org.libsdl.SDL2 (2.31.0) <267164bf-ed30-328e-84c7-af463ed6a02f> /Applications/Artemis.app/Contents/Frameworks/SDL2.framework/Versions/A/SDL2
       0x1ae3ce000 -        0x1ae44ffff libsystem_c.dylib (*) <fd566a15-42d8-314a-a99a-b59237ddf5bc> /usr/lib/system/libsystem_c.dylib
       0x1ae31b000 -        0x1ae345fff libsystem_malloc.dylib (*) <3a021c33-dd59-37f7-9a86-5ceed68ff9ba> /usr/lib/system/libsystem_malloc.dylib
       0x1b5438000 -        0x1b5761fff com.apple.QuartzCore (1.11) <b3f9d8bc-5d97-3a56-8797-fd3e8847a5b0> /System/Library/Frameworks/QuartzCore.framework/Versions/A/QuartzCore
       0x1ae346000 -        0x1ae38cfff libdispatch.dylib (*) <dc048e3b-e023-3d17-afe5-4ff3dc625608> /usr/lib/system/libdispatch.dylib
       0x1b5b98000 -        0x1b5bf5fff com.apple.CoreVideo (1.8) <f988dbd8-b383-38c8-a141-f80e0252430e> /System/Library/Frameworks/CoreVideo.framework/Versions/A/CoreVideo

External Modification Summary:
  Calls made by other processes targeting this process:
    task_for_pid: 0
    thread_create: 0
    thread_set_state: 0
  Calls made by this process:
    task_for_pid: 0
    thread_create: 0
    thread_set_state: 0
  Calls made by all processes on this machine:
    task_for_pid: 0
    thread_create: 0
    thread_set_state: 0

VM Region Summary:
ReadOnly portion of Libraries: Total=899.7M resident=0K(0%) swapped_out_or_unallocated=899.7M(100%)
Writable regions: Total=1.6G written=0K(0%) resident=0K(0%) swapped_out=0K(0%) unallocated=1.6G(100%)

                                VIRTUAL   REGION 
REGION TYPE                        SIZE    COUNT (non-coalesced) 
===========                     =======  ======= 
Accelerate framework               256K        2 
Activity Tracing                   256K        1 
CG backing stores                 2176K        4 
CG image                            48K        1 
ColorSync                          576K       25 
CoreAnimation                      128K        7 
CoreGraphics                        32K        2 
CoreUI image data                  832K        5 
Foundation                          16K        1 
JS VM Gigacage                    4096K        1 
JS VM Isolated Heap               6464K        5 
Kernel Alloc Once                   32K        1 
MALLOC                           283.3M       52 
MALLOC guard page                  192K        9 
MALLOC_MEDIUM (reserved)         960.0M        8         reserved VM address space (unallocated)
MALLOC_NANO (reserved)           384.0M        1         reserved VM address space (unallocated)
STACK GUARD                       56.2M       14 
Stack                             22.4M       15 
VM_ALLOCATE                        320K       18 
__AUTH                            1934K      187 
__AUTH_CONST                      11.5M      351 
__DATA                            26.2M      390 
__DATA_CONST                      13.4M      395 
__DATA_DIRTY                       741K      123 
__FONT_DATA                          4K        1 
__LINKEDIT                       592.3M       46 
__OBJC_CONST                      1637K      158 
__OBJC_RO                         82.9M        1 
__OBJC_RW                         3152K        1 
__TEXT                           307.4M      411 
__UNICODE                          592K        1 
dyld private memory               1024K        1 
mapped file                      370.1M       35 
shared memory                      864K       14 
===========                     =======  ======= 
TOTAL                              3.1G     2287 
TOTAL, minus reserved VM space     1.7G     2287 



-----------
Full Report
-----------

{"app_name":"Artemis","timestamp":"2026-06-12 20:07:43.00 +0700","app_version":"0.5.6","slice_uuid":"4461c454-7474-3a7e-a4b5-7efc7ed07b98","build_version":"0.5.6","platform":1,"bundleID":"com.artemis_desktop.Artemis","share_with_app_devs":0,"is_first_party":0,"bug_type":"309","os_version":"macOS 12.3.1 (21E258)","incident_id":"E83AD770-8BF9-4C8F-9D29-2BC0F66DCBA7","name":"Artemis"}
{
  "uptime" : 360000,
  "procLaunch" : "2026-06-12 20:07:27.8967 +0700",
  "procRole" : "Foreground",
  "version" : 2,
  "userID" : 501,
  "deployVersion" : 210,
  "modelCode" : "MacBookAir10,1",
  "procStartAbsTime" : 8827998947885,
  "coalitionID" : 52357,
  "osVersion" : {
    "train" : "macOS 12.3.1",
    "build" : "21E258",
    "releaseType" : "User"
  },
  "captureTime" : "2026-06-12 20:07:40.6779 +0700",
  "incident" : "E83AD770-8BF9-4C8F-9D29-2BC0F66DCBA7",
  "bug_type" : "309",
  "pid" : 50263,
  "procExitAbsTime" : 8828302846009,
  "translated" : false,
  "cpuType" : "ARM-64",
  "procName" : "Artemis",
  "procPath" : "\/Applications\/Artemis.app\/Contents\/MacOS\/Artemis",
  "bundleInfo" : {"CFBundleShortVersionString":"0.5.6","CFBundleVersion":"0.5.6","CFBundleIdentifier":"com.artemis_desktop.Artemis"},
  "storeInfo" : {"deviceIdentifierForVendor":"C80FACF2-5ABA-532E-99F0-83A738B13EE2","thirdParty":true},
  "parentProc" : "launchd",
  "parentPid" : 1,
  "coalitionName" : "com.artemis_desktop.Artemis",
  "crashReporterKey" : "3684DFE2-4AED-594F-AF5D-0F8A722EAF54",
  "wakeTime" : 45,
  "sleepWakeUUID" : "917908B3-666A-46EA-A15C-FF7958F4E359",
  "sip" : "enabled",
  "isCorpse" : 1,
  "exception" : {"codes":"0x0000000000000000, 0x0000000000000000","rawCodes":[0,0],"type":"EXC_CRASH","signal":"SIGABRT"},
  "asi" : {"libsystem_malloc.dylib":["Artemis(50263,0x16d903000) malloc: Heap corruption detected, free list is damaged at 0x600002010360","*** Incorrect guard value: 36170086411599872"],"libsystem_c.dylib":["abort() called"]},
  "extMods" : {"caller":{"thread_create":0,"thread_set_state":0,"task_for_pid":0},"system":{"thread_create":0,"thread_set_state":0,"task_for_pid":0},"targeted":{"thread_create":0,"thread_set_state":0,"task_for_pid":0},"warnings":0},
  "faultingThread" : 4,
  "threads" : [{"id":5133185,"queue":"com.apple.main-thread","frames":[{"imageOffset":6352,"symbol":"mach_msg_trap","symbolLocation":8,"imageIndex":0},{"imageOffset":7488,"symbol":"mach_msg","symbolLocation":76,"imageIndex":0},{"imageOffset":543772,"symbol":"__CFRunLoopServiceMachPort","symbolLocation":372,"imageIndex":1},{"imageOffset":536780,"symbol":"__CFRunLoopRun","symbolLocation":1180,"imageIndex":1},{"imageOffset":533648,"symbol":"CFRunLoopRunSpecific","symbolLocation":600,"imageIndex":1},{"imageOffset":212440,"symbol":"RunCurrentEventLoopInMode","symbolLocation":292,"imageIndex":2},{"imageOffset":211796,"symbol":"ReceiveNextEventCommon","symbolLocation":564,"imageIndex":2},{"imageOffset":211208,"symbol":"_BlockUntilNextEventMatchingListInModeWithFilter","symbolLocation":72,"imageIndex":2},{"imageOffset":269100,"symbol":"_DPSNextEvent","symbolLocation":860,"imageIndex":3},{"imageOffset":263204,"symbol":"-[NSApplication(NSEvent) _nextEventMatchingEventMask:untilDate:inMode:dequeue:]","symbolLocation":1328,"imageIndex":3},{"imageOffset":206320,"symbol":"-[NSApplication run]","symbolLocation":596,"imageIndex":3},{"imageOffset":96988,"imageIndex":4},{"imageOffset":645252,"symbol":"QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>)","symbolLocation":596,"imageIndex":5},{"imageOffset":606328,"symbol":"QCoreApplication::exec()","symbolLocation":144,"imageIndex":5},{"imageOffset":65340,"symbol":"main","symbolLocation":8396,"imageIndex":6},{"imageOffset":20616,"symbol":"start","symbolLocation":516,"imageIndex":7}]},{"id":5133205,"frames":[{"imageOffset":8312,"symbol":"start_wqthread","symbolLocation":0,"imageIndex":8}]},{"id":5133207,"name":"Thread (pooled)","frames":[{"imageOffset":21136,"symbol":"__psynch_cvwait","symbolLocation":8,"imageIndex":0},{"imageOffset":30780,"symbol":"_pthread_cond_wait","symbolLocation":1236,"imageIndex":8},{"imageOffset":2264104,"imageIndex":5},{"imageOffset":2263712,"symbol":"QWaitCondition::wait(QMutex*, QDeadlineTimer)","symbolLocation":108,"imageIndex":5},{"imageOffset":2239076,"imageIndex":5},{"imageOffset":2205620,"imageIndex":5},{"imageOffset":29292,"symbol":"_pthread_start","symbolLocation":148,"imageIndex":8},{"imageOffset":8332,"symbol":"thread_start","symbolLocation":8,"imageIndex":8}]},{"id":5133208,"name":"SDLTimer","frames":[{"imageOffset":21136,"symbol":"__psynch_cvwait","symbolLocation":8,"imageIndex":0},{"imageOffset":30780,"symbol":"_pthread_cond_wait","symbolLocation":1236,"imageIndex":8},{"imageOffset":937928,"imageIndex":9},{"imageOffset":196144,"imageIndex":9},{"imageOffset":144876,"imageIndex":9},{"imageOffset":129592,"imageIndex":9},{"imageOffset":142188,"imageIndex":9},{"imageOffset":29292,"symbol":"_pthread_start","symbolLocation":148,"imageIndex":8},{"imageOffset":8332,"symbol":"thread_start","symbolLocation":8,"imageIndex":8}]},{"triggered":true,"id":5133212,"threadState":{"x":[{"value":0},{"value":0},{"value":0},{"value":0},{"value":0},{"value":0},{"value":1},{"value":4458348584},{"value":2320411407151477510},{"value":2320411401204990726},{"value":14757395258967641293},{"value":10},{"value":0},{"value":53},{"value":912261120},{"value":8703938592,"symbolLocation":0,"symbol":"OBJC_CLASS_$___NSArrayM"},{"value":328},{"value":8727803456},{"value":0},{"value":6},{"value":6133133312},{"value":16643},{"value":6133133536},{"value":4458348544},{"value":0},{"value":0},{"value":6129712233},{"value":6133133312},{"value":55}],"flavor":"ARM_THREAD_STATE64","lr":{"value":7219502816},"cpsr":{"value":1073745920},"fp":{"value":6133129792},"sp":{"value":6133129760},"esr":{"value":1442840704,"description":" Address size fault"},"pc":{"value":7219285432,"matchesCrashFrame":1},"far":{"value":4458364928}},"queue":"CA::Context","frames":[{"imageOffset":40376,"symbol":"__pthread_kill","symbolLocation":8,"imageIndex":0},{"imageOffset":28384,"symbol":"pthread_kill","symbolLocation":288,"imageIndex":8},{"imageOffset":500544,"symbol":"abort","symbolLocation":168,"imageIndex":10},{"imageOffset":63680,"symbol":"malloc_vreport","symbolLocation":552,"imageIndex":11},{"imageOffset":150660,"symbol":"malloc_zone_error","symbolLocation":100,"imageIndex":11},{"imageOffset":7024,"symbol":"nanov2_allocate_from_block","symbolLocation":568,"imageIndex":11},{"imageOffset":4492,"symbol":"nanov2_allocate","symbolLocation":128,"imageIndex":11},{"imageOffset":4264,"symbol":"nanov2_malloc","symbolLocation":64,"imageIndex":11},{"imageOffset":124744,"symbol":"_malloc_zone_malloc","symbolLocation":156,"imageIndex":11},{"imageOffset":134292,"symbol":"-[__NSArrayM insertObject:atIndex:]","symbolLocation":264,"imageIndex":1},{"imageOffset":239484,"symbol":"layer_composited(_CAImageQueue*, void*, unsigned int)","symbolLocation":360,"imageIndex":12},{"imageOffset":239052,"symbol":"CAImageQueueDidComposite","symbolLocation":240,"imageIndex":12},{"imageOffset":238768,"symbol":"_XImageQueueDidComposite","symbolLocation":52,"imageIndex":12},{"imageOffset":530352,"symbol":"invocation function for block in CA::Context::client_port()","symbolLocation":232,"imageIndex":12},{"imageOffset":16840,"symbol":"_dispatch_client_callout","symbolLocation":20,"imageIndex":13},{"imageOffset":30320,"symbol":"_dispatch_continuation_pop","symbolLocation":500,"imageIndex":13},{"imageOffset":108768,"symbol":"_dispatch_source_invoke","symbolLocation":1596,"imageIndex":13},{"imageOffset":46980,"symbol":"_dispatch_lane_serial_drain","symbolLocation":376,"imageIndex":13},{"imageOffset":50180,"symbol":"_dispatch_lane_invoke","symbolLocation":392,"imageIndex":13},{"imageOffset":93336,"symbol":"_dispatch_workloop_worker_thread","symbolLocation":648,"imageIndex":13},{"imageOffset":13152,"symbol":"_pthread_wqthread","symbolLocation":288,"imageIndex":8},{"imageOffset":8320,"symbol":"start_wqthread","symbolLocation":8,"imageIndex":8}]},{"id":5133214,"name":"QQmlThread","frames":[{"imageOffset":40656,"symbol":"poll","symbolLocation":8,"imageIndex":0},{"imageOffset":2198788,"symbol":"qt_safe_poll(pollfd*, unsigned int, QDeadlineTimer)","symbolLocation":76,"imageIndex":5},{"imageOffset":2214340,"symbol":"QEventDispatcherUNIX::processEvents(QFlags<QEventLoop::ProcessEventsFlag>)","symbolLocation":904,"imageIndex":5},{"imageOffset":645252,"symbol":"QEventLoop::exec(QFlags<QEventLoop::ProcessEventsFlag>)","symbolLocation":596,"imageIndex":5},{"imageOffset":1594772,"symbol":"QThread::exec()","symbolLocation":332,"imageIndex":5},{"imageOffset":2205620,"imageIndex":5},{"imageOffset":29292,"symbol":"_pthread_start","symbolLocation":148,"imageIndex":8},{"imageOffset":8332,"symbol":"thread_start","symbolLocation":8,"imageIndex":8}]},{"id":5133216,"name":"Thread (pooled)","frames":[{"imageOffset":21136,"symbol":"__psynch_cvwait","symbolLocation":8,"imageIndex":0},{"imageOffset":30780,"symbol":"_pthread_cond_wait","symbolLocation":1236,"imageIndex":8},{"imageOffset":2264104,"imageIndex":5},{"imageOffset":2263712,"symbol":"QWaitCondition::wait(QMutex*, QDeadlineTimer)","symbolLocation":108,"imageIndex":5},{"imageOffset":2239076,"imageIndex":5},{"imageOffset":2205620,"imageIndex":5},{"imageOffset":29292,"symbol":"_pthread_start","symbolLocation":148,"imageIndex":8},{"imageOffset":8332,"symbol":"thread_start","symbolLocation":8,"imageIndex":8}]},{"id":5133219,"frames":[{"imageOffset":8312,"symbol":"start_wqthread","symbolLocation":0,"imageIndex":8}]},{"id":5133231,"name":"CM Delayed Flush Thread","frames":[{"imageOffset":21136,"symbol":"__psynch_cvwait","symbolLocation":8,"imageIndex":0},{"imageOffset":30780,"symbol":"_pthread_cond_wait","symbolLocation":1236,"imageIndex":8},{"imageOffset":2263916,"imageIndex":5},{"imageOffset":2263712,"symbol":"QWaitCondition::wait(QMutex*, QDeadlineTimer)","symbolLocation":108,"imageIndex":5},{"imageOffset":199924,"symbol":"DelayedFlushThread::run()","symbolLocation":140,"imageIndex":6},{"imageOffset":2205620,"imageIndex":5},{"imageOffset":29292,"symbol":"_pthread_start","symbolLocation":148,"imageIndex":8},{"imageOffset":8332,"symbol":"thread_start","symbolLocation":8,"imageIndex":8}]},{"id":5133232,"name":"com.apple.CFSocket.private","frames":[{"imageOffset":50616,"symbol":"__select","symbolLocation":8,"imageIndex":0},{"imageOffset":717308,"symbol":"__CFSocketManager","symbolLocation":644,"imageIndex":1},{"imageOffset":29292,"symbol":"_pthread_start","symbolLocation":148,"imageIndex":8},{"imageOffset":8332,"symbol":"thread_start","symbolLocation":8,"imageIndex":8}]},{"id":5133233,"name":"Polling thread for PC-Ryzen3300X","frames":[{"imageOffset":20620,"symbol":"__semwait_signal","symbolLocation":8,"imageIndex":0},{"imageOffset":61372,"symbol":"nanosleep","symbolLocation":220,"imageIndex":10},{"imageOffset":2207004,"symbol":"QThread::msleep(unsigned long)","symbolLocation":96,"imageIndex":5},{"imageOffset":216324,"imageIndex":6},{"imageOffset":2205620,"imageIndex":5},{"imageOffset":29292,"symbol":"_pthread_start","symbolLocation":148,"imageIndex":8},{"imageOffset":8332,"symbol":"thread_start","symbolLocation":8,"imageIndex":8}]},{"id":5133243,"name":"CVDisplayLink","frames":[{"imageOffset":21136,"symbol":"__psynch_cvwait","symbolLocation":8,"imageIndex":0},{"imageOffset":30824,"symbol":"_pthread_cond_wait","symbolLocation":1280,"imageIndex":8},{"imageOffset":15260,"symbol":"CVDisplayLink::waitUntil(unsigned long long)","symbolLocation":324,"imageIndex":14},{"imageOffset":11980,"symbol":"CVDisplayLink::runIOThread()","symbolLocation":488,"imageIndex":14},{"imageOffset":29292,"symbol":"_pthread_start","symbolLocation":148,"imageIndex":8},{"imageOffset":8332,"symbol":"thread_start","symbolLocation":8,"imageIndex":8}]},{"id":5133251,"name":"com.apple.NSEventThread","frames":[{"imageOffset":6352,"symbol":"mach_msg_trap","symbolLocation":8,"imageIndex":0},{"imageOffset":7488,"symbol":"mach_msg","symbolLocation":76,"imageIndex":0},{"imageOffset":543772,"symbol":"__CFRunLoopServiceMachPort","symbolLocation":372,"imageIndex":1},{"imageOffset":536780,"symbol":"__CFRunLoopRun","symbolLocation":1180,"imageIndex":1},{"imageOffset":533648,"symbol":"CFRunLoopRunSpecific","symbolLocation":600,"imageIndex":1},{"imageOffset":1763060,"symbol":"_NSEventThread","symbolLocation":196,"imageIndex":3},{"imageOffset":29292,"symbol":"_pthread_start","symbolLocation":148,"imageIndex":8},{"imageOffset":8332,"symbol":"thread_start","symbolLocation":8,"imageIndex":8}]},{"id":5133270,"name":"Thread (pooled)","frames":[{"imageOffset":21136,"symbol":"__psynch_cvwait","symbolLocation":8,"imageIndex":0},{"imageOffset":30780,"symbol":"_pthread_cond_wait","symbolLocation":1236,"imageIndex":8},{"imageOffset":2264104,"imageIndex":5},{"imageOffset":2263712,"symbol":"QWaitCondition::wait(QMutex*, QDeadlineTimer)","symbolLocation":108,"imageIndex":5},{"imageOffset":2239076,"imageIndex":5},{"imageOffset":2205620,"imageIndex":5},{"imageOffset":29292,"symbol":"_pthread_start","symbolLocation":148,"imageIndex":8},{"imageOffset":8332,"symbol":"thread_start","symbolLocation":8,"imageIndex":8}]}],
  "usedImages" : [
  {
    "source" : "P",
    "arch" : "arm64e",
    "base" : 7219245056,
    "size" : 229376,
    "uuid" : "1d7b3b8e-75a1-34ea-aa52-9f7c23155c55",
    "path" : "\/usr\/lib\/system\/libsystem_kernel.dylib",
    "name" : "libsystem_kernel.dylib"
  },
  {
    "source" : "P",
    "arch" : "arm64e",
    "base" : 7219798016,
    "CFBundleShortVersionString" : "6.9",
    "CFBundleIdentifier" : "com.apple.CoreFoundation",
    "size" : 5529600,
    "uuid" : "8e1809ff-f5b1-3d9e-be15-f2e7b1d8ce51",
    "path" : "\/System\/Library\/Frameworks\/CoreFoundation.framework\/Versions\/A\/CoreFoundation",
    "name" : "CoreFoundation",
    "CFBundleVersion" : "1858.112"
  },
  {
    "source" : "P",
    "arch" : "arm64e",
    "base" : 7367053312,
    "CFBundleShortVersionString" : "2.1.1",
    "CFBundleIdentifier" : "com.apple.HIToolbox",
    "size" : 3358720,
    "uuid" : "4a1d1f30-c79d-3502-b51f-9792adbd8e06",
    "path" : "\/System\/Library\/Frameworks\/Carbon.framework\/Versions\/A\/Frameworks\/HIToolbox.framework\/Versions\/A\/HIToolbox",
    "name" : "HIToolbox"
  },
  {
    "source" : "P",
    "arch" : "arm64e",
    "base" : 7265542144,
    "CFBundleShortVersionString" : "6.9",
    "CFBundleIdentifier" : "com.apple.AppKit",
    "size" : 15433728,
    "uuid" : "153590c1-624c-38fb-8ffb-ba751bccbd16",
    "path" : "\/System\/Library\/Frameworks\/AppKit.framework\/Versions\/C\/AppKit",
    "name" : "AppKit",
    "CFBundleVersion" : "2113.40.127"
  },
  {
    "source" : "P",
    "arch" : "arm64",
    "base" : 4391305216,
    "size" : 688128,
    "uuid" : "e0c9df08-e11b-3eb7-83f8-4436b4970a70",
    "path" : "\/Applications\/Artemis.app\/Contents\/PlugIns\/platforms\/libqcocoa.dylib",
    "name" : "libqcocoa.dylib"
  },
  {
    "source" : "P",
    "arch" : "arm64",
    "base" : 4399448064,
    "CFBundleShortVersionString" : "6.8",
    "CFBundleIdentifier" : "org.qt-project.QtCore",
    "size" : 4849664,
    "uuid" : "a1e0f1f5-b0bb-3371-87a5-5dd3ae408cd9",
    "path" : "\/Applications\/Artemis.app\/Contents\/Frameworks\/QtCore.framework\/Versions\/A\/QtCore",
    "name" : "QtCore",
    "CFBundleVersion" : "6.8.3"
  },
  {
    "source" : "P",
    "arch" : "arm64",
    "base" : 4337172480,
    "CFBundleShortVersionString" : "0.5.6",
    "CFBundleIdentifier" : "com.artemis_desktop.Artemis",
    "size" : 2965504,
    "uuid" : "4461c454-7474-3a7e-a4b5-7efc7ed07b98",
    "path" : "\/Applications\/Artemis.app\/Contents\/MacOS\/Artemis",
    "name" : "Artemis",
    "CFBundleVersion" : "0.5.6"
  },
  {
    "source" : "P",
    "arch" : "arm64e",
    "base" : 4342349824,
    "size" : 393216,
    "uuid" : "fbb89662-e6f2-3434-b542-f75185ac5e74",
    "path" : "\/usr\/lib\/dyld",
    "name" : "dyld"
  },
  {
    "source" : "P",
    "arch" : "arm64e",
    "base" : 7219474432,
    "size" : 53248,
    "uuid" : "cee8bc77-6923-34d9-89a3-6f8f7279605e",
    "path" : "\/usr\/lib\/system\/libsystem_pthread.dylib",
    "name" : "libsystem_pthread.dylib"
  },
  {
    "source" : "P",
    "arch" : "arm64",
    "base" : 4343087104,
    "CFBundleShortVersionString" : "2.31.0",
    "CFBundleIdentifier" : "org.libsdl.SDL2",
    "size" : 1327104,
    "uuid" : "267164bf-ed30-328e-84c7-af463ed6a02f",
    "path" : "\/Applications\/Artemis.app\/Contents\/Frameworks\/SDL2.framework\/Versions\/A\/SDL2",
    "name" : "SDL2",
    "CFBundleVersion" : "2.31.0"
  },
  {
    "source" : "P",
    "arch" : "arm64e",
    "base" : 7218192384,
    "size" : 532480,
    "uuid" : "fd566a15-42d8-314a-a99a-b59237ddf5bc",
    "path" : "\/usr\/lib\/system\/libsystem_c.dylib",
    "name" : "libsystem_c.dylib"
  },
  {
    "source" : "P",
    "arch" : "arm64e",
    "base" : 7217459200,
    "size" : 176128,
    "uuid" : "3a021c33-dd59-37f7-9a86-5ceed68ff9ba",
    "path" : "\/usr\/lib\/system\/libsystem_malloc.dylib",
    "name" : "libsystem_malloc.dylib"
  },
  {
    "source" : "P",
    "arch" : "arm64e",
    "base" : 7336067072,
    "CFBundleShortVersionString" : "1.11",
    "CFBundleIdentifier" : "com.apple.QuartzCore",
    "size" : 3317760,
    "uuid" : "b3f9d8bc-5d97-3a56-8797-fd3e8847a5b0",
    "path" : "\/System\/Library\/Frameworks\/QuartzCore.framework\/Versions\/A\/QuartzCore",
    "name" : "QuartzCore",
    "CFBundleVersion" : "964.19.5"
  },
  {
    "source" : "P",
    "arch" : "arm64e",
    "base" : 7217635328,
    "size" : 290816,
    "uuid" : "dc048e3b-e023-3d17-afe5-4ff3dc625608",
    "path" : "\/usr\/lib\/system\/libdispatch.dylib",
    "name" : "libdispatch.dylib"
  },
  {
    "source" : "P",
    "arch" : "arm64e",
    "base" : 7343800320,
    "CFBundleShortVersionString" : "1.8",
    "CFBundleIdentifier" : "com.apple.CoreVideo",
    "size" : 385024,
    "uuid" : "f988dbd8-b383-38c8-a141-f80e0252430e",
    "path" : "\/System\/Library\/Frameworks\/CoreVideo.framework\/Versions\/A\/CoreVideo",
    "name" : "CoreVideo",
    "CFBundleVersion" : "0.0"
  }
],
  "sharedCache" : {
  "base" : 7216185344,
  "size" : 3136438272,
  "uuid" : "1df3dfc1-141a-35d0-a4e5-f1e113894c6e"
},
  "vmSummary" : "ReadOnly portion of Libraries: Total=899.7M resident=0K(0%) swapped_out_or_unallocated=899.7M(100%)\nWritable regions: Total=1.6G written=0K(0%) resident=0K(0%) swapped_out=0K(0%) unallocated=1.6G(100%)\n\n                                VIRTUAL   REGION \nREGION TYPE                        SIZE    COUNT (non-coalesced) \n===========                     =======  ======= \nAccelerate framework               256K        2 \nActivity Tracing                   256K        1 \nCG backing stores                 2176K        4 \nCG image                            48K        1 \nColorSync                          576K       25 \nCoreAnimation                      128K        7 \nCoreGraphics                        32K        2 \nCoreUI image data                  832K        5 \nFoundation                          16K        1 \nJS VM Gigacage                    4096K        1 \nJS VM Isolated Heap               6464K        5 \nKernel Alloc Once                   32K        1 \nMALLOC                           283.3M       52 \nMALLOC guard page                  192K        9 \nMALLOC_MEDIUM (reserved)         960.0M        8         reserved VM address space (unallocated)\nMALLOC_NANO (reserved)           384.0M        1         reserved VM address space (unallocated)\nSTACK GUARD                       56.2M       14 \nStack                             22.4M       15 \nVM_ALLOCATE                        320K       18 \n__AUTH                            1934K      187 \n__AUTH_CONST                      11.5M      351 \n__DATA                            26.2M      390 \n__DATA_CONST                      13.4M      395 \n__DATA_DIRTY                       741K      123 \n__FONT_DATA                          4K        1 \n__LINKEDIT                       592.3M       46 \n__OBJC_CONST                      1637K      158 \n__OBJC_RO                         82.9M        1 \n__OBJC_RW                         3152K        1 \n__TEXT                           307.4M      411 \n__UNICODE                          592K        1 \ndyld private memory               1024K        1 \nmapped file                      370.1M       35 \nshared memory                      864K       14 \n===========                     =======  ======= \nTOTAL                              3.1G     2287 \nTOTAL, minus reserved VM space     1.7G     2287 \n",
  "legacyInfo" : {
  "threadTriggered" : {
    "queue" : "CA::Context"
  }
},
  "trialInfo" : {
  "rollouts" : [
    {
      "rolloutId" : "6112e14f37f5d11121dcd519",
      "factorPackIds" : {
        "SIRI_TEXT_TO_SPEECH" : "6267122541fbd3022330c3ea"
      },
      "deploymentId" : 240000231
    },
    {
      "rolloutId" : "60da5e84ab0ca017dace9abf",
      "factorPackIds" : {

      },
      "deploymentId" : 240000008
    }
  ],
  "experiments" : [

  ]
}
}

Model: MacBookAir10,1, BootROM 7459.101.3, proc 8:4:4 processors, 8 GB, SMC 
Graphics: Apple M1, Apple M1, Built-In
Display: Color LCD, 2560 x 1600 Retina, Main, MirrorOff, Online
Memory Module: LPDDR4
AirPort: Wi-Fi, wl0: Feb  8 2022 01:44:45 version 18.60.21.0.7.8.126 FWID 01-1cdae627
Bluetooth: Version (null), 0 services, 0 devices, 0 incoming serial ports
Network Service: Wi-Fi, AirPort, en0
USB Device: USB31Bus
USB Device: USB31Bus
USB Device: USB2.0 HUB
USB Device: TGZ Controller
Thunderbolt Bus: MacBook Air, Apple Inc.
Thunderbolt Bus: MacBook Air, Apple Inc.
