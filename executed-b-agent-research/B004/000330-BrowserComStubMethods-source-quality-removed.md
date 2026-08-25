<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B004\000330-BrowserComStubMethods-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [000330-BrowserComStubMethods-source-quality.md](000330-BrowserComStubMethods-source-quality.md)
- Source report SHA256 before cleanup: `616D4AC071E6A5AC55F6EA295123016FBB1BDD1BAA8DE791D8FBED0DAFA4892D`
- Cleanup generated: `2026-08-11T12:47:07Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `610-615`
- Original language: `powershell`
- Block SHA256: `2922E6BE398B18E630A06188DBD6F0D284619A94ACAD4838D75D311F6F4A9675`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0046f670-0x0046f808.BrowserComStubMethods.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\Browser.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0046f540-0x0046f66f.BrowserQueryInterface.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x006131b4-0x006139df.BrowserVtablesAndStrings.md --apply --queue-timeout 240
```

## Removed Block R002

- Original source line: `53`
- Original representation: inline PowerShell command
- Source report SHA256 before this cleanup: `B3EEBB2ADA90F6506E46223CE2C65BF67195FF73BFE8DC88F65BEC3338F87FBD`
- Block SHA256: `A62F970DDA785152054C3AD2748B3B043BE643B789BE8EC1EF9F72F1ED56C102`

```powershell
Invoke-WebRequest http://127.0.0.1:13337/mcp
```
