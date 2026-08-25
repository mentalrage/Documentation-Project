<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B014\0002IP-KeySpeedMgrConstructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0002IP-KeySpeedMgrConstructor-source-quality.md](0002IP-KeySpeedMgrConstructor-source-quality.md)
- Source report SHA256 before cleanup: `4E0DE652940726F8C0FA80DF0F01833DDD802ABC729F0FE454B917EC9F14FBF6`
- Cleanup generated: `2026-08-11T12:47:18Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `511-522`
- Original language: `powershell`
- Block SHA256: `4F208CEFFD02C2A838A57A41EF3B202D9B5EA7447F2F76F4BEFC763A04450983`

```powershell
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-memory\0x004efea0-0x004efedd.KeySpeedMgrConstructor.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-class\KeySpeedMgr.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-file\KeySpeedMgr.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-memory\0x004efea0-0x004f0008.KeySpeedMgr.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-type\by-struct\KeySpeedMgrLayout.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-type\by-vtable\KeySpeedMgrVtable.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-memory\0x0061c9c4-0x0061c9dc.KeySpeedMgrVtableData.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode file --file 'by-memory\-coverage-report.md'
python 'E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py' --mode autogen
rg -n "0002IP|KeySpeedMgr::KeySpeedMgr|m_savedKeyboardDelay|m_savedKeyboardSpeed|g_pKeySpeedMgr = this" 'E:\NTK\GhidraBridge\source-3\project-documentation'
```
