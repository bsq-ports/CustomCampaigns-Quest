param (
    [Parameter(Mandatory=$false)]
    [Switch]$debug_so,
    [Parameter(Mandatory=$false)]
    [Switch]$log
)

& $PSScriptRoot/build.ps1

if (-not ($LastExitCode -eq 0)) {
    echo "build failed, not copying"
    exit $LastExitCode
}

if ($debug.IsPresent) {
    & adb push build/debug/libcustomcampaigns.so /sdcard/ModData/com.beatgames.beatsaber/Modloader/mods/libcustomcampaigns.so
} else {
    & adb push build/libcustomcampaigns.so /sdcard/ModData/com.beatgames.beatsaber/Modloader/mods/libcustomcampaigns.so
}

& adb shell am force-stop com.beatgames.beatsaber
& adb shell am start com.beatgames.beatsaber/com.unity3d.player.UnityPlayerActivity
Start-Sleep -Seconds 1.0
& adb shell am start com.beatgames.beatsaber/com.unity3d.player.UnityPlayerActivity
if ($log.IsPresent) {
    & $PSScriptRoot/log.ps1
}
