<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B005\00037Y-MapPaneTileObjectGridRenderCore-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00037Y-MapPaneTileObjectGridRenderCore-source-quality.md](00037Y-MapPaneTileObjectGridRenderCore-source-quality.md)
- Source report SHA256 before cleanup: `A135FDAEFDDE210BAE5A5814DD11D3F08C6DF44A0D3B7885EED838198DD170B6`
- Cleanup generated: `2026-08-11T12:47:10Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `366-368`
- Original language: `powershell`
- Block SHA256: `8D120B18DE8B739CE67A1222C8B24BC4483B1EEA6607E531E13CFD5816E92FB8`

```powershell
python tools/validator.py --mode file --file by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source lines: `372-383`
- Original language: `powershell`
- Block SHA256: `FD59D9F7D8DC339BCD1FA4F0BA35786AF641C7911E6776C1C5B2F3A09A9AB424`

```powershell
python tools/validator.py --mode file --file by-class/MapPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md --apply --queue-timeout 240
python tools/validator.py --mode file --file by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md --apply --queue-timeout 240
```
