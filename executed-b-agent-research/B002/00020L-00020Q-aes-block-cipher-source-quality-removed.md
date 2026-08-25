<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\00020L-00020Q-aes-block-cipher-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [00020L-00020Q-aes-block-cipher-source-quality.md](00020L-00020Q-aes-block-cipher-source-quality.md)
- Source report SHA256 before cleanup: `BB150588318E09F147A19735BC95CC04190CC4FA38103DFFB94C99B98BBAF699`
- Cleanup generated: `2026-08-11T12:47:01Z`
- Removed executable blocks: `1`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `216-232`
- Original language: `powershell`
- Block SHA256: `1CAEA21BC3C995B2CA26F310E31A291A4F2CC7602024DF45A65B06DEF2BD2C91`

```powershell
Set-Location E:\NTK\GhidraBridge\source-3\project-documentation
python tools\validator.py --mode file --file by-memory\0x00461790-0x0046189b.AesCbcEncryptRaw.md --apply
python tools\validator.py --mode file --file by-memory\0x004618a0-0x004619b8.AesCbcDecryptRaw.md --apply
python tools\validator.py --mode file --file by-memory\0x004619c0-0x00461c07.AesEncryptBlock.md --apply
python tools\validator.py --mode file --file by-memory\0x00461c10-0x00461dc7.AesDecryptBlock.md --apply
python tools\validator.py --mode file --file by-memory\0x00461dd0-0x00461fd4.AesInvMixColumns.md --apply
python tools\validator.py --mode file --file by-memory\0x00461fe0-0x00462114.AesKeySchedule128.md --apply
python tools\validator.py --mode file --file by-file\AesBlockCipher.md --apply
python tools\validator.py --mode file --file by-global\AesBlockCipherStateAndTables.md --apply
python tools\validator.py --mode file --file by-memory\0x00610fe8-0x006112e8.AesReadOnlyTables.md --apply
python tools\validator.py --mode file --file by-memory\0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md --apply
python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply
python tools\memory_ranges.py report
python tools\validator.py --mode autogen --apply --lock-timeout -1
python tools\validator.py --mode rescore --apply --lock-timeout -1
```
