<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00012X-versatile-alert-pane-callbacks-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00012X-versatile-alert-pane-callbacks-source-quality.md](00012X-versatile-alert-pane-callbacks-source-quality.md)
- Source report SHA256 before cleanup: `F75E788C12F7A57788D174CF794EE35923F9B4E5AA03ADB8CE78313AEF39556C`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `1089-1098`
- Original language: `powershell`
- Block SHA256: `7EE8956297BCDD8C28A038AF0FA7628CAD1E7288BDF91F4F89F44212D0CF939F`

```powershell
python tools/validator.py --mode file --file by-memory/0x004a0690-0x004a0752.VersatileAlertPaneCallbacks.md --apply
python tools/validator.py --mode file --file by-class/VersatileAlertPane.md --apply
python tools/validator.py --mode file --file by-type/by-struct/AlertPaneLayout.md --apply
python tools/validator.py --mode file --file by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneRawCleanup.md --apply
python tools/validator.py --mode file --file by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor.md --apply
python tools/validator.py --mode file --file by-type/by-vtable/VersatileAlertPaneVtables.md --apply
python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply
python tools/validator.py --mode rescore --apply --lock-timeout -1
```

## Removed Block R002

- Original source lines: `1102-1104`
- Original language: `powershell`
- Block SHA256: `18069B3C5481D1C7E3ED440E41BF47316210143DDF5089844410BBA9258A0729`

```powershell
python tools/memory_ranges.py report
```
