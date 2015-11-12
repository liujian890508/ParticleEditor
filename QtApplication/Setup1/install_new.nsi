; 该脚本使用 HM VNISEdit 脚本编辑器向导产生

; 安装程序初始定义常量
!define PRODUCT_NAME "ParticleEditor"
!define PRODUCT_VERSION "1.0"
!define PRODUCT_PUBLISHER "MoXiang, Inc."
!define PRODUCT_WEB_SITE "http://www.weibo.com/loveMyue"
!define PRODUCT_DIR_REGKEY "Software\Microsoft\Windows\CurrentVersion\App Paths\ParticleEditor.exe"
!define PRODUCT_UNINST_KEY "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define PRODUCT_UNINST_ROOT_KEY "HKLM"
!define PRODUCT_STARTMENU_REGVAL "NSIS:StartMenuDir"

SetCompressor lzma

; ------ MUI 现代界面定义 (1.67 版本以上兼容) ------
!include "MUI.nsh"

; MUI 预定义常量
!define MUI_ABORTWARNING
!define MUI_ICON "..\QtApplication\QtApplication.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; 语言选择窗口常量设置
!define MUI_LANGDLL_REGISTRY_ROOT "${PRODUCT_UNINST_ROOT_KEY}"
!define MUI_LANGDLL_REGISTRY_KEY "${PRODUCT_UNINST_KEY}"
!define MUI_LANGDLL_REGISTRY_VALUENAME "NSIS:Language"

; 欢迎页面
!insertmacro MUI_PAGE_WELCOME
; 许可协议页面
!define MUI_LICENSEPAGE_CHECKBOX
!insertmacro MUI_PAGE_LICENSE "..\QtApplication\Licence.txt"
; 安装目录选择页面
!insertmacro MUI_PAGE_DIRECTORY
; 开始菜单设置页面
var ICONS_GROUP
!define MUI_STARTMENUPAGE_NODISABLE
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "ParticleEditor"
!define MUI_STARTMENUPAGE_REGISTRY_ROOT "${PRODUCT_UNINST_ROOT_KEY}"
!define MUI_STARTMENUPAGE_REGISTRY_KEY "${PRODUCT_UNINST_KEY}"
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "${PRODUCT_STARTMENU_REGVAL}"
!insertmacro MUI_PAGE_STARTMENU Application $ICONS_GROUP
; 安装过程页面
!insertmacro MUI_PAGE_INSTFILES
; 安装完成页面
!define MUI_FINISHPAGE_RUN "$INSTDIR\ParticleEditor.exe"
!define MUI_FINISHPAGE_SHOWREADME "$INSTDIR\README.txt"
!insertmacro MUI_PAGE_FINISH

; 安装卸载过程页面
!insertmacro MUI_UNPAGE_INSTFILES

; 安装界面包含的语言设置
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "SimpChinese"

; 安装预释放文件
!insertmacro MUI_RESERVEFILE_LANGDLL
!insertmacro MUI_RESERVEFILE_INSTALLOPTIONS
; ------ MUI 现代界面定义结束 ------

Name "${PRODUCT_NAME} ${PRODUCT_VERSION}"
OutFile "ParticleEditor.exe"
InstallDir "$PROGRAMFILES\ParticleEditor"
InstallDirRegKey HKLM "${PRODUCT_UNINST_KEY}" "UninstallString"
ShowInstDetails show
ShowUnInstDetails show

Section "ParticleEditor" SEC01
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "C:\Users\Administrator\Desktop\ParticleEditor\glew32.dll"
  SetOutPath "$INSTDIR\iconengines"
  File "C:\Users\Administrator\Desktop\ParticleEditor\iconengines\qsvgicon.dll"
  SetOutPath "$INSTDIR"
  File "C:\Users\Administrator\Desktop\ParticleEditor\iconv.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\icudt53.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\icuin53.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\icuuc53.dll"
  SetOutPath "$INSTDIR\imageformats"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qdds.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qgif.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qicns.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qico.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qjp2.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qjpeg.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qmng.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qsvg.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qtga.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qtiff.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qwbmp.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\imageformats\qwebp.dll"
  SetOutPath "$INSTDIR"
  File "C:\Users\Administrator\Desktop\ParticleEditor\libcocos2d.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\libcurl.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\libmpg123.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\libogg.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\libtiff.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\libvorbis.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\libvorbisfile.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\msvcp120.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\msvcr120.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\OpenAL32.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\ParticleEditor.exe"
  SetOutPath "$INSTDIR\platforms"
  File "C:\Users\Administrator\Desktop\ParticleEditor\platforms\qwindows.dll"
  SetOutPath "$INSTDIR\plists"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\BoilingFoam.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\BurstPipe.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\ButterFly.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\ButterFlyYFlipped.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\Comet.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\debian.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\ExplodingRing.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\Flower.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\Galaxy.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\LavaFlow.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\lines.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\Phoenix.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\SmallSun.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\SpinningPeas.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\Spiral.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\SpookyPeas.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\TestPremultipliedAlpha.plist"
  File "C:\Users\Administrator\Desktop\ParticleEditor\plists\Upsidedown.plist"
  SetOutPath "$INSTDIR"
  File "C:\Users\Administrator\Desktop\ParticleEditor\Qt5Core.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\Qt5Gui.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\Qt5OpenGL.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\Qt5Svg.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\Qt5Widgets.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\sqlite3.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\websockets.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\zlib1.dll"
  File "C:\Users\Administrator\Desktop\ParticleEditor\README.txt"

; 创建开始菜单快捷方式
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  CreateDirectory "$SMPROGRAMS\$ICONS_GROUP"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\ParticleEditor.lnk" "$INSTDIR\ParticleEditor.exe"
  CreateShortCut "$DESKTOP\ParticleEditor.lnk" "$INSTDIR\ParticleEditor.exe"
  CreateShortCut "$STARTMENU\ParticleEditor.lnk" "$INSTDIR\ParticleEditor.exe"
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section -AdditionalIcons
  !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Uninstall.lnk" "$INSTDIR\uninst.exe"
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section -Post
  WriteUninstaller "$INSTDIR\uninst.exe"
  WriteRegStr HKLM "${PRODUCT_DIR_REGKEY}" "" "$INSTDIR\ParticleEditor.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayName" "$(^Name)"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "UninstallString" "$INSTDIR\uninst.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayIcon" "$INSTDIR\ParticleEditor.exe"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "DisplayVersion" "${PRODUCT_VERSION}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}" "Publisher" "${PRODUCT_PUBLISHER}"
SectionEnd

#-- 根据 NSIS 脚本编辑规则，所有 Function 区段必须放置在 Section 区段之后编写，以避免安装程序出现未可预知的问题。--#

Function .onInit
  !insertmacro MUI_LANGDLL_DISPLAY
FunctionEnd

/******************************
 *  以下是安装程序的卸载部分  *
 ******************************/

Section Uninstall
  !insertmacro MUI_STARTMENU_GETFOLDER "Application" $ICONS_GROUP
  Delete "$INSTDIR\${PRODUCT_NAME}.url"
  Delete "$INSTDIR\uninst.exe"
  Delete "$INSTDIR\README.txt"
  Delete "$INSTDIR\zlib1.dll"
  Delete "$INSTDIR\websockets.dll"
  Delete "$INSTDIR\sqlite3.dll"
  Delete "$INSTDIR\Qt5Widgets.dll"
  Delete "$INSTDIR\Qt5Svg.dll"
  Delete "$INSTDIR\Qt5OpenGL.dll"
  Delete "$INSTDIR\Qt5Gui.dll"
  Delete "$INSTDIR\Qt5Core.dll"
  Delete "$INSTDIR\plists\Upsidedown.plist"
  Delete "$INSTDIR\plists\TestPremultipliedAlpha.plist"
  Delete "$INSTDIR\plists\SpookyPeas.plist"
  Delete "$INSTDIR\plists\Spiral.plist"
  Delete "$INSTDIR\plists\SpinningPeas.plist"
  Delete "$INSTDIR\plists\SmallSun.plist"
  Delete "$INSTDIR\plists\Phoenix.plist"
  Delete "$INSTDIR\plists\lines.plist"
  Delete "$INSTDIR\plists\LavaFlow.plist"
  Delete "$INSTDIR\plists\Galaxy.plist"
  Delete "$INSTDIR\plists\Flower.plist"
  Delete "$INSTDIR\plists\ExplodingRing.plist"
  Delete "$INSTDIR\plists\debian.plist"
  Delete "$INSTDIR\plists\Comet.plist"
  Delete "$INSTDIR\plists\ButterFlyYFlipped.plist"
  Delete "$INSTDIR\plists\ButterFly.plist"
  Delete "$INSTDIR\plists\BurstPipe.plist"
  Delete "$INSTDIR\plists\BoilingFoam.plist"
  Delete "$INSTDIR\platforms\qwindows.dll"
  Delete "$INSTDIR\ParticleEditor.exe"
  Delete "$INSTDIR\OpenAL32.dll"
  Delete "$INSTDIR\msvcr120.dll"
  Delete "$INSTDIR\msvcp120.dll"
  Delete "$INSTDIR\libvorbisfile.dll"
  Delete "$INSTDIR\libvorbis.dll"
  Delete "$INSTDIR\libtiff.dll"
  Delete "$INSTDIR\libogg.dll"
  Delete "$INSTDIR\libmpg123.dll"
  Delete "$INSTDIR\libcurl.dll"
  Delete "$INSTDIR\libcocos2d.dll"
  Delete "$INSTDIR\imageformats\qwebp.dll"
  Delete "$INSTDIR\imageformats\qwbmp.dll"
  Delete "$INSTDIR\imageformats\qtiff.dll"
  Delete "$INSTDIR\imageformats\qtga.dll"
  Delete "$INSTDIR\imageformats\qsvg.dll"
  Delete "$INSTDIR\imageformats\qmng.dll"
  Delete "$INSTDIR\imageformats\qjpeg.dll"
  Delete "$INSTDIR\imageformats\qjp2.dll"
  Delete "$INSTDIR\imageformats\qico.dll"
  Delete "$INSTDIR\imageformats\qicns.dll"
  Delete "$INSTDIR\imageformats\qgif.dll"
  Delete "$INSTDIR\imageformats\qdds.dll"
  Delete "$INSTDIR\icuuc53.dll"
  Delete "$INSTDIR\icuin53.dll"
  Delete "$INSTDIR\icudt53.dll"
  Delete "$INSTDIR\iconv.dll"
  Delete "$INSTDIR\iconengines\qsvgicon.dll"
  Delete "$INSTDIR\glew32.dll"

  Delete "$SMPROGRAMS\$ICONS_GROUP\Uninstall.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Website.lnk"
  Delete "$STARTMENU\ParticleEditor.lnk"
  Delete "$DESKTOP\ParticleEditor.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\ParticleEditor.lnk"
  
  Delete "$INSTDIR\*.qm"
  Delete "$INSTDIR\*.ini"

  RMDir "$SMPROGRAMS\$ICONS_GROUP"
  RMDir "$INSTDIR\plists"
  RMDir "$INSTDIR\platforms"
  RMDir "$INSTDIR\imageformats"
  RMDir "$INSTDIR\iconengines"

  RMDir "$INSTDIR"

  DeleteRegKey ${PRODUCT_UNINST_ROOT_KEY} "${PRODUCT_UNINST_KEY}"
  DeleteRegKey HKLM "${PRODUCT_DIR_REGKEY}"
  SetAutoClose true
SectionEnd

#-- 根据 NSIS 脚本编辑规则，所有 Function 区段必须放置在 Section 区段之后编写，以避免安装程序出现未可预知的问题。--#

Function un.onInit
!insertmacro MUI_UNGETLANGUAGE
  MessageBox MB_ICONQUESTION|MB_YESNO|MB_DEFBUTTON2 "您确实要完全移除 $(^Name) ，及其所有的组件？" IDYES +2
  Abort
FunctionEnd

Function un.onUninstSuccess
  HideWindow
  MessageBox MB_ICONINFORMATION|MB_OK "$(^Name) 已成功地从您的计算机移除。"
FunctionEnd
