<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B013\0000EV-Thread-class-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0000EV-Thread-class-source-quality.md](0000EV-Thread-class-source-quality.md)
- Source report SHA256 before cleanup: `CDFF45C1E8CD9156CC3853E60D27BBDF395E52960585C1D4EC804BBD449AFDC1`
- Cleanup generated: `2026-08-11T12:47:17Z`
- Removed executable blocks: `5`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `126-128`
- Original language: `powershell`
- Block SHA256: `3F1E6DDEFB50EC54DE39B0714AA19A18C66557BB825CF22F6D02EE9DA40EA1EF`

```powershell
python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-class\Thread.md --uid-only
```

## Removed Block R002

- Original source lines: `697-699`
- Original language: `powershell`
- Block SHA256: `FC4925DD57A292B4B8182505C798E4D8E3B93AEDB061AE928AC2E8102A2CB9BC`

```powershell
cd E:\NTK\GhidraBridge\source-3\project-documentation
```

## Removed Block R003

- Original source lines: `703-710`
- Original language: `powershell`
- Block SHA256: `DA92BF6F62D33974E0B674AB340220A8C0FA3EFD0251646A42EFBE0680DA4F77`

```powershell
python tools\validator.py --mode file --file by-class\Thread.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-file\Thread.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x00596250-0x0059756e.ThreadAndThreadMan.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x00596620-0x005969b0.CashShopRequestWaitDispatch.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md --apply --queue-timeout 240
```

## Removed Block R004

- Original source lines: `714-719`
- Original language: `powershell`
- Block SHA256: `1499ACF63C9058FCF8C977544E0687DAF53511125901E39975A59EFF563EBB67`

```powershell
python tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --queue-timeout 240
python tools\validator.py --mode autogen --apply --queue-timeout 240
python tools\validator.py --mode rescore --apply --queue-timeout 240
```

## Removed Block R005

- Original source lines: `723-726`
- Original language: `powershell`
- Block SHA256: `2AFAB2D5604EC52EDD189DED868825738CC550D2B2432119EC46A5F8623BD646`

```powershell
rg -n "below the 95/95|90/90\\+|OnSignaled\\(\\)|QueueThreadEvent|CashShopRequestWaitDispatch|005967f0|RemoveLastWaitHandle|WaitForQueueDrain|OnWaitObject" by-class\Thread.md by-file\Thread.md by-memory\0x00596250-0x0059756e.ThreadAndThreadMan.md by-memory\0x00596620-0x005969b0.CashShopRequestWaitDispatch.md by-memory\0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md by-memory\0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md
rg -n "0000EV|0001JX|0001JY|0001JZ|0000WL" by-class\-coverage-report.md by-memory\-coverage-report.md auto-generated\-ag-class-coverage.md auto-generated\-ag-memory-coverage.md
```
