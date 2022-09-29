## Installation

-----------------------------------------------------------------------------
### Requirements: ###

- MacOS High Sierra
- Xcode: 9.2
- Java 8u202

-----------------------------------------------------------------------------
**1. Getting the source code**
-----------------------------------------------------------------------------
```
git clone https://github.com/dmytrokoren/kodi.git --depth=1 --single-branch
```
-----------------------------------------------------------------------------
**2. Install Kodi build depends & binary addons**
-----------------------------------------------------------------------------
```
cd $HOME/kodi/tools/depends
```
```
./bootstrap
```
```
./configure --host=arm-apple-darwin --with-cpu=arm64 --with-platform=tvos
```
```
make -j$(getconf _NPROCESSORS_ONLN)
```
```
make -j$(getconf _NPROCESSORS_ONLN) -C target/binary-addons
```
-----------------------------------------------------------------------------
**3. How to compile**
-----------------------------------------------------------------------------
```
cd $HOME/kodi
```
```
make -j$(getconf _NPROCESSORS_ONLN) -C tools/depends/target/xbmc
```
```
make -j$(getconf _NPROCESSORS_ONLN) clean
```
```
make -j$(getconf _NPROCESSORS_ONLN) xcode_depends
```
-----------------------------------------------------------------------------
**4. Using Xcode**
-----------------------------------------------------------------------------
=== RECOMMENDED TO USE TERMINAL COMMAND TO BUILD KODI ===

Go to Kodi folder located in home folder ($HOME/kodi).<br>
Open Kodi.xcodeproj
<br>
Set target compilation as Kodi-TVOS > GenericTVOS<br>

Do changes for Target <b>Kodi-TVOS & TVOSTopShelf:</b><br>
Change Bundle Identifier to a unique name.<br>
Select your Team and Provisional Profile.

After all required fields are satisfied.<br>
Xcode Main Menu > Products > Clean > and then Build.

-----------------------------------------------------------------------------
**5. Using Terminal (command-line)**
-----------------------------------------------------------------------------
```
xcodebuild -project $HOME/kodi/Kodi.xcodeproj -target Kodi-TVOS -configuration Release build \ ONLY_ACTIVE_ARCH=YES ARCHS=arm64 VALID_ARCHS=arm64 CODE_SIGN_IDENTITY="" CODE_SIGNING_REQUIRED=NO
```
-----------------------------------------------------------------------------
**6. Build Path & Code Sign**
-----------------------------------------------------------------------------
This is the path when using Terminal Build
    $HOME/kodi/build/Release-appletvos
    
This is the path when using Xcode Build (to get Library folder- Hold Alt and navigate to finder GO)<br>
    $HOME/Library/Developer/Xcode/DerivedData/Kodi-xxxxxxxxxxxxx/Build/Products/Debug-appletvos/Kodi.app

NOTE: Code Sign it with [https://dantheman827.github.io/ios-app-signer/](https://dantheman827.github.io/ios-app-signer/)

-----------------------------------------------------------------------------

See [docs/README.xxx] (https://github.com/xbmc/xbmc/tree/master/docs) for specific platform build information.

## Quick Kodi development links

* [Contributing] (https://github.com/xbmc/xbmc/blob/master/CONTRIBUTING.md)
* [Submitting a patch] (http://kodi.wiki/view/HOW-TO_submit_a_patch)
* [Code guidelines] (https://codedocs.xyz/xbmc/xbmc/code_guidelines.html)
* [Kodi development] (http://kodi.wiki/view/Development)

## Useful links

* [Kodi wiki] (http://kodi.wiki/)
* [Kodi bug tracker] (http://trac.kodi.tv)
* [Kodi community forums] (http://forum.kodi.tv/)
* [Kodi website] (http://kodi.tv)

**Enjoy Kodi and help us improve it today. :)**
