<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\0000L3-MapPane-empty-emitter-family-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000L3-MapPane-empty-emitter-family-source-quality.md](0000L3-MapPane-empty-emitter-family-source-quality.md)
- Source report SHA256 before cleanup: `010AA02E28B522238A77E890D631F9EA670B69D38D85CCE64A24224DC5508ACE`
- Cleanup generated: `2026-08-11T12:47:06Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `408-410`
- Original language: `powershell`
- Block SHA256: `91BAE92552820FBCD7BE904854716CE1381661932ABCE65100F3BC3DFA9E8D01`

```powershell
python .\tools\leaser\leaser.py Agent-B004 lease by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md by-item/ScaleDirectionOffsetToPixels_00505100.md by-global/MapTilePixelDimensions.md by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md by-global/g_activeMapPane.md by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md by-global/MapPaneCmapSignaturePointer.md by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md by-memory/0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable.md by-memory/0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag.md by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md by-type/by-struct/MapPaneLayout.md by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md by-file/MapPane.md
```

## Removed Block R002

- Original source lines: `473-475`
- Original language: `powershell`
- Block SHA256: `77B121CD2EBA1DA262A2A68F6B4F7AC1F71A12E704DB0D56E9F5529D60F4ABCC`

```powershell
python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240
```
