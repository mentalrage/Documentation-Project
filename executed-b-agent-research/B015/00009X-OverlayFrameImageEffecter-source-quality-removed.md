<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B015\00009X-OverlayFrameImageEffecter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00009X-OverlayFrameImageEffecter-source-quality.md](00009X-OverlayFrameImageEffecter-source-quality.md)
- Source report SHA256 before cleanup: `1CEFED9207969B1685F234A2E6D034ABAFAFF828F988BC3328BDF88F1507B16E`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `359-365`
- Original language: `powershell`
- Block SHA256: `02BD9A18E65094BB0BF05F851D2BC99C927E96783B823C4F456802A569F7241A`

```powershell
python .\tools\validator.py --mode file --file by-class/OverlayFrameImageEffecter.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file/Effects.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-type/by-vtable/ScreenEffecterVtableFamily.md --apply --queue-timeout 240
python .\tools\validator.py --mode autogen --apply --queue-timeout 240
```
