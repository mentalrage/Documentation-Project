<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\executed-b-agent-research\B002\0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Executable Code Archive

- Source report: [0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality.md](0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality.md)
- Source report SHA256 before cleanup: `A5405F364D5D62339A6A1204BCDAB7E34CD0C1A3333C0440C2467A32C7898C01`
- Cleanup generated: `2026-08-11T12:47:03Z`
- Removed executable blocks: `2`
- Scope: exact executable or command-shaped fenced blocks removed from the source report by supervisor housekeeping.
- Authority: this file is not a B-agent research report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use any block in this archive as an operational instruction.

## Removed Block R001

- Original source lines: `371-381`
- Original language: `powershell`
- Block SHA256: `D9A56373091FB2843DF9BD046DDA7E27E6167EA838988046D64E95D3074BE037`

```powershell
$canonical = 'E:\NTK\Resources\NexusTK\NexusTK.exe.i64'
$stamp = Get-Date -Format 'yyyyMMdd-HHmmss'
$backup = "$canonical.bak-UID0004HV-prestate-$stamp"
Copy-Item -LiteralPath $canonical -Destination $backup -ErrorAction Stop
$canonicalItem = Get-Item -LiteralPath $canonical
$backupItem = Get-Item -LiteralPath $backup
$canonicalHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
$backupHash = (Get-FileHash -LiteralPath $backup -Algorithm SHA256).Hash
if (($canonicalItem.Length -ne $backupItem.Length) -or ($canonicalHash -cne $backupHash)) { throw 'UID0004HV prestate backup mismatch; abort before IDA mutation.' }
```

## Removed Block CLEANUP-20260813-0004HV-SECTION21

Source report: [0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality.md](0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality.md)

This block is non-authoritative and must never be executed. It receives no Gate, coverage, score, IDA, validator, or lifecycle credit. The following material is preserved verbatim from source artifact SHA256 `2F6B1B4C69C239AEA1258A799F46725F395EA0A2E05E59B3269AD4D8875F635C`.

<!-- BEGIN CLEANUP-20260813-0004HV-SECTION21 -->
## IDA Rename / Type / Comment Recommendations

The B agent made no IDA change. The following is a literal supervisor Gate 2B handoff. Every mutable prestate is accepted dated evidence from bounded `2026-08-04` research; most rows were last identity-reconfirmed at `2026-08-04T17:02:34.5363668-04:00`, I007 was corrected at `2026-08-04T19:27:00.0636866-04:00`, and I006-A was fully rebased at `2026-08-04T20:20:12-04:00`. None is permanent current authority. Before mutation, the supervisor must dynamically bind a healthy session, verify canonical disk identity, and reproduce every literal row below; any drift fails closed until separately reconciled.

| ID | Entity | Accepted dated pre-Gate2B snapshot | Proposed action | Evidence / expected readback |
| --- | --- | --- | --- | --- |
| I001 | Function `0x00542be0` | name `sub_542BE0`; type `int __thiscall(int this, int)`; address regular comment absent; address repeatable comment absent; function regular comment absent; function repeatable comment absent | Rename to `DLPalette_CopyConstructor`; apply `DLPalette *__thiscall DLPalette_CopyConstructor(DLPalette *this, const DLPalette *source)`; set function-repeatable comment `Deep-copies a DLPalette: copies the header and mapped-color table, duplicates optional two-byte palette-range records, and unwinds only the LObject base if allocation throws.` | Exact constructor body and source-quality signature. Read back name, declaration, all four comment channels, decompile, and complete stack frame. |
| I002 | Target frame | `var_10 +0x0c size4 LObject *`; `var_C +0x10 size4 _DWORD`; `var_4 +0x18 size4 _DWORD`; `saved +0x1c size4 _DWORD`; `return +0x20 size4 _UNKNOWN *`; `arg_0 +0x24 size4 _DWORD`; residual `arg_4 +0x28 size4 _DWORD` | The complete required post-`set_type` frame is exactly: `var_10 +0x0c size4 LObject *`; `var_C +0x10 size4 _DWORD`; `var_4 +0x18 size4 _DWORD`; `saved +0x1c size4 _DWORD`; `return +0x20 size4 _UNKNOWN *`; `source +0x24 size4 const DLPalette *`; residual `arg_4 +0x28 size4 _DWORD`. The sole permitted delta is `arg_0` name/type -> `source` / `const DLPalette *`; no row is added or removed and no other name, type, offset, or width changes. | A complete seven-row post-type frame readback must equal this literal state. Removal or alteration of residual `arg_4`, or any other delta, fails the transaction and requires rollback. |
| I003 | DLPalette UDT | UDT `DLPalette`, size `0x22c`, exactly five members: `vftable +0x00 width4 void *`; `m_entryMoves +0x04 width4 unsigned __int8 *`; `m_entryMoveCount +0x08 width4 int`; `m_paletteHeader +0x0c width32 unsigned __int8[32]`; `m_mappedColors +0x2c width512 unsigned __int16[256]`; no sixth member. UDT regular comment absent and UDT repeatable comment absent. For each of `vftable`, `m_entryMoves`, `m_entryMoveCount`, `m_paletteHeader`, and `m_mappedColors`, member regular comment absent and member repeatable comment absent. Exact UDT lookups `DLPaletteData`, `PaletteData`, and `DLPaletteRange` each return absent. | No UDT mutation. Protect the UDT name/size/count, every literal member name/type/offset/width, each separately enumerated UDT/member comment channel, all three absent lookup results, and no-sixth-member state. | Fresh preflight, immediate post-action protection pass, and fresh-reopen readback must reproduce every literal entity/channel independently. |
| I004 | Target range/items and fences | Target function range `[0x542be0,0x542c95)`, size `0xb5`, name `sub_542BE0`, type `int __thiscall(int this, int)`; its entry physical code item is separately `[0x542be0,0x542be1)`, width `0x1`, symbol `sub_542BE0`, item type `int __thiscall(int this, int)`. Target address regular absent, address repeatable absent, function regular absent, function repeatable absent, zero inbound xrefs, bytes/body SHA256 `22BC683E2EBBE5C16605E6FEC013CF683AC2A8D2BEE1A41A150932E53D075377`. Predecessor is one data item head `0x542bda`, range `[0x542bda,0x542be0)`, width `0x6`, bytes `CC CC CC CC CC CC`, no function object, item symbol/name absent, declared type absent, address regular absent, address repeatable absent, function regular/repeatable not applicable, zero inbound xrefs, SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`. Successor is one data item head `0x542c95`, range `[0x542c95,0x542ca0)`, width `0xb`, bytes `CC CC CC CC CC CC CC CC CC CC CC`, no function object, item symbol/name absent, declared type absent, address regular absent, address repeatable absent, function regular/repeatable not applicable, zero inbound xrefs, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`. | Protect every literal item/function/fence property. I001 permits only the target name, target function type, and target function-repeatable-comment deltas; every other target/fence channel remains exact. Create no function/data item and absorb no fence byte. | Immediate and fresh-reopen readback must reproduce both fence items exactly, the one-byte entry physical item, and the target function with only I001's three authorized deltas. |
| I005 | Target xrefs/pointers | zero inbound target xrefs; four exact little-endian start/end VA/RVA pattern searches each returned zero hits: `E0 2B 54 00`, `E0 2B 14 00`, `95 2C 54 00`, `95 2C 14 00` | Protect all five literal zero-result sets as negative evidence; bounded post-action and fresh-reopen readback must remain semantically unchanged. | Rename/type/comment must not manufacture references or encoded pointer hits. |
| I007 | EH support | Cleanup chunk `[0x605850,0x605858)` is part of target function `sub_542BE0`, not a standalone function, and has exactly two physical code items: `[0x605850,0x605853)` width `0x3`, symbol `loc_605850`, declared item type absent, address regular exactly `this`, address repeatable absent, inbound data xref `0x663044 -> 0x605850`, fall-through `0x605850 -> 0x605853`; `[0x605853,0x605858)` width `0x5`, symbol/type absent, address regular absent, address repeatable absent, inbound fall-through from `0x605850`, outbound jump `0x605853 -> LObject_destructor(0x4f4a90)`. Function comments/frame are not independently applicable to either remote chunk item. Chunk bytes SHA256 `7F903871BEB9D3A21146BC08590F73C2666704187F43FFE57856863D15BEB945`. Handler chunk `[0x605858,0x605873)` is part of `sub_542BE0`, not a standalone function, has exact chunk symbol `SEH_542BE0`, inbound data xref `0x542be5 -> 0x605858`, bytes SHA256 `251BB10FBB3D3538F71DBECCEC4BBE139967CE477DD133F76D4EA6B108169A77`, and exactly seven physical code items: `[0x605858,0x60585c)` width4 symbol `SEH_542BE0`, `[0x60585c,0x60585f)` width3 symbol absent, `[0x60585f,0x605862)` width3 symbol absent, `[0x605862,0x605864)` width2 symbol absent/address regular exactly `StackCookie`, `[0x605864,0x605869)` width5 symbol absent/outbound call to `@__security_check_cookie@4(0x5c772f)`, `[0x605869,0x60586e)` width5 symbol absent/outbound data xref to `0x6631e0`, `[0x60586e,0x605873)` width5 symbol absent/outbound jump to `___CxxFrameHandler3(0x5c956c)`. Every handler item has declared type absent and address repeatable absent; address regular is absent except exact `StackCookie` at `0x605862`; function comment/frame channels are not independently applicable. EH-table is one data item `[0x6631e0,0x663204)` width `0x24`; `inspect_items` display name is exactly `stru_6631E0`, exact names-index query over `[0x6631d0,0x663210)` returns zero explicit rows, declared type absent, address regular absent, address repeatable absent, no function/comment/frame channels, bytes SHA256 `21B21D09DAD7A54C50C5AAAA801B4D7D7B629746FBD998F9A76F553E46CFC24A`; exact xrefs are inbound data `0x605869 -> 0x6631e0` and outbound data `0x6631e0 -> 0x663044` plus tool-rendered `0x6631e0 -> 0xff000000000081a8`. | No EH action. Protect every enumerated item/range/width/kind/symbol/type/frame/comment/xref/byte property independently. | Clearing/changing cleanup regular `this`, handler regular `StackCookie`, either chunk/table symbol/display, any absent repeatable channel, any item boundary, or any relation fails closed. Immediate and fresh-reopen readbacks must match every literal row. |
| I008 | Candidate record type | Exact UDT lookup `DLPaletteData`: absent; exact UDT lookup `PaletteData`: absent; exact UDT lookup `DLPaletteRange`: absent. | No IDA UDT creation, declaration rewrite, member addition, or candidate-type mutation. | Formal source may infer `DLPaletteRange`; all three literal lookup results must remain absent through immediate and fresh-reopen readback. |

I006 protected dependencies are intentionally outside the action table because they receive no mutation. The supervisor must reread every listed prestate before I001 and verify the same listed state immediately after I001 and after fresh reopen:

| I006 item | Exact protected prestate | Deterministic readback |
| --- | --- | --- |
| I006-A LObject base constructor | Accepted external UID0003OO dated state, reconfirmed read-only after exclusive-window release: function `[0x4f4a80,0x4f4a89)`, unique name `LObject_constructor`, size `0x9`, type `LObject *__thiscall(LObject *this)`, frame exactly `__return_address +0x0 size0x4 _UNKNOWN *`; address regular absent; address repeatable absent; function regular exactly `LObject::LObject base constructor. Installs the LObject primary vtable at this+0x00 and returns this; the human constructor body is empty.`; function repeatable absent. Code items exactly `[0x4f4a80,0x4f4a86)`, `[0x4f4a86,0x4f4a88)`, `[0x4f4a88,0x4f4a89)`. Bytes `C7 01 68 CF 61 00 8B C1 C3`, SHA256 `B022A69F4751DE10FECAED5A4137C3A24C361E944430A217BBE2B0F7686B0EF0`; outgoing refs code fall-through `0x4f4a86` and data `0x61cf68` (`??_7LObject@@6B@`). Exactly 195 inbound code-xref addresses, normalized as numerically sorted uppercase eight-digit hexadecimal joined by `\n` with no trailing newline, hash to `347534B3CEAA32D719903F81B34A08026DAF0CE6EE56835119C61FFAA879405D`; prior report/tool representation hash `DB57B86CC1144C532377F864FD7038931B2275C6B6A9B9B2D81B8FDF917E48FB` and 157 modeled-identity hash `0A6D31A6BA725C6C6C93C21E3CC6944113C5E99A6ADAFB6E5340335A21C99D1D` remain dated history. Ten unmodeled sites are `0x4a61ba`, `0x4a633a`, `0x4a63ea`, `0x5039fa`, `0x584dca`, `0x58766f`, `0x5876a8`, `0x58a86f`, `0x58a8a8`, `0x594e6a`; target-family calls are `0x542bba` and `0x542c0a`; exact-name function/name queries each total one at `0x4f4a80`. | No mutation. Immediate, fresh-reopen, no-save rollback, and saved rollback proofs separately require address regular absent, address repeatable absent, exact function regular sentence, and function repeatable absent, plus every other literal property unchanged. Never restore superseded pre-UID0003OO state. |
| I006-B DLPalette default constructor | Function `[0x542bb0,0x542bda)`, name `sub_542BB0`, size `0x2a`, type `void __thiscall(_DWORD *this)`; complete frame exactly `var_4 +0x4 size4 _DWORD`, `saved +0x8 size4 _DWORD`, `return +0x0c size4 _UNKNOWN *`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; body SHA256 `DE25B9CF081C8D1EC3A20A23A8105DA21E29C2785405E19CDA8A7A01E52CDA4F`. | No mutation. Exact range/name/size/type, all three frame rows, all four comment channels, and body hash remain unchanged immediately and after fresh reopen. |
| I006-C DLPalette destructor | Function `[0x542ca0,0x542ccf)`, name `sub_542CA0`, size `0x2f`, type `void __thiscall(LObject *this)`; complete frame exactly `return +0x4 size4 _UNKNOWN *`; address regular absent; address repeatable absent; function regular absent; function repeatable absent; body SHA256 `D9438998C2B416BE5B073A51F47EF56071C51BF4AAF32A39CC014426E9CA32E4`. | No mutation. Exact range/name/size/type, one frame row, four comment channels, and body hash remain unchanged immediately and after fresh reopen. |
| I006-D raw CopyPaletteState helper | Raw executable `[0x542d00,0x542d81)`, no IDA function, function name/type/frame absent, range-head address regular absent, range-head address repeatable absent, function regular/repeatable not applicable, zero inbound xrefs, body SHA256 `F42A78BAF1B050B16B1953B7337C67AF11BF871707BEC9FEBE3E9D7789A98346`; exact 48-item inventory is enumerated below. | No mutation. Exact non-function state, every item head/range/width/kind/name/type/comment/xref property, bytes/hash, and zero start-xref state remain unchanged immediately and after fresh reopen; no function is created. |
| I006-E allocator | Function `[0x5c7790,0x5c7799)`, name `unknown_libname_19`, size `0x9`, type `void *__cdecl(size_t)`; address regular absent; address repeatable absent; function regular absent; function repeatable exactly `Microsoft VisualC 14/net runtime`; body SHA256 `E67AE64ED97DE43D9A47D5161945F5B2DE2E1D8D922C5711ED6E7CE5CB813919`. The complete sorted 163 direct-rel32 caller-address set has normalized uppercase-eight-hex/newline SHA256 `A7A2FC2135AA6C945DE6CADCC4BBB2477F35D6B1E442869AE6EA62D250C0F939`; exact set is enumerated below. | No mutation. Exact function identity/type/four comment channels/body hash and full caller-set hash/count remain unchanged immediately and after fresh reopen; count-only equality is insufficient. |

**I006-D literal physical-item inventory.** Read-only PE/Capstone decoding of the exact 129 bytes whose SHA256 is `F42A78BAF1B050B16B1953B7337C67AF11BF871707BEC9FEBE3E9D7789A98346` yields these 48 instruction items, each `kind=code`, with exact head/end/width: `[0x542d00,0x542d01)/1`, `[0x542d01,0x542d03)/2`, `[0x542d03,0x542d04)/1`, `[0x542d04,0x542d07)/3`, `[0x542d07,0x542d08)/1`, `[0x542d08,0x542d0a)/2`, `[0x542d0a,0x542d0e)/4`, `[0x542d0e,0x542d12)/4`, `[0x542d12,0x542d16)/4`, `[0x542d16,0x542d1a)/4`, `[0x542d1a,0x542d1d)/3`, `[0x542d1d,0x542d20)/3`, `[0x542d20,0x542d24)/4`, `[0x542d24,0x542d26)/2`, `[0x542d26,0x542d29)/3`, `[0x542d29,0x542d2b)/2`, `[0x542d2b,0x542d30)/5`, `[0x542d30,0x542d32)/2`, `[0x542d32,0x542d35)/3`, `[0x542d35,0x542d37)/2`, `[0x542d37,0x542d39)/2`, `[0x542d39,0x542d3a)/1`, `[0x542d3a,0x542d3f)/5`, `[0x542d3f,0x542d42)/3`, `[0x542d42,0x542d45)/3`, `[0x542d45,0x542d47)/2`, `[0x542d47,0x542d48)/1`, `[0x542d48,0x542d4b)/3`, `[0x542d4b,0x542d4c)/1`, `[0x542d4c,0x542d51)/5`, `[0x542d51,0x542d54)/3`, `[0x542d54,0x542d57)/3`, `[0x542d57,0x542d5a)/3`, `[0x542d5a,0x542d5f)/5`, `[0x542d5f,0x542d61)/2`, `[0x542d61,0x542d62)/1`, `[0x542d62,0x542d63)/1`, `[0x542d63,0x542d64)/1`, `[0x542d64,0x542d67)/3`, `[0x542d67,0x542d6e)/7`, `[0x542d6e,0x542d71)/3`, `[0x542d71,0x542d74)/3`, `[0x542d74,0x542d79)/5`, `[0x542d79,0x542d7b)/2`, `[0x542d7b,0x542d7c)/1`, `[0x542d7c,0x542d7d)/1`, `[0x542d7d,0x542d7e)/1`, `[0x542d7e,0x542d81)/3`.

- For each of those 48 items: declared item type absent; source/user name absent; address regular comment absent; address repeatable comment absent; no enclosing standalone function, so function regular/repeatable channels and function frame are not applicable. Auto name is absent for every item except exact branch target `0x542d67`, whose accepted auto name is `loc_542D67`. Non-fallthrough xrefs are exactly: code jump `0x542d24 -> 0x542d67`, call `0x542d3a -> 0x5c7790`, and call `0x542d4c -> 0x5c95b0`; `0x542d67` has exactly the one listed inbound branch and range head `0x542d00` has zero inbound xrefs. All other listed items have no non-fallthrough outbound xref and no separately named inbound xref. Gate 2B must reproduce this complete item inventory with bounded `inspect_items`/xref calls before mutation and after mutation/reopen; any mismatch fails before save.

**I006-E complete normalized caller set.** The sorted 163 direct-rel32 caller addresses are normalized as uppercase eight-digit hexadecimal, one address per line with `\n` separators and no trailing newline; SHA256 must equal `A7A2FC2135AA6C945DE6CADCC4BBB2477F35D6B1E442869AE6EA62D250C0F939`. The exact set is:

```text
00422266 004225F4 00422A75 00422F4B 00425105 00428360 00454369 00454DCB 0045664E 004566AA
004568AE 0045690A 00456F16 004577C4 004578A8 00457917 00457985 004579A2 004621D2 004622B8
00465B2E 004665E1 00470088 0047B2C1 0047B2D1 0047B2E1 0047B30C 0047B31C 0047BB4B 0047BB5B
0047BB6B 0047BB96 0047BBA6 0048EB95 00492958 00493A73 00493B33 00493BE3 004A1654 004A1971
004A2016 004A3B23 004A5408 004A5500 004A5C03 004A6808 004AA07E 004B90D0 004D066C 004D10FD
004D114D 004D1912 004D1C12 004D1C59 004D2BE6 004D3096 004D327A 004D3451 004D367C 004D38AC
004D3AC4 004D3CE2 004D3F02 004D411D 004DACCC 004DB942 004DB989 004DC49C 004DD14A 004DDAF2
004DDB39 004DE4B2 004DE4F9 004DE8C8 004DE9D7 004DE9EE 004DEB8F 004DED36 004DF586 004DF8C5
004DFF48 004E0F2A 004E0F62 004E111D 004E14FA 004E15A1 004E15E6 004E1642 004E16F8 004E1A8B
004E1AD4 004E6AC3 004E6B5A 004E6CC8 004EFCD5 004F4D09 004F4D3B 004F4DD9 004F50FD 004F5130
004F51CE 004F6F83 004F6FC9 004F7013 004F7052 004F706A 00503B7A 00503F32 00503FAD 00504FBE
00506763 0050A5B9 0050A61A 0050C7E8 0050C7F4 0050D068 0050D074 0050E2C5 0050F77B 00514F07
00522F63 00523538 00523688 00524763 0052482F 00527A51 00528A1D 00528C2D 00542C4F 00542D3A
00542EA3 0054352A 005442FC 0054767B 005477C6 005494D5 00549BDE 0054BDD5 00558C8D 00558CA5
00558D1C 00558D55 00577C2C 00577C84 00577D90 00577FEF 00578118 0057838A 0057841C 00578544
00578ED9 0058243B 00582E08 00582EBC 005918DD 0059947F 00599516 005A27AD 005A2AB7 005A7C0D
005A9326 005ABBA4 005C8D37
```

The line-wrapped display above is presentation only; Gate 2B normalization splits on whitespace, sorts numerically, formats each address as uppercase eight-digit hexadecimal, joins with `\n`, and hashes the resulting 163-line byte string. This binds the full set rather than only the count. Exact target-family members `00542C4F` and raw-helper member `00542D3A` must both be present.

Historical failed transaction note: at `2026-08-04T19:27:00.0636866-04:00`, primary Gate 2B preflight reproduced cleanup item `[0x605850,0x605853)`, auto name `loc_605850`, address regular comment `this`, and repeatable blank, contradicting the former absent-comment I007 row. The supervisor stopped before mutation/save, so no rollback write was required. The failed preflight is dated evidence only; another attempt must dynamically revalidate the corrected I007 prestate.

Historical external-transaction/rebase note: the separately accepted/executed UID0003OO transaction changed I006-A to `LObject_constructor` with the exact source-quality type and function regular comment above. A later UID0004HV Gate 2B preflight detected the report drift and stopped before mutation/save. B002's `2026-08-04T20:20:12-04:00` bounded recheck accepted the live UID0003OO state as protection-only prestate; neither UID0004HV action nor rollback may revert it.

Released-window read-only reconciliation note: after the supervisor released the MCP exclusive window, B002 dynamically bound the already-running healthy session and performed only bounded reads. The pass changed no IDA state and corrected report text only: I006-C type is `void __thiscall(LObject *this)`; I007 is the exact two-item cleanup/seven-item handler/table inventory above, including `SEH_542BE0`, regular `StackCookie` at `0x605862`, and `stru_6631E0` display with no explicit table names-index row. The same pass supplied reproducible 195-address I006-A hash `347534B3CEAA32D719903F81B34A08026DAF0CE6EE56835119C61FFAA879405D`. These facts remain a dated snapshot and must be dynamically reread by the supervisor.

Deterministic Gate 2B transaction package:

**Itemized C0004HV-024 through C0004HV-028 transaction records**

- `C0004HV-024` / I001 mutation record: prestate is target name `sub_542BE0`, type `int __thiscall(int this, int)`, address regular absent, address repeatable absent, function regular absent, function repeatable absent. The only action is the literal rename, function-type write, and function-repeatable-comment write below. Immediate and fresh-reopen readback require name `DLPalette_CopyConstructor`, type `DLPalette *__thiscall DLPalette_CopyConstructor(DLPalette *this, const DLPalette *source)`, address regular absent, address repeatable absent, function regular absent, and the exact new function-repeatable sentence. All I003-I008 dependencies are protected. Any mismatch after the first mutation triggers the single phase-bound rollback policy below; any pre-mutation mismatch aborts without mutation.
- `C0004HV-025` / I002 frame record: the `set_type` call is the only action that may affect the frame. Immediate and fresh-reopen frame readback must contain exactly seven rows: `var_10 +0x0c size4 LObject *`, `var_C +0x10 size4 _DWORD`, `var_4 +0x18 size4 _DWORD`, `saved +0x1c size4 _DWORD`, `return +0x20 size4 _UNKNOWN *`, `source +0x24 size4 const DLPalette *`, residual `arg_4 +0x28 size4 _DWORD`. The only permitted physical delta from prestate is `arg_0` -> `source` and `_DWORD` -> `const DLPalette *`; any other row/name/type/offset/width/addition/removal triggers rollback.
- `C0004HV-026` / I004-I007 protection record: no protection entity is mutated. Immediate and fresh-reopen readbacks must match I004 target/fences, I005 five zero-result sets, I006-A exact accepted external name/type/four channels/frame/items/bytes/reproducible 195-xref hash, I006-B/C complete frames and four channels including I006-C `LObject *this`, I006-D all 48 items and three non-fallthrough xrefs, I006-E exact 163-caller normalized set/hash, and I007's complete two-item cleanup/seven-item named handler/table properties and comments. Any drift triggers rollback; preflight drift aborts before mutation.
- `C0004HV-027` / I003-I008 no-action record: no UDT is mutated or created. Immediate and fresh-reopen readbacks require the exact five-member `DLPalette` UDT, every per-entity/per-channel absent comment, no sixth member, and exact absent lookups for `DLPaletteData`, `PaletteData`, and `DLPaletteRange`. Any drift triggers rollback; inability to read the required state aborts before mutation.
- `C0004HV-028` / transaction-control record: dynamically bind one healthy canonical session; create and verify the timestamped backup; execute the complete preflight and dry run; apply only I001; perform immediate and unsaved full protection readback; save exactly once; record disk identity; close only the bound worker while preserving the listener; fresh-reopen under a different session; rerun every action/protection readback. The deterministic rollback policy below has no discretionary branch: pre-save failures use exact reverse calls followed by unsaved-worker discard/reopen verification; post-save persistence failures restore the exact prestate backup and reopen/verify it.

**Literal dynamic bind and backup**

```text
idb_list {}
server_health {"database":"<gate2b-database>"}
```

The supervisor selects exactly one healthy session bound to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, records `<gate2b-database>` and `<gate2b-worker-pid>`, and independently rereads canonical path, size, SHA256, and last-write time. Fixed report session/PID/hash values are historical only. Before mutation, execute this exact backup shape and require byte-identical size/hash:

> Executable block R001 was removed from this report and preserved verbatim in [0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality-removed.md](0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

**Literal bounded preflight calls**

Every call below is read-only and every address/entity/region batch contains ten or fewer elements. Compare results literally with I001-I008; a missing field, unexpected extra item/member/xref/comment, collision, or unsupported query aborts before mutation.

```text
lookup_funcs {"database":"<gate2b-database>","queries":["0x00542be0","0x004f4a80","0x00542bb0","0x00542ca0","0x00542d00","0x005c7790","DLPalette_CopyConstructor","LObject_constructor","sub_542BE0","unknown_libname_19"]}
lookup_funcs {"database":"<gate2b-database>","queries":["0x00605850","0x00605858","SEH_542BE0","0x006631e0","stru_6631E0"]}
entity_query {"database":"<gate2b-database>","queries":{"kind":"names","regex":"^(DLPalette_CopyConstructor|LObject_constructor|sub_542BE0|unknown_libname_19)$","offset":0,"count":10,"sort_by":"addr","descending":false,"fields":["addr","name"]}}
entity_query {"database":"<gate2b-database>","queries":[{"kind":"names","min_addr":"0x00605840","max_addr":"0x00605880","offset":0,"count":10,"sort_by":"addr","descending":false,"fields":["addr","name"]},{"kind":"names","min_addr":"0x006631d0","max_addr":"0x00663210","offset":0,"count":10,"sort_by":"addr","descending":false,"fields":["addr","name"]}]}
stack_frame {"database":"<gate2b-database>","addrs":["0x00542be0","0x004f4a80","0x00542bb0","0x00542ca0"]}
get_comments {"database":"<gate2b-database>","addrs":["0x00542be0","0x004f4a80","0x00542bb0","0x00542ca0","0x00542d00","0x005c7790"]}
get_comments {"database":"<gate2b-database>","addrs":["0x00605850","0x00605853","0x00605858","0x0060585c","0x0060585f","0x00605862","0x00605864","0x00605869","0x0060586e","0x006631e0"]}
inspect_items {"database":"<gate2b-database>","addrs":["0x00542bda","0x00542be0","0x00542c95","0x004f4a80","0x004f4a86","0x004f4a88","0x00542bb0","0x00542ca0","0x005c7790"]}
inspect_items {"database":"<gate2b-database>","addrs":["0x00605850","0x00605853","0x00605858","0x0060585c","0x0060585f","0x00605862","0x00605864","0x00605869","0x0060586e","0x006631e0"]}
get_bytes {"database":"<gate2b-database>","regions":[{"addr":"0x00542bda","size":6},{"addr":"0x00542be0","size":181},{"addr":"0x00542c95","size":11},{"addr":"0x004f4a80","size":9},{"addr":"0x00542bb0","size":42},{"addr":"0x00542ca0","size":47},{"addr":"0x00542d00","size":129},{"addr":"0x005c7790","size":9},{"addr":"0x00605850","size":8},{"addr":"0x00605858","size":27}]}
get_bytes {"database":"<gate2b-database>","regions":[{"addr":"0x006631e0","size":36}]}
xrefs_to {"database":"<gate2b-database>","addrs":["0x00542bda","0x00542be0","0x00542c95","0x004f4a80","0x00542bb0","0x00542ca0","0x00542d00","0x005c7790","0x00605850","0x00605858"],"limit":1000}
xref_query {"database":"<gate2b-database>","queries":[{"addr":"0x004f4a80","direction":"both","count":1000,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00542d24","direction":"both","count":20,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00542d3a","direction":"both","count":20,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00542d4c","direction":"both","count":20,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}]}
xref_query {"database":"<gate2b-database>","queries":[{"addr":"0x00605850","direction":"both","count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00605853","direction":"both","count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00605858","direction":"both","count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0060585c","direction":"both","count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0060585f","direction":"both","count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00605862","direction":"both","count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00605864","direction":"both","count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x00605869","direction":"both","count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x0060586e","direction":"both","count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false},{"addr":"0x006631e0","direction":"both","count":50,"include_fn":true,"dedup":true,"sort_by":"addr","descending":false}]}
find_bytes {"database":"<gate2b-database>","patterns":["E0 2B 54 00","E0 2B 14 00","95 2C 54 00","95 2C 14 00"],"limit":10}
type_inspect {"database":"<gate2b-database>","queries":{"name":"DLPalette","include_members":true,"max_members":10}}
type_inspect {"database":"<gate2b-database>","queries":{"name":"DLPaletteData","include_members":true,"max_members":10}}
type_inspect {"database":"<gate2b-database>","queries":{"name":"PaletteData","include_members":true,"max_members":10}}
type_inspect {"database":"<gate2b-database>","queries":{"name":"DLPaletteRange","include_members":true,"max_members":10}}
decompile {"database":"<gate2b-database>","addr":"0x00542be0","include_addresses":true}
```

I006-D's 48 item heads are read in these exact batches; each result must match the literal inventory and common/per-item properties above:

```text
inspect_items {"database":"<gate2b-database>","addrs":["0x00542d00","0x00542d01","0x00542d03","0x00542d04","0x00542d07","0x00542d08","0x00542d0a","0x00542d0e","0x00542d12","0x00542d16"]}
inspect_items {"database":"<gate2b-database>","addrs":["0x00542d1a","0x00542d1d","0x00542d20","0x00542d24","0x00542d26","0x00542d29","0x00542d2b","0x00542d30","0x00542d32","0x00542d35"]}
inspect_items {"database":"<gate2b-database>","addrs":["0x00542d37","0x00542d39","0x00542d3a","0x00542d3f","0x00542d42","0x00542d45","0x00542d47","0x00542d48","0x00542d4b","0x00542d4c"]}
inspect_items {"database":"<gate2b-database>","addrs":["0x00542d51","0x00542d54","0x00542d57","0x00542d5a","0x00542d5f","0x00542d61","0x00542d62","0x00542d63","0x00542d64","0x00542d67"]}
inspect_items {"database":"<gate2b-database>","addrs":["0x00542d6e","0x00542d71","0x00542d74","0x00542d79","0x00542d7b","0x00542d7c","0x00542d7d","0x00542d7e"]}
```

Normalize I006-A's 195 inbound addresses and I006-E's 163 caller addresses exactly as each row specifies, then verify the recorded hashes; count equality alone does not pass. `DLPalette_CopyConstructor` collision queries must return zero; `LObject_constructor` must resolve uniquely to `0x4f4a80` and is protection-only.

**Literal dry run, mutation, and immediate readback**

```text
rename {"database":"<gate2b-database>","batch":{"func":[{"addr":"0x00542be0","name":"DLPalette_CopyConstructor"}],"stop_on_error":true,"dry_run":true,"allow_overwrite":false}}
rename {"database":"<gate2b-database>","batch":{"func":[{"addr":"0x00542be0","name":"DLPalette_CopyConstructor"}],"stop_on_error":true,"dry_run":false,"allow_overwrite":false}}
set_type {"database":"<gate2b-database>","edits":[{"addr":"0x00542be0","kind":"function","signature":"DLPalette *__thiscall DLPalette_CopyConstructor(DLPalette *this, const DLPalette *source)"}]}
set_repeatable_comments {"database":"<gate2b-database>","items":[{"addr":"0x00542be0","comment":"Deep-copies a DLPalette: copies the header and mapped-color table, duplicates optional two-byte palette-range records, and unwinds only the LObject base if allocation throws."}]}
lookup_funcs {"database":"<gate2b-database>","queries":["0x00542be0","DLPalette_CopyConstructor","sub_542BE0"]}
stack_frame {"database":"<gate2b-database>","addrs":["0x00542be0"]}
get_comments {"database":"<gate2b-database>","addrs":["0x00542be0"]}
decompile {"database":"<gate2b-database>","addr":"0x00542be0","include_addresses":true}
```

Immediately rerun every bounded protection call above before save. The target must have only the three I001 deltas and exact seven-row I002 postframe. I006-A must separately read address regular absent, address repeatable absent, the exact function regular sentence, and function repeatable absent. Every I003/I004/I005/I006/I007/I008 property must match. Any mismatch enters the deterministic rollback policy and no save occurs.

**Literal save and fresh-reopen persistence proof**

```text
idb_save {"database":"<gate2b-database>","path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"}
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"prefer_headless","run_auto_analysis":false,"build_caches":true,"init_hexrays":true,"idle_ttl_sec":3600,"preferred_session_id":"b002-uid0004hv-persist-reopen"}
```

Save exactly once only after the complete unsaved readback passes; record result and canonical post-save size/SHA256/last-write. The supervisor then closes only `<gate2b-worker-pid>` through its controlled worker path, confirms the listener remains up and the old session is absent, opens the fresh persistence session above, records the distinct session/PID, calls `server_health`, and reruns every poststate/action/protection call. No save follows persistence verification.

**Single deterministic rollback policy**

- Before first mutation: any failure aborts with no rollback.
- After first mutation but before `idb_save`: the supervisor records the failed invariant and runs the exact reverse calls below in order. These reverse calls are not permission to continue. Whether they pass or fail, the supervisor does not save, closes only the bound worker, proves canonical disk identity still equals the captured prestate, opens `b002-uid0004hv-nosave-rollback-verify`, and reruns the complete original I001-I008 prestate package. This is the only no-save rollback path.

```text
set_repeatable_comments {"database":"<gate2b-database>","items":[{"addr":"0x00542be0","comment":""}]}
set_type {"database":"<gate2b-database>","edits":[{"addr":"0x00542be0","kind":"function","signature":"int __thiscall DLPalette_CopyConstructor(int this, int)"}]}
rename {"database":"<gate2b-database>","batch":{"func":[{"addr":"0x00542be0","name":"sub_542BE0"}],"stop_on_error":true,"dry_run":true,"allow_overwrite":false}}
rename {"database":"<gate2b-database>","batch":{"func":[{"addr":"0x00542be0","name":"sub_542BE0"}],"stop_on_error":true,"dry_run":false,"allow_overwrite":false}}
lookup_funcs {"database":"<gate2b-database>","queries":["0x00542be0","sub_542BE0","DLPalette_CopyConstructor"]}
stack_frame {"database":"<gate2b-database>","addrs":["0x00542be0"]}
get_comments {"database":"<gate2b-database>","addrs":["0x00542be0","0x004f4a80","0x00605850"]}
```

```text
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"prefer_headless","run_auto_analysis":false,"build_caches":true,"init_hexrays":true,"idle_ttl_sec":3600,"preferred_session_id":"b002-uid0004hv-nosave-rollback-verify"}
```

The no-save rollback verifier must reproduce the exact original target name/type/four comment channels/seven-row preframe, all target/fence bytes/items/xrefs, I003 exact five-member/three-absent-type state, all I006 dependencies including the four separate I006-A comment channels and full I006-D/I006-E sets, and all I007/I008 properties. It must not save.

- If `idb_save` returned success but fresh persistence readback fails: the deterministic saved branch records the failed invariant, stops the persistence worker, proves no session remains bound to canonical, restores exactly `$backup` over `$canonical`, verifies restored size/SHA256 equal both backup and captured prestate, opens `b002-uid0004hv-saved-rollback-verify`, and reruns the complete original I001-I008 prestate package. It must not save. This is not an alternative choice; it is the mandatory post-save branch of the same rollback policy.

> Executable block R002 was removed from this report and preserved verbatim in [0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality-removed.md](0004HV-DLPaletteCopyConstructor-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

```text
idb_open {"input_path":"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64","mode":"prefer_headless","run_auto_analysis":false,"build_caches":true,"init_hexrays":true,"idle_ttl_sec":3600,"preferred_session_id":"b002-uid0004hv-saved-rollback-verify"}
```

Both rollback verifiers must separately prove I006-A address regular absent, address repeatable absent, exact function regular sentence, and function repeatable absent; they must also prove every target frame/item, I006-D item, I006-E caller-set hash, and I007 comment/item channel. Any rollback mismatch halts the larger supervisor goal. B002 did not run any call, backup, mutation, process-control, save, reopen, or rollback operation.
<!-- END CLEANUP-20260813-0004HV-SECTION21 -->

## Removed Block R002

- Original source lines: `469-474`
- Original language: `powershell`
- Block SHA256: `C7F36F2E46CC3954DAAC5BB09C3184DAF7AB263D99704EB429DE628EA42A7CB9`

```powershell
Copy-Item -LiteralPath $backup -Destination $canonical -Force -ErrorAction Stop
$restoredItem = Get-Item -LiteralPath $canonical
$restoredHash = (Get-FileHash -LiteralPath $canonical -Algorithm SHA256).Hash
if (($restoredItem.Length -ne $backupItem.Length) -or ($restoredHash -cne $backupHash) -or ($restoredHash -cne $canonicalHash)) { throw 'UID0004HV saved rollback restore mismatch; halt.' }
```
