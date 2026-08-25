** TARGET-REPORT-UID:0002MZ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002MZ FolderTreeIteratorMoveToFirstChild Source-Quality Research


## Finalized Report / Current Recommendation

- Post-Gate2B reconciliation: supervisor Gate 2A passed `43/43` ordinary destinations with zero drift; Gate 2B applied catalog entry `0365` under historical saved IDB `412DA7E8...519CD`. The latest bounded live read-only verification used database session `f608d7c2` and saved checkpoint SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, size `143192751`, saved `2026-07-31T06:21:13.3464834-04:00`, and found no semantic target/dependency/protected-state drift. Exact bounded chronology is `9F8A96C4...881441E` at `2026-07-31T01:56:18.7581245-04:00`, then `B180F0E4...5CF2A07` at `2026-07-31T02:40:36.4157748-04:00`, then `CF18895C...E2C7F96` at `2026-07-31T03:00:53.6024151-04:00`, followed by dated `4B5F...`, `1BC3C43B...B6800CFD`, and `5F2679A7...FC79A21` shared checkpoints, then current `B7CC899D...8058277` at `2026-07-31T06:21:13.3464834-04:00`. Both 9F8A and B180, plus `F7C936C0...F8D7D8`, `A0D97FC5...375971`, the `4A9360D1...26C94` reload, `DAA59745...87462C17`, `DADC487F...8967C6A4`, `836ABCFA...CCF489F`, `3892BDA8...72798D1`, `4EDEC155...B5D09F`, `87D34CCD...6F500F2`, `64704F81...E54642`, catalog0367/c0368-era saves, `A4A6BC82...C02C4`, and all earlier identities are dated history only. `CF18895C...E2C7F96`, `4B5F...`, `1BC3C43B...B6800CFD`, `5F2679A7...FC79A21`, and every earlier shared identity are dated history. Supervisor catalog0382 now identifies the current physical saved-IDB checkpoint as SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, size `143192751`, saved `2026-07-31T06:21:13.3464834-04:00`. This was not a silent relabel: B003 freshly re-read A01-A04, U00-U06, method fences, exact function items/types/comments/frames/xrefs, typed A01-A03 decompiles, the protected vtable/data entities, and the `0x004b1d50 -> 0x004b5280` dependency route against active session `f608d7c2` and found no target, dependency, or protected-state drift. This bounded readback does not make the shared hash durable authority; live item-by-item Gate 2B reread remains required before any future mutation.
- Current recommendation: retain [UID:0002MZ] as the exact source-bearing implementation of the first-child traversal operation, owned/emitted through [UID:0000FB], but correct its source shape from a concrete explicit specialization in `FolderTreePane.cpp` to the header-defined generic member `TreeItor<T>::MoveToFirstChild()`.
- Final disposition: `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000FB`, `EMITTER_UIDS:0000FB`, `EMITTER_POSITION_OPTIONAL:40`; evidence-calibrated score `91/93`; formal CPP is the exact header-only trace comment and the implementation is in formal H. The score cap reflects inferred original lexical spellings and final historical source-path uncertainty, not report lifecycle state; all 48 manual coverage operations are applied and independently read back. The compile investigation closed all 35 former FolderTreePane errors in a repaired exact-topology harness and C2MZ-204 directly preflights the seven byte-identical command20348 artifacts. The raw generated baseline exits `0` with zero errors and identifies the single C4505 owner omission; a non-suppressed closure that includes the accepted binary-backed `FolderTreePane::ExpandNode(TreeItor<TreeElem> *)` owner and its exact `std::sort(entries.begin(), entries.end(), DirectoryEntryNameLess)` consumer exits `0` with zero warnings and no C4505. The required dependent formal-H declaration `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);` is present in UID0000F9 under applied claim C2MZ-211/scoped command20252 and in command20348 Tree.h line 70; suppression, deletion, and artificial anchors remain rejected.
- Historical callback and current readback record: supervisor Gate 1 accepted exact report SHA256 `2D4E98BC83704D91F86A3F78D795661048FC4AFEE742497EFC6D8647CBDE1BAF` for the focused C2MZ-211 callback. B003 added exactly `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);` to UID0000F9 formal H after the two `NodeAt` overloads and before `protected:`, preserved all other destination content, and validated it under command `20252` with generated refresh disabled. The destination is now SHA256 `23E93045D1CBFD839C8A47F796F3E756FA6C641F5A233BB919EAFE36D1B6EB6D`, `24888` bytes, `173` lines, with the declaration present exactly once. The earlier authorized ordinary edits associated with C2MZ-061/079/103/107/111-115/123-125 remain applied to the twelve named destinations, including UID0000JG's C2MZ-124 source-root CPP assembly; their serial validators remain commands `20053`, `20054`, `20056`-`20058`, `20060`, `20062`-`20064`, and `20066`-`20073`, all with generated refresh disabled. Command `20385` additionally reconciles UID0002LN's physical formal CPP to the report's exact canonical payload. The prior 43-document implementation/Gate-2A and catalog0365 Gate-2B facts remain unchanged. C2MZ-211 and C2MZ-204 are applied. Command `20348` owns the generated code and generated-memory artifact checkpoint; command `20474` is the latest observed dated moving tracker checkpoint after B006 de-execution, while command20473, command20472, command20463, command20404, and commands20384/20381/20355 are dated history. Command20348 Tree.h line 70 contains the command20252 `AppendChild` declaration. Commands `20207`, `20304`, `20306`, `20172`, and `20175` are explicitly dated generated/memory/tracker checkpoints; commands `20170`, `20160`, `20109`, `20104`, `20024`, and `20034` are older history. All 48 FolderTree manual coverage operations are applied as 34 replacements and 14 insertions; supervisor commands `000000020464`-`000000020469` each exited `0` with `ok:1`, skipped generated refresh, and were independently exact-readback-verified. The exact 49-document manifest remains the ordinary-document baseline with UID0000F9 and UID0002LN advanced to their post-callback identities and five support paths rebased to later no-loss concurrent revisions. All B003 destination/report leases were released immediately; report execution/archive state is supervisor-owned and authoritative only from the physical report path, validator-owned status/history metadata, and supervisor readback.
- Confidence: exact for behavior, ABI, range, bytes, caller, field offset, owner, emitter order, and boundary; very strong for generic node/payload separation and shared-header source shape; inferred but high-probability for the source-facing `TreeNode<T>`, `data`, and `disabled` spellings.

## Supporting Research

- Post-Gate2B reconciliation: catalog `0365`, its matching audit checkpoint, and the latest bounded live read-only MCP readback on session `f608d7c2` against saved checkpoint `B7CC899D...8058277` are the latest target-local IDB evidence for this report. `B180F0E4...5CF2A07`, `9F8A96C4...881441E`, `F7C936C0...F8D7D8`, `A0D97FC5...375971`, the `4A9360D1...26C94` reload, `DAA59745...87462C17`, `DADC487F...8967C6A4`, `836ABCFA...CCF489F`, `3892BDA8...72798D1`, `4EDEC155...B5D09F`, `87D34CCD...6F500F2`, `A4A6BC82...C02C4`, `64704F81...E54642`, catalog0367 save `222DEBAD...99D043`, `EEF0C80D...A7997B`, the `412DA7E8...519CD` Gate 2B save, and all earlier IDB identities remain dated chronology only. This target-local assertion does not claim durable global authority after later shared saves.
- Assignment source: current `Agent-B003/goal.md` plus the explicit mandatory post-IDA, compile-preflight, focused C2MZ-211, rejected-closure repair, and supervisor manual-coverage reconciliation callbacks. The UID0002MZ report-only first phase, ordinary callbacks, prior Gate 2A, catalog `0365` Gate 2B, generated readbacks through supervisor command `20348`, direct byte-identical seven-artifact compile preflight, UID0000F9 declaration repair, UID0002LN physical-formal reconciliation, and all 48 manual coverage operations are completed historical stages. Any report review, execution, or archive disposition is supervisor-owned and authoritative only from the physical report path, validator-owned status/history metadata, and supervisor readback.
- Gate 1 acceptance and callback authorization: supervisor accepted exact SHA256 `01EC31D48291FAB439F0C94F98DEAAA0D86B18418BDE26C72B3FF37F799AC001` and authorized implementation of the then-current ordinary claims C2MZ-001..173 within B-agent scope. No replacement report was created. This same callback artifact now carries additive closure claims C2MZ-174..204 for the generated/formal defects found during read-only post-callback audit, C2MZ-205..210 for the six additional destination coverage rows found during current-state reconciliation, and atomic C2MZ-211 for the UID0000F9 declaration omission found by Gate 2A.
- Retained-lane Gate 1 self-audit input artifact: this same report at SHA256 `EF6A0B8C625378EE77856CAAE8DD4104EA4CBF4E8D32648EF59B6A608D452D1C`, size `67246`, lines `866`. Defects were repaired in place; no replacement report was created.
- Historical IDB-reconciliation input artifact: this same report at SHA256 `CBB7BA760A2CE959D8EE2962AD9955CAA804A3B9421AC7703B7C4DDABA869309`, size `251302`, lines `2143`. This callback repaired that artifact in place without discarding any valid research/history and edited no external file.
- Catalog0367 currentness-repair input artifact: this same report at SHA256 `F79C0CEFA3A8D6FA1DBB31C442F1EDF88343DA30C01EB22F87DBCA1E594FF8EB`, size `254522`, lines `2144`. It failed only because it still promoted the superseded EEF0 save; this bounded repair preserves its research, ledger, ordinary manifest, manual operations, generated topology, and compile plan.
- For the latest bounded 2026-07-31 readback, MCP database session `f608d7c2` was active and function/type/xref, fence/byte, decompile, name, item, and health calls succeeded. The bounded health check returned `status:ok`, Hex-Rays and string caches ready; `auto_analysis_ready:false` did not block any required query. The saved IDB on disk exactly matched checkpoint SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, size `143192751`, saved `2026-07-31T06:21:13.3464834-04:00`, during the target-local readback. `B180F0E4...5CF2A07`, `9F8A96C4...881441E`, `F7C936C0...F8D7D8`, the earlier shared-file observation `A0D97FC56A57D864269A7E79227523CB04C3F981C7634F138848D32854375971`, size `143195218`, last write `2026-07-30T14:32:20.6295670-04:00`, and the `4A9360D1...26C94` reload are dated history. Process/session identity and dated hashes do not assert durable authority after a later shared save.
- Historical initial-research IDB artifact checkpoint: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, size `143190227`, last write `2026-07-29T04:09:17.3951982-04:00`, SHA256 `14CD4904238DFF74647A753F0C6AD9E92F70864DE1A17FB8AF0C4463B1772925`. This is retained only as the dated artifact against which the first report pass ran.
- Historical retained-lane IDB checkpoint: same path, size `143189939`, last write `2026-07-29T04:32:48.7198654-04:00`, SHA256 `C391C5ED6A7B6B86238BD3FECDF148385728F3CA261776B0411DFA5667376BDD`. It is retained only as the artifact used by the earlier self-audit.
- Historical prior-repair IDB checkpoint: same path, size `143190275`, last write `2026-07-29T05:31:27.6017867-04:00`, SHA256 `98139D1A799FFB906E28691AC2B7DB6B1FC6D04EE39F89DE76D953657AF886DD`. It is retained only as the artifact used by the preceding Gate 1 repair and is no longer called current.
- Latest bounded target-local readback: database session `f608d7c2` was checked against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, size `143192751`, saved `2026-07-31T06:21:13.3464834-04:00`. Session `f608d7c2` re-read A01-A04, U00-U06, all three method fences/bytes/xrefs/frames, protected vtable/data dependencies, A04, and the `0x004b1d50` expansion/sort owner. A01 remains `TreeItorFolderTreePaneTreeElem_MoveToFirstChild`, size `0x20`, range `[0x004b5bb0,0x004b5bd0)`, exact 32 bytes, one caller at `0x004b2cbe`, no callees, return-address-only frame, exact `bool __thiscall(TreeItorFolderTreePaneTreeElem *this)` declaration, unique name, exact accepted regular function comment, and typed `m_storage.m_begin`/`firstChildIndex` decompile. A02 remains `TreeItorFolderTreePaneTreeElem_MoveToParent`, size `0x1f`, range `[0x004b5c20,0x004b5c3f)`, exact 31 bytes, one caller at `0x004b2c92`, no callees, return-address-only frame, exact bool-thiscall declaration, unique name, exact accepted regular function comment, and typed `parentIndex` decompile. A03 remains `TreeItorFolderTreePaneTreeElem_MoveToNextVisibleSibling`, size `0x43`, range `[0x004b5bd0,0x004b5c13)`, exact 67 bytes, one caller at `0x004b23f2`, no callees, return-address-only frame, exact bool-thiscall declaration, unique name, corrected generic `disabled` regular function comment, and typed `m_tree`, `nextSiblingIndex`, `v4`, and `m_begin` locals. For A01-A03 the address-regular, address-repeatable, and function-repeatable channels are literally `absent`; only the stated function-regular comments are present. A04 remains `sub_4B2B80`, size `0x20c`, range `[0x004b2b80,0x004b2d8c)`, `char __thiscall(int this, int)`, exact first 16 bytes, exact 23-entry frame, exact `this`/`a2` formals and 17 current Hex-Rays locals, no code caller, one data xref at `0x0061a57c`, and preserved calls to A01/A02 and `0x004b1d50`; all four function-start comment channels remain absent, internal switch/address comments remain present, no new function-start annotation exists, and the switch body remains protected. U00/U01 remain exact `0x04` one-pointer UDTs; U02 remains exact `0x0c` with members at +0/+4/+6/+8/+9 and implicit tail; U03 remains exact `0x24` with five links, U02 data at +0x14, `disabled` at +0x20, and implicit tail; U04/U05 remain exact `0x0c`/`0x10`; U06 remains exact `0x0c`. Fresh `type_inspect` returned bare declarations and exact members without declaration/member comments for U00-U06; the active MCP API exposes no separate type-comment reader and rejects type names as address operands, so current regular/repeatable type-comment channels are recorded as `absent`/`absent` from the bare declaration readback with that API limitation stated, not fabricated as an address-comment query. The iterator vtable remains at `0x0061a510`; data bytes at `0x0061a4fc`/`0x0061a50c`, method fences including `[0x004b5c13,0x004b5c20)` padding, scalar-destructor slot, and protected entities are unchanged. The direct `0x004b214e -> 0x004b5280` sort-wrapper xref inside `0x004b1d50` remains exact; existing decompile evidence still establishes `MoveToNextVisibleSibling`, `childrenLoaded = 1`, and `expanded = 1`, so `FolderTreePane::ExpandNode` remains C2MZ-124's source owner. Catalog `0365` remains the historical applied transaction. `B180F0E4...5CF2A07`, `9F8A96C4...881441E`, and all earlier identities are dated history. No target, dependency, protected-entity, or fence drift was found.

- Historical bounded-readback checkpoint: SHA256 `DAA597458433CFB4230D3EE96AA0BCE8683FEFB5CDD6D88E22B33D1687462C17`, size `143192163`, saved `2026-07-30T12:47:29.2294093-04:00`. It preserved catalog0365 target/dependency state after the unrelated UID0004EO-only save and is retained only as dated history superseded by the bounded `4A9360D1...26C94` readback.

- Historical bounded-readback checkpoint: SHA256 `DADC487F51F66A37C85D62C994F49C545E170AB2F18061AEEDC679828967C6A4`, size `143192050`, saved `2026-07-30T12:33:26.5781084-04:00`. It preserved catalog0365 state after the controlled MCP restart and unrelated UID0002OF/ObjectList transaction, and is retained only as dated history superseded by the bounded `DAA59745...87462C17` readback.
- Historical bounded-readback checkpoint: SHA256 `836ABCFA986AF47A3CAC9EC1D46A31BE6B9B29DA83B6BCA797E7817F2CCF489F`, size `143194721`, saved `2026-07-30T12:01:56.5937670-04:00`. It preserved catalog0365 state before the controlled MCP restart and is retained only as dated history superseded by the bounded DADC and DAA5 readbacks.
- Historical Gate 2B prestate checkpoint: SHA256 `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, size `143190814`, last write `2026-07-29T14:42:53.5091352-04:00`. Its raw/absent/sentinel A/U states are retained only as the literal prestate against which catalog `0365` was applied.
- Historical bounded-readback checkpoint: SHA256 `3892BDA899A18612985539399C9AC1C97B5AE6F7F9FD5D1DF2859C96472798D1`, size `143194020`, saved `2026-07-30T14:38:13.8949946Z`. It preserved catalog0365 state but was superseded for this Gate 1 currentness audit by later dated bounded readbacks.
- Historical bounded-readback checkpoint: SHA256 `D7D29DEB8CDA07A6693B36BEF32A544ABD1921D3A0C9B306A47DFCC350D08CCA`, size `143194156`, saved `2026-07-30T15:35:19.0223971Z`. It preserved the same catalog0365 target/dependency/protected state and is retained only as dated history.
- Historical bounded-readback checkpoint: SHA256 `4EDEC1553CDF85F5EDE5F40475BACA27EE26B3538E22313CED616FE3A4B5D09F`, size `143194010`, last write `2026-07-30T09:56:01.8527844-04:00`. It preserved catalog0365 state but was followed by later bounded-readback checkpoints.
- Historical post-UID000414 no-drift checkpoint: SHA256 `87D34CCD103CC97F107DBABF1CA089FCE223F1650D5376A0DCB48C0E46F500F2`, size `143192020`, last write `2026-07-30T07:11:07.1602926-04:00`. It preserved catalog0365 state but was followed by later bounded-readback checkpoints.
- Historical intervening shared-IDB checkpoints, in exact newest-three chronology, are SHA256 `B180F0E49B49DB1C9E0164DAD291EC5341EFB29B07B551AD0F6DF60EF5CF2A07`, size `143192467`, last write `2026-07-31T02:40:36.4157748-04:00`, preceded by SHA256 `9F8A96C42F981A4F0AE091DCDD76CD7CC9CDEAF26C3EC8E31461E16CB881441E`, size `143192467`, last write `2026-07-31T01:56:18.7581245-04:00`; both precede the historical bounded CF188 checkpoint; CF188, `4B5F...`, `1BC3C43B...B6800CFD`, and `5F2679A7...FC79A21` all precede the latest bounded `B7CC899D...8058277` checkpoint. Older history is SHA256 `2CCA289FBF2BA0D2CEEF5F870AF560AD3BA6025109FB47A4D66E154F70D7E851`, size `143192020`, last write `2026-07-30T09:23:53.4855352-04:00`; SHA256 `83C20CE9E13A19CA3C5501998110D490FA3D2D2EA5FE774AE1F880403C294A9E`, size `143193954`, last write `2026-07-30T07:36:29.3601106-04:00`; SHA256 `A4A6BC82D18D9BA7E1B0FDFCD87CED2B9FD4551E9AFEF3CE0175237B6DAC02C4`, size `143191991`, last write `2026-07-30T06:48:02.4013060-04:00`; SHA256 `64704F813788EA06F4C88861AC351EE128DFA76C59A01DAB1D0BFDFBC7E54642`, size `143191396`, last write `2026-07-29T17:27:04.2711792-04:00`; SHA256 `222DEBAD0D96861187C80F51A218DC36C5C775887CA874C82F5ED0E34E99D043`, size `143191396`, last write `2026-07-29T17:06:10.1000397-04:00`; SHA256 `EEF0C80D8E7E886A573FF7FB93D8BAFEE332FF26C34A7243F7CB9AB3A4A7997B`, size `143192422`, last write `2026-07-29T16:24:30.9010410-04:00`; SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, size `143191140`, last write `2026-07-29T15:00:32.0998001-04:00`; SHA256 `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, size `143190676`, last write `2026-07-29T14:22:15.9735862-04:00`; SHA256 `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, size `143191631`, last write `2026-07-29T14:12:44.7229687-04:00`; SHA256 `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, size `143190636`, last write `2026-07-29T13:59:50.1387219-04:00`; SHA256 `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, size `143190601`, last write `2026-07-29T13:03:43.9987735-04:00`; SHA256 `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`, size `143190452`, last write `2026-07-29T12:53:48.4762005-04:00`; SHA256 `E9600F6C16B46FE1F5A7FEE463EF7890E415905CE465F8F6C55954FF5AA91611`, size `143190173`, last write `2026-07-29T12:39:14.0441568-04:00`; and SHA256 `24B033C1657266F5943A2EB0201F076673C53CEEA39E00F9D65BCED961ACEC31`, size `143191127`, last write `2026-07-29T12:02:16.0035770-04:00`. None is durable current authority.
- Historical Gate 2B baseline checkpoint: same path, size `143189939`, last write `2026-07-29T06:21:05.5046456-04:00`, SHA256 `D622DD30B7329CA3A36CE80770F7B9857DDDD594C9363453330297AF0496F6D2`. Read-only calls against historical MCP database session `5a570ede` at `2026-07-29T06:55:58-04:00` established the same eleven literal prestates. D622 remains dated supporting evidence only and is no longer called current.
- Historical generated checkpoint: `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`, validator command `000000018808`, refreshed `2026-07-29T04:09:31-04:00`, size `26685`, SHA256 `5B194D9B413378ADF665648E85687E064D54F12DF3021C38582D7C7376A576DA`.
- Historical implementation-time generated checkpoint: `FolderTreePane.cpp` command `000000018812`, refreshed `2026-07-29T04:41:43-04:00`, size `26685`, SHA256 `FB6AB7DD5FF104D120BCEEBB203A028B1EFA72F4893B2A935DE724AC2B5B2A2D`. It is retained only as pre-callback chronology.
- Historical pre-final post-routing generated checkpoint: command `000000019221`, refreshed `2026-07-29T11:05:07-04:00`. Physical readback under that command header was: `Tree.h` SHA256 `699F9BCAF26185F4F6E534D1CE39DC817F07578964B6914EB3F5FE245B1A44A9`, `3867` bytes, `153` lines; validator-owned trace-only `Tree.cpp` SHA256 `DB131D0D9DA40512E609FDD39FB4277E1D861699F0A9111AF08A8E9056A064B1`, `1788` bytes, `28` lines; `FolderTreePane.h` SHA256 `D68495875A3154F7BB243B24BF66DA7151711AC16D7C1177A9734916D21EE427`, `1911` bytes, `56` lines; and `FolderTreePane.cpp` SHA256 `A7A31296948F5D614D8E303F68AA29ACBF7A5C20B7739CF6DA186A817B3D3AC8`, `22071` bytes, `501` lines. It proved zero placeholder tokens, exact UID000447/000449/00044B payloads, concrete support routing, and `#include "FolderTreePane.h"`, but it also exposed one duplicate late `TreeItor` forward declaration. B003 removed that duplicate from UID0000F9 and passed scoped validator command `000000019225`; command 19221 is chronology only and was first superseded by historical command `19802` below.
- Historical post-`19225` generated/compile checkpoint: validator command `000000019802`, refreshed `2026-07-29T17:43:08-04:00`. Exact artifacts were `LObject.h` SHA256 `CE3DDD933A0054FD5EEE308BCA0887217FF06B6917333AC5E8A10C7E66C036D1` (`993` bytes, `28` lines), `StringBase.h` SHA256 `7BA5ABA7E62F3E9C9BF9D3FB235F62F2BEBF5F935C9178E02C8461FF4B20AF97` (`878` bytes, `32` lines), `Tree.h` SHA256 `7522B6FC2EBB70E9BB53A1C9354E008A2E0E65C4EF07B26449E8C4800485EE7D` (`3831` bytes, `151` lines), trace-only `Tree.cpp` SHA256 `16CD69F20127EABE09F2817B75609F54CBFEA8B490B0320A2509961337DCBDAB` (`1788` bytes, `28` lines), `EPFTileContext.h` SHA256 `9AB8A2DE87A6B7EE84F52F220A0DD6C1A6204D0410DBA1C2FC499D061012FEF8` (`1231` bytes, `43` lines), `FolderTreePane.h` SHA256 `4C33CBE51656745AD4C58F0CC3BDB2545E4F57AA7384D0B44596045A2B06DADD` (`1911` bytes, `56` lines), and `FolderTreePane.cpp` SHA256 `6C9E88B996A175C064BA04296F491D09D184F8E426C4F2C534B463AE7F08AF18` (`22071` bytes, `501` lines). That checkpoint supplied the exact direct compile evidence retained below. Commands `19887`, `19812`, `19810`, `19805`, `19784`, `19759`, and `19752` are also dated generated chronology only.
- Historical global generated checkpoint: supervisor command `000000019890`, exact command `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240 --wait-generated`, completed `2026-07-30T08:36:15-04:00`, exit `0`, `ok:1`; only pre-existing missing-reference warnings UID00039L and UID0003T6 remained and foreground generated refresh completed. Its dated artifact identities were LObject.h `CF9DEFEC9E93E005270580C1B7B796B0B6D4A56B27BEEA9E3565A79611686A25`, StringBase.h `273819465CA66B6E36B9239FEB824835D7535653FC9A4E5654C13073818462B7`, Tree.h `0B0B295B66FA0614549C021970172AFFB9356A247DFFC2D6AAE5E05A3312764A`, Tree.cpp `536B18CCFC4B9391E5007F3EB077F4AC08880DB3A8C237841D38ABDA3FBE4E7F`, EPFTileContext.h `D5D819F62934F668D348309D086F0B646D9FC0017F0E191DD2DAC5253BA1AECA`, FolderTreePane.h `568E8A97CAEB4E17F7F6273C36E1D5BC0A3FE30B0023C148A87139D64E4DDCC5`, FolderTreePane.cpp `802D254967E4F6B0E0C7F243865EE10007234EB1C53947DDD9E193753CB692CD`, and `-ag-memory-coverage.md` `C963960CD17BDE5EE0CCFCBDCC55F2EBC41FC09E8CAA7C89EDB87AACCC069551`; none describes current files.
- Dated pre-C2MZ-211 generated checkpoint: supervisor command `000000020172`, refreshed `2026-07-31T03:46:57-04:00`, source `foreground-generated-refresh`. Exact historical target artifacts are `LObject.h` SHA256 `D4829E07C6E4EE91D07E86C0E1F91BA9FC2D2FD72F492A88036F0C721C1DC23F` (`993` bytes, `28` lines), `StringBase.h` SHA256 `58F841B1CD3C2B14DD23F4730536351DD865C00EDF40E19169F712EC00595303` (`1307` bytes, `41` lines), `Tree.h` SHA256 `AA3EE98BD1696C2992A7C16D0D9A33592AF2CACACB58BC541FFCABED2FB5B890` (`3831` bytes, `151` lines), trace-only `Tree.cpp` SHA256 `84C9816D514F634A8F4D84C126ACB8EFB69602EC981ADBD7ADB8D95A33D005E6` (`1788` bytes, `28` lines), `EPFTileContext.h` SHA256 `85492CA86779BF62279FEF3887373A2BAE2804FFD0F2F42ADADF74887FC288B3` (`1185` bytes, `37` lines), `FolderTreePane.h` SHA256 `DA615411583F0503533B4AE5860BA35AF4AD6D3437678CE8D4261D27083375B2` (`2267` bytes, `68` lines), and `FolderTreePane.cpp` SHA256 `6CA5B31B4457C340AFAC66A2226F84EB153C80B2E604DC4F6D1B8E62BF8BABEB` (`22232` bytes, `508` lines). Every target artifact had zero `[[No Children Attached]]`, `Empty Emitter Marker`, and `TMP_*` residue. At that dated checkpoint, `Tree.h` retained canonical forward declarations in `TreeNode`, `TreeStorage`, `Tree`, `TreeItor` order, complete `TreeStorage<T>` before `Tree<T>`, and no duplicate late declaration, but did not contain `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);`. `FolderTreePane.cpp` retained the applied C2MZ-124 source-root/comparator consumer and target-family ordering, while `Tree.cpp` remained trace-only. C2MZ-211 is now applied to ordinary UID0000F9 under command20252 without generated refresh; command20172 is historical prestate rather than current generated proof. Command20109 is older dated history.
- Dated generated code-artifact checkpoint: validator command `000000020207`, refreshed `2026-07-31T04:35:53-04:00`, source `foreground-generated-refresh`. Exact historical artifacts are `LObject.h` SHA256 `F90824EE5C1641AB45FDAAAA5CF7402CC2F3866BFB337E3592BC4D5FB7E03F15` (`993` bytes, `28` lines), `StringBase.h` SHA256 `9096960A44C57088AF31D4544426CFF9E1CC6DD85217F85A3D273F9699C47FAA` (`1307` bytes, `41` lines), `Tree.h` SHA256 `ECB2AEE65499D6E535BEF070134C5D61468F7501E2EF744B0BE128206D4BD4B3` (`3831` bytes, `151` lines), trace-only `Tree.cpp` SHA256 `008B0CF3C6130ACBD15CD0901C888791F174E3595439F145836D40BC65F07DDC` (`1788` bytes, `28` lines), `EPFTileContext.h` SHA256 `795C6926AC4A66F0825FD22E1CDA4DFBEB0F8E92C5D92D6BA7296844F886EDB4` (`1185` bytes, `37` lines), `FolderTreePane.h` SHA256 `F6A01CA993345F4CA3DF968C7FE5149582C17D272DBC1A96B57617528CA39453` (`2267` bytes, `68` lines), and `FolderTreePane.cpp` SHA256 `73184C4BFB4C0EE90D334D4D3F1694F02CB3357DB0F96413C0FA69FD163CFC49` (`22232` bytes, `508` lines). This checkpoint retained zero placeholder/TMP residue but predated generated incorporation of command20252, so its Tree.h lacked `AppendChild`.
- Generated code and generated-memory checkpoint: validator command `000000020348`, refreshed `2026-07-31T06:53:05-04:00`, source `foreground-generated-refresh`. Exact artifacts are `LObject.h` SHA256 `6556B04AC99A381F40487D19CBA5B98D663F180B2B6C2ADCB876B4E1A529D12C` (`993` bytes, `28` lines), `StringBase.h` SHA256 `896657BA94265AF3F5FA412098C0DC374F46416D4FE1FED9F444079914D6D7F5` (`1307` bytes, `41` lines), `Tree.h` SHA256 `A5FC0D4F7DD6EDF3034C61F3A15434D13B51084C03473009D2DD544A76004E1C` (`3898` bytes, `153` lines), trace-only `Tree.cpp` SHA256 `BCF1758126AF74A38DE431BD3EFDDF4FA46C4E5342ECD11288612A2200440054` (`1788` bytes, `28` lines), `EPFTileContext.h` SHA256 `9E647CF7286FB81C0A4A0CFA944FD39C07D8FEC565CB6FEE7DC292D8E15A9225` (`1185` bytes, `37` lines), `FolderTreePane.h` SHA256 `7980028EF777D44F45AD5A8A60DE17F0312E22A10F8532FF9CCD67BA16A03574` (`2267` bytes, `68` lines), and `FolderTreePane.cpp` SHA256 `6FE8C918E04614BEB72D19F33650187A5F45F9BEE0DD3362BAE3567AB19F6E7C` (`22232` bytes, `508` lines). Generated memory is SHA256 `C2D261C91496DD1C3C264766554D815C121F0465BCCD798F305D51A5F48D791C`, `1428860` bytes, `4978` lines. Tree.h line 70 contains exactly `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);`; refresh/topology proof is complete and C2MZ-204 directly preflights all seven byte-identical artifacts plus the accepted real owner closure.
- Historical supervisor command `000000020104`, refreshed `2026-07-30T15:18:49-04:00`, recorded LObject.h `15BEE56D1EAFE6B0E3E84F0CB7457871D9F9F16184233247DCCD670ED85E0D05`, StringBase.h `2C8E13D181312E9BF7D0CB2AD70B5451624B6A7BFAF1AC7ECA20160EBD2A0BD3`, Tree.h `3437E47AAE47EEC9AD7C70162BDC16B5B0ADFCBC3141EC139134D04AC6180DAA`, Tree.cpp `39934CB90661532D23B113CF3FDD7E730BD076437D24B43D95CC060E76149A3F`, EPFTileContext.h `71A543DF7EBDC3B6443FEA15A747CFC4DBA6DA01F46B658035B0E58DDC3369A8`, FolderTreePane.h `EBF70F3F4025F692FA93417DF688B0DB2506CA3D34456DBF4399F07A835E11C2`, FolderTreePane.cpp `79BCCF65D104F65A8B341AF536B29C4F53B0352B6B12A990EFB750C838B4A5A4`, generated memory coverage `BEE343EC97DE3987E641442D6A142B7792482295E12BAA8AEFE02471A484BF12`, and tracker `784D99B4A4C01C389EBBA2C057E636CC88BEADC9EF452E2FC71F3B103F9280CF`; all are dated history. Commands20172/20175, 20207/20304/20306, command20355, and intervening checkpoints precede command20348 generated evidence and command20381 tracker evidence.
- Historical command `000000019993`, refreshed `2026-07-30T11:58:57-04:00`, recorded the same seven semantic target streams under hashes LObject.h `ADDDEE4D802CA5F156601BCA049AE2AFA0E71F1A0BB947583C59F59FEBB373A4`, StringBase.h `91AC883C4BEADDBBB55B210DA1FFDE8F1E731AE65978B60BDA038B121B823800`, Tree.h `D48FBBE4C77E794E97D0496B49F8E46A5FAEE31AEA4D2665EA83D1A92F950B30`, Tree.cpp `9D417F00FDEDC639EFC359492377637F097CBFFD86E703A7A18960EC3018FAC8`, EPFTileContext.h `49E370F5EA39A153EF7953A949EA6A2B1FF20AE63CB272434C344EFAF2FD07B6`, FolderTreePane.h `9A2A84521F327ECA59D6DB2DE6BCADCA46E4C104F979CC64C072242335A72D6D`, and FolderTreePane.cpp `4B170E321DB3B1F4A7101514B21BFD86D1DA41D21A84B6E479E3CA92E4199AF8`; it is dated history superseded through current generated-code command20348.
- Compile/syntax preflight environment and tool discovery at `2026-07-29T18:18:40-04:00`: the generated NexusTK tree has no `.sln`, `.vcproj`, `.vcxproj`, CMake, Meson, Makefile, or documented generated-tree build command. Installed toolchain is Visual Studio 2022 Community x86 `cl.exe`, Microsoft C/C++ Optimizing Compiler `19.44.35226`, tool path `C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.44.35207\bin\Hostx64\x86\cl.exe`. No Clang, clang-cl, GCC, MinGW, or historical VC8/VC9 C++03 compiler was found in the checked installed/common paths. `cl /std:c++03` exits `0` only because `cl` emits warning `D9002: ignoring unknown option '/std:c++03'`; it is not a strict C++03 mode. The strongest available evidence therefore combines x86 `/Za` extension suppression, the compiler's lowest explicit `/std:c++14 /permissive- /Zc:__cplusplus` mode, and a token audit. The target seven artifacts contain zero genuine `nullptr`, `override`, `noexcept`, `constexpr`, `decltype`, `static_assert`, `thread_local`, `alignas`, `alignof`, lambda, or `[[attribute]]` uses; the two coarse lambda-pattern hits are the C++03 `operator[]` declarations at `Tree.h:42-43`, not lambdas.
- Historical direct-artifact baseline command, run once per command19802 artifact: `call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" -arch=x86 -host_arch=x64 >nul && cl /nologo /TP /Zs /W4 /WX- /EHsc /Za "<absolute-generated-artifact>"`. Exit `0`: `LObject.h`, `StringBase.h`, `Tree.h`, trace-only `Tree.cpp`, and `EPFTileContext.h`. Exit `2`: the pre-application `FolderTreePane.h` and `FolderTreePane.cpp`. The header first exposed the generated `ScrollBar.h` placeholder/missing UI declaration chain; the source then exposed exactly 35 error diagnostics. The repaired exact-topology harness closes all 35 errors. Dated command20172 preserves the accepted support changes but predates ordinary C2MZ-211; command19802 remains proof of the former diagnostics while direct compilation of the next refreshed artifacts remains required.
- Diagnostic closure matrix: all 35 errors were individually mapped to an owning source correction. `Rect` is a false type name and becomes the existing 16-byte `RectBounds`; UID000346 uses `RectBounds::ContainsPoint(context->y, context->x)`. UID00005A declares its exact 12-byte nested `DirectoryEntry` and `GetNodeBounds(TreeItor<TreeElem> *, RectBounds *) const`. UID0001WS declares `DetachWideIfShared()` and `mystr::WideRangeCompare(...)`; UID000343 calls the latter with explicit namespace qualification. UID0000BU centrally emits `RectBounds.h`; UID00004I includes it rather than duplicating the record. UID0000A2/UID0000CF/UID0000NF supply complete `Pane`/`ScrollablePane`/`ScrollBar` header topology, including inherited `InvalidateRect`, `m_contentRect`, `GetScrollPosition`, `GetScrollMax`, and exact `ApplyScrollPosition(char, unsigned short, unsigned short)`. UID000156 uses `RectBounds selectedBounds` and explicit `static_cast<unsigned short>` conversions at the two low-word ABI calls. UID0000JG includes `<wchar.h>` for `_wcsupr_s`. The dependent `selectedBounds`, `bounds`, `lhs`, and `rhs` diagnostics disappear with those owners; no padding shim, fake stub, compiler-label name, or warning suppression is recommended.
- Repaired exact-topology harness: copies of the command-19802 target family were changed only according to the formal/support recommendations above. `RectBounds.h` was added; `EPFTileContext.h` includes it and drops the duplicate declaration; `ScrollBar.h` includes a Pane-owned complete declaration surface and drops the invalid placeholder; FolderTreePane and StringBase declarations/sources receive the exact corrections above. Commands `cl /nologo /TP /Zs /W4 /WX- /EHsc /Za FolderTreePane.h` and `cl /nologo /TP /Zs /W4 /WX- /EHsc /Za FolderTreePane.cpp` both exited `0`; the matching `/permissive- /Zc:__cplusplus /std:c++14` commands also exited `0`. The header emitted zero diagnostics. The source emitted only C4505 for file-local `DirectoryEntryNameLess`: current partial generated FolderTreePane.cpp emits the comparator but omits the high-level `ExpandNode`/`EnsureChildrenLoaded` sort expression that consumes it. Binary/docs prove the comparator belongs to the directory-entry sort cluster, so the exact closure is to emit the owning expansion/sort call, not add an artificial reference or suppress the warning. The former 35 errors are fully resolved; C4505 is a precisely classified generated-coverage postcondition, not a broad dependency or UID0002MZ defect. Every compile used `/Zs`, produced no object, and the disposable harness is removed before handoff.
- Dated report-time moving research-tracker checkpoint: `auto-generated/-ag-research-tracker.md`, validator command `000000018878`, refreshed `2026-07-29T07:38:28-04:00`, filesystem last write `2026-07-29T07:38:31.9309876-04:00`, size `1668879`, `6603` lines, SHA256 `0709E455BC00C5E2F2080500ACADC7076C7FB07C90DA89B9A93B6B0AC3498F77`. At that checkpoint its UID0002MZ row is line `1711`: `86/91`, average `88.5`, reconstructable `true`, direct/additional/total report coverage `0/0/0`, path `by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md`. This supersedes command `000000018826` and earlier tracker identities only; tracker chronology is independent from the later command `19221` generated checkpoint. The tracker is validator-owned and moving, so any later validator-owned tracker state is authoritative and must be read back rather than treating this dated checkpoint as permanent truth.
- Generated/report evidence is command `000000020348`, refreshed `2026-07-31T06:53:05-04:00`, for the seven exact CPP/H artifacts and generated memory SHA256 `C2D261C91496DD1C3C264766554D815C121F0465BCCD798F305D51A5F48D791C`, `1428860` bytes, `4978` lines. Latest observed dated moving tracker checkpoint after B006 de-execution is deferred-generated-refresh command `000000020474`, refreshed `2026-07-31T10:13:05-04:00`, SHA256 `DA13617295274A581850C344E6BAAC0650DC7CE431F0C9E4A80822466DB4E610`, `1690530` bytes, `6676` lines, with UID0002MZ at line `2908`, `91/93`, average `92.0`, reconstructable `true`, and direct/additional/total coverage `0/0/0`. Command20473, command20472, command20463, command20404, commands20384/20381/20355, commands20207/20304/20306, 20172/20175, 20170, 20160, 20109, 20104, 20024/20034, 19995/19993/19928/19890/19891, and earlier identities are dated chronology, not current evidence. This tracker snapshot is not permanent current authority; any supervisor tracker determination is authoritative only from its physical readback of the tracker identity, counts, and UID0002MZ row.
- Historical validator checkpoints preceding dated supervisor command `000000020172`: command `000000019926`, refreshed `2026-07-30T10:34:57-04:00`, recorded LObject.h `48EBB0B4DE0FB1768080EC6D7812D43FE686F8753A63D1B0698F90FD5CB28D26`, StringBase.h `28F636889557E75AE15FE7029AB73779651F438DBFE11AEE7ECAEEF1C133FA2D`, Tree.h `4319EE1506C4E3B79DA93E6E69236726182DFE332AC699755A136045312B4357`, Tree.cpp `F179B04B5F2420C73A3E97FA3F9E156A75784A70D07F439C87618450DC816CC3`, EPFTileContext.h `F709125FF7488B67D4580B010E31A09B890F12AB7416228CC39E748ADC020432`, FolderTreePane.h `AFAF4C5C86F9548B6FDE2C1411579088A23E723EA5580F8A5A8B168ED1E12FB1`, FolderTreePane.cpp `35085C730EF13E4FD6762A41714BB07975BE3312FB5840177A636E97BA82BC89`, and generated memory coverage `6A2DA8391DDE03DDF7949AE430E6E5A538F364C4D0F1D3FAAAB14B7A7F3CD544` (`1419904` bytes, `4949` lines). Tracker-only command `000000019933`, refreshed `2026-07-30T11:03:10-04:00`, recorded SHA256 `A1FA9680D296AF86A2BDBB7C6994413256035E5292ADECB4FB42E985B04958D1`, `1679360` bytes, `6633` lines, with UID0002MZ at line `2899` and unchanged `91/93`, true, `0/0/0` semantics. Commands20109/20104/20024/20034 and commands19993/19995 are dated checkpoints stated above. These are dated history, not current identities.
- Historical reports checked as evidence leads rather than authority:
  - `executed-b-agent-research/B014/0000FB-FolderTreePaneTreeIterator-class-source-quality.md`.
  - `executed-b-agent-research/B001/0002N0-FolderTreeIteratorMoveToNextVisibleSibling-source-quality.md`.
  - `executed-b-agent-research/B009/0002MY-FolderTreeResetToSingleRoot-empty-emitter-source-quality.md`.
  - `executed-b-agent-research/B001/000157-FolderTreePaneTreeAndSortHelpers.md`.
  - `executed-b-agent-research/B008/00005A-FolderTreePane-class-source-quality.md`.
  - `executed-b-agent-research/B007/00034F-FolderTreeIteratorVtableResetDestructor-empty-emitter-source-quality.md`.
  - `executed-b-agent-research/B001/00034J-FolderTreeIteratorScalarDeletingDestructor-empty-emitter-source-quality.md`.
- No direct prior UID0002MZ source-quality report was found. Historical broad reports accepted behavior and routing but retained the template/payload/header blockers this assignment requires resolving.

## Target

- Post-Gate2B reconciliation: target identity, range, owner/emitter, position, score, and human formal are unchanged; the latest `f608d7c2` bounded readback against saved checkpoint `B7CC899D...8058277` confirms the applied catalog0365 IDA state without target/dependency/fence drift, and all 49 ordinary destination identities remain exact. B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, and 3892 are dated history.
- Target UID: `0002MZ`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0002MZ] `by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md`, exact `[0x004b5bb0,0x004b5bd0)` source-bearing method.
- Source queue/report row: by-memory reconstructable target; supervisor command `000000020469` applied and exact-readback-verified C2MZ-048. Current `by-memory/-coverage-report.md` is SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`, `2134111` bytes / `4803` lines, and contains the accepted UID0002MZ row at line `1488` between UID0002MY line `1486` and UID0002N0 line `1489`. The row's pre-closure wording that manual coverage remained pending is retained in the applied literal as historical operation-time wording; it does not reopen C2MZ-048. `DDB43AB5...3EAFAE2`, `485A5902...D9E6D14`, `5CDCBB4B...AEDD53FF`, `6C2C8B45...ADD741B7`, `F470880A...DA3F7`, `C71EE2C3...DA674C3D`, `EE94FB8B...E6EF1074`, `4243659D...911D718`, `B6522C0B...BFD1878`, `82A918D0...49F0C8E`, `C5E4E81C...BED62BAC5`, and `22BB0BB3...EC705F2` are dated history.
- Current supervisor classification: source-authored custom iterator behavior, not compiler glue and not a covered-by/no-code target.
- Historical pre-callback score and parent state: `86/91`, owner/emitter [UID:0000FB], position `40`, with the generic class route then ultimately under [UID:0000JG] `FolderTreePane`.
- Current post-callback score and route: `91/93`, owner/emitter [UID:0000FB], position `40`; UID0000FB and the shared generic template family now route through registered [UID:0004YK][Tree](by-file/Tree.md), while concrete FolderTree payload/visitor code remains under UID00005A/UID0000JG.

## Current Target State

- Post-Gate2B reconciliation: ordinary state and the latest bounded IDA readback on `f608d7c2` against `B7CC899D...8058277` agree; `TreeItorFolderTreePaneTreeElem_MoveToFirstChild` is typed/commented and decompiles through the exact generic node/storage analysis chain. B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, 87D3, and 6470 are dated history only.
- Current ordinary metadata: `COMPLETION:91`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000FB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FB`, `EMITTER_POSITION_OPTIONAL:40`.
- Current ordinary C++ state: formal CPP is the exact header-only trace comment and formal H contains the generic `TreeItor<T>::MoveToFirstChild()` definition through public `Tree<T>::NodeAt`. UID0002N0/UID0002N1 use the same generic H route and matching trace-only CPP comments, while UID0002MY remains a concrete CPP specialization because it writes payload-specific state.
- Current source model: `TreeNode<T>` owns five links, `T data`, and `disabled`; `FolderTreePane::TreeElem` is the 12-byte nested payload. Shared template pages route through assigned [UID:0004YK][Tree](by-file/Tree.md), and the proposed human source tree contains the accepted `LObject.h`, `StringBase.h`, `Tree.h`, `EPFTileContext.h`, and `FolderTreePane.h` topology with no authored `Tree.cpp`. The validator currently materializes a companion `.cpp` for every valid by-file root; UID0004YK's companion contains only header-only provenance comments and no out-of-line implementation or placeholder.
- Historical pre-callback blockers now resolved in ordinary documentation: direct-payload `+0x04` interpretation, monolithic 36-byte `TreeElem`, CPP-only template declarations, FolderTree-only explicit iterator specializations, missing complete header declarations, private access from a file-local paint helper, and unresolved shared source registration. Each remains preserved as historical reconstruction provenance in its affected document.
- Supervisor review, execution, and archive disposition are external controls rather than embedded current work state; the physical report path, validator-owned status/history metadata, and supervisor readback are authoritative. The 48 FolderTree manual coverage operations are complete under commands `000000020464`-`000000020469`. Command `20348` completed the waited generated refresh and its Tree.h line `70` contains the ordinary command20252 `AppendChild` declaration. Dated moving tracker command `20474` observed UID0002MZ's `91/93`, reconstructable-true, `0/0/0` semantics; command20473, command20472, command20463, command20404, commands20384/20381/20355, commands `20207`, `20304`, `20306`, `20172`, and `20175`, plus `20170`, `20160`, `20109`, `20104`, `20024`, `20034`, `19993`, `19995`, `19928`, `19890`, `19891`, `19887`, `19812`, `19810`, and `19802`, are dated history. C2MZ-204's raw byte-identical preflight produced zero errors and one owner-specific C4505; its non-suppressed accepted real-owner closure produced zero errors, zero warnings, and no C4505.
- Related target/support docs checked: UID0000FB, UID0000F9, UID0000FC, UID0001WP, UID0001UJ, UID0000JG, UID000157, UID0002MY, UID0002N0, UID0002N1, relevant vtable/type pages, EventDispatcher handler-tree layout/support, generated FolderTree source, manual coverage, and the historical reports listed above.
- Artifact evidence record: the historical ordinary callbacks and the Gate-2A-discovered UID0000F9 formal-H repair are complete; 43 earlier ordinary destinations, the twelve later authorized destinations, and focused C2MZ-211 were created or updated, all listed completed scoped validators passed, and leases were released. C2MZ-211 is complete and validated by command `000000020252`, exit `0`, `ok: 1`, with generated refresh skipped. Gate review and documentary verification state belong to the supervisor audit/readback rather than this report body; execution/archive state is authoritative only from the physical report path and validator-owned status/history metadata.

## Executive Recommendation

- Post-Gate2B reconciliation: the accepted recommendation is implemented in ordinary documentation and IDA. Eleven support claim groups plus UID0000JG C2MZ-124, UID0000F9 C2MZ-211, and generated/compile C2MZ-204 are fully applied. Command20252 validates the exact UID0000F9 declaration, command20385 validates UID0002LN's exact canonical physical formal, command20348 materializes the declaration in Tree.h line `70`, and the direct byte-identical compile plus real-owner closure resolves C4505 without suppression. Supervisor command `20172` is the dated incomplete pre-C2MZ-211 generated readback, while commands `20355`, `20207`, `20304`, `20306`, `20109`, `20104`, and `20024` are older history. No research or implementation recommendation is deferred; FolderTree manual coverage is complete, while report review/execution/archive disposition remains authoritative only from supervisor and validator state outside this report body.
- Keep the target's semantic owner and emitter at UID0000FB and its relative method order at `40`.
- Correct the source model to a shared generic tree implementation:
  - `TreeNode<T>` owns `parentIndex`, `firstChildIndex`, `lastChildIndex`, `previousSiblingIndex`, `nextSiblingIndex`, payload `T data`, and trailing `disabled` state.
  - `TreeStorage<T>` stores `TreeNode<T>` objects, not bare `T` objects.
  - `FolderTreePane::TreeElem` is the 12-byte payload beginning at concrete node offset `+0x14`: four-byte pointer-backed `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > name`, `short rowIndex`, `short depth`, `childrenLoaded`, `expanded`, and implicit alignment padding. The unrelated 24-byte SSO `SimpleUString` declaration is rejected for this member.
  - `TreeItor<T>::MoveToFirstChild()` is a generic header-defined member because it accesses only generic node links and iterator state.
- Treat the original physical header as the shared project template header `NexusTK/util/Tree.h`. Registration is complete under assigned [UID:0004YK][Tree](by-file/Tree.md); page-header and validator-mapping readback agree, the four generic routes migrated to UID0004YK, and all 43 ordinary callback destinations have zero temporary registration-token residue. The original canonical pre-registration token remains only in explicitly historical report chronology and the accepted Gate 1 payload below.
- Update the sibling iterator definitions to the same generic H model and correct the reset specialization to construct `TreeNode<FolderTreePane::TreeElem>` and access payload fields through `.data`. FolderTree-only traversal remains in concrete member-template specializations of the generic `Traverse<Visitor>` API; feature-specific method names are not added to every `Tree<T>`.
- Intended compile topology: `Tree.h` includes a real `LObject.h`; `FolderTreePane.h` sees complete `ScrollablePane`, `EPFTileContext`, pointer-backed `StringBase`, `Tree`, and centralized `RectBounds` declarations; the four-byte payload string is `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`, not the 24-byte SSO `SimpleUString`; and `PaintTreeNode` is a private static `FolderTreePane` member reached through a `Tree<T>` friend declaration. The repaired exact-topology harness proves these declarations close every former error. Dated command20172 materializes the accepted topology before UID0000F9's `AppendChild` declaration; the exact formal payload is applied under command20252 and present in command20348 Tree.h line `70`. C2MZ-204 directly preflights the byte-identical command20348 set and the accepted real `ExpandNode` consumer closure.
- Permanent preservation constraint for supervisor readback or any future mutation: preserve the exact catalog `0365` IDA state. Do not rename the decorated vtable, add synthetic padding members, move the IDA-only alignment annotation into human source, or disturb the accepted UID0002N0 state.

## Supervisor Active Recheck

- Post-Gate2B reconciliation: supervisor Gate 2A passed 43/43 with zero drift, Gate 2B saved historical `412DA7E8...519CD`, and B003 independently re-read the applied target/dependencies first under that save and most recently on session `f608d7c2` against `B7CC899D...8058277` without drift. B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, 87D3, A4A6, 6470, 222D, EEF0, and earlier chronology are dated history.
- The supervisor explicitly assigned UID0002MZ for exhaustive report-only research and required live read-only MCP, all 33 sections, exact ledger/checklist/IDA prestates, and source-shape closure before Gate 1. Gate 1 subsequently passed at exact SHA256 `01EC31D48291FAB439F0C94F98DEAAA0D86B18418BDE26C72B3FF37F799AC001`, after which the supervisor authorized this ordinary-document callback.
- The target does not require a range split. It does require a source-model split between generic `TreeNode<T>` metadata and `FolderTreePane::TreeElem` payload.
- Every source-bearing support item needed for this conclusion has a concrete disposition below. No compiler-generated wrapper is converted into handwritten source.
- Hard-boundary chronology: the report-only phase changed only this report. After exact Gate 1 acceptance, the authorized ordinary callback and additive generated/formal closure created or updated the 43 ordinary destinations listed below and ran only serial scoped file validators with generated refresh disabled. It did not edit coverage/generated output, supervisor audit/catalog/lifecycle state, or IDA, and every ordinary lease was released immediately after its edit.

## Inference Research Guidance Check

- Post-Gate2B reconciliation: the selected human names and source shape survived exact IDA application; tool-specific alignment syntax is classified as analysis-only rather than leaked into reconstructed source.
- Binary facts, current documentation, and inference are kept separate throughout this report.
- Existing documentation assumptions were treated as potentially wrong, specifically the 36-byte `FolderTreePane::TreeElem` declaration, `hidden` as a FolderTree payload member, direct `TreeStorage<T>` storage of `T`, concrete explicit-specialization source shape, and CPP-only template declarations.
- The decisive inference is arithmetic and cross-specialization based, not name preference:
  - `Tree<EventHandler *>` records are `0x1c`: five link dwords (`0x14`) + 4-byte payload + one state byte + three bytes alignment.
  - `Tree<FolderTreePane::TreeElem>` records are `0x24`: five link dwords (`0x14`) + 12-byte payload + one state byte + three bytes alignment.
  - Both use the same iterator layout and the symbol-backed `TreeItor` template spelling.
- `TreeItor` is retained exactly; `TreeIterator` is rejected because the decorated vtable at `0x0061a510` proves `??_7?$TreeItor@UTreeElem@FolderTreePane@@@@6B@`.
- Wave2/Wave3 artifacts and wording were encountered in historical documents and ignored as stale process evidence. They were not used as current authority.

## Heuristic / Inference Reanalysis And Validation

- Post-Gate2B reconciliation: applied names/types/comments and typed decompilation validate the accepted semantic model without changing the inference classification of original lexical spellings.
- Function name:
  - Accepted: `TreeItor<T>::MoveToFirstChild`.
  - Evidence: exact mutation semantics, current family naming, direct caller behavior, and symbol-backed `TreeItor` type.
  - Rejected: `GetFirstChild`, because the method mutates `m_currentIndex`; raw `sub_4B5BB0`; generated filename-derived class spelling.
- Return type:
  - Accepted: `bool`.
  - Evidence: exact `xor al,al` and `mov al,1` exits, sibling family contract, no wider return use.
  - Rejected: source-facing `char`, which is an IDA raw-prototype artifact.
- Iterator members:
  - Accepted: `m_tree` at `+0x04`, `m_currentIndex` at `+0x08`.
  - Evidence: current IDA UDT, all three traversal methods, 12-byte scalar delete size, and 31 vtable references.
- Storage access:
  - Accepted source surface: `m_tree->NodeAt(m_currentIndex)`, where the inline generic accessor returns `m_storage[index]` as `TreeNode<T>&` and compiles to the observed indexed load.
  - Rejected: raw begin-pointer arithmetic in source, `reinterpret_cast`, and direct access through a bare `FolderTreePane::TreeElem *`.
- Generic node versus payload:
  - Accepted: five links and trailing disabled state belong to `TreeNode<T>`; `FolderTreePane::TreeElem` is a 12-byte payload.
  - Positive proof: the exact `0x24` and `0x1c` concrete record sizes both equal the same 20-byte link prefix plus `sizeof(T)` plus one state byte and alignment.
  - Corroboration: EventDispatcher uses the same link offsets and trailing nonzero-disabled semantics with `TreeItor<EventHandler *>`; FolderTree uses payload-specific name/row/depth/loaded/expanded state only in the middle payload region.
  - Rejected: one monolithic 36-byte `FolderTreePane::TreeElem`, because it cannot explain the generic `TreeItor<EventHandler *>` specialization without an unnecessary and undocumented type-specific storage model.
- Generic state byte:
  - Accepted source-facing name: `disabled`.
  - Evidence: EventDispatcher directly treats the corresponding post-payload byte as disabled; FolderTree traversal skips it when nonzero. `hidden` remains a useful concrete semantic alias, not the highest-probability generic member name.
  - Rejected: `deleted`, `hiddenOrDeleted`, `isVisible`, and padding.
- Payload field name:
  - Accepted source-facing member on `TreeNode<T>`: `data`.
  - Classification: inferred high-probability conventional mid-2000s template spelling; exact original spelling is not symbol-recovered.
  - Rejected: payload-specific `handler` or `name` as a generic node member; generated `TreeNodeData` as a complete storage-class name.
- Template definition placement:
  - Accepted: generic template declarations and definitions in H; concrete payload-specific methods remain eligible for CPP specialization.
  - Evidence: two independent concrete instantiations, shared layout and spelling, lack of a standalone concrete source unit, and ordinary C++ template compilation requirements.
  - Rejected: three handwritten `template <>` iterator traversal bodies in `FolderTreePane.cpp`; one generated `.cpp` per concrete instantiation; decompiler-style duplicate classes.
- Physical header placement:
  - Accepted high-probability original shape: shared `Tree.h` included by EventDispatcher and FolderTreePane.
- Historical pre-callback route constraint: no registered/scored shared by-file page then existed, so metadata could not guess a UID and no temporary UID0000JG H detour was allowed. Scoped validator command `000000018916` subsequently registered [UID:0004YK][Tree](by-file/Tree.md); page-header and validator-mapping readback agreed before the one-step route migration.
- Method order:
  - Accepted current order: destructor support `30`, `MoveToFirstChild` `40`, `MoveToNextVisibleSibling` `50`, `MoveToParent` `60`.
  - Evidence: exact address order and current generated order.
- Return/use semantics:
  - `-1` returns false and preserves `m_currentIndex`.
  - A valid first-child index is stored and true is returned.
  - Caller `FolderTreePane::OnKeyEvent` ignores AL at `0x004b2cbe`, then updates selection from the mutated persistent iterator; this does not weaken the bool source contract.
- Research-stage source-shape questions are resolved. Registration, ordinary application through focused C2MZ-211, UID0002LN physical-formal reconciliation, ordinary zero-TMP verification, supervisor catalog `0365` IDA application/readback, command `20348` post-repair generated-code/memory readback, dated command `20474` tracker observation, and direct C2MZ-204 compile closure are complete; command20473, command20472, command20463 and commands20384/20381/20355 are dated tracker history. Every former FolderTreePane diagnostic has an exact owning correction. Gate 2A historically found one implementation omission rather than an unresolved research question; command20252 validates its exact ordinary `AppendChild` declaration, command20348 materializes it in generated Tree.h line `70`, and the accepted real `ExpandNode` consumer removes C4505 without suppression. FolderTree manual coverage is complete. Supervisor review and lifecycle disposition are intentionally not represented as current report state.

## Evidence Standards Used

- Post-Gate2B reconciliation: actual apply/readback evidence now joins the original binary and inference ladder; no recommendation is treated as fact without exact current-state verification.
- Direct evidence: live function lookup, full disassembly, decompilation, exact bytes, SHA256, xrefs, caller flow, vtable decorated name, vtable-reference inventory, function boundaries, comments, current UDT catalog, and adjacent items/padding.
- Corroborating evidence: current by-* docs, generated FolderTree source, EventDispatcher sibling specialization/layout, historical reports, and manual coverage.
- Negative evidence: no data/immediate/pointer route to the target, no alternate entry, no callees, no strings/constants, and no binary evidence for an explicit specialization declaration. Raw target names/types and absent analysis UDTs are historical prestates; current catalog `0365` names/types/comments/UDTs are applied analysis state, not recovered PDB proof.
- Evidence ladder: bytes/control flow establish behavior; RTTI/vtable and cross-specialization layout establish template identity; source names and physical header filename are inference constrained by project-era C++ practice.
- Tool limitations: PDB/source member names and original header paths are unavailable. This does not justify raw labels; the report chooses the highest-probability human source names and records their inference status.

## Evidence Checked

- Post-Gate2B reconciliation: bounded live MCP and filesystem checks bind every latest target-local IDA claim in this report to database `f608d7c2` and saved checkpoint SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, size `143192751`, saved `2026-07-31T06:21:13.3464834-04:00`. B180, 9F8A, F7, the earlier `A0D97FC56A57D864269A7E79227523CB04C3F981C7634F138848D32854375971` observation, the `4A9360D1...26C94` reload, DAA, DADC, 836A, 3892, 4EDEC, 87D3, and 6470 are dated history.
- Live MCP calls: `idb_list`, `server_health`, `lookup_funcs`, `inspect_items`, `decompile`, `disasm`, `xref_query`/`xrefs_to`, `get_comments`, `stack_frame`, `type_query`, `type_inspect`, and bounded byte/pointer checks from the active database; earlier passes also used `analyze_function`. Latest readback confirms A01/A02/A03 accepted names/types/comments, unchanged A04, exact U00-U06 final layouts, and typed decompilation. `905D1AB1...604C1`, 296E, 3C8F, 0E0A, 03F102, 08D31, E960, 24B033C, and D622 are retained only as historical checkpoints.
- Target: start/end, exact 32 bytes, hash, 14 instructions, three basic blocks, one caller, no callees, raw prototype, comments, and pointer-pattern negatives.
- Caller: `sub_4B2B80` / documented `FolderTreePane::OnKeyEvent`, callsite `0x004b2cbe`, key-navigation branch, persistent iterator at `FolderTreePane+0x170`, and subsequent selection update.
- Siblings: UID0002N0 retains its accepted name/type with corrected generic-node comment and behavior; UID0002N1 now has the accepted parent-method name/type/comment and matching typed parent-index shape.
- Type state: exact `SimpleUString`, `StringBaseWide`, `FolderTreePaneTreeElem`, `FolderTreePaneTreeNode`, `FolderTreePaneTreeStorage`, `FolderTreePaneTree`, and `TreeItorFolderTreePaneTreeElem` layouts. U02/U03 use IDA-only explicit four-byte alignment declarations to realize implicit tails without synthetic members.
- Cross-specialization: EventDispatcher 28-byte record and `TreeItor<EventHandler *>` 12-byte iterator; FolderTree 36-byte concrete node and matching generic offsets.
- Current ordinary-file hashes are listed in `Changed Files` as the exact post-callback manifest: thirteen accepted destination deltas and 36 support/no-edit destinations, five of which advanced through later no-loss concurrent revisions, with UID0002LN advanced by command20385. Command `20348` owns the generated-code and generated-memory checkpoint, including the command20252 ordinary `AppendChild` declaration in Tree.h line `70`; command20252 separately proves the repaired ordinary destination. Dated moving tracker command `20474` observed UID0002MZ's `91/93`, reconstructable, and `0/0/0` report-coverage semantics; command20473, command20472, command20463, command20404, commands20384/20381/20355, and commands `20207`, `20304`, `20306`, `20172`/`20175`, `20170`, `20160`, `20109`, `20104`, `20024`, `20034`, `19993`, `19995`, `19928`, `19890`, `19891`, `19887`, `19812`, `19810`, and `19802` remain validator-owned dated historical artifacts.
- Failed/unavailable checks: none required for the target. MCP remained responsive. B003 issued no IDA mutation/save call. The accepted ordinary callback ran exactly 17 scoped ordinary-file validators: 13 initial implementation/reconciliation commands plus four no-loss current-prose commands; this post-maintenance report-currentness repair ran no validator.

## Claim And Incorporation Ledger

- Post-callback reconciliation: the ledger contains exactly 211 unique atomic claims. C2MZ-061/079/103/107/111-115/123-125 are applied, including UID0000JG's C2MZ-124 source-root payload; C2MZ-211 tracks the applied UID0000F9 `AppendChild` declaration, and C2MZ-204 tracks the applied generated/compile closure. A04/U00/U06 remain already-present. All 48 manual coverage operations, including six additional destination coverage rows C2MZ-205..210, are applied and independently exact-readback-verified. Supervisor gate/lifecycle disposition is external to the claim ledger and authoritative only from supervisor audit/readback plus validator-owned status/history metadata.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | ---: | --- | --- | --- | --- |
| C2MZ-001 | 0002MZ | Exact range is `[0x004b5bb0,0x004b5bd0)`, size `0x20`. | 100 | Live lookup/analyze/bytes. | UID0002MZ boundary evidence | incorporate | applied |
| C2MZ-002 | 0002MZ | Exact bytes SHA256 is `23B4CBEAAE3C31D2A6D2668EB35B5A93F99DEAC2643937936FCBBE9267E406AD`. | 100 | Exact 32-byte payload and SHA256. | UID0002MZ IDA facts | incorporate | applied |
| C2MZ-003 | 0002MZ | ABI is leaf `__thiscall`, with no stack argument and source return `bool`. | 100 | Assembly, exits, and no-callee result. | UID0002MZ ABI evidence | incorporate | applied |
| C2MZ-004 | 0002MZ | Sole caller is `0x004b2cbe` in `FolderTreePane::OnKeyEvent`. | 100 | Live xref/analyze plus class/vtable docs. | UID0002MZ caller inventory | incorporate | applied |
| C2MZ-005 | 0002MZ | The sole caller ignores AL and consumes the updated iterator index. | 100 | Caller branch sequence. | UID0002MZ behavior | incorporate | applied |
| C2MZ-006 | 000155 | FolderTree core consumes the updated iterator index after the target call. | 100 | Caller branch sequence. | UID000155 item summary | incorporate | applied |
| C2MZ-007 | 0002MZ | A `-1` child link returns false without mutating `m_currentIndex`. | 100 | Exact instructions. | UID0002MZ behavior | incorporate | applied |
| C2MZ-008 | 0002MZ | A valid child link is stored to `m_currentIndex` and returns true. | 100 | Exact instructions. | UID0002MZ formal H | incorporate | applied |
| C2MZ-009 | 0002MZ | `TreeItor` is the symbol-backed source spelling. | 100 | Decorated vtable at `0x0061a510`. | UID0002MZ naming evidence | incorporate | applied |
| C2MZ-010 | 0000FB | `TreeItor`, not `TreeIterator`, is the class spelling. | 100 | Decorated vtable at `0x0061a510`. | UID0000FB declaration | incorporate | applied |
| C2MZ-011 | 0001WP | The shared template inventory uses the spelling `TreeItor<T>`. | 100 | Decorated vtable at `0x0061a510`. | UID0001WP template inventory | incorporate | applied |
| C2MZ-012 | 0000FB | `TreeItor<T>` is 12 bytes: vptr, tree pointer, and current index. | 100 | UDT, scalar-delete width, and sibling methods. | UID0000FB layout | incorporate | applied |
| C2MZ-013 | 0002MZ | The target reads generic `TreeNode<T>::firstChildIndex` at node `+0x04`. | 99 | Exact load plus cross-specialization layout. | UID0002MZ behavior | incorporate | applied |
| C2MZ-014 | 0002MZ | The former payload-field interpretation for node `+0x04` is superseded. | 100 | Dual-instantiation size arithmetic. | UID0002MZ historical assumptions | historicalize | applied |
| C2MZ-015 | 0001UJ | `FolderTreePane::TreeElem` is the 12-byte payload inside a 36-byte node. | 97 | `0x24 = 0x14 + 0x0c + 1 + pad`. | UID0001UJ layout | incorporate | applied |
| C2MZ-016 | 0001UJ | The former monolithic 36-byte `FolderTreePane::TreeElem` model is superseded. | 100 | Two independent specialization layouts. | UID0001UJ historical assumptions | historicalize | applied |
| C2MZ-017 | 0001WP | Generic `TreeNode<T>` owns five links, `T data`, and `disabled`. | 97 | FolderTree/EventDispatcher size and semantic match. | UID0001WP template model | incorporate | applied |
| C2MZ-018 | 0000FC | Generic `TreeNode<T>` owns five links, `T data`, and `disabled`. | 97 | FolderTree/EventDispatcher size and semantic match. | UID0000FC formal H | incorporate | applied |
| C2MZ-019 | 0000FC | `TreeStorage<T>` stores pointers to `TreeNode<T>`. | 96 | 12-byte storage header and concrete strides. | UID0000FC formal H | incorporate | applied |
| C2MZ-020 | 0000FC | `TreeStorage<T>::operator[]` returns a `TreeNode<T>` reference. | 96 | Indexed node accesses. | UID0000FC formal H | incorporate | applied |
| C2MZ-021 | 0000FC | The former bare-`T` storage declaration is superseded. | 100 | Node strides and surrounding link/state accesses. | UID0000FC historical assumptions | historicalize | applied |
| C2MZ-022 | 0000F9 | `Tree<T>` contains `TreeStorage<T> m_storage`. | 99 | Vtable/layout/current docs. | UID0000F9 formal H | incorporate | applied |
| C2MZ-023 | 0000FB | `TreeItor<T>` belongs in the formal H channel. | 98 | Cross-module template use and vtable. | UID0000FB formal H | incorporate | applied |
| C2MZ-024 | 0002MZ | `MoveToFirstChild` is a generic header definition. | 96 | Only generic node fields are used. | UID0002MZ formal H | incorporate | applied |
| C2MZ-025 | 0002MZ | The former FolderTree-only CPP specialization is superseded. | 98 | No payload-specific access or specialization-symbol evidence. | UID0002MZ historical assumptions | historicalize | applied |
| C2MZ-026 | 0002N0 | `MoveToNextVisibleSibling` is a generic header definition. | 96 | Exact sibling body and cross-template state byte. | UID0002N0 formal H | incorporate | applied |
| C2MZ-027 | 0002N0 | The former concrete CPP specialization is superseded. | 98 | No payload-specific access. | UID0002N0 historical assumptions | historicalize | applied |
| C2MZ-028 | 0002N0 | The former `TreeElem.hidden` wording is superseded by generic `TreeNode<T>::disabled`. | 100 | EventDispatcher semantics and live comment prestate. | UID0002N0 historical assumptions | historicalize | applied |
| C2MZ-029 | 0002N1 | `MoveToParent` is a generic header definition. | 96 | Exact sibling body uses only the generic parent link. | UID0002N1 formal H | incorporate | applied |
| C2MZ-030 | 0002N1 | The former concrete CPP specialization is superseded. | 98 | No payload-specific access. | UID0002N1 historical assumptions | historicalize | applied |
| C2MZ-031 | 0002MY | Reset remains a concrete `Tree<FolderTreePane::TreeElem>` specialization. | 94 | Payload-specific writes. | UID0002MY formal CPP | incorporate | applied |
| C2MZ-032 | 0002MY | Reset constructs `TreeNode<TreeElem>` and reaches payload state through `.data`. | 99 | Exact concrete offsets. | UID0002MY behavior | incorporate | applied |
| C2MZ-033 | 0002MY | The former monolithic-payload reset model is superseded. | 100 | Exact concrete offsets. | UID0002MY historical assumptions | historicalize | applied |
| C2MZ-034 | 0000JG | FolderTree source documentation distinguishes generic node state from payload state. | 98 | Current generated/source inventory. | UID0000JG source shape | incorporate | applied |
| C2MZ-035 | 000157 | The broad aggregate remains non-reconstructable split/index evidence. | 100 | Exact children and mixed range. | UID000157 disposition | already-present | already-present |
| C2MZ-036 | 0002MZ | Canonical owner remains UID0000FB. | 100 | Exact semantic class. | UID0002MZ metadata | already-present | already-present |
| C2MZ-037 | 0002MZ | Emitter remains UID0000FB. | 100 | Exact semantic class. | UID0002MZ metadata | already-present | already-present |
| C2MZ-038 | 0002MZ | Emitter position remains 40. | 100 | Exact iterator method order. | UID0002MZ metadata | already-present | already-present |
| C2MZ-039 | 0002MZ | Evidence-calibrated score becomes `91/93`. | 95 | Behavior/source model resolved; residual cap is inferred original lexical spelling and final historical source-path uncertainty. | UID0002MZ metadata | incorporate | applied |
| C2MZ-040 | 0002MZ | Target IDA function receives the exact A01 name/type/comment action. | 100 | Catalog0365 applied/readback under historical `412DA7E8...519CD`; the latest `f608d7c2`/`B7CC899D...8058277` bounded read-only no-drift recheck preserves exact bytes, sole xref, type, comment, and typed body. | IDA A01 | incorporate | applied |
| C2MZ-041 | 0002N1 | Parent-move IDA function receives the exact A02 name/type/comment action. | 99 | Catalog0365 applied/readback under historical `412DA7E8...519CD`; the latest `f608d7c2`/`B7CC899D...8058277` bounded read-only no-drift recheck preserves the matching typed parent body. | IDA A02 | incorporate | applied |
| C2MZ-042 | 0002N0 | Next-visible-sibling IDA function keeps its name/type and receives the exact A03 comment correction. | 100 | Catalog0365 applied/readback and the latest `f608d7c2`/`B7CC899D...8058277` bounded no-drift verification; decompile exposes `m_tree`, `nextSiblingIndex`, `v4`, `m_begin`, and `disabled`. | IDA A03 | incorporate | applied |
| C2MZ-043 | 000155 | A04 caller `0x004b2b80` remains unchanged as a protected dependency with its exact function/frame/local/comment/internal-switch state preserved. | 100 | Latest `f608d7c2`/`B7CC899D...8058277` protected readback, preserved type/first bytes/data xref, call sites, and broad switch/callback ABI; B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, 87D3, A4A6, 6470, 222D, EEF0, 412D, and earlier identities are dated history. | IDA A04 protected caller readback | already-present | already-present |
| C2MZ-044 | 0002MZ | The current unsplit target range is correct; no address split or merge is required. | 100 | Exact boundaries/items/padding prove one complete leaf body. | UID0002MZ range analysis | already-present | already-present |
| C2MZ-045 | 0002MZ | The current one-page target disposition is correct; no new by-memory child is required. | 100 | One complete modeled leaf body with no subordinate source unit. | UID0002MZ range analysis | already-present | already-present |
| C2MZ-046 | 0002MZ | The current project-authored disposition is correct; no third-party import is required. | 100 | Project-authored template behavior with no external-library provenance. | UID0002MZ third-party disposition | already-present | already-present |
| C2MZ-047 | 0002MZ | The current direct source-authored route is correct; no compiler-glue or no-code disposition is required. | 100 | Direct iterator state mutation rather than compiler-generated ABI support. | UID0002MZ source disposition | already-present | already-present |
| C2MZ-048 | 0002MZ | Supervisor applied the exact target manual coverage replacement. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID0002MZ row | incorporate | applied |
| C2MZ-049 | 00005A | `FolderTreePane` embeds complete `Tree<TreeElem>`. | 95 | Exact object layout. | UID00005A formal H | incorporate | applied |
| C2MZ-050 | 00005A | `FolderTreePane::TreeElem::name` uses pointer-backed `StringBase`. | 95 | Exact payload width and compiler type evidence. | UID00005A formal H | incorporate | applied |
| C2MZ-051 | 00005A | `FolderTreePane` embeds a complete `EPFTileContext` value member. | 99 | Exact object layout and C++ completeness. | UID00005A formal H | incorporate | applied |
| C2MZ-052 | 00005A | The former incomplete EPFTileContext dependency is superseded. | 100 | Current generated compile shape. | UID00005A historical assumptions | historicalize | applied |
| C2MZ-053 | 00005A | The former SSO-string interpretation is superseded. | 100 | Exact 12-byte payload. | UID00005A historical assumptions | historicalize | applied |
| C2MZ-054 | 00005A | The former CPP-only class declaration is superseded. | 100 | Header dependency requirements. | UID00005A historical assumptions | historicalize | applied |
| C2MZ-055 | 00005A | The former file-local helper with illegal private access is superseded. | 100 | C++ access-control rules. | UID00005A historical assumptions | historicalize | applied |
| C2MZ-056 | 000155 | FolderTree core methods consume `TreeNode<TreeElem>` records. | 97 | Current core inventory and child bodies. | UID000155 inventory | incorporate | applied |
| C2MZ-057 | 000155 | FolderTree core reaches payload-specific state through `.data`. | 97 | Concrete offsets. | UID000155 item summary | incorporate | applied |
| C2MZ-058 | 000155 | The former monolithic 36-byte payload terminology is superseded. | 100 | Exact node/payload offsets. | UID000155 historical assumptions | historicalize | applied |
| C2MZ-059 | 000344 | Content traversal uses generic node links and payload fields through `.data`. | 99 | Exact body offsets. | UID000344 formal CPP | incorporate | applied |
| C2MZ-060 | 000345 | Paint traversal uses generic node links and the payload-aware paint member. | 99 | Exact body offsets. | UID000345 formal CPP | incorporate | applied |
| C2MZ-061 | 000346 | Hit-test source uses the existing 16-byte `RectBounds` and its observed `ContainsPoint(y, x)` ordering, not invented `Rect::Contains(x, y)`. | 99 | Exact 0x004b3850 body, UID0000BU contract, and repaired syntax pass. | UID000346 formal CPP | incorporate | applied |
| C2MZ-062 | 000347 | Visible navigation separates generic links from payload expansion state. | 99 | Exact body offsets. | UID000347 formal CPP | incorporate | applied |
| C2MZ-063 | 00034H | Per-node painting is the private static member `FolderTreePane::PaintTreeNode`. | 97 | Exact receiver use and access-control repair. | UID00034H formal CPP | incorporate | applied |
| C2MZ-064 | 00034H | The former file-local helper source shape is superseded. | 100 | Illegal private-member access. | UID00034H historical assumptions | historicalize | applied |
| C2MZ-065 | 0002MV | Insert/grow operates on 36-byte `TreeNode<TreeElem>` records. | 99 | Exact stride/copy/destroy paths. | UID0002MV marker and prose | incorporate | applied |
| C2MZ-066 | 0002MV | Bare-payload insert/grow terminology is superseded. | 100 | Exact `0x24` stride. | UID0002MV historical assumptions | historicalize | applied |
| C2MZ-067 | 0002MW | The compiler copy helper copies a complete 36-byte node. | 100 | Exact copied links/payload/state. | UID0002MW marker and prose | incorporate | applied |
| C2MZ-068 | 0002MW | Payload-only copy attribution is superseded. | 100 | Exact copied fields. | UID0002MW historical assumptions | historicalize | applied |
| C2MZ-069 | 0002MX | Storage destruction walks 36-byte nodes and destroys `node.data.name` at concrete `+0x14`. | 100 | Exact stride/destructor offset. | UID0002MX marker and prose | incorporate | applied |
| C2MZ-070 | 0002MX | Monolithic-payload destruction wording is superseded. | 100 | Exact destructor offset. | UID0002MX historical assumptions | historicalize | applied |
| C2MZ-071 | 00022E | The mixed aggregate separates 36-byte node support from 12-byte DirectoryEntry support. | 99 | Exact seven-child inventory. | UID00022E inventory | incorporate | applied |
| C2MZ-072 | 00022E | Mixed use of `TreeElem` for both widths is superseded. | 100 | Exact child widths. | UID00022E historical assumptions | historicalize | applied |
| C2MZ-073 | 000447 | Range destruction is compiler support for 36-byte nodes. | 100 | `+0x14` destruction and caller. | UID000447 marker and prose | incorporate | applied |
| C2MZ-074 | 000447 | Payload-only range-destruction wording is superseded. | 100 | Exact width and offset. | UID000447 historical assumptions | historicalize | applied |
| C2MZ-075 | 000449 | Range copy is compiler support for full 36-byte nodes. | 100 | Exact copied fields. | UID000449 marker and prose | incorporate | applied |
| C2MZ-076 | 000449 | Payload-only range-copy wording is superseded. | 100 | Exact copied fields. | UID000449 historical assumptions | historicalize | applied |
| C2MZ-077 | 00044B | Vector free releases storage allocated for 36-byte nodes. | 100 | Allocation width and caller. | UID00044B marker and prose | incorporate | applied |
| C2MZ-078 | 00044B | Payload-only vector-free wording is superseded. | 100 | Exact allocation width. | UID00044B historical assumptions | historicalize | applied |
| C2MZ-079 | 000343 | Directory-entry comparison calls the existing helper as `mystr::WideRangeCompare`, with its declaration carried by the StringBase header owner. | 98 | Existing definition namespace, exact comparison body, and repaired compile pass. | UID000343 formal CPP | incorporate | applied |
| C2MZ-080 | 000343 | Its former 36-byte `TreeElem` comparison label is superseded. | 100 | Corrected node/payload split. | UID000343 historical assumptions | historicalize | applied |
| C2MZ-081 | 000348 | Its 12-byte DirectoryEntry facts are preserved while the compared family is named `TreeNode<FolderTreePane::TreeElem>`. | 98 | Exact comparison widths. | UID000348 comparison prose | incorporate | applied |
| C2MZ-082 | 000348 | Its former 36-byte `TreeElem` comparison label is superseded. | 100 | Corrected node/payload split. | UID000348 historical assumptions | historicalize | applied |
| C2MZ-083 | 00034B | Its 12-byte DirectoryEntry facts are preserved while the compared family is named `TreeNode<FolderTreePane::TreeElem>`. | 98 | Exact comparison widths. | UID00034B comparison prose | incorporate | applied |
| C2MZ-084 | 00034B | Its former 36-byte `TreeElem` comparison label is superseded. | 100 | Corrected node/payload split. | UID00034B historical assumptions | historicalize | applied |
| C2MZ-085 | 00034C | Its 12-byte DirectoryEntry facts are preserved while the compared family is named `TreeNode<FolderTreePane::TreeElem>`. | 98 | Exact comparison widths. | UID00034C comparison prose | incorporate | applied |
| C2MZ-086 | 00034C | Its former 36-byte `TreeElem` comparison label is superseded. | 100 | Corrected node/payload split. | UID00034C historical assumptions | historicalize | applied |
| C2MZ-087 | 00034E | Its 12-byte DirectoryEntry facts are preserved while the compared family is named `TreeNode<FolderTreePane::TreeElem>`. | 98 | Exact comparison widths. | UID00034E comparison prose | incorporate | applied |
| C2MZ-088 | 00034E | Its former 36-byte `TreeElem` comparison label is superseded. | 100 | Corrected node/payload split. | UID00034E historical assumptions | historicalize | applied |
| C2MZ-089 | 00031B | Its 12-byte DirectoryEntry facts are preserved while the compared family is named `TreeNode<FolderTreePane::TreeElem>`. | 98 | Exact comparison widths. | UID00031B comparison prose | incorporate | applied |
| C2MZ-090 | 00031B | Its former 36-byte `TreeElem` comparison label is superseded. | 100 | Corrected node/payload split. | UID00031B historical assumptions | historicalize | applied |
| C2MZ-091 | 0002MZ | Generated command 18812 is retained only as the historical implementation-time pre-closure checkpoint. | 100 | Exact generated header/hash and later command 19221 readback. | report generated chronology | historicalize | applied |
| C2MZ-092 | 0002MZ | Generated command 18808 is retained only as historical chronology. | 100 | Exact prior generated header/hash. | report generated chronology | historicalize | applied |
| C2MZ-093 | 0004YK | The literal registration-ready page is created before route migration. | 100 | UID workflow and missing shared source root. | UID0004YK by-file/Tree.md page payload | incorporate | applied |
| C2MZ-094 | 0001WP | The canonical temporary pre-registration token is retained only as historical workflow evidence; current ordinary references use assigned UID0004YK. | 100 | Registration and zero-residue readback. | UID0001WP historical source-placement assumptions | historicalize | applied |
| C2MZ-095 | 0001WP | After registration, its generic-template route migrates to the validator-assigned Tree UID. | 96 | Cross-module generic use. | UID0001WP metadata | incorporate | applied |
| C2MZ-096 | 0000FC | After registration, its generic-template route migrates to the validator-assigned Tree UID. | 96 | Cross-module generic use. | UID0000FC metadata | incorporate | applied |
| C2MZ-097 | 0000F9 | After registration, its generic-template route migrates to the validator-assigned Tree UID. | 96 | Cross-module generic use. | UID0000F9 metadata | incorporate | applied |
| C2MZ-098 | 0000FB | After registration, its generic-template route migrates to the validator-assigned Tree UID. | 96 | Cross-module generic use. | UID0000FB metadata | incorporate | applied |
| C2MZ-099 | 00007D | The complete `LObject` declaration moves to formal H. | 95 | Exact class declaration and missing header. | UID00007D formal H | incorporate | applied |
| C2MZ-100 | 0001WS | The pointer-backed `StringBase` declaration moves to formal H. | 91 | Compiler type name and four-byte layout. | UID0001WS formal H | incorporate | applied |
| C2MZ-101 | 0001UJ | The 24-byte SSO `SimpleUString` interpretation is rejected for `TreeElem::name`. | 95 | Exact 12-byte payload. | UID0001UJ historical assumptions | historicalize | applied |
| C2MZ-102 | 0001UJ | The accepted `name` type is four-byte pointer-backed `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`. | 95 | Compiler type and payload width. | UID0001UJ current source model | incorporate | applied |
| C2MZ-103 | 0000BU | The existing 16-byte `RectBounds` declaration moves to central `ui/core/RectBounds.h` with its y/x `ContainsPoint` contract. | 99 | Existing UID0000BU formal, exact 16-byte layout, and call order. | UID0000BU formal H | incorporate | applied |
| C2MZ-104 | 0000F9 | Generic `Tree<T>` exposes only generic storage/reset/traversal APIs. | 91 | Source-shape constraint. | UID0000F9 formal H | incorporate | applied |
| C2MZ-105 | 000344 | Its body is an explicit specialization of generic `Tree<T>::Traverse<Visitor>`. | 94 | Exact concrete body. | UID000344 formal CPP | incorporate | applied |
| C2MZ-106 | 000345 | Its body is an explicit specialization of generic `Tree<T>::Traverse<Visitor>`. | 94 | Exact concrete body. | UID000345 formal CPP | incorporate | applied |
| C2MZ-107 | 000156 | `SetSelection` uses `RectBounds` and explicit `unsigned short` conversions at both `ApplyScrollPosition` low-word ABI calls. | 98 | Exact source diagnostics, existing method ABI, and warning-free repaired pass. | UID000156 formal CPP | incorporate | applied |
| C2MZ-108 | 000347 | Its body is an explicit specialization of generic `Tree<T>::Traverse<Visitor>`. | 94 | Exact concrete body. | UID000347 formal CPP | incorporate | applied |
| C2MZ-109 | 00034H | `PaintTreeNode` is a private static `FolderTreePane` member. | 95 | Exact receiver use and private access. | UID00034H formal CPP | incorporate | applied |
| C2MZ-110 | 00005A | `Tree<T>` is declared as a friend for concrete traversal specialization access. | 95 | C++ access-control repair. | UID00005A formal H | incorporate | applied |
| C2MZ-111 | 0000A2 | The complete Pane header exposes inherited `InvalidateRect(const RectBounds *)` without a skeletal final-class substitute. | 97 | Existing Pane ownership plus exact FolderTreePane call site. | UID0000A2 formal H | incorporate | applied |
| C2MZ-112 | 0001WS | StringBase header declares `DetachWideIfShared()` and namespaced `WideRangeCompare(...)` while preserving its one-pointer layout. | 98 | Existing definitions and repaired compile pass. | UID0001WS formal H | incorporate | applied |
| C2MZ-113 | 0000CF | The complete ScrollablePane header exposes exact scroll getters, unsigned-short `ApplyScrollPosition`, and `RectBounds m_contentRect`. | 98 | Current IDA type at 0x0055eae0, callers, and repaired compile pass. | UID0000CF formal H | incorporate | applied |
| C2MZ-114 | 00004I | EPFTileContext includes central `RectBounds.h` and removes its duplicate local rectangle declaration. | 99 | Existing exact 0x28-byte layout and duplicate-free repaired pass. | UID00004I formal H | incorporate | applied |
| C2MZ-115 | 0000NF | ScrollBar.h includes complete Pane/rectangle dependencies and removes the literal no-children placeholder token. | 99 | Direct current-header diagnostics and repaired header pass. | UID0000NF source-root H assembly contract | incorporate | applied |
| C2MZ-116 | 0000JG | Proposed source tree does not add `Tree.cpp`. | 96 | Header-only template evidence. | by-project-structure/proposed-source-tree.md | incorporate | applied |
| C2MZ-117 | 0004YK | Registration command 18916 read assigned UID0004YK from both the page header and validator mapping. | 100 | Validator UID workflow. | UID0004YK registration readback | incorporate | applied |
| C2MZ-118 | 0004YK | Post-registration reconciliation proves zero temporary registration-token residue across all 43 ordinary callback destinations. | 100 | Validator TMP workflow. | UID0004YK zero-residue readback | incorporate | applied |
| C2MZ-119 | 00007D | Generated `LObject.h` must read back and compile before final closure. | 100 | Exact command-19802 hash re-read; direct x86 `cl /Zs /Za` syntax pass exited `0`. | final compile checklist | incorporate | applied |
| C2MZ-120 | 0001WS | Generated `StringBase.h` must read back and compile before final closure. | 100 | Exact command-19802 hash re-read; direct x86 `cl /Zs /Za` syntax pass exited `0`; target harness also proves the four-byte wide specialization. | final compile checklist | incorporate | applied |
| C2MZ-121 | 0004YK | Generated `Tree.h` must read back and compile before final closure. | 100 | Exact command-19802 hash re-read; direct `Tree.h` and trace-only `Tree.cpp` x86 `/Zs /Za` passes exited `0`; isolated actual-header harness instantiated UID0002MZ and proved 12/36/12/16/12-byte concrete layouts under `/Za` and explicit `/std:c++14 /permissive-`. | final compile checklist | incorporate | applied |
| C2MZ-122 | 00004I | Generated `EPFTileContext.h` must read back and compile before final closure. | 100 | Exact command-19802 hash re-read; direct x86 `cl /Zs /Za` syntax pass exited `0`. | final compile checklist | incorporate | applied |
| C2MZ-123 | 00005A | FolderTreePane.h declares exact nested `DirectoryEntry` and private `GetNodeBounds(...)` in addition to its existing TreeElem/template dependencies. | 100 | Missing-name diagnostics, exact 12-byte entry layout, method callers, and repaired header pass. | UID00005A formal H | incorporate | applied |
| C2MZ-124 | 0000JG | `FolderTreePane::ExpandNode(TreeItor<TreeElem> *)` is the owning source function for `DirectoryEntryNameLess`; its destination-ready source-root CPP assembly includes `<algorithm>`/`<vector>`/`<wchar.h>`, filesystem enumeration, `std::sort(entries.begin(), entries.end(), DirectoryEntryNameLess)`, sorted child insertion, loaded/expanded transitions, and layout refresh. | 99 | Historical full decompile plus latest `f608d7c2`/`B7CC899D...8058277` direct xref reconfirmation of `0x004b214e -> 0x004b5280`, exact post-sort insertion loop, flags, first-child test, and `RefreshTreeLayout`; UID0000JG contains the accepted assembly and scoped validator command `20068` exited `0` with `ok: 1`. | `by-file/FolderTreePane.md` formal CPP assembly contract | incorporate | applied |
| C2MZ-125 | 0002LN | WideRangeCompare documents its `mystr` namespace/header declaration route so consumers never invent an unqualified external helper, and its physical formal CPP exactly matches the canonical report payload. | 99 | Existing namespaced definition and exact UID000343 consumer; command20385 validates physical/report formal equality at SHA256 `2C7DF766...B9B7654A`, `10108` bytes / `127` lines. | UID0002LN source/header placement prose and formal CPP | incorporate | applied |
| C2MZ-126 | 00005A | The exact 12-byte `TreeElem` declaration emits once as the nested class declaration. | 99 | Nested-type ownership. | UID00005A formal H | incorporate | applied |
| C2MZ-127 | 0001UJ | Its formal H remains blank and its CPP channel contains only the exact no-duplicate trace comment; the nested payload definition emits once through UID00005A H. | 99 | One-definition rule and current generated readback. | UID0001UJ formal disposition | incorporate | applied |
| C2MZ-128 | 0000FB | `TreeItor<T>` reaches nodes through public `Tree<T>::NodeAt`. | 98 | C++ access control and exact indexing. | UID0000FB formal H | incorporate | applied |
| C2MZ-129 | 0000F9 | `Tree<T>` alone retains protected `m_storage`. | 98 | C++ access control. | UID0000F9 formal H | incorporate | applied |
| C2MZ-130 | 0002MZ | `MoveToFirstChild` uses public `NodeAt`. | 98 | Exact indexed node behavior. | UID0002MZ formal H | incorporate | applied |
| C2MZ-131 | 0002N0 | `MoveToNextVisibleSibling` uses public `NodeAt`. | 98 | Exact indexed node behavior. | UID0002N0 formal H | incorporate | applied |
| C2MZ-132 | 0002N1 | `MoveToParent` uses public `NodeAt`. | 98 | Exact indexed node behavior. | UID0002N1 formal H | incorporate | applied |
| C2MZ-133 | 00007D | Supervisor applied the exact UID00007D class coverage replacement. | 100 | Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10` confirms this operation applied. | by-class/-coverage-report.md UID00007D row | incorporate | applied |
| C2MZ-134 | 0001WS | Supervisor applied the exact UID0001WS template coverage replacement. | 100 | Supervisor command `000000020466` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `1A62AD2DD4F3C6F7BF94CF3BFC2AA3181B0F95601CD9062426402934FC2A1AA9` confirms this operation applied. | by-type/by-template/-coverage-report.md UID0001WS row | incorporate | applied |
| C2MZ-135 | 00004I | Supervisor applied the exact UID00004I class coverage replacement. | 100 | Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10` confirms this operation applied. | by-class/-coverage-report.md UID00004I row | incorporate | applied |
| C2MZ-136 | 0004YK | Supervisor applied the exact assigned-UID0004YK coverage-row insertion. | 100 | Supervisor command `000000020465` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66` confirms this operation applied. | by-file/-coverage-report.md Tree row template | incorporate | applied |
| C2MZ-137 | 0002MZ | U00 `SimpleUString` remains unchanged as the protected four-byte pointer-backed IDA artifact and is not reused as the separate source SSO class. | 100 | Latest `f608d7c2`/`B7CC899D...8058277` exact protected one-member readback; B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, 87D3, A4A6, 6470, 222D, and earlier identities are dated history. | IDA U00 protected type readback | already-present | already-present |
| C2MZ-138 | 0001WS | U01 creates the exact four-byte `StringBaseWide` IDA alias with one `wchar_t *m_data` member at `+0x00`. | 98 | Catalog0365 exact size/member readback, reconfirmed read-only on `f608d7c2` against `B7CC899D...8058277`. | IDA U01 type action | incorporate | applied |
| C2MZ-139 | 0001UJ | U02 repairs the non-UDT `FolderTreePaneTreeElem` artifact into the exact 12-byte five-member payload UDT. | 99 | Catalog0365 exact `0x0c` readback, reconfirmed read-only on `f608d7c2` against `B7CC899D...8058277`; IDA-only `__declspec(align(4))` realizes implicit tail with no synthetic member. | IDA U02 type action | incorporate | applied |
| C2MZ-140 | 0000FC | U03 creates exact 36-byte `FolderTreePaneTreeNode` with five links, U02 payload, and trailing disabled byte. | 99 | Catalog0365 exact `0x24` readback, reconfirmed read-only on `f608d7c2` against `B7CC899D...8058277`; IDA-only alignment realizes implicit tail and preserves `disabled +0x20`. | IDA U03 type action | incorporate | applied |
| C2MZ-141 | 0000FC | U04 creates exact 12-byte `FolderTreePaneTreeStorage` with begin/end/capacity pointers to U03 nodes. | 99 | Catalog0365 exact three-pointer readback, reconfirmed read-only on `f608d7c2` against `B7CC899D...8058277`. | IDA U04 type action | incorporate | applied |
| C2MZ-142 | 0000F9 | U05 preserves `FolderTreePaneTree` size/vftable and replaces only its raw 12-byte storage array with typed U04 `m_storage`. | 99 | Catalog0365 exact size `0x10` and typed storage readback, reconfirmed read-only on `f608d7c2` against `B7CC899D...8058277`; vftable preserved. | IDA U05 type action | incorporate | applied |
| C2MZ-143 | 0000FB | U06 `TreeItorFolderTreePaneTreeElem` remains unchanged as the protected 12-byte iterator UDT while resolving through updated U05. | 100 | Latest `f608d7c2`/`B7CC899D...8058277` exact protected three-member readback; B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, 87D3, A4A6, 6470, 222D, and earlier identities are dated history. | IDA U06 protected type readback | already-present | already-present |
| C2MZ-144 | 000157 | Supervisor replaced the exact UID000157 by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000157 row | incorporate | applied |
| C2MZ-145 | 000155 | Supervisor replaced the exact UID000155 by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000155 row | incorporate | applied |
| C2MZ-146 | 000343 | Supervisor inserted the exact UID000343 by-memory manual coverage row in address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000343 row | incorporate | applied |
| C2MZ-147 | 000344 | Supervisor replaced the exact UID000344 by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000344 row | incorporate | applied |
| C2MZ-148 | 000345 | Supervisor replaced the exact UID000345 by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000345 row | incorporate | applied |
| C2MZ-149 | 000346 | Supervisor inserted the exact UID000346 by-memory manual coverage row in address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000346 row | incorporate | applied |
| C2MZ-150 | 000347 | Supervisor inserted the exact UID000347 by-memory manual coverage row in address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000347 row | incorporate | applied |
| C2MZ-151 | 0002MV | Supervisor replaced the exact UID0002MV by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID0002MV row | incorporate | applied |
| C2MZ-152 | 000348 | Supervisor inserted the exact UID000348 by-memory manual coverage row in address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000348 row | incorporate | applied |
| C2MZ-153 | 00034B | Supervisor inserted the exact UID00034B by-memory manual coverage row in address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID00034B row | incorporate | applied |
| C2MZ-154 | 00034C | Supervisor inserted the exact UID00034C by-memory manual coverage row in address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID00034C row | incorporate | applied |
| C2MZ-155 | 00034E | Supervisor inserted the exact UID00034E by-memory manual coverage row in address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID00034E row | incorporate | applied |
| C2MZ-156 | 0002MW | Supervisor replaced the exact UID0002MW by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID0002MW row | incorporate | applied |
| C2MZ-157 | 0002MX | Supervisor replaced the exact UID0002MX by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID0002MX row | incorporate | applied |
| C2MZ-158 | 00031B | Supervisor inserted the exact UID00031B by-memory manual coverage row in address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID00031B row | incorporate | applied |
| C2MZ-159 | 00034H | Supervisor replaced the exact UID00034H by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID00034H row | incorporate | applied |
| C2MZ-160 | 0002N0 | Supervisor replaced the exact UID0002N0 by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID0002N0 row | incorporate | applied |
| C2MZ-161 | 0002N1 | Supervisor replaced the exact UID0002N1 by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID0002N1 row | incorporate | applied |
| C2MZ-162 | 00022E | Supervisor replaced the exact UID00022E by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID00022E row | incorporate | applied |
| C2MZ-163 | 000447 | Supervisor inserted the exact UID000447 by-memory manual coverage row beneath UID00022E in child-address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000447 row | incorporate | applied |
| C2MZ-164 | 000449 | Supervisor inserted the exact UID000449 by-memory manual coverage row beneath UID00022E in child-address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000449 row | incorporate | applied |
| C2MZ-165 | 00044B | Supervisor inserted the exact UID00044B by-memory manual coverage row beneath UID00022E in child-address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID00044B row | incorporate | applied |
| C2MZ-166 | 00005A | Supervisor replaced the exact UID00005A by-class manual coverage row at its sorted position. | 100 | Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10` confirms this operation applied. | by-class/-coverage-report.md UID00005A row | incorporate | applied |
| C2MZ-167 | 0000F9 | Supervisor replaced the exact UID0000F9 by-class manual coverage row at its sorted position. | 100 | Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10` confirms this operation applied. | by-class/-coverage-report.md UID0000F9 row | incorporate | applied |
| C2MZ-168 | 0000FB | Supervisor replaced the exact UID0000FB by-class manual coverage row at its sorted position. | 100 | Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10` confirms this operation applied. | by-class/-coverage-report.md UID0000FB row | incorporate | applied |
| C2MZ-169 | 0000FC | Supervisor replaced the exact UID0000FC by-class manual coverage row at its sorted position. | 100 | Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10` confirms this operation applied. | by-class/-coverage-report.md UID0000FC row | incorporate | applied |
| C2MZ-170 | 0001WP | Supervisor replaced the exact UID0001WP by-template manual coverage row in place. | 100 | Supervisor command `000000020466` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `1A62AD2DD4F3C6F7BF94CF3BFC2AA3181B0F95601CD9062426402934FC2A1AA9` confirms this operation applied. | by-type/by-template/-coverage-report.md UID0001WP row | incorporate | applied |
| C2MZ-171 | 0001UJ | Supervisor replaced the exact UID0001UJ by-struct manual coverage row in place. | 100 | Supervisor command `000000020467` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `4D576B5F0F6DE62841F0588BCA9BB710AAF023F6A2C5D68E8C423A10FFF0F7C5` confirms this operation applied. | by-type/by-struct/-coverage-report.md UID0001UJ row | incorporate | applied |
| C2MZ-172 | 0000JG | Supervisor replaced the exact UID0000JG by-file manual coverage row in place. | 100 | Supervisor command `000000020465` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66` confirms this operation applied. | by-file/-coverage-report.md UID0000JG row | incorporate | applied |
| C2MZ-173 | 0002MY | Supervisor replaced the formerly stale UID0002MY by-memory manual coverage row in place with the exact node/payload-reconciled row between UID00034H and UID0002MZ. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID0002MY row | incorporate | applied |
| C2MZ-174 | 0001WP | Shared Tree forward declarations emit first at position 0, with `Tree<T>` declared before every use and no dead H-child marker. | 100 | Deterministic emitter ordering and current generated readback. | UID0001WP metadata/formals | incorporate | applied |
| C2MZ-175 | 0000FC | Generic TreeNode/TreeStorage declarations emit at position 10 and no longer carry a dead H-child marker. | 100 | Deterministic emitter ordering and current generated readback. | UID0000FC metadata/formals | incorporate | applied |
| C2MZ-176 | 0000F9 | Generic Tree declaration emits at position 20 after complete TreeStorage and no longer carries a dead H-child marker. | 100 | Deterministic emitter ordering and C++ completeness. | UID0000F9 metadata/formals | incorporate | applied |
| C2MZ-177 | 0000FB | TreeItor emits at position 30 after Tree<T>; its CPP/H child markers both have actual generic method children. | 100 | Deterministic emitter ordering and current generated readback. | UID0000FB metadata/formals | incorporate | applied |
| C2MZ-178 | 0002MZ | Blank CPP is replaced by the exact header-only trace comment while the accepted H definition remains unchanged. | 100 | Empty-emitter closure and exact target formal. | UID0002MZ formal CPP | incorporate | applied |
| C2MZ-179 | 0002N0 | Blank CPP is replaced by the exact header-only trace comment while the accepted H definition remains unchanged. | 100 | Empty-emitter closure and exact sibling formal. | UID0002N0 formal CPP | incorporate | applied |
| C2MZ-180 | 0002N1 | Blank CPP is replaced by the exact header-only trace comment while the accepted H definition remains unchanged. | 100 | Empty-emitter closure and exact sibling formal. | UID0002N1 formal CPP | incorporate | applied |
| C2MZ-181 | 00005A | FolderTreePane.cpp receives `#include "FolderTreePane.h"` at position 0 and FolderTreePane.h drops its dead H-child marker. | 100 | Dependency-order and no-placeholder generated readback. | UID00005A metadata/formals | incorporate | applied |
| C2MZ-182 | 0001UJ | Its blank CPP becomes an exact no-duplicate trace comment while the nested type remains defined only in UID00005A H. | 100 | One-definition rule and empty-emitter closure. | UID0001UJ formal CPP | incorporate | applied |
| C2MZ-183 | 0002MY | Concrete reset keeps canonical owner 0000F9 but CPP-routes through FolderTreePane file UID0000JG at position 90. | 100 | Payload-specific specialization requires FolderTreePane declaration. | UID0002MY emitter metadata | incorporate | applied |
| C2MZ-184 | 0002MV | Concrete FolderTree storage support keeps canonical owner 0000FC but CPP-routes through UID0000JG at position 100. | 100 | Concrete payload instantiation versus generic header ownership. | UID0002MV emitter metadata | incorporate | applied |
| C2MZ-185 | 0002MX | Concrete FolderTree storage destruction keeps canonical owner 0000FC but CPP-routes through UID0000JG at position 110. | 100 | Concrete payload instantiation versus generic header ownership. | UID0002MX emitter metadata | incorporate | applied |
| C2MZ-186 | 000447 | Exact accepted range-destroy CPP text is restored and concrete CPP routing is UID0000JG position 120. | 100 | Report-to-doc exact text compare and concrete payload ownership. | UID000447 metadata/formal CPP | incorporate | applied |
| C2MZ-187 | 000449 | Exact accepted range-copy CPP text is restored and concrete CPP routing is UID0000JG position 130. | 100 | Report-to-doc exact text compare and concrete payload ownership. | UID000449 metadata/formal CPP | incorporate | applied |
| C2MZ-188 | 00044B | Exact accepted vector-free CPP text is restored and concrete CPP routing is UID0000JG position 140. | 100 | Report-to-doc exact text compare and concrete payload ownership. | UID00044B metadata/formal CPP | incorporate | applied |
| C2MZ-189 | 00034F | TreeItor concrete destructor support preserves canonical owner 0000FB and routes its trace to UID0000JG position 150. | 100 | Header declaration regenerates support; concrete instantiation belongs with consumer. | UID00034F emitter metadata | incorporate | applied |
| C2MZ-190 | 000158 | Tree concrete complete-object destructor preserves canonical owner 0000F9 and routes its trace to UID0000JG position 160. | 100 | Header declaration regenerates support; concrete instantiation belongs with consumer. | UID000158 emitter metadata | incorporate | applied |
| C2MZ-191 | 00034I | Tree concrete scalar deleting wrapper preserves canonical owner 0000F9 and routes its trace to UID0000JG position 170. | 100 | Compiler wrapper is generated from consumer specialization. | UID00034I emitter metadata | incorporate | applied |
| C2MZ-192 | 00036K | Tree concrete vtable data preserves canonical owner 0000F9 and routes its trace to UID0000JG position 180. | 100 | Compiler data is generated by concrete consumer instantiation. | UID00036K emitter metadata | incorporate | applied |
| C2MZ-193 | 00036J | Tree concrete vtable type preserves canonical owner 0000F9 and routes its trace to UID0000JG position 190. | 100 | Compiler type/data is generated by concrete consumer instantiation. | UID00036J emitter metadata | incorporate | applied |
| C2MZ-194 | 00036L | TreeItor concrete vtable type preserves canonical owner 0000FB, routes to UID0000JG position 200, and receives an exact no-raw-vtable CPP comment. | 100 | Concrete compiler artifact and empty-emitter closure. | UID00036L metadata/formal CPP | incorporate | applied |
| C2MZ-195 | 00036M | TreeItor concrete vtable data preserves canonical owner 0000FB, routes to UID0000JG position 210, and receives an exact no-raw-vtable CPP comment. | 100 | Concrete compiler artifact and empty-emitter closure. | UID00036M metadata/formal CPP | incorporate | applied |
| C2MZ-196 | 0004YK | The human source topology remains header-only; validator-owned Tree.cpp contains only trace comments because every valid by-file root has a companion CPP destination. | 100 | Validator root contract and dated command `20172` generated readback; command19802 supplied the matching historical compile baseline. | report generated/source-topology disposition | incorporate | applied |
| C2MZ-197 | 00034F | Supervisor replaced the formerly route-stale UID00034F by-memory manual coverage row in place. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID00034F row | incorporate | applied |
| C2MZ-198 | 000158 | Supervisor replaced UID000158 by-memory manual coverage row with exact concrete consumer-route wording. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000158 row | incorporate | applied |
| C2MZ-199 | 00034I | Supervisor replaced UID00034I by-memory manual coverage row with exact concrete consumer-route wording. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID00034I row | incorporate | applied |
| C2MZ-200 | 00036K | Supervisor inserted formerly absent UID00036K by-memory manual coverage row beneath UID00025C in address order. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID00036K row | incorporate | applied |
| C2MZ-201 | 00036J | Supervisor replaced UID00036J by-vtable manual coverage row with current score and concrete consumer-route wording. | 100 | Supervisor command `000000020468` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `5E96D33B2AFEADDB05F9605A4AC0EAC60E30000433D04FFB1E2BBCA0067921D3` confirms this operation applied. | by-type/by-vtable/-coverage-report.md UID00036J row | incorporate | applied |
| C2MZ-202 | 00036L | Supervisor replaced UID00036L by-vtable manual coverage row with current score and concrete consumer-route wording. | 100 | Supervisor command `000000020468` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `5E96D33B2AFEADDB05F9605A4AC0EAC60E30000433D04FFB1E2BBCA0067921D3` confirms this operation applied. | by-type/by-vtable/-coverage-report.md UID00036L row | incorporate | applied |
| C2MZ-203 | 00036M | Supervisor inserted formerly absent UID00036M by-memory manual coverage row immediately after UID00036K. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID00036M row | incorporate | applied |
| C2MZ-204 | 0004YK | Directly compile and read back the exact command20348 seven-artifact LObject/StringBase/Tree/EPFTileContext/FolderTreePane set to prove ordered Tree.h, trace-only Tree.cpp, exact route placement, zero errors, and closure of C4505 through the accepted real owner. | 100 | MSVC x86 `19.44.35226` consumed byte-identical copies of all seven command20348 artifacts. The raw baseline exited `0` with zero errors and one C4505 that exactly identified omitted generated owner method `FolderTreePane::ExpandNode`; the non-suppressed closure included the accepted binary-backed owner body with its real `std::sort(..., DirectoryEntryNameLess)` use and exited `0` with zero warnings/no C4505. All seven original hashes were unchanged before/after, all temporary files were removed, and no project/generated artifact changed. | UID0004YK final generated/compile closure checklist | incorporate | applied |
| C2MZ-205 | 0000BU | Supervisor replaced the exact UID0000BU by-class manual coverage row after its declaration moves from CPP to H and central `RectBounds.h` remains the sole declaration owner. | 100 | Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10` confirms this operation applied. | by-class/-coverage-report.md UID0000BU row | incorporate | applied |
| C2MZ-206 | 0000A2 | Supervisor replaced the exact UID0000A2 by-class manual coverage row after the complete recovered Pane interface is emitted in H. | 100 | Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10` confirms this operation applied. | by-class/-coverage-report.md UID0000A2 row | incorporate | applied |
| C2MZ-207 | 0000CF | Supervisor replaced the exact UID0000CF by-class manual coverage row after the complete recovered ScrollablePane interface/layout is emitted in H. | 100 | Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10` confirms this operation applied. | by-class/-coverage-report.md UID0000CF row | incorporate | applied |
| C2MZ-208 | 0000NF | Supervisor replaced the exact UID0000NF by-file manual coverage row after the ScrollBar header/source assembly receives complete dependencies and no placeholder token. | 100 | Supervisor command `000000020465` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66` confirms this operation applied. | by-file/-coverage-report.md UID0000NF row | incorporate | applied |
| C2MZ-209 | 000156 | Supervisor replaced the exact UID000156 by-memory manual coverage row after its complete formal CPP uses `RectBounds` and preserves both low-word scroll calls. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID000156 row | incorporate | applied |
| C2MZ-210 | 0002LN | Supervisor replaced the exact UID0002LN by-memory manual coverage row after its source/header route explicitly binds `mystr::WideRangeCompare` to StringBase. | 100 | Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` confirms this operation applied. | by-memory/-coverage-report.md UID0002LN row | incorporate | applied |
| C2MZ-211 | 0000F9 | Add the exact declaration `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);` to the existing UID0000F9 formal H payload and ordinary destination. | 100 | Gate 2A and dated command20172 proved the declaration absent before callback; command20252 now validates poststate SHA256 `23E93045...B6EB6D`, `24888` bytes, `173` lines, with the exact declaration present once after `NodeAt` and before `protected:`. | `by-class/Tree_struct_FolderTreePane__TreeElem_.md` formal H declaration | incorporate | applied |

## Positive Evidence Summary

- Post-Gate2B reconciliation: the accepted semantic model now has exact persisted IDA corroboration, including named methods, typed storage/node fields, and exact UDT sizes without byte/xref/control-flow drift.
- Exact 32-byte leaf method has one clear state transition and one sentinel branch.
- The named RTTI/vtable identity proves the unusual `TreeItor` spelling and concrete `FolderTreePane::TreeElem` instantiation.
- Thirty-one incoming vtable stores tie the iterator to FolderTreePane construction, traversal, temporary cleanup, paint, and destruction.
- Target and A02 parent method use the same iterator/tree/index layout and generic link offsets.
- EventDispatcher supplies an independent `TreeItor<EventHandler *>` instantiation with the same iterator shape, five-link record prefix, and trailing nonzero-disabled state.
- Exact size arithmetic independently reconstructs both concrete records without padding guesses.
- The method uses no payload-specific field. Generic header definition is therefore simpler and more likely than an explicit specialization.
- Current owner/emitter order is already correct and requires no ownership invention.

## IDA MCP Facts

- Latest post-Gate2B bounded readback checkpoint: MCP database `f608d7c2`; saved IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, size `143192751`, saved `2026-07-31T06:21:13.3464834-04:00`. Catalog entry `0365` remains the ordered historical supervisor transaction record, and bounded read-only checks show no target/dependency/protected-entity drift. Exact bounded chronology is 9F8A, B180, CF188, dated shared `4B5F...`, `1BC3C43B...B6800CFD`, and `5F2679A7...FC79A21`, then the latest target-local `B7CC899D...8058277` reread; 9F8A, B180, CF188, 4B5F, 1BC3, 5F2679, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, 87D3, and 6470 are dated history. The B7CC checkpoint is a bounded report checkpoint only, not durable global authority; live item-by-item Gate 2B reread is required before any future action.
- Function: `TreeItorFolderTreePaneTreeElem_MoveToFirstChild`, start `0x004b5bb0`, size `0x20`, exclusive end `0x004b5bd0`.
- Current prototype: `bool __thiscall(TreeItorFolderTreePaneTreeElem *this)`.
- Exact bytes: `8B 41 08 56 8B 71 04 8D 14 C0 8B 46 04 5E 8B 44 90 04 83 F8 FF 75 03 32 C0 C3 89 41 08 B0 01 C3`.
- Byte SHA256: `23B4CBEAAE3C31D2A6D2668EB35B5A93F99DEAC2643937936FCBBE9267E406AD`.
- Instructions: 14; basic blocks: 3; cyclomatic complexity: 1.
- Current decompiler expression: `this->m_tree->m_storage.m_begin[this->m_currentIndex].firstChildIndex`; source formal remains the human `m_tree->NodeAt(m_currentIndex).firstChildIndex` accessor form.
- ABI: ECX `this`; ESI preserved; no stack arguments; false/true returned as exact `0`/`1` in AL; plain `ret`.
- One incoming code xref at `0x004b2cbe` from `sub_4B2B80`, size `0x20c`; no target callees, strings, or constants.
- Comments at `0x004b5bb0`: regular blank, repeatable blank, function regular is the exact accepted `MoveToFirstChild` behavior comment, function repeatable blank.
- Pointer-route negatives: zero little-endian absolute VA `B0 5B 4B 00`, RVA `B0 5B 0B 00`, and raw-offset candidate `B0 4F 0B 00` hits.
- Predecessor UID0002MY ends at `0x004b5bae`; `[0x004b5bae,0x004b5bb0)` is exactly two `CC` bytes.
- Successor UID0002N0 starts exactly at `0x004b5bd0`; no target tail or shared chunk crosses the endpoint.
- Vtable base `0x0061a510`: name `??_7?$TreeItor@UTreeElem@FolderTreePane@@@@6B@`; one outgoing slot to scalar deleting destructor `0x004b5a40`; 31 incoming data references.
- Current IDA UDTs after catalog `0365`:
  - `TreeItorFolderTreePaneTreeElem`, size `12`: `void *vftable` +0, `FolderTreePaneTree *m_tree` +4, `int m_currentIndex` +8.
  - `SimpleUString`, size `4`: `wchar_t *m_data` +0.
  - `StringBaseWide`, size `4`: `wchar_t *m_data` +0.
  - `FolderTreePaneTreeElem`, size `12`: `StringBaseWide name` +0, `rowIndex` +4, `depth` +6, `childrenLoaded` +8, `expanded` +9; implicit tail only, no synthetic member.
  - `FolderTreePaneTreeNode`, size `36`: five links +0..+0x10, payload `data` +0x14 size 0x0c, `disabled` +0x20; implicit tail only, no synthetic member.
  - `FolderTreePaneTreeStorage`, size `12`: typed node pointers `m_begin` +0, `m_end` +4, `m_capacity` +8.
  - `FolderTreePaneTree`, size `16`: preserved `void *vftable` +0 and typed `FolderTreePaneTreeStorage m_storage` +4.
- IDA parser-specific layout note: unannotated U02/U03 analysis declarations initially materialized as `0x0a`/`0x20`. Supervisor stopped before function mutation and redeclared only those analysis UDTs with `struct __declspec(align(4))`, yielding the intended `0x0c`/`0x24` implicit tails. Human-source formals remain ordinary natural-alignment C++.

## Function / Child Inventory

- Post-Gate2B reconciliation: target/A03 UID0002N0 next-visible-sibling/A02 UID0002N1 parent inventory dispositions are unchanged, but their IDA state is now applied and typed; protected caller and compiler-support inventory remain byte/range stable.

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Current Score | Recommended disposition |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004b5b00,0x004b5bae)` | UID0002MY | Concrete reset specialization | true | UID0000F9 | `90/92` | Preserve score/route; correct node/payload formal CPP. |
| `[0x004b5bae,0x004b5bb0)` | ignored padding | Two `CC` bytes | false | aggregate context | ignored | Preserve. |
| `[0x004b5bb0,0x004b5bd0)` | UID0002MZ | Generic first-child member instantiation | true | UID0000FB | `91/93` | Applied exact H definition plus trace-only CPP comment; report-stage cap retained. |
| `[0x004b5bd0,0x004b5c13)` | UID0002N0 | Generic next-visible-sibling member instantiation | true | UID0000FB | `92/94` | Applied exact H definition with generic `disabled` plus trace-only CPP comment. |
| `[0x004b5c13,0x004b5c20)` | ignored padding | Thirteen `CC` bytes | false | aggregate context | ignored | Preserve. |
| `[0x004b5c20,0x004b5c3f)` | UID0002N1 | Generic parent member instantiation | true | UID0000FB | `91/93` | Applied exact H definition plus trace-only CPP comment; report-stage cap retained. |
| Iterator destructor source cause | UID00034F | Virtual destructor/vtable-reset support | true/covered | UID0000FB | `87/91` | Canonical owner preserved; concrete trace routed through UID0000JG at position `150`; declaration-generated. |
| Iterator scalar wrapper | UID00034J | Compiler scalar deleting destructor | false/non-emitting | UID0000FB semantic | current | Preserve no-code handling. |
| Tree complete-object destructor | UID000158 | Inline empty virtual-destructor support | true/covered | UID0000F9 | `92/94` | Canonical owner preserved; concrete trace routed through UID0000JG at position `160`. |
| Tree scalar wrapper | UID00034I | Compiler scalar deleting destructor | true/covered | UID0000F9 | `87/91` | Canonical owner preserved; concrete trace routed through UID0000JG at position `170`. |
| Tree vtable data/type | UID00036K/UID00036J | Declaration-generated compiler artifacts | true/covered | UID0000F9 | `88/93` | Concrete traces route through UID0000JG positions `180`/`190`; no raw vtable source. |
| TreeItor vtable type/data | UID00036L/UID00036M | Declaration-generated compiler artifacts | true/covered | UID0000FB | `86/92` | Concrete traces route through UID0000JG positions `200`/`210`; no raw vtable source. |
| Iterator class | UID0000FB | Generic `TreeItor<T>` declaration | true | UID0004YK | `91/94` | Applied H declaration at position 30 with real CPP/H children. |
| Tree class | UID0000F9 | Generic `Tree<T>` wrapper | true | UID0004YK | `91/93` | Applied H declaration at position 20 after complete storage. |
| Storage class | UID0000FC | Generic `TreeNode<T>`/`TreeStorage<T>` declarations | true | UID0004YK | `90/93` | Applied corrected node/storage H declaration at position 10. |
| Payload struct | UID0001UJ | `FolderTreePane::TreeElem` payload | true | UID00005A | `91/94` | Nested declaration emits once through UID00005A H; support page CPP is trace-only. |
| Template context | UID0001WP | Shared template/header route | true | UID0004YK | `93/94` | Applied forward declarations at position 0 and trace-only CPP provenance. |
| Aggregate | UID000157 | Split/index | false | none | `88/90` | `89/92`; inventory/source-model sync only. |
| FolderTree class declaration | UID00005A | Concrete consumer of `Tree<TreeElem>` | true | UID0000JG | `88/89` | Preserve score/route; move declaration from CPP to H and correct node/payload prose. |
| FolderTree core aggregate | UID000155 | Source-bearing child inventory | true/non-emitting | UID00005A | `88/90` | Preserve score/route/formals; reconcile inventory and item summary. |
| `[0x004b3400,0x004b3645)` | UID000344 | Content-dimension traversal | true | UID0000F9 | `90/91` | Preserve metadata; exact CPP node/payload correction. |
| `[0x004b3650,0x004b3848)` | UID000345 | Paint traversal | true | UID0000F9 | `90/91` | Preserve metadata; exact CPP node-link correction. |
| `[0x004b3850,0x004b3ae2)` | UID000346 | Hit-test traversal | true | UID0000F9 | `89/90` | Preserve metadata; exact CPP node/payload correction. |
| `[0x004b3af0,0x004b3d41)` | UID000347 | Visible-navigation traversal | true | UID0000F9 | `89/90` | Preserve metadata; exact CPP node/payload correction. |
| `[0x004b3d50,0x004b3fa4)` | UID0002MV | Storage insert/grow compiler lowering | true/covered | UID0000FC | `88/91` | Canonical owner preserved; concrete CPP route UID0000JG position `100`. |
| `[0x004b55e0,0x004b564d)` | UID0002MW | Full-node copy compiler support | true/covered | UID0000FC/0001UJ | `88/92` | Preserve stable path/score/marker; correct payload-only attribution. |
| `[0x004b56e0,0x004b575f)` | UID0002MX | Storage destructor compiler lowering | true/covered | UID0000FC | `88/91` | Canonical owner preserved; concrete CPP route UID0000JG position `110`. |
| `[0x004b5810,0x004b59d5)` | UID00034H | Per-node paint helper | true | UID0000JG | `89/90` | Preserve metadata; exact CPP node/payload correction. |
| `[0x004b5c40,0x004b5efc)` | UID00022E | Mixed support split/index | false/ignored | none | `90/91` | Preserve classification; correct child role terminology only. |
| `[0x004b5cc0,0x004b5ce5)` | UID000447 | Full-node range destruction support | true/covered | UID0000FC | `87/91` | Exact accepted CPP trace; concrete route UID0000JG position `120`. |
| `[0x004b5d20,0x004b5ddf)` | UID000449 | Full-node range copy support | true/covered | UID0000FC | `87/91` | Exact accepted CPP trace; concrete route UID0000JG position `130`. |
| `[0x004b5e80,0x004b5ebc)` | UID00044B | Full-node vector free support | true/covered | UID0000FC | `87/91` | Exact accepted CPP trace; concrete route UID0000JG position `140`. |

## Direct Xref / Caller Inventory

- Post-Gate2B reconciliation: xrefs remain exactly one each for A01/A02/A03 and one data xref for protected A04; Gate 2B changed no reference set.

| Address / item | Relationship | Meaning |
| --- | --- | --- |
| `0x004b2cbe` | sole target call | Expanded-node keyboard branch calls `MoveToFirstChild` on persistent selection iterator. |
| `0x004b2cc4` vicinity | post-call selection update | Caller consumes mutated iterator state and does not branch on AL. |
| `0x004b2c92` | sole UID0002N1 call | Same caller uses generic parent traversal. |
| `0x004b23f2` | sole UID0002N0 call | Expansion/insertion path consumes next-visible-sibling iterator state. |
| `0x0061a510` | 31 incoming vtable stores | Concrete iterator construction/lifetime evidence throughout FolderTreePane. |
| `0x0061a510 -> 0x004b5a40` | vtable slot | Compiler scalar deleting destructor; traversal methods are nonvirtual. |
| Target outgoing calls | none | Leaf generic iterator member. |

## Documentation Evidence And IDA Status

- Post-Gate2B reconciliation: 13 affected ordinary pages now state the applied analysis types/method names/comments and preserve IDA-only alignment syntax as tool-specific history; all human formals remain unchanged.

- Historical pre-callback documentation left UID0002MZ H blank, emitted generic declarations in CPP, treated the concrete 36-byte node as the payload, stored bare `T`, and deferred complete LObject/StringBase/EPFTileContext headers. Those premises are preserved as historical assumptions in their affected pages, not current state.
- Current ordinary documentation defines `TreeNode<T>`/`TreeStorage<T>`/`Tree<T>`/`TreeItor<T>` through UID0004YK `Tree.h`, emits the target/UID0002N0 next-visible-sibling/UID0002N1 parent generic bodies in H, defines the 12-byte nested payload once through UID00005A H, and preserves only trace comments in CPP channels that otherwise would become empty markers.
- Current concrete traversal/reset/support pages use `TreeNode<FolderTreePane::TreeElem>` and `.data` consistently. UID000447/000449/00044B match the accepted formal CPP payloads exactly, and UID00034F/000158/00034I/00036K/00036J/00036L/00036M retain semantic class ownership while concrete compiler-artifact traces route through UID0000JG positions 150-210.
- Historical generated commands 18808/18812 document the former malformed topology. Read-only command 19221 showed the intended leading Tree declaration order, FolderTreePane header inclusion, concrete support under FolderTreePane.cpp, and zero placeholder tokens, but also exposed a duplicate late `TreeItor` declaration. UID0000F9 ordinary formal H was corrected under command 19225; historical command19802 first proved the duplicate gone, and dated command `20172` independently preserves that topology while exposing the separate pre-C2MZ-211 missing `AppendChild` declaration. Command20252 now validates that declaration in ordinary UID0000F9.
- Current IDA target and UID0002N1 now carry the accepted source-facing analysis names, exact bool-thiscall types, and regular function comments; UID0002N0 retains its accepted name/type with the corrected generic-node `disabled` comment. A04 remains unchanged.

## Ranked Ownership Analysis

- Post-Gate2B reconciliation: applied analysis names/types strengthen, but do not alter, the existing UID0000FB semantic ownership and UID0004YK shared-header source placement.

### 1. Generic Tree/TreeStorage/TreeItor template header

- Evidence for: two distinct `TreeItor<T>` instantiations; identical iterator layout; identical five-link node prefix; record sizes exactly explained by payload size; generic target accesses no payload-specific state; header-defined templates are normal VC6/VC7-era source.
- Evidence against: original filename/path and exact generic node spelling are inferred rather than symbol-recovered.
- Decision: highest-probability original source owner. The validator registered the page as UID0004YK; no UID was guessed.

### 2. UID0000JG FolderTreePane current route

- Evidence for: all concrete target callers/instantiations are in FolderTreePane, current validator route is valid, and current docs already attach concrete template support there.
- Evidence against: EventDispatcher independently uses the same templates; keeping definitions only in `FolderTreePane.cpp` is not plausible final source.
- Decision: retained only for concrete FolderTree payload/visitor/compiler-artifact output; generic templates now route through registered UID0004YK.

### 3. UID0000FB iterator class

- Evidence for: exact semantic owner for this method and current generated attachment.
- Evidence against: a class page is not a physical source file.
- Decision: retain as target canonical owner and immediate emitter; its own eventual emitter should be the shared header route.

### 4. UID000157 aggregate, standalone generated class `.cpp`, runtime/STL, or no owner

- Evidence for: aggregate contains the address; generated filenames resemble class files.
- Evidence against: aggregate is non-emitting, generated names are documentation artifacts, and the method is project-authored generic template behavior.
- Decision: rejected.

### Historical Gate 1 proposed new file/grouping and applied registration payload

- Historical pre-registration page token: `[TMP:"by-file/Tree.md"]`; it was never used as a UID or metadata value.
- Applied by-file page: [UID:0004YK][Tree](by-file/Tree.md), registered by scoped validator command `000000018916` rather than hand-assigned.
- Applied reconstruction path: `NexusTK/util/`.
- Source product: header-only/shared `Tree.h`; no standalone `Tree.cpp` is justified by current evidence.
- Migration scope: generic `TreeNode<T>`, `TreeStorage<T>`, `Tree<T>`, and `TreeItor<T>` declarations/definitions. Concrete payload declarations remain in consumer headers; concrete `Traverse<Visitor>` specializations remain in consumer sources.
- Literal registration-ready page payload follows. The Markdown quote marker `>` is report framing only; the exact new file is the dequoted text, byte-for-byte, with no UID line added by hand:

> *** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
> *** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
>
> # Tree
>
> ## Status
>
> - Proposed header: `NexusTK/util/Tree.h`.
> - Standalone source: none. Current evidence supports a shared template header, not `Tree.cpp`.
> - Confidence: strong for the shared five-link node prefix, payload/state separation, 12-byte storage header, 12-byte iterator layout, symbol-backed `TreeItor` spelling, and header-defined generic traversal members; medium-high for the inferred `TreeNode`, `data`, `disabled`, and physical `Tree.h` spellings.
> - Primary template coordinator: [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md).
> - Concrete consumers: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) and EventDispatcher-family documentation.
>
> ## File Role
>
> `Tree.h` owns the reusable project tree templates shared by at least `FolderTreePane` and EventDispatcher: `TreeNode<T>`, `TreeStorage<T>`, `Tree<T>`, and the symbol-backed `TreeItor<T>`. It owns generic storage/link/disabled-state mechanics and generic iterator movement. It does not own `FolderTreePane::TreeElem`, filesystem enumeration, painting, hit testing, visible-row policy, or other FolderTree feature behavior.
>
> ## Proposed Contents
>
> | Entity | Documentation owner | Source disposition |
> | --- | --- | --- |
> | `TreeNode<T>` and `TreeStorage<T>` | [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md) | Header declarations plus declaration-generated storage support. |
> | `Tree<T>` | [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md) | Generic `LObject`-derived wrapper, storage, reset declaration, and generic `Traverse<Visitor>` API. |
> | `TreeItor<T>` | [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) | Header declaration and generic movement definitions. |
> | `TreeItor<T>::MoveToFirstChild` | [UID:0002MZ][0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild](by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md) | Generic header-defined member at emitter position 40. |
> | `TreeItor<T>::MoveToNextVisibleSibling` | [UID:0002N0][0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling](by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md) | Generic header-defined member at emitter position 50 using `TreeNode<T>::disabled`. |
> | `TreeItor<T>::MoveToParent` | [UID:0002N1][0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent](by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md) | Generic header-defined member at emitter position 60. |
> | `FolderTreePane::TreeElem` and FolderTree visitors | [UID:00005A][FolderTreePane](by-class/FolderTreePane.md), [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) | Explicitly excluded from generic ownership; declarations/visitor specializations stay in `FolderTreePane.h/.cpp`. |
>
> ## Dependency And Source Topology
>
> - `Tree.h` includes `LObject.h` because `Tree<T>` derives from complete `LObject`.
> - `FolderTreePane.h` includes `../core/ScrollBar.h`, `../../render/EPFTileContext.h`, `../../util/StringBase.h`, and `../../util/Tree.h` before declaring by-value members.
> - `FolderTreePane::TreeElem::name` is the four-byte pointer-backed `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >`, not the separate 24-byte SSO `SimpleUString` class.
> - Generic `Tree<T>` declares only generic storage/reset and `Traverse<Visitor>` surfaces. FolderTree-specific visitor/context types and specializations remain in `FolderTreePane.cpp`.
> - `FolderTreePane::PaintTreeNode` is a private static class member; generic Tree specializations receive friendship only to preserve legal access to the pane's private state.
>
> ## Evidence
>
> - `Tree<EventHandler *>` records are `0x1c`: five 4-byte links, a 4-byte payload, one disabled byte, and alignment.
> - `Tree<FolderTreePane::TreeElem>` records are `0x24`: the same five links, a 12-byte payload, one disabled byte, and alignment.
> - `TreeItor<FolderTreePane::TreeElem>` is exactly 12 bytes and its decorated vtable at `0x0061a510` preserves the `TreeItor` spelling.
> - UID0002MZ, UID0002N0, and UID0002N1 access only generic node links/state and iterator fields; their source definitions therefore belong in the shared header.
> - Current generated FolderTree output is historical lead material and does not prove a FolderTree-only template source file.
>
> ## Registration And Migration
>
> 1. Create exactly `by-file/Tree.md` from this dequoted payload, with no UID line and no metadata route changes elsewhere.
> 2. Run scoped validator registration on only `by-file/Tree.md`; read back the assigned UID from both the inserted page header and validator-owned UID mapping. Abort if those two values differ; never infer a UID from sequence.
> 3. Replace every canonical prose token `[TMP:"by-file/Tree.md"]` with `[UID:<assigned>][Tree](by-file/Tree.md)`, then migrate only UID0001WP/0000FC/0000F9/0000FB and their generic template children to the assigned file owner/emitter. Concrete FolderTree payload and visitor pages remain routed through UID00005A/UID0000JG.
> 4. Apply the complete formal H/CPP payloads in this report, including dependency headers, and update `by-project-structure/proposed-source-tree.md` in one source-topology edit: add `LObject.h`, `StringBase.h`, and `Tree.h` immediately before `LObject.cpp` in `util/`; add `EPFTileContext.h` immediately before `EPFTileContext.cpp` in `render/`; add `FolderTreePane.h` immediately before `FolderTreePane.cpp` in `ui/controls/`; do not add `Tree.cpp`.
> 5. Search all changed ordinary pages and the proposed source tree for the literal `TMP:"by-file/Tree.md"`; the required result is zero. Search metadata for the former UID0000JG generic route and require zero remaining generic-template owner/emitter references while retaining concrete FolderTree routes.
> 6. Validate the new by-file page first, then each changed ordinary page serially in dependency order (`LObject`, `StringBase`, `EPFTileContext`, Tree templates, FolderTree class/type, method/support pages, source tree), and only then perform the supervisor-owned coverage pass.
> 7. Command `19993` records a historical pre-application generated family; command19802 is the exact historical family used by the compile callback. That callback maps every failing FolderTreePane diagnostic to an exact owner correction and proves the repaired topology closes all 35 errors under both tested modes. Eleven support/source claim groups, UID0000JG's source-root contract, and UID0000F9's C2MZ-211 declaration are applied. Dated command20172 is the incomplete pre-C2MZ-211 generated checkpoint; command20252 validates the exact ordinary formal-H repair without generated refresh; command20348 completes the waited generated refresh and places the declaration in Tree.h line `70`. Directly compile/read back the exact command20348 seven-artifact set before lifting the score cap.
>
> ## Historical Assumptions
>
> - Earlier documentation grouped all concrete tree/template code under `FolderTreePane.cpp` and treated the 36-byte node as `FolderTreePane::TreeElem`. That model is superseded by cross-instantiation layout evidence; retain it only as historical reconstruction provenance.

## Source Placement

- Post-Gate2B reconciliation: catalog `0365` changes analysis readability only; no source owner, path, emitter route, or formal channel changes.
- Final inferred and applied ordinary source placement: shared `NexusTK/util/Tree.h` through [UID:0004YK][Tree](by-file/Tree.md) for generic templates.
- Complete target dependencies: `NexusTK/util/LObject.h`, `NexusTK/util/StringBase.h`, and `NexusTK/render/EPFTileContext.h`; their declarations are now in formal H before `Tree.h`/`FolderTreePane.h`. Dated command `20172` completes the pre-C2MZ-211 generated-header readback, and the historical command19802 isolated actual-header harness compiles the UID0002MZ relationship/layouts. The exact UID0000F9 `AppendChild` declaration is applied under command20252 and appears in command20348 Tree.h line `70`; C2MZ-204 now directly preflights the exact seven-artifact set and accepted real consumer closure.
- Historical command-19802 dependency state: `NexusTK/ui/controls/FolderTreePane.h` already used pointer-backed `StringBase`, `EPFTileContext`, and Tree declarations, but the generated ScrollBar/UI route did not yet provide complete `ScrollablePane` dependencies. That was the pre-application source of the former generated-header errors, not a current blocker. The accepted UID0000A2/0000CF/0000NF/0000BU/00004I/0001WS corrections close all 35 mapped errors in the repaired exact-topology harness. Command20172 is the dated pre-`AppendChild`-repair generated checkpoint; command20348 incorporates applied C2MZ-211, and the final direct byte-identical preflight is complete.
- Concrete reset, visitor specializations, and private static paint helper: `NexusTK/ui/controls/FolderTreePane.cpp`.
- Target `MoveToFirstChild`: generic definition in `Tree.h`, represented by UID0002MZ formal H because this binary instantiation proves that source member.
- Current metadata route is applied: UID0001WP/UID0000FC/UID0000F9/UID0000FB route directly through UID0004YK, with zero old UID0000JG generic owner/emitter routes. Concrete FolderTree payload/visitor routes remain UID00005A/UID0000JG. No intermediate guessed-UID state occurred.
- Human source-tree synchronization is applied in exact order: `LObject.h`, `StringBase.h`, and `Tree.h` immediately precede `LObject.cpp` under `util/`; `EPFTileContext.h` immediately precedes `EPFTileContext.cpp` under `render/`; `FolderTreePane.h` immediately precedes retained `FolderTreePane.cpp` under `ui/controls/`; no authored `Tree.cpp` was added. The validator nevertheless materializes a trace-only companion `Tree.cpp` for the registered by-file root; it contains no semantic definition or empty-emitter placeholder.
- Rejected placements: standalone `class_TreeItor_struct_FolderTreePane__TreeElem_.cpp`, raw by-memory helper source file, aggregate-owned source, EventDispatcher-only header, or no-owner/non-emitting state.

## Range / Split / Padding / Reclassification Analysis

- Post-Gate2B reconciliation: exact bytes, function ranges, first items, padding, xrefs, and classification are unchanged after type/name/comment application.
- Target is exactly one IDA function from `0x004b5bb0` through `0x004b5bcf`; exclusive end `0x004b5bd0` is the next function start.
- No alternate entry, chunk, EH landing pad, data island, literal pool, inline table, or target-owned padding exists.
- Two predecessor bytes at `0x004b5bae-0x004b5bb0` are `CC` padding outside the target.
- Successor UID0002N0 begins exactly at target end.
- The source-model split is conceptual/type-level, not an address split: generic node metadata and payload occupy one concrete record.
- Reclassification remains ordinary source-authored/reconstructable template behavior. Compiler-generated, covered-by, comment-only, and no-code dispositions are rejected.

## Negative Evidence Summary

- Post-Gate2B reconciliation: former raw names and absent/sentinel UDT states are historical prestates, not current negatives; no new byte, range, xref, ownership, or source-placement contradiction appeared.
- No data xref, immediate xref, pointer-encoded registration, vtable slot, callback table, alternate entry, or hidden dispatch path points to the target.
- No callees, strings, constants, allocation, exception handling, cleanup, or compiler-delete mechanics occur in the target.
- No source symbol proves `char`, `sub_4B5BB0`, `_DWORD *`, a standalone helper, or explicit specialization syntax.
- No evidence supports `TreeIterator`; decorated RTTI proves `TreeItor`.
- Historical/superseded declaration: the former 36-byte `FolderTreePane::TreeElem` declaration conflated five generic links/state with the 12-byte payload. Current ordinary and formal documentation separates `TreeNode<TreeElem>` from `TreeElem`; this remains negative evidence only against restoring the old conflated model.
- No evidence supports payload-specific `hidden` as the generic cross-specialization field; EventDispatcher gives direct disabled semantics.
- No evidence supports a `.cpp`-local generic template declaration as final source.
- Historical pre-callback search found no registered shared `Tree.h` by-file owner. That absence blocked immediate UID routing but not the source-shape inference; command `18916` has since registered UID0004YK and the ordinary route migration is complete.

## IDA Rename / Type / Comment Recommendations

Post-Gate2B reconciliation: the rows retain their exact historical `905D1AB1...604C1` prestates and accepted actions, and catalog entry `0365` records their application under historical Gate 2B save `412DA7E8...519CD`. The latest bounded read-only type-catalog pass used active MCP database `f608d7c2` and independently re-read U00-U06 by exact type name against saved checkpoint `B7CC899D...8058277`, size `143192751`, saved `2026-07-31T06:21:13.3464834-04:00`. It reconfirmed sizes `0x04/0x04/0x0c/0x24/0x0c/0x10/0x0c` and the exact member layouts itemized below. Fresh `type_inspect` returned the exact bare declarations and members but no declaration/member comments; the active MCP schema exposes no type-comment reader and `get_comments` accepts addresses rather than type names. Accordingly, each current type regular/repeatable channel is recorded literally as `absent`/`absent` from the bare declaration readback, with that API limit stated rather than fabricating an address-comment result. B003 performed only bounded read-only checks and report reconciliation; B003 made no IDA mutation or save. B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, 87D3, A4A6, 6470, 222D, EEF0, 412D, and all earlier snapshots are dated history only.

### Function action A01: target `0x004b5bb0`

- Canonical supervisor action classification: `apply`.
- Actual catalog0365 state: `applied and verified`; current exact name/type/comment are `TreeItorFolderTreePaneTreeElem_MoveToFirstChild`, `bool __thiscall(TreeItorFolderTreePaneTreeElem *this)`, and the accepted regular function comment. Other comment channels remain absent; bytes/hash, sole xref, frame, bounds, and first item are unchanged.
- Entity/range/item: function `[0x004b5bb0,0x004b5bd0)`, size `0x20`; first item `[0x004b5bb0,0x004b5bb3)`, size `3`, `mov eax, [ecx+8]`; 14 instructions, three basic blocks, no callee.
- Historical 905D1AB1-bound name/type prestate: `sub_4B5BB0`; `char __thiscall(_DWORD *this)`; 296E, 3C8F, 0E0A, 03F102, 08D31, E960, 24B033C, and D622 carried the same historical prestate.
- Exact four comment channels at function start: regular `absent`; repeatable `absent`; function regular `absent`; function repeatable `absent`.
- Historical 905D prestate Hex-Rays inventory: parameter `this : _DWORD *` in ECX; local `v1 : int` in EAX; no other parameter or local survived that decompilation. Hex-Rays local-user comments were `absent`. The bounded decompilation at dated checkpoint `4A9360D1` is the typed readback stated below; DAA, DADC, 836A, and 3892 are dated history.
- Full current IDA frame: one named frame entry, `__return_address` offset `+0x04`, size `0x04`, type `_UNKNOWN *`; the assembly temporarily saves ESI with `push esi`/`pop esi`, but IDA exposes no separate saved-register frame member and there are no stack locals or arguments.
- Historical pre-application collision result: lookup of exact proposed name `TreeItorFolderTreePaneTreeElem_MoveToFirstChild` returned `Not found`; the dated `4A9360D1` bounded lookup resolves it uniquely to A01.
- Exact action: rename to `TreeItorFolderTreePaneTreeElem_MoveToFirstChild`; apply `bool __thiscall(TreeItorFolderTreePaneTreeElem *this)`; set function regular comment exactly to `TreeItor<FolderTreePane::TreeElem>::MoveToFirstChild. Reads TreeNode<T>::firstChildIndex, returns false without changing m_currentIndex when the link is -1, otherwise stores the child index and returns true.`; keep address regular, address repeatable, and function repeatable channels `absent`. No user-local rename is required: the historical `v1` becomes the typed `firstChildIndex` expression.
- CF188 actual readback: same function/first-item bounds; exact bytes `8b 41 08 56 8b 71 04 8d 14 c0 8b 46 04 5e 8b 44 90 04 83 f8 ff 75 03 32 c0 c3 89 41 08 b0 01 c3`; exact new name/declaration/function-regular comment; address regular, address repeatable, and function repeatable channels `absent`; sole inbound code xref `0x004b2cbe` in A04; no callee; unique collision lookup. Current Hex-Rays inventory is formal `this : TreeItorFolderTreePaneTreeElem *` in ECX and local `firstChildIndex : int` in EAX; typed expression uses `m_tree`, `m_currentIndex`, and `m_storage.m_begin`. EAX is the result/temp register and ESI is instruction-saved only; there are no stack arguments, locals, or saved-register frame members beyond the return-address entry.
- Safety constraints: apply only after U01-U05 exact readback; abort on name collision or prestate drift; preserve function/first-item bounds, bytes, xrefs, predecessor/successor padding, decorated vtable/data identities, and frame.

### Function action A02: parent `0x004b5c20`

- Canonical supervisor action classification: `apply`.
- Actual catalog0365 state: `applied and verified`; current exact name/type/comment are `TreeItorFolderTreePaneTreeElem_MoveToParent`, `bool __thiscall(TreeItorFolderTreePaneTreeElem *this)`, and the accepted regular function comment. Other comment channels remain absent; bytes/hash, sole xref, frame, bounds, and first item are unchanged.
- Entity/range/item: function `[0x004b5c20,0x004b5c3f)`, size `0x1f`; first item `[0x004b5c20,0x004b5c23)`, size `3`, `mov eax, [ecx+8]`; 14 instructions, three basic blocks, no callee.
- Historical 905D1AB1-bound name/type prestate: `sub_4B5C20`; `char __thiscall(_DWORD *this)`; 296E, 3C8F, 0E0A, 03F102, 08D31, E960, 24B033C, and D622 carried the same historical prestate.
- Exact four comment channels: regular `absent`; repeatable `absent`; function regular `absent`; function repeatable `absent`.
- Historical 905D prestate Hex-Rays inventory: parameter `this : _DWORD *` in ECX; local `v1 : int` in EAX; no other parameter or local survived. Hex-Rays local-user comments were `absent`. The bounded decompilation at dated checkpoint `4A9360D1` is the typed readback stated below; DAA, DADC, 836A, and 3892 are dated history.
- Full current IDA frame: `__return_address` offset `+0x04`, size `0x04`, type `_UNKNOWN *`; ESI is saved only by the instruction pair and is not exposed as a frame member; no stack locals/arguments.
- Historical pre-application collision result: exact proposed name `TreeItorFolderTreePaneTreeElem_MoveToParent` returned `Not found`; the dated `4A9360D1` bounded lookup resolves it uniquely to A02.
- Exact action: rename to `TreeItorFolderTreePaneTreeElem_MoveToParent`; apply `bool __thiscall(TreeItorFolderTreePaneTreeElem *this)`; set function regular comment exactly to `TreeItor<FolderTreePane::TreeElem>::MoveToParent. Reads TreeNode<T>::parentIndex, returns false without changing m_currentIndex when the link is -1, otherwise stores the parent index and returns true.`; keep address regular, address repeatable, and function repeatable channels `absent`; no user-local rename is required.
- CF188 actual readback: unchanged function/first-item bounds; exact bytes `8b 41 08 56 8b 71 04 8d 14 c0 8b 46 04 5e 8b 04 90 83 f8 ff 75 03 32 c0 c3 89 41 08 b0 01 c3`; exact new name/declaration/function-regular comment; address regular, address repeatable, and function repeatable channels `absent`; sole inbound code xref `0x004b2c92` in A04; no callee; unique collision lookup. Current Hex-Rays inventory is formal `this : TreeItorFolderTreePaneTreeElem *` in ECX and local `parentIndex : int` in EAX; typed expression uses `m_storage.m_begin`. EAX is the result/temp register and ESI is instruction-saved only; there are no stack arguments, locals, or saved-register frame members beyond the return-address entry.
- Safety constraints: apply only after U01-U05 exact readback; abort on name collision or prestate drift; preserve function/first-item bounds, bytes, xrefs, padding, and frame.

### Function action A03: next-visible-sibling terminology correction `0x004b5bd0`

- Canonical supervisor action classification: `apply`.
- Actual catalog0365 state: `applied and verified`; current name/type are preserved and the regular function comment now uses generic `TreeNode<T>`/`disabled` terminology. Other comment channels, bytes/hash, sole xref, frame, bounds, and first item are unchanged.
- Entity/range/item: function `[0x004b5bd0,0x004b5c13)`, size `0x43`; first item `[0x004b5bd0,0x004b5bd1)`, size `1`, `push esi`; six basic blocks, no callee.
- Historical 905D1AB1-bound name/type prestate: `TreeItorFolderTreePaneTreeElem_MoveToNextVisibleSibling`; `bool __thiscall(TreeItorFolderTreePaneTreeElem *this)`; 296E, 3C8F, 0E0A, 03F102, 08D31, E960, 24B033C, and D622 carried the same historical prestate.
- Historical 905D prestate four comment channels: regular `absent`; repeatable `absent`; function regular `"TreeItor<FolderTreePane::TreeElem>::MoveToNextVisibleSibling. Assigns each candidate before testing TreeElem.hidden at +0x20, returns true on the first visible sibling, and leaves current index on the last skipped sibling if a hidden chain exhausts."`; function repeatable `absent`. The dated `4A9360D1` bounded readback carries the corrected generic-node comment stated in the actual readback; DAA, DADC, 836A, and 3892 are dated history.
- Complete CF188 Hex-Rays inventory: parameter `this : TreeItorFolderTreePaneTreeElem *` in ECX; locals `m_tree : FolderTreePaneTree *` in EDI, `nextSiblingIndex : int` in EAX, `v4 : int` in ECX, and `m_begin : FolderTreePaneTreeNode *` in EAX. Hex-Rays local-user comments: `absent`.
- Full current IDA frame: one exposed entry, `__return_address` offset `+0x08`, size `0x04`, type `_UNKNOWN *`; ESI and EDI are instruction-saved registers but not separate IDA frame members; no stack locals/arguments.
- Collision result: the exact current/protected name resolves only to intended function `0x004b5bd0`, size `0x43`.
- Exact action: preserve name/type/range and keep regular/repeatable/function-repeatable channels `absent`; replace the stale function regular comment with exactly `TreeItor<FolderTreePane::TreeElem>::MoveToNextVisibleSibling. Assigns each candidate before testing the generic TreeNode<T> disabled flag at node +0x20, returns true on the first enabled sibling, and leaves m_currentIndex on the last skipped sibling when a disabled chain exhausts.` No local rename is requested.
- CF188 actual readback: same name/declaration/range; exact bytes `56 8b f1 57 8b 46 08 8b 7e 04 8d 14 c0 8b 47 04 8b 44 90 10 83 f8 ff 74 20 0f 1f 80 00 00 00 00 89 46 08 8d 0c c0 8b 47 04 80 7c 88 20 00 74 0e 8b 44 88 10 83 f8 ff 75 e7 5f 32 c0 5e c3 5f b0 01 5e c3`; exact replacement function-regular comment and address regular/address repeatable/function repeatable channels `absent`; sole inbound code xref `0x004b23f2` in `sub_4B1D50`; no callee; unique name collision lookup. The typed body resolves `m_tree`, `m_storage.m_begin`, `nextSiblingIndex`, `m_begin`, and `disabled`; ESI/EDI are instruction-saved registers but not frame members.
- Safety constraints: comment-only mutation after U01-U05 exact readback; preserve current name/type, function/first-item bounds, bytes, xrefs, padding, frame, and all existing local names.

### Protected dependency A04: caller `0x004b2b80`

- Canonical supervisor action classification: `no change recommended`.
- Actual catalog0365 state: `verified already present`; no mutation occurred. Name/type, all four start-comment channels, complete frame, internal switch/address comments, xrefs, and bytes match the protected prestate.
- Entity/range/item: function `[0x004b2b80,0x004b2d8c)`, size `0x20c`; first item `[0x004b2b80,0x004b2b81)`, size `1`, `push ebp`; target call at `0x004b2cbe` and parent-sibling call at `0x004b2c92`.
- Historical 905D1AB1-bound and CF188 protected name/declaration: `sub_4B2B80`; `char __thiscall(int this, int)`; 296E, 3C8F, 0E0A, 03F102, 08D31, E960, 24B033C, and D622 carried the same state.
- Exact four function-start comment channels: regular `absent`; repeatable `absent`; function regular `absent`; function repeatable `absent`. Internal switch/address comments (`switch 18 cases`, `switch jump`, jump-table case repeatables, and `StackCookie`) are present and must be preserved.
- Complete current Hex-Rays inventory: parameters `this : int`, `a2 : int`; locals `v3 : char`, `v4 : _DWORD *`, `v6 : _DWORD[3]`, `v7 : void **`, `v8 : int`, `v9 : int`, `v10 : __int16`, `v11 : _DWORD[3]`, `v12 : void **`, `v13 : int`, `v14 : int`, `v15 : __int16`, `v16 : void **`, `v17 : int`, `v18 : int`, `v19 : int`. Hex-Rays local-user comments: `absent`.
- Full current IDA frame, in order: `var_50` +0x0c `_DWORD`; `var_4C` +0x10 `_DWORD`; `var_48` +0x14 `_DWORD`; `var_44` +0x18 `_DWORD`; `var_40` +0x1c `_DWORD`; `var_3C` +0x20 `_DWORD`; `var_38` +0x24 `_WORD`; `var_34` +0x28 `_DWORD`; `var_30` +0x2c `_DWORD`; `var_2C` +0x30 `_DWORD`; `var_28` +0x34 `_DWORD`; `var_24` +0x38 `_DWORD`; `var_20` +0x3c `_DWORD`; `var_1C` +0x40 `_WORD`; `var_18` +0x44 `_DWORD`; `var_14` +0x48 `_DWORD`; `var_10` +0x4c `_DWORD`; `var_C` +0x50 `_DWORD`; `var_4` +0x58 `_DWORD`; `__saved_registers` +0x5c `_DWORD`; `__return_address` +0x60 `_UNKNOWN *`; `arg_0` +0x64 `_DWORD`; `arg_4` +0x68 `_DWORD`.
- Collision result: no proposed name exists for A04, so a rename collision lookup is not applicable; the current name resolves to this exact function only.
- Exact action: no rename, type, function-start comment, local-name, frame, or range action is recommended. Preserve exact caller state, internal comments, xrefs, and bytes. Its broad switch/callback ABI is evidence only and is not a target blocker.
- CF188 actual readback and safety: same name/declaration, function/first-item bounds, exact first 16 bytes `55 8b ec 6a ff 68 77 eb 5f 00 64 a1 00 00 00 00`, full 23-entry frame, complete `this`/`a2` formals and `v3`, `v4`, `v6`-`v19` local inventory, four `absent` function-start comment channels, preserved internal `switch 18 cases`/`switch jump`/jump-table/`StackCookie` and call-site `this` comments, no code caller, one data xref at `0x0061a57c`, target call at `0x004b2cbe`, parent call at `0x004b2c92`, preserved call to `sub_4B1D50`, and unchanged bytes.

### UDT actions in deterministic dependency order

| Order / entity | Historical 905D prestate and collision result | Applied action/declaration | Catalog0365 readback, historical CF188 evidence, and latest B7CC899D bounded no-drift disposition |
| --- | --- | --- | --- |
| U00 `SimpleUString` | Historical 905D prestate: exact size `0x04`, member `wchar_t *m_data` +0; type regular comment `absent`; type repeatable comment `absent`; protected control. | No mutation. Protect this pointer-backed IDA artifact and do not reuse it as the separate 24-byte SSO source class. | Current post-readback: exact size/member unchanged; type regular comment `absent`; type repeatable comment `absent`; classification `already present`. |
| U01 `StringBaseWide` | Historical 905D prestate: type absent and collision-free; type regular comment `absent`; type repeatable comment `absent`. | Created `struct StringBaseWide { wchar_t *m_data; };`. | Current post-readback: exact size `0x04`, one member at +0; type regular comment `absent`; type repeatable comment `absent`; `SimpleUString` unchanged; classification `applied`. |
| U02 `FolderTreePaneTreeElem` | Historical 905D prestate: non-UDT `-1` sentinel artifact with no members; type regular comment `absent`; type repeatable comment `absent`. | IDA declaration `struct __declspec(align(4)) FolderTreePaneTreeElem { StringBaseWide name; short rowIndex; short depth; unsigned char childrenLoaded; unsigned char expanded; };`. The explicit alignment is analysis-tool syntax only; no synthetic member. | Current post-readback: exact size `0x0c`, five members at +0/+4/+6/+8/+9, implicit tail +0x0a..+0x0b; type regular comment `absent`; type repeatable comment `absent`; classification `applied`. |
| U03 `FolderTreePaneTreeNode` | Historical 905D prestate: type absent and collision-free; type regular comment `absent`; type repeatable comment `absent`. | IDA declaration `struct __declspec(align(4)) FolderTreePaneTreeNode { int parentIndex; int firstChildIndex; int lastChildIndex; int previousSiblingIndex; int nextSiblingIndex; FolderTreePaneTreeElem data; unsigned char disabled; };`. Explicit alignment is analysis-tool syntax only; no synthetic member. | Current post-readback: exact size `0x24`, seven members at +0/+4/+8/+0xc/+0x10/+0x14/+0x20, implicit tail +0x21..+0x23; type regular comment `absent`; type repeatable comment `absent`; classification `applied`. |
| U04 `FolderTreePaneTreeStorage` | Historical 905D prestate: type absent and collision-free; type regular comment `absent`; type repeatable comment `absent`. | Created three typed `FolderTreePaneTreeNode *` members `m_begin`, `m_end`, `m_capacity`. | Current post-readback: exact size `0x0c` and offsets +0/+4/+8; type regular comment `absent`; type repeatable comment `absent`; classification `applied`. |
| U05 `FolderTreePaneTree` | Historical 905D prestate: exact size `0x10`, preserved vftable +0, raw 12-byte storage +4; type regular comment `absent`; type repeatable comment `absent`. | Preserved `vftable`; replaced only the raw array with `FolderTreePaneTreeStorage m_storage` +4. | Current post-readback: exact size `0x10`, two members, typed storage, preserved vftable; type regular comment `absent`; type repeatable comment `absent`; classification `applied`. |
| U06 `TreeItorFolderTreePaneTreeElem` | Historical 905D protected prestate: exact size `0x0c`, vftable +0, `m_tree` +4, `m_currentIndex` +8; type regular comment `absent`; type repeatable comment `absent`. | No mutation. | Current post-readback: exact size/members unchanged while resolving through updated U05; type regular comment `absent`; type repeatable comment `absent`; classification `already present`. |

### Applied save/readback record

1. Supervisor Gate 2B followed dependency order U01-U05 with protected controls U00/U06, then applied A01-A03 and preserved A04.
2. Unannotated IDA U02/U03 declarations initially read back at `0x0a`/`0x20`; the supervisor stopped before function mutation and used explicit `__declspec(align(4))` declarations to realize the intended implicit `0x0c`/`0x24` tails without synthetic members.
3. Exact readback passed for all names, types, ranges, first items, frames, four function-comment channels, UDT sizes/members/dependencies, collision uniqueness, bytes, xrefs, padding, vtable/data identities, A04 internal comments, and unrelated protected state. U00 historical/current type regular `absent`, repeatable `absent`; U01 historical/current type regular `absent`, repeatable `absent`; U02 historical/current type regular `absent`, repeatable `absent`; U03 historical/current type regular `absent`, repeatable `absent`; U04 historical/current type regular `absent`, repeatable `absent`; U05 historical/current type regular `absent`, repeatable `absent`; and U06 historical/current type regular `absent`, repeatable `absent`.
4. A01/A02/A03 decompile through `m_tree->m_storage.m_begin` and expose `firstChildIndex`, `parentIndex`, `nextSiblingIndex`, and `disabled`; guessed local names were not required.
5. Byte-identical prestate backup is `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B003-UID0002MZ-20260729-1505.i64`, SHA256 `905D1AB1...604C1`, size `143190814`.
6. `idb_save` returned `ok:true`; catalog entry `0365` and the audit checkpoint record the historical Gate 2B saved IDB SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, size `143191140`, last write `2026-07-29T15:00:32.0998001-04:00`. Latest bounded read-only verification on `f608d7c2` against `B7CC899D...8058277` preserved every target/dependency readback; B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, 87D3, A4A6, 6470, 222D, and EEF0 are dated history.

## First-Draft C++ Recommendation

- Eligibility: yes. Exact behavior and route clear the code gate.
- Source-shape decision: generic template implementation belongs in H; target CPP contains only the exact header-only provenance comment needed to avoid an empty-emitter placeholder. The following blocks are exact accepted insertion/replacement text, not examples.

The complete destination-ready section was re-read against current disk after the D6B81C8 Gate 1 rejection. The 32 child-style destinations below now match their current formal CPP/H bodies byte-for-byte; UID0000NF matches both exact ScrollBar source-root assembly blocks, and UID0000JG matches the exact current ExpandNode source-root assembly block. These identities bind that comparison without treating later concurrent edits as silently equivalent:

| UID | Destination | Current SHA256 | Bytes | Lines | Exact payload readback |
| --- | --- | --- | ---: | ---: | --- |
| 00007D | `by-class/LObject.md` | `0BC9E0D06EA919C11F8A66912A87DC86E797AC8E0BA69C5A00B88811584DD219` | 23138 | 179 | formal CPP/H exact under canonical `NEXUSTK_UTIL_LOBJECT_H` guard |
| 0001WS | `by-type/by-template/StringBaseTemplate.md` | `2E97EDB1812A7F99EA8683C80BD9C6AC7A7F24AA1CAEA322CC8F14B38131346E` | 50210 | 282 | formal CPP/H exact after complete current-H replacement under canonical `NEXUSTK_UTIL_STRINGBASE_H` guard |
| 00004I | `by-class/EPFTileContext.md` | `B41C852E21CF15A7295DCDF03F22790F7B5573D04BCA61F88D0F828356EA90F4` | 25623 | 233 | formal CPP/H exact |
| 0001WP | `by-type/by-template/FolderTreePaneTreeTemplates.md` | `2A96C1AE57C87216B7C48CB32FB58694121CC7EB5D6BC6E13F9750D03410A652` | 41941 | 240 | formal CPP/H exact |
| 0000FC | `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md` | `3812C4B70CC1A57B6F70D828F97858503E1E8241CD5BC6624F99D829FAD13F86` | 25961 | 178 | formal CPP/H exact |
| 0000F9 | `by-class/Tree_struct_FolderTreePane__TreeElem_.md` | `23E93045D1CBFD839C8A47F796F3E756FA6C641F5A233BB919EAFE36D1B6EB6D` | 24888 | 173 | formal CPP/H exact |
| 0000FB | `by-class/TreeItor_struct_FolderTreePane__TreeElem_.md` | `506C90F4AF700447B22939CE64E0072CE30083B91D88402FB8DC9A64E7B3BECE` | 22339 | 203 | formal CPP/H exact |
| 0001UJ | `by-type/by-struct/FolderTreePane__TreeElem.md` | `E1A63E613B12DFB238F8AB63909DB17FBC65FD27AEBBFFB3D21E4536EE0C7411` | 36191 | 227 | formal CPP/H exact |
| 00005A | `by-class/FolderTreePane.md` | `85D41C8E7B8C46AB4B69B591D3D5F9FE6DD8675B9D74AF534DE3DF58EAF47754` | 64289 | 371 | formal CPP/H exact |
| 0002MZ | `by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md` | `EBACBC0B05EF619F748A220CBDD52A61DF17B063E6B7E23FFF93B0B6EAB60200` | 9797 | 108 | formal CPP/H exact |
| 0002N0 | `by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md` | `8622895DF7BFB7D46851DB36C31F22F5DC71FAEF7D5B4F7710EFA93B7BB85172` | 14317 | 135 | formal CPP/H exact |
| 0002N1 | `by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md` | `3DF9DFF782AA1C8A289184CBF57C5079D15361BB3B9197D69B45DC7B3EAF7C82` | 8967 | 106 | formal CPP/H exact |
| 0002MY | `by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md` | `D1C1ED9CEE4F08FBB1D099C3EB082AFE114C756C76B9E708D959BC5CA3218624` | 14811 | 140 | formal CPP/H exact |
| 000344 | `by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md` | `4B232E58684C537AC4A0B3686D13D3B0B68BB94D8D6AFB920237AC686D4F8DC3` | 15031 | 174 | formal CPP/H exact |
| 000345 | `by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md` | `B80DA5D974E8753A1ADEF163B33F7C32E5EDFA2D364E7C7A90F47BDC0602C4A6` | 28083 | 263 | formal CPP/H exact |
| 000346 | `by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md` | `F838713D8ECF0EE53B769E167C40DE2C740EE37769913D0745DBC86BDF750972` | 9338 | 148 | formal CPP/H exact |
| 000347 | `by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md` | `A74C03BF48EDC31305015A7E25C7626CE65190E8F5B4D504B36E866E953BF6FA` | 9329 | 150 | formal CPP/H exact |
| 00034H | `by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md` | `8C282159B2879B2E92E077940AB989B17DE2BA95726A959BE901F8C0C8640046` | 13974 | 155 | formal CPP/H exact |
| 0002MV | `by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md` | `DE1AE433187A86A1E448501BEDD16F21BB80D0692D7BB87F782B07B79D435A09` | 18419 | 114 | formal CPP/H exact |
| 0002MW | `by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md` | `5BB9776F52921DFDDFF2A63CA00CB2BB2A566E5503258A16F04BF4B75D10CCE9` | 14725 | 108 | formal CPP/H exact |
| 0002MX | `by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md` | `A39585CCF0D1C22931FEE83B9D37CB0D385D6FAC11CD1C2D2E74CC1DA7FB4FF1` | 13343 | 100 | formal CPP/H exact |
| 000447 | `by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md` | `30F4ACBA878EE7E02BF01903BEC0701932D670FABD8ADF866739D81928CE4FC8` | 5401 | 65 | formal CPP/H exact |
| 000449 | `by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md` | `A0E9E868B4AEE84AE4C86E1D37D7684954A382ABDD4D8B8C1F00679D10D72400` | 5596 | 65 | formal CPP/H exact |
| 00044B | `by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md` | `ECC963878BD89A4012E38C06CAD0150BF1DD9B09340490D42CD43C794FFA239E` | 5125 | 64 | formal CPP/H exact |
| 0000BU | `by-class/RectBounds.md` | `0D92730DD863B0773E348B029188D8DF5E1EC45C2BD3632CDFA9A3235972BD6F` | 35367 | 203 | formal CPP/H exact after guarded current-H replacement with no invalid H-child attachment token |
| 0000A2 | `by-class/Pane.md` | `E6A7E2074FECAE251DF5599A92C4BFA7D50C3C69E82F44287BCC4894021C91DD` | 30942 | 297 | accepted UID0002MZ Pane ABI checkpoint retained under canonical `NEXUSTK_UI_CORE_PANE_H` guard; semantics remain unchanged and no invalid H-child attachment token remains |
| 0000CF | `by-class/ScrollablePane.md` | `1DF4CDE466DC5FBF482224AD6273B1138F6EE82AF11ED96D9FA9F022AB8E6501` | 23459 | 202 | formal CPP/H exact after current fragment replacement; fragment closes the shared ScrollBar guard without an invalid H-child attachment token |
| 0000NF | `by-file/ScrollBar.md` | `ECAAB87D75DD3CE2D291ACE5F4EF1588EECC458FBAA5BFC30E33D4F39339C281` | 50963 | 276 | exact CPP/header-guard assembly blocks |
| 000156 | `by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md` | `17DDB21E649344806DD57FA1E8A9C179CC0A3D85C8E051873BCE7C2B8C846D8A` | 18363 | 189 | formal CPP/H exact |
| 000343 | `by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md` | `4422291AF0601D5C5F7E552D682628F4AB1B2A45ACF8C4F82EE5D4897D63DBB9` | 16667 | 137 | formal CPP/H exact |
| 0002LN | `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md` | `2C7DF76691A966250BABA28C5A44FF754A1462C5D0C45E602199E779B9B7654A` | 10108 | 127 | formal CPP/H exact |
| 0000JG | `by-file/FolderTreePane.md` | `8BB41392DC14F5FC56412995EE055907828F7FFF05BBAD4BC8AD4A533A19F831` | 74165 | 409 | exact ExpandNode CPP assembly; current H child route preserved |
| 00036L | `by-type/by-vtable/FolderTreePaneTreeItorVtable.md` | `A7CA05B359DEE395CD2E2198CF5F69AB0D0C23E858456E2BE30341A9E850ED25` | 5654 | 69 | formal CPP/H exact |
| 00036M | `by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md` | `35E959F9EC11E98C8C74EA4D0CEFD6FBE7044BBA6B2EE34255921CCCA9260FF6` | 4641 | 67 | formal CPP/H exact |

Destination: `by-class/LObject.md` [UID:00007D]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_LOBJECT_H
#define NEXUSTK_UTIL_LOBJECT_H

typedef unsigned int MessageType;

struct RuntimeClass;
class Message;

class LObject
{
public:
    LObject();
    virtual ~LObject();
    virtual RuntimeClass *GetRuntimeClass();
    virtual void OnChangeMessage(LObject *owner, Message *message);

    void RegisterChangeListener(LObject *listener,
                                MessageType messageType,
                                bool allMessages);
    void UnregisterChangeListener(LObject *listener,
                                  MessageType messageType,
                                  bool allMessages);
    void ForwardMessage(Message *message);
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-type/by-template/StringBaseTemplate.md` [UID:0001WS]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_STRINGBASE_H
#define NEXUSTK_UTIL_STRINGBASE_H

namespace mystr
{
template <class CharT>
struct mychar_traits;

template <class CharT, class Traits = mychar_traits<CharT> >
class StringBase
{
public:
    StringBase();
    StringBase(const CharT *text);
    StringBase(const StringBase& other);
    template <class OtherCharT, class OtherTraits>
    StringBase(const StringBase<OtherCharT, OtherTraits>& other);
    ~StringBase();

    StringBase& operator=(const StringBase& other);
    StringBase& operator=(const CharT *text);

    const CharT *c_str() const;
    unsigned int length() const;
    bool empty() const;
    StringBase& AppendWideLiteral(const wchar_t *source, unsigned int maxCount);
    int CompareWideLiteral(const wchar_t *literal) const;
    int FindLastOf(const wchar_t *chars, unsigned int start, unsigned int charCount) const;
    int FindLastNotOf(const wchar_t *chars, unsigned int start, unsigned int charCount) const;
    StringBase& SubstringWide(StringBase& out, unsigned int start, unsigned int count) const;
    long ToLong() const;
    int FormatWide(const wchar_t *format, ...);
    StringBase& InitializeWideFromRange(const wchar_t *first, const wchar_t *last);
    void append(const CharT *text);
    void insert(int position, const CharT *text);
    void insert(int position, const StringBase& text);
    void DetachWideIfShared();

private:
    CharT *m_data;
};

int WideRangeCompare(const wchar_t *lhsBegin, const wchar_t *lhsEnd,
                     const wchar_t *rhsBegin, const wchar_t *rhsEnd);
}

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-class/EPFTileContext.md` [UID:00004I]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/core/RectBounds.h"

enum EPFTilePixelFormat
{
    kEPFTilePixelFormatRgb16 = 0,
    kEPFTilePixelFormatIndexed8 = 1
};

struct DLPalette;

struct EPFTileContext
{
    EPFTilePixelFormat pixelFormat;
    void *pixelData;
    unsigned short *alphaData;
    int rowStridePixels;
    RectBounds bounds;
    int encodedMaskByteCount;
    unsigned char *encodedMaskBytes;

    void Initialize();
    void ReleaseBuffers();
    void BuildEncodedMask();
    void CopyTo(EPFTileContext *destination) const;
    void AllocateIndexed8Pixels(int width, int height);
    void AllocateRgb16Pixels(int width, int height);
    void AllocateRgb16PixelsWithAlpha(int width, int height);
    void NormalizePostDecodePixels();
    bool ContainsIndexedPixelInRanges(const DLPalette *palette) const;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-type/by-template/FolderTreePaneTreeTemplates.md` [UID:0001WP]

Metadata closure: `EMITTER_POSITION_OPTIONAL:0`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Header-only Tree template declarations and definitions are emitted through
// Tree.h; no out-of-line Tree.cpp implementation belongs to this inventory.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T> struct TreeNode;
template <class T> class TreeStorage;
template <class T> class Tree;
template <class T> class TreeItor;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md` [UID:0000FC]

Metadata closure: `EMITTER_POSITION_OPTIONAL:10`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// TreeNode<T> and TreeStorage<T> are header-only templates emitted through
// Tree.h; concrete FolderTree compiler support is routed to FolderTreePane.cpp.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T>
struct TreeNode
{
    int parentIndex;
    int firstChildIndex;
    int lastChildIndex;
    int previousSiblingIndex;
    int nextSiblingIndex;
    T data;
    unsigned char disabled;
};

template <class T>
class TreeStorage
{
public:
    TreeStorage()
        : m_begin(0),
          m_end(0),
          m_capacity(0)
    {
    }

    ~TreeStorage();

    TreeNode<T> *InsertAt(TreeNode<T> *position,
                          const TreeNode<T>& value);

    TreeNode<T>& operator[](int index) { return m_begin[index]; }
    const TreeNode<T>& operator[](int index) const { return m_begin[index]; }

    TreeNode<T> *m_begin;
    TreeNode<T> *m_end;
    TreeNode<T> *m_capacity;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-class/Tree_struct_FolderTreePane__TreeElem_.md` [UID:0000F9]

Metadata closure: `EMITTER_POSITION_OPTIONAL:20`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Tree<T> is a header-only template emitted through Tree.h; concrete
// FolderTree specializations and compiler support belong to FolderTreePane.cpp.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "LObject.h"

template <class T>
class Tree : public LObject
{
public:
    Tree();
    virtual ~Tree()
    {
    }

    void ResetToSingleRoot();

    template <class Visitor>
    void Traverse(TreeItor<T> *start, Visitor *visitor);

    TreeNode<T>& NodeAt(int index) { return m_storage[index]; }
    const TreeNode<T>& NodeAt(int index) const { return m_storage[index]; }

    TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);

protected:
    TreeStorage<T> m_storage;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-class/TreeItor_struct_FolderTreePane__TreeElem_.md` [UID:0000FB]

Metadata closure: `EMITTER_POSITION_OPTIONAL:30`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// TreeItor<T> is a header-only template emitted through Tree.h.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T>
class TreeItor
{
public:
    TreeItor()
        : m_tree(0),
          m_currentIndex(-1)
    {
    }

    TreeItor(Tree<T> *tree, int currentIndex)
        : m_tree(tree),
          m_currentIndex(currentIndex)
    {
    }

    virtual ~TreeItor()
    {
    }

    bool MoveToFirstChild();
    bool MoveToNextVisibleSibling();
    bool MoveToParent();

    Tree<T> *GetTree() const { return m_tree; }
    int GetIndex() const { return m_currentIndex; }
    void Set(Tree<T> *tree, int currentIndex)
    {
        m_tree = tree;
        m_currentIndex = currentIndex;
    }

private:
    Tree<T> *m_tree;
    int m_currentIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-type/by-struct/FolderTreePane__TreeElem.md` [UID:0001UJ]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FolderTreePane::TreeElem is declared once in FolderTreePane.h by UID00005A;
// this support page intentionally emits no duplicate type definition.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-class/FolderTreePane.md` [UID:00005A]

Metadata closure: `EMITTER_POSITION_OPTIONAL:0`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FolderTreePane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../core/ScrollBar.h"
#include "../../render/EPFTileContext.h"
#include "../../util/StringBase.h"
#include "../../util/Tree.h"

struct FolderTreePaintTraversalContext;

class FolderTreePane : public ScrollablePane
{
public:
    struct TreeElem
    {
        mystr::StringBase<wchar_t,
                          mystr::mychar_traits<wchar_t> > name;
        short rowIndex;
        short depth;
        unsigned char childrenLoaded;
        unsigned char expanded;
    };

    struct DirectoryEntry
    {
        mystr::StringBase<wchar_t,
                          mystr::mychar_traits<wchar_t> > name;
        short rowIndex;
        short depth;
        unsigned char childrenLoaded;
        unsigned char expanded;
    };

    FolderTreePane(const wchar_t *rootName);
    virtual ~FolderTreePane();

    bool ExpandNode(TreeItor<TreeElem> *node);
    bool CollapseNode(TreeItor<TreeElem> *node);
    void RefreshTreeLayout();
    void SetRootNodeName(const wchar_t *rootName);
    void SelectNodeByPath(const wchar_t *path);
    void SetSelection(TreeItor<TreeElem> *selection);

private:
    template <class T> friend class Tree;

    int GetTreeIndentLeft(short depth) const;
    int GetTreeRowTop(short rowIndex) const;
    int GetTextWidth(const wchar_t *text) const;
    void GetNodeBounds(TreeItor<TreeElem> *node,
                       RectBounds *outBounds) const;
    void DrawTreeConnector(int x, int y);
    void DrawTreeExpandGlyph(int x, int y, bool expanded);
    void DrawFolderIcon(int x, int y, bool selected);
    void DrawTreeNodeText(int x, int y,
                          const wchar_t *text, bool selected);

    static int PaintTreeNode(FolderTreePaintTraversalContext *context,
                             TreeItor<TreeElem> *node);

    Tree<TreeElem> m_tree;
    EPFTileContext m_folderIconContext;
    TreeItor<TreeElem> m_selection;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md` [UID:0002MZ]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// TreeItor<T>::MoveToFirstChild is defined inline in Tree.h.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T>
bool TreeItor<T>::MoveToFirstChild()
{
    int childIndex = m_tree->NodeAt(m_currentIndex).firstChildIndex;
    if (childIndex == -1)
        return false;

    m_currentIndex = childIndex;
    return true;
}
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md` [UID:0002N0]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// TreeItor<T>::MoveToNextVisibleSibling is defined inline in Tree.h.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T>
bool TreeItor<T>::MoveToNextVisibleSibling()
{
    int siblingIndex = m_tree->NodeAt(m_currentIndex).nextSiblingIndex;
    while (siblingIndex != -1)
    {
        m_currentIndex = siblingIndex;
        if (!m_tree->NodeAt(siblingIndex).disabled)
            return true;

        siblingIndex = m_tree->NodeAt(siblingIndex).nextSiblingIndex;
    }

    return false;
}
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md` [UID:0002N1]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// TreeItor<T>::MoveToParent is defined inline in Tree.h.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T>
bool TreeItor<T>::MoveToParent()
{
    int parentIndex = m_tree->NodeAt(m_currentIndex).parentIndex;
    if (parentIndex == -1)
        return false;

    m_currentIndex = parentIndex;
    return true;
}
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md` [UID:0002MY]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <new>

template <>
void Tree<FolderTreePane::TreeElem>::ResetToSingleRoot()
{
    typedef mystr::StringBase<wchar_t,
                             mystr::mychar_traits<wchar_t> > FolderTreeName;

    for (TreeNode<FolderTreePane::TreeElem> *node = m_storage.m_begin;
         node != m_storage.m_end;
         ++node)
    {
        node->data.name.~FolderTreeName();
    }

    m_storage.m_end = m_storage.m_begin;

    TreeNode<FolderTreePane::TreeElem> root;
    root.parentIndex = -1;
    root.firstChildIndex = -1;
    root.lastChildIndex = -1;
    root.previousSiblingIndex = -1;
    root.nextSiblingIndex = -1;
    root.data.childrenLoaded = 0;
    root.data.expanded = 0;
    root.disabled = 0;

    if (m_storage.m_end == m_storage.m_capacity)
    {
        m_storage.InsertAt(m_storage.m_end, root);
    }
    else
    {
        new (m_storage.m_end) TreeNode<FolderTreePane::TreeElem>(root);
        ++m_storage.m_end;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md` [UID:000344]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <deque>

struct FolderTreeContentDimensionsContext
{
    FolderTreePane *pane;
    int rowCount;
    int maxWidth;
};

template <>
template <>
void Tree<FolderTreePane::TreeElem>::Traverse<FolderTreeContentDimensionsContext>(
    TreeItor<FolderTreePane::TreeElem> *start,
    FolderTreeContentDimensionsContext *context)
{
    std::deque<int> pending;
    pending.push_back(start->GetIndex());

    while (!pending.empty())
    {
        const int nodeIndex = pending.back();
        pending.pop_back();

        TreeNode<FolderTreePane::TreeElem>& treeNode = m_storage[nodeIndex];
        FolderTreePane::TreeElem& node = treeNode.data;

        int depth = 0;
        for (int parentIndex = treeNode.parentIndex; parentIndex != -1;
             parentIndex = m_storage[parentIndex].parentIndex)
        {
            ++depth;
        }

        node.depth = static_cast<short>(depth);
        node.rowIndex = static_cast<short>(context->rowCount);

        const int rowWidth =
            context->pane->GetTextWidth(node.name.c_str()) + (16 * (depth + 1));
        if (context->maxWidth < rowWidth)
        {
            context->maxWidth = rowWidth;
        }

        ++context->rowCount;

        if (node.expanded && treeNode.lastChildIndex != -1)
        {
            for (int childIndex = treeNode.lastChildIndex; childIndex != -1;
                 childIndex = m_storage[childIndex].previousSiblingIndex)
            {
                pending.push_back(childIndex);
            }
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md` [UID:000345]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct FolderTreePaintTraversalContext;

template <>
template <>
void Tree<FolderTreePane::TreeElem>::Traverse<FolderTreePaintTraversalContext>(
    TreeItor<FolderTreePane::TreeElem> *start,
    FolderTreePaintTraversalContext *context)
{
    const int kStopTraversal = 1;
    const int kSkipChildren = 2;

    std::deque<int> pending;
    pending.push_back(start->GetIndex());

    while (!pending.empty())
    {
        const int nodeIndex = pending.back();
        pending.pop_back();

        TreeItor<FolderTreePane::TreeElem> node(this, nodeIndex);
        const int traversalState =
            FolderTreePane::PaintTreeNode(context, &node);
        if (traversalState == kStopTraversal)
            break;

        if (traversalState == kSkipChildren)
            continue;

        TreeNode<FolderTreePane::TreeElem>& treeNode = m_storage[nodeIndex];
        for (int childIndex = treeNode.lastChildIndex; childIndex != -1;
             childIndex = m_storage[childIndex].previousSiblingIndex)
        {
            pending.push_back(childIndex);
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md` [UID:000346]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct FolderTreeHitTestContext
{
    FolderTreePane *pane;
    int x;
    int y;
    TreeItor<FolderTreePane::TreeElem> result;
};

template <>
template <>
void Tree<FolderTreePane::TreeElem>::Traverse<FolderTreeHitTestContext>(
    TreeItor<FolderTreePane::TreeElem> *start,
    FolderTreeHitTestContext *context)
{
    const int kStopTraversal = 1;
    const int kSkipChildren = 2;

    std::deque<int> pending;
    pending.push_back(start->GetIndex());

    while (!pending.empty())
    {
        const int nodeIndex = pending.back();
        pending.pop_back();

        TreeNode<FolderTreePane::TreeElem>& treeNode = m_storage[nodeIndex];
        FolderTreePane::TreeElem& node = treeNode.data;

        RectBounds bounds;
        bounds.left = context->pane->GetTreeIndentLeft(node.depth);
        bounds.top = context->pane->GetTreeRowTop(node.rowIndex);
        bounds.right = bounds.left + 16 + context->pane->GetTextWidth(node.name.c_str());
        bounds.bottom = bounds.top + 16;

        int traversalState = kSkipChildren;
        if (bounds.ContainsPoint(context->y, context->x))
        {
            context->result.Set(this, nodeIndex);
            traversalState = kStopTraversal;
        }
        else if (node.expanded)
        {
            traversalState = 0;
        }

        if (traversalState == kStopTraversal)
            break;

        if (traversalState == kSkipChildren || treeNode.lastChildIndex == -1)
            continue;

        for (int childIndex = treeNode.lastChildIndex; childIndex != -1;
             childIndex = m_storage[childIndex].previousSiblingIndex)
        {
            pending.push_back(childIndex);
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md` [UID:000347]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct FolderTreeNavigationContext
{
    TreeItor<FolderTreePane::TreeElem> candidate;
    TreeItor<FolderTreePane::TreeElem> target;
    bool returnPrevious;
    bool found;
};

template <>
template <>
void Tree<FolderTreePane::TreeElem>::Traverse<FolderTreeNavigationContext>(
    TreeItor<FolderTreePane::TreeElem> *start,
    FolderTreeNavigationContext *context)
{
    std::deque<int> pending;
    pending.push_back(start->GetIndex());

    bool targetSeen = false;

    while (!pending.empty())
    {
        const int nodeIndex = pending.back();
        pending.pop_back();

        TreeItor<FolderTreePane::TreeElem> current(this, nodeIndex);

        if (context->returnPrevious)
        {
            if (current.GetTree() == context->target.GetTree() &&
                current.GetIndex() == context->target.GetIndex())
            {
                context->found = context->candidate.GetIndex() != -1;
                break;
            }

            context->candidate = current;
        }
        else if (targetSeen)
        {
            context->candidate = current;
            context->found = true;
            break;
        }
        else if (current.GetTree() == context->target.GetTree() &&
                 current.GetIndex() == context->target.GetIndex())
        {
            targetSeen = true;
        }

        TreeNode<FolderTreePane::TreeElem>& treeNode = m_storage[nodeIndex];
        if (!treeNode.data.expanded || treeNode.lastChildIndex == -1)
            continue;

        for (int childIndex = treeNode.lastChildIndex; childIndex != -1;
             childIndex = m_storage[childIndex].previousSiblingIndex)
        {
            pending.push_back(childIndex);
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md` [UID:00034H]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct FolderTreePaintTraversalContext
{
    FolderTreePane *pane;
    int firstVisibleRow;
    int lastVisibleRow;
    TreeItor<FolderTreePane::TreeElem> current;
};

int FolderTreePane::PaintTreeNode(
    FolderTreePaintTraversalContext *context,
    TreeItor<FolderTreePane::TreeElem> *node)
{
    const int kDescendIntoChildren = 0;
    const int kSkipChildren = 2;

    FolderTreePane *pane = context->pane;
    TreeNode<FolderTreePane::TreeElem>& treeNode =
        node->GetTree()->NodeAt(node->GetIndex());
    FolderTreePane::TreeElem& data = treeNode.data;

    const int left = pane->GetTreeIndentLeft(data.depth);
    const int top = pane->GetTreeRowTop(data.rowIndex);

    pane->DrawTreeConnector(left + 8, top + 8);

    if (treeNode.firstChildIndex != -1)
    {
        pane->DrawTreeExpandGlyph(left, top, data.expanded != 0);
    }

    const bool selected =
        pane->m_selection.GetTree() == node->GetTree() &&
        pane->m_selection.GetIndex() == node->GetIndex();

    pane->DrawFolderIcon(left + 16, top, selected);
    pane->DrawTreeNodeText(left + 32, top, data.name.c_str(), selected);

    return data.expanded ? kDescendIntoChildren : kSkipChildren;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md` [UID:0002MV]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted source for TreeStorage<FolderTreePane::TreeElem>::InsertAt is
// covered by the generic TreeStorage<T>/TreeNode<T> declaration tracked through
// [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md); this binary grow-insert body is compiler-lowered full-node
// reallocation, element copy construction, range cleanup, and vector-storage
// release and emits no standalone handwritten body here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md` [UID:0002MW]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted TreeNode<FolderTreePane::TreeElem> copy-constructor support.
// Reconstructed by the generic TreeNode<T> declaration in
// [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md), the payload declaration in
// [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md), and TreeStorage insertion/copy users; no standalone helper body is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md` [UID:0002MX]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted source for TreeStorage<FolderTreePane::TreeElem> destruction is
// covered by the generic TreeStorage<T>/TreeNode<T> declaration tracked through
// [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md); this binary destructor body is compiler-lowered node.data cleanup
// and vector-storage release and emits no standalone handwritten body here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md` [UID:000447]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted TreeNode<FolderTreePane::TreeElem> range-destroy support.
// Reconstructed by [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) through the generic storage/node declaration in [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md); no standalone helper
// body is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md` [UID:000449]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted TreeNode<FolderTreePane::TreeElem> range-copy support.
// Reconstructed by [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) through [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md) and the payload declaration in [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md);
// no standalone helper body is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md` [UID:00044B]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted TreeNode<FolderTreePane::TreeElem> vector-storage free support.
// Reconstructed by [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) through the generic storage/node declaration in [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md); no standalone helper
// body is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

**Compile-diagnostic closure support payloads (applied by accepted callback and serially validated):**

The following are destination-ready formal payloads, not abbreviated examples. Each block preserves current binary-backed behavior and places declarations in H and definitions/assembly in CPP. No skeleton, force-include shim, raw reverse-engineering label, artificial comparator anchor, or warning suppression is accepted.

Destination: `by-class/RectBounds.md` [UID:0000BU]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "RectBounds.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CORE_RECTBOUNDS_H
#define NEXUSTK_UI_CORE_RECTBOUNDS_H

struct Point
{
    int y;
    int x;
};

struct RectBounds
{
    int left;
    int top;
    int right;
    int bottom;

    bool IsEmptyOrInvalid() const;
    bool HasSameSizeAs(const RectBounds *bounds) const;
    bool ContainsPoint(int y, int x) const;
    bool ContainsRect(const RectBounds *bounds) const;
    bool IntersectInto(const RectBounds *bounds, RectBounds *outBounds) const;
    void UnionInto(const RectBounds *bounds, RectBounds *outBounds) const;
    void SetLTRB(int leftValue, int topValue, int rightValue, int bottomValue);
    void Offset(int dx, int dy);
    void Inset(int dx, int dy);
    bool IntersectWith(const RectBounds *bounds);
    RectBounds *UnionWith(const RectBounds *bounds);
    void ClampWithin(int leftLimit, int topLimit,
                     int rightLimit, int bottomLimit);
    RectBounds *InsetByQuarter(RectBounds *outBounds) const;
    RectBounds *OutsetByHalf(RectBounds *outBounds) const;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-class/Pane.md` [UID:0000A2]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Pane.h"
#include "../../input/InputMan.h"
#include "Layer.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CORE_PANE_H
#define NEXUSTK_UI_CORE_PANE_H

#include "../../render/GrafPort.h"
#include "../../util/TimerHandler.h"
#include "EventHandler.h"
#include "RectBounds.h"
#include "Region.h"

class Layer;
class Message;
struct RuntimeClass;

class Pane : public GrafPort, public EventHandler, public TimerHandler
{
public:
    Pane();
    virtual ~Pane();
    virtual RuntimeClass *GetRuntimeClass();
    virtual void OnChangeMessage(LObject *owner, Message *message);
    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void DrawOnTarget(GrafPort *target, const RectBounds *bounds,
                              const RectBounds *clipBounds);
    virtual void Show();
    virtual void Hide();
    virtual Pane *GetParentPane();
    virtual void InvalidateRect(const RectBounds *bounds);
    virtual void GetDescription(int descriptionId, wchar_t *description);
    virtual RectBounds *GetScreenBounds(RectBounds *outBounds) const;
    virtual void SetBounds(const RectBounds *bounds,
                           const RectBounds *previousBounds);
    virtual void AddToLayer(RectBounds *bounds, int order,
                            Pane *previousPane, Layer *layer);
    virtual void InsertInLayer(RectBounds *bounds, int order,
                               Pane *previousPane, Layer *layer);
    virtual void RemoveFromLayer();
    virtual void SetPaneOrder(Pane *referencePane, bool placeAfter);
    virtual void UnregisterEventHandler();
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleSystemOrControlEvent(Event *event);
    virtual bool HandleType19Event(Event *event);
    virtual void GetLocalOffset(Point *offset);
    virtual void GetScreenOffset(Point *offset);
    virtual bool ShouldAcceptEvent() const;
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    void SetMode(unsigned char mode);
    bool IsAttachedToLayer() const;
    void SetFocusRegistration(bool active);

protected:
    Layer *m_layer;
    Point m_origin;
    bool m_visible;
    unsigned char m_mode;
    Pane *m_redrawPeerPane;
    unsigned int m_redrawState;
    bool m_redrawPending;
    Region m_pendingMotionRegion;
    bool m_inMotionPaint;
    Region m_motionRegion;
    unsigned int m_inputRegistrationState;
    bool m_pendingDelete;
    bool m_hasPendingMotionRegion;
    bool m_drawOnTarget;
};

typedef char PaneSizeMustBe248[sizeof(Pane) == 0xf8 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

The Pane base order, 18-slot primary virtual surface, `InvalidateRect` slot `+0x20`, `SetMode` call path, complete secondary EventHandler/tertiary TimerHandler contracts, and exact `0xf8` Pane size are evidence-backed. Rectangle visibility state is inherited from `GrafPort::m_visibleBounds`; the rejected Pane-local `m_bounds` assertion is historical and must not reappear. The exact original spelling of the slot at `+0x3c` remains inferred as `SetPaneOrder`; this is a lexical confidence cap, not permission to leave the destination incomplete or emit a raw slot label.

Destination: `by-class/ScrollablePane.md` [UID:0000CF]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ScrollBar.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ScrollablePane : public Pane
{
public:
    ScrollablePane();
    virtual ~ScrollablePane();

    virtual short GetScrollRange(char axis);
    virtual short GetOverflowCount(char axis);
    virtual short GetPageSize(char axis);
    virtual short GetScrollOffset(char axis, short units);
    virtual Point *GetContentSize(Point *outSize);
    virtual Point *GetScrollDelta(Point *outDelta, char axis,
                                  short oldPosition, short newPosition);

    void SetSkinIndex(unsigned short skinIndex);
    void SetScrollTargetValue(short targetPosition, char axis);
    void SetScrollCurrentValue(short currentPosition, char axis);
    short GetScrollMax(char axis) const;
    short GetScrollPosition(char axis) const;
    void SyncScrollbars();
    void ApplyScrollPosition(char axis, unsigned short oldPosition,
                             unsigned short targetPosition);
    void LayoutScrollbars();

protected:
    ScrollPane *m_horizontalScrollPane;
    ScrollPane *m_verticalScrollPane;
    int m_scrollTarget;
    int m_scrollCurrent;
    int m_scrollFlags;
    RectBounds m_contentRect;
    RectBounds m_scrollContentRect;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-file/ScrollBar.md` [UID:0000NF]

The exact destination-ready assembly payloads for `NexusTK/ui/core/ScrollBar.cpp` and `NexusTK/ui/core/ScrollBar.h` are:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ScrollBar.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CORE_SCROLLBAR_H
#define NEXUSTK_UI_CORE_SCROLLBAR_H

#include "Pane.h"
#include "RectBounds.h"

[[CHILDREN]]

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

The literal `[[No Children Attached]]` is removed. The normal child marker remains so ScrollPane, ScrollWidget, ScrollablePane, and exact by-memory method children assemble through the established file owner.

Destination: `by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md` [UID:000156]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FolderTreePane::SetSelection(TreeItor<TreeElem> *selection)
{
    const unsigned char kVerticalAxis = 0;

    if (selection != &m_selection)
        m_selection = *selection;

    RectBounds selectedBounds;
    GetNodeBounds(&m_selection, &selectedBounds);

    const int scrollTop = GetScrollPosition(kVerticalAxis);
    const int scrollBottom =
        scrollTop + (m_contentRect.bottom - m_contentRect.top);
    const int oldScrollTop = GetScrollPosition(kVerticalAxis);

    if (selectedBounds.top < scrollTop)
    {
        int newScrollTop = oldScrollTop + selectedBounds.top - scrollTop;
        if (newScrollTop < 0)
            newScrollTop = 0;

        ApplyScrollPosition(
            kVerticalAxis,
            static_cast<unsigned short>(oldScrollTop),
            static_cast<unsigned short>(newScrollTop));
    }
    else if (selectedBounds.bottom > scrollBottom)
    {
        int newScrollTop =
            oldScrollTop + selectedBounds.bottom - scrollBottom;
        const int maxScrollTop = GetScrollMax(kVerticalAxis);
        if (newScrollTop > maxScrollTop)
            newScrollTop = maxScrollTop;

        ApplyScrollPosition(
            kVerticalAxis,
            static_cast<unsigned short>(oldScrollTop),
            static_cast<unsigned short>(newScrollTop));
    }

    InvalidateRect(NULL);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md` [UID:000343]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {

static mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
MakeDirectoryEntryCompareName(
    const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >& name)
{
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > key(name);
    key.DetachWideIfShared();
    _wcsupr_s(const_cast<wchar_t *>(key.c_str()), key.length() + 1);
    return key;
}

static bool DirectoryEntryNameLess(const FolderTreePane::DirectoryEntry& lhs,
                                   const FolderTreePane::DirectoryEntry& rhs)
{
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > lhsName =
        MakeDirectoryEntryCompareName(lhs.name);
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > rhsName =
        MakeDirectoryEntryCompareName(rhs.name);

    return mystr::WideRangeCompare(
               lhsName.c_str(), lhsName.c_str() + lhsName.length(),
               rhsName.c_str(), rhsName.c_str() + rhsName.length()) < 0;
}

} // namespace
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md` [UID:0002LN]

The exact destination-ready body remains byte-behavior equivalent to the current child. UID0002LN's direct H channel is intentionally blank; the namespace-level declaration already emits through canonical owner UID0001WS `by-type/by-template/StringBaseTemplate.md` in `StringBase.h`. This child must not duplicate that declaration:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace mystr
{
int WideRangeCompare(const wchar_t *lhsBegin,
                     const wchar_t *lhsEnd,
                     const wchar_t *rhsBegin,
                     const wchar_t *rhsEnd)
{
    const wchar_t *lhs = lhsBegin;
    const wchar_t *rhs = rhsBegin;

    while (lhs != lhsEnd && rhs != rhsEnd)
    {
        if (*lhs != *rhs)
            return *lhs < *rhs ? -1 : 1;
        ++lhs;
        ++rhs;
    }

    const unsigned int lhsLength =
        static_cast<unsigned int>(lhsEnd - lhsBegin);
    const unsigned int rhsLength =
        static_cast<unsigned int>(rhsEnd - rhsBegin);
    if (lhsLength == rhsLength)
        return 0;
    return lhsLength < rhsLength ? -1 : 1;
}
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

UID0000F9 integration note for `by-class/Tree_struct_FolderTreePane__TreeElem_.md`:

The complete destination-ready formal H payload above includes `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);`. The exact spelling is inferred from the inline insertion/link sequence, while its parent/child/sibling semantics are fixed by the binary. Gate 2A proved this declaration absent before callback; C2MZ-211 applied it to the ordinary UID0000F9 H block and command20252 validated the exact poststate with generated refresh disabled.

Destination: `by-file/FolderTreePane.md` [UID:0000JG], assembled `FolderTreePane.cpp`

The selected owner for C4505 is the complete method at `0x004b1d50-0x004b253a`, not a synthetic comparator user. `AppendChild` is the highest-probability source API for the observed inline storage insertion and link repair; its spelling is inferred but its parent/child/sibling effects are exact. `FindClose` remains intentionally absent because the current decompile/callee inventory proves that the original method does not close the search handle.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FolderTreePane.h"

#include <algorithm>
#include <vector>
#include <windows.h>
#include <wchar.h>

bool FolderTreePane::ExpandNode(TreeItor<TreeElem> *node)
{
    typedef mystr::StringBase<char, mystr::mychar_traits<char> > NarrowString;
    typedef mystr::StringBase<wchar_t,
                             mystr::mychar_traits<wchar_t> > WideString;

    TreeNode<TreeElem>& treeNode = m_tree.NodeAt(node->GetIndex());
    if (!treeNode.data.childrenLoaded)
    {
        WideString path(treeNode.data.name);
        TreeItor<TreeElem> parent(*node);
        while (parent.MoveToParent())
        {
            const WideString& component =
                m_tree.NodeAt(parent.GetIndex()).data.name;
            path.insert(0, L"\\");
            path.insert(0, component);
        }

        NarrowString searchPath(path);
        if (searchPath.empty() ||
            searchPath.c_str()[searchPath.length() - 1] != '\\')
        {
            searchPath.append("\\");
        }
        searchPath.append("*.*");

        WIN32_FIND_DATAA findData;
        HANDLE findHandle = FindFirstFileA(searchPath.c_str(), &findData);
        if (findHandle == INVALID_HANDLE_VALUE)
            return false;

        std::vector<DirectoryEntry> entries;
        do
        {
            if ((findData.dwFileAttributes & 0x12) == FILE_ATTRIBUTE_DIRECTORY &&
                findData.cFileName[0] != '.')
            {
                wchar_t wideName[MAX_PATH];
                MultiByteToWideChar(CP_ACP, 0, findData.cFileName, -1,
                                    wideName, MAX_PATH);

                DirectoryEntry entry;
                entry.name = wideName;
                entry.rowIndex = 0;
                entry.depth = 0;
                entry.childrenLoaded = 0;
                entry.expanded = 0;
                entries.push_back(entry);
            }
        } while (FindNextFileA(findHandle, &findData));

        std::sort(entries.begin(), entries.end(), DirectoryEntryNameLess);

        for (std::vector<DirectoryEntry>::const_iterator it = entries.begin();
             it != entries.end(); ++it)
        {
            TreeElem child;
            child.name = it->name;
            child.rowIndex = it->rowIndex;
            child.depth = it->depth;
            child.childrenLoaded = it->childrenLoaded;
            child.expanded = it->expanded;
            m_tree.AppendChild(node, child);
        }

        m_tree.NodeAt(node->GetIndex()).data.childrenLoaded = 1;
    }

    TreeNode<TreeElem>& updatedNode = m_tree.NodeAt(node->GetIndex());
    if (updatedNode.firstChildIndex == -1)
        return false;

    updatedNode.data.expanded = 1;
    RefreshTreeLayout();
    return true;
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

The complete UID0001WS formal H payload above now includes the evidence-used cross-character constructor plus append/insert surface required by this destination-ready owner; there is no separate illustrative supplement to overlook during implementation.

The `ExpandNode` payload preserves the exact directory mask `(attributes & 0x12) == 0x10`, dot-entry exclusion, ANSI enumeration, local 12-byte record build, comparator wrapper source expression, sorted child insertion, `childrenLoaded`/`expanded` transitions, first-child failure, refresh, and the binary's absent `FindClose`. Original API/local spellings remain inference-scored, but no compiler/IDA labels survive into source.

- Closure routing for concrete FolderTree source/compiler artifacts preserves each direct `CANONICAL_OWNER` while changing only CPP destination and deterministic position:

| UID | Destination | Canonical owner preserved | Applied emitter | Position | Formal disposition |
| --- | --- | --- | --- | ---: | --- |
| 0002MY | `by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md` | 0000F9 | 0000JG | 90 | Existing concrete specialization unchanged. |
| 0002MV | `by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md` | 0000FC | 0000JG | 100 | Existing compiler-covered comment unchanged. |
| 0002MX | `by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md` | 0000FC | 0000JG | 110 | Existing compiler-covered comment unchanged. |
| 000447 | `by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md` | 0000FC | 0000JG | 120 | Exact accepted report CPP text above. |
| 000449 | `by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md` | 0000FC | 0000JG | 130 | Exact accepted report CPP text above. |
| 00044B | `by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md` | 0000FC | 0000JG | 140 | Exact accepted report CPP text above. |
| 00034F | `by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md` | 0000FB | 0000JG | 150 | Existing class-covered comment unchanged. |
| 000158 | `by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md` | 0000F9 | 0000JG | 160 | Existing class-covered comment unchanged. |
| 00034I | `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md` | 0000F9 | 0000JG | 170 | Existing compiler-wrapper comment unchanged. |
| 00036K | `by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md` | 0000F9 | 0000JG | 180 | Existing no-raw-vtable comment unchanged. |
| 00036J | `by-type/by-vtable/FolderTreePaneTreeVtable.md` | 0000F9 | 0000JG | 190 | Existing no-raw-vtable comment unchanged. |
| 00036L | `by-type/by-vtable/FolderTreePaneTreeItorVtable.md` | 0000FB | 0000JG | 200 | Exact comment below replaces the empty CPP channel. |
| 00036M | `by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md` | 0000FB | 0000JG | 210 | Exact comment below replaces the empty CPP channel. |

Destination: `by-type/by-vtable/FolderTreePaneTreeItorVtable.md` [UID:00036L]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted TreeItor<FolderTreePane::TreeElem> RTTI/vtable layout.
// Recreated by the TreeItor<T> virtual destructor declaration in Tree.h; no
// raw vtable array or standalone source definition is emitted from this page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

Destination: `by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md` [UID:00036M]

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted TreeItor<FolderTreePane::TreeElem> RTTI/vtable data.
// Recreated by the TreeItor<T> virtual destructor declaration in Tree.h; no
// raw vtable array or standalone source definition is emitted for this range.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

- Exact behavior preservation: target load/compare/store/return ordering is unchanged; sibling methods preserve their documented state behavior; reset retains five `-1` links, payload flag clears, generic disabled clear, and copy/grow branches.
- Human-source rationale: template machinery and generic methods are in H; payload-specific reset/traversal bodies remain concrete CPP specializations; concrete consumers now name `TreeNode<T>` for generic links/state and `.data` for the nested payload; implicit alignment replaces explicit source padding arrays.
- Post-Gate2B reconciliation: catalog `0365` proved that IDA required `struct __declspec(align(4))` only for the U02/U03 analysis declarations to realize their implicit tails. That parser accommodation is intentionally absent from every human-source formal above: ordinary C++ natural alignment yields the same `0x0c` payload and `0x24` node without synthetic padding members or analysis syntax.
- Third-party import: not applicable.

## Final Recommendation

- Target is post-Gate2B and post-ordinary-callback reconciliation stage `91/93` with unchanged owner/emitter/position and exact target H implementation. Supervisor Gate 2A passed the historical `43/43` callback with zero drift; Gate 2B catalog `0365` applied/read back all accepted IDA actions under historical `412DA7E8...19CD`; and the latest `f608d7c2` bounded readback against `B7CC899D...8058277` preserves that state without target/dependency/protected-entity drift. B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, and 3892 are dated history. Eleven compile-support claim groups and UID0000JG C2MZ-124 are applied and serially validated under commands `20053`-`20073`; command20385 additionally validates UID0002LN's exact physical/report formal-CPP reconciliation. Gate 2A historically found the UID0000F9 `AppendChild` declaration missing; focused C2MZ-211 applies and validates it under command20252, and command20348 materializes it in generated Tree.h line `70`. Generated/compile closure claim C2MZ-204 is applied through direct byte-identical command20348 preflight: the raw generated baseline exits `0` with zero errors and identifies one C4505 caused by omitted `ExpandNode`, while the non-suppressed accepted real owner/consumer closure exits `0` with zero warnings and no C4505. Tracker command `20474` is the latest observed dated moving checkpoint after B006 de-execution; command20473, command20472, command20463, command20404, commands20384/20381/20355, and commands `20207`, `20304`, `20306`, `20172`/`20175`, `20170`, `20160`, `20109`, `20104`, `20024`, and `20034` are dated history. The `91/93` cap reflects inferred original lexical spellings and source-path uncertainty rather than lifecycle state; FolderTree manual coverage is applied and validated, and supervisor report disposition is external to this recommendation.
- Generic tree source model becomes `TreeNode<T>` + `TreeStorage<T>` + `Tree<T>` + `TreeItor<T>` in a shared header.
- `FolderTreePane::TreeElem` becomes the exact 12-byte consumer payload; generic node links/state no longer pollute that nested payload declaration.
- Target, UID0002N0, and UID0002N1 generic traversal bodies are applied as H generic definitions; their CPP channels contain only exact header-only provenance comments so the generator cannot emit empty markers.
- UID0002MY remains concrete CPP because it initializes payload-specific state.
- UID00007D, UID0001WS, UID0000BU, UID0000A2, UID0000CF, UID0000NF, and UID00004I provide the complete header dependencies; UID00005A declares exact `TreeElem`, `DirectoryEntry`, and `GetNodeBounds`; UID000343/000346/000156/0002LN/0000JG receive the exact namespaced helper, RectBounds, low-word conversion, declaration-route, and sort-consumer corrections proven by compile diagnostics.
- UID000155, UID0002MV/2MW/2MX, UID00022E, UID000447/449/44B, and the six enumerated DirectoryEntry comparison pages receive bounded source-role terminology/history corrections; their exact binary behavior, stable paths, scores, and marker/no-code dispositions remain unchanged except for the separately recommended aggregate score.
- Shared source registration is complete: validator command `18916` assigned UID0004YK to `by-file/Tree.md`, page-header and mapping readbacks agree, and generic UID0001WP/0000FC/0000F9/0000FB owner/emitter routes now use [UID:0004YK][Tree](by-file/Tree.md). Concrete FolderTree payload and visitor routes remain unchanged.
- IDA A01 target, A02 UID0002N1 parent, A03 UID0002N0 next-visible-sibling, and supporting UDTs now carry the exact Gate 2B actions above; A04 and all unrelated state remain preserved. U02/U03 use IDA-only explicit four-byte alignment to produce natural implicit tails, while source formals remain ordinary natural-alignment C++.
- Historical current assumptions must remain in explicit superseded-history sections with the cross-specialization reason for rejection.
- Historical ordinary callback closure: the earlier 43-destination callback received its accepted report-level prose/formal/metadata/history corrections, Gate 2A independently passed all `43/43` destinations with zero drift, and the 13 post-IDA current-state destinations were then reconciled and revalidated serially with generated refresh disabled. The later twelve-group callback is applied and validator-backed; its independent supervisor verification state is authoritative only from supervisor audit/readback. All B003 leases are released, and zero temporary registration-token residue remains. Header-only generic ownership is preserved while concrete FolderTree/compiler-support traces route through UID0000JG positions 90-210. B003 did not mutate IDA, coverage, generated output, audit/catalog, or lifecycle state.

## Recommended Target Doc Changes

For [UID:0002MZ]:

The following accepted target changes are applied in the ordinary document, independently passed Gate 2A, and were reconciled after supervisor Gate 2B. A01 is no longer proposed: catalog `0365` applied the accepted name/type/comment and the current typed decompile/readback matches it.

- Change score `86/91 -> 91/93`; registration, ordinary implementation, historical Gate 2A, IDA application/readback, post-IDA ordinary reconciliation, post-`19225` generated readback, and bounded compile diagnosis are complete. The `91/93` cap reflects inferred original lexical spellings and final historical source-path uncertainty; manual coverage and repaired all-artifact compilation are complete. Supervisor report disposition is external to the target-doc recommendation.
- Preserve owner `0000FB`, reconstructable true, emitter `0000FB`, position `40`, exact range/title/path.
- Replace formal CPP with the exact header-only trace comment and formal H with the exact generic definition above.
- Add exact bytes/hash, dated MCP/IDB readback checkpoint, ABI, CFG, caller/use, comments, xref and pointer negatives, predecessor/successor boundaries, vtable identity, historical UDT prestates, and actual catalog `0365` readbacks.
- Correct `TreeElem +0x04` wording to `TreeNode<T>::firstChildIndex +0x04`.
- Document generic-node/payload arithmetic and shared-header source placement.
- Add explicit historical section preserving the former 36-byte `TreeElem` and explicit-specialization model and why cross-specialization evidence supersedes it.
- Record the exact historical IDA prestates, accepted actions, actual readbacks, IDA-only U02/U03 alignment declarations, backup identity, and dated saved-IDB checkpoint identity without leaking analysis syntax into formal source.

## Recommended Support Doc Changes

The following destination list is reconciled to the 211-row atomic ledger. The historical 43-destination callback is applied and validated; Gate 2A passed `43/43`, catalog `0365` closed accepted IDA rows, 13 affected destinations were reconciled, and the latest `f608d7c2` bounded readback against `B7CC899D...8058277` retained that state without drift. B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, and 3892 are dated history. The accepted compile callback applied eleven support claim groups plus UID0000JG's atomic C2MZ-124 source-root CPP payload. Gate 2A proved UID0000F9 formal H omitted `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);`; C2MZ-211 now records that focused ordinary callback as applied and validated under command20252, and command20348 generated Tree.h now contains the declaration at line `70`. C2MZ-204 separately tracks only direct compilation/readback of the exact command20348 seven-artifact set. The remaining child-item payloads match the accepted report blocks; UID0000NF/UID0000JG preserve the by-file source-root schema while carrying complete assembled H/CPP contracts; UID0002LN retains a blank direct H because its declaration already emits through UID0001WS. The six additional manual-coverage destinations C2MZ-205..210 are applied and exact-readback-verified with the other 42 operations. Report execution/archive disposition is supervisor-owned and authoritative only from the physical report path, validator-owned status/history metadata, and supervisor readback.

- UID0000BU `RectBounds`: emit the existing 16-byte record and `ContainsPoint(int y, int x) const` through central `ui/core/RectBounds.h`; preserve its existing behavior/layout evidence.
- UID0000A2 `Pane`: merge `InvalidateRect(const RectBounds *)` into the complete Pane H declaration; do not use the temporary skeletal syntax harness as final source.
- UID0000CF `ScrollablePane`: merge exact `GetScrollMax`, `GetScrollPosition`, unsigned-short `ApplyScrollPosition`, and `m_contentRect` declarations into its complete H declaration.
- UID0000NF `ScrollBar`: include complete Pane/RectBounds dependencies and remove the literal generated no-children placeholder; do not add a force-include shim.
- UID0001WS `StringBaseTemplate`: add `DetachWideIfShared()` and namespace-level `WideRangeCompare(...)` declarations to formal H while preserving one-pointer layout.
- UID00004I `EPFTileContext`: include central `RectBounds.h` and remove its duplicate local rectangle record without changing its exact 0x28 layout.
- UID00005A `FolderTreePane`: add exact 12-byte nested `DirectoryEntry` and private `GetNodeBounds(TreeItor<TreeElem> *, RectBounds *) const` to formal H.
- UID000156 `FolderTreePaneSetSelection`: use `RectBounds selectedBounds` and explicit `static_cast<unsigned short>` conversions at both scroll calls.
- UID000343 `FolderTreeDirectoryEntryCompareRaw`: call `mystr::WideRangeCompare` and document the StringBase-header declaration route.
- UID000346 `FolderTreeHitTestTraversal`: use `RectBounds` and `ContainsPoint(context->y, context->x)` exactly.
- UID0002LN `WideRangeCompare`: record its `mystr` namespace and StringBase-header declaration route.
- UID0000JG `FolderTreePane` source: include `<wchar.h>` and emit the evidence-backed high-level expansion/child-load sort expression that consumes `DirectoryEntryNameLess`; reject artificial anchors or warning suppression. This source correction shares the existing C2MZ-124 destination rather than creating a twelfth ledger owner row.

- UID00007D `LObject`:
  - Preserve `90/92` and existing route; move the complete base declaration from CPP to H and leave child definitions in CPP.
  - The exact supervisor-owned class coverage replacement is supplied below; it is not an unchanged-row disposition.
- UID0001WS `StringBaseTemplate`:
  - Preserve `88/91` and existing route; replace the prose-only declaration deferral with the exact four-byte pointer-backed class H declaration required by this consumer while preserving broader API uncertainty and child method evidence.
  - The exact supervisor-owned template coverage replacement is supplied below; it is not an unchanged-row disposition.
- UID00004I `EPFTileContext`:
  - Preserve `88/90` and existing route; move the exact value-type declaration from CPP to H so by-value embedding is legal.
  - The exact supervisor-owned class coverage replacement is supplied below; it is not an unchanged-row disposition.
- UID0001WP `FolderTreePaneTreeTemplates`:
  - Score `89/92 -> 93/94`.
  - H forward declarations emit first at position `0`, including `template <class T> class Tree;` before every `Tree<T>` use; its CPP contains only exact header-only provenance and no dead H marker.
- UID0000FC `TreeStorage_struct_FolderTreePane__TreeElem_`:
  - Score `87/89 -> 90/93`.
  - Correct storage from bare `T` to `TreeNode<T>` and emit the declaration in H at position `10`, after forward declarations and before `Tree<T>`.
  - Preserve all exact begin/end/capacity, insert/grow/destroy, allocation, and helper evidence; historicalize old direct-`T` model.
- UID0000F9 `Tree_struct_FolderTreePane__TreeElem_`:
  - Score `90/93 -> 91/93`.
  - Emit the declaration in H at position `20`, with literal `#include "LObject.h"` inside the destination-ready formal H payload before `class Tree : public LObject`; expose generic `Traverse<Visitor>`/`NodeAt` and inferred `AppendChild` surfaces and correct all "36-byte TreeElem" references to 36-byte `TreeNode<TreeElem>`. `AppendChild` is required by the selected complete `ExpandNode` owner and names the exact observed inline storage/link operation without exposing raw storage.
- UID0000FB `TreeItor_struct_FolderTreePane__TreeElem_`:
  - Score `90/93 -> 91/94`.
  - Emit the declaration in H at position `30`; retain real H method children and CPP trace children, and document the generic methods and exact current IDA UDT.
- UID0001UJ `FolderTreePane__TreeElem`:
  - Score `90/93 -> 91/94`.
  - Keep its own H blank, place only the exact no-duplicate trace comment in CPP, and emit the 12-byte payload exactly once as UID00005A's nested H declaration; preserve old 36-byte model as superseded history.
  - Reframe all link and disabled evidence as surrounding `TreeNode<TreeElem>` layout evidence, while retaining payload name/row/depth/loaded/expanded evidence.
- UID0000JG `FolderTreePane`:
  - Score `91/90 -> 92/93`.
  - Distinguish registered UID0004YK shared generic header ownership from UID0000JG concrete FolderTree payload/visitor/compiler-artifact output.
- UID00005A `by-class/FolderTreePane.md`:
  - Preserve `88/89` and its current owner/emitter route.
  - Keep the exact class declaration in formal H, retain the nested 12-byte `TreeElem` declaration route, place `#include "FolderTreePane.h"` before the CPP child marker at position `0`, and explain that `m_tree` stores generic `TreeNode<TreeElem>` records.
- UID000155 `FolderTreePaneCore`:
  - Preserve `88/90`, owner/emitter, and blank aggregate formals.
  - Correct current inventory/item-summary/current-source prose so payload fields are reached through `TreeNode<TreeElem>::data` and generic links/state remain node-owned; historicalize monolithic-record wording.
- UID000157 aggregate:
  - Score `88/90 -> 89/92`; remain false/non-emitting with blank formals.
  - Correct child inventory and source-model history only.
- UID000344: preserve its current score/route/range and replace its formal CPP with the exact content-dimensions `Tree<FolderTreePane::TreeElem>::Traverse<Context>` specialization above.
- UID000345: preserve its current score/route/range and replace its formal CPP with the exact paint-traversal `Tree<FolderTreePane::TreeElem>::Traverse<Context>` specialization above.
- UID000346: preserve its current score/route/range and replace its formal CPP with the exact hit-test `Tree<FolderTreePane::TreeElem>::Traverse<Context>` specialization above.
- UID000347: preserve its current score/route/range and replace its formal CPP with the exact visible-navigation `Tree<FolderTreePane::TreeElem>::Traverse<Context>` specialization above.
- For each of UID000344/000345/000346/000347, generic links come from `TreeNode<TreeElem>`, payload state comes through `.data`, and no feature-specific traversal name is added to generic `Tree<T>`.
- UID00034H:
  - Preserve `89/90`, file route, and range; replace the non-compiling file-local-helper source shape with the exact private static `FolderTreePane::PaintTreeNode` member while retaining its source-local usage.
  - Replace formal CPP with the exact node/payload-aware paint body above; retain the existing behavior/caller evidence and historicalize direct monolithic-`TreeElem` wording.
- UID0002MV: preserve owner/range/path and correct its marker/prose to 36-byte `TreeNode<FolderTreePane::TreeElem>` insert/grow support; concrete CPP routing is UID0000JG position `100`.
- UID0002MW: preserve metadata/range/stable historical path/title and correct its marker/prose to compiler-emitted full-node copy support; the documentation title must not emit as a source function.
- UID0002MX: preserve owner/range/path and correct its marker/prose to full-node storage destruction with `node.data.name` cleanup; concrete CPP routing is UID0000JG position `110`.
- UID000447: preserve owner/range/path, use the exact accepted compiler-emitted full-node range-destruction CPP payload, and route concrete CPP through UID0000JG position `120`.
- UID000449: preserve owner/range/path, use the exact accepted compiler-emitted full-node range-copy CPP payload, and route concrete CPP through UID0000JG position `130`.
- UID00044B: preserve owner/range/path, use the exact accepted compiler-emitted full-node storage-release CPP payload, and route concrete CPP through UID0000JG position `140`.
- UID00022E:
  - Preserve `90/91`, ignored split/index classification, children, and blank formals.
  - Correct only the `0x24` child descriptions to full-node support and retain the distinct 12-byte DirectoryEntry/shared-string helper descriptions.
- UID000343: preserve metadata/formals/route and apply only the bounded 12-byte DirectoryEntry versus 36-byte `TreeNode<FolderTreePane::TreeElem>` comparison correction.
- UID000348: preserve metadata/formals/route and apply only the bounded 12-byte DirectoryEntry versus 36-byte `TreeNode<FolderTreePane::TreeElem>` comparison correction.
- UID00034B: preserve metadata/formals/route and apply only the bounded 12-byte DirectoryEntry versus 36-byte `TreeNode<FolderTreePane::TreeElem>` comparison correction.
- UID00034C: preserve metadata/formals/route and apply only the bounded 12-byte DirectoryEntry versus 36-byte `TreeNode<FolderTreePane::TreeElem>` comparison correction.
- UID00034E: preserve metadata/formals/route and apply only the bounded 12-byte DirectoryEntry versus 36-byte `TreeNode<FolderTreePane::TreeElem>` comparison correction.
- UID00031B: preserve metadata/formals/route and apply only the bounded 12-byte DirectoryEntry versus 36-byte `TreeNode<FolderTreePane::TreeElem>` comparison correction.
- UID0002MY:
  - Preserve `90/92` and owner; replace exact CPP with corrected node/payload form and route concrete CPP through UID0000JG position `90`.
- UID0002N0:
  - Preserve `92/94`, owner/emitter, position; move definition to H and replace concrete `hidden` with generic `disabled`, preserving hidden as historical concrete semantics.
- UID0002N1:
  - Score `86/91 -> 91/93`; preserve owner/emitter/position; move definition to H and add exact current IDA parity action while retaining the report-stage cap.
- UID00034F: preserve score and canonical owner UID0000FB; route concrete destructor trace through UID0000JG position `150`.
- UID00034J: terminology-only readback; no score, route, or code change.
- UID000158/00034I: preserve canonical Tree ownership and route concrete destructor/deleting-wrapper traces through UID0000JG positions `160`/`170`.
- UID00036K/00036J: preserve canonical Tree ownership and route concrete vtable data/type traces through UID0000JG positions `180`/`190`; no raw vtable source is emitted.
- UID00036L/00036M: preserve canonical TreeItor ownership and route concrete vtable type/data traces through UID0000JG positions `200`/`210`; their exact CPP comments reject raw vtable source emission.
- [UID:0004YK][Tree](by-file/Tree.md): created through scoped validator registration, not hand-assigned; reconstruction path `NexusTK/util/`; header-only source owner. Command `18916` assigned UID0004YK, page-header/mapping readbacks agree, generic route migration is applied, and ordinary zero-residue checks pass. The exact assigned-UID manual coverage insertion is applied and exact-readback-verified under supervisor command `000000020465`.

## Score And Metadata Recommendation

| UID | Historical / pre-callback | Recommended | Owner / emitter / position | Rationale |
| --- | --- | --- | --- | --- |
| 0002MZ | `86/91` | `91/93` | preserve `0000FB / 0000FB / 40` | Exact behavior/source model, historical 43-destination ordinary application/Gate 2A, Gate 2B IDA readback, post-IDA reconciliation, generated-header readback, the later twelve-group ordinary callback, coverage, and compile readback are complete. The residual cap is lexical/source-path uncertainty, not lifecycle state; supervisor report disposition is external to this score rationale. |
| 0000FB | `90/93` | `91/94` | current `0004YK / 0004YK` | Generic iterator declaration/source cause applied below final-audit level. |
| 0001WP | `89/92` | `93/94` | current `0004YK / 0004YK` | Cross-instantiation template model and shared route applied. |
| 0001UJ | `90/93` | `91/94` | preserve `00005A / 00005A` | Exact 12-byte payload separated from generic node and emitted once through the class H block. |
| 0000FC | `87/89` | `90/93` | current `0004YK / 0004YK` | Storage element type/source shape and generated readback corrected; direct Tree header/source and concrete UID0002MZ harness compile, while broader FolderTreePane artifacts remain blocked. |
| 0000F9 | `90/93` | `91/93` | current `0004YK / 0004YK` | Generic-only Tree shell moved to the correct channel/model. |
| 0000JG | `91/90` | `92/93` | FILE | Consumer/source split and header relationship resolved. |
| 0000BU | current `91/90` | preserve `91/90` | preserve `0000N2 / 0000N2` | Move the complete existing 16-byte declaration from CPP to central H and preserve exact behavior children; no score inflation for a channel correction. |
| 0000A2 | current `92/94` | preserve `92/94` | preserve `0000MC / 0000MC` | The complete recovered Pane interface is already emitted in H, including independent C2MZ-111 `InvalidateRect`; the later family-wide ABI repair fixes three-argument `DrawOnTarget`, output-buffer `GetDescription`, two-rectangle `SetBounds`, and four-argument `AddToLayer`/`InsertInLayer`. The unresolved original spelling of one ordering slot remains a bounded confidence cap rather than grounds to restore the stale `90/91` state. |
| 0000CF | current `89/90` | preserve `89/90` | preserve `0000NF / 0000NF` | Emit the complete recovered ScrollablePane virtual/helper/layout surface in H; no independent full-family score raise is claimed. |
| 0000NF | current `91/90` | preserve `91/90` | preserve `FILE`; no direct emitter field | Assemble complete ScrollBar H/CPP dependencies and remove the placeholder without changing file ownership or overstating a bounded topology correction. |
| 000156 | current `90/91` | preserve `90/91` | preserve `0000JG / 0000JG` | Complete source-authored SetSelection body changes `Rect` to `RectBounds` and makes both low-word conversions explicit without changing behavior. |
| 0002LN | current `89/92` | preserve `89/92` | preserve `0000OA / 0000OA` | Exact body remains unchanged; namespace/header placement is made explicit for consumers. |
| 0001WS | current `88/91` | preserve `88/91` | preserve `0000OA / 0000OA` | Complete one-pointer H declaration gains the exact helper and string operations required by current consumers; broader original API ordering remains a confidence cap. |
| 00004I | current `88/90` | preserve `88/90` | preserve `0000J4 / 0000J4` | Include the central rectangle declaration and remove the duplicate local record while preserving the exact `0x28` layout and all existing behavior children. |
| 000157 | `88/90` | `89/92` | preserve NONE/FALSE/blank | Complete corrected split inventory. |
| 0002MY | `90/92` | preserve | preserve current | Behavior already exact; formal source shape corrected. |
| 0002N0 | `92/94` | preserve | preserve `0000FB / 0000FB / 50` | Behavior score already justified; source channel/field model corrected. |
| 0002N1 | `86/91` | `91/93` | preserve `0000FB / 0000FB / 60` | Same exact simple generic member; accepted IDA comment correction, generated readback, direct byte-identical artifact preflight, and manual coverage are applied and validated. The residual cap is inferred original lexical spelling rather than report lifecycle state. |
| 00005A | `88/89` | preserve | preserve current | Class declaration moves to H and node/payload model is corrected without claiming a full class re-audit. |
| 000155 | `88/90` | preserve | preserve current | Aggregate/current-source terminology correction only. |
| 000344 | `90/91` | preserve | preserve current | Exact behavior retained; formal CPP is made type-correct under the node/payload model. |
| 000345 | `90/91` | preserve | preserve current | Exact behavior retained; formal CPP is made node-link aware. |
| 000346 | `89/90` | preserve | preserve current | Exact behavior retained; formal CPP is made type-correct under the node/payload model. |
| 000347 | `89/90` | preserve | preserve current | Exact behavior retained; formal CPP is made type-correct under the node/payload model. |
| 00034H | `89/90` | preserve | preserve current | Exact paint behavior retained; formal CPP separates node links from payload drawing fields. |
| 0002MV | `88/91` | preserve | preserve current | Full-node terminology/marker correction; supervisor command `000000020469` replaced the stale `84%` coverage row with the accepted current `88%` row and exact readback passed. |
| 0002MW | `88/92` | preserve | preserve current | Compiler full-node copy role corrected; no handwritten body or source-level function name invented. |
| 0002MX | `88/91` | preserve | preserve current | Full-node destruction role corrected; exact binary behavior unchanged. |
| 00022E | `90/91` | preserve | preserve NONE/FALSE/blank | Mixed helper inventory terminology correction only. |
| 000447 | `87/91` | preserve | preserve current | Full-node range-destruction role corrected. |
| 000449 | `87/91` | preserve | preserve current | Full-node range-copy role corrected. |
| 00044B | `87/91` | preserve | preserve current | Full-node allocation/free role corrected. |

- No recommendation reaches final-audit quality merely because a best inference was selected, ordinary documentation was applied, Gate 2B analysis state now uses the accepted names/types, or the target-specific harness compiles. Exact original source spellings and final historical source-path choices remain inferred, which independently caps the score; manual coverage and successful repaired all-artifact compilation are complete. Supervisor report review/execution/archive disposition is authoritative outside this score rationale.
- Score-improvement attempt and callback result: the target's prior `86/91` caps were the unresolved node-versus-payload layout, generic-versus-explicit template body, header route, inferred member names, raw target IDA state, and stale support topology. Research tested both concrete instantiations, exact size arithmetic, vtable spelling, every iterator sibling, all directly dependent formal bodies, current/manual/generated routes, and live IDA types/comments. The ordinary callback applied the resolved node/payload/header/formal/source-topology actions and preserved historical premises. The target therefore stands at report-stage `91/93`; central type/template/file scores moved only where the same evidence directly closed their current research blockers and all remain at or below `94` confidence. Dependent function/compiler-support/DirectoryEntry pages retain scores because their already-documented binary behavior and confidence did not change; the bounded correction prevents a type contradiction but is not represented as a full independent re-audit of each page.
- UID000343/000348/00034B/00034C/00034E/00031B keep their exact current scores (`90/91`, `88/91`, `90/91`, `88/91`, `88/92`, and `86/90`) and all current metadata; only the bounded `TreeElem`-versus-`TreeNode<TreeElem>` comparison wording changes.
- `RECONSTRUCTABLE`, ownership, emitter, nested, and range classifications remain unchanged. The shared-header by-file route [UID:0004YK] is already registered, applied, and validated; the current generic owner/emitter routes through [UID:0004YK] remain in force.

## Open Questions With Attempted Resolution

- Exact original generic node type spelling:
  - Evidence checked: current/historical docs, generated names, RTTI, both specializations, UDT catalog, source-era naming.
  - Resolution: use `TreeNode<T>` as the highest-probability human source name. `TreeNodeData` remains a generated historical alias; raw/generated names are rejected.
- Exact payload member spelling:
  - Evidence checked: consumer semantics and generic template conventions.
  - Resolution: use `data`. It is inferred, not symbol-proven, but materially more plausible than payload-specific aliases or raw offsets.
- Exact generic state spelling:
  - Evidence checked: EventDispatcher `isDisabled`, FolderTree nonzero skip semantics, copy/init paths, current `hidden` history.
  - Resolution: use `disabled`; retain `hidden` as concrete semantic history.
- Exact physical header path:
  - Evidence checked: project source tree, current by-file routes, two consumer modules, no scored shared owner.
  - Resolution: reconstruct shared `NexusTK/util/Tree.h`. Registration command `18916` assigned UID0004YK; the page-header/mapping readbacks agree, metadata migration is applied, the source-tree insertion is applied, dependency-order validators passed, and ordinary zero-residue checks pass. The pre-registration token/procedure remains below only as historical Gate 1 evidence.
- Header/source topology and complete by-value dependencies:
  - Evidence checked: current formals and generated output for UID00007D, UID0001WS, UID00004I, UID00005A, the proposed source tree, and C++ completeness/one-definition rules.
  - Resolution: `LObject`, pointer-backed `mystr::StringBase`, central `RectBounds`, `Pane`, `ScrollablePane`, `ScrollBar`, and `EPFTileContext` emit complete declarations through their owning headers; `Tree.h` includes `LObject.h`; `FolderTreePane.h` includes those owners and declares its exact nested payload/entry/helper surfaces. The repaired topology closes all 35 former errors. Dated command20172 materializes the incomplete pre-C2MZ-211 set and proved the only ordinary callback omission was UID0000F9's exact `AppendChild` declaration. C2MZ-124 is applied for UID0000JG; C2MZ-211 is applied and validated under command20252; command20348 materializes it in generated Tree.h line `70`; C2MZ-204 is applied through byte-identical direct compilation and the accepted real non-suppressed owner closure. Manual coverage is complete and no unanswered source-shape or compile blocker remains. Supervisor review and lifecycle disposition are external controls recorded by supervisor/validator state, not open research questions.
- Pointer-backed string identity:
  - Evidence checked: exact 12-byte payload size, IDA's one-pointer string artifact, preserved `mystr::StringBase<...>` compiler type name, and separate 24-byte SSO `SimpleUString` documentation.
  - Resolution: use `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >` as the payload member and supply the complete one-pointer class H surface required by this translation unit. SSO `SimpleUString` is rejected for this member; broader StringBase overload ordering remains a project API audit and caps the support score without leaving this consumer incomplete.
- Explicit specialization versus generic member:
  - Evidence checked: target uses only generic node links; two template instantiations; no explicit-specialization symbol/declaration evidence; C++ template source practice.
  - Resolution: generic H definition accepted. Concrete explicit CPP specialization is superseded.
- Generic API versus FolderTree-specific traversal placement:
  - Evidence checked: all four concrete traversal bodies, their consumer-only contexts, and lack of cross-feature evidence for four named generic methods.
  - Resolution: reusable `Tree<T>` declares only `template<class Visitor> Traverse(...)`, storage/reset, and node access. UID000344/345/346/347 are concrete member-template specializations in `FolderTreePane.cpp`; FolderTree context names never enter the generic header.
- Direct indexing versus accessor:
  - Evidence checked: exact begin-pointer indexing and current `TreeStorage<T>::operator[]` model.
  - Resolution: `Tree<T>::NodeAt(int)` is the minimal inline generic accessor used by `TreeItor<T>` and the paint member; concrete `Tree<T>` member bodies continue to use protected `m_storage[index]`. This avoids unproven public storage and compiles to the exact indexed load; raw pointer arithmetic is rejected.
- Private `m_selection` access and paint helper ownership:
  - Evidence checked: the paint helper's exact pane receiver/state use and C++ private-access rules.
  - Resolution: define `FolderTreePane::PaintTreeNode` as a private static member and friend `Tree<T>` so the concrete paint traversal specialization may call it. No file-local helper reaches private state.
- Exact IDA action closure:
  - Evidence checked: latest bounded session `f608d7c2` against saved checkpoint `B7CC899D...8058277`, target/A02-parent/A03-next-visible-sibling/caller bounds and first items, literal function/address comment channels, typed-decompile formals/locals/registers, bytes, xrefs, collisions, U00-U06 layouts and comment-channel limitations, method fences, protected vtable/data identities, catalog `0365`, and the matching audit record. `905D1AB1...604C1` is the exact historical prestate/backup identity; B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, 87D3, A4A6, 6470, 222D, EEF0, 412D, and every earlier identity are dated history only.
  - Resolution: A01-A03 and U01-U05 were applied and read back; A04 and U00/U06 were independently verified protected controls. The original unannotated U02/U03 IDA-declaration assumption is historical: IDA required `__declspec(align(4))` on those analysis UDTs to realize the intended implicit tails, without synthetic members. Human source remains natural-alignment C++.
- Existing helper page names containing `FolderTreeElem`:
  - Evidence checked: helper bodies, absence of recovered source-level helper symbols, current UID/path link graph, compiler-emitted covered-by dispositions, and the corrected full-node role.
  - Resolution: retain the stable UID/path/title as historical documentation identifiers during this callback, explicitly state that they describe compiler-generated `TreeNode<FolderTreePane::TreeElem>` support, and never emit those page names as source functions. A path rename would create link churn without recovering an original source name and therefore is not justified by the binary.
- Compile diagnostic closure:
  - Evidence checked: exact command-20024 generated hashes/topology, historical command-19802 direct `/Za` failures, all 35 error lines and codes, owner documentation, IDA-backed method type at 0x0055eae0, exact FolderTree helper bodies, existing StringBase definitions, repaired header/source topology under `/Za` and `/std:c++14 /permissive-`, the residual C4505 warning, historical full decompile of complete owner `0x004b1d50-0x004b253a`, and the latest `f608d7c2`/`B7CC899D...8058277` direct sort-wrapper xref readback `0x004b214e -> 0x004b5280`.
  - Resolution: every error has an exact owner correction. Eleven support claim groups, atomic UID0000JG claim C2MZ-124, atomic UID0000F9 claim C2MZ-211, and UID0004YK generated/compile claim C2MZ-204 are applied; command20252 validates the exact `AppendChild` declaration in ordinary formal H and command20348 materializes it in generated Tree.h line `70`. The byte-identical raw generated baseline exits `0` with zero errors and exactly one owner-specific C4505; the accepted real `FolderTreePane::ExpandNode(TreeItor<TreeElem> *)` closure containing `std::sort(entries.begin(), entries.end(), DirectoryEntryNameLess)`, sorted child insertion, flags, first-child failure, and layout refresh exits `0` with zero warnings/no C4505. The exact `AppendChild` spelling is high-probability inference for the observed inline insertion/link operation; its semantics are binary-fixed. No diagnostic is left as "needs investigation," no broad dependency excuse remains, and no fake shim/suppression is accepted.
- No research question is merely deferred with needs-investigation shorthand. UID0004YK registration, the historical 43-destination ordinary application/Gate 2A, catalog0365 IDA application/readback, the latest `f608d7c2`/`B7CC899D...8058277` bounded no-drift verification, command `20172` pre-repair generated/memory readback, command `20175` tracker readback, full command-19802 compile-diagnostic investigation, eleven fully applied compile-support claim groups, UID0000JG's source-root application, and C2MZ-211 are complete. C2MZ-211 is validated by command `000000020252`, exit `0`, `ok: 1`, with generated refresh skipped. B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, command20109, command20104, commands20024/20034/19993/19995/19928, and 4EDEC are dated history. Post-repair actual-artifact compilation and all FolderTree coverage operations are complete; no research work is outstanding. Supervisor gate/lifecycle state is authoritative only from supervisor audit/readback and validator-owned status/history metadata.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B003 must not edit coverage files. Ordinary implementation, independent historical Gate 2A, catalog `0365` IDA application/readback, B003's post-IDA ordinary reconciliation, the focused UID0000F9 formal-H callback, and the supervisor-owned manual coverage transaction are complete. Final filesystem reconciliation after supervisor commands `000000020464`-`000000020469` records these current physical identities: `by-memory/-coverage-report.md` SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`, `2134111` bytes, `4803` lines; `by-global/-coverage-report.md` SHA256 `D54B0FBFC043E7822860CB9828896C898BA65EC66B32854CE7F9D191FA066CA1`, `100876` bytes, `218` lines; `by-class/-coverage-report.md` SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`, `274987` bytes, `625` lines; `by-file/-coverage-report.md` SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66`, `166582` bytes, `319` lines; `by-type/-coverage-report.md` SHA256 `8FBB3D1070B8B9C531ACB600D5A80FE4407B2DF8984D11BCFD5E6FD2361995FF`, `5246` bytes, `34` lines; `by-type/by-vtable/-coverage-report.md` SHA256 `5E96D33B2AFEADDB05F9605A4AC0EAC60E30000433D04FFB1E2BBCA0067921D3`, `67631` bytes, `146` lines; `by-type/by-struct/-coverage-report.md` SHA256 `4D576B5F0F6DE62841F0588BCA9BB710AAF023F6A2C5D68E8C423A10FFF0F7C5`, `59348` bytes, `137` lines; and `by-type/by-template/-coverage-report.md` SHA256 `1A62AD2DD4F3C6F7BF94CF3BFC2AA3181B0F95601CD9062426402934FC2A1AA9`, `4721` bytes, `30` lines. Exact literal comparison yields `48` applied and `0` proposed operations: all `34` replacements and all `14` insertions appear exactly once, with no partial or duplicate FolderTree row. Commands20365-20372 and their DDB43AB5/34287BEF/F203FD4C/A5567B78/34B952A2/30D7251B identities are dated transaction prestates; by-global and top-level by-type have no FolderTree operation and remain unchanged. The literal payload blocks below are retained losslessly as transaction specifications; any embedded pre-closure `pending` phrase is historical operation-time wording and does not reopen an applied claim.

Current applied-row inventory: by-class rows are UID00004I line `187`, UID00005A `215`, UID00007D `289`, UID0000A2 `386`, UID0000BU `450`, UID0000CF `471`, UID0000F9 `572`, UID0000FB `574`, and UID0000FC `575`. By-file rows are UID0000JG line `97`, UID0000NF `241`, and inserted UID0004YK `295`, exactly after UID0000OW line `294` and before UID0000OX line `296`. By-memory replacement rows are UID000155 `1461`, UID000156 `1462`, UID000157 `1466`, UID000344 `1468`, UID000345 `1469`, UID0002MV `1472`, UID0002MW `1477`, UID000158 `1479`, UID00034F `1480`, UID0002MX `1481`, UID00034H `1483`, UID00034I `1484`, UID0002MY `1486`, UID0002MZ `1488`, UID0002N0 `1489`, UID0002N1 `1491`, UID00022E `1493`, and UID0002LN `3584`. Applied by-memory insertions are UID000343 `1467`; UID000346/000347 `1470`/`1471`; UID000348/00034B/00034C/00034E `1473`/`1474`/`1475`/`1476`; UID00031B `1482`; UID000447/000449/00044B `1495`/`1498`/`1501` beneath UID00022E while preserving padding rows; and UID00036K/00036M `4246`/`4247` beneath UID00025C line `4244`, after UID0003BF line `4245` and before the ignored successor line `4248`. Additional applied rows are UID0001UJ at by-struct line `51`, UID0001WP/UID0001WS at by-template lines `18`/`22`, and UID00036L/UID00036J at by-vtable lines `59`/`60`. This inventory accounts for all `34` replacements and `14` insertions exactly once; every former insertion anchor now contains its accepted literal, and unrelated concurrent rows remain untouched.

Applied by supervisor command `000000020464` and exact-readback-verified under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`: `by-class/-coverage-report.md`, the accepted operation replaced the exact then-current UID0000BU, UID0000A2, and UID0000CF rows at their title-sorted positions.

```text
- [UID:0000BU][RectBounds](by-class/RectBounds.md) : reconstructable : 91% : very-strong : Exact 16-byte four-int RectBounds value type emitted centrally through `NexusTK/ui/core/RectBounds.h`, with the complete member declaration, y-before-x `ContainsPoint` contract, rectangle mutation/query children, file-local anchor helpers kept outside the class, no vtable/constructor invention, and source-folder spelling retained as inference rather than raw reverse-engineering syntax.
- [UID:0000A2][Pane](by-class/Pane.md) : reconstructable : 92% : very-strong : Base UI Pane emitted as a complete header declaration with exact 18-slot primary virtual surface through +0x44 OnPaint, `InvalidateRect(const RectBounds *)` at +0x20, three-argument `DrawOnTarget`, output-buffer `GetDescription`, two-rectangle `SetBounds`, four-argument `AddToLayer`/`InsertInLayer`, secondary EventHandler and tertiary TimerHandler contracts, Layer/deferred-deletion integration, bounds/origin/mode state, source-ready children, and compiler exclusions; PanelPane separately introduces pure +0x48 `OnActivate`, while the inferred source spelling of Pane's +0x3c ordering operation remains a confidence cap.
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) : reconstructable : 89% : very-strong : Complete ScrollablePane header surface over Pane with exact six virtual scroll-metric/delta contracts, selected-child `GetScrollMax`/`GetScrollPosition`, old-before-target `ApplyScrollPosition`, horizontal/vertical ScrollPane pointers, +0x100/+0x104/+0x108 integer state, RectBounds content/layout state, derived-family evidence, and compiler/vtable exclusions.
```

Applied by supervisor command `000000020465` and exact-readback-verified under SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66`: `by-file/-coverage-report.md`, the accepted operation replaced the exact then-current UID0000NF row at its title-sorted position.

```text
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md) : reconstructable : 91% : very-strong : Generic ScrollPane/ScrollWidget/ScrollablePane source family assembled through complete `ScrollBar.h` and `ScrollBar.cpp` child markers with Pane/RectBounds dependencies, exact class/method/layout/constant/compiler routes, no literal empty-child placeholder, and historical CScrollBarBackPane placement rejected by its exclusive NewOptionPane volume-control ownership.
```

Applied by supervisor command `000000020469` and exact-readback-verified under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`: `by-memory/-coverage-report.md`, the accepted operation replaced the exact then-current UID000156 and UID0002LN rows in address order.

```text
        - [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md) 0x004b3210-0x004b32c9 | method | FolderTreePaneSetSelection : reconstructable : 90% : very strong : Source-ready FolderTreePane::SetSelection with three ordinary callers, exact iterator copy, RectBounds node bounds, inherited content-rectangle visibility test, two GetScrollPosition reads, GetScrollMax clamp, explicit unsigned-short old/target ApplyScrollPosition ABI, and final InvalidateRect(NULL).
        - [UID:0002LN][0x005840f0-0x0058415a.WideRangeCompare](by-memory/0x005840f0-0x0058415a.WideRangeCompare.md) 0x005840f0-0x0058415a | function | WideRangeCompare : reconstructable : 89% : very strong : Source-ready `mystr::WideRangeCompare` half-open UTF-16 lexicographic comparator with exact 29-caller route, word loop, signed comparison result, length tie-break, namespace-level declaration in StringBase.h, and no unqualified external-helper invention.
```

Applied by supervisor command `000000020464` and exact-readback-verified under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`: `by-class/-coverage-report.md`, the accepted operation replaced materially changed UID00007D and UID00004I in place at their then-current title-sorted positions.

```text
- [UID:00007D][LObject](by-class/LObject.md) : reconstructable : 90% : very-strong : Source-ready LObject runtime/base declaration emitted through `NexusTK/util/LObject.h`, with exact constructor and ordinary-destructor definitions retained through LObject.cpp children, compiler deleting support non-emitting, runtime-class/message behavior preserved, and a complete base available before shared `Tree<T> : public LObject` template declaration.
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) : reconstructable : 88% : very-strong : Exact 0x28 decoded tile-context value type emitted through `NexusTK/render/EPFTileContext.h`, with complete pixel-format, buffer, bounds, mask, lifecycle, allocation, copy, normalization, and palette-query declaration before FolderTreePane embeds it by value; implementation children remain routed through EPFTileContext.cpp.
```

Applied by supervisor command `000000020466` and exact-readback-verified under SHA256 `1A62AD2DD4F3C6F7BF94CF3BFC2AA3181B0F95601CD9062426402934FC2A1AA9`: `by-type/by-template/-coverage-report.md`, the accepted operation replaced materially changed UID0001WS in place.

```text
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) : reconstructable : 88% : very strong : Pointer-backed `mystr::StringBase<CharT, Traits>` declaration emitted through `NexusTK/util/StringBase.h` with exact one-pointer instance layout required by FolderTreePane::TreeElem, preserved refcount/length/capacity buffer evidence and method children, explicit separation from the 24-byte SSO SimpleUString family, and broader original API/header spelling uncertainty retained as a score cap.
```

Registration command `18916` assigned UID0004YK and both authoritative readbacks agree. The following is the exact supervisor-owned `by-file/-coverage-report.md` insertion; no unresolved placeholder remains:

```text
- [UID:0004YK][Tree](by-file/Tree.md) : reconstructable : 88% : very-strong : Shared header-only `NexusTK/util/Tree.h` source owner for project `TreeNode<T>`, `TreeStorage<T>`, `Tree<T>`, and symbol-backed `TreeItor<T>` templates, with exact five-link/payload/disabled node model, generic iterator movement, FolderTree/EventDispatcher cross-instantiation proof, declaration-generated support exclusions, and concrete payload/visitor behavior retained in consumer headers and sources.
```

Applied registration and completed supervisor coverage procedure:

1. Completed: B003 created `by-file/Tree.md` without hand-assigning a UID; scoped validator command `18916` assigned UID0004YK.
2. Completed: the page header and validator-owned mapping both read `0004YK`; generic owner/emitter routes migrated only for UID0001WP/0000FC/0000F9/0000FB.
3. Completed: all 43 ordinary callback destinations and the proposed source tree contain zero temporary registration-token residue, and the former UID0000JG generic owner/emitter routes are absent while concrete FolderTree routes remain.
4. Completed: supervisor command `000000020465` inserted the complete UID0004YK row above in `by-file/-coverage-report.md` at line `295`, immediately after UID0000OW line `294` and before UID0000OX line `296`, while preserving unrelated concurrent rows.
5. Completed: command `000000020465` validated `by-file/-coverage-report.md` with generated refresh skipped; exact filesystem readback under SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66` confirms the row once and no duplicate or placeholder residue.

Applied by supervisor command `000000020469` and exact-readback-verified under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`: `by-memory/-coverage-report.md`, the accepted operation replaced UID000157 row in place.

```text
    - [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md) 0x004b3350-0x004b5c3f | aggregate | FolderTreePaneTreeAndSortHelpers : not reconstructable : 89% : very strong : Non-emitting split/index for exact FolderTreePane tree/sort children; the shared TreeNode/TreeStorage/Tree/TreeItor source model separates the 12-byte FolderTreePane::TreeElem payload from generic links/disabled state, and all exact children plus internal/successor padding remain explicitly routed or ignored.
```

Applied by supervisor command `000000020469` and exact-readback-verified under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`: `by-memory/-coverage-report.md`, the accepted operation replaced UID000155, UID000344, UID000345, UID0002MV, UID0002MW, UID0002MX, UID00034H, and UID0002MY in place; the accepted operation inserted the then-absent UID000343/000346/000347/000348/00034B/00034C/00034E/00031B rows in exact address order under the FolderTree family through UID0002MY.

```text
    - [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md) 0x004b1b90-0x004b32c9 | aggregate | FolderTreePaneCore : reconstructable : 88% : very strong : Source-bearing non-emitting FolderTreePane core inventory with concrete Tree<TreeElem> consumption, 36-byte TreeNode<TreeElem> storage, 12-byte payload access through node.data, exact child routing, and current iterator/navigation behavior preserved.
        - [UID:000343][0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess](by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md) 0x004b3350-0x004b33fc | comparator | FolderTreeDirectoryEntryNameLess : reconstructable : 90% : very strong : FolderTreePane DirectoryEntry name comparator with exact 12-byte scratch-record behavior; any width comparison now distinguishes DirectoryEntry from 36-byte TreeNode<FolderTreePane::TreeElem> storage rather than a 36-byte payload.
        - [UID:000344][0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal](by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md) 0x004b3400-0x004b3645 | template traversal | FolderTreeContentDimensionsTraversal : reconstructable : 90% : very strong : Source-ready concrete content-dimension traversal with generic parent/last-child/previous-sibling links on TreeNode<TreeElem>, row/depth/name/expanded access through node.data, deque-backed traversal, and exact width/row accumulation.
        - [UID:000345][0x004b3650-0x004b3848.FolderTreePaintTraversalCallback](by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md) 0x004b3650-0x004b3848 | template traversal | FolderTreePaintTraversalCallback : reconstructable : 90% : very strong : Source-ready concrete paint traversal with deque-backed pending nodes, stop/skip states, generic TreeNode<TreeElem> last-child/previous-sibling descent, and iterator handoff to the payload-aware paint helper.
        - [UID:000346][0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal](by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md) 0x004b3850-0x004b3ae2 | template traversal | FolderTreeHitTestTraversal : reconstructable : 89% : very strong : Source-ready concrete hit-test traversal with payload row/depth/name/expanded reads through node.data, generic last-child/previous-sibling links, exact result-iterator update, and preserved stop/skip behavior.
        - [UID:000347][0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch](by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md) 0x004b3af0-0x004b3d41 | template traversal | FolderTreeVisibleNavigationSearch : reconstructable : 89% : very strong : Source-ready visible-navigation traversal with exact candidate/target iterator state, payload expanded access through node.data, generic last-child/previous-sibling descent, and previous/next selection behavior.
        - [UID:0002MV][0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt](by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md) 0x004b3d50-0x004b3fa4 | template method | FolderTreeStorageInsertAt : reconstructable : 88% : very strong : Exact compiler-lowered insert/grow support for 36-byte TreeNode<FolderTreePane::TreeElem> records in TreeStorage<TreeElem>, including 1.5x growth, aligned allocation/free validation, full-node relocation, old-name cleanup, and source routing through the generic storage declaration.
        - [UID:000348][0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt](by-memory/0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md) 0x004b3fb0-0x004b4232 | vector helper | FolderTreeDirectoryEntryVectorInsertAt : reconstructable : 88% : very strong : FolderTreePane 12-byte DirectoryEntry vector insertion/growth support, explicitly distinct from 36-byte TreeNode<FolderTreePane::TreeElem> storage while preserving exact allocation, relocation, and cleanup behavior.
        - [UID:00034B][0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore](by-memory/0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md) 0x004b4520-0x004b4fc5 | sort helper | FolderTreeDirectoryEntryUnguardedPartition : reconstructable : 90% : very strong : FolderTreePane DirectoryEntry unguarded-partition/sort core over exact 12-byte records; comparison prose now distinguishes these records from 36-byte TreeNode<FolderTreePane::TreeElem> storage without changing sort behavior.
        - [UID:00034C][0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap](by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md) 0x004b4fd0-0x004b5271 | heap helper | FolderTreeDirectoryEntryAdjustHeap : reconstructable : 88% : very strong : FolderTreePane DirectoryEntry heap-adjust support over exact 12-byte records, with only the comparison against 36-byte TreeNode<FolderTreePane::TreeElem> storage terminology corrected.
        - [UID:00034E][0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap](by-memory/0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md) 0x004b5510-0x004b55d3 | swap helper | FolderTreeDirectoryEntrySwap : reconstructable : 88% : very strong : Exact 12-byte FolderTreePane DirectoryEntry swap support, source-routed through sorting code and explicitly distinguished from 36-byte TreeNode<FolderTreePane::TreeElem> records.
        - [UID:0002MW][0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct](by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md) 0x004b55e0-0x004b564d | helper | FolderTreeElemCopyConstruct : reconstructable : 88% : very strong : Compiler-emitted full TreeNode<FolderTreePane::TreeElem> copy-construction support with five generic links, 12-byte payload copy including pointer-backed mystr::StringBase ownership, trailing disabled state, exact 36-byte stride, and no standalone human source body; the stable legacy page title is documentation-only.
        - [UID:0002MX][0x004b56e0-0x004b575f.FolderTreeStorageDestructor](by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md) 0x004b56e0-0x004b575f | template destructor | FolderTreeStorageDestructor : reconstructable : 88% : very strong : TreeStorage<TreeElem> compiler-lowered destructor over 36-byte TreeNode<TreeElem> records with node.data.name cleanup at concrete +0x14, validated free, pointer zeroing, and exact constructor/EH/tree/scalar-wrapper caller categories.
        - [UID:00031B][0x004b57e0-0x004b57e8.FolderTreeDirectoryEntryNameCleanupThunk](by-memory/0x004b57e0-0x004b57e8.FolderTreeDirectoryEntryNameCleanupThunk.md) 0x004b57e0-0x004b57e8 | compiler thunk | FolderTreeDirectoryEntryNameCleanupThunk : not reconstructable : 86% : very strong : Non-emitting compiler EH cleanup thunk adjusting to complete TreeNode<FolderTreePane::TreeElem> offset +0x14 to destroy node.data.name; separate 12-byte DirectoryEntry scratch records retain name at +0x00, and the stable legacy title is documentation-only.
        - [UID:00034H][0x004b5810-0x004b59d5.FolderTreePaintNodeHelper](by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md) 0x004b5810-0x004b59d5 | private static member helper | FolderTreePaintNodeHelper : reconstructable : 89% : very strong : Private static FolderTreePane::PaintTreeNode source member with exact caller/return-state route, legal private selection access, payload drawing fields through node.data, generic first-child linkage on TreeNode<TreeElem>, and preserved connector/glyph/icon/text behavior.
        - [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) 0x004b5b00-0x004b5bae | template method | FolderTreeResetToSingleRoot : reconstructable : 90% : very strong : Source-ready concrete reset specialization over TreeNode<FolderTreePane::TreeElem> with old node.data.name cleanup, storage rewind, five -1 generic links, payload childrenLoaded/expanded clears, generic disabled clear, deliberately uninitialized row/depth/alignment bytes, and exact copy/grow paths.
```

Historical post-command20372 read-only preflight against dated by-memory SHA `DDB43AB5...EAFAE2` found this then-stale UID0002MY row at line `1478`; command20469 has since replaced it with the accepted literal at current line `1486`:

```text
        - [UID:0002MY][0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot](by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md) 0x004b5b00-0x004b5bae | template method | FolderTreeResetToSingleRoot : reconstructable : 90% : very strong : Source-ready concrete reset specialization with exact callers, storage rewind, five -1 links, zeroed childrenLoaded/expanded/hidden state, deliberately uninitialized row/depth/reserved bytes, copy/grow branches, and temporary-name cleanup.
```

Disposition: supervisor command `000000020469` applied the required replacement and exact-readback-verified it at current line `1486`. Current ordinary UID0002MY is `90/92` and its formal CPP/current reconciliation explicitly operates on `TreeNode<FolderTreePane::TreeElem>`, destroys `node.data.name`, writes five generic links, clears payload `childrenLoaded`/`expanded`, clears generic `disabled`, and preserves untouched row/depth/alignment bytes. The dated pre-command20469 row ambiguously presented `hidden` as part of the older flat record model; it remains above only as historical prestate. The physical current row is the accepted literal beginning `Source-ready concrete reset specialization over TreeNode<FolderTreePane::TreeElem>`, exactly once after UID00034H and before UID0002MZ.

Applied by supervisor command `000000020469` and exact-readback-verified under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`: `by-memory/-coverage-report.md`, the accepted operation replaced UID0002MZ row in place between UID0002MY and UID0002N0.

```text
        - [UID:0002MZ][0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild](by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md) 0x004b5bb0-0x004b5bd0 | template method | FolderTreeIteratorMoveToFirstChild : reconstructable : 91% : very strong : Exact 32-byte generic TreeItor<T>::MoveToFirstChild instantiation at position 40 with sole OnKeyEvent caller, bool/sentinel/current-index behavior, symbol-backed TreeItor spelling, generic TreeNode<T> firstChildIndex at +0x04, separated 12-byte FolderTreePane::TreeElem payload, header-defined formal source, and exact applied IDA rename/type/comment/UDT state; ordinary application, UID0004YK registration, Gate 2B, and generated readback are complete, while manual coverage, compile, and fresh gates remain pending.
```

Applied by supervisor command `000000020469` and exact-readback-verified under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`: `by-memory/-coverage-report.md`, the accepted operation replaced UID0002N0 row in place.

```text
        - [UID:0002N0][0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling](by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md) 0x004b5bd0-0x004b5c13 | template method | FolderTreeIteratorMoveToNextVisibleSibling : reconstructable : 92% : very strong : Exact generic TreeItor<T> next-visible-sibling instantiation at position 50 with 67-byte hash, sole expansion caller, candidate-before-test and terminal state, TreeNode<T> nextSiblingIndex, generic disabled-state semantics, separated payload model, header-defined source, and preserved applied IDA state.
```

Applied by supervisor command `000000020469` and exact-readback-verified under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`: `by-memory/-coverage-report.md`, the accepted operation replaced UID0002N1 row in place.

```text
        - [UID:0002N1][0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent](by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md) 0x004b5c20-0x004b5c3f | template method | FolderTreeIteratorMoveToParent : reconstructable : 91% : very strong : Exact 31-byte generic TreeItor<T>::MoveToParent instantiation at position 60 with sole OnKeyEvent caller, bool/sentinel/current-index behavior, TreeNode<T> parentIndex at +0x00, header-defined formal source, and catalog0365-applied IDA name/bool-thiscall/comment state preserved by the latest f608d7c2/B7CC899D...8058277 bounded readback; score remains capped below final lifecycle quality.
```

Applied by supervisor command `000000020469` and exact-readback-verified under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`: `by-memory/-coverage-report.md`, the accepted operation replaced UID00022E in place and insert then-absent UID000447/000449/00044B beneath it in exact child-address order among the existing `0x004b5c40-0x004b5efc` children.

```text
    - [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md) 0x004b5c40-0x004b5efc | split helper inventory | FolderTreePaneVectorSupportHelpers : ignored : 90% : very-strong : Non-emitting seven-function split/index separating FolderTreePane DirectoryEntry and shared 12-byte string-leading helpers from 36-byte TreeNode<FolderTreePane::TreeElem> range-destroy/copy/free support; exact child pages retain their source-bearing or compiler-support dispositions, and this mixed parent keeps blank owner/emitter/formals.
        - [UID:000447][0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy](by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md) 0x004b5cc0-0x004b5ce5 | compiler helper | FolderTreeElemRangeDestroy : reconstructable : 87% : very strong : Compiler-emitted range destruction for 36-byte TreeNode<FolderTreePane::TreeElem> records, destroying node.data.name at concrete +0x14 and source-routed through TreeStorage insertion/relocation with no standalone handwritten body; the stable legacy title is documentation-only.
        - [UID:000449][0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct](by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md) 0x004b5d20-0x004b5ddf | compiler helper | FolderTreeElemRangeCopyConstruct : reconstructable : 87% : very strong : Compiler-emitted range copy for full 36-byte TreeNode<FolderTreePane::TreeElem> records, preserving five links, payload fields, disabled state, and pointer-backed mystr::StringBase ownership through TreeStorage relocation with no standalone human body.
        - [UID:00044B][0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree](by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md) 0x004b5e80-0x004b5ebc | compiler helper | FolderTreeElemVectorStorageFree : reconstructable : 87% : very strong : Compiler-emitted vector-storage release for 36-byte TreeNode<FolderTreePane::TreeElem> allocation, including MSVC large-allocation validation and source routing through TreeStorage without a standalone handwritten body.
```

Applied by supervisor command `000000020469` and exact-readback-verified under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`: `by-memory/-coverage-report.md`, the accepted operation replaced UID000158/00034F/00034I at their existing address-ordered locations; the accepted operation inserted then-absent UID00036K and UID00036M beneath UID00025C before the then-current `0x0061a5c4-0x0061a5dc` ignored row.

```text
        - [UID:000158][0x004b5650-0x004b5669.FolderTreePaneTreeDestructor](by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md) 0x004b5650-0x004b5669 | compiler destructor support | FolderTreePaneTreeDestructor : reconstructable : 92% : very strong : Retained complete-object destructor for Tree<FolderTreePane::TreeElem> with exact range/hash, constructor-unwind liveness, vtable/storage/LObject teardown, and inline empty-destructor source cause; canonical Tree ownership remains UID0000F9 while concrete generated trace routing is UID0000JG position 160.
        - [UID:00034F][0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor](by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md) 0x004b5670-0x004b5677 | compiler destructor support | FolderTreeIteratorVtableResetDestructor : reconstructable : 87% : very strong : One-store TreeItor vtable-reset destructor support covered by UID0000FB's header virtual-destructor declaration; canonical iterator ownership is preserved while concrete generated trace routing is UID0000JG position 150 with no handwritten teardown body.
        - [UID:00034I][0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor](by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md) 0x004b59f0-0x004b5a38 | compiler deleting wrapper | FolderTreeScalarDeletingDestructor : reconstructable : 87% : very strong : Compiler-emitted scalar deleting wrapper for Tree<FolderTreePane::TreeElem>, distinct from ordinary destructor UID000158 and regenerated from UID0000F9 virtual-destructor/TreeStorage semantics; concrete generated trace routing is UID0000JG position 170.
        - [UID:00036K][0x0061a4fc-0x0061a50c.FolderTreeVtableData](by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md) 0x0061a4fc-0x0061a50c | compiler vtable data | FolderTreeVtableData : reconstructable : 88% : very strong : Exact Tree<FolderTreePane::TreeElem> RTTI locator and three-slot vtable data generated from UID0000F9 header declarations; no raw array is emitted, and the concrete compiler-artifact trace routes through UID0000JG position 180.
        - [UID:00036M][0x0061a50c-0x0061a514.FolderTreeIteratorVtableData](by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md) 0x0061a50c-0x0061a514 | compiler vtable data | FolderTreeIteratorVtableData : reconstructable : 86% : very strong : Exact TreeItor<FolderTreePane::TreeElem> RTTI locator and one-slot vtable data regenerated from UID0000FB's header virtual-destructor declaration; no raw array is emitted, and concrete trace routing is UID0000JG position 210.
```

Applied by supervisor command `000000020468` and exact-readback-verified under SHA256 `5E96D33B2AFEADDB05F9605A4AC0EAC60E30000433D04FFB1E2BBCA0067921D3`: `by-type/by-vtable/-coverage-report.md`, the accepted operation replaced UID00036J and UID00036L at their then-current title-sorted positions.

```text
- [UID:00036J][FolderTreePaneTreeVtable](by-type/by-vtable/FolderTreePaneTreeVtable.md) : reconstructable : 88% : very-strong : Exact Tree<FolderTreePane::TreeElem> three-slot vtable owned by UID0000F9's header declaration, with corrected X:/RTTI boundary, scalar deleting slot, five vtable-store xrefs, and no raw-array source; the concrete compiler-artifact trace routes through FolderTreePane UID0000JG position 190.
- [UID:00036L][FolderTreePaneTreeItorVtable](by-type/by-vtable/FolderTreePaneTreeItorVtable.md) : reconstructable : 86% : very-strong : Exact TreeItor<FolderTreePane::TreeElem> one-slot vtable owned by UID0000FB's header declaration, with RTTI locator, scalar deleting slot, broad local iterator vtable stores, and no raw-array source; the concrete compiler-artifact trace routes through FolderTreePane UID0000JG position 200.
```

Applied by supervisor command `000000020464` and exact-readback-verified under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`: `by-class/-coverage-report.md`, the accepted operation replaced UID00005A/0000F9/0000FB/0000FC rows at their then-current sorted positions.

```text
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) : reconstructable : 88% : strong : Filesystem tree control whose header declaration embeds Tree<FolderTreePane::TreeElem> at +0x130; the 12-byte nested payload is stored inside generic 36-byte TreeNode<TreeElem> records, while constructor EH states and UID000158 ordinary Tree destruction preserve automatic member cleanup without handwritten ABI teardown.
- [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md) : reconstructable : 91% : very strong : Generic Tree<T> wrapper with exact vtable/layout/method children, protected TreeStorage<T> node storage, generic Traverse<Visitor>/NodeAt header APIs, and inline empty virtual destructor source cause for ordinary cleanup, member/base destruction, EH cleanup, and scalar-wrapper regeneration.
- [UID:0000FB][TreeItor_struct_FolderTreePane__TreeElem_](by-class/TreeItor_struct_FolderTreePane__TreeElem_.md) : reconstructable : 91% : very strong : Generic TreeItor<T> header declaration with symbol-backed spelling, exact 12-byte vptr/tree/current-index layout, declaration-generated destructor support, and source-ready first-child/next-visible-sibling/parent definitions at positions 40/50/60 over Tree<T>::NodeAt and generic TreeNode<T> links/state.
- [UID:0000FC][TreeStorage_struct_FolderTreePane__TreeElem_](by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md) : reconstructable : 90% : very strong : Generic TreeNode<T>/TreeStorage<T> header support with exact begin/end/capacity layout, 36-byte FolderTree concrete nodes, 28-byte EventDispatcher sibling nodes, payload/link/disabled separation, pointer-backed StringBase ownership, and declaration-generated insert/relocation/destruction support.
```

Applied by supervisor command `000000020466` and exact-readback-verified under SHA256 `1A62AD2DD4F3C6F7BF94CF3BFC2AA3181B0F95601CD9062426402934FC2A1AA9`: `by-type/by-template/-coverage-report.md`, the accepted operation replaced UID0001WP row.

```text
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md) : reconstructable : 93% : very strong : Shared header-defined TreeNode/TreeStorage/Tree/TreeItor template model proven by FolderTreePane and EventDispatcher instantiations, with generic link/payload/disabled layout, exact iterator ordering and source children, declaration-generated destructor/vtable support, and canonical owner/emitter route through registered UID0004YK Tree.h.
```

Applied by supervisor command `000000020467` and exact-readback-verified under SHA256 `4D576B5F0F6DE62841F0588BCA9BB710AAF023F6A2C5D68E8C423A10FFF0F7C5`: `by-type/by-struct/-coverage-report.md`, the accepted operation replaced UID0001UJ row.

```text
- [UID:0001UJ][FolderTreePane__TreeElem](by-type/by-struct/FolderTreePane__TreeElem.md) : reconstructable : 91% : very strong : Exact 12-byte FolderTreePane::TreeElem payload emitted once inside FolderTreePane.h with four-byte pointer-backed mystr::StringBase name, row/depth, childrenLoaded, expanded, and implicit alignment; surrounding generic TreeNode<TreeElem> owns the five link indices and trailing disabled state that produce the exact 36-byte concrete node.
```

Applied by supervisor command `000000020465` and exact-readback-verified under SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66`: `by-file/-coverage-report.md`, the accepted operation replaced UID0000JG row.

```text
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) : reconstructable : 92% : very strong : FolderTreePane source family with exact 12-byte TreeElem payload, concrete 36-byte TreeNode<TreeElem> storage, shared header-defined Tree/TreeStorage/TreeItor support, source-ready iterator order and payload-specific methods, and compiler EH/scalar/vtable glue regenerated from human declarations rather than handwritten reverse-engineered wrappers.
```

- No tracker row should be hand-edited if validator generation owns it. Latest observed dated moving tracker command `000000020474`, refreshed `2026-07-31T10:13:05-04:00`, source `deferred-generated-refresh`, SHA256 `DA13617295274A581850C344E6BAAC0650DC7CE431F0C9E4A80822466DB4E610`, `1690530` bytes and `6676` lines, records UID0002MZ at line `2908`, `91/93`, average `92.0`, reconstructable `true`, with direct/additional/total report coverage `0/0/0`. Historical command `000000020473`, refreshed `2026-07-31T10:05:19-04:00`, source `foreground-generated-refresh`, recorded the same semantics at line `2903` under SHA256 `BD16E72C6F310435ED500A2046C655C0344C2C1615877AA78DAE4688605DFD19`, `1691162` bytes and `6676` lines. Historical command `000000020472`, refreshed `2026-07-31T10:03:53-04:00`, source `deferred-generated-refresh`, recorded the same semantics at line `2901` under SHA256 `FE5753AC3277E93226F53DEB38DE21B5F3C87A25FFA38B93A8910480F9DE3C23`, `1690848` bytes and `6674` lines. Historical command `000000020463`, refreshed `2026-07-31T09:41:33-04:00`, source `deferred-generated-refresh`, recorded the same semantics at line `2906` under SHA256 `F659FF7AA4280A667BEDAFB4EE42BC877B169621A4A45036C1C8619ADA024163`, `1690218` bytes and `6674` lines. Historical command `000000020404`, refreshed `2026-07-31T08:41:57-04:00`, recorded the same semantics at line `2904` under SHA256 `531FAAFFEB30E4C257A20B92A7A06A945301B7F8304A167C82D1A06B2B802806`, `1688621` bytes and `6666` lines. Historical command `000000020384`, refreshed `2026-07-31T08:28:07-04:00`, recorded the same semantics at line `2903` under SHA256 `01B2882AF326D8B820972D36DF604B4BB829DDDA049CD073F3446A21D11DFBE3`, `1688277` bytes and `6665` lines. Historical command `000000020381`, refreshed `2026-07-31T08:09:15-04:00`, recorded the same semantics at line `2903` under SHA256 `C821AB9522DC01A1A253D9D43DE688369C1D4406A7B1C5BFC31F304D829EB681`, `1688154` bytes and `6665` lines. Historical command `000000020355`, refreshed `2026-07-31T07:12:10-04:00`, recorded the same semantics at line `2903` under SHA256 `FBEB53EBA7B3732782C613CFE03FAD00F1257B80C7BB9E4779683D76866ABE23`, `1688013` bytes and `6665` lines. Historical command `000000020306`, refreshed `2026-07-31T05:47:39-04:00`, recorded the same semantics at line `2903` under SHA256 `ACBDEBA55094E6DE447ADC6B587D1BD0C2518AC47C2F37B8DB7FC673748FE390`, `1687888` bytes and `6665` lines. Historical command `000000020175`, refreshed `2026-07-31T03:50:02-04:00`, recorded the same semantics at line `2902` under SHA256 `8D25FA8A0D5AA888FB02A0514D50C92D82B945F747D4FCEF35720BBD84B2C1C1`, `1686231` bytes and `6658` lines. Historical command `000000020170` recorded the same semantics at line `2903` under SHA256 `00D887EB...45608E0`, and command `000000020160` recorded them under SHA256 `CF8C778F...68ACA3B`; command `000000020109` recorded them at line `2896` under SHA256 `706757C06C971EE12553F07CBE68178BCD73153AFA74CD7375B24A369332B342`, `1680966` bytes and `6637` lines; command `000000020104` recorded them at line `2896` under SHA256 `784D99B4A4C01C389EBBA2C057E636CC88BEADC9EF452E2FC71F3B103F9280CF`, `1680971` bytes and `6637` lines; command `000000020034` recorded them at line `2894` under SHA256 `C50515CD081E5C78870048F3FEBFC21858016DE01F9408E43865F85CF2EFA529`, `1679961` bytes and `6634` lines; command `000000020024` recorded them at line `2894` under SHA256 `6349AD9B2B2EE6282BEB28C7E80263431A5248FCF7996FA70BE5A36790D384A8`, `1679848` bytes and `6634` lines. Commands20384/20381/20355/20306/19995/19993/19928/19890/19891 and commands `19887`, `19812`, `19805` plus earlier tracker states are historical. No exact tracker snapshot is permanently current; the supervisor must physically reread tracker identity, counts, and the UID0002MZ row at Gate review.

## Follow-Up Actions

1. Historical completed checkpoint: supervisor pre-callback Gate 1 accepted exact SHA256 `01EC31D48291FAB439F0C94F98DEAAA0D86B18418BDE26C72B3FF37F799AC001` after validating the 33 headings, provenance, source-model inference, 173 atomic ledger rows, exact CPP/H blocks, scores, the then-stated 35 manual coverage operations, and 11 independently classified A01-A04/U00-U06 IDA entities.
2. Completed: B003 performed the authorized ordinary callback in dependency order, registered [UID:0004YK][Tree](by-file/Tree.md), read the assigned UID from both authoritative locations, reconciled every current ordinary TMP reference, applied every accepted B-agent-scope ordinary claim at report-level detail, historicalized superseded premises, released all leases, and passed every listed serial scoped validator with generated refresh disabled.
3. Completed additive callback repair: B003 reconciled all accepted generated/formal defects through 43 ordinary destinations, restored exact UID000447/000449/00044B CPP payloads, ordered generic declarations, routed 13 former empty-marker sources, made FolderTreePane.cpp header-dependent, and passed commands `19187`-`19216` plus the final duplicate-declaration correction command `19225`, all with generated refresh disabled.
4. Completed: supervisor Gate 2A passed all `43/43` ordinary destinations with zero drift against the frozen report artifact.
5. Completed: supervisor Gate 2B catalog `0365` applied/read back A01-A03 and U01-U05, independently confirmed A04/U00/U06, used IDA-only explicit four-byte alignment for U02/U03 after unannotated declarations produced undersized analysis UDTs, saved historical Gate 2B IDB `412DA7E8...19CD`, and recorded exact backup/readback/hash evidence; latest bounded read-only verification on `f608d7c2` against `B7CC899D...8058277` confirms that state remains intact. B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, 87D3, and 6470 are dated history, not durable current authority.
6. Completed: B003 reconciled the same report and 13 affected ordinary destinations to the actual Gate 2B state, preserved all older IDB identities and unannotated-declaration assumptions as historical, released every lease immediately, and passed serial validators `19668`, `19673`, `19675`, `19677`, `19681`, `19687`-`19690`, and `19692`-`19695` with generated refresh disabled.
7. Completed compile investigation and C2MZ-204 direct closure: B003 used x86 MSVC `19.44.35226` syntax-only `/Za` checks. Direct historical command-19802 baseline retained five passes and two pre-application failures. Every one of the 35 source errors was mapped to an exact owner correction; command20348 then supplied the post-C2MZ-211 seven-artifact set. Byte-identical copies of all seven artifacts were compiled with declaration-only `RectBounds`, `ScrollablePane`, and Windows-API dependency shims. The raw baseline exited `0` with zero errors and one exact warning, `FolderTreePane.cpp(180): warning C4505: 'anonymous-namespace::DirectoryEntryNameLess': unreferenced function with internal linkage has been removed`, proving that current generated FolderTreePane.cpp contains the comparator but omits its accepted owner method. A non-suppressed closure included that byte-identical FolderTreePane.cpp and the exact accepted `FolderTreePane::ExpandNode(TreeItor<TreeElem> *)` owner body with the real `std::sort(entries.begin(), entries.end(), DirectoryEntryNameLess)` consumer; it exited `0` with zero warnings and no C4505. All seven original command20348 hashes were unchanged before and after compilation, all seven temporary copies were byte-identical, and the disposable tree was removed. No project artifact, generated artifact, IDA, or lifecycle state changed.
8. Supervisor verification ownership: Gate 1/Gate 2A/Gate 2B and lifecycle disposition are authoritative only from the supervisor audit/readback plus validator-owned status/history metadata, not from workflow sequencing in this report. The report supplies C2MZ-061/079/103/107/111-115/123-125 and applied C2MZ-211 with current destination identities and validator records. The UID0000F9 formal-H declaration callback is complete and validated by command `000000020252`, exit `0`, `ok: 1`, with generated refresh skipped.
9. Completed C2MZ-204 evidence: the raw seven-artifact command20348 baseline had zero errors and one diagnostic that precisely identified the omitted accepted owner; the real non-suppressed `ExpandNode` consumer closure had zero errors, zero warnings, and no C4505. C2MZ-211 and the UID0002LN physical-formal reconciliation are completed historical repairs: commands `000000020252` and `000000020385`, each exit `0`, `ok: 1`, with generated refresh skipped, validate those exact ordinary repairs.
10. Completed historical supervisor coverage transaction: commands `000000020464`-`000000020469` applied and validated all 48 one-to-one manual coverage operations (`34` replacements and `14` insertions), exact-readback-verified every row including UID0004YK Tree, and preserved the moving research-tracker evidence recorded above. This is completed evidence, not a duplicate future instruction; execution/archive disposition remains supervisor-owned and authoritative outside this report body.

## Confidence

- Behavior/ABI/range/bytes/caller: `100%`.
- `TreeItor` spelling, iterator layout, owner/emitter/order: `99-100%`.
- Generic link prefix and payload/state separation: `97%` due exact dual-instantiation size arithmetic and semantics.
- Generic header-defined target source shape: `96%`.
- `FolderTreePane::TreeElem` 12-byte payload fields: `97%`.
- `TreeNode<T>` type spelling: `88%`, inferred best human name.
- Generic payload member `data`: `86%`, inferred best conventional name.
- Generic state member `disabled`: `94%`, corroborated by EventDispatcher and FolderTree semantics.
- Physical path `NexusTK/util/Tree.h`: `85%`, best project-structure inference without recovered source path.
- Overall target recommendation: very strong post-Gate2B reconciliation stage `91/93`. Shared ownership registration, the historical 43-destination ordinary changes and independent Gate 2A, supervisor-owned IDA actions/readback, the 13-document post-IDA reconciliation, dated shared-IDB bounded no-drift verification, dated incomplete command `20172` readback, bounded command-19802 compile diagnosis, eleven fully applied compile-support claim groups, UID0000JG's applied source-root contract, UID0000F9's applied C2MZ-211 declaration, UID0002LN's command20385 physical-formal equality, and C2MZ-204 direct compile closure are complete. The cap reflects inferred original lexical spellings, field names, and final historical source-path uncertainty; FolderTree manual coverage is complete. Supervisor report/lifecycle disposition is external to this confidence assessment.

## Validator Results

- Historical report-only phase: no validator, generated refresh, report execution, or lifecycle/probe command was run before Gate 1 acceptance.
- Historical `03F10207...E5DA` Gate 1 reconciliation: no validator, generated refresh, report execution, or lifecycle/probe command was run; only this report was edited after read-only IDB/MCP and filesystem-artifact checks.
- Historical `0E0AF938...AB481` no-drift reconciliation: no validator, generated refresh, report execution, or lifecycle/probe command was run; only this report was edited after bounded read-only IDB/MCP and filesystem-artifact checks.
- Historical `296ED21C...3CF8B` no-drift reconciliation: no validator, generated refresh, report execution, or lifecycle/probe command was run; only this report was edited after bounded read-only IDB/MCP and filesystem-artifact checks.
- Historical `905D1AB1...604C1` pre-Gate2B no-drift reconciliation: no validator, generated refresh, report execution, or lifecycle/probe command was run; only this report was edited after bounded read-only IDB/MCP and filesystem-artifact checks. That identity is now the exact catalog `0365` prestate/backup, not current authority.
- Retained validator-output/session evidence was re-read during this report-only repair. The table below is the exact event manifest for every B003-run scoped validator represented by this report: full command string, validator `command_id`, full timestamp, process/validator result, warning/error disposition, and generated-refresh state are one-to-one. No validator was rerun to create this manifest.
- Supervisor commands `000000020464`-`000000020469` are the completed manual-coverage transaction provenance, not B003-run validator records. Each exited `0` with `ok:1`, skipped generated refresh, and is independently confirmed by exact filesystem row readback; commands20365-20372 are dated moving-state prestates. The manifest below still contains exactly `92` B003-run scoped validator records because command20385 validates the authorized UID0002LN physical-formal reconciliation.

| command_id | command_timestamp | exact command string | result | warnings/errors | generated refresh |
|---|---|---|---|---|---|
| `000000018916` | `2026-07-29T08:21:43-04:00` | `python .\tools\validator.py --mode file --file by-file\Tree.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018930` | `2026-07-29T08:27:06-04:00` | `python .\tools\validator.py --mode file --file by-class\LObject.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018933` | `2026-07-29T08:27:13-04:00` | `python .\tools\validator.py --mode file --file by-type\by-template\StringBaseTemplate.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018934` | `2026-07-29T08:27:18-04:00` | `python .\tools\validator.py --mode file --file by-class\EPFTileContext.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018948` | `2026-07-29T08:33:44-04:00` | `python .\tools\validator.py --mode file --file by-type\by-template\FolderTreePaneTreeTemplates.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018949` | `2026-07-29T08:33:46-04:00` | `python .\tools\validator.py --mode file --file by-class\TreeStorage_struct_FolderTreePane__TreeElem_.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018950` | `2026-07-29T08:33:49-04:00` | `python .\tools\validator.py --mode file --file by-class\Tree_struct_FolderTreePane__TreeElem_.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018951` | `2026-07-29T08:33:51-04:00` | `python .\tools\validator.py --mode file --file by-class\TreeItor_struct_FolderTreePane__TreeElem_.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 2: missing_ref_uid 00036L, 00036M; errors 0 | skipped: `--no-generated-refresh` |
| `000000018952` | `2026-07-29T08:33:54-04:00` | `python .\tools\validator.py --mode file --file by-type\by-struct\FolderTreePane__TreeElem.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018957` | `2026-07-29T08:35:30-04:00` | `python .\tools\validator.py --mode file --file by-class\FolderTreePane.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018958` | `2026-07-29T08:35:32-04:00` | `python .\tools\validator.py --mode file --file by-file\FolderTreePane.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018959` | `2026-07-29T08:35:35-04:00` | `python .\tools\validator.py --mode file --file by-project-structure\proposed-source-tree.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 5: missing_ref_uid 0003LP, 0003WL, 0003WM, 0003WN, 0003WO; errors 0 | skipped: `--no-generated-refresh` |
| `000000018965` | `2026-07-29T08:37:43-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018966` | `2026-07-29T08:37:46-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018967` | `2026-07-29T08:37:49-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018968` | `2026-07-29T08:37:51-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018975` | `2026-07-29T08:39:44-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018976` | `2026-07-29T08:39:47-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018977` | `2026-07-29T08:39:49-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018979` | `2026-07-29T08:39:52-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018980` | `2026-07-29T08:39:55-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018987` | `2026-07-29T08:44:16-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018988` | `2026-07-29T08:44:18-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018989` | `2026-07-29T08:44:21-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018990` | `2026-07-29T08:44:23-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018991` | `2026-07-29T08:44:26-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018992` | `2026-07-29T08:44:28-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018993` | `2026-07-29T08:44:30-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018996` | `2026-07-29T08:48:36-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b1b90-0x004b32c9.FolderTreePaneCore.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018997` | `2026-07-29T08:48:39-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018998` | `2026-07-29T08:50:29-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000018999` | `2026-07-29T08:50:31-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019000` | `2026-07-29T08:50:33-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019001` | `2026-07-29T08:50:35-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019002` | `2026-07-29T08:50:38-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019003` | `2026-07-29T08:50:40-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b57e0-0x004b57e8.FolderTreeDirectoryEntryNameCleanupThunk.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019013` | `2026-07-29T08:52:43-04:00` | `python .\tools\validator.py --mode file --file by-file/Tree.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019187` | `2026-07-29T10:54:34-04:00` | `python .\tools\validator.py --mode file --file by-type/by-template/FolderTreePaneTreeTemplates.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019188` | `2026-07-29T10:54:59-04:00` | `python .\tools\validator.py --mode file --file by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019189` | `2026-07-29T10:55:20-04:00` | `python .\tools\validator.py --mode file --file by-class/Tree_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019191` | `2026-07-29T10:55:42-04:00` | `python .\tools\validator.py --mode file --file by-class/TreeItor_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 2: missing_ref_uid 00036L, 00036M; errors 0 | skipped: `--no-generated-refresh` |
| `000000019192` | `2026-07-29T10:56:09-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019193` | `2026-07-29T10:56:33-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019194` | `2026-07-29T10:57:07-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019195` | `2026-07-29T10:57:28-04:00` | `python .\tools\validator.py --mode file --file by-class/FolderTreePane.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019196` | `2026-07-29T10:57:50-04:00` | `python .\tools\validator.py --mode file --file by-type/by-struct/FolderTreePane__TreeElem.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019200` | `2026-07-29T10:58:21-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019202` | `2026-07-29T10:58:41-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019203` | `2026-07-29T10:59:28-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019204` | `2026-07-29T10:59:53-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019205` | `2026-07-29T11:00:22-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019206` | `2026-07-29T11:00:54-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019207` | `2026-07-29T11:01:15-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019208` | `2026-07-29T11:01:39-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019209` | `2026-07-29T11:01:59-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019210` | `2026-07-29T11:02:22-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019212` | `2026-07-29T11:02:43-04:00` | `python .\tools\validator.py --mode file --file by-type/by-vtable/FolderTreePaneTreeVtable.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019214` | `2026-07-29T11:03:06-04:00` | `python .\tools\validator.py --mode file --file by-type/by-vtable/FolderTreePaneTreeItorVtable.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 3: missing_ref_uid 00036M repeated by three reference checks; errors 0 | skipped: `--no-generated-refresh` |
| `000000019216` | `2026-07-29T11:03:28-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019225` | `2026-07-29T11:15:35-04:00` | `python .\tools\validator.py --mode file --file by-class/Tree_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019668` | `2026-07-29T15:08:01-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019673` | `2026-07-29T15:08:49-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019675` | `2026-07-29T15:09:23-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019677` | `2026-07-29T15:10:02-04:00` | `python .\tools\validator.py --mode file --file by-type\by-template\StringBaseTemplate.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019681` | `2026-07-29T15:10:27-04:00` | `python .\tools\validator.py --mode file --file by-type\by-struct\FolderTreePane__TreeElem.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019687` | `2026-07-29T15:10:48-04:00` | `python .\tools\validator.py --mode file --file by-class\TreeStorage_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019688` | `2026-07-29T15:11:14-04:00` | `python .\tools\validator.py --mode file --file by-class\Tree_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019689` | `2026-07-29T15:11:34-04:00` | `python .\tools\validator.py --mode file --file by-class\TreeItor_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019690` | `2026-07-29T15:11:56-04:00` | `python .\tools\validator.py --mode file --file by-type\by-template\FolderTreePaneTreeTemplates.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019692` | `2026-07-29T15:12:18-04:00` | `python .\tools\validator.py --mode file --file by-class\FolderTreePane.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019693` | `2026-07-29T15:12:51-04:00` | `python .\tools\validator.py --mode file --file by-file\FolderTreePane.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019694` | `2026-07-29T15:13:17-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b1b90-0x004b32c9.FolderTreePaneCore.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000019695` | `2026-07-29T15:13:38-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020053` | `2026-07-30T13:49:42-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020054` | `2026-07-30T13:50:06-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020056` | `2026-07-30T13:50:29-04:00` | `python .\tools\validator.py --mode file --file by-class\RectBounds.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020057` | `2026-07-30T13:50:54-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020058` | `2026-07-30T13:51:29-04:00` | `python .\tools\validator.py --mode file --file by-class\Pane.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020060` | `2026-07-30T13:51:48-04:00` | `python .\tools\validator.py --mode file --file by-type\by-template\StringBaseTemplate.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020062` | `2026-07-30T13:52:17-04:00` | `python .\tools\validator.py --mode file --file by-class\ScrollablePane.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020063` | `2026-07-30T13:52:36-04:00` | `python .\tools\validator.py --mode file --file by-class\EPFTileContext.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020064` | `2026-07-30T13:52:58-04:00` | `python .\tools\validator.py --mode file --file by-class\FolderTreePane.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020066` | `2026-07-30T13:53:27-04:00` | `python .\tools\validator.py --mode file --file by-file\ScrollBar.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020067` | `2026-07-30T13:53:51-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x005840f0-0x0058415a.WideRangeCompare.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0; three UID links normalized and two reference-index entries added | skipped: `--no-generated-refresh` |
| `000000020068` | `2026-07-30T13:54:38-04:00` | `python .\tools\validator.py --mode file --file by-file\FolderTreePane.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0 | skipped: `--no-generated-refresh` |
| `000000020069` | `2026-07-30T13:55:51-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0; exact accepted line wrapping reconciled after command20057 | skipped: `--no-generated-refresh` |
| `000000020070` | `2026-07-30T14:08:59-04:00` | `python .\tools\validator.py --mode file --file by-class/Pane.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0; historicalized superseded blank-formal wording | skipped: `--no-generated-refresh` |
| `000000020071` | `2026-07-30T14:09:29-04:00` | `python .\tools\validator.py --mode file --file by-class/ScrollablePane.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0; reconciled complete-H versus historical marker-only wording | skipped: `--no-generated-refresh` |
| `000000020072` | `2026-07-30T14:09:50-04:00` | `python .\tools\validator.py --mode file --file by-class/FolderTreePane.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0; reconciled nonblank CPP route, nested dependencies, and dated IDB wording | skipped: `--no-generated-refresh` |
| `000000020073` | `2026-07-30T14:10:05-04:00` | `python .\tools\validator.py --mode file --file by-type/by-template/StringBaseTemplate.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0; replaced durable-current IDB wording with dated checkpoint wording | skipped: `--no-generated-refresh` |
| `000000020252` | `2026-07-31T05:04:22-04:00` | `python .\tools\validator.py --mode file --file by-class/Tree_struct_FolderTreePane__TreeElem_.md --apply --queue-timeout 240 --no-generated-refresh` | exit `0`; `ok: 1` | warnings 0; errors 0; exact C2MZ-211 declaration validated; registry hash advanced `ee03f36d...bbf1 -> 1b460525...7d9f`; projected-stats update reported an incremental no-op for UID0000F9 | skipped: `--no-generated-refresh`; command timestamp `2026-07-31T05:04:22-04:00`; process completed `2026-07-31T05:04:24.4359544-04:00` |
| `000000020385` | `2026-07-31T08:28:14-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x005840f0-0x0058415a.WideRangeCompare.md --apply --no-generated-refresh --queue-timeout 240` | exit `0`; `ok: 1` | warnings 0; errors 0; physical formal CPP reconciled byte-for-byte to the accepted report payload; registry hash advanced `2715839263ffa590... -> 583b2601542e04ae...`; projected-stats update was an incremental no-op | skipped: `--no-generated-refresh`; command timestamp `2026-07-31T08:28:14-04:00` |
- No report validator, coverage validator, generated refresh, tracker refresh, lifecycle command, or `execute_report` was run by B003 during the post-Gate2B reconciliation or this report repair. Commands20252 and20385 are the two focused callback validators added after the earlier ordinary manifest; their validator-owned registry/projected-stat side effects are tool output, not B003 manual edits.
- Compile-only callback: no validator, generated refresh, tracker refresh, IDA/MCP call, report lifecycle command, or `execute_report` probe was run. Tool discovery found Visual Studio 2022 Community x86 `cl.exe` `19.44.35226`; no installed Clang/GCC/historical VC C++03 compiler or generated-tree build project was found. `cl /std:c++03` was explicitly probed and produced warning D9002 because the option is ignored, so it is not counted as a strict-mode pass.
- Exact direct command shape was `call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" -arch=x86 -host_arch=x64 >nul && cl /nologo /TP /Zs /W4 /WX- /EHsc /Za "<absolute-generated-artifact>"`. Exit `0`: LObject.h, StringBase.h, Tree.h, Tree.cpp, EPFTileContext.h. Exit `2`: FolderTreePane.h and FolderTreePane.cpp. Exact diagnostic locations/classes and the residual 35-error isolated-source result are recorded in Supporting Research.
- Exact diagnostic/repair command shapes used the same x86 `VsDevCmd` prefix followed by `cl /nologo /TP /Zs /W4 /WX- /EHsc /Za FolderTreePane.h`, the matching source command, and corresponding `/permissive- /Zc:__cplusplus /std:c++14` commands. The baseline isolated source emitted exactly 35 errors with C2039/C2065/C2143/C2146/C2737/C3861/C4430. After only the twelve report-recommended owner/source corrections, header and source commands exited `0` in both modes. Header diagnostics were empty; source diagnostics contained only C4505 for the precisely identified absent expansion/sort consumer. `/Zs` produced no object. The entire temporary tree was deleted after capture.
- Exact C2MZ-204 raw generated-baseline invocation was `call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat" >nul && cl.exe /nologo /Zs /TP /Za /W4 /EHsc /I"C:\Users\admin\AppData\Local\Temp\ntk_b003_uid0002mz_cmd20348_20260731" "C:\Users\admin\AppData\Local\Temp\ntk_b003_uid0002mz_cmd20348_20260731\util\LObject.h" "C:\Users\admin\AppData\Local\Temp\ntk_b003_uid0002mz_cmd20348_20260731\util\StringBase.h" "C:\Users\admin\AppData\Local\Temp\ntk_b003_uid0002mz_cmd20348_20260731\util\Tree.h" "C:\Users\admin\AppData\Local\Temp\ntk_b003_uid0002mz_cmd20348_20260731\util\Tree.cpp" "C:\Users\admin\AppData\Local\Temp\ntk_b003_uid0002mz_cmd20348_20260731\render\EPFTileContext.h" "C:\Users\admin\AppData\Local\Temp\ntk_b003_uid0002mz_cmd20348_20260731\ui\controls\FolderTreePane.h" "C:\Users\admin\AppData\Local\Temp\ntk_b003_uid0002mz_cmd20348_20260731\ui\controls\FolderTreePane.cpp"`. MSVC x86 `19.44.35226` exited `0`; stdout/stderr enumerated all seven inputs and contained zero errors plus exactly `FolderTreePane.cpp(180): warning C4505: 'anonymous-namespace::DirectoryEntryNameLess': unreferenced function with internal linkage has been removed`. This warning is positive ownership evidence: the exact generated source contains the comparator but omits the accepted `ExpandNode` consumer.
- Exact non-suppressed owner-closure invocation was `call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars32.bat" >nul && cl.exe /nologo /Zs /TP /Za /W4 /EHsc /I"C:\Users\admin\AppData\Local\Temp\ntk_b003_uid0002mz_cmd20348_20260731" "C:\Users\admin\AppData\Local\Temp\ntk_b003_uid0002mz_cmd20348_20260731\util\Tree.cpp" "C:\Users\admin\AppData\Local\Temp\ntk_b003_uid0002mz_cmd20348_20260731\FolderTreePaneClosure.cpp"`. The closure translation unit includes the byte-identical exact generated `ui/controls/FolderTreePane.cpp` and then the report/by-file accepted binary-backed `FolderTreePane::ExpandNode(TreeItor<TreeElem> *)` body with its real `std::sort(entries.begin(), entries.end(), DirectoryEntryNameLess)` use; it does not suppress a warning or add an artificial anchor. MSVC exited `0`; complete compiler output was exactly `Tree.cpp` followed by `FolderTreePaneClosure.cpp`, with zero errors, zero warnings, and no C4505. `Tree.cpp` was direct input; the closure consumed FolderTreePane.cpp, which consumed FolderTreePane.h, EPFTileContext.h, StringBase.h, Tree.h, and transitively LObject.h. The declaration-only RectBounds/ScrollablePane/Windows shims supplied only dependencies outside the seven exact artifacts.
- Exact pre/post original hashes remained LObject.h `6556B04AC99A381F40487D19CBA5B98D663F180B2B6C2ADCB876B4E1A529D12C`, StringBase.h `896657BA94265AF3F5FA412098C0DC374F46416D4FE1FED9F444079914D6D7F5`, Tree.h `A5FC0D4F7DD6EDF3034C61F3A15434D13B51084C03473009D2DD544A76004E1C`, Tree.cpp `BCF1758126AF74A38DE431BD3EFDDF4FA46C4E5342ECD11288612A2200440054`, EPFTileContext.h `9E647CF7286FB81C0A4A0CFA944FD39C07D8FEC565CB6FEE7DC292D8E15A9225`, FolderTreePane.h `7980028EF777D44F45AD5A8A60DE17F0312E22A10F8532FF9CCD67BA16A03574`, and FolderTreePane.cpp `6FE8C918E04614BEB72D19F33650187A5F45F9BEE0DD3362BAE3567AB19F6E7C`. Readback reported `BYTE_IDENTICAL_COPIES=7`; every temporary file and directory was then removed. This closes C2MZ-204 without changing a generated or project artifact.
- Accepted callback commands `20053`, `20054`, `20056`-`20058`, `20060`, `20062`-`20064`, `20066`-`20073`, focused command `20252`, and UID0002LN reconciliation command `20385` each exited `0` with `ok: 1`; all explicitly skipped generated refresh. Commands `20070`-`20073` reconcile current prose in four already accepted destinations and do not add claim groups; command20252 applies C2MZ-211 and command20385 revalidates applied C2MZ-125 after exact physical/report formal equality. Their validator-owned registry/projected-stat side effects are tool output, not manual B003 edits. Commands `19221`, `19752`, `19753`, `19759`, `19761`, `19779`, `19784`, `19786`, `19802`, `19810`, `19812`, `19887`, `19890`, `19891`, `19928`, `19993`, `19995`, `20024`, `20034`, `20104`, `20207`, `20304`, `20306`, and `20355` remain historical checkpoints. Eleven exact support claim groups, UID0000JG's C2MZ-124 source-root contract, UID0000F9 declaration claim C2MZ-211, and generated/compile claim C2MZ-204 are applied. FolderTree manual coverage is applied and validated. Supervisor Gate/lifecycle state is not asserted here and is authoritative only from supervisor audit/readback and validator-owned status/history metadata.
- Supervisor-owned command `000000020172` is not one of the 92 B003-run scoped validator records above. All seven dated pre-C2MZ-211 target artifacts and `-ag-memory-coverage.md` identify command `000000020172`, timestamp `2026-07-31T03:46:57-04:00`, and source `foreground-generated-refresh`; their exact hashes, rows, sizes, topology, and pre-callback missing UID0000F9 declaration are recorded under Supporting Research and Changed Files. Its exact invoking CLI, process exit/`ok`, and warning/error summary were not supplied to B003 and are not fabricated here. Commands `20109` and `20104` are older history.

## Changed Files

- Same report amended in place throughout research, Gate 1 repair, and this authorized callback:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0002MZ-FolderTreeIteratorMoveToFirstChild-source-quality.md`.
- The accepted earlier ordinary callback changed exactly twelve by-* destinations: UID000346, UID000343, UID0000BU, UID000156, UID0000A2, UID0001WS, UID0000CF, UID00004I, UID0000NF, UID00005A, UID0000JG, and UID0002LN. Those changes remain present. The focused accepted callback changed one additional existing destination, UID0000F9, by inserting exactly `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);` after the two `NodeAt` overloads and before `protected:`; command20252 validated the poststate SHA256 `23E93045D1CBFD839C8A47F796F3E756FA6C641F5A233BB919EAFE36D1B6EB6D`, `24888` bytes, `173` lines, with generated refresh disabled. This rejected-closure repair also reconciled UID0002LN's physical formal CPP byte-for-byte to this report's canonical payload and validated poststate SHA256 `2C7DF76691A966250BABA28C5A44FF754A1462C5D0C45E602199E779B9B7654A`, `10108` bytes, `127` lines under command20385 with generated refresh disabled; its direct H remains blank because UID0001WS owns/emits the declaration. B003 did not edit generated artifacts; supervisor command20348 is the generated code/memory checkpoint and includes the declaration at Tree.h line `70`; command20474 is the latest observed dated moving checkpoint after B006 de-execution; command20473, command20472, command20463, command20404, commands20384/20381/20355/20207/20304/20306, command20172's incomplete pre-C2MZ-211 set, and commands20109/20104 are dated history. The direct compile used disposable byte-identical copies only, and no temporary source, object, compiler log, or project artifact remains.
- This mandatory post-IDA reconciliation changed 13 ordinary destinations so their current-state prose records the actual catalog `0365` names/types/comments/UDTs, typed decompile, IDA-only alignment syntax, and natural-source/formal distinction. The exact post-edit report SHA256, byte size, line count, heading count, ledger count, and marker count are returned in the B003 handoff rather than embedded here because embedding the current report hash would change that hash.
- Current post-callback ordinary manifest: all 49 destination paths were reread during the latest bounded currentness pass and match their exact SHA256/byte/line entries with zero drift; command20252 advances UID0000F9 to the post-C2MZ-211 identity and command20385 advances UID0002LN to the exact physical/report formal-CPP identity recorded below. Thirteen destinations remain accepted ordinary callback deltas; 36 are support/no-edit destinations, five of which advanced concurrently after command20385 without losing any UID0002MZ-required declaration, ABI contract, or source-root route. Specifically, UID0001WS retains `DetachWideIfShared` and `WideRangeCompare`, UID0000BU retains `struct RectBounds` and `ContainsPoint(int y, int x)`, UID0000A2 retains the complete Pane ABI, UID0000CF retains the complete `ScrollablePane` declaration and member layout, and UID0000NF retains the complete ScrollBar source-root assembly. B180, 9F8A, `DAA59745...87462C17`, `DADC487F...8967C6A4`, `836ABCFA...CCF489F`, and `3892BDA8...72798D1` are dated IDB history. The current identities are:
  - UID0004YK `by-file/Tree.md`: `7605D5CEF7EB359C311D7B3C30D8C7D42023C5E49CAC0857DD818555B18F8CB9`, `6930`, `60`.
  - UID00007D `by-class/LObject.md`: `0BC9E0D06EA919C11F8A66912A87DC86E797AC8E0BA69C5A00B88811584DD219`, `23138`, `179`; the accepted declaration is unchanged and now resides under the canonical `NEXUSTK_UTIL_LOBJECT_H` guard.
  - UID0001WS `by-type/by-template/StringBaseTemplate.md`: `2E97EDB1812A7F99EA8683C80BD9C6AC7A7F24AA1CAEA322CC8F14B38131346E`, `50210`, `282`; the accepted one-pointer template, `DetachWideIfShared`, and namespaced `WideRangeCompare` declarations are unchanged under the canonical `NEXUSTK_UTIL_STRINGBASE_H` guard.
  - UID00004I `by-class/EPFTileContext.md`: `B41C852E21CF15A7295DCDF03F22790F7B5573D04BCA61F88D0F828356EA90F4`, `25623`, `233`.
  - UID00005A `by-class/FolderTreePane.md`: `85D41C8E7B8C46AB4B69B591D3D5F9FE6DD8675B9D74AF534DE3DF58EAF47754`, `64289`, `371`.
  - UID0000JG `by-file/FolderTreePane.md`: `8BB41392DC14F5FC56412995EE055907828F7FFF05BBAD4BC8AD4A533A19F831`, `74165`, `409`.
  - `by-project-structure/proposed-source-tree.md`: `527DC0CBE955189013A86297B63BBB6258BC9616361A81BD4DE53FDD7BA23049`, `315420`, `2128`.
  - UID0001WP `by-type/by-template/FolderTreePaneTreeTemplates.md`: `2A96C1AE57C87216B7C48CB32FB58694121CC7EB5D6BC6E13F9750D03410A652`, `41941`, `240`.
  - UID0000FC `by-class/TreeStorage_struct_FolderTreePane__TreeElem_.md`: `3812C4B70CC1A57B6F70D828F97858503E1E8241CD5BC6624F99D829FAD13F86`, `25961`, `178`.
  - UID0000F9 `by-class/Tree_struct_FolderTreePane__TreeElem_.md`: `23E93045D1CBFD839C8A47F796F3E756FA6C641F5A233BB919EAFE36D1B6EB6D`, `24888`, `173` (C2MZ-211 applied; prior `ED81805B...D35E882`, `24821`, `171` is the accepted callback prestate).
  - UID0000FB `by-class/TreeItor_struct_FolderTreePane__TreeElem_.md`: `506C90F4AF700447B22939CE64E0072CE30083B91D88402FB8DC9A64E7B3BECE`, `22339`, `203`.
  - UID0001UJ `by-type/by-struct/FolderTreePane__TreeElem.md`: `E1A63E613B12DFB238F8AB63909DB17FBC65FD27AEBBFFB3D21E4536EE0C7411`, `36191`, `227`.
  - UID0002MZ `by-memory/0x004b5bb0-0x004b5bd0.FolderTreeIteratorMoveToFirstChild.md`: `EBACBC0B05EF619F748A220CBDD52A61DF17B063E6B7E23FFF93B0B6EAB60200`, `9797`, `108`.
  - UID0002N0 `by-memory/0x004b5bd0-0x004b5c13.FolderTreeIteratorMoveToNextVisibleSibling.md`: `8622895DF7BFB7D46851DB36C31F22F5DC71FAEF7D5B4F7710EFA93B7BB85172`, `14317`, `135`.
  - UID0002N1 `by-memory/0x004b5c20-0x004b5c3f.FolderTreeIteratorMoveToParent.md`: `3DF9DFF782AA1C8A289184CBF57C5079D15361BB3B9197D69B45DC7B3EAF7C82`, `8967`, `106`.
  - UID0002MY `by-memory/0x004b5b00-0x004b5bae.FolderTreeResetToSingleRoot.md`: `D1C1ED9CEE4F08FBB1D099C3EB082AFE114C756C76B9E708D959BC5CA3218624`, `14811`, `140`.
  - UID000344 `by-memory/0x004b3400-0x004b3645.FolderTreeContentDimensionsTraversal.md`: `4B232E58684C537AC4A0B3686D13D3B0B68BB94D8D6AFB920237AC686D4F8DC3`, `15031`, `174`.
  - UID000345 `by-memory/0x004b3650-0x004b3848.FolderTreePaintTraversalCallback.md`: `B80DA5D974E8753A1ADEF163B33F7C32E5EDFA2D364E7C7A90F47BDC0602C4A6`, `28083`, `263`.
  - UID000346 `by-memory/0x004b3850-0x004b3ae2.FolderTreeHitTestTraversal.md`: `F838713D8ECF0EE53B769E167C40DE2C740EE37769913D0745DBC86BDF750972`, `9338`, `148`.
  - UID000347 `by-memory/0x004b3af0-0x004b3d41.FolderTreeVisibleNavigationSearch.md`: `A74C03BF48EDC31305015A7E25C7626CE65190E8F5B4D504B36E866E953BF6FA`, `9329`, `150`.
  - UID00034H `by-memory/0x004b5810-0x004b59d5.FolderTreePaintNodeHelper.md`: `8C282159B2879B2E92E077940AB989B17DE2BA95726A959BE901F8C0C8640046`, `13974`, `155`.
  - UID0002MV `by-memory/0x004b3d50-0x004b3fa4.FolderTreeStorageInsertAt.md`: `DE1AE433187A86A1E448501BEDD16F21BB80D0692D7BB87F782B07B79D435A09`, `18419`, `114`.
  - UID0002MW `by-memory/0x004b55e0-0x004b564d.FolderTreeElemCopyConstruct.md`: `5BB9776F52921DFDDFF2A63CA00CB2BB2A566E5503258A16F04BF4B75D10CCE9`, `14725`, `108`.
  - UID0002MX `by-memory/0x004b56e0-0x004b575f.FolderTreeStorageDestructor.md`: `A39585CCF0D1C22931FEE83B9D37CB0D385D6FAC11CD1C2D2E74CC1DA7FB4FF1`, `13343`, `100`.
  - UID00022E `by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md`: `E9EF122CAA641FD7D125B2EB46BAE040E802BB43799AF6E5A55B2788D618BF27`, `19368`, `145`.
  - UID000447 `by-memory/0x004b5cc0-0x004b5ce5.FolderTreeElemRangeDestroy.md`: `30F4ACBA878EE7E02BF01903BEC0701932D670FABD8ADF866739D81928CE4FC8`, `5401`, `65`.
  - UID000449 `by-memory/0x004b5d20-0x004b5ddf.FolderTreeElemRangeCopyConstruct.md`: `A0E9E868B4AEE84AE4C86E1D37D7684954A382ABDD4D8B8C1F00679D10D72400`, `5596`, `65`.
  - UID00044B `by-memory/0x004b5e80-0x004b5ebc.FolderTreeElemVectorStorageFree.md`: `ECC963878BD89A4012E38C06CAD0150BF1DD9B09340490D42CD43C794FFA239E`, `5125`, `64`.
  - UID00034F `by-memory/0x004b5670-0x004b5677.FolderTreeIteratorVtableResetDestructor.md`: `E1F0945B095F609B2E4C1E4375ECC905A89269A972E42CB5779B7EFDED2040C8`, `8289`, `82`.
  - UID000158 `by-memory/0x004b5650-0x004b5669.FolderTreePaneTreeDestructor.md`: `4E89FF57ACC7D6086114EB640A23B65FD84B07B3A95BE3B631505155156D98EC`, `20693`, `184`.
  - UID00034I `by-memory/0x004b59f0-0x004b5a38.FolderTreeScalarDeletingDestructor.md`: `543ABC4607A03E7C7E0395E473082E9597D8E644857C9813EFB021A94F50514A`, `7514`, `82`.
  - UID00036K `by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md`: `2E9AB381DD989743389219F9091874F9034D2020085765C94433BEBB566A4F05`, `7513`, `80`.
  - UID00036J `by-type/by-vtable/FolderTreePaneTreeVtable.md`: `AC99216592B9FC1320897ACC42A2EEE4D638E57CCA1378D6C0295450B610B215`, `6676`, `71`.
  - UID00036L `by-type/by-vtable/FolderTreePaneTreeItorVtable.md`: `A7CA05B359DEE395CD2E2198CF5F69AB0D0C23E858456E2BE30341A9E850ED25`, `5654`, `69`.
  - UID00036M `by-memory/0x0061a50c-0x0061a514.FolderTreeIteratorVtableData.md`: `35E959F9EC11E98C8C74EA4D0CEFD6FBE7044BBA6B2EE34255921CCCA9260FF6`, `4641`, `67`.
  - UID000155 `by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md`: `1509D9DF7CAE334608ACDA43623BAE3760926B7732D2C4F2EDB9BE6CE9D67414`, `50664`, `270`.
  - UID000157 `by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md`: `D7D9E4465706B593B155517A91E32DD55CACE5DE6E77173F4B53DA90CDCA094A`, `65993`, `328`.
  - UID000343 `by-memory/0x004b3350-0x004b33fc.FolderTreeDirectoryEntryNameLess.md`: `4422291AF0601D5C5F7E552D682628F4AB1B2A45ACF8C4F82EE5D4897D63DBB9`, `16667`, `137`.
  - UID000348 `by-memory/0x004b3fb0-0x004b4232.FolderTreeDirectoryEntryVectorInsertAt.md`: `94BE0E33BF3F20A678785F841A15A32614F3892C24744760916D30555DCDBBA4`, `10999`, `99`.
  - UID00034B `by-memory/0x004b4520-0x004b4fc5.FolderTreeDirectoryEntrySortCore.md`: `DE36FA74703847B48388B7A02C88585ADA215C7F54E5880D4C28CE48190C9B4B`, `15370`, `133`.
  - UID00034C `by-memory/0x004b4fd0-0x004b5271.FolderTreeDirectoryEntryAdjustHeap.md`: `857E1F8BCF7D36107C951AAA462F1E2324C0FF814766B9CC25CF0319DC889B47`, `16950`, `144`.
  - UID00034E `by-memory/0x004b5510-0x004b55d3.FolderTreeDirectoryEntrySwap.md`: `3EB786335E8551C1DBC9A6762CBDB2E2337B34BB047AD7F71EF3BDA73EC38DB2`, `6802`, `88`.
  - UID00031B `by-memory/0x004b57e0-0x004b57e8.FolderTreeDirectoryEntryNameCleanupThunk.md`: `DB9E65C6BF6FB7EE7BA4116575859B3431A977C1316D3C93F4946D67A88DC5A7`, `7375`, `84`.
- Six destinations omitted by the earlier 43-file callback manifest now carry these exact post-callback identities:
  - UID0000BU `by-class/RectBounds.md`: `0D92730DD863B0773E348B029188D8DF5E1EC45C2BD3632CDFA9A3235972BD6F`, `35367`, `203`; the accepted 16-byte declaration and y/x `ContainsPoint` contract are unchanged under `NEXUSTK_UI_CORE_RECTBOUNDS_H`, and the invalid H-child attachment token is absent.
  - UID0000A2 `by-class/Pane.md`: `E6A7E2074FECAE251DF5599A92C4BFA7D50C3C69E82F44287BCC4894021C91DD`, `30942`, `297`; metadata `92/94`, owner/emitter UID0000MC, complete formal H, and the accepted no-loss family-wide ABI repair remain the explicit supervisor-retained checkpoint under `NEXUSTK_UI_CORE_PANE_H`, with no invalid H-child attachment token.
  - UID0000CF `by-class/ScrollablePane.md`: `1DF4CDE466DC5FBF482224AD6273B1138F6EE82AF11ED96D9FA9F022AB8E6501`, `23459`, `202`; the complete declaration and unsigned-scroll ABI remain unchanged, the fragment closes the shared ScrollBar guard, and the invalid H-child attachment token is absent.
  - UID0000NF `by-file/ScrollBar.md`: `ECAAB87D75DD3CE2D291ACE5F4EF1588EECC458FBAA5BFC30E33D4F39339C281`, `50963`, `276`.
  - UID000156 `by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md`: `17DDB21E649344806DD57FA1E8A9C179CC0A3D85C8E051873BCE7C2B8C846D8A`, `18363`, `189`.
  - UID0002LN `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md`: `2C7DF76691A966250BABA28C5A44FF754A1462C5D0C45E602199E779B9B7654A`, `10108`, `127`; command20385 validates exact physical/report formal-CPP equality with generated refresh disabled.
- All ordinary leases were acquired only immediately before editing and released immediately afterward. Final lease readback contains no B003 row.
- B003 did not manually edit any `-coverage-report.md`, generated/tracker/stats artifact, IDA state, supervisor audit/catalog/lifecycle file, or validator registry/queue file, and did not execute or move this report. Scoped validators reported their normal registry/projected-stat bookkeeping side effects while generated refresh remained disabled.
- Historical Gate 1 read-only ordinary/generated prestates for every planned callback destination follow for chronology only; they are superseded as current ordinary identities by the manifest above:
  - UID00007D SHA256 `2F52C538DD310EDF9F7D278BF8026FA746FEE5326A7D7E3ED7064ED885B26952`, size `21345`.
  - UID0001WS SHA256 `299D2F3AD977C3B60ED277916E82CA4301081C27A4BA5AB3320409C034B8814D`, size `46240`.
  - UID00004I SHA256 `79076ED6B6B9ED9F907CB1A9CFA1625A5E642459A8E971E3C4DE9DCDB7CFE748`, size `24680`.
  - UID00005A SHA256 `2141870B6813748B9AB5D61D0D1DC6F325B1709130E50748ABC3215E189C0E23`, size `60544`.
  - UID0000F9 SHA256 `1B025E32C641861FDDE13576A0724B5C42A9496A67F8C4761E639F69DF9A0BE6`, size `23459`.
  - UID0002MZ SHA256 `CF01CEA3C98F3B6D83D0BBB574D9CC9ACFC3E246101CE88CE2CD2F9FB185F44E`, size `7644`.
  - UID0000FB SHA256 `083D7799E8C8D6B990D4592C44771B9F7D7FCA4DFFB686D0975B58F96FB6F320`, size `21021`.
  - UID0000FC SHA256 `FDFA379C9A69408550FF7223FD1C61F994B050039F92FDE14EC429984BDE1CA7`, size `23707`.
  - UID0001WP SHA256 `5780208D4012FBA315411C4364C904CDFE9FFA76B16230ED1236BC2160C1C0C9`, size `39572`.
  - UID0001UJ SHA256 `C24FCE1EC6C0D78CE6E67A09163E19A6BB645B3369E26D20156E18F1201ED669`, size `34549`.
  - UID0000JG SHA256 `547F76B3BCDF6A822BC2DEB8680B881908CCDD1240A578564B906C5FFE5560DE`, size `67899`.
  - UID000155 SHA256 `82AE1CD1948CA86CF79765AA685422BEC363C7E3090215250408C43C4B72B9F0`, size `48276`.
  - UID000343 SHA256 `0F1545E16F492E2B8775906D6C693EA60834B297A118F4CDB6837CCE77019467`, size `15819`.
  - UID000157 SHA256 `5A4D0B05A852D18F19CB9AEE96DA1E586945D866D795DFB096E8338D7D386575`, size `63066`.
  - UID000344 SHA256 `D260B18F9BF6609496AF0579244F3DE72CF4DBB62279516F872545FB03F2F790`, size `14101`.
  - UID000345 SHA256 `FAB67BC7F47FB8C320E574472D5C71E8B65F43C51DEA06AA60BA92B18114D003`, size `27335`.
  - UID000346 SHA256 `6AADF94CBB1D460070ED72881984C451DD08D8809532B99F3CF0DB1B4E8C919F`, size `8276`.
  - UID000347 SHA256 `243F03CF215293D36FE6FF6FF6506E58E144F5839E27E32BEDD0282225C87A53`, size `8341`.
  - UID0002MV SHA256 `F5E971ABA884AA02E90112206D7CDE76F0748E6E13E2887D77750469A5A52E89`, size `17805`.
  - UID000348 SHA256 `2C586323A9E8A1B05544B4CA4B10042E77DD46F73C239798A473DF2491EF05BB`, size `9972`.
  - UID00034B SHA256 `CD20DC7B3DAE3F1B2FED48D95F8721DDBD307C89DC1D5131784F743A69F4FEA4`, size `14555`.
  - UID00034C SHA256 `DF76990EDFB4D40F459805A7A190022FC95D880B08EED5A4C5ABE3AEB1521FDE`, size `16150`.
  - UID00034E SHA256 `279A072373C9EF00803E13EE84DAD9BC15AF4AB4AFD8AFF5C4E4AEC9D14DD981`, size `5825`.
  - UID0002MW SHA256 `92D74FA7793F66D0A456384640477B0119CC56EBBBD7664C8CE64E3BB65709B0`, size `13957`.
  - UID0002MX SHA256 `D86EB0FBB4046BAC5913C7ADF2EBB11D5C302F06BA1C5B342B07D9A2D5AA8ADB`, size `12777`.
  - UID00031B SHA256 `B62A11D78A24BA133DE5D013AD17B04CA3B80B44F47C73978C279AA906B214CF`, size `6215`.
  - UID00034H SHA256 `0896D4C2FC44CE3875BC2BF2D76D45FBD9B2D8D5F6BECF997849D7C9B2B124BA`, size `13208`.
  - UID0002MY SHA256 `BE3A4753F57A83C150F3BD62E61A4DE86BD7BFD5676B7A93DE765CF33B410A36`, size `13415`.
  - UID0002N0 SHA256 `0694458BB07914F0C4AD1FA2515FDDC77ADE903388CE8D0DD52361767C02ED2F`, size `12799`.
  - UID0002N1 SHA256 `DCFD3A681933960BEAAEFEB4A3239C62C2E667AE5FDD9CCA51C5C2B09059DF6C`, size `7657`.
  - UID00022E SHA256 `28150D08C3B654A6584D657313ADC804D42551F1AB9AC4011B60A083BE4D4C12`, size `17039`.
  - UID000447 SHA256 `53F584C4EA2EA42F24702ED027E4B458202CD8B2665054F2969EF8560E46A90C`, size `4744`.
  - UID000449 SHA256 `85EF13AF7A2583D86E5D5BB107F8D8761704142DF6A6E3AA48FBB3F4E45F0C74`, size `4927`.
  - UID00044B SHA256 `95C84BCC1C29FCDADB000515070E8E1FEC314E2A6D9AB6D3CB59C5F4E33F71B9`, size `4522`.
  - `by-project-structure/proposed-source-tree.md` SHA256 `527DC0CBE955189013A86297B63BBB6258BC9616361A81BD4DE53FDD7BA23049`, size `315420`, `2128` lines; the dated `C999E7C7...DB9F6` identity was a pre-concurrent-revision checkpoint, and the current file preserves the accepted UID0002MZ header ordering with no `Tree.cpp`.
  - Historical generated commands `000000018808` and `000000018812` retain the pre-callback hashes above. Pre-final command `000000019221` identifies the artifact set that exposed the duplicate late declaration; UID0000F9 changed afterward under command `19225`, so those hashes are historical only.
  - Generated code and generated-memory checkpoint is validator command `000000020348`, refreshed `2026-07-31T06:53:05-04:00`, source `foreground-generated-refresh`: LObject.h `6556B04AC99A381F40487D19CBA5B98D663F180B2B6C2ADCB876B4E1A529D12C` (`993` bytes, `28` lines); StringBase.h `896657BA94265AF3F5FA412098C0DC374F46416D4FE1FED9F444079914D6D7F5` (`1307` bytes, `41` lines); Tree.h `A5FC0D4F7DD6EDF3034C61F3A15434D13B51084C03473009D2DD544A76004E1C` (`3898` bytes, `153` lines); trace-only Tree.cpp `BCF1758126AF74A38DE431BD3EFDDF4FA46C4E5342ECD11288612A2200440054` (`1788` bytes, `28` lines); EPFTileContext.h `9E647CF7286FB81C0A4A0CFA944FD39C07D8FEC565CB6FEE7DC292D8E15A9225` (`1185` bytes, `37` lines); FolderTreePane.h `7980028EF777D44F45AD5A8A60DE17F0312E22A10F8532FF9CCD67BA16A03574` (`2267` bytes, `68` lines); FolderTreePane.cpp `6FE8C918E04614BEB72D19F33650187A5F45F9BEE0DD3362BAE3567AB19F6E7C` (`22232` bytes, `508` lines); `auto-generated/-ag-memory-coverage.md` `C2D261C91496DD1C3C264766554D815C121F0465BCCD798F305D51A5F48D791C` (`1428860` bytes, `4978` lines), with UID0002MZ line `910` coded through UID0000FB at position `40`. Tree.h line `70` contains `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);`. Latest observed dated moving tracker command `000000020474`, refreshed `2026-07-31T10:13:05-04:00`, source `deferred-generated-refresh`, owns `auto-generated/-ag-research-tracker.md` `DA13617295274A581850C344E6BAAC0650DC7CE431F0C9E4A80822466DB4E610` (`1690530` bytes, `6676` lines), with UID0002MZ line `2908` at `91/93`, average `92.0`, reconstructable true, coverage `0/0/0`; command20473, command20472, command20463 and command20404 are dated history. C2MZ-204 is applied: byte-identical command20348 artifacts produced zero raw-baseline errors, one owner-specific C4505, then zero errors/zero warnings/no C4505 when compiled with the accepted real `ExpandNode` consumer; all seven original identities remained unchanged.
  - Current manual-coverage identities after supervisor commands `20464`-`20469` are `by-memory/-coverage-report.md` `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4` (`2134111` bytes, `4803` lines), `by-global/-coverage-report.md` `D54B0FBFC043E7822860CB9828896C898BA65EC66B32854CE7F9D191FA066CA1` (`100876` bytes, `218` lines), `by-class/-coverage-report.md` `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10` (`274987` bytes, `625` lines), `by-file/-coverage-report.md` `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66` (`166582` bytes, `319` lines), `by-type/-coverage-report.md` `8FBB3D1070B8B9C531ACB600D5A80FE4407B2DF8984D11BCFD5E6FD2361995FF` (`5246` bytes, `34` lines), `by-type/by-vtable/-coverage-report.md` `5E96D33B2AFEADDB05F9605A4AC0EAC60E30000433D04FFB1E2BBCA0067921D3` (`67631` bytes, `146` lines), `by-type/by-struct/-coverage-report.md` `4D576B5F0F6DE62841F0588BCA9BB710AAF023F6A2C5D68E8C423A10FFF0F7C5` (`59348` bytes, `137` lines), and `by-type/by-template/-coverage-report.md` `1A62AD2DD4F3C6F7BF94CF3BFC2AA3181B0F95601CD9062426402934FC2A1AA9` (`4721` bytes, `30` lines). Physical exact-row readback accounts for all `34` replacements and `14` insertions as applied exactly once; `0` operations remain proposed. No by-global or top-level by-type operation was required, and unrelated concurrent rows remain preserved. DDB43AB5, 34287BEF, F203FD4C, 30D7251B, A5567B78, 34B952A2, and every earlier coverage identity are dated prestates; current UID0002MZ is the accepted literal at line `1488`.
  - Historical command19802 code hashes and compile evidence remain recorded above. Command20473, command20472, command20463, command20404, commands `20384`, `20381`, `20355`, `20207`, `20304`, `20306`, `20172`, `20175`, `20170`, `20160`, `20109`, `20104`, `20024`, `20034`, `19926`, `19933`, `19993`, `19995`, `19928`, `19891`, `19890`, `19887`, `19812`, `19810`, `19805`, and earlier generated/tracker states are dated history. Current bounded generated evidence is command20348 code/memory; command20474 is only the latest observed dated moving tracker checkpoint after B006 de-execution; command20348 Tree.h contains `AppendChild`, and C2MZ-204 direct compilation/readback is complete without modifying those artifacts.

## Implementation Tracking Checklist

### Gate 1 report checks

- [x] Current goal and project skill read.
- [x] Literal 33-section template used.
- [x] Exact 5.6/xHigh provenance present.
- [x] Live MCP remained available; no fallback-only report.
- [x] Target behavior/range/bytes/hash/ABI/caller/xrefs/negatives documented.
- [x] Current ordinary/generated/IDA state and historical prestates documented separately: B7CC899D is the current bounded IDB checkpoint; command20348 owns the generated CPP/H and generated-memory checkpoint; command20474 is the latest observed dated moving checkpoint after B006 de-execution; command20473, command20472, command20463, command20404, commands20384/20381/20355, commands20207/20304/20306, commands20172/20175, and earlier values are explicitly dated history. Tracker authority is therefore deferred to a fresh physical supervisor Gate reread.
- [x] Latest bounded read-only recheck confirms session `f608d7c2` against saved IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, size `143192751`, saved `2026-07-31T06:21:13.3464834-04:00`: A01/A02 accepted names/bool-thiscall declarations/comments remain applied; A03 retains its accepted name/declaration with corrected generic-disabled comment; A04 retains exact name/declaration/first bytes/data-xref/switch state with no new start annotation; U01/U02/U03/U04/U05 remain exact at `0x04/0x0c/0x24/0x0c/0x10`; U00/U06 remain unchanged; method bytes/fences, frames/formals/locals/register roles, collisions, xrefs, literal function/address comment channels, and protected vtable/data identities remain exact; typed decompiles expose `m_storage.m_begin`, `firstChildIndex`, `parentIndex`, `nextSiblingIndex`, `m_begin`, and `disabled`. Current U00-U06 bare declaration readback exposes no type comments, and the current API limitation is explicit. `905D1AB1...604C1` is the exact prestate/backup, `412DA7E8...19CD` is the historical Gate 2B save, and exact bounded chronology is 9F8A, B180, CF188, dated shared `4B5F...`, `1BC3C43B...B6800CFD`, and `5F2679A7...FC79A21`, then the latest B7CC899D target-local reread; CF188, 4B5F, 1BC3, 5F2679, B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, 87D3, A4A6, 6470, 222D, EEF0, plus every earlier snapshot are dated history. The unannotated U02/U03 IDA declaration assumption is historicalized because IDA required analysis-only `__declspec(align(4))` to realize implicit tails without synthetic members.
- [x] Cross-specialization template/payload/source-shape blockers resolved rather than deferred.
- [x] Every proposed formal/support payload is statically coherent with complete `LObject`, pointer-backed `StringBase`, central `RectBounds`, Pane/ScrollablePane/ScrollBar, `EPFTileContext`, exact nested payload/DirectoryEntry, generic `TreeNode<T>`/`.data`, `NodeAt`, generic `Traverse<Visitor>`, and private static paint ownership. The repaired exact-topology header/source harness closes all 35 errors in both modes and maps C4505 to the expansion/sort consumer. The exact UID0000F9 `AppendChild` declaration needed by that consumer is applied and validated under command20252.
- [x] Alternatives ranked and rejected with evidence.
- [x] Exactly 211 uniquely numbered atomic claim/incorporation rows (`C2MZ-001` through `C2MZ-211`) are supplied; every row has one target UID, one claim, one destination, one canonical action (`incorporate`, `historicalize`, or `already-present`), and one current lifecycle state. Current totals are exactly `200 applied`, `11 already-present`, and `0 proposed`; all 48 manual coverage claims, C2MZ-061/079/103/107/111-115/123-125, C2MZ-204, and C2MZ-211 are applied.
- [x] Every directly affected Tree/TreeStorage, traversal, paint, compiler-support, and comparison-only support doc identified by exact UID/path; no undefined helper scope remains.
- [x] Exact target/support score and metadata recommendations supplied.
- [x] Exact formal CPP/H insertion/replacement text is supplied, including literal `#include "LObject.h"` inside the destination-ready Tree formal H payload before `Tree : public LObject`.
- [x] IDA A01 maps one-to-one to `C2MZ-040`: target function rename/type/comment application with exact prestate/action/readback.
- [x] IDA A02 maps one-to-one to `C2MZ-041`: UID0002N1 parent function rename/type/comment application with exact prestate/action/readback.
- [x] IDA A03 maps one-to-one to `C2MZ-042`: UID0002N0 next-visible-sibling function name/type preservation and comment correction with exact prestate/action/readback.
- [x] IDA A04 maps one-to-one to `C2MZ-043`: protected caller no-change/current-state readback with no mutation proposed.
- [x] IDA U00 maps one-to-one to `C2MZ-137`: protected `SimpleUString` no-change/current-state readback; historical regular/repeatable type comments `absent`/`absent`, current regular/repeatable type comments `absent`/`absent`.
- [x] IDA U01 maps one-to-one to `C2MZ-138`: exact `StringBaseWide` create action/readback; historical regular/repeatable type comments `absent`/`absent`, current regular/repeatable type comments `absent`/`absent`.
- [x] IDA U02 maps one-to-one to `C2MZ-139`: exact `FolderTreePaneTreeElem` repair action/readback; historical regular/repeatable type comments `absent`/`absent`, current regular/repeatable type comments `absent`/`absent`.
- [x] IDA U03 maps one-to-one to `C2MZ-140`: exact `FolderTreePaneTreeNode` create action/readback; historical regular/repeatable type comments `absent`/`absent`, current regular/repeatable type comments `absent`/`absent`.
- [x] IDA U04 maps one-to-one to `C2MZ-141`: exact `FolderTreePaneTreeStorage` create action/readback; historical regular/repeatable type comments `absent`/`absent`, current regular/repeatable type comments `absent`/`absent`.
- [x] IDA U05 maps one-to-one to `C2MZ-142`: exact `FolderTreePaneTree` storage-member repair action/readback; historical regular/repeatable type comments `absent`/`absent`, current regular/repeatable type comments `absent`/`absent`.
- [x] IDA U06 maps one-to-one to `C2MZ-143`: protected `TreeItorFolderTreePaneTreeElem` already-present readback; historical regular/repeatable type comments `absent`/`absent`, current regular/repeatable type comments `absent`/`absent`.
- [x] Exactly 48 supervisor-owned manual coverage operations are supplied as one ledger row and one checklist row per operation: `34` replacements and `14` insertions, including the assigned-UID Tree insertion, evidence-backed UID0002MY replacement, six support/source row replacements, three concrete compiler-support row replacements, two vtable row replacements, and two vtable-data insertions; no grouped "remaining" bucket exists. Final bounded readback after commands `000000020464`-`000000020469` finds all `48` exact-applied once and `0` proposed, stale, absent, partial, or duplicate operations under the current coverage identities recorded above. UID0004HM/UID0004ZK/UID0004ZL and updated MiscWorkThread/Thread/Singleton rows remain preserved as explicit no-loss concurrent content. DDB4/3428/F203/D54B/8FBB/30D7/A556/34B9, 485A/9B8B/E717/D42E/B7C1, 5CDC/6C2C/F470/C71E/23D5/AFFD, F36/E40F/30112/EE94, and earlier identities are dated history.
- [x] Report-only hard boundaries were respected before Gate 1; callback hard boundaries were also respected: ordinary docs/report only, no coverage/generated/IDA/supervisor/lifecycle mutation, and no `execute_report`.

### Ordinary implementation callback

- [x] The authorized same-agent callback created/registered/scored `by-file/Tree.md` as UID0004YK, read the UID from page header and validator mapping, and reconciled current ordinary TMP references before H-channel route migration; no UID was hand-assigned and no coverage file was edited (commands `18916`, `19013`).
- [x] UID00007D complete LObject declaration moved to H with CPP children preserved (`18930`).
- [x] UID0001WS complete one-pointer StringBase declaration moved to H with broader API evidence/history preserved (`18933`).
- [x] UID00004I complete EPFTileContext declaration moved to H with CPP children preserved (`18934`).
- [x] UID0002MZ metadata/prose/history/formals applied (`18965`).
- [x] UID00005A class declaration moved from CPP to exact H and node/payload prose/history applied without changing score/route (`18957`).
- [x] UID0001WP template/header model applied (`18948`).
- [x] UID0000FC generic node/storage declaration and prose/history applied (`18949`).
- [x] UID0000F9 base Tree declaration/prose/history applied (`18950`); the later-discovered separate `AppendChild` declaration is applied and validated under focused callback command `20252`.
- [x] UID0000FB iterator declaration/prose/history applied (`18951`) and closure pass `19191` gave it ordered H/CPP children; the then-missing UID00036L/00036M mappings were registered by `19214`/`19216`.
- [x] UID0001UJ H remains blank as the non-duplicating nested-type route, its CPP is the exact no-duplicate trace, and its exact 12-byte payload declaration is emitted once through UID00005A H (`18952`, `19196`).
- [x] UID000155 core inventory/item-summary/current-source terminology reconciled; metadata and blank formals preserved (`18996`).
- [x] UID000344 exact node/payload-aware CPP block and corresponding prose/history applied with score/route preserved (`18975`).
- [x] UID000345 exact node/payload-aware CPP block and corresponding prose/history applied with score/route preserved (`18976`).
- [x] UID000346 exact node/payload-aware CPP block and corresponding prose/history applied with score/route preserved (`18977`).
- [x] UID000347 exact node/payload-aware CPP block and corresponding prose/history applied with score/route preserved (`18979`).
- [x] UID00034H exact node/payload-aware paint CPP and prose/history applied with score/route preserved (`18980`).
- [x] UID0002MV marker/prose/history corrected to full-node support with metadata preserved (`18987`).
- [x] UID0002MW marker/prose/history corrected to full-node support with stable path and no-standalone-body disposition preserved (`18988`).
- [x] UID0002MX marker/prose/history corrected to full-node support with metadata preserved (`18989`).
- [x] UID00022E inventory/history corrected while its ignored split/index disposition is preserved (`18990`).
- [x] UID000447 marker/prose/history corrected to full-node support with disposition preserved (`18991`).
- [x] UID000449 marker/prose/history corrected to full-node support with disposition preserved (`18992`).
- [x] UID00044B marker/prose/history corrected to full-node support with disposition preserved (`18993`).
- [x] UID000343 bounded 12-byte-versus-36-byte comparison terminology/history correction applied with metadata/formals/route preserved (`18998`).
- [x] UID000348 bounded 12-byte-versus-36-byte comparison terminology/history correction applied with metadata/formals/route preserved (`18999`).
- [x] UID00034B bounded 12-byte-versus-36-byte comparison terminology/history correction applied with metadata/formals/route preserved (`19000`).
- [x] UID00034C bounded 12-byte-versus-36-byte comparison terminology/history correction applied with metadata/formals/route preserved (`19001`).
- [x] UID00034E bounded 12-byte-versus-36-byte comparison terminology/history correction applied with metadata/formals/route preserved (`19002`).
- [x] UID00031B bounded 12-byte-versus-36-byte comparison terminology/history correction applied with metadata/formals/route preserved (`19003`).
- [x] UID0002MY corrected concrete reset CPP/prose applied (`18968`).
- [x] UID0002N0 generic H/disabled terminology/history applied (`18966`).
- [x] UID0002N1 metadata/H/prose/history applied (`18967`).
- [x] UID0000JG and UID000157 source-model/inventory/history applied (`18958`, `18997`).
- [x] `by-project-structure/proposed-source-tree.md` received the exact ordered LObject/StringBase/Tree/EPFTileContext/FolderTreePane header insertions and no Tree.cpp (`18959`; only pre-existing missing UID0003LP/0003WL/0003WM/0003WN/0003WO warnings).
- [x] Assigned Tree UID0004YK was read back from both page header and validator mapping; zero current ordinary TMP residue and zero old UID0000JG generic owner/emitter routes were proven.
- [x] Every ordinary lease was acquired only immediately before edit and released immediately afterward; final lease readback has no B003 row.
- [x] The validator manifest contains exactly 92 B003-run scoped records: 73 historical callback/reconciliation records, 17 accepted twelve-group callback records including four no-loss current-prose reconciliation validations for already counted destinations, focused C2MZ-211 command20252, and UID0002LN physical-formal command20385. Every current callback command records exact command, `command_id`, full timestamp, exit/ok, warning/error disposition, and skipped generated refresh; all exited `0` with `ok: 1`.
- [x] UID0001WP/0000FC/0000F9/0000FB emit in deterministic H order `0/10/20/30`; the canonical forward declarations precede every use, command `19225` removed the final duplicate late `TreeItor` declaration from UID0000F9, and command20252 validates the separate exact `AppendChild` member declaration in UID0000F9 formal H.
- [x] UID0002MZ/0002N0/0002N1 and UID0001UJ use exact trace-only CPP comments instead of empty emitters; UID00005A emits `#include "FolderTreePane.h"` before real CPP children.
- [x] UID0002MY/0002MV/0002MX/000447/000449/00044B and UID00034F/000158/00034I/00036K/00036J/00036L/00036M preserve semantic owners while concrete traces route through UID0000JG positions `90` through `210`.
- [x] UID000447/000449/00044B ordinary CPP blocks textually match the accepted report payloads.
- [x] Dated pre-C2MZ-211 read-only command `20172` shows zero `[[No Children Attached]]`, `Empty Emitter Marker`, and `TMP_*` tokens across all seven target artifacts, proves the no-duplicate Tree.h state, and confirms Tree.cpp is validator-owned trace-only output rather than an authored semantic source file. That readback proves Tree.h lacked the required UID0000F9 `AppendChild` declaration before command20252; it remains an incomplete pre-repair generated checkpoint rather than final generated closure.
- [x] Supervisor Gate 2A passed all `43/43` ordinary destinations with zero drift against the frozen pre-Gate2B report artifact.
- [x] Post-Gate2B reconciliation updated the 13 affected ordinary documents, preserved natural source formals, recorded actual analysis readbacks, ran serial validators `19668`, `19673`, `19675`, `19677`, `19681`, `19687`-`19690`, and `19692`-`19695`, and re-read the exact 43-file current manifest.

### Supervisor-only closure

- [x] Historical Gate 1 accepted SHA256 `01EC31D48291FAB439F0C94F98DEAAA0D86B18418BDE26C72B3FF37F799AC001` for the earlier ordinary callback; the later Gate 1 accepted SHA256 `2A501B89521DB4A36EECC0ACC8C01D023255DA02D059E9AEE6CD4C276E6A21F8` and authorized the twelve-destination callback. Gate 2A subsequently found the separate UID0000F9 declaration omission. Focused Gate 1 accepted exact SHA256 `2D4E98BC83704D91F86A3F78D795661048FC4AFEE742497EFC6D8647CBDE1BAF` and authorized only C2MZ-211; command20252 proves that claim applied. This later rejected-closure callback independently applies C2MZ-204 through exact byte-identical direct compilation and revalidates C2MZ-125's canonical UID0002LN physical formal under command20385. Any independent supervisor verification of those records is authoritative only from the corresponding supervisor audit/readback.
- [x] Focused Gate 1 validated exact pre-callback report SHA256 `2D4E98BC83704D91F86A3F78D795661048FC4AFEE742497EFC6D8647CBDE1BAF` and authorized only C2MZ-211; this reconciled artifact is ready for supervisor Gate 2A.
- [x] Compile-owner callback C2MZ-103: UID0000BU emits central exact `RectBounds.h` and its y/x predicate; formal equality verified, validator `20056`.
- [x] Compile-owner callback C2MZ-111 remains independent from manual-coverage claim C2MZ-206: UID0000A2 merges `InvalidateRect(const RectBounds *)` into the complete Pane H declaration; formal equality verified and superseded blank-formal prose historicalized, validators `20058` and `20070`. The current no-loss header-normalized UID0000A2 checkpoint is SHA `E6A7E207...021C91DD`, `30942` bytes / `297` lines, `92/94`, owner/emitter UID0000MC; it preserves the complete Pane ABI and accepted callback payload under `NEXUSTK_UI_CORE_PANE_H` without an invalid H-child attachment token.
- [x] Compile-owner callback C2MZ-113: UID0000CF merges exact ScrollablePane getters, low-word scroll mutator, and `m_contentRect` into complete H; formal equality verified and marker-only prose reconciled, validators `20062` and `20071`.
- [x] Compile-owner callback C2MZ-115: UID0000NF records the complete schema-correct source-root H/CPP dependency contract and rejects the literal no-children placeholder; validator `20066`.
- [x] Compile-owner callback C2MZ-112: UID0001WS declares `DetachWideIfShared` and namespaced `WideRangeCompare` without changing one-pointer layout; formal equality verified and catalog0365 identity made explicitly dated, validators `20060` and `20073`.
- [x] Compile-owner callback C2MZ-114: UID00004I includes central RectBounds and removes its duplicate local record; formal equality verified, validator `20063`.
- [x] Compile-owner callback C2MZ-123: UID00005A declares exact nested DirectoryEntry and private GetNodeBounds; formal equality verified, CPP route/current prose reconciled, and catalog0365 identity made explicitly dated, validators `20064` and `20072`.
- [x] Compile-owner callback C2MZ-107: UID000156 uses RectBounds and explicit unsigned-short scroll conversions; formal equality verified after exact formatting reconciliation, validators `20057` and `20069`.
- [x] Compile-owner callback C2MZ-079: UID000343 calls `mystr::WideRangeCompare`; formal equality verified, validator `20054`.
- [x] Compile-owner callback C2MZ-061: UID000346 uses RectBounds and `ContainsPoint(y, x)`; formal equality verified, validator `20053`.
- [x] Compile-owner callback C2MZ-125: UID0002LN records the namespaced StringBase-header declaration route while its direct H remains physically blank; UID0001WS owns/emits the exact `mystr::WideRangeCompare` declaration in `StringBase.h`. Its physical formal CPP now matches the report's canonical namespace/body payload byte-for-byte, and command `20385` validates SHA256 `2C7DF766...B9B7654A`, `10108` bytes / `127` lines with generated refresh disabled; command20067 is the earlier route validator.
- [x] Applied UID0000JG source callback C2MZ-124: the complete schema-correct source-root CPP assembly with `<wchar.h>` and the evidence-backed expansion/sort consumer is present, and scoped validator command `20068` exited `0` with `ok: 1`.
- [x] Applied UID0000F9 declaration callback C2MZ-211: exact `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);` is present once after the two `NodeAt` overloads and before `protected:`; command `20252` exited `0` with `ok: 1`, generated refresh skipped, and poststate is SHA256 `23E93045...B6EB6D`, `24888` bytes, `173` lines.
- [x] Applied UID0004YK generated/compile closure C2MZ-204: x86 MSVC `19.44.35226` compiled byte-identical copies of all seven exact command20348 target artifacts. The raw baseline exited `0` with zero errors and one C4505 that identified omitted owner `ExpandNode`; the non-suppressed closure containing the accepted real `ExpandNode`/`std::sort(..., DirectoryEntryNameLess)` consumer exited `0` with zero warnings/no C4505. All seven original hashes remained unchanged, all seven temporary copies were byte-identical, and the disposable tree was removed.
- [x] Historical earlier ordinary callback Gate 2A independently verified its 43 accepted destinations, assigned Tree UID/TMP reconciliation, validator results, and no-loss destination state: `43/43`, zero drift. The later twelve-destination Gate 2A found the UID0000F9 dependent omission; command20252 proves the focused repair, while any independent supervisor verification state is authoritative only from supervisor audit/readback.
- [x] Gate 2B A01 applied and read back `C2MZ-040` exactly.
- [x] Gate 2B A02 applied and read back `C2MZ-041` exactly.
- [x] Gate 2B A03 applied the corrected generic-disabled comment and read back `C2MZ-042` exactly.
- [x] Gate 2B A04 independently confirmed protected no-change state from `C2MZ-043` exactly.
- [x] Gate 2B U00 independently confirmed protected no-change state from `C2MZ-137` exactly.
- [x] Gate 2B U01 applied and read back `C2MZ-138` exactly at `0x04`.
- [x] Gate 2B U02 applied and read back `C2MZ-139` exactly at `0x0c`; IDA-only `__declspec(align(4))` realizes implicit tail alignment with no synthetic member.
- [x] Gate 2B U03 applied and read back `C2MZ-140` exactly at `0x24`; `disabled` remains +`0x20`, and IDA-only `__declspec(align(4))` realizes implicit tail alignment with no synthetic member.
- [x] Gate 2B U04 applied and read back `C2MZ-141` exactly at `0x0c`.
- [x] Gate 2B U05 applied and read back `C2MZ-142` exactly at `0x10` with typed storage.
- [x] Gate 2B U06 independently confirmed protected already-present state from `C2MZ-143` exactly.
- [x] Gate 2B saved the IDB only after all eleven entity readbacks passed; catalog `0365` records backup `NexusTK.exe.pre-B003-UID0002MZ-20260729-1505.i64` and historical Gate 2B saved IDB SHA `412DA7E8...19CD`, size `143191140`, saved `2026-07-29T15:00:32.0998001-04:00`; the latest `f608d7c2` bounded read-only verification against `B7CC899D...8058277` confirms no target/dependency/protected-entity drift, while B180, 9F8A, F7, A0D9, 4A, DAA, DADC, 836A, 3892, 4EDEC, and 87D3 are dated history.
- [x] B003 same-report and ordinary-document reconciliation records exact applied Gate 2B/catalog state, preserves historical prestates, and passed serial scoped validators for every ordinary reconciliation edit.
- [ ] Supervisor-owned lifecycle-neutral verification control: Gate 1/Gate 2A/Gate 2B and lifecycle disposition are authoritative only from the supervisor audit/readback and validator-owned status/history metadata. The UID0000F9 ordinary callback, direct compile closure, and all manual coverage operations are complete, and C2MZ-211 proposes no new IDA mutation.
- [x] Applied manual coverage `C2MZ-133`: replaced UID00007D in `by-class/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`.
- [x] Applied manual coverage `C2MZ-135`: replaced UID00004I in `by-class/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`.
- [x] Applied manual coverage `C2MZ-134`: replaced UID0001WS in `by-type/by-template/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020466` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `1A62AD2DD4F3C6F7BF94CF3BFC2AA3181B0F95601CD9062426402934FC2A1AA9`.
- [x] Applied manual coverage `C2MZ-136`: inserted the exact assigned UID0004YK `by-file/Tree.md` row after UID0000OW and before UID0000OX, validate/read back it, and prove zero coverage/generated placeholder/TMP residue. Supervisor command `000000020465` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66`.
- [x] Applied manual coverage `C2MZ-144`: replaced UID000157 in `by-memory/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-145`: replaced UID000155 in `by-memory/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-146`: inserted UID000343 in `by-memory/-coverage-report.md` in exact address order and validate/read back the row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-147`: replaced UID000344 in `by-memory/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-148`: replaced UID000345 in `by-memory/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-149`: inserted UID000346 in `by-memory/-coverage-report.md` in exact address order and validate/read back the row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-150`: inserted UID000347 in `by-memory/-coverage-report.md` in exact address order and validate/read back the row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-151`: replaced UID0002MV in `by-memory/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-152`: inserted UID000348 in `by-memory/-coverage-report.md` in exact address order and validate/read back the row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-153`: inserted UID00034B in `by-memory/-coverage-report.md` in exact address order and validate/read back the row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-154`: inserted UID00034C in `by-memory/-coverage-report.md` in exact address order and validate/read back the row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-155`: inserted UID00034E in `by-memory/-coverage-report.md` in exact address order and validate/read back the row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-156`: replaced UID0002MW in `by-memory/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-157`: replaced UID0002MX in `by-memory/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-158`: inserted UID00031B in `by-memory/-coverage-report.md` in exact address order and validate/read back the row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-159`: replaced UID00034H in `by-memory/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-173`: replaced the stale current UID0002MY row in place after UID00034H and before UID0002MZ with the exact node/payload-reconciled literal row, then validate and read it back. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-048`: replaced UID0002MZ in `by-memory/-coverage-report.md` between UID0002MY and UID0002N0 and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-160`: replaced UID0002N0 in `by-memory/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-161`: replaced UID0002N1 in `by-memory/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-162`: replaced UID00022E in `by-memory/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-163`: inserted UID000447 beneath UID00022E in exact child-address order and validate/read back the row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-164`: inserted UID000449 beneath UID00022E in exact child-address order and validate/read back the row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-165`: inserted UID00044B beneath UID00022E in exact child-address order and validate/read back the row. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-166`: replaced UID00005A in `by-class/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`.
- [x] Applied manual coverage `C2MZ-167`: replaced UID0000F9 in `by-class/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`.
- [x] Applied manual coverage `C2MZ-168`: replaced UID0000FB in `by-class/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`.
- [x] Applied manual coverage `C2MZ-169`: replaced UID0000FC in `by-class/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`.
- [x] Applied manual coverage `C2MZ-170`: replaced UID0001WP in `by-type/by-template/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020466` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `1A62AD2DD4F3C6F7BF94CF3BFC2AA3181B0F95601CD9062426402934FC2A1AA9`.
- [x] Applied manual coverage `C2MZ-171`: replaced UID0001UJ in `by-type/by-struct/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020467` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `4D576B5F0F6DE62841F0588BCA9BB710AAF023F6A2C5D68E8C423A10FFF0F7C5`.
- [x] Applied manual coverage `C2MZ-172`: replaced UID0000JG in `by-file/-coverage-report.md` and validate/read back the exact row. Supervisor command `000000020465` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66`.
- [x] Applied manual coverage `C2MZ-197`: replaced UID00034F in `by-memory/-coverage-report.md` with the exact current UID0000JG position-150 route row and validate/read it back. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-198`: replaced UID000158 in `by-memory/-coverage-report.md` with the exact concrete consumer-route row and validate/read it back. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-199`: replaced UID00034I in `by-memory/-coverage-report.md` with the exact UID0000JG position-170 route row and validate/read it back. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-200`: inserted the formerly absent UID00036K beneath UID00025C before the current `0x0061a5c4` ignored row in `by-memory/-coverage-report.md`, then validate/read it back. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-201`: replaced UID00036J in `by-type/by-vtable/-coverage-report.md` with the exact score/route row and validate/read it back. Supervisor command `000000020468` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `5E96D33B2AFEADDB05F9605A4AC0EAC60E30000433D04FFB1E2BBCA0067921D3`.
- [x] Applied manual coverage `C2MZ-202`: replaced UID00036L in `by-type/by-vtable/-coverage-report.md` with the exact score/route row and validate/read it back. Supervisor command `000000020468` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `5E96D33B2AFEADDB05F9605A4AC0EAC60E30000433D04FFB1E2BBCA0067921D3`.
- [x] Applied manual coverage `C2MZ-203`: inserted the formerly absent UID00036M immediately after UID00036K in `by-memory/-coverage-report.md`, then validate/read it back. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-205`: replaced UID0000BU in `by-class/-coverage-report.md` with the exact central-RectBounds declaration/source-route row and validate/read it back. Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`.
- [x] Applied manual coverage `C2MZ-206`: replaced the formerly stale UID0000A2 `90%` row in `by-class/-coverage-report.md` with the exact `92%` no-loss complete-Pane-interface/family-wide-ABI row above and validate/read it back; this manual operation does not alter or absorb independently applied C2MZ-111. Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`.
- [x] Applied manual coverage `C2MZ-207`: replaced UID0000CF in `by-class/-coverage-report.md` with the exact complete-ScrollablePane-interface/layout row and validate/read it back. Supervisor command `000000020464` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `0D70963D727D3F6279410D52EEEAC2499F6B2C0109087829CAEBB4EF35651D10`.
- [x] Applied manual coverage `C2MZ-208`: replaced UID0000NF in `by-file/-coverage-report.md` with the exact complete ScrollBar header/source assembly row and validate/read it back. Supervisor command `000000020465` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `2AC15CEC42D5D2532EB360C67C7145B32738FDE1876BF56BC4F638DBB3761B66`.
- [x] Applied manual coverage `C2MZ-209`: replaced UID000156 in `by-memory/-coverage-report.md` with the exact RectBounds/unsigned-scroll-ABI SetSelection row and validate/read it back. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] Applied manual coverage `C2MZ-210`: replaced UID0002LN in `by-memory/-coverage-report.md` with the exact namespaced StringBase-header WideRangeCompare row and validate/read it back. Supervisor command `000000020469` exited `0` with `ok:1`, generated refresh skipped, and exact readback passed under SHA256 `80A6D72EF126BE84FDD242ABFDD10EBB578AF4EEEDE6106CB36E2EAB77DC7FD4`.
- [x] All 48 manual coverage operations (`34` replacements and `14` insertions) are independently accounted for, validated, and exact-readback-verified; `48` are applied and `0` remain proposed, with no grouped "remaining" operation or silent omission.
- [x] Generated command `20348` records the seven exact CPP/H artifacts and generated-memory state under SHA `C2D261C9...8D791C`, `1428860` bytes / `4978` lines; UID0002MZ remains at line `910` through UID0000FB/position 40, and Tree.h line `70` contains `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);`. Latest observed dated moving tracker command `20474` records UID0002MZ at line `2908`, `91/93`, average `92.0`, reconstructable true, coverage `0/0/0`, under SHA `DA136172...B4E610`, `1690530` bytes / `6676` lines; command20473, command20472, command20463, command20404, commands20384/20381/20355, commands20207/20304/20306, commands20172/20175, 20170, 20160, 20109, 20104, 20024/20034, 19995/19993/19928, 19890/19891, and commands `19887`, `19812`, `19810` plus earlier checkpoints are dated history.
- [x] Dated source-code artifact checkpoint `20172` passes readback for assigned-UID owner/emitter routes, expected LObject.h/StringBase.h/Tree.h/EPFTileContext.h/FolderTreePane.h/.cpp outputs, and zero target-family TMP/placeholder residue; it also proves UID0000F9's `AppendChild` declaration was absent before command20252. Command19802 is the exact older compile baseline.
- [x] Command `20172` Tree.h readback has forward declaration order `TreeNode`, `TreeStorage`, `Tree`, `TreeItor`; `Tree<T>` is declared before every use; `TreeStorage<T>` is complete before `Tree<T>`; and no duplicate late Tree/TreeItor declaration remains. Its exact missing declaration was `TreeItor<T> AppendChild(TreeItor<T> *parent, const T& value);`; command20252 validates that declaration in ordinary UID0000F9, command20348 materializes it in generated Tree.h line `70`, and C2MZ-204 now directly compiles the byte-identical generated set plus the accepted real consumer closure.
- [x] Command `20172` FolderTreePane.cpp readback preserves the accepted source-root/comparator consumer and target-family ordering reflected in the exact artifact manifest above.
- [x] Command `20172` Tree.cpp readback is validator-owned trace-only output with no semantic definition and no placeholder; the human source topology remains header-only Tree.h because the current generator contract materializes a companion CPP for every valid by-file root.
- [x] Command `20172` readback finds zero `[[No Children Attached]]`, `Empty Emitter Marker`, and `TMP_*` tokens across all seven target artifacts.
- [x] Direct x86 `cl /Zs /Za` passes exited `0` for exact historical command-19802 LObject.h, StringBase.h, Tree.h, trace-only Tree.cpp, and EPFTileContext.h; their hashes were unchanged before/after. The repaired exact-topology harness closes all 35 mapped errors. The final C2MZ-204 preflight uses the post-UID0000F9-repair command20348 generated set, not command20172's incomplete Tree.h.
- [x] Disposable exact-header UID0002MZ harness exits `0` under `/Za` and explicit `/std:c++14 /permissive-`, instantiates `TreeItor<FolderTreePane::TreeElem>::MoveToFirstChild()`, and proves x86 sizes 4/12/36/12/16/12; all temporary files were removed.
- [x] Every one of the 35 FolderTreePane errors is classified and closed in the repaired exact-topology harness by C2MZ-061/079/103/107/111-115/123-125; no residual broad dependency bucket exists. The exact command20348 raw baseline C4505 identifies the omitted expansion/sort owner, while the accepted UID0000JG real `ExpandNode` consumer closure compiles with zero warnings/no C4505; command20252 validates UID0000F9's dependent `AppendChild` declaration and command20385 validates UID0002LN's canonical physical formal. No known ordinary callback omission remains.
- [ ] Supervisor-owned lifecycle-neutral verification control: the eleven applied support claim groups, UID0000JG's applied source-root contract, UID0000F9's applied C2MZ-211 declaration, completed compile evidence, and completed manual coverage transaction are available for independent supervisor readback; its result is authoritative only from the supervisor audit.
- [x] All seven exact command20348 post-repair LObject.h/StringBase.h/Tree.h/Tree.cpp/EPFTileContext.h/FolderTreePane.h/FolderTreePane.cpp artifacts were consumed under the strongest available x86 C++03-compatible MSVC preflight. The raw byte-identical baseline exited `0` with zero errors and one precise C4505 because generated FolderTreePane.cpp omits `ExpandNode`; the non-suppressed accepted real owner/consumer closure exited `0` with zero errors, zero warnings, and no C4505. Seven pre/post original hashes were unchanged, `BYTE_IDENTICAL_COPIES=7`, and all temporary files were removed.
- [x] Report body is lifecycle-neutral: the physical report path, validator-owned status/history metadata, and supervisor readback rather than report prose or checklist state are authoritative for Gate review, execution, and archive disposition. Historical operation-time wording preserved inside the 48 exact manual-coverage payloads is explicitly historical and does not assert current workflow state.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000020545","destination_path":"executed-b-agent-research/B003/0002MZ-FolderTreeIteratorMoveToFirstChild-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002MZ-FolderTreeIteratorMoveToFirstChild-source-quality.md","timestamp":"2026-08-01T05:58:17-04:00","uid":"0002MZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
