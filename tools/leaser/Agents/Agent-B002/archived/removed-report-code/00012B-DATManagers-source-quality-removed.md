<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00012B-DATManagers-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00012B-DATManagers-source-quality.md](00012B-DATManagers-source-quality.md)
- Source report SHA256 before cleanup: `BA56C5555985E1B9C076AFF22DA1CEDA09B3740E8D58EE6FA58E3C852E901DA3`
- Cleanup generated: `2026-08-11T12:47:00Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `793-815`
- Original language: `powershell`
- Block SHA256: `8BE2F095F0C664D71AACD83966222D7D3C0A0F6976E1D14075641205F8D59181`

```powershell
python .\tools\validator.py --mode file --file by-memory\0x0049bd30-0x0049d6ed.DATManagers.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-file\DATFileMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\DATFileMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\_DATFileMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\DATFileContainer.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-class\DATFileResolver.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-global\g_pDATFileMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0067ab40-0x0067ab44.g_pDATFileMgr.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049bd30-0x0049be41.DATFileMgrConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049be50-0x0049be6d.DATFileMgrDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049be80-0x0049c0c9.DATFileContainerConstructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049c0d0-0x0049c130.DATFileContainerDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049c700-0x0049c71d.HasDATEntry.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049cbb0-0x0049cc39.CreateDATEntryNode.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049d490-0x0049d4bd.AllocateDATEntryNode.md --apply --queue-timeout 240
python .\tools\validator.py --mode file --file by-memory\0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey.md --apply --queue-timeout 240
```
