<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002B2-MidiSMFParserScratchGlobals-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002B2-MidiSMFParserScratchGlobals-source-quality.md](0002B2-MidiSMFParserScratchGlobals-source-quality.md)
- Source report SHA256 before cleanup: `D30B25BBDE97B85D9A9CE64E9C16F23577FE5CE2887A6F2B9B15708C3F5D544B`
- Cleanup generated: `2026-08-11T12:47:04Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `113-132`
- Original language: `powershell`
- Block SHA256: `EFD7BA0D74082DEB4AD02E1286A6FF175D61DA1E957A5A46E978F96D9FACB7F1`

```powershell
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\by-global\MidiPlayerWinMMState.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\by-file\MidiPlayer.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\by-class\MidiPlayer.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\executed\0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00526790-0x005269ea.MidiEventReader.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005269f0-0x00526ba8.MidiStreamEventEncoder.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md'
Get-Content -Raw 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md'
Select-String -Path 'E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md' -Pattern '0002B2|MidiSMFParserScratchGlobals|0069b870|0069b890' -Context 1,1
Get-Item 'E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\NexusTK\audio\MidiPlayer.cpp'
Select-String -Path 'E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\NexusTK\audio\MidiPlayer.cpp' -Pattern 'g_midiTrackScanCursor|g_midiPendingEvent|MidiFillStreamBuffer|MidiEvent|MidiFillResult|MidiTrackState|MIDI_FILL'
Select-String -Path 'E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\-ag-memory-coverage.md' -Pattern '0002B2|MidiSMFParserScratchGlobals|0069b870|0069b890' -Context 1,1
Get-ChildItem 'E:\NTK\GhidraBridge\source-3\project-documentation\by-type' | Where-Object { $_.Name -match 'Midi|MIDI|SMF|Track|StreamWrite' }
rg -n "MidiDocument|MidiTrackState|MidiEvent|MidiStreamWriteContext|g_midiTrackScanCursor|MIDI_FILL_" "E:\NTK\GhidraBridge\source-3\project-documentation" -g "*.md" -g "*.cpp"
```

## Removed Block R002

- Original source lines: `515-519`
- Original language: `powershell`
- Block SHA256: `DF4C11AE4D78A921023F2F8D14404579D624C5A0AF9DB607CF5C0829261EC376`

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode scoped --paths "by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md" "by-global/MidiPlayerWinMMState.md" "by-file/MidiPlayer.md" "by-class/MidiPlayer.md" "by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md" "by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md" "by-memory/-coverage-report.md"
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode autogen --apply --paths "by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md"
Select-String -Path 'E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\NexusTK\audio\MidiPlayer.cpp' -Pattern 'UID:0002B2|g_midiTrackScanCursor|static int MidiReadEvent|static int MidiFillStreamBuffer'
```
