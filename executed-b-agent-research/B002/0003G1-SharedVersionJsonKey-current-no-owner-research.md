** TARGET-REPORT-UID:0003G1 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G1 **
# 0003G1 SharedVersionJsonKey current no-owner research

## Final recommendation

Keep [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](../../../by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) as:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000JE,0000O5
COMPLETION:88
CONFIDENCE:93
```

No by-* documentation edit, split, merge, reclassification, IDA-safe rename, or shared coverage-report edit is recommended. The current state is not a non-emitting dead end: the literal has three proven source-use routes into generated file roots, but no single declaration owner clears the canonical-owner bar.

Code-entry gate: the metadata clears the minimum gate (`RECONSTRUCTABLE:TRUE`, nonblank confirmed emitters, and `(88+93)/2 = 90.5 > 85`), but this report does not recommend entering standalone C++ for the data item. Reconstructed consumers should spell `"version"` at each parse use unless later source/debug evidence proves a real shared named constant.

## Target and scope

- Target: [UID:0003G1] `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`
- Current generated status checked: `no-owner`, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`
- Current target score: `COMPLETION:88`, `CONFIDENCE:93`
- After this pass: unchanged `88/93`
- Assignment scope: current Goal 2 no-owner ownership/emitter research only. I did not edit by-* files or `by-memory/-coverage-report.md`.

## Evidence standard used

I treated prior reports and current prose as leads only. The recommendation is based on current target metadata, generated coverage, related owner/emitter docs, live IDA MCP output, and raw PE byte scans. The canonical-owner test used by-structure routing: a file/class/global can own the item only if it is the defensible source declaration owner, not merely one of several use sites or a physical neighbor in `.rdata`.

## Current documentation state

The target header already records the right no-owner/multi-emitter state:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JC,0000JE,0000O5`
- blank `RECONSTRUCTION_CPP`

The target body describes the exact range as narrow ASCII `version` at `0x0060d94c-0x0060d954`, four zero alignment bytes at `0x0060d954-0x0060d958`, and the successor wide URL at `0x0060d958`. It lists the three source-use xrefs:

- `0x0041ad2e` in [UID:0002TS][DownloadCashShopVersion](../../../by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md)
- `0x004227c6` in [UID:0002E9][FittingRoomDialogItemStateLoadEncodedStateBuffer](../../../by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md)
- `0x00580cab` in [UID:0001IO][StartupWindowUpdateCheck](../../../by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)

Generated memory coverage currently agrees:

```text
| [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | no-owner | `NONE` | `0000JC`,`0000JE`,`0000O5` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` |  |
```

Emitter detail coverage resolves the three emitters to [UID:0000JC][FileDownloader](../../../by-file/FileDownloader.md), [UID:0000JE][FittingRoom](../../../by-file/FittingRoom.md), and [UID:0000O5][StartupWindow](../../../by-file/StartupWindow.md). Generated file coverage confirms those roots emit to:

- `auto-generated/NexusTK/network/FileDownloader.cpp`
- `auto-generated/NexusTK/cashshop/FittingRoom.cpp`
- `auto-generated/NexusTK/app/StartupWindow.cpp`

All three files exist in the generated tree; they are currently zero-byte outputs because no approved final source block has been entered for these routes, not because the emitter roots are dead ends.

## Live IDA MCP facts

IDA MCP session checked: `b001_0002bd`, module `NexusTK.exe`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis and Hex-Rays ready.

`get_bytes` at `0x0060d940` shows the target sequence in context:

```text
... 76 65 72 73 69 6f 6e 00 00 00 00 00 68 00 74 00 74 00 70 00 ...
```

This confirms ASCII `version`, four zero bytes, then the UTF-16LE successor beginning `h\0t\0t\0p\0`.

`xrefs_to` returned:

```text
0x0060d94c:
  0x0041ad2e data ref in sub_41AA00, size 0x41c
  0x004227c6 data ref in sub_422740, size 0x1d9
  0x00580cab data ref in sub_580870, size 0x88d
0x0060d950: no xrefs
0x0060d954: no xrefs
0x0060d958:
  0x0041ae84 data ref in sub_41AE20, size 0x2ec
```

`lookup_funcs` confirms `0x0060d94c`, `0x0060d950`, `0x0060d954`, and `0x0060d958` are not functions; the three target refs belong to `sub_41AA00`, `sub_422740`, and `sub_580870`. The `0x0060d958` ref belongs to `sub_41AE20`, the successor item-shop catalog URL use site, so the target should not be merged forward.

`find_bytes` in IDA found:

- full target bytes `76 65 72 73 69 6F 6E 00 00 00 00 00`: one match at `0x0060d94c`
- `version\0`: three matches at `0x0060d94c`, `0x0060fcd4`, and `0x00671b25`
- `push 0x0060d94c`: three matches at `0x0041ad2e`, `0x004227c6`, and `0x00580cab`
- interior/tail dwords `0x0060d950` and `0x0060d954`: no matches
- successor dword `0x0060d958`: one match at `0x0041ae85`
- RVA forms for `0x0060d94c`, `0x0060d950`, `0x0060d954`, and `0x0060d958`: no matches

Decompilation confirms the three source-use contexts:

- `sub_41AA00` parses downloaded `itemshop.ver` data and calls the JsonCpp accessor as `sub_4278E0(..., "version", ...)` at `0x0041ad40`.
- `sub_422740` parses the fitting-room encoded/catalog state buffer and calls `sub_4278E0(..., "version", ...)` at `0x004227d8`.
- `sub_580870` fetches startup update metadata from `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver` and calls `sub_581E40("version", 0)` at `0x00580cb3`.

The successor `sub_41AE20` uses `0x0060d958` as `L"https://secure.kru.com/itemshop/data/itemshop.json"` for the catalog download. That is adjacent but separate.

## Raw PE evidence

Raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- imagebase: `0x400000`
- target VA `0x0060d94c` maps to raw `0x20c34c` in `.rdata`
- target bytes at raw `0x20c34c`: `76 65 72 73 69 6f 6e 00 00 00 00 00`
- full 12-byte target pattern occurs once, at VA `0x0060d94c`
- shorter `version\0` occurs three times: VA `0x0060d94c`, `0x0060fcd4`, and `0x00671b25`
- `push 0x0060d94c` occurs at VA `0x0041ad2e`, `0x004227c6`, and `0x00580cab`
- absolute dword `0x0060d94c` occurs only as those three operands, each preceded by opcode `0x68`
- absolute dwords `0x0060d950` and `0x0060d954` have zero hits
- absolute dword `0x0060d958` has one hit at VA `0x0041ae85`, the successor URL operand
- RVA forms `0x0020d94c`, `0x0020d950`, `0x0020d954`, and `0x0020d958` have zero hits

The PE evidence independently supports the exact range, rejects interior/tail refs, and separates this target from both duplicate textual `version` byte sequences and the adjacent `itemshop.json` URL.

## Function and child inventory

Relevant children around the physical literal pool:

- [UID:0003FZ][MinimapDownloadWideLiterals](../../../by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md): preceding shared minimap literals, multi-emitter.
- [UID:0003G0][CashShopVersionDownloadWideLiterals](../../../by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md): `itemshop.ver` URL/progress literals, assigned to FileDownloader.
- [UID:0003G1][SharedVersionJsonKey](../../../by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md): this narrow shared key.
- [UID:0003G2][CashShopCatalogDownloadWideUrl](../../../by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md): successor `itemshop.json` URL, assigned to FileDownloader.
- [UID:0003AL][CashShopDownloaderLiterals](../../../by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md): non-reconstructable split-audit container over the mixed literal block.

Relevant executable consumers:

- [UID:0002TS][DownloadCashShopVersion](../../../by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md): emits through [UID:0000JC][FileDownloader](../../../by-file/FileDownloader.md).
- [UID:0002E9][FittingRoomDialogItemStateLoadEncodedStateBuffer](../../../by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md): emits through fitting-room source, with class-local ownership under [UID:000051][FittingRoomDialogItemState](../../../by-class/FittingRoomDialogItemState.md) and generated file root [UID:0000JE][FittingRoom](../../../by-file/FittingRoom.md).
- [UID:0001IO][StartupWindowUpdateCheck](../../../by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md): emits through [UID:0000O5][StartupWindow](../../../by-file/StartupWindow.md).

The `0000JE` emitter should remain a file-root source-use emitter rather than being replaced by `000051`; this shared literal is not proven to be a `FittingRoomDialogItemState` declaration, and the actual generated destination is still `NexusTK/cashshop/FittingRoom.cpp`.

## Ownership and emitter analysis

Accepted model: `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`.

This is a pooled narrow key literal reused by separate source families. It is reconstructable because source uses should be recoverable at the consumer calls, but declaration ownership is not. The three emitter UIDs are justified because each is a real source-use route into a generated file root:

- `0000JC` FileDownloader: `DownloadCashShopVersion` parses online item-shop version metadata and uses `"version"`.
- `0000JE` FittingRoom: `FittingRoomDialogItemStateLoadEncodedStateBuffer` parses cached/decoded item-shop catalog state and uses `"version"`.
- `0000O5` StartupWindow: `StartupWindowUpdateCheck` parses startup update/minimap metadata and uses `"version"`.

Rejected owner alternatives:

- FileDownloader as canonical owner: rejected because two current xrefs are outside FileDownloader and represent separate fitting-room and startup update source contexts.
- FittingRoom or FittingRoomDialogItemState as canonical owner: rejected because FileDownloader and StartupWindow also directly use the same physical literal.
- StartupWindow as canonical owner: rejected because FileDownloader and FittingRoom also directly use the same physical literal.
- JsonCpp as canonical owner: rejected because JsonCpp supplies parser/accessor helpers; this literal is a caller-provided key, not JsonCpp-owned data.
- `CashShopDownloaderLiterals` / physical `.rdata` container as canonical owner: rejected because the container is a split-audit index, not a source declaration owner.
- A new shared constants/global owner: rejected because there is no evidence of a named source-level shared constant. The compiler/IDA evidence is consistent with ordinary literal pooling.

Rejected structural changes:

- Split: rejected. The exact child already separates the ASCII string plus alignment tail, and there are no refs to `0x0060d950` or `0x0060d954`.
- Merge backward: rejected. The predecessor is a FileDownloader wide-literal group ending cleanly at `0x0060d94c`.
- Merge forward: rejected. `0x0060d958` is a UTF-16LE item-shop catalog URL with a different sole use in `sub_41AE20`.
- Reclassify non-reconstructable: rejected. The source-use routes are known and generated file roots are valid.
- IDA-safe rename repair: not needed. IDA's `aVersion` at `0x0060d94c` is safe and descriptive; no generated-name mismatch is blocking coverage.

## Exact supervisor-owned report text

No edit to `by-memory/-coverage-report.md` is recommended. If the supervisor wants the retained row stated explicitly, keep the current row:

```text
            - [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) 0x0060d94c-0x0060d958 | string-data | SharedVersionJsonKey : reconstructable : 88% : very-strong : Narrow ASCII `version` JSON key; B001 post-migration and B002 second-pass reviews keep `CANONICAL_OWNER:NONE` because FileDownloader, FittingRoom, StartupWindow, JsonCpp, and the physical mixed literal container each overclaim declaration ownership, but retain `EMITTER_UIDS:0000JC,0000JE,0000O5` because live IDA/PE evidence proves source-use contexts in FileDownloader item-shop version parsing (`sub_41AA00` / `0x0041ad2e`), FittingRoomDialogItemState catalog-state parsing (`sub_422740` / `0x004227c6`), and StartupWindow update metadata parsing (`sub_580870` / `0x00580cab`); B002 reconfirmed no interior/tail refs, no split/merge/reclassification, and no IDA repair need.
```

Optional tracker close-out row for `tools/leaser/Agents/no_owner_b-agent-tracker.md`:

```text
| `0003G1` | 0x0060d94c-0x0060d958.SharedVersionJsonKey | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` | Agent-B002 | 2026-06-14 | complete-no-change | `Agent-B002/research/0003G1-SharedVersionJsonKey-current-no-owner-research.md` | `Agent-B001/research/executed/0003G1-SharedVersionJsonKey-current-no-owner-research.md` |
```

## Validation and lease state

- Changed files: this report only.
- by-* documentation edits: none.
- `by-memory/-coverage-report.md` edits: none.
- Validator: not run, because no in-scope by-* documentation file changed.
- Dry runs: none.
- Leases: none used; this root Agent-B002 research report is in the assigned agent folder and did not require a lease.

## Confidence

Recommendation confidence: high. The live IDA MCP xrefs, decompilation snippets, generated coverage routing, current owner docs, and independent raw PE scan all agree. The remaining uncertainty is only source-style placement: whether original source spelled three independent `"version"` literals or used some named constant is not provable from the available binary evidence. That uncertainty supports `CANONICAL_OWNER:NONE`; it does not justify removing the proven source-use emitters.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G1","source_path":"executed-b-agent-research/B002/0003G1-SharedVersionJsonKey-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
