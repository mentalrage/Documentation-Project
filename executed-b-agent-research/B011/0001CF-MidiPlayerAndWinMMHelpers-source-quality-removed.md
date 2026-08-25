<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B011\0001CF-MidiPlayerAndWinMMHelpers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0001CF-MidiPlayerAndWinMMHelpers-source-quality.md](0001CF-MidiPlayerAndWinMMHelpers-source-quality.md)
- Source report SHA256 before cleanup: `FB06E8CDB1898F5A3D765DFFCBF83953B88E57E53AF264C1F4F6D82E50CA796C`
- Cleanup generated: `2026-08-11T12:47:16Z`
- Removed executable blocks: `10`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `261-263`
- Original language: `powershell`
- Block SHA256: `C3392C4930D7853D8B51BA214C54271257555B0A3FCF37501171DD874363C4F1`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `307-309`
- Original language: `powershell`
- Block SHA256: `3753EB0D04E1F398ECAE0DAFE524EBF83945EDCA5BD875A3B1F866C7391C6DEB`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md --apply --queue-timeout 240
```

## Removed Block R003

- Original source lines: `374-376`
- Original language: `powershell`
- Block SHA256: `222422C6D3A48DA136042ADDE9FE4DAF0DB96D2E0924D304935D47947F130511`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `479-481`
- Original language: `powershell`
- Block SHA256: `198F62F6389CA8001A05B1F7BBBC413B0A361C46ABA06F148F628F2A9B10E0B4`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md --apply --queue-timeout 240
```

## Removed Block R005

- Original source lines: `534-536`
- Original language: `powershell`
- Block SHA256: `AA643FBE245BBE341B8638432C2E14FE92464A2176E3649AE54F496DB1255A1B`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md --apply --queue-timeout 240
```

## Removed Block R006

- Original source lines: `571-573`
- Original language: `powershell`
- Block SHA256: `8CFAF4136B8F38BBA651B797FA1285B086E72C26DD000204076B9766058FCF5C`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md --apply --queue-timeout 240
```

## Removed Block R007

- Original source lines: `652-654`
- Original language: `powershell`
- Block SHA256: `EA959DBB70571093E12C3B5CA5294A11569A79E7B2AEA564BDDDE511D5FC394E`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md --apply --queue-timeout 240
```

## Removed Block R008

- Original source lines: `750-752`
- Original language: `powershell`
- Block SHA256: `D6EB0AB6BE3BC25E986505C9C25CCA3FBE05DFB7E60878A88FC467134EECA17F`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md --apply --queue-timeout 240
```

## Removed Block R009

- Original source lines: `776-778`
- Original language: `powershell`
- Block SHA256: `3DDDADD9A3BEB6BB54ACD7ECCA8152B7EB01278F0E1AB524C5A83B3775FFCA6B`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md --apply --queue-timeout 240
```

## Removed Block R010

- Original source lines: `846-865`
- Original language: `powershell`
- Block SHA256: `149C3C98A1CDFC77E6A62ADB3AE79D02DB24197A485F26858F5A881E5919D038`

```powershell
python .\tools\validator.py --mode file --file by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00525b10-0x00525b98.MidiReleaseStreamBuffers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00525ba0-0x00525bdf.MidiApplySingleChannelVolumeRaw.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00525dc0-0x00525f3d.MidiPlayerLifecycleMethods.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/MidiPlayer.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class/MidiPlayer.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/MidiPlayerWinMMState.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global/g_pMidiPlayer.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md --apply --queue-timeout 240
```
