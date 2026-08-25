<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B003\0002IZ-0002J1-maptileimagelib-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002IZ-0002J1-maptileimagelib-source-quality.md](0002IZ-0002J1-maptileimagelib-source-quality.md)
- Source report SHA256 before cleanup: `EBA8354FBFB834E022FC8AAF99F14554A5E01DEE5BDE75DA9CADB95AC45339ED`
- Cleanup generated: `2026-08-11T12:47:05Z`
- Removed executable blocks: `3`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `389-391`
- Original language: `powershell`
- Block SHA256: `878A149A8F5DFD2727D1F57354BD42CF2572827F77158E2078FE14F530E4D37C`

```powershell
python source-3\project-documentation\tools\validator.py --help
```

## Removed Block R002

- Original source lines: `395-403`
- Original language: `powershell`
- Block SHA256: `03180F98F29A593C19874E66371A613A62620BB55AFA7B13EA71808F9C7B7685`

```powershell
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004d1860-0x004d199e.MapTileImageLibConstructor.md --apply
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md --apply
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md --apply
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-class\MapTileImageLib.md --apply
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-file\MapTileImageLib.md --apply
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004d1860-0x004d199e.MapTileImageLibConstructor.md
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md
```


## Removed Block R003

- Source report SHA256 before this cleanup pass: `8F817854022B5080F4BAFC95A5E923691EA116BEF7672818BD80589B8AF78634`
- Original source lines: `40-42`
- Original language: `text`
- Block SHA256: `8294A0732E34DA0E21F4F97D8892B46306CA416CB7FCF16F45578BF39002D4FF`

```text
rg -n "0002IZ|0002J1|MapTileImageLibConstructor|LoadTileEpfMetadata|MapTileImageLib" source-3/project-documentation/tools/leaser/Agents/Agent-B00*/research/executed
```
