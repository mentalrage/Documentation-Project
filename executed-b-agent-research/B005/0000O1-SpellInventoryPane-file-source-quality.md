
# UID0000O1 SpellInventoryPane Whole-File Source-Quality Audit
** TARGET-REPORT-UID:0000O1 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation
- Current recommendation: reconstruct `NexusTK/ui/inventory/SpellInventoryPane.cpp` and its required sibling `SpellInventoryPane.h` as one compilation unit containing legacy `SpellInventoryPane` and `SpellInventoryPane2` only.
- Final disposition: keep UID0000O1 as the file root; keep UID0000DN and UID0000DO as the two emitting class owners; convert broad legacy island UID0002RI to a non-emitting split/index; retain Pane2 split/index UID0002RK and compiler island UID0002RL as non-emitting; exclude separately owned `NewSpellInventoryPane` UID0000LU and `ScrollSpellInventoryPane` UID0000NJ.
- Callback disposition: B005 physically applied and scoped-validated C-O1-001 through C-O1-050 and C-O1-053 across the accepted ordinary by-* destinations. C-O1-026 is complete in UID00044D and its validator-owned generated CPP readback. C-O1-051 IDA, C-O1-052 manual coverage, and C-O1-054 independent supervisor generated verification remain proposed.
- Artifact-hygiene disposition: no `0000O1-SpellInventoryPane-file-source-quality-removed.md` companion is present, no trustworthy verbatim source for one was found, and none is created or claimed by this report. The active report itself contains only formal `cpp` and inert `text` fences and zero executable-language scripting.
- Confidence: high for ownership, ranges, behavior, two-class layout, vtable/resource mapping, and source routing; medium-high for stripped original helper spellings and the zero-direct-xref constructor entry routes.

## Supporting Research
- Authored-phase history (`2026-08-22`): B005 produced this artifact under a report-only assignment and made no ordinary implementation change. This dated fact is not current lifecycle authority; execution/archive truth derives only from the artifact's physical path plus validator-owned status/history metadata.
- Callback history (`2026-08-22`): exact report SHA256 `8DFCC55A2831862D24619111F482B6B590AE85C78A9515A4D0B6289279FCC194` passed Gate 1 and authorized the same B005 to apply the accepted ordinary implementation. The callback changed only the report and named ordinary by-* destinations; IDA, manual coverage, generated output, audit/catalog/tracker, lifecycle, registry, and archive state remained outside B005's direct-edit authority.
- Gate 2 history (`2026-08-22`): supervisor Gate 2A passed. Gate 2B used canonical SHA256 `A4A6CF1D81D595DD7265F05183D92D977BF141688C1EB91E23970C6920C55C28` and unmutated working session `supervisor_uid0000o1_gate2b_20260822_1134`; it failed closed at the M01 literal-type prestate before UDT declaration or any mutation/save. That failed transaction must not be promoted or reused for mutation.
- Deterministic-frame repair history (`2026-08-22`): exact report SHA256 `F98A4ED9B035CF710693FD4935176C985DFBC64D5C28392A2EB8D0F429A602E5` failed fresh Gate 1 because M03/F03 and M14/F14 allowed alternative post-type frames and R01-R09 deferred future D01-D09 discovery. That repair selected return-address-only F03/F14 predictions and narrowed every raw row to no action. The later unsaved physical M03 transaction disproved only the return-address-only prediction; the old prediction is retained solely as dated failed history.
- Mixed-session/constructor repair history (`2026-08-22`): exact report SHA256 `608DD9412771CD80ABFFD6D53BC33C8F8DC8B1961BFDA138F601A31126152650` failed fresh Gate 1 because M05's current value was attributed to the wrong session and UID00044D omitted `m_isLastPage(false)` despite the observed 16-bit zero store at `this+0xf8`. That report-only pass returned C-O1-026 to a later ordinary callback.
- C-O1-026 callback history (`2026-08-22`): exact report SHA256 `87C4B1598D35F33D3455893C46857FE69D1E697FFEA0D785A0116CC8C05233F6` passed fresh Gate 1 and authorized only the same-B005 UID00044D implementation callback recorded below.
- Isolated U01 failure history (`2026-08-22`): transaction `UID0000O1-20260822-225300000`, session `supervisor_uid0000o1_gate2b_20260822_2253`, passed runtime/path/prestate checks. Its one combined U01 declaration produced the correct `0x100` layout and offsets but materialized `m_spellEffect@0xfc/4` as nested `struct SpellInventoryPane::InterfaceEfx *`, while global `InterfaceEfx` remained absent. The supervisor stopped before U02, M01-M21, N01, or save and discarded the isolated worker. Canonical and working-copy disk receipts both remained SHA256 `0180129575CC0E3E0789AD16556A16BF7725101C9C5418834F8483B5DF7A6D09`, `143,211,331` bytes; neither artifact contains the failed in-memory U01 result.
- Named-function-declarator failure history (`2026-08-22`): exact report SHA256 `2F2C01D613AAFEC3EF76EFFB8A8BA1923CCAC9B34C256E7B29EF53A161F64300` passed fresh Gate 1 and Gate 2A. The next isolated Gate 2B attempt passed every precondition and exact U01.a/U01.b/U02 readback; M01's pure rename succeeded only in the disposable session, then `set_type(kind:function)` rejected anonymous payload `SpellInventoryPane *__thiscall(SpellInventoryPane *this)` as `Not a function type`. The supervisor stopped before M01 prototype mutation, recompile, comment, M02-M21, N01, or save. The unsaved disposable rename is rejected history and supplies no persisted/current-state credit.
- Five-claim Gate 2A repair history (`2026-08-23`): exact report SHA256 `B853DB8D18DFFA99F6BF053DA59AD2F2FE4DA69675D94DE583EB9ABA240EF445` passed fresh Gate 1, then Gate 2A failed only C-O1-004/C-O1-005/C-O1-008/C-O1-010/C-O1-053 because four active ordinary pages retained nonexistent `class_*`/`simroot_v2` current routes and UID0000DO prose retained old UID0002RK/UID0001IH scores. The supervisor's independent generated check found C-O1-054 physically passable but left that row supervisor-owned. This additive callback repaired only those five ordinary claims and their report receipts.
- Physical-frame Gate 2B failure history (`2026-08-23`): exact report SHA256 `BE793B5E3C8BD76F915B04AC45F6ACD2AA9D82C18793E7CCCCA2407D4DAA52D0` passed fresh Gate 1 and Gate 2A. In a fresh unsaved transaction, U01.a/U01.b/U02 and all prestates passed; M01/M02 completed rename/type/recompile/comment; M03 completed rename, accepted the exact named type, recompiled, and normalized the exact semantic type. Its physical frame became `__return_address@0x0/4:_UNKNOWN *; activationData@0x4/4:const unsigned __int8 *`. The supervisor stopped before M03 comment, M04-M21, N01, save, or promotion. The 14 successful primitive mutation calls in that stopped prefix are rejected unsaved history, not current-state or completion credit. Canonical remains SHA256 `0180129575CC0E3E0789AD16556A16BF7725101C9C5418834F8483B5DF7A6D09`, `143,211,331` bytes.
- F11/F20 physical-frame Gate 2B failure/probe history (`2026-08-23`): exact report SHA256 `85717ADD12507DB3F660AF061FD0D59E0093D087B0765AD9C96203D373350B63` passed fresh Gate 1 and Gate 2A. Strict transaction `UID0000O1-20260823-173839262-strict`, session `supervisor_uid0000o1_gate2b_strict_20260823_173839`, passed U01.a/U01.b/U02 and M01-M10 only in unsaved isolated memory. At M11, exact named type application produced entity `SpellInventoryPane__HitTestSpellRow` and public type `__int16 __stdcall(int y, int x)`, while the physical frame preserved `row@0x28/0x4:int; column@0x2c/0x4:int`. A supervisor batching-order defect also applied M11's comment in disposable unsaved memory before the batch surfaced that mismatch; the comment and the entire M11 batch receive no evidence, implementation, or persistence credit. Independent no-comment probe `supervisor_uid0000o1_f11_probe_20260823_1756` reproduced the exact M11 entity/public type and preserved physical frame with every comment channel blank. Independent no-comment probe `supervisor_uid0000o1_f20_probe_20260823_1759` at `0x57f490` produced entity `SpellInventoryPane2__HitTestSpellRow`, the same public type, the same preserved physical `row`/`column` frame, and blank comments. These independent probes are authoritative; the former physical-`y`/`x` prediction is dated rejected history only. Canonical, backup, and working files all remained SHA256 `0180129575CC0E3E0789AD16556A16BF7725101C9C5418834F8483B5DF7A6D09`, `143,211,331` bytes; no save or promotion occurred.
- Destination-contract Gate 2A history (`2026-08-23`): exact report SHA256 `310CF895E3DD8E9CA87E50758AFEBDE13793BC8FD3D73337AD1637555E443A94` passed fresh Gate 1, then Gate 2A returned `35 PASS`, `18 FAIL`, and two `OUTSIDE`. All 28 ordinary-file hashes and all formal/generated source passed; the 18 failures were limited to checked destination cells naming absent or historically superseded H2 headings. This callback adds the required active nonhistorical UID0001IH generated-route paragraph and reconciles only C-O1-002/003/004/005/007/008/013/026/028/029/034/036/037/038/039/045/049/050 to exact physical active headings.
- Six-claim Gate 2A repair history (`2026-08-23`): exact report SHA256 `BF0A9B4BD7D57D46348D72220DE345146177D59BB2BF8C0689263593152844DB` failed fresh Gate 2A only on C-O1-004/C-O1-005/C-O1-006/C-O1-007/C-O1-028/C-O1-034. The failures were active stale Source Route, field/name/type/source-placement, malformed global-header, and inbound child-label contracts; the other 46 claims passed and three remained outside. This bounded callback repairs only those six ordinary contracts and their report twins/receipts.
- Three-claim Gate 2A repair history (`2026-08-23`): exact report SHA256 `4325732A854A5F7D1D3839D13987C47FCFAECFD2C526E9F6D64B1DB2C74A0120` passed fresh Gate 1, then Gate 2A returned 49 checked claims PASS, exactly C-O1-004/C-O1-006/C-O1-032 FAIL, and three supervisor-owned claims OUTSIDE. The failures were limited to UID0001IH's overbroad historical-snapshot scope, stale active legacy dispatcher/mapper names, UID00044J's stale `PaneKeyEvent` type note, and directly related UID0002RK event/message and active `94/95` score prose. This bounded callback repairs only those ordinary contracts and their report twins/receipts.
- Goal read: `tools/leaser/Agents/Agent-B005/goal.md`, SHA256 `29EFA33AFD0D1F0D83F4B16737CF458E0D199EC2A0E8D0CF54E554BA45ED169B`.
- Missing-companion search (`2026-08-22`): an exact-name recursive search under `E:\NTK\GhidraBridge`, a report-stem inventory under project documentation, and bounded B005/audit searches found the active report but no target `-removed.md`, backup, or trustworthy verbatim payload. Unrelated SpellInventoryPane-family companions belong to other reports and are not evidence for UID0000O1. No companion is restored or invented.
- Existing report searches used the terms `SpellInventoryPane`, `SpellInventoryPane2`, `SpellInventoryPanes`, `0x0057c2d0`, `0x0057ea60`, `0000O1`, `0002RI`, `0002RK`, and `0001IH`. Matching executed reports were B007 UID0002RI, B008 UID0002RK, B010 UID0002RL, B011 UID0001IH, B009 UID0000LU, B003 UID0000NJ, and the B001 UID0000KA `InventoryPane` whole-file analogue. They were treated as leads and rechecked against the current IDB and current files.
- Authored-phase MCP history used a target-unrelated preserved IDB copy read-only. The complete U/M/F/R/D/N/P matrices remain the live read-only results from the single canonical session `supervisor_uid0000ih_canonical_verify_20260822_1450` at exact path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; no value from either failed UID0000O1 transaction is part of those matrices. This U01 repair separately reread only declaration-scope evidence from healthy canonical read-only session `supervisor_uid0000mm_canonical_verify_20260822_1745`: both target UDTs, global `InterfaceEfx`, and both nested `SpellInventoryPane::InterfaceEfx`/`SpellInventoryPane2::InterfaceEfx` were absent. A future Gate 2B attempt must open/attest a distinct fresh authorized transaction.

## Target
- Target UID: `0000O1`.
- Additional target UIDs: none.
- Declared-target inventory: only `source-3/project-documentation/by-file/SpellInventoryPane.md` is a declared report target. All other UIDs below are support pages or excluded siblings, not additional declared targets.
- Target path: `source-3/project-documentation/by-file/SpellInventoryPane.md`.
- Assignment-time queue/report row (`2026-08-22`): `auto-generated/-ag-research-tracker.md` `## by-file` / `### Not-Covered Files - Not Reconstructable`, first eligible blank-reconstructable metadata row at `88/89`, zero direct/additional reports when assigned.
- Authored-phase supervisor classification (`2026-08-22`): report-only whole-file inventory/reconstruction audit. This is dated assignment history, not current lifecycle authority.
- Report-time ordinary-document scores and parent state: UID0000O1 `88/89`, file owner; UID0000DN `85/88`, owner/emitter UID0000O1; UID0000DO `89/90`, owner/emitter UID0000O1; UID0002RI `88/89`, reconstructable/empty-emitting through UID0000DN at evidence time; UID0002RK `90/92`, non-emitting split/index; UID0002RL `91/93`, compiler-only/non-emitting; UID0001IH `87/90`, broad non-emitting split/index.
- Inferred compilation-unit boundary: legacy `[0x0057c2d0,0x0057cf6b)` excluding embedded shared helper `[0x0057c430,0x0057c440)`, Pane2 `[0x0057ea60,0x0057f58b)`, their compiler-generated vtable/destructor support, and source resource literals. Physical adjacency alone does not include NewSpell `[0x0057cf70,0x0057ea57)` or ScrollSpell `[0x0055f450,0x005608fc)` because their independent file audits, class routes, constructors, and generated files establish separate compilation units.

## Current Target State
- Callback metadata readback: UID0000O1 is `93/94`; UID0000DN and UID0000DO are `93/94` emitters at positions `010` and `020`; UID0002RI is `92/94`, reconstructable false, and non-emitting; UID0002RK is `94/95`; UID0001II is `92/94`; UID0001IH is `91/94`. The by-file root retains `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/"` and `CANONICAL_OWNER:FILE`.
- Callback owner/emitter readback: the two classes route to UID0000O1; source-bearing Pane2 children UID00044D-UID00044G and UID00044I-UID00044S route through UID0000DO at positions `100` through `240`; UID00044H remains source-empty/non-emitting; UID0002RI, UID0002RK, UID0002RL, and UID0001IH are non-emitting inventory/compiler pages.
- Report-time generated snapshot (`2026-08-22T06:16:15-04:00`): validator command `000000026432` had produced `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` at SHA256 `5D813A7128887DE101E7A8C9D8DEE3954913398DF087360653B5D36240E6FEF9`, `9,092` bytes, and `305` LF lines. That dated file began directly with Pane2 child definitions, had no include/preamble or legacy definitions, used unprovided `PaneKeyEvent`, `PaneMouseEvent`, `PaneMessage`, `EpfFrame`, and wrapper APIs, conflated the 13-entry page with the 10-row hit-test, and ended with empty-emitter markers for UID0000DN, UID0002RI, and UID0000DO. This snapshot is historical evidence only; supervisor Gate 2A subsequently established mutable generated CPP/H authority.
- Historical callback generated readback: scoped validator command `000000026502` refreshed `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` and `.h` at `2026-08-22T10:59:56-04:00`. B005's structural readback found 30 definitions, two class declarations, complete emitter ordering, and no marker/stub pollution, but it did not detect UID00044D's missing `m_isLastPage(false)` initializer. The later Gate 2A pass is therefore historical and is not proof for the corrected C-O1-026 state.
- Gate-1-current command-`000000026517` generated evidence (`2026-08-22`, physically reread `2026-08-22T16:28:27Z`): `SpellInventoryPane.cpp` was 19,341 bytes, 622 LF/zero CRLF, terminal LF, SHA256 `2F56C88DB020C4B5961715F392873C072B142702500046FBD3D1A7ED7ED72281`; `SpellInventoryPane.h` was 2,886 bytes, 81 LF/zero CRLF, terminal LF, SHA256 `3803D2B8A1037377CFEDE150CD8C633D3C0ADD3D9A6DD03596EA4384C475CE50`. The CPP constructor contained only `m_pageIndex(0)` and `m_spellInputActive(false)`, proving the later C-O1-026 ordinary callback was required. This command-26517 receipt is dated evidence only.
- Pre-callback shared generated-state observation: another validator-owned refresh retouched both files at `2026-08-22T16:38:37Z` while B005 held only the report lease. The then-current read-only hashes became CPP `894C0E7525331BBD7AAC1AE9E17EB6D897F09895FBADF32197A568F3C95A43B9` and H `252839F0CF44D3A141D20257831029482709665383B6A02613443A9D4456EC66` with the same sizes/LF counts; the CPP still omitted `m_isLastPage(false)`. This external touch is historical and is not attributed to command 26517.
- Historical C-O1-026 callback generated readback: scoped validator command `000000026749` completed its deferred validator-owned refresh before the physical `2026-08-22T19:20:17Z` readback. `SpellInventoryPane.cpp` was SHA256 `A94AFDFA1B464ACE9D69185DE134D05EB3BF1BA1322B77A94749F7AB99A20548`, 19,366 bytes, 623 LF/zero CR, terminal LF, last-write `2026-08-22T19:20:17.1513748Z`; `SpellInventoryPane.h` was SHA256 `AA3F04FD457BDEF5D650A4EDB9FC7E4DC3E8344E30084AE856CA43E8ED12D207`, 2,884 bytes, 81 LF/zero CR, terminal LF, last-write `2026-08-22T19:20:17.1863790Z`. CPP lines 350-353 contained `m_pageIndex(0)`, `m_isLastPage(false)`, and `m_spellInputActive(false)` in order. Whole-file CPP/H scans found zero empty-emitter markers, stubs, TODO placeholders, `sub_`, `dword_`, `nullsub_`, `unk_`, or raw `aN`/`vN` decompiler names attributable to that callback.
- Historical shared generated-state observation: a later validator-owned `2026-08-22T19:24:18Z` refresh retouched the same files without B005 direct edits, producing CPP SHA256 `977A6C2B497ECD66FEFB8300F7C00CBB7CB39F23102462793E02F139E8131B5A`, 19,368 bytes, 623 LF/zero CR, and H SHA256 `4035174A0DA3153EFB578EA0EE5284DDB103F642E8EDF8C755E9E479745E97E6`, 2,886 bytes, 81 LF/zero CR. This dated receipt is no longer mutable current authority and does not replace command 26749's historical callback receipt.
- Post-five-claim generated proof (`2026-08-23`, command `000000027000` stamped `2026-08-22T20:21:09-04:00`): validator-owned `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` is SHA256 `1EA8A504A0070AF27A119B426A61AE3E27F240167F2351C59330AABF9D5685E3`, 19,368 bytes, 623 LF/zero CR, terminal LF; sibling H is SHA256 `153F551023CAD35C6CC6A79EF325D6A4287419D7EAC81E239C9D9C13AF570967`, 2,886 bytes, 81 LF/zero CR, terminal LF. Mechanical readback found exactly 30 definitions in the required 15-legacy/15-Pane2 order; one global `class InterfaceEfx;`; one complete `SpellInventoryPane` and one complete `SpellInventoryPane2` declaration; one size-`0x100` assertion for each; the corrected three-initializer Pane2 constructor; and zero NewSpell/Scroll definitions, `[[CHILDREN]]`, empty-emitter markers, placeholders, TODO/FIXME/stub text, or `sub_`/`dword_`/`nullsub_`/`unk_`/raw `aN`/`vN` pollution. This is a dated validator/readback receipt; the supervisor must reread mutable generated authority at each fresh gate.
- Five-claim ordinary repair: UID0001IH, UID0000DN, UID0000DO, and UID0000O1 now distinguish the canonical `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp`/`.h` route from explicitly historical nonexistent `class_*`/`simroot_v2` paths. UID0000DO's active support prose now reads UID0002RK `94/95` and UID0001IH `91/94`. NewSpell/Scroll exclusions, UID00044F `OnActivate`, UID00044L `OnServerMessage`, all five exclusive-end paths, 13-entry page versus ten-row hit-test behavior, and UID0001II source-level `void` remain present in their exact ordinary destinations.
- Destination-contract repair readback: NewSpell/Scroll exclusions reside in each file's active `## UID0000O1 Exclusion Cross-Reference - 2026-08-22`; legacy/Pane2 size-layout facts reside in their active accepted-class headings plus `## Field Notes` / `## Field And Split Notes`; UID0001II behavior resides in its accepted-helper heading plus `## Function`; C-O1-013 uses physical `## Method Notes`; C-O1-026 uses physical `## Source Reconstruction Notes`; the five corrected raw ends reside in each child's active `## UID0000O1 Accepted Exact Range...` heading; broad path/ownership facts reside in active `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22`, `## Source Route Table`, and `## Ownership Decision`; and resource/dependency/no-global facts reside in active `## UID0000O1 Accepted Whole-File Reconstruction - 2026-08-22`. No detail was deleted or redirected to implicit/scattered prose.
- Post-destination validator/readback (`2026-08-23`): scoped command `000000027148` validated only UID0001IH and completed generated refresh with `ok:1`. The ordinary page is SHA256 `1A07DB4A361A34F9E971504B0D5E86922DEEA4995E060B2A55148D3D8704446C`, `34,277` bytes, `175` LF, with 12 H2 headings and exactly one active canonical generated-route paragraph under the accepted split heading. The other 27 ordinary hashes remain exact. A subsequent validator-owned shared refresh stamped generated CPP/H command `000000027149`; physical readback preserved 30 definitions in 15/15 order, both size guards, one global `class InterfaceEfx;`, both three-initializer constructors, and zero pollution. Generated files remain read-only mutable gate evidence, not B005 edits.
- Six-claim ordinary repair readback (`2026-08-23`): UID0001IH `## Source Route Table` now says legacy and NewSpell exact children are already selected/emitted; UID0000DN `## Field Notes` and UID0002RI `## Field And Global Interpretation`/`## Reconstruction Notes` use `m_pageIndex`, `OnActivate`, `m_isLastPage`, and `InterfaceEfx *m_spellEffect` while explicitly historicalizing rejected alternatives; UID0000DM formal H now declares `SpellInputPaneState::SetInputModeFlag(bool)` as a class member with the proven `+0xfa` field behind an opaque prefix; UID0002RK `## Accepted Current Implementation Path`/`## Cross-References` use `OnActivate` and `OnServerMessage` and preserve old labels only as rejected history. The goal-supplied `by-memory/0x004ce000-0x004d071d.SpellInventoryPanes.md` path does not exist; a workspace UID search uniquely resolves UID0001IH and the failed Source Route text to current canonical `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`, which is the page repaired and validated.
- Six-claim generated-route readback (`2026-08-23`, waited command `000000027172`): `TargetSelectionInputPanes.h` contains exactly one `class SpellInputPaneState`, one member `void SetInputModeFlag(bool active);`, one `m_spellInputActive`, and zero global `void SetInputModeFlag(bool active);`; `TargetSelectionInputPanes.cpp` contains exactly one matching `void SpellInputPaneState::SetInputModeFlag(bool active)` definition. Preserved SpellInventory output remains exactly 15 legacy plus 15 Pane2 definitions in emitter order, one complete declaration for each primary class, one global `class InterfaceEfx;` before the legacy class and zero nested spellings, two three-initializer constructor sequences, and zero marker/stub/TODO/decompiler pollution.
- Three-claim ordinary repair readback (`2026-08-23`): UID0001IH explicitly bounds only its pre-callback status/covered-range narrative as history and keeps `## Source Route Table`/`## Ownership Decision` active; the file root, legacy class, legacy index, and UID0001IH active evidence use `ActivateSpellSlot` and `VisibleOrdinalToSpellSlot`, with any retained old method labels confined to bounded history; UID00044J uses `Event *`/`kEventKeyDown` and rejects `PaneKeyEvent`; UID0002RK uses current `Event *`/`OnServerMessage` names and defends current `94/95`, retaining `90/92` only as dated score history.
- Three-claim waited generated readback (`2026-08-23`, command `000000027183` stamped `2026-08-23T12:58:01-04:00`): `SpellInventoryPane.cpp` is SHA256 `3C85D63FC29B04804C1DAEAFDCC0849A29D337E6C68872188E32DD272B86D149`, `19,368` bytes, `623` LF/zero CR; H is SHA256 `033D979F3F02B7176B3475B9D8022AB1667EE6B89E9EC4D738FC9C1926C44648`, `2,886` bytes, `81` LF/zero CR. `TargetSelectionInputPanes.cpp` is SHA256 `9388429469740860341F559EAE20609C097E79FF1F56308444CA5D056EFD0759`, `46,081` bytes, `1,275` LF/zero CR; H is SHA256 `B16391461CFAEFB811C12A77A1109BAEB4991243F2F0F1984EFD9EEE7489ACF3`, `1,477` bytes, `47` LF/zero CR. All four have terminal LF and exact command/timestamp headers. SpellInventory retains 30 definitions in 15-legacy/15-Pane2 order, the complete legacy constructor with three state initializers plus `m_spellEffect`, the complete Pane2 constructor with three state initializers, one global InterfaceEfx declaration, both complete class declarations, and zero NewSpell/Scroll, marker/stub/TODO, or decompiler-name pollution; TargetSelection retains one `SpellInputPaneState` class/member declaration and one matching definition.
- Related target/support docs checked: UID0000O1, UID0000DN, UID0000DO, UID0002RI, UID0001II, UID0002RK, all UID00044D-UID00044S children, UID0002RL, UID0001IH, UID00026J, UID0000LU, UID0000NJ, UID0000K9/UID00006N InterfaceEfx, UserPane/SpellCommandSlotRecord, Event, RectBounds, PanelPane, Socket/PacketBuffer, SpellInputPanes, TargetSelectionInputPanes, MapPane/LivingObjectPane/ObjectPane, and InventoryPane analogues.
- Current inventory status: all 59 exact target/exclusion code-range rows, 13 destructor-tail/thunk/boundary rows, 10 target/exclusion RTTI-vtable-literal/constant rows, 7 type/resource/import rows, and 5 root/class/index rows remain dispositioned below. Ordinary documentation now incorporates every accepted disposition, including the bounded UID00044D constructor/prose correction under applied C-O1-026. No target-owned global/static storage definition was found; source constants are anonymous-namespace compile-time values.
- Current IDA handoff disposition: U01 is one logical UDT row with two ordered calls, U01.a global `struct InterfaceEfx;` then U01.b full `SpellInventoryPane`; the global tag must remain incomplete and `SpellInventoryPane::InterfaceEfx` must remain absent. U02 follows that pair and has no InterfaceEfx member dependency. Every M01-M21 `set_type(kind:function)` signature is a complete named declarator using that row's proposed IDA function name; post-type readback separately requires the exact proposed name and normalized semantic function type. M03/F03 deterministically requires `__return_address@0x0/4:_UNKNOWN *; activationData@0x4/4:const unsigned __int8 *` from direct unsaved physical evidence. M14/F14 requires the same two-row shape by very-high-confidence (`>=0.99`) parallel inference from its identical 21-byte body/hash, identical current frame, and same named formal shape, with fail-closed fresh verification. M11/F11 and M20/F20 retain public/source parameters `y, x` but deterministically preserve physical `row@0x28/0x4:int; column@0x2c/0x4:int`; no stack/local rename is authorized. R01-R09 remain deterministically no-action in IDA, so no D01-D09 function/frame post-state is created or accepted.
- Current Gate 2B history: isolated transaction `UID0000O1-20260822-225300000` failed closed at the old combined U01 before any later action or save. Its worker was discarded and both canonical and working-copy files remained byte-identical at SHA256 `0180129575CC0E3E0789AD16556A16BF7725101C9C5418834F8483B5DF7A6D09`, `143,211,331` bytes.
- Prior named-declarator failure history: an isolated attempt passed U01.a/U01.b/U02 and reached M01, but the anonymous M01 signature was parser-invalid after its disposable pure rename. It stopped before prototype mutation or save; all M01-M21 payloads were subsequently repaired.
- Current physical-frame failure history: the next fresh attempt proved the named M payload form through M03 but stopped unsaved on the report's stale F03 hard stop. No dirty session or its 14-call prefix is reusable. The next supervisor attempt must begin from a fresh clean canonical-derived physical copy/session and must verify the repaired F03/F14 contracts before comments or later actions.
- Current strict F11 failure history: transaction `UID0000O1-20260823-173839262-strict` passed only U01.a/U01.b/U02 and M01-M10 in unsaved isolated memory, then failed closed at M11/F11. Its prematurely batched M11 comment is uncredited. Independent blank-comment F11/F20 probes establish preserved physical `row`/`column` names while public types remain `y`/`x`; all physical canonical/backup/working receipts remained exact and unsaved.
- Current artifact hygiene: the active report has 21 balanced formal `cpp` fences, five balanced inert `text` fences, zero executable-language script fences, and no embedded operational package. No UID0000O1 `-removed.md` companion is physically present or required, and this report contains no link or preservation claim for one.
- Lifecycle authority: this report body asserts no current gate, execution, movement, or archive state. Those facts derive only from the artifact's physical path plus validator-owned status/history metadata.

## Executive Recommendation
- Best direct owners: UID0000DN for legacy class source, UID0000DO for Pane2 class/source children, both emitted through UID0000O1.
- UID0002RI is `RECONSTRUCTABLE:FALSE` with blank emitters while retaining UID0000DN as semantic owner; complete legacy source is in UID0000DN formal CPP/H. The empty marker is removed without pretending the mixed code/table/padding island is one source fragment.
- UID0002RK and UID0002RL remain non-emitting. UID00044F and UID00044L have their completed source-role corrections; UID00044N/UID00044O/UID00044P/UID00044Q have their completed exclusive-end filename/range repairs; all Pane2 child C++ has the completed coherent Event/project-API and 13-page/10-hit-row correction.
- NewSpell and ScrollSpell remain separate by-file targets. No class, code, vtable, or resource source moves from those accepted files.
- All currently discoverable source blockers are resolved to applied repairs or explicit compiler/no-code/external dispositions. C-O1-026 now supplies the exact `m_isLastPage(false)` initializer and packed-word prose. Original stripped helper spellings remain inference-only and require no generic investigation.
- Ordinary callback status: all accepted ordinary work, including C-O1-026, is physically applied and scoped-validated. The supervisor retains fresh Gate 2A/C-O1-054 independent generated verification, C-O1-051 Gate 2B, C-O1-052 coverage, and lifecycle authority.
- Deterministic Gate 2B scope: in a wholly fresh clean transaction, apply only U01.a, U01.b, U02, M01-M21, and N01 in that order; every modeled type call uses its exact named function declarator, and every post-type readback requires the exact entity name, normalized semantic type, and repaired physical frame before its comment. M11/M20 keep public `y, x` while F11/F20 preserve physical `row, column`; no frame-row rename is part of either four-call action. Verify R01-R09 remain exact raw no-function/no-frame spans. The full fresh topology remains 24 logical actionable rows and 88 primitive mutation calls: three UDT declarations, four calls for each of 21 modeled rows, and one comment-only call. Neither the historical 14-call prefix nor the later strict U01.a/U01.b/U02+M01-M10 prefix/M11 batch is subtracted, resumed, or credited. Raw source ownership and formal CPP/H remain unchanged.

## Supervisor Active Recheck
- Trigger: exact report SHA256 `85717ADD12507DB3F660AF061FD0D59E0093D087B0765AD9C96203D373350B63` passed fresh Gate 1 and Gate 2A, then strict transaction `UID0000O1-20260823-173839262-strict` failed cleanly at M11/F11. This bounded report-only repair changes only the F11/F20 physical-frame handoff, C-O1-051 twins, and their dependent current receipts/recommendations/self-audit; every passing ordinary/formal/generated/coverage claim remains preserved.
- Split repair: yes. The file root depends on a legacy aggregate-to-class source route, a corrected Pane2 child range/name map, and explicit compiler/data exclusions.
- Source-bearing closure: every discovered source-bearing legacy item has an exact UID0000DN formal definition/declaration; every Pane2 item has an exact applied formal replacement or UID00044H no-code proof. UID00044D now carries all three initializers and the explicit packed-word fact; compiler/data/padding rows retain no-code/compiler-covered dispositions.
- Current boundary: this F11/F20 correction directly changes only this report. Read-only ordinary inspection found the source/public `HitTestSpellRow(int y, int x)` contracts already correct, so the narrow ordinary-document contradiction exception did not trigger. B005 edited no ordinary, generated, coverage, audit/catalog/tracker, validator/lifecycle/registry, archive, companion, note, goal, or other report, made no IDA call, ran no validator, and did not run/probe/dry-run `execute_report`. Every formal source block and passing claim remains intact. The supervisor retains wholly fresh Gate 1/Gate 2A, C-O1-051 Gate 2B mutation/persistence, C-O1-052 manual coverage, C-O1-054 independent generated verification, execution/archive, audit, and lifecycle confirmation.

## Inference Research Guidance Check
- `inference_research.md` and `by-structure.md` require direct call/vtable/byte/storage evidence to outrank physical adjacency. That rule preserves UID0001II under shared input-state ownership despite its physical location in the legacy island, and rejects NewSpell/Scroll ownership by broad family naming.
- Existing assumptions treated as uncertain: broad three-file target content, legacy `0x57c430` class ownership, Pane2 `ResetPage`/`OnPaneMessage` names, one Pane2 row-count constant, raw child exclusive ends, source-empty virtual identity, constructor reachability, and generated source completeness.
- IDA fact: exact bytes, functions, types, vtable slots, xrefs, caller fanout, stack frames, and resource references. Documentation fact: current UID relationships, formal blocks, generated output, and accepted sibling reports. Inference: original stripped method spellings and the historical two-class filename.
- One stale Wave3 mention was found in `by-class/SpellInventoryPane.md`. Its spell-record stride claim was not accepted because it was Wave3; current live `SpellCommandSlotRecord` size `0x148`, UserPane access, and both dispatchers independently prove the same layout. No Wave2 artifact affected this decision.

## Heuristic / Inference Reanalysis And Validation
- Ownership: physical adjacency of `[0x57c430,0x57c440)` was rejected. Fourteen direct callers are spell/target prompt constructors/destructors/scalar wrappers, no target-local caller exists, the current name/type/comment are `SpellInputPaneState__SetInputModeFlag`, `void __thiscall(SpellInputPaneState *, bool)`, and an assignment-residue comment, and raw Pane2 has its own duplicate setter. Keep UID0001II external.
- Virtual roles: primary vtable slots point `[0x57c410,0x57c425)` and `[0x57eac0,0x57ead5)` to the same `OnActivate` position. Both clear the packed page word and invalidate. Their corresponding secondary-vtable packet methods test payload opcodes `23/24` and call that primary slot. `ResetPage`, `OnPaneMessage`, and input-flag-clear interpretations are rejected.
- Pane2 row geometry: paint and activation use page stride `13`; `[0x57f490,0x57f523)` loops inclusive rows `0..9`, and raw `[0x57f380,0x57f3d3)` builds only those ten rectangles. Use `kSpellPageSize=13` and `kSpellClickableRows=10`.
- Raw range ends: bytes prove Pane2 setter `c2 04 00` ends at `0x57eaf0`, direct-packet `c2 04 00` ends at `0x57f2f0`, and each `c2 08 00` ends at `0x57f371`, `0x57f3d3`, and `0x57f488`. Existing ends `0x57eaee`, `0x57f2ee`, `0x57f36f`, `0x57f3d1`, and `0x57f486` are mid-instruction/instruction-start artifacts, not valid half-open ranges.
- Raw helper liveness: legacy starts `0x57cc70`, `0x57cd60`, `0x57cdc0` and Pane2 starts `0x57eae0`, `0x57f290`, `0x57f2f0`, `0x57f380`, `0x57f3e0` have zero direct start xrefs. Complete prologues/returns, duplicate/inlined behavior in live callers, and ordinary source shape support retained private/static methods that the optimizer inlined while preserving out-of-line bodies. They are not padding and are not public entry points.
- Constructors: legacy `0x57c2d0` and raw Pane2 `0x57ea60` have zero direct start xrefs. Their base construction, class-specific vtable triads, matching ordinary/scalar destructors, and `0x100` delete sizes prove class ownership. In Pane2, `66 C7 86 F8 00 00 00 00 00` is one 16-bit zero store that explicitly initializes both `m_pageIndex@+0xf8` and `m_isLastPage@+0xf9`; the separate byte store initializes `m_spellInputActive@+0xfa`. Lack of a direct factory edge caps confidence but does not justify deleting source-authored constructors.
- Compiler wrappers: six adjustor thunks and three scalar deleting destructors are generated ABI support. Only Pane2 and legacy wrappers are target compiler coverage; NewSpell thunks/wrapper are excluded sibling support.
- Data: vtables/RTTI regenerate from declarations; `SPELLINV.EPD`, `SPELLINV.EPF`, and legacy `%c: %s` are source literals; four dwords at `0x62d1d0` are the Pane2 initial `RectBounds(12,20,22,41)`. Do not hand-emit vtable bytes or an rdata array.
- Types: live IDA has `PanelPane` size `0xf8`, `Event` size `0x110`, `RectBounds` size `0x10`, and `SpellCommandSlotRecord` size `0x148` with `active +0`, `inputKind +4`, `displayName +8`, `prompt +0xa8`. Target class UDTs are absent. Both deleting wrappers pass size `0x100`; proposed layouts preserve exact tails.
- Generated names/types: all `sub_`/`nullsub_` labels and decompiler `char *`, `_DWORD *`, adjusted-this, and `Pane*Event` aliases are rejected from formal source. Source uses current project `Event`, `RectBounds`, `EPFTileContext`, `SpellCommandSlotRecord`, `InterfaceEfx`, PacketBuffer, Socket, and map/input-pane APIs.
- Rejected source placement: NewSpell in this file is rejected by UID0000LU's complete separate file audit and the report-time accepted generated CPP/H snapshot; ScrollSpell is rejected by UID0000NJ's separate constructor/class/file route. A new `SpellInventoryPane2.cpp` is weaker than its established class/file route and shared legacy resource/helper family. The historical Gate 2A readback does not waive the subsequently identified UID00044D initializer omission.
- Unresolved but non-blocking: exact original filename and private helper spellings are stripped; UID00044H's one-byte no-op has no vtable/data/caller route, so no method declaration can be safely invented. These cap confidence and leave UID00044H non-emitting.

## Evidence Standards Used
- Live IDA MCP: `server_health`, `runtime_attestation`, `entity_query`, `func_profile`, `decompile`, `disasm`, `insn_query`, `get_bytes`, `get_comments`, `stack_frame`, `xref_query`, `find_bytes`, and `type_inspect`.
- Binary evidence ladder: function/raw instruction boundaries, vtable slot/store xrefs, constructor/destructor symmetry, direct callers/callees, record offsets/strides, resource refs, compiler wrapper sizes, and negative start-xref/pointer-pattern evidence.
- Documentation evidence: current by-* pages, formal channels, generated CPP/H, manual coverage rows, proposed tree, matching reports, and InventoryPane/NewSpell analogues.
- Strength: ownership and behavior are supported by multiple independent binary routes. Confidence is capped only where stripped names or zero-route retained bodies prevent original-symbol proof.

## Evidence Checked
- Authored-phase IDA MCP/manual checks: healthy session `2e5d96cf` at the target-unrelated backup path, module `NexusTK.exe`, imagebase `0x400000`, read-only. This remains historical research evidence only.
- Single-session current-prestate checks (`2026-08-22T16:29:46Z` onward): session `supervisor_uid0000ih_canonical_verify_20260822_1450`, exact path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `server_health.status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings cache ready with 2,067 entries, and `runtime_attestation` top-level/target-worker `ok:true` with exact session/path route and clean top-level/worker errors. `auto_analysis_ready:false` did not block the successful bounded reads. B005 called only read endpoints and issued no mutation/save/start/stop operation.
- Function inventory: 13 modeled legacy functions, 3 legacy raw helper starts, 10 modeled Pane2 functions plus one nullsub, 6 Pane2 raw starts, 6 adjustor thunks, and 3 scalar deleting wrappers. Raw constructor and setter/helper spans were checked instruction-by-instruction/bytewise.
- Data inventory: legacy/P2 vtable clusters, NewSpell exclusion cluster, resource strings, formatting literal, packed rectangle constants, predecessor/successor boundaries, and vtable stores/slot refs.
- Docs/reports: all paths named in Current Target State and the seven matching report leads. Search found no prior direct UID0000O1 report.
- Generated readback: commands `000000026432`/`000000026502`/`000000026517` remain historical defect/structure evidence; command `000000026749` remains the dated C-O1-026 callback receipt; commands `000000027172`/`000000027174` remain dated six-claim evidence. Current B005 callback evidence is the completed waited command `000000027183` physical readback for both TargetSelection and SpellInventory CPP/H; C-O1-054 remains reserved for independent fresh supervisor Gate 2A verification.
- Callback physical evidence: every named by-* destination was reread after application; seven old paths were absent and their exact new paths existed; every changed by-* file passed scoped validator file mode. The current three-claim destinations were separately reread for exact active/historical scope, accepted legacy identities, Event/server-message names, score rationale, hashes, bytes, and line endings. UID00044D remains SHA256 `3D0EA5B60928ED5B6927B648D45E60546FCBC1D2FCCF1B7E62A81A7CF7F0826F`, 4,288 bytes, 52 LF/zero CR, terminal LF, and its formal constructor/active prose retain the complete packed-word initialization fact.
- Negative checks: zero constructor start xrefs, zero raw-helper start xrefs, no target UDTs, no target-owned global definition, no source-empty-virtual pointer hit, no NewSpell/Scroll ownership route, no separate target resource/data emitter requirement.
- Authored-phase intentionally skipped (`2026-08-22`): no IDA open/save/mutation, validator, generated refresh, coverage edit, execute-report probe, or ordinary-doc edit occurred while the artifact was report-only. During the later authorized callback, B005 still performed no IDA, coverage, generated direct edit, audit/lifecycle mutation, or execute-report action.

## Claim And Incorporation Ledger
| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C-O1-001 | 0000O1 | File contains legacy SpellInventoryPane and SpellInventoryPane2 only. | High | Code/vtable/resource islands and sibling audits. | `by-file/SpellInventoryPane.md` UID0000O1 `## Status`, `## Proposed Contents`, and `## File-Split Guidance` | replace | APPLIED_CALLBACK |
| C-O1-002 | 0000LU | NewSpellInventoryPane is excluded and remains separate. | High | UID0000LU audit, constructor caller, CPP/H. | `by-file/SpellInventoryPane.md` UID0000O1 `## Proposed Contents`; `by-file/NewSpellInventoryPane.md` UID0000LU `## UID0000O1 Exclusion Cross-Reference - 2026-08-22` | clarify-crossref | APPLIED_CALLBACK |
| C-O1-003 | 0000NJ | ScrollSpellInventoryPane is excluded and remains separate. | High | UID0000NJ audit and constructor route. | `by-file/SpellInventoryPane.md` UID0000O1 `## Proposed Contents`; `by-file/ScrollSpellInventoryPane.md` UID0000NJ `## UID0000O1 Exclusion Cross-Reference - 2026-08-22` | clarify-crossref | APPLIED_CALLBACK |
| C-O1-004 | 0001IH | Broad executable page remains a non-emitting split/index; only its bounded pre-callback status/covered-range narrative is historical, while accepted synchronization, Source Route Table, and Ownership Decision are active and state that exact children are already selected/emitted. | High | Mixed legacy/New/Pane2/compiler span; canonical UID0001IH path resolution; current CPP/H existence; command `000000027177` scope/route/ownership readback. | `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22`, `## Historical Pre-Callback Research Snapshot (Superseded 2026-08-15)` exact scope paragraph, `## Source Route Table`, and `## Ownership Decision` | repair-active-history-scope | APPLIED_CALLBACK |
| C-O1-005 | 0000DN | Legacy class is source-ready, size 0x100, owner/emitter UID0000O1; active prose and formal CPP/H agree on `m_pageIndex`, `OnActivate`, `m_isLastPage`, and `InterfaceEfx *m_spellEffect`, with rejected alternatives historicalized. | High | Constructor/destructor/vtables/wrapper size; accepted formal CPP/H; command `000000027169` physical Field Notes/current-prose readback; canonical generated CPP/H. | `by-class/SpellInventoryPane.md` UID0000DN `## UID0000O1 Accepted Class Reconstruction - 2026-08-22`, `## Status`, `## Method Notes`, `## Field Notes`, `## Evidence Notes`, `RECONSTRUCTION_CPP CODE`, and `RECONSTRUCTION_H CODE` | replace-formal-route | APPLIED_CALLBACK |
| C-O1-006 | 0002RI | Legacy aggregate remains non-emitting; active dispatcher/mapper identities are `ActivateSpellSlot` and `VisibleOrdinalToSpellSlot`, active names/types/source placement are resolved, and UID0000DN formal CPP/H owns the complete source. | High | Mixed methods/table/padding/external child; commands `000000027178`/`000000027179` plus waited root command `000000027183`; UID0000DN accepted formal source. | `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md` UID0002RI `## UID0000O1 Accepted Non-Emitting Index - 2026-08-22`, `## Covered Range`, `## ActivateSpellSlot Dispatcher Route Table`, and `## Reconstruction Notes`; `by-class/SpellInventoryPane.md` UID0000DN `## Method Notes`/`## Evidence Notes`; `by-file/SpellInventoryPane.md` UID0000O1 `## Behavior Summary`/`## IDA MCP Evidence` | synchronize-active-identities | APPLIED_CALLBACK |
| C-O1-007 | 0001II | Embedded shared setter remains external and returns source-level void; UID0000DM formal H supplies one coherent `SpellInputPaneState` class/member declaration matching the sole child definition. | High | 14 external callers, AL residue, command `000000027172`; generated H has one class/member and no global prototype, generated CPP has one matching definition. | `by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md` UID0001II accepted heading/`## Status`/`## Function`/formal CPP; `by-class/SpellInputPaneState.md` UID0000DM `## UID0000O1 External-Helper Correction - 2026-08-22`, `## Status`, `## Method Notes`, `## C++ Gate And Emission`, and `RECONSTRUCTION_H CODE` | repair-support | APPLIED_CALLBACK |
| C-O1-008 | 0000DO | Pane2 is the size-0x100 owner/emitter for UID0000O1; applied C-O1-026 completes its source-ready constructor and its current CPP/H route is canonical. | High | Constructor/vtables/wrapper/children; corrected UID00044D initializer/generated readback; physical current CPP/H and absent historical simroot file. | `by-class/SpellInventoryPane2.md` UID0000DO metadata header, `## UID0000O1 Accepted Class Reconstruction - 2026-08-22` size/layout/owner/emitter paragraphs, `## Status` current/historical route rows, `## Field And Split Notes`, `RECONSTRUCTION_CPP CODE`, and `RECONSTRUCTION_H CODE`; C-O1-026 exact UID00044D destination | replace-formal-route | APPLIED_CALLBACK |
| C-O1-009 | 0002RK | Pane2 broad parent remains a non-emitting exact index. | High | Exact child and gap inventory. | `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range` and `## Exact Child Pages` | repair-index | APPLIED_CALLBACK |
| C-O1-010 | 0000O1 | Dated validator command 000000026432 remains historical incomplete-CPP/absent-H evidence; active route text names the canonical current SpellInventoryPane CPP/H and separate excluded-unit outputs. | Certain | Historical command-26432 physical readback/path absence; current by-file route cells; command-27000 generated CPP/H existence, hashes, inventory, declarations, and zero-pollution readback. | `by-file/SpellInventoryPane.md` UID0000O1 `## UID0000O1 Accepted Whole-File Reconstruction - 2026-08-22`, `## Status`, and `## Proposed Contents`; fresh-gate readback of `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` and `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.h` | replace-generated-route | APPLIED_CALLBACK |
| C-O1-011 | 0000DN | Legacy constructor initializes packed state and MAGEFX InterfaceEfx. | High | 0x57c2d0 decompile/callees/resources. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` symbol `SpellInventoryPane::SpellInventoryPane` | add-definition | APPLIED_CALLBACK |
| C-O1-012 | 0000DN | Legacy destructor marks effect for deletion then destroys base. | High | 0x57c3a0. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` symbol `SpellInventoryPane::~SpellInventoryPane` | add-definition | APPLIED_CALLBACK |
| C-O1-013 | 0000DN | 0x57c410 is OnActivate, not generic ResetPage. | High | Primary vtable slot +0x48 and packet call. | `by-class/SpellInventoryPane.md` UID0000DN `## Method Notes`, `RECONSTRUCTION_CPP CODE`, and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::OnActivate` | rename-role | APPLIED_CALLBACK |
| C-O1-014 | 0000DN | 0x57c440 is PlaySpellEffect over InterfaceEfx*. | High | Constructor allocation and tail-call 0x4e9950 Play. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::PlaySpellEffect` | add-definition | APPLIED_CALLBACK |
| C-O1-015 | 0000DN | Legacy OnPaint uses 13-entry pages and EPD resources. | High | 0x57c450 decompile/resource refs. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` symbol `SpellInventoryPane::OnPaint` | add-definition | APPLIED_CALLBACK |
| C-O1-016 | 0000DN | Legacy key virtual uses Event* and page keys. | High | 0x57c710/vtable/Event layout. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::OnKeyEvent` | add-definition | APPLIED_CALLBACK |
| C-O1-017 | 0000DN | Legacy mouse virtual handles page/single/double activation. | High | 0x57c790 and helper xrefs. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::OnMouseEvent` | add-definition | APPLIED_CALLBACK |
| C-O1-018 | 0000DN | Legacy packet virtual calls OnActivate for opcodes 23/24. | High | 0x57c980 and vtable slot. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::OnServerMessage` | add-definition | APPLIED_CALLBACK |
| C-O1-019 | 0000DN | Legacy activation dispatch includes targeted shortcut. | High | 0x57c9b0 switch/callees. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::ActivateSpellSlot` | add-definition | APPLIED_CALLBACK |
| C-O1-020 | 0002RI | Legacy alignment/jump-table/padding is compiler-covered no-code. | Certain | Bytes at 0x57cc42 and exact gaps. | `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md` UID0002RI `## Covered Range` | document-no-code | APPLIED_CALLBACK |
| C-O1-021 | 0000DN | Legacy raw direct packet helper is retained private source. | High | Complete 0x57cc70 body, zero xrefs, inline duplicate. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::SendDirectSpellPacket` | add-definition | APPLIED_CALLBACK |
| C-O1-022 | 0000DN | Legacy page-rectangle helper is source-owned. | High | 0x57ccd0 and mouse caller. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::BuildPageButtonRect` | add-definition | APPLIED_CALLBACK |
| C-O1-023 | 0000DN | Legacy raw row-rectangle helper is retained source. | High | Complete 0x57cd60 body, zero start xrefs. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::BuildSpellRowRect` | add-definition | APPLIED_CALLBACK |
| C-O1-024 | 0000DN | Legacy raw page hit-test helper is retained source. | High | Complete 0x57cdc0 body, inline duplicate. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::HitTestPageButton` | add-definition | APPLIED_CALLBACK |
| C-O1-025 | 0000DN | Legacy row hit-test and ordinal mapper are source-owned. | High | 0x57ce70/0x57cf10 two callers each. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbols `SpellInventoryPane::HitTestSpellRow` and `SpellInventoryPane::VisibleOrdinalToSpellSlot` | add-definitions | APPLIED_CALLBACK |
| C-O1-026 | 00044D | Pane2 constructor initializes `m_pageIndex(0)`, `m_isLastPage(false)`, and `m_spellInputActive(false)`; its 16-bit `+0xf8` clear explicitly covers `+0xf9`. | High | Vtable triad; raw bytes `66 C7 86 F8 00 00 00 00 00` and `C6 86 FA 00 00 00 00`; ordinary SHA256 `3D0EA5B60928ED5B6927B648D45E60546FCBC1D2FCCF1B7E62A81A7CF7F0826F`; validator/generated command `000000026749`. | `by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md` UID00044D `RECONSTRUCTION_CPP CODE`, `## Source Reconstruction Notes`, and `## C++ Disposition`; scoped validator and physical generated CPP/H readback | repair-definition-and-prose | APPLIED_CALLBACK |
| C-O1-027 | 00044E | Pane2 ordinary destructor remains empty source body. | High | Vtable reset/base cleanup. | `by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md` UID00044E `RECONSTRUCTION_CPP CODE` | retain-definition | APPLIED_CALLBACK |
| C-O1-028 | 00044F | Pane2 child is `OnActivate`; every active inbound role uses that identity and the rejected reset-page label is historical only. | High | Primary vtable/opcode-handler call; command `000000027171` physical UID0002RK inbound-label readback. | Current `by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate.md` UID00044F title/`## Status`/`## Behavior`/formal CPP; historical rename provenance from `SpellInventoryPane2ResetPage.md`; `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Exact Child Pages`, `## Accepted Current Implementation Path`, and `## Cross-References`; UID0001IH accepted split heading | rename-path-role | APPLIED_CALLBACK |
| C-O1-029 | 00044G | Pane2 raw local input-active setter ends at 0x57eaf0 and remains private source. | High | Exact duplicate body, zero direct xrefs, `c2 04 00` terminal bytes. | UID00044G callback rename from `by-memory/0x0057eae0-0x0057eaee.SpellInventoryPane2SetSpellInputActive.md` -> current `by-memory/0x0057eae0-0x0057eaf0.SpellInventoryPane2SetSpellInputActive.md`: current filename, `# 0x0057eae0-0x0057eaf0 SpellInventoryPane2 SetSpellInputActive` title, `## UID0000O1 Accepted Exact Range - 2026-08-22`, `## Status`, and `RECONSTRUCTION_CPP CODE`; exact parent range rows in `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range`/`## Exact Child Pages` and `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22` | rename-range-definition | APPLIED_CALLBACK |
| C-O1-030 | 00044H | One-byte nullsub stays non-emitting/no declaration. | High | `ret`, no xrefs/pointer hit/side effects. | `by-memory/0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual.md` UID00044H `## No-Code Proof` | retain-no-code | APPLIED_CALLBACK |
| C-O1-031 | 00044I | Pane2 paint uses project APIs, page size 13, initial rect constants. | High | 0x57eb00 and rdata 0x62d1d0. | `by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md` UID00044I `RECONSTRUCTION_CPP CODE` | replace-definition | APPLIED_CALLBACK |
| C-O1-032 | 00044J | Pane2 key method uses `Event *` and `kEventKeyDown`; `PaneKeyEvent` is rejected historical naming, and the UID0002RK active index agrees on `Event *`/`OnServerMessage` authority. | High | 0x57edb0/Event layout/vtable; commands `000000027180`/`000000027181`; current formal child signatures. | `by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md` UID00044J `## UID0000O1 Accepted Source Definition - 2026-08-22`, `## Source Reconstruction Notes`, and `RECONSTRUCTION_CPP CODE`; `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Source-Facing Type And Route Names` | synchronize-event-authority | APPLIED_CALLBACK |
| C-O1-033 | 00044K | Pane2 mouse uses page stride 13 and hit rows 10. | High | 0x57ee30/0x57f490. | `by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md` UID00044K `RECONSTRUCTION_CPP CODE` | replace-definition | APPLIED_CALLBACK |
| C-O1-034 | 00044L | Pane2 child is `OnServerMessage`, calls `OnActivate`, and every active inbound role uses that identity; the rejected pane-message label is historical only. | High | 0x57f000/primary slot; command `000000027171` physical UID0002RK inbound-label readback. | Current `by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage.md` UID00044L title/`## Status`/`## Behavior`/formal CPP; historical rename provenance from `SpellInventoryPane2OnPaneMessage.md`; `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Exact Child Pages`, `## Accepted Current Implementation Path`, and `## Cross-References`; UID0001IH accepted split heading | rename-path-role | APPLIED_CALLBACK |
| C-O1-035 | 00044M | Pane2 activation has eight input-kind routes and owned jump table. | High | 0x57f030 decompile/table bytes. | `by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md` UID00044M `## Spell Input Routes` and `RECONSTRUCTION_CPP CODE` | replace-definition | APPLIED_CALLBACK |
| C-O1-036 | 00044N | Direct packet child exclusive end is 0x57f2f0. | Certain | `c2 04 00` byte end. | UID00044N callback rename from `by-memory/0x0057f290-0x0057f2ee.SpellInventoryPane2SendDirectSpellPacket.md` -> current `by-memory/0x0057f290-0x0057f2f0.SpellInventoryPane2SendDirectSpellPacket.md`: current filename, `# 0x0057f290-0x0057f2f0 SpellInventoryPane2 SendDirectSpellPacket` title, `## UID0000O1 Accepted Exact Range - 2026-08-22`, `## Status`, and `RECONSTRUCTION_CPP CODE`; exact parent rows in `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range`/`## Exact Child Pages` and `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22` | rename-range | APPLIED_CALLBACK |
| C-O1-037 | 00044O | Page-rect child exclusive end is 0x57f371. | Certain | `c2 08 00` byte end. | UID00044O callback rename from `by-memory/0x0057f2f0-0x0057f36f.SpellInventoryPane2BuildPageButtonRect.md` -> current `by-memory/0x0057f2f0-0x0057f371.SpellInventoryPane2BuildPageButtonRect.md`: current filename, `# 0x0057f2f0-0x0057f371 SpellInventoryPane2 BuildPageButtonRect` title, `## UID0000O1 Accepted Exact Range - 2026-08-22`, `## Status`, and `RECONSTRUCTION_CPP CODE`; exact parent rows in `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range`/`## Exact Child Pages` and `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22` | rename-range | APPLIED_CALLBACK |
| C-O1-038 | 00044P | Row-rect child exclusive end is 0x57f3d3 and rows are 0..9. | Certain | Return bytes and bounds loop. | UID00044P callback rename from `by-memory/0x0057f380-0x0057f3d1.SpellInventoryPane2BuildSpellRowRect.md` -> current `by-memory/0x0057f380-0x0057f3d3.SpellInventoryPane2BuildSpellRowRect.md`: current filename, `# 0x0057f380-0x0057f3d3 SpellInventoryPane2 BuildSpellRowRect` title, `## UID0000O1 Accepted Exact Range And Rows - 2026-08-22`, `## Status`, `## Behavior`, and `RECONSTRUCTION_CPP CODE`; exact parent rows in `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range`/`## Exact Child Pages` and `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22` | rename-range | APPLIED_CALLBACK |
| C-O1-039 | 00044Q | Page-hit child exclusive end is 0x57f488. | Certain | Return bytes. | UID00044Q callback rename from `by-memory/0x0057f3e0-0x0057f486.SpellInventoryPane2HitTestPageButton.md` -> current `by-memory/0x0057f3e0-0x0057f488.SpellInventoryPane2HitTestPageButton.md`: current filename, `# 0x0057f3e0-0x0057f488 SpellInventoryPane2 HitTestPageButton` title, `## UID0000O1 Accepted Exact Range - 2026-08-22`, `## Status`, and `RECONSTRUCTION_CPP CODE`; exact parent rows in `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range`/`## Exact Child Pages` and `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22` | rename-range | APPLIED_CALLBACK |
| C-O1-040 | 00044R | Pane2 hit-test scans exactly ten rows. | Certain | 0x57f490 loop `<=9`. | `by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md` UID00044R `## Behavior` and `RECONSTRUCTION_CPP CODE` | replace-definition | APPLIED_CALLBACK |
| C-O1-041 | 00044S | Pane2 ordinal mapper scans active slots 1..52. | High | 0x57f530. | `by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md` UID00044S `RECONSTRUCTION_CPP CODE` | replace-definition | APPLIED_CALLBACK |
| C-O1-042 | 0002RK | All Pane2 gaps/padding and switch table have exact no-code rows. | Certain | Raw bytes across entire parent. | `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range` and `## No Aggregate C++ And Tiny-Body Dispositions` | replace-inventory | APPLIED_CALLBACK |
| C-O1-043 | 0002RL | Target adjustor thunks/wrappers remain compiler-only; NewSpell rows excluded. | Certain | Six thunks/three wrappers and vtables. | `by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md` UID0002RL `## Covered Range` and `## Source-Quality Disposition And No-Code Proof` | clarify-target-split | APPLIED_CALLBACK |
| C-O1-044 | 00026J | Legacy/P2 vtables are target compiler data; NewSpell/macro data excluded. | High | Exact rdata clusters/store xrefs. | `by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md` UID00026J `## Ownership Map` | update-crossref | APPLIED_CALLBACK |
| C-O1-045 | 0000O1 | EPD/EPF/format/rect constants emit through source literals, not raw arrays. | High | Resource xrefs and bytes. | `by-file/SpellInventoryPane.md` UID0000O1 `## UID0000O1 Accepted Whole-File Reconstruction - 2026-08-22` target read-only-data/source-literal paragraph; `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE`; `by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md` UID00044I `RECONSTRUCTION_CPP CODE` | add-source-literals | APPLIED_CALLBACK |
| C-O1-046 | 0000DN | Legacy H fragment opens guard/includes, globally forward-declares InterfaceEfx before the class, and declares the exact 0x100 class. | High | PanelPane 0xf8, wrapper size, accepted formal declaration order, and fresh canonical parser-scope evidence. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_H CODE`; this report U01.a/U01.b handoff | add-header-fragment | APPLIED_CALLBACK |
| C-O1-047 | 0000DO | Pane2 H fragment declares exact 0x100 class and closes guard. | High | PanelPane 0xf8 and wrapper size. | `by-class/SpellInventoryPane2.md` UID0000DO `RECONSTRUCTION_H CODE` | add-header-fragment | APPLIED_CALLBACK |
| C-O1-048 | 0000O1 | Deterministic emitter order is DN 010, DO 020 with child 100..240. | High | Required preamble/header ordering. | Metadata-header `EMITTER_POSITION_OPTIONAL` in `by-class/SpellInventoryPane.md` UID0000DN and `by-class/SpellInventoryPane2.md` UID0000DO; the same metadata-header field in each exact child `by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md` UID00044D, `by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md` UID00044E, `by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate.md` UID00044F, `by-memory/0x0057eae0-0x0057eaf0.SpellInventoryPane2SetSpellInputActive.md` UID00044G, `by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md` UID00044I, `by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md` UID00044J, `by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md` UID00044K, `by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage.md` UID00044L, `by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md` UID00044M, `by-memory/0x0057f290-0x0057f2f0.SpellInventoryPane2SendDirectSpellPacket.md` UID00044N, `by-memory/0x0057f2f0-0x0057f371.SpellInventoryPane2BuildPageButtonRect.md` UID00044O, `by-memory/0x0057f380-0x0057f3d3.SpellInventoryPane2BuildSpellRowRect.md` UID00044P, `by-memory/0x0057f3e0-0x0057f488.SpellInventoryPane2HitTestPageButton.md` UID00044Q, `by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md` UID00044R, and `by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md` UID00044S; supervisor refresh/readback of `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` and `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.h` | set-order | APPLIED_CALLBACK |
| C-O1-049 | 0000O1 | Dependencies stay externally owned and are included/forward-declared only. | High | Call graph and current project headers. | `by-file/SpellInventoryPane.md` UID0000O1 `## UID0000O1 Accepted Whole-File Reconstruction - 2026-08-22` external-dependency paragraph; `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` | document-imports | APPLIED_CALLBACK |
| C-O1-050 | 0000O1 | No target-owned global/static storage definition exists. | High | Entity/global/xref search and constructors. | `by-file/SpellInventoryPane.md` UID0000O1 `## UID0000O1 Accepted Whole-File Reconstruction - 2026-08-22` no-target-global/static-storage paragraph | record-negative | APPLIED_CALLBACK |
| C-O1-051 | 0000O1 | Exact IDA handoff is supervisor-only, fresh-canonical gated, orders global incomplete InterfaceEfx before the legacy pane UDT, and supplies complete named function declarators plus deterministic public-type/physical-frame contracts for M01-M21. | Certain | Complete canonical U/M/F/R/D/N/P prestates; fresh canonical type-scope/parser analogues; failed isolated old-U01 nested result; deterministic U01.a/U01.b global readbacks; failed anonymous M01 parser receipt; direct unsaved M03/F03 two-row receipt and M14/F14 `>=0.99` parallel inference; strict M11/F11 failed-batch history plus independent blank-comment F11/F20 probes proving public `y, x` with protected physical `row@0x28/0x4:int; column@0x2c/0x4:int`; 21 exact named-declarator/normalized readbacks; eight current modeled type deltas including M05 `int __thiscall(int this)`; M13 end; R01-R09 no-action/D01-D09 absent. | `tools/leaser/Agents/Agent-B005/research/0000O1-SpellInventoryPane-file-source-quality.md` UID0000O1 `## IDA Rename / Type / Comment Recommendations`, including Gate 2B history/order, U01.a/U01.b/U02, M01-M21, `### Named Function Declarator Parser Contract`, `### Fresh-Current Modeled Receipts`, `### Modeled Frame Contracts` F01-F21 with exact F11/F20 zero-delta protections, `### Raw No-Action Protection Contracts` R01-R09/D01-D09, N01, P01/P0, and final aggregate readback; `tools/leaser/Agents/b-report-validation-audit.md` exact UID0000O1 supervisor Gate 2B audit entry with per-action, named-declarator/normalized-type, F03 observed/F14 inferred frames, F11/F20 public-type versus physical-frame receipts, global-versus-nested type, and raw no-action pre/post/protection receipts | supervisor-ida | PLANNED_GATE1 |
| C-O1-052 | 0000O1 | Manual coverage rows are stale and need exact supervisor replacements/insertions. | Certain | Physical manual-row readback. | `by-file/-coverage-report.md` `## Covered Items To Replicate` replace UID0000O1 row; `by-class/-coverage-report.md` `## Covered Items To Replicate` replace UID0000DM/UID0000DN/UID0000DO rows; `by-memory/-coverage-report.md` `## Covered Items` replace UID0001IH/UID0002RI/UID0001II/UID0002RK/UID0002RL and UID00026J rows, then insert UID00044D-UID00044S immediately after UID0002RK and before UID0002RL | supervisor-coverage | PLANNED_GATE1 |
| C-O1-053 | 0000O1 | Callback score metadata and active support-score prose are physically applied; completed C-O1-026 adds no score beyond the accepted defended state. | High | Applied metadata receipts; UID0000DO active UID0002RK `94/95` and UID0001IH `91/94` prose; corrected constructor/readback; remaining stripped names. | Metadata-header `COMPLETION`/`CONFIDENCE` fields in `by-file/SpellInventoryPane.md` UID0000O1, `by-class/SpellInventoryPane.md` UID0000DN, `by-class/SpellInventoryPane2.md` UID0000DO, `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md` UID0002RI, and `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK; `by-class/SpellInventoryPane2.md` UID0000DO `## Evidence Notes` active support-score rows | update-score | APPLIED_CALLBACK |
| C-O1-054 | 0000O1 | After applied C-O1-026, a fresh independent supervisor verification must prove complete CPP/H without markers/stubs or an initializer omission. | Certain | Dated command 000000026432 incomplete-CPP/absent-H snapshot; historical 000000026502/000000026517 omission receipts; B005 callback readback command 000000026749 is complete but does not replace supervisor Gate 2A authority. | Supervisor fresh Gate 2A verification of validator-generated `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` and `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.h` after the accepted C-O1-026 callback | refresh-verify | PLANNED_GATE1 |
| C-O1-055 | 0000O1 | B005 changed only the named ordinary by-* docs and this report while preserving generated/coverage/IDA/audit/lifecycle state from direct mutation. | Certain | Gate 1 authorization, changed-file hashes, validator receipts, and prohibited-state boundary. | `tools/leaser/Agents/Agent-B005/research/0000O1-SpellInventoryPane-file-source-quality.md` UID0000O1 `## Changed Files` | preserve-boundary | VERIFIED_CALLBACK_BOUNDARY |

## Positive Evidence Summary
- Direct facts: two target vtable triads, two `0x100` deleting-wrapper sizes, source-shaped constructors/destructors/virtuals/helpers, exact UserPane spell record layout, exact page/geometry constants, direct dispatcher/helper callers, and target resource refs.
- UID00044D constructor fact: the 16-bit zero store at `this+0xf8` writes both `m_pageIndex@+0xf8` and `m_isLastPage@+0xf9`; the byte store at `+0xfa` writes `m_spellInputActive`. The faithful source initializer list therefore contains all three fields.
- Corroboration: current class/file routes, Pane2 exact children, InventoryPane ABI/API analogue, NewSpell/Scroll separate whole-file audits, and current project headers.
- Declaration-scope corroboration: canonical `FunctionObject0` is a global incomplete type (`size=18446744073709551615`, `is_udt:false`); `LogoPane.m_completionCallback` binds to `FunctionObject0 *` and `LogoPane::FunctionObject0` is absent. Conversely, `LightingObjectPane.m_anchorSource` retains `struct LightingObjectPane::ObjectPane *` despite a complete global `ObjectPane`, proving a late/global same-name type does not retroactively repair a member-local nested binding. The accepted formal H already uses the required global-forward-before-class order.
- Physical-frame corroboration: independent fail-closed no-comment probes at M11 and M20 each accepted the exact named declarator and exposed public `__int16 __stdcall(int y, int x)` while preserving physical `row@0x28/0x4:int; column@0x2c/0x4:int`. This directly separates source/public names from protected physical frame names without changing source semantics or adding a stack rename action.
- Strongest inference chain: class-specific constructor stores plus vtable method slots plus matching ordinary/scalar destructors plus source resource literals establish both classes; independent file audits and caller routes exclude siblings; complete bytes/gaps establish the compilation-unit inventory.

## IDA MCP Facts
- Function/range: legacy modeled starts `57c2d0,57c3a0,57c410,57c430,57c440,57c450,57c710,57c790,57c980,57c9b0,57ccd0,57ce70,57cf10`; Pane2 modeled starts `57eaa0,57eac0,57eaf0,57eb00,57edb0,57ee30,57f000,57f030,57f490,57f530`; raw source starts are listed in the inventory.
- Fresh-current boundary correction: M13 is function `[57eaa0,57eabf)` with last code item `[57eaba,57eabf)`; `[57eabf,57eac0)` is a separate protected one-byte data item before M14 at `57eac0`.
- Data/table/padding: legacy jump table entries are `57ca2c,57ca60,57cae8,57cb1c,57cb50,57cb98,57cbc5,57cbf2`; Pane2 entries are `57f0ab,57f0df,57f113,57f147,57f17b,57f1c3,57f1f0,57f21d`.
- Xrefs: legacy activate has two calls from `57c790`; legacy row/ordinal helpers have two each; Pane2 activate/row/ordinal helpers have one each from `57ee30`; UID0001II has fourteen external callers; raw starts and both constructors have zero direct start xrefs.
- Vtables: legacy `[62cfd8,62d064)` stores from constructor/destructor/wrapper; Pane2 `[62d0f0,62d17c)` stores from raw constructor/destructor/wrapper. Virtual slots directly reference both paints, both key/mouse/packet methods, and both OnActivate methods.
- Types: `PanelPane 0xf8`, `Event 0x110`, `RectBounds 0x10`, `SpellCommandSlotRecord 0x148`; `SpellInventoryPane`, `SpellInventoryPane2`, global `InterfaceEfx`, `SpellInventoryPane::InterfaceEfx`, and `SpellInventoryPane2::InterfaceEfx` all absent in the fresh UDT-scope prestate.
- Current-prestate receipt: the single healthy canonical session `supervisor_uid0000ih_canonical_verify_20260822_1450` supplied the complete fresh read of all U/M/F/R/D/N/P types, items, frames, comments, bytes, hashes, boundaries, exact-entry xrefs, and proposed-name collisions. Eight modeled types and M13's end differ from superseded historical prestates and are corrected in the Gate 2B matrices. Healthy canonical read-only session `supervisor_uid0000mm_canonical_verify_20260822_1745` independently supplied only the current UDT-scope absences and global-versus-nested parser analogues used by this repair. No current matrix cell comes from a failed UID0000O1 transaction.
- Failed-U01 receipt: `supervisor_uid0000o1_gate2b_20260822_2253` materialized the old combined declaration as nested `SpellInventoryPane::InterfaceEfx *`, stopped before every later action/save, and was discarded. The unchanged canonical/working physical receipt is SHA256 `0180129575CC0E3E0789AD16556A16BF7725101C9C5418834F8483B5DF7A6D09`, `143,211,331` bytes.
- Negative: no target global definition, no raw-helper route, no UID00044H pointer hit, no direct target constructor caller, and no evidence to merge separate sibling files.
- Deterministic frame disposition: F03's accepted named type physically materializes `activationData@0x4/4:const unsigned __int8 *` beside `__return_address@0x0/4:_UNKNOWN *`; F14 requires the same two rows by `>=0.99` parallel inference from the identical 21-byte body/hash and declarator shape. Both forbid every other row. Independent physical probes make F11/F20 certain zero-delta contracts: each keeps `row@0x28/0x4:int; column@0x2c/0x4:int` despite public `y, x`. R01-R09 remain raw no-function/no-frame items; D01-D09 are intentionally absent and `stack_frame` must continue returning `No function found`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status | CPP/H and exact destination |
| --- | --- | --- | --- | --- | --- | --- | --- |
| file root | UID0000O1 `by-file/SpellInventoryPane.md` | compilation unit | yes | FILE | 88/89 -> 93/94 | repair | source routed by UID0000DN/UID0000DO |
| legacy class | UID0000DN `by-class/SpellInventoryPane.md` | class/layout/emitter | yes | 0000O1 | 85/88 -> 93/94 | incomplete | full CPP/H below |
| legacy aggregate | UID0002RI `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md` | split/index | no after repair | 0000DN | 88/89 -> 92/94 | empty emitter | no-code; UID0000DN owns source |
| `57c2d0-57c39f` | UID0002RI / UID0000DN | constructor | yes | 0000DN | class score | source-owned | UID0000DN CPP/H |
| `57c39f-57c3a0` | UID0002RI | `cc` padding | no | 0002RI | index | exact | compiler-covered/no-code |
| `57c3a0-57c401` | UID0002RI / UID0000DN | ordinary destructor | yes | 0000DN | class score | source-owned | UID0000DN CPP/H |
| `57c401-57c410` | UID0002RI | `cc` padding | no | 0002RI | index | exact | no-code |
| `57c410-57c425` | UID0002RI / UID0000DN | `OnActivate` | yes | 0000DN | class score | role repair | UID0000DN CPP/H |
| `57c425-57c430` | UID0002RI | `cc` padding | no | 0002RI | index | exact | no-code |
| `57c430-57c440` | UID0001II `by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md` | external shared setter | yes, external | 0000DM | 88/90 | excluded | `TargetSelectionInputPanes.cpp`; no target CPP/H |
| `57c440-57c44b` | UID0002RI / UID0000DN | `PlaySpellEffect` | yes | 0000DN | class score | source-owned | UID0000DN CPP/H |
| `57c44b-57c450` | UID0002RI | `cc` padding | no | 0002RI | index | exact | no-code |
| `57c450-57c710` | UID0002RI / UID0000DN | `OnPaint` | yes | 0000DN | class score | source-owned | UID0000DN CPP/H |
| `57c710-57c78c` | UID0002RI / UID0000DN | `OnKeyEvent` | yes | 0000DN | class score | source-owned | UID0000DN CPP/H |
| `57c78c-57c790` | UID0002RI | padding | no | 0002RI | index | exact | no-code |
| `57c790-57c979` | UID0002RI / UID0000DN | `OnMouseEvent` | yes | 0000DN | class score | source-owned | UID0000DN CPP/H |
| `57c979-57c980` | UID0002RI | padding | no | 0002RI | index | exact | no-code |
| `57c980-57c9a8` | UID0002RI / UID0000DN | `OnServerMessage` | yes | 0000DN | class score | role repair | UID0000DN CPP/H |
| `57c9a8-57c9b0` | UID0002RI | padding | no | 0002RI | index | exact | no-code |
| `57c9b0-57cc42` | UID0002RI / UID0000DN | `ActivateSpellSlot` | yes | 0000DN | class score | source-owned | UID0000DN CPP/H |
| `57cc42-57cc44` | UID0002RI | `66 90` alignment | no | 0002RI | index | exact | no-code |
| `57cc44-57cc64` | UID0002RI | eight-entry switch table | no | 0002RI | index | exact | compiler-lowered from switch |
| `57cc64-57cc70` | UID0002RI | padding | no | 0002RI | index | exact | no-code |
| `57cc70-57ccd0` | UID0002RI / UID0000DN | raw direct packet helper | yes | 0000DN | class score | retained/inlined | UID0000DN CPP/H |
| `57ccd0-57cd51` | UID0002RI / UID0000DN | page rect helper | yes | 0000DN | class score | one caller | UID0000DN CPP/H |
| `57cd51-57cd60` | UID0002RI | padding | no | 0002RI | index | exact | no-code |
| `57cd60-57cdb3` | UID0002RI / UID0000DN | raw row rect helper | yes | 0000DN | class score | retained/inlined | UID0000DN CPP/H |
| `57cdb3-57cdc0` | UID0002RI | padding | no | 0002RI | index | exact | no-code |
| `57cdc0-57ce68` | UID0002RI / UID0000DN | raw page hit-test | yes | 0000DN | class score | retained/inlined | UID0000DN CPP/H |
| `57ce68-57ce70` | UID0002RI | padding | no | 0002RI | index | exact | no-code |
| `57ce70-57cf03` | UID0002RI / UID0000DN | row hit-test | yes | 0000DN | class score | two callers | UID0000DN CPP/H |
| `57cf03-57cf10` | UID0002RI | padding | no | 0002RI | index | exact | no-code |
| `57cf10-57cf6b` | UID0002RI / UID0000DN | visible ordinal mapper | yes | 0000DN | class score | two callers | UID0000DN CPP/H |
| `57cf6b-57cf70` | UID0001IH | boundary padding | no | NONE | index | excluded | before UID0000LU |
| `57cf70-57ea57` | UID0000LU | NewSpell compilation unit | yes, external | 0000LU | accepted | excluded | `NewSpellInventoryPane.cpp/.h` |
| `57ea57-57ea60` | UID0002RK | predecessor padding | no | 0002RK | index | exact | no-code |
| Pane2 class | UID0000DO `by-class/SpellInventoryPane2.md` | class/layout/emitter | yes | 0000O1 | 89/90 -> 93/94 | incomplete H | H plus `[[CHILDREN]]` |
| Pane2 aggregate | UID0002RK `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` | split/index | no | 0000DO | 90/92 -> 94/95 | repair | no aggregate code |
| `57ea60-57eaa0` | UID00044D current path | constructor | yes | 0000DO | 90/92 -> 93/94 | replace | UID00044D CPP; UID0000DO H |
| `57eaa0-57eac0` | UID00044E current path | destructor plus one-byte tail pad | yes body | 0000DO | 90/92 -> 93/94 | retain | UID00044E CPP |
| `57eac0-57ead5` | UID00044F renamed path | `OnActivate` | yes | 0000DO | 89/91 -> 94/95 | rename role/path | UID00044F CPP; UID0000DO H |
| `57ead5-57eae0` | UID0002RK | padding | no | 0002RK | index | exact | no-code |
| `57eae0-57eaf0` | UID00044G repaired range/path | input-active setter | yes | 0000DO | 89/91 -> 92/94 | range/definition repair | UID00044G CPP/H declaration |
| `57eaf0-57eaf1` | UID00044H current path | source-empty/no-route ret | no | 0000DO | 86/92 | protected | blank CPP/H |
| `57eaf1-57eb00` | UID0002RK | padding | no | 0002RK | index | exact | no-code |
| `57eb00-57eda4` | UID00044I current path | `OnPaint` | yes | 0000DO | 89/91 -> 94/95 | replace | UID00044I CPP |
| `57eda4-57edb0` | UID0002RK | padding | no | 0002RK | index | newly explicit | no-code |
| `57edb0-57ee2c` | UID00044J current path | `OnKeyEvent` | yes | 0000DO | 89/91 -> 94/95 | replace type/source | UID00044J CPP |
| `57ee2c-57ee30` | UID0002RK | padding | no | 0002RK | index | newly explicit | no-code |
| `57ee30-57eff7` | UID00044K current path | `OnMouseEvent` | yes | 0000DO | 89/91 -> 94/95 | replace | UID00044K CPP |
| `57eff7-57f000` | UID0002RK | padding | no | 0002RK | index | newly explicit | no-code |
| `57f000-57f028` | UID00044L renamed path | `OnServerMessage` | yes | 0000DO | 88/90 -> 94/95 | rename role/path | UID00044L CPP |
| `57f028-57f030` | UID0002RK | padding | no | 0002RK | index | newly explicit | no-code |
| `57f030-57f26c` | UID00044M current path | activation body | yes | 0000DO | 90/92 -> 94/95 | replace | UID00044M CPP |
| `57f26c-57f28c` | UID00044M | eight-entry switch table | no | 00044M | child | exact | compiler-lowered from switch |
| `57f28c-57f290` | UID0002RK | padding | no | 0002RK | index | exact | no-code |
| `57f290-57f2f0` | UID00044N renamed range/path | raw direct packet helper | yes | 0000DO | 89/91 -> 94/95 | range repair | UID00044N CPP |
| `57f2f0-57f371` | UID00044O renamed range/path | raw page rect helper | yes | 0000DO | 90/92 -> 94/95 | range repair | UID00044O CPP |
| `57f371-57f380` | UID0002RK | padding | no | 0002RK | index | exact | no-code |
| `57f380-57f3d3` | UID00044P renamed range/path | raw row rect helper | yes | 0000DO | 90/92 -> 94/95 | range/constant repair | UID00044P CPP |
| `57f3d3-57f3e0` | UID0002RK | padding | no | 0002RK | index | exact | no-code |
| `57f3e0-57f488` | UID00044Q renamed range/path | raw page hit-test | yes | 0000DO | 90/92 -> 94/95 | range repair | UID00044Q CPP |
| `57f488-57f490` | UID0002RK | padding | no | 0002RK | index | exact | no-code |
| `57f490-57f523` | UID00044R current path | ten-row hit-test | yes | 0000DO | 90/92 -> 94/95 | constant repair | UID00044R CPP |
| `57f523-57f530` | UID0002RK | padding | no | 0002RK | index | newly explicit | no-code |
| `57f530-57f58b` | UID00044S current path | visible ordinal mapper | yes | 0000DO | 90/92 -> 94/95 | replace API | UID00044S CPP |
| `57f58b-57f596` | UID0002RL | NewSpell adjustor thunk | no | NONE | 91/93 | excluded compiler | UID0000LU compiler coverage |
| `57f596-57f5a1` | UID0002RL | NewSpell adjustor thunk | no | NONE | 91/93 | excluded compiler | UID0000LU compiler coverage |
| `57f5a1-57f5ac` | UID0002RL | Pane2 adjustor thunk | no | NONE | 91/93 | target compiler | regenerated from UID0000DO H |
| `57f5ac-57f5b7` | UID0002RL | Pane2 adjustor thunk | no | NONE | 91/93 | target compiler | regenerated from UID0000DO H |
| `57f5b7-57f5c2` | UID0002RL | legacy adjustor thunk | no | NONE | 91/93 | target compiler | regenerated from UID0000DN H |
| `57f5c2-57f5cd` | UID0002RL | legacy adjustor thunk | no | NONE | 91/93 | target compiler | regenerated from UID0000DN H |
| `57f5cd-57f5d0` | UID0002RL | padding | no | NONE | 91/93 | compiler | no-code |
| `57f5d0-57f637` | UID0002RL | NewSpell scalar deleting destructor | no | NONE | 91/93 | excluded compiler | UID0000LU |
| `57f637-57f640` | UID0002RL | padding | no | NONE | 91/93 | compiler | no-code |
| `57f640-57f695` | UID0002RL | Pane2 scalar deleting destructor | no | NONE | 91/93 | target compiler | UID0000DO destructor/H |
| `57f695-57f6a0` | UID0002RL | padding | no | NONE | 91/93 | compiler | no-code |
| `57f6a0-57f742` | UID0002RL | legacy scalar deleting destructor | no | NONE | 91/93 | target compiler | UID0000DN destructor/H |
| `57f742-57f750` | UID0001IH successor boundary | padding before macro controls | no | NONE | boundary | excluded | no-code/outside parent |
| `62cfd8-62d064` | UID00026J | legacy RTTI/vtable triad | no direct source | mixed rdata | 87/92 | target compiler data | UID0000DN H regenerates |
| `62d064-62d0f0` | UID00026J / UID0000LU | NewSpell RTTI/vtables | no direct source | mixed rdata | 87/92 | excluded | UID0000LU H regenerates |
| `62d0f0-62d17c` | UID00026J | Pane2 RTTI/vtable triad | no direct source | mixed rdata | 87/92 | target compiler data | UID0000DO H regenerates |
| `62d17c-62d196` | UID00026J | `L"SPELLINV.EPD"` | source literal | 0000DN | 87/92 | target | UID0000DN CPP |
| `62d196-62d198` | UID00026J | alignment | no | mixed rdata | 87/92 | exact | no-code |
| `62d198-62d1a6` | UID00026J | `L"%c: %s"` | source literal/shared | 0000DN | 87/92 | target consumer | UID0000DN CPP |
| `62d1a6-62d1a8` | UID00026J | alignment | no | mixed rdata | 87/92 | exact | no-code |
| `62d1a8-62d1c2` | UID00026J | `L"SPELLINV.EPF"` | source literal/shared | 0000DO/0000LU | 87/92 | target P2 consumer | UID00044I CPP |
| `62d1c2-62d1d0` | UID00026J | alignment/zeros | no | mixed rdata | 87/92 | exact | no-code |
| `62d1d0-62d1e0` | UID00026J | RectBounds `{12,20,22,41}` | source constant | 0000DO | 87/92 | target | UID00044I CPP |
| `62d1e0-62d418` | UID00026J / UID0003DB | Macro control data/strings | no target source | MacroDialogs | current | excluded | no target CPP/H |
| target layouts | UID0000DN/UID0000DO class pages | two 0x100 classes | yes | 0000O1 | recommended | source-owned | formal H below |
| external types | PanelPane/Event/RectBounds/SpellCommandSlotRecord/InterfaceEfx | imported types | external | respective owners | current | dependencies | include/forward-declare only |
| resource dependencies | `MAGEFX.EPD`,`INTEFX.PAD`,`SPELLBUT.EPD`,`NPAL6.PAL`,`ITEMINV.PAL` | external resources/literals | external | InterfaceEfx/render inventory | current | dependencies | string use only; no ownership move |
| globals/statics | none discovered | no target storage definition | n/a | n/a | n/a | negative complete | anonymous compile-time constants only |

Inventory reconciliation: 94 rows above cover every discovered root/class/index, exact code/gap/table/compiler row, rdata/resource row, type/import group, and negative global category. Every source row maps to formal CPP/H below; every excluded/compiler/padding row has a no-code or external destination.

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `57c2d0` constructor | zero inbound; calls PanelPane ctor, InterfaceEfx ctor/new | source constructor; route proved structurally |
| `57c3a0` destructor | zero direct inbound; vtable family/wrapper support; calls MarkForDeletion/base dtor | ordinary source destructor |
| `57c410` | vtable data ref `62d024`; called indirectly by packet virtual | legacy `OnActivate` |
| `57c430` | fourteen external prompt-family callers; no target caller | excluded shared state setter |
| `57c440` | zero inbound; tail-calls InterfaceEfx::Play | retained private effect method |
| `57c450` | vtable ref `62d020`; resource refs `62d17c/62d198` | legacy paint |
| `57c710` | vtable ref `62d034`; calls EventMan translator | key virtual |
| `57c790` | vtable ref `62d030`; calls activate/page/row/ordinal helpers | mouse virtual |
| `57c980` | vtable ref `62d03c`; indirect call to `57c410` slot | packet virtual |
| `57c9b0` | calls at `57c84f`,`57c934`; input-pane/map/packet callees | legacy activation dispatcher |
| `57cc44` table | data ref from legacy switch | compiler-lowered switch table |
| `57cc70` | zero start xrefs; PacketBuffer/Socket calls | retained inline candidate |
| `57ccd0` | call at `57c887` | live page rect helper |
| `57cd60`,`57cdc0` | zero start xrefs; behavior inlined in live callers | retained geometry helpers |
| `57ce70` | calls at `57c80d`,`57c902` | legacy row hit-test |
| `57cf10` | calls at `57c836`,`57c923` | legacy visible mapper |
| `57ea60` constructor | zero inbound; vtable stores `62d0f4/144/174` | raw Pane2 constructor |
| `57eaa0` destructor | zero direct inbound; vtable stores/base dtor | ordinary source destructor |
| `57eac0` | vtable ref `62d13c`; indirect calls from packet method | Pane2 `OnActivate` |
| `57eae0`,`57eaf0` | zero start/pointer xrefs | retained setter; protected no-op respectively |
| `57eb00` | vtable ref `62d138`; refs EPF and rect constants | Pane2 paint |
| `57edb0` | vtable ref `62d14c`; EventMan call | Pane2 key virtual |
| `57ee30` | vtable ref `62d148`; calls activate/row/ordinal | Pane2 mouse virtual |
| `57f000` | vtable ref `62d154`; indirect call to OnActivate slot | Pane2 packet virtual |
| `57f030` | caller `57eeef`; switch-table data at `57f26c` | Pane2 activation |
| `57f290`,`57f2f0`,`57f380`,`57f3e0` | zero start xrefs; complete source bodies/inlined behavior | retained private/static helpers |
| `57f490` | caller `57eead` | ten-row hit-test |
| `57f530` | caller `57eed6` | visible mapper |
| `57f5a1`,`57f5ac`,`57f640` | vtable-only ABI routes | Pane2 compiler support |
| `57f5b7`,`57f5c2`,`57f6a0` | vtable-only ABI routes | legacy compiler support |
| legacy vtables | stores from `57c2d0`,`57c3a0`,`57f6a0`; method data refs | compiler data regenerated by class |
| Pane2 vtables | stores from `57ea60`,`57eaa0`,`57f640`; method data refs | compiler data regenerated by class |
| `SPELLINV.EPD` | ref `57c488` | legacy resource literal |
| `%c: %s` | target ref `57c560` plus unrelated consumers | source literal, not exclusive data owner |
| `SPELLINV.EPF` | refs `57d49b` external NewSpell and `57eb38` target | shared resource literal |
| rect constants | ref `57eba2` | Pane2 initial text rectangle |

Padding, alignment, and boundary rows in the exhaustive inventory have no semantic xrefs beyond fallthrough/alignment and receive no source definition.

## Documentation Evidence And IDA Status
- Supporting current docs correctly establish broad class/file relationships, spell record layout, input-pane dependencies, and compiler/non-emitter policy.
- The accepted callbacks repaired the broad target contents, legacy empty emitter, Pane2 roles/types/row constant/ranges, routes, and UID00044D. Its formal constructor now includes `m_isLastPage(false)`, and its current `## Reconstruction Notes`/`## C++ Disposition` prose states the explicit `+0xf9` write made by the observed word clear.
- IDA state used for this repair was healthy and read-only. Every current handoff prestate was reread from only `supervisor_uid0000ih_canonical_verify_20260822_1450`; the older failed UID0000O1 transaction is historical evidence only, and Gate 2B requires a distinct fresh supervisor transaction. The handoff remains recommendations only.
- Validator commands `000000026432`, `000000026502`, and `000000026517` are historical snapshots that predate the correction. Current callback command `000000026749` emits the corrected UID00044D initializer list; fresh independent supervisor Gate 2A verification remains C-O1-054.

## Ranked Ownership Analysis

### 1. UID0000O1 SpellInventoryPane.cpp
- Evidence for: legacy/P2 naming, class routes, shared resources, current projected tree, vtable clusters, and absence of another Pane2 file owner.
- Evidence against: stripped original filename; the two code islands are separated by NewSpell code.
- Decision: accepted. Link-order interleaving does not outweigh the direct class/file routes and separate NewSpell audit.

### 2. New standalone SpellInventoryPane2.cpp
- Evidence for: Pane2 is a distinct class and code island.
- Evidence against: no by-file owner, no distinct resource/source route, current direct owner is UID0000O1, and shared filename family is stronger.
- Decision: rejected as unnecessary and less supported.

### 3. UID0000LU or UID0000NJ family merge
- Evidence for: physical adjacency/shared resources for NewSpell; constructor relationship for ScrollSpell.
- Evidence against: independent accepted whole-file audits, separate generated CPP/H, distinct class owners and ranges.
- Decision: rejected.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file. Keep `NexusTK/ui/inventory/SpellInventoryPane.cpp` and add its missing generated sibling `SpellInventoryPane.h` through formal routes.
- Likely full contents: two class declarations, legacy class definitions, Pane2 child definitions, anonymous compile-time constants, resource literals, and dependency includes.
- Rejected items: NewSpell, ScrollSpell, shared state helper UID0001II, compiler thunks/wrappers, raw vtable bytes, and macro rdata.
- Source-file inference: narrow two-class UI inventory compilation unit.

## Source Placement
- Recommended placement: `NexusTK/ui/inventory/SpellInventoryPane.cpp` and `.h`.
- Context: matches current inventory module tree and `InventoryPane.cpp/.h`; the classes consume UI pane, Event, UserPane, input-dialog, map, network, and render APIs.
- Rejected placements: generic controls, SpellInputPanes, TargetSelectionInputPanes, Socket, UserPane, InterfaceEfx, NewSpell, ScrollSpell, and a new Pane2 file. Those are dependencies or separately audited siblings.
- Remaining uncertainty: original stripped filename cannot be symbol-proved; current source tree and ownership graph are sufficient for reconstruction.

## Range / Split / Padding / Reclassification Analysis
- Exact range facts are exhaustive in Function / Child Inventory.
- Reclassify UID0002RI to a non-emitting split/index and preserve UID0001II as an overlapping exact external child.
- Rename UID00044F path/title to `0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate.md` and UID00044L to `0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage.md`.
- Rename raw child ranges to UID00044G `[57eae0,57eaf0)`, UID00044N `[57f290,57f2f0)`, UID00044O `[57f2f0,57f371)`, UID00044P `[57f380,57f3d3)`, and UID00044Q `[57f3e0,57f488)`; update every inbound link and parent range table.
- Add missing Pane2 gaps `[57eda4,57edb0)`, `[57ee2c,57ee30)`, `[57eff7,57f000)`, `[57f028,57f030)`, and `[57f523,57f530)` to UID0002RK. Reject the former `[57eaee,57eaf0)` gap because those bytes are the setter's `retn 4` immediate.
- Jump tables remain owned control-flow data inside UID0002RI/UID00044M but emit only through the source `switch` statements.
- Parent impact: UID0001IH remains non-emitting and must reflect the repaired child paths/roles without becoming a source owner.

## Negative Evidence Summary
- No direct constructor xref is not evidence of no source; class vtable/store/destructor symmetry proves constructors.
- Consumer calls into input panes, Socket, UserPane, InterfaceEfx, map panes, and render helpers do not transfer source ownership.
- No raw-helper start xref is not padding proof; complete bodies and inlined copies support retained private helpers.
- Shared `%c: %s` and `SPELLINV.EPF` literals are not exclusive file ownership proof; only target consumer source belongs here.
- The one-byte no-op has no defensible method identity, so a fabricated declaration is rejected.
- Physical proximity to NewSpell and macro rdata is insufficient to merge their source.

## IDA Rename / Type / Comment Recommendations
This is a structured supervisor-only Gate 2B handoff, not an executable transaction. B005 performed only read-only research. Authored-phase prestates came from target-unrelated session `2e5d96cf`; failed sessions `supervisor_uid0000o1_gate2b_20260822_1134` and `supervisor_uid0000o1_gate2b_20260822_2253` are historical only. The later anonymous-M01 attempt and the earlier physical-F03 attempt are also unsaved history: the latter passed U01.a/U01.b/U02 and M01/M02, then stopped after M03 rename/type/recompile and physical frame readback, before M03 comment or save. Its 14-call dirty prefix is evidence only and is neither reusable nor current. Strict transaction `UID0000O1-20260823-173839262-strict` / session `supervisor_uid0000o1_gate2b_strict_20260823_173839` later passed U01.a/U01.b/U02 and M01-M10 only, then failed at M11/F11; its prematurely batched M11 comment is rejected unsaved history. Independent no-comment sessions `supervisor_uid0000o1_f11_probe_20260823_1756` and `supervisor_uid0000o1_f20_probe_20260823_1759` supply authoritative expected-poststate F11/F20 evidence only. Every clean prestate below was freshly reread beginning `2026-08-22T16:29:46Z` from the one exact canonical session `supervisor_uid0000ih_canonical_verify_20260822_1450` at `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; the U01/U02 declaration-scope prestates and parser analogues came separately from healthy canonical read-only session `supervisor_uid0000mm_canonical_verify_20260822_1745`. The direct M03 and F11/F20 post-type receipts supply expected-poststate evidence, not prestate or persistence credit. B005 issued no mutation or save.

Artifact boundary: this handoff contains structured entity rows and inline literal endpoint payloads only, not an executable script or report-local operational persistence package. No UID0000O1 inert companion exists, is linked, or is credited; zero-script proof comes from the active report's physical fence/content scan.

### Gate 2B Authority And Fail-Closed Order

1. Public `tools/list` must expose exactly one `runtime_attestation`, no public `runtime/attest`, and the current schemas for `inspect_items`, `entity_query`, `type_inspect`, `get_comments`, `stack_frame`, `get_bytes`, `xref_query`, `declare_type`, `define_func`, `rename`, `set_type`, `set_function_comments`, `set_address_repeatable_comments`, and `force_recompile`. Any absence, duplicate, schema mismatch, listener/session error, or route mismatch stops Gate 2B before mutation.
2. Define `DB` only as a newly returned supervisor-owned read/write session opened from a fresh clean physical copy of the exact authorized canonical. The failed `supervisor_uid0000o1_gate2b_20260822_1134` session and every later dirty unsaved UID0000O1 session are forbidden as `DB`; no stopped prefix may be resumed. Require `server_health.status:"ok"`, correct module/imagebase, bounded target reads, and `runtime_attestation({expected_database:DB,expected_canonical_path:CANON})` top-level `ok:true`, exact worker/session/path route, and role-specific listener/worker module baselines. `auto_analysis_ready:false` alone is not a stop when these checks and bounded reads succeed.
3. Before each actionable row, reread its exact item/function/type/frame/comments/bytes/xrefs against the fresh-current matrices below. Separately reread every R01-R09 raw-protection row and require its exact no-function/no-name/no-type/no-frame/comment/byte/boundary/xref prestate. A literal prestate mismatch, occupied modeled proposed name, existing target UDT, changed boundary, unexpected raw function/model, or unexpected comment stops before mutation. Never set `allow_overwrite:true`; never define or type an R row; never undefine, patch bytes, rename a collision, or absorb a neighbor.
4. Apply one actionable logical row at a time in listed order: U01.a, immediate U01.a readback, U01.b, immediate U01.b readback, U02, M01-M21, then N01. U01 remains one logical claim row but contains two non-combinable `declare_type` calls. Every M `set_type(kind:function)` signature must be the row's complete named declarator; an anonymous signature, omitted/mismatched function identifier, parser error, normalized semantic-type mismatch, or frame mismatch stops before comment/next row. After a successful modeled `set_type`, call `force_recompile` only for that function. Read back the proposed entity name separately from normalized semantic type and physical frame, then range/comments/bytes/xrefs, before advancing. Never batch an M comment ahead of its frame gate: the abandoned strict transaction applied M11's comment in unsaved memory before surfacing F11 drift, and that batching-order defect receives no evidence or implementation credit. The fresh topology remains 24 logical actionable rows and exactly 88 primitive mutation calls: U01.a/U01.b/U02 are three calls, M01-M21 are 84 calls, and N01 is one call. Neither stopped historical prefix receives completion credit or can shorten the fresh 88-call attempt. R01-R09 receive no action and must be reread unchanged both before the first mutation and in the final aggregate protection pass.
5. Record exact pre/action/post/protection receipts in `tools/leaser/Agents/b-report-validation-audit.md` under a distinct UID0000O1 supervisor Gate 2B audit entry. That audit entry, not this recommendation text, is the Gate 2B completion authority. Saving/persistence remains separately supervisor-owned under the current workflow and is not specified by an executable package here.

Fresh public-surface check found exactly one `runtime_attestation`, no `runtime/attest`, one `idb_save`, and every read/mutation endpoint named here. Schema-safe call forms used by the narrowed handoff are literal: `inspect_items({database:DB,addrs:ADDRS})`; `entity_query({database:DB,queries:QUERIES})`; `type_inspect({database:DB,queries:QUERIES})`; `get_comments({database:DB,addrs:ADDRS})`; `stack_frame({database:DB,addrs:ADDRS})`; `get_bytes({database:DB,regions:REGIONS})`; `xref_query({database:DB,queries:QUERIES})`; `rename({database:DB,batch:PAYLOAD})`; `set_type({database:DB,edits:EDITS})`; `set_function_comments({database:DB,items:ITEMS})`; `set_address_repeatable_comments({database:DB,items:ITEMS})`; `force_recompile({database:DB,items:[{addr:EA}]})`; and `declare_type({database:DB,decls:DECLS})`. Current `set_type` exposes `edits[].addr`, `kind`, and `signature`; its typed fixture uses complete form `int __fastcall sum_point(struct Point *p)`, and the isolated M01 rejection proves an anonymous `RETURN CC(PARAMS)` string is not accepted as a function type. Therefore every M edit below uses `kind:"function"` and exact `signature:"RETURN CC PROPOSED_NAME(PARAMS)"`. `define_func` is deliberately not called for R01-R09. Function renames are name-only and always use `pure:true`, `allow_overwrite:false`, `dry_run:false`, and `stop_on_error:true`.

Comment prestate token `C0` means the literal fresh-current `get_comments` result `regular:"", repeatable:"", function_regular:"", function_repeatable:""`. Every M row and N01 starts at `C0`; every R row freshly returned only `regular:"", repeatable:""` because no function exists. Only `function_regular` may change in M rows. R01-R09 remain no-function rows with both address channels empty; no function-comment channels may be created. Address regular, address repeatable, and function repeatable remain empty for every modeled action.

Shared protection `P0` applies to every row: exact instruction bytes and SHA256 receipts below, non-target names, function/item boundaries, exact-entry inbound/outbound xref sets below, locals, saved-register rows, return-address rows, unaffected argument rows, all unlisted comment channels, jump tables `[0x57cc44,0x57cc64)` and `[0x57f26c,0x57f28c)`, every documented padding span including `[0x57eabf,0x57eac0)`, compiler island `[0x57f58b,0x57f742)`, vtable/RTTI ranges `[0x62cfd8,0x62d064)` and `[0x62d0f0,0x62d17c)`, and external ownership remain byte-for-byte/model-for-model unchanged. F03/F14 authorize only their exact typed `activationData@0x4/4:const unsigned __int8 *` addition while preserving `__return_address@0x0/4:_UNKNOWN *`; no other frame row or local/stack rename is permitted. F11/F20 authorize no physical frame delta: `row@0x28/0x4:int; column@0x2c/0x4:int` remain exact, and public normalized type names `y, x` do not authorize a stack/local rename. Before U01.a, global `InterfaceEfx` and both nested target spellings must be absent. After U01.a and through the final aggregate pass, global `InterfaceEfx` must remain exactly incomplete (`declaration:InterfaceEfx`, sentinel size `18446744073709551615`, `is_udt:false`, zero members), both nested target spellings must remain absent, and no full InterfaceEfx layout/member/type-owner mutation is permitted. For R01-R09, P0 additionally requires no containing function, no name/type/frame, no function-comment channels, and unchanged empty address comments. No row authorizes byte patching, data creation, raw function definition, function-tail movement, thunk/wrapper renaming, vtable typing, or InterfaceEfx completion.

### UDT Actions

Fresh-current canonical `type_inspect` prestates: `SpellInventoryPane`, `SpellInventoryPane2`, global `InterfaceEfx`, `SpellInventoryPane::InterfaceEfx`, and `SpellInventoryPane2::InterfaceEfx` are each absent with literal `Type not found`. Protected external layouts are `PanelPane` size `0xf8`, member `_paneBase@0x0/0xf8:unsigned __int8[248]`; `Event` size `0x110`, members `vftable@0x0/4:void *`, `m_type@0x4/1:unsigned __int8`, `_gap5@0x5/3:unsigned __int8[3]`, `m_payload@0x8/0x108:EventPayload`; `RectBounds` size `0x10`, four `int` members `left/top/right/bottom@0/4/8/c`; `SpellCommandSlotRecord` size `0x148`, members `active@0/1:unsigned __int8`, `reserved001@1/3:unsigned __int8[3]`, `inputKind@4/4:int`, `displayName@8/0xa0:wchar_t[80]`, `prompt@a8/0xa0:wchar_t[80]`. Read-only parser proof is deterministic: pre-existing global incomplete `FunctionObject0` binds `LogoPane.m_completionCallback` as `FunctionObject0 *` with no nested type, while unresolved member-local `struct ObjectPane` in `LightingObjectPane` remains displayed as `struct LightingObjectPane::ObjectPane *` even though global `ObjectPane` exists. Therefore the global forward declaration must precede the full pane declaration; any target-name collision or protected-layout drift stops before U01.a.

| ID | Exact `declare_type` action data | Required readback / protection | Claims |
| --- | --- | --- | --- |
| U01.a | First and alone: `decls:["struct InterfaceEfx;"]` | Immediate `type_inspect(include_members:true)` must return global `InterfaceEfx` with `exists:true`, `declaration:InterfaceEfx`, sentinel size `18446744073709551615`, `is_udt:false`, `members:null`, `member_count:0`; both target UDTs and both nested target InterfaceEfx spellings remain absent; protected external layouts remain exact. Stop before U01.b on any delta. | C-O1-005, C-O1-046, C-O1-051 |
| U01.b | Only after U01.a passes: `decls:["struct SpellInventoryPane { PanelPane _panelPane; unsigned __int8 m_pageIndex; bool m_isLastPage; bool m_spellInputActive; unsigned __int8 m_reservedFB; struct InterfaceEfx *m_spellEffect; };"]` | Immediate `type_inspect(include_members:true)` must return `SpellInventoryPane` UDT size `0x100`; `_panelPane@0/0xf8:PanelPane`, `m_pageIndex@f8/1:unsigned __int8`, `m_isLastPage@f9/1:bool`, `m_spellInputActive@fa/1:bool`, `m_reservedFB@fb/1:unsigned __int8`, `m_spellEffect@fc/4:struct InterfaceEfx *`. Global `InterfaceEfx` remains the exact incomplete U01.a object; `SpellInventoryPane::InterfaceEfx` and `SpellInventoryPane2::InterfaceEfx` remain absent; no nested/full InterfaceEfx type is accepted; protected layouts remain exact. Stop before U02 on any delta. | C-O1-005, C-O1-046, C-O1-051 |
| U02 | Only after U01.b passes: `decls:["struct SpellInventoryPane2 { PanelPane _panelPane; unsigned __int8 m_pageIndex; bool m_isLastPage; bool m_spellInputActive; unsigned __int8 m_reservedFB[5]; };"]` | `type_inspect(include_members:true)` => UDT size `0x100`; `_panelPane@0/0xf8:PanelPane`, `m_pageIndex@f8/1:unsigned __int8`, `m_isLastPage@f9/1:bool`, `m_spellInputActive@fa/1:bool`, `m_reservedFB@fb/5:unsigned __int8[5]`; U01.b's global-pointer member remains exact, global InterfaceEfx remains incomplete, both nested spellings remain absent, and all protected types remain exact. U02 has no InterfaceEfx field or declaration-scope dependency beyond preserving U01. | C-O1-008, C-O1-047, C-O1-051 |

### Modeled Function Actions

Each prestate gives the exact current function range, entry instruction item, name, type, frame ID, and `C0`. For every row the deterministic operation order is: exact pre-read; collision query; pure rename and name/range readback; `set_type` with the complete named declarator; exact-address `force_recompile`; separate proposed-name and normalized semantic-type/frame/range readback; `set_function_comments`; all-channel comment readback; final byte/xref/protection readback. Before rename, `entity_query({database:DB,queries:[{kind:"names",regex:"^NEW_NAME$",count:1}]})` must return `total:0` and empty `data`. The `set_type` result must be `ok:true` with no `error`; the entity-name channel must equal the proposed identifier, while the type channel must equal the corresponding anonymous normalized function type in `### Named Function Declarator Parser Contract`. No readback may require the function identifier to be embedded in IDA's normalized type string.

| ID | Exact entity and literal prestate | Exact rename payload; exact type edits; exact regular function comment | Required post-readback / claims |
| --- | --- | --- | --- |
| M01 | function `[57c2d0,57c39f)`, entry item `[57c2d0,57c2d1)`, `sub_57C2D0`, `_DWORD *__thiscall(_DWORD *this)`, F01, C0 | `{func:[{addr:"0x57c2d0",name:"SpellInventoryPane__Constructor"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57c2d0",kind:"function",signature:"SpellInventoryPane *__thiscall SpellInventoryPane__Constructor(SpellInventoryPane *this)"}]`; `{addr:"0x57c2d0",comment:"Constructs legacy spell inventory pane and its MAGEFX InterfaceEfx."}` | exact proposed name plus normalized type `SpellInventoryPane *__thiscall(SpellInventoryPane *this)`, same comment/range/bytes/xrefs, F01; C-O1-011,C-O1-051 |
| M02 | `[57c3a0,57c401)`, entry `[57c3a0,57c3a1)`, `sub_57C3A0`, `void __thiscall(_DWORD *this)`, F02, C0 | `{func:[{addr:"0x57c3a0",name:"SpellInventoryPane__Destructor"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57c3a0",kind:"function",signature:"void __thiscall SpellInventoryPane__Destructor(SpellInventoryPane *this)"}]`; `{addr:"0x57c3a0",comment:"Ordinary destructor; marks m_spellEffect for deletion before PanelPane cleanup."}` | exact proposed name plus normalized type `void __thiscall(SpellInventoryPane *this)`, F02/P0; C-O1-012,C-O1-051 |
| M03 | `[57c410,57c425)`, entry `[57c410,57c412)`, `sub_57C410`, `int __thiscall(_WORD *this, int)`, F03, C0 | `{func:[{addr:"0x57c410",name:"SpellInventoryPane__OnActivate"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57c410",kind:"function",signature:"void __thiscall SpellInventoryPane__OnActivate(SpellInventoryPane *this, const unsigned __int8 *activationData)"}]`; `{addr:"0x57c410",comment:"Resets packed page state and invalidates the pane."}` | after type/recompile and before comment/M04: exact proposed name, normalized type `void __thiscall(SpellInventoryPane *this, const unsigned __int8 *activationData)`, and deterministic observed F03 `__return_address@0x0/4:_UNKNOWN *; activationData@0x4/4:const unsigned __int8 *`; preserve the return row and permit only that typed-formal addition, with no local/saved-register/other argument row; source behavior remains no body stack-formal access; stop before comment/M04 on any mismatch; P0; C-O1-013,C-O1-051 |
| M04 | `[57c440,57c44b)`, entry `[57c440,57c446)`, `sub_57C440`, `int __thiscall(unsigned __int16 **this)`, F04, C0 | `{func:[{addr:"0x57c440",name:"SpellInventoryPane__PlaySpellEffect"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57c440",kind:"function",signature:"void __thiscall SpellInventoryPane__PlaySpellEffect(SpellInventoryPane *this)"}]`; `{addr:"0x57c440",comment:"Starts the pane-owned InterfaceEfx animation."}` | exact proposed name plus normalized type `void __thiscall(SpellInventoryPane *this)`, F04/P0; C-O1-014,C-O1-051 |
| M05 | `[57c450,57c710)`, entry `[57c450,57c451)`, `sub_57C450`, `int __thiscall(int this)`, F05, C0 | `{func:[{addr:"0x57c450",name:"SpellInventoryPane__OnPaint"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57c450",kind:"function",signature:"void __thiscall SpellInventoryPane__OnPaint(SpellInventoryPane *this)"}]`; `{addr:"0x57c450",comment:"Paints 13 learned spells per page and page controls from SPELLINV.EPD."}` | exact proposed name plus normalized type `void __thiscall(SpellInventoryPane *this)`, F05/P0; C-O1-015,C-O1-051 |
| M06 | `[57c710,57c78c)`, entry `[57c710,57c711)`, `sub_57C710`, `char __thiscall(_BYTE *this, _BYTE *)`, F06, C0 | `{func:[{addr:"0x57c710",name:"SpellInventoryPane__OnKeyEvent"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57c710",kind:"function",signature:"bool __thiscall SpellInventoryPane__OnKeyEvent(SpellInventoryPane *this, Event *event)"}]`; `{addr:"0x57c710",comment:"Handles unmodified Page Up/Page Down navigation."}` | exact proposed name plus normalized type `bool __thiscall(SpellInventoryPane *this, Event *event)`, F06/P0; C-O1-016,C-O1-051 |
| M07 | `[57c790,57c979)`, entry `[57c790,57c791)`, `sub_57C790`, `char __userpurge@<al>(char *@<ecx>, int@<ebx>, int)`, F07, C0 | `{func:[{addr:"0x57c790",name:"SpellInventoryPane__OnMouseEvent"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57c790",kind:"function",signature:"bool __thiscall SpellInventoryPane__OnMouseEvent(SpellInventoryPane *this, Event *event)"}]`; `{addr:"0x57c790",comment:"Handles page buttons and single/double-click spell activation."}` | exact proposed name plus normalized type `bool __thiscall(SpellInventoryPane *this, Event *event)`, F07/P0; C-O1-017,C-O1-051 |
| M08 | `[57c980,57c9a8)`, entry `[57c980,57c981)`, `sub_57C980`, `char __thiscall(_DWORD *this, int)`, F08, C0 | `{func:[{addr:"0x57c980",name:"SpellInventoryPane__OnServerMessage"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57c980",kind:"function",signature:"bool __thiscall SpellInventoryPane__OnServerMessage(SpellInventoryPane *this, Event *event)"}]`; `{addr:"0x57c980",comment:"For packet opcodes 23/24, calls OnActivate(0); always returns false."}` | exact proposed name plus normalized type `bool __thiscall(SpellInventoryPane *this, Event *event)`, F08/P0; C-O1-018,C-O1-051 |
| M09 | `[57c9b0,57cc42)`, entry `[57c9b0,57c9b1)`, `sub_57C9B0`, `_DWORD *__userpurge@<eax>(int@<ecx>, int@<ebx>, char)`, F09, C0 | `{func:[{addr:"0x57c9b0",name:"SpellInventoryPane__ActivateSpellSlot"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57c9b0",kind:"function",signature:"void __thiscall SpellInventoryPane__ActivateSpellSlot(SpellInventoryPane *this, unsigned __int8 spellSlot)"}]`; `{addr:"0x57c9b0",comment:"Dispatches learned spell slot 1..52 to prompt, target, or direct packet route."}` | exact proposed name plus normalized type `void __thiscall(SpellInventoryPane *this, unsigned __int8 spellSlot)`, F09/P0; C-O1-019,C-O1-051 |
| M10 | `[57ccd0,57cd51)`, entry `[57ccd0,57ccd1)`, `sub_57CCD0`, `int __stdcall(__int16, _DWORD *)`, F10, C0 | `{func:[{addr:"0x57ccd0",name:"SpellInventoryPane__BuildPageButtonRect"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57ccd0",kind:"function",signature:"void __stdcall SpellInventoryPane__BuildPageButtonRect(__int16 button, RectBounds *bounds)"}]`; `{addr:"0x57ccd0",comment:"Builds previous/next page button bounds."}` | exact proposed name plus normalized non-const type `void __stdcall(__int16 button, RectBounds *bounds)`, F10/P0; C-O1-022,C-O1-051 |
| M11 | `[57ce70,57cf03)`, entry `[57ce70,57ce71)`, `sub_57CE70`, `__int16 __stdcall(int, int)`, F11, C0 | `{func:[{addr:"0x57ce70",name:"SpellInventoryPane__HitTestSpellRow"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57ce70",kind:"function",signature:"__int16 __stdcall SpellInventoryPane__HitTestSpellRow(int y, int x)"}]`; `{addr:"0x57ce70",comment:"Returns legacy row 0..12 or -1."}` | after type/recompile and before comment/M12: exact proposed name plus normalized public type `__int16 __stdcall(int y, int x)` and exact physical F11 `row@0x28/0x4:int; column@0x2c/0x4:int`; no stack/local rename or frame delta; only after that gate set the exact function comment, preserving every other comment channel/range/byte/xref/P0; C-O1-025,C-O1-051 |
| M12 | `[57cf10,57cf6b)`, entry `[57cf10,57cf11)`, `sub_57CF10`, `int __stdcall(__int16)`, F12, C0 | `{func:[{addr:"0x57cf10",name:"SpellInventoryPane__VisibleOrdinalToSpellSlot"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57cf10",kind:"function",signature:"int __stdcall SpellInventoryPane__VisibleOrdinalToSpellSlot(__int16 visibleOrdinal)"}]`; `{addr:"0x57cf10",comment:"Maps learned-spell ordinal to one-based slot 1..52."}` | exact proposed name plus normalized type `int __stdcall(__int16 visibleOrdinal)`, F12/P0; C-O1-025,C-O1-051 |
| M13 | `[57eaa0,57eabf)`, entry `[57eaa0,57eaa6)`, `sub_57EAA0`, `void __thiscall(_DWORD *this)`, F13, C0; protected one-byte data item `[57eabf,57eac0)` is `CC`, SHA256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6` | `{func:[{addr:"0x57eaa0",name:"SpellInventoryPane2__Destructor"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57eaa0",kind:"function",signature:"void __thiscall SpellInventoryPane2__Destructor(SpellInventoryPane2 *this)"}]`; `{addr:"0x57eaa0",comment:"Ordinary Pane2 destructor and PanelPane cleanup."}` | exact proposed name plus normalized type `void __thiscall(SpellInventoryPane2 *this)`; function remains `[57eaa0,57eabf)`, `[57eabf,57eac0)` remains data byte `CC` with the same hash, F13/P0; C-O1-027,C-O1-051 |
| M14 | `[57eac0,57ead5)`, entry `[57eac0,57eac2)`, `sub_57EAC0`, `int __thiscall(_WORD *this, int)`, F14, C0 | `{func:[{addr:"0x57eac0",name:"SpellInventoryPane2__OnActivate"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57eac0",kind:"function",signature:"void __thiscall SpellInventoryPane2__OnActivate(SpellInventoryPane2 *this, const unsigned __int8 *activationData)"}]`; `{addr:"0x57eac0",comment:"Resets packed page state and invalidates the pane."}` | after type/recompile and before comment/M15: exact proposed name, normalized type `void __thiscall(SpellInventoryPane2 *this, const unsigned __int8 *activationData)`, and deterministic inferred F14 `__return_address@0x0/4:_UNKNOWN *; activationData@0x4/4:const unsigned __int8 *`; preserve the return row and permit only that typed-formal addition, with no local/saved-register/other argument row; expectation is `>=0.99` from M03's direct receipt plus identical 21-byte body/hash, clean current frame, and named-formal shape; source behavior remains no body stack-formal access; stop before comment/M15 on any mismatch; P0; C-O1-028,C-O1-051 |
| M15 | `[57eb00,57eda4)`, entry `[57eb00,57eb01)`, `sub_57EB00`, `char __thiscall(int this)`, F15, C0 | `{func:[{addr:"0x57eb00",name:"SpellInventoryPane2__OnPaint"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57eb00",kind:"function",signature:"void __thiscall SpellInventoryPane2__OnPaint(SpellInventoryPane2 *this)"}]`; `{addr:"0x57eb00",comment:"Paints 13-entry pages; clickable geometry is separately 10 rows."}` | exact proposed name plus normalized type `void __thiscall(SpellInventoryPane2 *this)`, F15/P0; C-O1-031,C-O1-051 |
| M16 | `[57edb0,57ee2c)`, entry `[57edb0,57edb1)`, `sub_57EDB0`, `char __thiscall(_BYTE *this, _BYTE *)`, F16, C0 | `{func:[{addr:"0x57edb0",name:"SpellInventoryPane2__OnKeyEvent"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57edb0",kind:"function",signature:"bool __thiscall SpellInventoryPane2__OnKeyEvent(SpellInventoryPane2 *this, Event *event)"}]`; `{addr:"0x57edb0",comment:"Handles unmodified Page Up/Page Down navigation."}` | exact proposed name plus normalized type `bool __thiscall(SpellInventoryPane2 *this, Event *event)`, F16/P0; C-O1-032,C-O1-051 |
| M17 | `[57ee30,57eff7)`, entry `[57ee30,57ee31)`, `sub_57EE30`, `char __thiscall(char *this, int)`, F17, C0 | `{func:[{addr:"0x57ee30",name:"SpellInventoryPane2__OnMouseEvent"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57ee30",kind:"function",signature:"bool __thiscall SpellInventoryPane2__OnMouseEvent(SpellInventoryPane2 *this, Event *event)"}]`; `{addr:"0x57ee30",comment:"Handles page buttons and activation using page stride 13 and hit rows 0..9."}` | exact proposed name plus normalized type `bool __thiscall(SpellInventoryPane2 *this, Event *event)`, F17/P0; C-O1-033,C-O1-051 |
| M18 | `[57f000,57f028)`, entry `[57f000,57f001)`, `sub_57F000`, `char __thiscall(_DWORD *this, int)`, F18, C0 | `{func:[{addr:"0x57f000",name:"SpellInventoryPane2__OnServerMessage"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57f000",kind:"function",signature:"bool __thiscall SpellInventoryPane2__OnServerMessage(SpellInventoryPane2 *this, Event *event)"}]`; `{addr:"0x57f000",comment:"For packet opcodes 23/24, calls OnActivate(0); always returns false."}` | exact proposed name plus normalized type `bool __thiscall(SpellInventoryPane2 *this, Event *event)`, F18/P0; C-O1-034,C-O1-051 |
| M19 | `[57f030,57f26c)`, entry `[57f030,57f031)`, `sub_57F030`, `_DWORD *__userpurge@<eax>(int@<ecx>, int@<ebx>, char)`, F19, C0 | `{func:[{addr:"0x57f030",name:"SpellInventoryPane2__ActivateSpellSlot"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57f030",kind:"function",signature:"void __thiscall SpellInventoryPane2__ActivateSpellSlot(SpellInventoryPane2 *this, unsigned __int8 spellSlot)"}]`; `{addr:"0x57f030",comment:"Dispatches learned spell slots through eight input-kind routes."}` | exact proposed name plus normalized type `void __thiscall(SpellInventoryPane2 *this, unsigned __int8 spellSlot)`, F19/P0; C-O1-035,C-O1-051 |
| M20 | `[57f490,57f523)`, entry `[57f490,57f491)`, `sub_57F490`, `__int16 __stdcall(int, int)`, F20, C0 | `{func:[{addr:"0x57f490",name:"SpellInventoryPane2__HitTestSpellRow"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57f490",kind:"function",signature:"__int16 __stdcall SpellInventoryPane2__HitTestSpellRow(int y, int x)"}]`; `{addr:"0x57f490",comment:"Scans exactly ten rows 0..9."}` | after type/recompile and before comment/M21: exact proposed name plus normalized public type `__int16 __stdcall(int y, int x)` and exact physical F20 `row@0x28/0x4:int; column@0x2c/0x4:int`; no stack/local rename or frame delta; only after that gate set the exact function comment, preserving every other comment channel/range/byte/xref/P0; C-O1-040,C-O1-051 |
| M21 | `[57f530,57f58b)`, entry `[57f530,57f531)`, `sub_57F530`, `int __stdcall(__int16)`, F21, C0 | `{func:[{addr:"0x57f530",name:"SpellInventoryPane2__VisibleOrdinalToSpellSlot"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`; `[{addr:"0x57f530",kind:"function",signature:"int __stdcall SpellInventoryPane2__VisibleOrdinalToSpellSlot(__int16 visibleOrdinal)"}]`; `{addr:"0x57f530",comment:"Maps active learned-spell ordinal to slot 1..52."}` | exact proposed name plus normalized type `int __stdcall(__int16 visibleOrdinal)`, F21/P0; C-O1-041,C-O1-051 |

### Named Function Declarator Parser Contract

Only M01's prior anonymous payload was attempted, and it was rejected before prototype mutation. M02-M21 were not attempted in that isolated transaction; their prior strings are historical report payloads, not runtime failures. For each fresh M row, the middle column is the only authorized `edits[].signature`. After success, the proposed function name must be exact in the entity-name channel and the right column must be exact in IDA's normalized type channel; stripping the declarator identifier during type normalization is expected and does not permit any return/calling-convention/parameter drift. The later direct M03 receipt establishes that applying the named semantic type can materialize its unused named stack formal as a physical frame row even when the function body never accesses that stack slot. This is type-application behavior, not source/body-access evidence: M03/F03 therefore requires the observed two-row frame, and parallel M14/F14 requires the same two-row frame at `>=0.99` confidence from the identical 21-byte body/hash, clean current frame, and activation-data declarator, with a fresh fail-closed readback. Conversely, independent M11/M20 probes prove that normalized public parameters `y, x` do not rename their pre-existing physical frame rows: F11/F20 must preserve `row, column` exactly, and the declarator matrix authorizes no frame-row rename.

| ID | Prior anonymous report payload | Required named `set_type(kind:function)` declarator -> normalized type readback |
| --- | --- | --- |
| M01 | `SpellInventoryPane *__thiscall(SpellInventoryPane *this)` | `SpellInventoryPane *__thiscall SpellInventoryPane__Constructor(SpellInventoryPane *this)` -> `SpellInventoryPane *__thiscall(SpellInventoryPane *this)` |
| M02 | `void __thiscall(SpellInventoryPane *this)` | `void __thiscall SpellInventoryPane__Destructor(SpellInventoryPane *this)` -> `void __thiscall(SpellInventoryPane *this)` |
| M03 | `void __thiscall(SpellInventoryPane *this, const unsigned __int8 *activationData)` | `void __thiscall SpellInventoryPane__OnActivate(SpellInventoryPane *this, const unsigned __int8 *activationData)` -> `void __thiscall(SpellInventoryPane *this, const unsigned __int8 *activationData)` |
| M04 | `void __thiscall(SpellInventoryPane *this)` | `void __thiscall SpellInventoryPane__PlaySpellEffect(SpellInventoryPane *this)` -> `void __thiscall(SpellInventoryPane *this)` |
| M05 | `void __thiscall(SpellInventoryPane *this)` | `void __thiscall SpellInventoryPane__OnPaint(SpellInventoryPane *this)` -> `void __thiscall(SpellInventoryPane *this)` |
| M06 | `bool __thiscall(SpellInventoryPane *this, Event *event)` | `bool __thiscall SpellInventoryPane__OnKeyEvent(SpellInventoryPane *this, Event *event)` -> `bool __thiscall(SpellInventoryPane *this, Event *event)` |
| M07 | `bool __thiscall(SpellInventoryPane *this, Event *event)` | `bool __thiscall SpellInventoryPane__OnMouseEvent(SpellInventoryPane *this, Event *event)` -> `bool __thiscall(SpellInventoryPane *this, Event *event)` |
| M08 | `bool __thiscall(SpellInventoryPane *this, Event *event)` | `bool __thiscall SpellInventoryPane__OnServerMessage(SpellInventoryPane *this, Event *event)` -> `bool __thiscall(SpellInventoryPane *this, Event *event)` |
| M09 | `void __thiscall(SpellInventoryPane *this, unsigned __int8 spellSlot)` | `void __thiscall SpellInventoryPane__ActivateSpellSlot(SpellInventoryPane *this, unsigned __int8 spellSlot)` -> `void __thiscall(SpellInventoryPane *this, unsigned __int8 spellSlot)` |
| M10 | `void __stdcall(__int16 button, RectBounds *bounds)` | `void __stdcall SpellInventoryPane__BuildPageButtonRect(__int16 button, RectBounds *bounds)` -> `void __stdcall(__int16 button, RectBounds *bounds)` |
| M11 | `__int16 __stdcall(int y, int x)` | `__int16 __stdcall SpellInventoryPane__HitTestSpellRow(int y, int x)` -> `__int16 __stdcall(int y, int x)`; F11 remains physical `row@0x28/0x4:int; column@0x2c/0x4:int` |
| M12 | `int __stdcall(__int16 visibleOrdinal)` | `int __stdcall SpellInventoryPane__VisibleOrdinalToSpellSlot(__int16 visibleOrdinal)` -> `int __stdcall(__int16 visibleOrdinal)` |
| M13 | `void __thiscall(SpellInventoryPane2 *this)` | `void __thiscall SpellInventoryPane2__Destructor(SpellInventoryPane2 *this)` -> `void __thiscall(SpellInventoryPane2 *this)` |
| M14 | `void __thiscall(SpellInventoryPane2 *this, const unsigned __int8 *activationData)` | `void __thiscall SpellInventoryPane2__OnActivate(SpellInventoryPane2 *this, const unsigned __int8 *activationData)` -> `void __thiscall(SpellInventoryPane2 *this, const unsigned __int8 *activationData)` |
| M15 | `void __thiscall(SpellInventoryPane2 *this)` | `void __thiscall SpellInventoryPane2__OnPaint(SpellInventoryPane2 *this)` -> `void __thiscall(SpellInventoryPane2 *this)` |
| M16 | `bool __thiscall(SpellInventoryPane2 *this, Event *event)` | `bool __thiscall SpellInventoryPane2__OnKeyEvent(SpellInventoryPane2 *this, Event *event)` -> `bool __thiscall(SpellInventoryPane2 *this, Event *event)` |
| M17 | `bool __thiscall(SpellInventoryPane2 *this, Event *event)` | `bool __thiscall SpellInventoryPane2__OnMouseEvent(SpellInventoryPane2 *this, Event *event)` -> `bool __thiscall(SpellInventoryPane2 *this, Event *event)` |
| M18 | `bool __thiscall(SpellInventoryPane2 *this, Event *event)` | `bool __thiscall SpellInventoryPane2__OnServerMessage(SpellInventoryPane2 *this, Event *event)` -> `bool __thiscall(SpellInventoryPane2 *this, Event *event)` |
| M19 | `void __thiscall(SpellInventoryPane2 *this, unsigned __int8 spellSlot)` | `void __thiscall SpellInventoryPane2__ActivateSpellSlot(SpellInventoryPane2 *this, unsigned __int8 spellSlot)` -> `void __thiscall(SpellInventoryPane2 *this, unsigned __int8 spellSlot)` |
| M20 | `__int16 __stdcall(int y, int x)` | `__int16 __stdcall SpellInventoryPane2__HitTestSpellRow(int y, int x)` -> `__int16 __stdcall(int y, int x)`; F20 remains physical `row@0x28/0x4:int; column@0x2c/0x4:int` |
| M21 | `int __stdcall(__int16 visibleOrdinal)` | `int __stdcall SpellInventoryPane2__VisibleOrdinalToSpellSlot(__int16 visibleOrdinal)` -> `int __stdcall(__int16 visibleOrdinal)` |

### Fresh-Current Modeled Receipts

The current repair reread all 21 modeled functions from only `supervisor_uid0000ih_canonical_verify_20260822_1450`. `get_comments` returned C0 for every row; `stack_frame` returned the exact F01-F21 rows below; every modeled entry/range/name/item matched its row above except the separately documented M13 historical-end correction; and one combined exact-name collision query for all 30 researched M/R identities returned `total:0` and empty `data`. Only the 21 M identities remain actionable; the nine R identities are evidence labels under the no-action raw contracts. The following SHA256 values cover each complete current function range, and each xref set is the exact same-session set at the function entry (`none` means empty):

| ID | Bytes / SHA256 | Exact-entry inbound xrefs | Exact-entry outbound xrefs |
| --- | --- | --- | --- |
| M01 | 207 / `8E677FC69C2C25CD3AA7EA23EB55AD28F0B1D3A04F5F6887471B03633130C777` | none | `57c2d1` |
| M02 | 97 / `A330C3DD9E4925E2357FF3D383C474B3221D15AB924238D068BFC910B896E37F` | none | `57c3a1` |
| M03 | 21 / `FE4EABE1DC86355D6DD992105D26E3C01F64AA7A03673E0415C7269659F3C0A5` | `62d024` | `57c412` |
| M04 | 11 / `E191CFB901B4001FE04EF7EC049BA090CFDF25AA72691DC9B9F2683790AD9C95` | none | `57c446` |
| M05 | 704 / `EA654C2FB4BC608E7B772FA6C02DB5F59D91604722979328E74FA84904B88CAC` | `62d020` | `57c451` |
| M06 | 124 / `F94EE7CDB09A3EC8013F6FEAED74EA942FD6A1B3623F9DD2A8D9EECB35B4F4F9` | `62d034` | `57c711` |
| M07 | 489 / `EBE13E76AABFD2A2810B1C0597060B7B162742B975337181B964B0E31A26417A` | `62d030` | `57c791` |
| M08 | 40 / `55362FD77407D446E3CEE60DFD20A84B99A2EE6017E8BD3CFB221059F31B6A8B` | `62d03c` | `57c981` |
| M09 | 658 / `F0B0B1F5281EE37047FAE69EBD7B17C5F78B46A621CEAE02A3568FB150B89C56` | `57c84f`, `57c934` | `57c9b1` |
| M10 | 129 / `4845FC7CC67B4B07D895256F421BB402775234962D0782FD4A2CEBD30C05B7C1` | `57c887` | `57ccd1` |
| M11 | 147 / `207C81656264435202DCCF249E12720445C0211AE75BFDAE76BCBD03762FD174` | `57c80d`, `57c902` | `57ce71` |
| M12 | 91 / `719BC0BD46BC32052650F99B52B147D81F1BF4477E88CE7EED3C1C84ACD575EF` | `57c836`, `57c923` | `57cf11` |
| M13 | 31 / `B39AD4D1C126DA3B08D4AF4EBC27E1E3542BDDEB06F36AFD41304C0C8B22D1AC` | none | `57eaa6`, `62d0f4` |
| M14 | 21 / `FE4EABE1DC86355D6DD992105D26E3C01F64AA7A03673E0415C7269659F3C0A5` | `62d13c` | `57eac2` |
| M15 | 676 / `69E8BF71862785638EC333F978E186B69AB1B72C4244722AF57A87F216A95099` | `62d138` | `57eb01` |
| M16 | 124 / `452BAE24FAB4029C9C5EEAE3FF2BBC965DCC397C5C31F1D87FEB84736ADA78A3` | `62d14c` | `57edb1` |
| M17 | 455 / `C74E37ABC40976B0E5ACAD3B505CFFC093C688D0A76366897F8DCC4EC080E786` | `62d148` | `57ee31` |
| M18 | 40 / `55362FD77407D446E3CEE60DFD20A84B99A2EE6017E8BD3CFB221059F31B6A8B` | `62d154` | `57f001` |
| M19 | 572 / `5085AD36AB0A15BDEEBC067B82DD0756CC30D95D8FBB61917240B27FB1344B97` | `57eeef` | `57f031` |
| M20 | 147 / `B2540C3EA16A5023C028D4F9BF1FD6732292444A20D6E83768AEF16E4F7C5991` | `57eead` | `57f491` |
| M21 | 91 / `719BC0BD46BC32052650F99B52B147D81F1BF4477E88CE7EED3C1C84ACD575EF` | `57eed6` | `57f531` |

Expected-poststate probe receipts are separate from those one-session current prestates. In `supervisor_uid0000o1_f11_probe_20260823_1756`, exact named type application at `0x57ce70` returned entity `SpellInventoryPane__HitTestSpellRow`, public type/prototype `__int16 __stdcall(int y, int x)`, physical frame `row@0x28/0x4:int; column@0x2c/0x4:int`, and blank regular/repeatable/function comment channels. In `supervisor_uid0000o1_f20_probe_20260823_1759`, exact named type application at `0x57f490` returned entity `SpellInventoryPane2__HitTestSpellRow`, the same public type/prototype, the same physical frame, and all comments blank. These probes independently prove zero F11/F20 physical-frame delta. The strict transaction's prematurely batched M11 comment is excluded from this evidence and supplies no action credit.

Eight fresh-current prototypes from the one canonical session differ from superseded historical values and are the literal preconditions for the proposed prototype-only changes. M13 has a separate boundary-only correction. Historical values below are comparison evidence only and never supply a current prestate. These deltas do not authorize bytes, xrefs, ranges, comments, locals, saved-register rows, return-address rows, or unlisted stack arguments to change:

| ID | Superseded historical type, not current prestate | One-session fresh-current type | Sole proposed type-model delta |
| --- | --- | --- | --- |
| M01 | `PanelPane *__thiscall(PanelPane *this)` | `_DWORD *__thiscall(_DWORD *this)` | return/`this` become `SpellInventoryPane *`; calling convention and physical frame remain unchanged |
| M02 | `void __thiscall(PanelPane *this)` | `void __thiscall(_DWORD *this)` | only `this` becomes `SpellInventoryPane *` |
| M05 | failed UID0000O1 transaction channel: `void __thiscall(GrafPort *this)` | canonical session `func_profile` and `inspect_items`: `int __thiscall(int this)` | return becomes `void`; `this` becomes `SpellInventoryPane *` |
| M07 | `char __thiscall(char *this, int)` | `char __userpurge@<al>(char *@<ecx>, int@<ebx>, int)` | return becomes `bool`; convention becomes `__thiscall`; ECX becomes `SpellInventoryPane *`; the modeled EBX formal is removed; sole stack formal becomes `Event *`; physical F07 rows remain governed only by the listed F07 argument delta |
| M09 | `void __thiscall(int this, unsigned __int8)` | `_DWORD *__userpurge@<eax>(int@<ecx>, int@<ebx>, char)` | return becomes `void`; convention becomes `__thiscall`; ECX becomes `SpellInventoryPane *`; the modeled EBX formal is removed; stack byte becomes `unsigned __int8`; physical F09 rows remain governed only by the listed F09 argument delta |
| M10 | `void __stdcall(__int16, struct RectBounds *bounds)` | `int __stdcall(__int16, _DWORD *)` | return becomes `void`; first formal gains name `button`; second becomes non-const `RectBounds *` |
| M15 | `char __thiscall(GrafPort *this)` | `char __thiscall(int this)` | return becomes `void`; `this` becomes `SpellInventoryPane2 *` |
| M19 | `void __thiscall(int this, char)` | `_DWORD *__userpurge@<eax>(int@<ecx>, int@<ebx>, char)` | return becomes `void`; convention becomes `__thiscall`; ECX becomes `SpellInventoryPane2 *`; the modeled EBX formal is removed; stack byte becomes `unsigned __int8`; physical F19 rows remain governed only by the listed F19 argument delta |

M13's rejected stale range was `[57eaa0,57eac0)`. It is currently the 31-byte function `[57eaa0,57eabf)`, whose last code item is `[57eaba,57eabf)`; the separate one-byte data item `[57eabf,57eac0)` is `CC` (SHA256 `1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6`) and must remain data. No action may extend M13 through that protected byte.

M05 one-session proof: in `supervisor_uid0000ih_canonical_verify_20260822_1450`, both public read channels returned `int __thiscall(int this)` for `sub_57C450` at function `[57c450,57c710)` and entry item `[57c450,57c451)`. The same session returned C0 comments, exact F05, 704 bytes with SHA256 `EA654C2FB4BC608E7B772FA6C02DB5F59D91604722979328E74FA84904B88CAC`, inbound xref `62d020`, and outbound flow `57c451`. The old transaction's `void __thiscall(GrafPort *this)` result is retained only in the explicitly historical comparison column and is not a current precondition.

M11/M20 delta disposition: neither row has a semantic type-shape delta beyond adding public parameter names in the accepted named declarator/normalized presentation. Independent physical probes prove that this public `y, x` presentation leaves existing physical argument rows `row, column` unchanged. No stack/local rename action is present, implied, or permitted.

### Modeled Frame Contracts

The `Current protected rows` column is the literal fresh-current `stack_frame` result from the canonical-derived session. Every listed local, saved-register, return-address, and unaffected argument row must survive exactly. Only the enumerated argument-row delta is permitted after `set_type`; no local row may be renamed or retyped. The old `2026-08-22` return-address-only F03/F14 post-type prediction and the later F11/F20 physical-`y`/`x` prediction are failed unsaved-transaction history only. Direct M03 type/recompile readback proved that public type application materializes `activationData@0x4/4:const unsigned __int8 *` beside the preserved return row even though the body has no stack-formal access. M14 has the identical 21-byte body/SHA256, clean current return-only frame, and corresponding named activation-data declarator, so its same two-row post-type contract is a deterministic `>=0.99` parallel inference; any different fresh result stops before comment/M15. Independent blank-comment M11/M20 probes instead prove exact zero-delta F11/F20 frames: the public type remains `y, x`, while physical rows remain `row, column`. The strict M11 comment batching defect is uncredited and must not recur. These physical type-model results do not change the researched source behavior. M01/M02/M05/M07/M09/M10/M15/M19 must start from the corrected types above; M07/M09/M19's current EBX register formals are type-model prestates, not stack rows, and their permitted removal does not authorize any additional F07/F09/F19 frame delta.

| Frame | Current protected rows | Sole permitted argument-row delta after typing |
| --- | --- | --- |
| F01 | locals `Block@8/4:void *; var_10@c/4:PanelPane *; var_C@10/4:_DWORD; var_4@18/4:_DWORD`; ABI `__saved_registers@1c/4:_DWORD; __return_address@20/4:_UNKNOWN *`; unaffected `arg_4@28/4:_DWORD` | none |
| F02 | local `var_C@8/4:_DWORD`; ABI `__saved_registers@14/4:_DWORD; __return_address@18/4:_UNKNOWN *`; unaffected `arg_4@20/4:_DWORD` | none |
| F03 | ABI `__return_address@0/4:_UNKNOWN *`; no locals/arguments | deterministic exact observed post-type frame: preserved `__return_address@0x0/4:_UNKNOWN *` plus sole added `activationData@0x4/4:const unsigned __int8 *`; no local, saved-register, or other argument row is permitted; direct unsaved M03 receipt, verify before comment/M04 |
| F04 | ABI `__return_address@0/4:_UNKNOWN *`; no locals/arguments | none |
| F05 | locals `point@c/8:Point; var_144@14/4:_DWORD; var_140@18/4:_DWORD; outContext@1c/28:EPFTileContext; bounds@44/10:struct RectBounds; Buffer@54/2:wchar_t; var_4@154/4:_DWORD`; ABI `__saved_registers@158/4:_DWORD; __return_address@15c/4:_UNKNOWN *` | none |
| F06 | ABI `__saved_registers@8/4:_DWORD; __return_address@c/4:_UNKNOWN *`; current `arg_0@10/4:_DWORD` | only `arg_0` -> `event@10/4:Event *` |
| F07 | locals `var_24@4/4:_DWORD; row@8/4:int; column@c/4:int; var_15@13/1:_BYTE; bounds@14/10:MapRect; var_4@24/4:_DWORD`; ABI `__saved_registers@28/4:_DWORD; __return_address@2c/4:_UNKNOWN *`; current `arg_0@30/4:_DWORD` | only `arg_0` -> `event@30/4:Event *` |
| F08 | ABI `__saved_registers@0/4:_DWORD; __return_address@4/4:_UNKNOWN *`; current `arg_0@8/4:_DWORD` | only `arg_0` -> `event@8/4:Event *` |
| F09 | locals `var_A4@10/8:MapPoint; position@18/8:MapPoint; spellIndex@20/4:char[4]; Src@24/1:_BYTE; destination@25/1:unsigned __int8; var_8E@26/1:_BYTE; var_10@a4/4:_DWORD; var_C@a8/4:_DWORD; var_4@b0/4:_DWORD`; ABI `__saved_registers@b4/4:_DWORD; __return_address@b8/4:_UNKNOWN *`; current `arg_0@bc/1:_BYTE`; unaffected `arg_4@c0/4:_DWORD` | only `arg_0` -> `spellSlot@bc/1:unsigned __int8` |
| F10 | ABI `__saved_registers@4/4:_DWORD; __return_address@8/4:_UNKNOWN *`; current `arg_0@c/2:_WORD`; unaffected `bounds@10/4:struct RectBounds *` | only `arg_0` -> `button@c/2:__int16`; `bounds` must remain non-const |
| F11 | locals `bounds@c/10:struct RectBounds; var_4@1c/4:_DWORD`; ABI `__saved_registers@20/4:_DWORD; __return_address@24/4:_UNKNOWN *`; current `row@28/4:int; column@2c/4:int` | none; exact post-type frame preserves physical `row@0x28/0x4:int; column@0x2c/0x4:int`; public type parameters remain `y, x`, with no stack/local rename permitted; independent blank-comment F11 probe |
| F12 | ABI `__saved_registers@c/4:_DWORD; __return_address@10/4:_UNKNOWN *`; current `arg_0@14/2:_WORD` | only `arg_0` -> `visibleOrdinal@14/2:__int16` |
| F13 | ABI `__return_address@0/4:_UNKNOWN *`; no locals/arguments | none |
| F14 | ABI `__return_address@0/4:_UNKNOWN *`; no locals/arguments | deterministic exact inferred post-type frame: preserved `__return_address@0x0/4:_UNKNOWN *` plus sole added `activationData@0x4/4:const unsigned __int8 *`; no local, saved-register, or other argument row is permitted; `>=0.99` parallel inference from M03 and identical M14 body/hash/current frame/declarator, verify before comment/M15 |
| F15 | locals `var_148@c/4:_DWORD; var_144@10/4:_DWORD; var_140@14/4:_DWORD; outContext@18/28:EPFTileContext; var_114@40/10:RectBounds; Buffer@50/2:wchar_t; var_4@150/4:_DWORD`; ABI `__saved_registers@154/4:_DWORD; __return_address@158/4:_UNKNOWN *` | none |
| F16 | ABI `__saved_registers@8/4:_DWORD; __return_address@c/4:_UNKNOWN *`; current `arg_0@10/4:_DWORD` | only `arg_0` -> `event@10/4:Event *` |
| F17 | locals `var_24@4/4:_DWORD; row@8/4:int; column@c/4:int; var_15@13/1:_BYTE; bounds@14/10:struct RectBounds; var_4@24/4:_DWORD`; ABI `__saved_registers@28/4:_DWORD; __return_address@2c/4:_UNKNOWN *`; current `arg_0@30/4:_DWORD` | only `arg_0` -> `event@30/4:Event *` |
| F18 | ABI `__saved_registers@0/4:_DWORD; __return_address@4/4:_UNKNOWN *`; current `arg_0@8/4:_DWORD` | only `arg_0` -> `event@8/4:Event *` |
| F19 | locals `Block@c/4:void *; spellIndex@10/4:char[4]; Src@14/1:_BYTE; destination@15/1:unsigned __int8; var_8E@16/1:_BYTE; var_10@94/4:_DWORD; var_C@98/4:_DWORD; var_4@a0/4:_DWORD`; ABI `__saved_registers@a4/4:_DWORD; __return_address@a8/4:_UNKNOWN *`; current `arg_0@ac/1:_BYTE`; unaffected `arg_4@b0/4:_DWORD` | only `arg_0` -> `spellSlot@ac/1:unsigned __int8` |
| F20 | locals `bounds@c/10:struct RectBounds; var_4@1c/4:_DWORD`; ABI `__saved_registers@20/4:_DWORD; __return_address@24/4:_UNKNOWN *`; current `row@28/4:int; column@2c/4:int` | none; exact post-type frame preserves physical `row@0x28/0x4:int; column@0x2c/0x4:int`; public type parameters remain `y, x`, with no stack/local rename permitted; independent blank-comment F20 probe |
| F21 | ABI `__saved_registers@c/4:_DWORD; __return_address@10/4:_UNKNOWN *`; current `arg_0@14/2:_WORD` | only `arg_0` -> `visibleOrdinal@14/2:__int16` |

### Raw No-Action Protection Contracts

For every R row, the fresh-current prestate is: no containing function, no name/type/frame, zero inbound xrefs to the exact start, empty regular/repeatable address comments, decoded code instruction items throughout the exact byte span, and the literal bytes below. Complete future post-`define_func`/post-`set_type` frames cannot be established without performing the forbidden mutation, so R01-R09 are narrowed to deterministic no-action protections. The researched source-facing identity/signature/comment remains evidence for formal CPP/H and ordinary documentation only; it is not an IDA action. `define_func`, `rename`, `set_type`, `force_recompile`, and comment mutation are forbidden for these rows. For each D01-D09 the complete current and required final frame contract is literal `stack_frame` error `No function found`: local set empty, saved-register set empty, return-address set empty, argument set empty, permitted delta none, and every row absence protected. Any created function, frame, local, ABI row, argument, name, type, or comment is drift and fails Gate 2B.

Fresh bounded `insn_query` completed without truncation for all nine spans and returned the exact counts/last instructions below. Full-range `get_bytes` independently matched every literal byte string in the action table and produced these SHA256 receipts. Each raw start has no inbound xref and exactly the listed current outbound flow xref:

| ID | Bytes / SHA256 | Instructions / first..last | Exact-entry inbound / outbound |
| --- | --- | --- | --- |
| R01 | 96 / `A50E7B563D3261F9AF9918E33140A0520B0F3328A95C629287D8437A754ABA26` | 28 / `57cc70..57cccd` | none / `57cc71` |
| R02 | 83 / `DE55714118B93A0C1CCB052BDE958D469E793A95A35A04C8D35BD5B5A283E362` | 36 / `57cd60..57cdb0` | none / `57cd61` |
| R03 | 168 / `E99C801F1F603521B32D32CC4B6491B26AC73DA9FEAFD0806613908F2FC15709` | 70 / `57cdc0..57ce65` | none / `57cdc1` |
| R04 | 64 / `072B8384D285AAC0090642CB4CB1D8B112F7629DA6B63989F31F3DF08699340C` | 17 / `57ea60..57ea9f` | none / `57ea61` |
| R05 | 16 / `73CEDDE9AEAD9D734DD8476308B3D0785DEE5BA1B992396DE3F69348D39D0087` | 6 / `57eae0..57eaed` | none / `57eae1` |
| R06 | 96 / `F3A0F847DD7992C16C0C10205E09528838A190A33029DBAD1A9F59B9F2D5CADE` | 28 / `57f290..57f2ed` | none / `57f291` |
| R07 | 129 / `B419F55A9B6CEF63AD235E40B2A27BE9CF22F2584B140F648D2DC9D4035A8394` | 52 / `57f2f0..57f36e` | none / `57f2f1` |
| R08 | 83 / `C17CB999CD62DDB45B10533C73A80BBD6768CF1092F80EDCEE5A9404078245BA` | 36 / `57f380..57f3d0` | none / `57f381` |
| R09 | 168 / `03C57D99FAF502B3CE66E442B9ABE5DF21604EADB99D25067ACEF249DD1E6F6C` | 70 / `57f3e0..57f485` | none / `57f3e1` |

| ID | Exact raw prestate: range, first/last code items, boundary, literal bytes | Preserved research identity and deterministic IDA disposition | Complete D-frame contract / claims |
| --- | --- | --- | --- |
| R01 | `[57cc70,57ccd0)`; first `[57cc70,57cc71)`, last `[57cccd,57ccd0)`; predecessor data `[57cc64,57cc70)`, successor M10; bytes `558BEC81EC84000000A1242F670033C58945FC8D857CFFFFFF506A0FE8EF86FFFF8D857DFFFFFF500FB6450850E8DE86FFFF8B0DECA767008D857CFFFFFF83C410C6857EFFFFFF006A0250E8F07EFFFF8B4DFC33CDE865AA04008BE55DC20400` | Research identity `SpellInventoryPane__SendDirectSpellPacket`, source signature `void __thiscall(SpellInventoryPane *this, unsigned __int8 spellSlot)`, note `Retained private direct-cast helper; zero direct start xrefs.`; no IDA action | D01 remains nonexistent: `stack_frame` -> `No function found`; locals `[]`; saved-registers `[]`; return-addresses `[]`; arguments `[]`; argument name/type/offset/width none; permitted delta none; protect every set empty and complete raw prestate; C-O1-021,C-O1-051 |
| R02 | `[57cd60,57cdb3)`; first `[57cd60,57cd61)`, last `[57cdb0,57cdb3)`; predecessor data `[57cd51,57cd60)`, successor data `[57cdb3,57cdc0)`; bytes `558BEC668B4508566683F80C772898BEAA0000006BC00DB9160000008D503383C04050565251FF750CE8C2AEF3FF83C4145E5DC2080083C9FF0BC10BF150560BD15251FF750CE8A5AEF3FF83C4145E5DC20800` | Research identity `SpellInventoryPane__BuildSpellRowRect`, source signature `void __stdcall(__int16 row, RectBounds *bounds)`, note `Retained 13-row geometry helper; zero direct start xrefs.`; no IDA action | D02 remains nonexistent: `stack_frame` -> `No function found`; locals `[]`; saved-registers `[]`; return-addresses `[]`; arguments `[]`; argument name/type/offset/width none; permitted delta none; protect every set empty and complete raw prestate; C-O1-023,C-O1-051 |
| R03 | `[57cdc0,57ce68)`; first `[57cdc0,57cdc1)`, last `[57ce65,57ce68)`; predecessor data `[57cdb3,57cdc0)`, successor data `[57ce68,57ce70)`; bytes `558BEC83EC14A1242F670033C58945FC538B5D0C565733F60FBFC683F8FF742B85C0741583F8017522B89D0000008D48408D50168D7852EB1BB80E000000B9DD0000008D50168D7912EB0983C8FF0BC80BD00BF8575251508D45EC50E82FAEF3FF8D45EC5053FF7508E852B0F3FF83C4203C01741D466683FE027C9C5F5E83C8FF5B8B4DFC33CDE8E3A804008BE55DC208008B4DFC668BC65F5E33CD5BE8CDA804008BE55DC20800` | Research identity `SpellInventoryPane__HitTestPageButton`, source signature `__int16 __stdcall(int y, int x)`, note `Retained page-button hit-test helper; zero direct start xrefs.`; no IDA action | D03 remains nonexistent: `stack_frame` -> `No function found`; locals `[]`; saved-registers `[]`; return-addresses `[]`; arguments `[]`; argument name/type/offset/width none; permitted delta none; protect every set empty and complete raw prestate; C-O1-024,C-O1-051 |
| R04 | `[57ea60,57eaa0)`; first `[57ea60,57ea61)`, last `[57ea9f,57eaa0)`; predecessor data `[57ea57,57ea60)`, successor M13; bytes `558BEC51568BF18975FCE82166FCFFC706F4D062008BC6C786A000000044D16200C786A400000074D1620066C786F80000000000C686FA000000005E8BE55DC3` | Research identity `SpellInventoryPane2__Constructor`, source signature `SpellInventoryPane2 *__thiscall(SpellInventoryPane2 *this)`, note `Raw Pane2 constructor; installs three vtables, explicitly clears m_pageIndex@+0xf8 and m_isLastPage@+0xf9 with one word store, then clears m_spellInputActive@+0xfa.`; no IDA action | D04 remains nonexistent: `stack_frame` -> `No function found`; locals `[]`; saved-registers `[]`; return-addresses `[]`; arguments `[]`; argument name/type/offset/width none; permitted delta none; protect every set empty and complete raw prestate; C-O1-026,C-O1-051 |
| R05 | `[57eae0,57eaf0)`; first `[57eae0,57eae1)`, last `[57eaed,57eaf0)`; predecessor data `[57ead5,57eae0)`, successor N01; bytes `558BEC8A45088881FA0000005DC20400` | Research identity `SpellInventoryPane2__SetSpellInputActive`, source signature `void __thiscall(SpellInventoryPane2 *this, bool active)`, note `Retained private setter; zero direct start xrefs; exact end includes the retn 4 immediate.`; no IDA action | D05 remains nonexistent: `stack_frame` -> `No function found`; locals `[]`; saved-registers `[]`; return-addresses `[]`; arguments `[]`; argument name/type/offset/width none; permitted delta none; protect every set empty and exact `[57eae0,57eaf0)` without a synthetic gap; C-O1-029,C-O1-042,C-O1-051 |
| R06 | `[57f290,57f2f0)`; first `[57f290,57f291)`, last `[57f2ed,57f2f0)`; predecessor data `[57f28c,57f290)`, successor R07; bytes `558BEC81EC84000000A1242F670033C58945FC8D857CFFFFFF506A0FE8CF60FFFF8D857DFFFFFF500FB6450850E8BE60FFFF8B0DECA767008D857CFFFFFF83C410C6857EFFFFFF006A0250E8D058FFFF8B4DFC33CDE8458404008BE55DC20400` | Research identity `SpellInventoryPane2__SendDirectSpellPacket`, source signature `void __thiscall(SpellInventoryPane2 *this, unsigned __int8 spellSlot)`, note `Retained private direct-cast helper; exact end includes the retn 4 immediate.`; no IDA action | D06 remains nonexistent: `stack_frame` -> `No function found`; locals `[]`; saved-registers `[]`; return-addresses `[]`; arguments `[]`; argument name/type/offset/width none; permitted delta none; protect every set empty and complete raw prestate; C-O1-036,C-O1-051 |
| R07 | `[57f2f0,57f371)`; first `[57f2f0,57f2f1)`, last `[57f36e,57f371)`; predecessor R06, successor data `[57f371,57f380)`; bytes `558BEC0FBF45085683F8FF745785C0742B83F801754EB89D000000BEEF00000056BAB3000000528D48405150FF750CE82C89F3FF83C4145E5DC20800BEEF000000BA240000005652B9DD000000B80E0000005150FF750CE80489F3FF83C4145E5DC2080083C8FF0BF00BD056520BC85150FF750CE8E788F3FF83C4145E5DC20800` | Research identity `SpellInventoryPane2__BuildPageButtonRect`, source signature `void __stdcall(__int16 button, RectBounds *bounds)`, note `Exact end includes the retn 8 immediate.`; no IDA action | D07 remains nonexistent: `stack_frame` -> `No function found`; locals `[]`; saved-registers `[]`; return-addresses `[]`; arguments `[]`; argument name/type/offset/width none; permitted delta none; protect every set empty and complete raw prestate; C-O1-037,C-O1-051 |
| R08 | `[57f380,57f3d3)`; first `[57f380,57f381)`, last `[57f3d0,57f3d3)`; predecessor data `[57f371,57f380)`, successor data `[57f3d3,57f3e0)`; bytes `558BEC668B4508566683F809772898BEAA0000006BC017B9020000008D500A83C02150565251FF750CE8A288F3FF83C4145E5DC2080083C9FF0BC10BF150560BD15251FF750CE88588F3FF83C4145E5DC20800` | Research identity `SpellInventoryPane2__BuildSpellRowRect`, source signature `void __stdcall(__int16 row, RectBounds *bounds)`, note `Builds rows 0..9; exact end includes the retn 8 immediate.`; no IDA action | D08 remains nonexistent: `stack_frame` -> `No function found`; locals `[]`; saved-registers `[]`; return-addresses `[]`; arguments `[]`; argument name/type/offset/width none; permitted delta none; protect every set empty and complete raw prestate; C-O1-038,C-O1-051 |
| R09 | `[57f3e0,57f488)`; first `[57f3e0,57f3e1)`, last `[57f485,57f488)`; predecessor data `[57f3d3,57f3e0)`, successor data `[57f488,57f490)`; bytes `558BEC83EC14A1242F670033C58945FC538B5D0C565733F60FBFC683F8FF742B85C0741583F8017522B89D0000008D48408D50168D7852EB1BB80E000000B9DD0000008D50168D7912EB0983C8FF0BC80BD00BF8575251508D45EC50E80F88F3FF8D45EC5053FF7508E8328AF3FF83C4203C01741D466683FE027C9C5F5E83C8FF5B8B4DFC33CDE8C38204008BE55DC208008B4DFC668BC65F5E33CD5BE8AD8204008BE55DC20800` | Research identity `SpellInventoryPane2__HitTestPageButton`, source signature `__int16 __stdcall(int y, int x)`, note `Returns button 0/1 or -1; exact end includes the retn 8 immediate.`; no IDA action | D09 remains nonexistent: `stack_frame` -> `No function found`; locals `[]`; saved-registers `[]`; return-addresses `[]`; arguments `[]`; argument name/type/offset/width none; permitted delta none; protect every set empty and complete raw prestate; C-O1-039,C-O1-051 |

### Comment-Only And Protected Readbacks

| ID/entity | Literal prestate | Exact action / required readback | Claims |
| --- | --- | --- | --- |
| N01 `57eaf0` | function `[57eaf0,57eaf1)`, entry item same, name `nullsub_55`, type `void()`, frame `__return_address@0/4:_UNKNOWN *`, C0, byte `C3`, SHA256 `AE3F4619B0413D70D3004B9131C3752153074E45725BE13B9A148978895E359E`, no inbound/outbound xrefs or pointer hit | `set_address_repeatable_comments` items `[{addr:"0x57eaf0",comment:"One-byte no-route source-empty body; method identity unresolved; do not invent a declaration."}]`; expected `repeatable` address channel exact; regular address/function and repeatable function channels empty; function/name/type/frame/byte/hash/xrefs unchanged | C-O1-030,C-O1-051 |
| P01 `57c430` external | function `[57c430,57c440)`, entry `[57c430,57c431)`, name `SpellInputPaneState__SetInputModeFlag`, type `void __thiscall(SpellInputPaneState *this, bool active)`, frame `__saved_registers@0/4:_DWORD; __return_address@4/4:_UNKNOWN *; active@8/1:bool`; address regular/repeatable and function repeatable empty; regular function comment `Source-facing SpellInputPaneState::SetInputModeFlag(bool); stores the Boolean at state offset +0xfa. AL is assignment residue, so source return is void.`; bytes `558BEC8A45088881FA0000005DC20400`; 16-byte SHA256 `73CEDDE9AEAD9D734DD8476308B3D0785DEE5BA1B992396DE3F69348D39D0087`; inbound xrefs `5ae037,5ae3e7,5b0877,5b0bb7,5b0e97,5b1127,5b1377,5b7c8e,5b7d5e,5b7e2e,5b7efe,5b7fce,5b809e,5b816e`; outbound `57c431` | no action; exact item/name/type/frame/comment/bytes/hash and fourteen external caller xrefs plus outbound flow must remain unchanged | C-O1-007,C-O1-051 |

Final aggregate readback must reproduce U01.a, U01.b, U02, M01-M21, N01, P01, every corrected type/range/byte-hash/xref receipt in the fresh-current matrices, every P0 protection, exactly 88 successful primitive mutation calls, and zero action/result errors. All 21 M `set_type` results must be `ok:true` for the exact named declarators, all 21 entity-name readbacks must equal their proposed names, and all 21 normalized type readbacks must equal `### Named Function Declarator Parser Contract`; no anonymous action payload remains authorized. Global `InterfaceEfx` must be the exact incomplete U01.a type, `m_spellEffect@fc/4` must be exactly global `struct InterfaceEfx *`, both nested target InterfaceEfx spellings must be absent, and no InterfaceEfx completeness/member change is accepted. No modeled function semantic type depends on InterfaceEfx; M01/M02/M04 comments merely name the externally owned effect object, and only the parser-required declarator identifiers changed in the M payloads. F03 and F14 must each be exactly `__return_address@0x0/4:_UNKNOWN *; activationData@0x4/4:const unsigned __int8 *`, with the return row preserved and no local, saved-register, or other argument row; F03 is direct unsaved physical evidence and F14 is the `>=0.99` same-body/hash/current-frame/declarator inference, and each must pass before its comment/next action. F11 and F20 must each preserve exact physical `row@0x28/0x4:int; column@0x2c/0x4:int` while entity/type channels expose the proposed names and public `__int16 __stdcall(int y, int x)`; there is no physical frame delta and no stack/local rename. Each F11/F20 frame must pass before its comment/next action, and every non-function comment channel remains protected. R01-R09 must remain raw with no containing function, name, type, frame, or function-comment channels; `stack_frame` must return `No function found` for D01-D09, both address-comment channels must remain empty, and every listed item/boundary/byte/hash/xref receipt must remain exact. No Gate 2B credit is valid unless the exact UID0000O1 audit entry records each actionable row, each named-declarator result and normalized type/name readback, F03's observed and F14's inferred exact physical frame, F11/F20 public-type versus preserved-physical-frame receipts, each global-versus-nested type readback, each raw no-action protection row, and the protected external types/ranges. The rejected 14-call prefix and abandoned strict transaction/M11 batch supply no credit: a fresh clean physical copy/session must complete the full 88-call attempt.

## First-Draft C++ Recommendation
- Eligible: UID0000DN, UID0000DO, and Pane2 reconstructable children. UID0002RI/UID0002RK/UID0002RL/UID00026J and UID00044H are no-code/compiler/index rows.
- Emitter order: UID0000DN `010`; UID0000DO `020`; UID00044D/E/F/G/I/J/K/L/M/N/O/P/Q/R/S `100/110/120/130/140/150/160/170/180/190/200/210/220/230/240`; UID00044H remains blank/non-emitting.
- Current application boundary: all report formal source below is preserved, and UID00044D's physical ordinary block now matches the three-initializer constructor shown here. C-O1-026 is applied after scoped validator command `000000026749` and physical generated CPP/H readback; C-O1-054 remains an independent supervisor Gate 2A check.
- UID0000DN exact `RECONSTRUCTION_CPP CODE`:

```cpp
#include "SpellInventoryPane.h"

#include <cwchar>

#include "../MainUiGraph.h"
#include "../InterfaceEfx.h"
#include "../core/Event.h"
#include "../core/RectBounds.h"
#include "../dialogs/SpellInputPanes.h"
#include "../dialogs/TargetSelectionInputPanes.h"
#include "../panels/UserPane.h"
#include "../../config/Config.h"
#include "../../map/LivingObjectPane.h"
#include "../../map/MapPane.h"
#include "../../network/PacketBuffer.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"

wchar_t SlotIndexToHotkeyLetter(int slot);

namespace
{
const int kSpellSlotCount = 52;
const int kSpellPageSize = 13;
const int kSpellClickableRows = 10;
}

SpellInventoryPane::SpellInventoryPane()
    : m_pageIndex(0),
      m_isLastPage(false),
      m_spellInputActive(false),
      m_spellEffect(new InterfaceEfx(
          L"MAGEFX.EPD", 50, 434, 12,
          g_mainUiLayerSlots.rootPaneLayerContext, false, L"INTEFX.PAD"))
{
}

SpellInventoryPane::~SpellInventoryPane()
{
    m_spellEffect->MarkForDeletion();
}

void SpellInventoryPane::OnActivate(const unsigned char *)
{
    m_pageIndex = 0;
    m_isLastPage = false;
    InvalidateRect(&m_visibleBounds);
}

void SpellInventoryPane::PlaySpellEffect()
{
    m_spellEffect->Play();
}

void SpellInventoryPane::OnPaint()
{
    EPFTileContext frame;
    g_pEPFLib->CopyEntryTileContext(L"SPELLINV.EPD", 0, &frame);
    RenderTileFrame(&frame, &frame.bounds,
                    &m_visibleBounds, 0, L"NPAL6.PAL", 0);

    int visibleOrdinal = 0;
    int slot = 1;
    while (slot <= kSpellSlotCount)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot);
        if (record->active && ++visibleOrdinal > m_pageIndex * kSpellPageSize)
            break;
        ++slot;
    }

    Point textPoint;
    InitPointPair(&textPoint, 63, 35);
    SetDrawColor(0x80);
    SetDrawMode(1);
    int drawn = 0;
    for (; slot <= kSpellSlotCount && drawn < kSpellPageSize; ++slot)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot);
        if (!record->active)
            continue;
        wchar_t text[128];
        swprintf_s(text, 128, L"%c: %s",
                   SlotIndexToHotkeyLetter(slot), record->displayName);
        MoveTo(textPoint.x, textPoint.y);
        DrawWideText(text, (int)wcslen(text));
        textPoint.y += 13;
        textPoint.x = 35;
        ++drawn;
    }

    m_isLastPage = true;
    for (; slot <= kSpellSlotCount; ++slot)
    {
        if (g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot)->active)
        {
            m_isLastPage = false;
            break;
        }
    }

    SetDrawColor(0x8f);
    SetDrawMode(2);
    RectBounds bounds;
    if (m_pageIndex == 0)
    {
        InitRectBounds(&bounds, 14, 221, 36, 239);
        g_pEPFLib->CopyEntryTileContext(L"SPELLBUT.EPD", 6, &frame);
        RenderTileFrame(&frame, &frame.bounds, &bounds, 0, L"NPAL6.PAL", 0);
    }
    if (m_isLastPage)
    {
        InitRectBounds(&bounds, 157, 221, 179, 239);
        g_pEPFLib->CopyEntryTileContext(L"SPELLBUT.EPD", 7, &frame);
        RenderTileFrame(&frame, &frame.bounds, &bounds, 0, L"NPAL6.PAL", 0);
    }
}

bool SpellInventoryPane::OnKeyEvent(Event *event)
{
    const int key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key, event->m_payload.m_key.m_modifiers);
    if (event->m_type != kEventKeyDown ||
        event->m_payload.m_key.m_modifiers != 0)
        return false;
    if (key == kPaneKeyPageUp)
    {
        if (m_pageIndex > 0)
        {
            --m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    if (key == kPaneKeyPageDown)
    {
        if (!m_isLastPage)
        {
            ++m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    return false;
}

bool SpellInventoryPane::OnMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    const int y = event->m_payload.m_pointer.m_y;
    const int x = event->m_payload.m_pointer.m_x;
    bool handled = false;
    if (event->m_type == kEventLeftButtonDown)
    {
        const int button = HitTestPageButton(y, x);
        if (button == 0 && m_pageIndex > 0)
        {
            --m_pageIndex;
            handled = true;
        }
        else if (button == 1 && !m_isLastPage)
        {
            ++m_pageIndex;
            handled = true;
        }
        if (handled)
            InvalidateRect(&m_visibleBounds);
        if (!g_pConfig->m_doubleClickEnabled && !m_spellInputActive && !handled)
        {
            const int row = HitTestSpellRow(y, x);
            if (row >= 0)
            {
                const int slot = VisibleOrdinalToSpellSlot(
                    (short)(m_pageIndex * kSpellPageSize + row + 1));
                if (slot != -1)
                {
                    ActivateSpellSlot((unsigned char)slot);
                    return true;
                }
            }
        }
        return handled;
    }
    if (event->m_type == kEventLeftButtonDoubleClick &&
        g_pConfig->m_doubleClickEnabled && !m_spellInputActive)
    {
        const int row = HitTestSpellRow(y, x);
        if (row >= 0)
        {
            const int slot = VisibleOrdinalToSpellSlot(
                (short)(m_pageIndex * kSpellPageSize + row + 1));
            if (slot != -1)
            {
                ActivateSpellSlot((unsigned char)slot);
                return true;
            }
        }
    }
    return false;
}

bool SpellInventoryPane::OnServerMessage(Event *event)
{
    const unsigned char *packet = static_cast<const unsigned char *>(
        event->m_payload.m_packet.m_data);
    if ((unsigned char)(packet[0] - 23) <= 1)
        OnActivate(0);
    return false;
}

void SpellInventoryPane::ActivateSpellSlot(unsigned char spellSlot)
{
    if ((unsigned char)(spellSlot - 1) > 51)
        return;
    SpellCommandSlotRecord *record =
        g_pUserPane->GetSpellCommandSlotRecord(spellSlot);
    if (!record->active)
        return;

    switch (record->inputKind)
    {
    case 1:
        new SpellStringInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 2:
        if (g_activeMapPane->m_selectedObjectActive &&
            g_activeMapPane->m_selectedObjectPane != 0)
        {
            LivingObjectPane *target = g_activeMapPane->m_selectedObjectPane;
            MapPoint position;
            target->GetMapPosition(&position);
            SendTargetedActionPacket(spellSlot,
                (unsigned int)target->GetObjectId(),
                (unsigned short)position.column,
                (unsigned short)position.row);
        }
        else
        {
            new SpellWhoInputPane((char)spellSlot);
            m_spellInputActive = true;
        }
        break;
    case 3:
        new SpellFourArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 4:
        new SpellThreeArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 5:
        SendDirectSpellPacket(spellSlot);
        m_spellInputActive = false;
        break;
    case 6:
        new SpellTwoArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 7:
        new SpellOneArgInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 8:
        new SpellSlotInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    }
}

void SpellInventoryPane::SendDirectSpellPacket(unsigned char spellSlot)
{
    unsigned char packet[3];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(spellSlot, packet + 1);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}

void __stdcall SpellInventoryPane::BuildPageButtonRect(
    short button, RectBounds *bounds)
{
    if (button == 0)
        InitRectBounds(bounds, 14, 221, 36, 239);
    else if (button == 1)
        InitRectBounds(bounds, 157, 221, 179, 239);
    else
        InitRectBounds(bounds, -1, -1, -1, -1);
}

void __stdcall SpellInventoryPane::BuildSpellRowRect(
    short row, RectBounds *bounds)
{
    if ((unsigned short)row < kSpellPageSize)
        InitRectBounds(bounds, 22, 51 + 13 * row, 170, 64 + 13 * row);
    else
        InitRectBounds(bounds, -1, -1, -1, -1);
}

short __stdcall SpellInventoryPane::HitTestPageButton(int y, int x)
{
    for (short button = 0; button < 2; ++button)
    {
        RectBounds bounds;
        BuildPageButtonRect(button, &bounds);
        if (PointInRect(y, x, &bounds))
            return button;
    }
    return -1;
}

short __stdcall SpellInventoryPane::HitTestSpellRow(int y, int x)
{
    for (short row = 0; row < kSpellPageSize; ++row)
    {
        RectBounds bounds;
        BuildSpellRowRect(row, &bounds);
        if (PointInRect(y, x, &bounds))
            return row;
    }
    return -1;
}

int __stdcall SpellInventoryPane::VisibleOrdinalToSpellSlot(short visibleOrdinal)
{
    for (int slot = 1; slot <= kSpellSlotCount; ++slot)
    {
        if (!g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot)->active)
            continue;
        if (--visibleOrdinal == 0)
            return slot;
    }
    return -1;
}
```

- UID0000DN exact `RECONSTRUCTION_H CODE`:

```cpp
#ifndef NEXUSTK_UI_INVENTORY_SPELLINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_SPELLINVENTORYPANE_H

#include "../core/PanelPane.h"
#include "../core/Event.h"
#include "../core/RectBounds.h"

class InterfaceEfx;

class SpellInventoryPane : public PanelPane
{
public:
    SpellInventoryPane();
    virtual ~SpellInventoryPane();

    virtual void OnActivate(const unsigned char *activationData);
    virtual void OnPaint();
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
    virtual bool OnServerMessage(Event *event);

private:
    void PlaySpellEffect();
    void ActivateSpellSlot(unsigned char spellSlot);
    void SendDirectSpellPacket(unsigned char spellSlot);
    static void __stdcall BuildPageButtonRect(short button, RectBounds *bounds);
    static void __stdcall BuildSpellRowRect(short row, RectBounds *bounds);
    static short __stdcall HitTestPageButton(int y, int x);
    static short __stdcall HitTestSpellRow(int y, int x);
    static int __stdcall VisibleOrdinalToSpellSlot(short visibleOrdinal);

    unsigned char m_pageIndex;
    bool m_isLastPage;
    bool m_spellInputActive;
    unsigned char m_reservedFB;
    InterfaceEfx *m_spellEffect;
};

typedef char SpellInventoryPane_size_must_be_0x100[
    sizeof(SpellInventoryPane) == 0x100 ? 1 : -1];
```

- UID0000DO exact `RECONSTRUCTION_CPP CODE`:

```cpp
[[CHILDREN]]
```

- UID0000DO exact `RECONSTRUCTION_H CODE`:

```cpp
class SpellInventoryPane2 : public PanelPane
{
public:
    SpellInventoryPane2();
    virtual ~SpellInventoryPane2();

    virtual void OnActivate(const unsigned char *activationData);
    virtual void OnPaint();
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
    virtual bool OnServerMessage(Event *event);

private:
    void SetSpellInputActive(bool active);
    void ActivateSpellSlot(unsigned char spellSlot);
    void SendDirectSpellPacket(unsigned char spellSlot);
    static void __stdcall BuildPageButtonRect(short button, RectBounds *bounds);
    static void __stdcall BuildSpellRowRect(short row, RectBounds *bounds);
    static short __stdcall HitTestPageButton(int y, int x);
    static short __stdcall HitTestSpellRow(int y, int x);
    static int __stdcall VisibleOrdinalToSpellSlot(short visibleOrdinal);

    unsigned char m_pageIndex;
    bool m_isLastPage;
    bool m_spellInputActive;
    unsigned char m_reservedFB[5];
};

typedef char SpellInventoryPane2_size_must_be_0x100[
    sizeof(SpellInventoryPane2) == 0x100 ? 1 : -1];

#endif
```

- Exact Pane2 child CPP replacements, in emitter order:

UID00044D:
```cpp
SpellInventoryPane2::SpellInventoryPane2()
    : m_pageIndex(0),
      m_isLastPage(false),
      m_spellInputActive(false)
{
}
```

UID00044E:
```cpp
SpellInventoryPane2::~SpellInventoryPane2()
{
}
```

UID00044F at renamed path:
```cpp
void SpellInventoryPane2::OnActivate(const unsigned char *)
{
    m_pageIndex = 0;
    m_isLastPage = false;
    InvalidateRect(&m_visibleBounds);
}
```

UID00044G:
```cpp
void SpellInventoryPane2::SetSpellInputActive(bool active)
{
    m_spellInputActive = active;
}
```

UID00044H: keep CPP and H blocks blank. Exact no-code proof is one `ret`, no stable method identity, no xref/pointer hit, no side effect, and no defensible declaration slot.

UID00044I:
```cpp
void SpellInventoryPane2::OnPaint()
{
    EPFTileContext frame;
    g_pEPFLib->CopyEntryTileContext(L"SPELLINV.EPF", 0, &frame);
    RenderTileFrame(&frame, &frame.bounds,
                    &m_visibleBounds, 0, L"ITEMINV.PAL", 0);

    int visibleOrdinal = 0;
    int slot = 1;
    while (slot <= kSpellSlotCount)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot);
        if (record->active && ++visibleOrdinal > m_pageIndex * kSpellPageSize)
            break;
        ++slot;
    }

    SetDrawMode(1);
    SetTextBackColor(0);
    RectBounds textBounds;
    InitRectBounds(&textBounds, 12, 20, 22, 41);
    int drawn = 0;
    for (; slot <= kSpellSlotCount && drawn < kSpellPageSize; ++slot)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot);
        if (!record->active)
            continue;
        wchar_t text[128];
        swprintf_s(text, 128, L"%c", SlotIndexToHotkeyLetter(slot));
        SetTextColor(0x80);
        OffsetRect(&textBounds, 1, 0);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);
        SetTextColor(1);
        OffsetRect(&textBounds, -1, 0);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);
        textBounds.left += 25;
        textBounds.right = 160;
        swprintf_s(text, 128, L"%s", record->displayName);
        SetTextColor(0x80);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);
        InitRectBounds(&textBounds, 12, textBounds.top + 23,
                       22, textBounds.bottom + 23);
        ++drawn;
    }

    m_isLastPage = true;
    for (; slot <= kSpellSlotCount; ++slot)
    {
        if (g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot)->active)
        {
            m_isLastPage = false;
            break;
        }
    }
}
```

UID00044J:
```cpp
bool SpellInventoryPane2::OnKeyEvent(Event *event)
{
    const int key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key, event->m_payload.m_key.m_modifiers);
    if (event->m_type != kEventKeyDown ||
        event->m_payload.m_key.m_modifiers != 0)
        return false;
    if (key == kPaneKeyPageUp)
    {
        if (m_pageIndex > 0)
        {
            --m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    if (key == kPaneKeyPageDown)
    {
        if (!m_isLastPage)
        {
            ++m_pageIndex;
            InvalidateRect(&m_visibleBounds);
        }
        return true;
    }
    return false;
}
```

UID00044K:
```cpp
bool SpellInventoryPane2::OnMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;
    const int y = event->m_payload.m_pointer.m_y;
    const int x = event->m_payload.m_pointer.m_x;
    bool handled = false;
    if (event->m_type == kEventLeftButtonDown)
    {
        const int button = HitTestPageButton(y, x);
        if (button == 0 && m_pageIndex > 0)
        {
            --m_pageIndex;
            handled = true;
        }
        else if (button == 1 && !m_isLastPage)
        {
            ++m_pageIndex;
            handled = true;
        }
        if (handled)
            InvalidateRect(&m_visibleBounds);
        if (!g_pConfig->m_doubleClickEnabled && !m_spellInputActive && !handled)
        {
            const int row = HitTestSpellRow(y, x);
            if (row >= 0)
            {
                const int slot = VisibleOrdinalToSpellSlot(
                    (short)(m_pageIndex * kSpellPageSize + row + 1));
                if (slot != -1)
                {
                    ActivateSpellSlot((unsigned char)slot);
                    return true;
                }
            }
        }
        return handled;
    }
    if (event->m_type == kEventLeftButtonDoubleClick &&
        g_pConfig->m_doubleClickEnabled && !m_spellInputActive)
    {
        const int row = HitTestSpellRow(y, x);
        if (row >= 0)
        {
            const int slot = VisibleOrdinalToSpellSlot(
                (short)(m_pageIndex * kSpellPageSize + row + 1));
            if (slot != -1)
            {
                ActivateSpellSlot((unsigned char)slot);
                return true;
            }
        }
    }
    return false;
}
```

UID00044L at renamed path:
```cpp
bool SpellInventoryPane2::OnServerMessage(Event *event)
{
    const unsigned char *packet = static_cast<const unsigned char *>(
        event->m_payload.m_packet.m_data);
    if ((unsigned char)(packet[0] - 23) <= 1)
        OnActivate(0);
    return false;
}
```

UID00044M:
```cpp
void SpellInventoryPane2::ActivateSpellSlot(unsigned char spellSlot)
{
    if ((unsigned char)(spellSlot - 1) > 51)
        return;
    SpellCommandSlotRecord *record =
        g_pUserPane->GetSpellCommandSlotRecord(spellSlot);
    if (!record->active)
        return;
    switch (record->inputKind)
    {
    case 1: new SpellStringInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 2: new SpellWhoInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 3: new SpellFourArgsInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 4: new SpellThreeArgsInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 5: SendDirectSpellPacket(spellSlot); m_spellInputActive = false; break;
    case 6: new SpellTwoArgsInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 7: new SpellOneArgInputPane((char)spellSlot); m_spellInputActive = true; break;
    case 8: new SpellSlotInputPane((char)spellSlot); m_spellInputActive = true; break;
    }
}
```

UID00044N at repaired range:
```cpp
void SpellInventoryPane2::SendDirectSpellPacket(unsigned char spellSlot)
{
    unsigned char packet[3];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(spellSlot, packet + 1);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}
```

UID00044O at repaired range:
```cpp
void __stdcall SpellInventoryPane2::BuildPageButtonRect(
    short button, RectBounds *bounds)
{
    if (button == 0)
        InitRectBounds(bounds, 14, 221, 36, 239);
    else if (button == 1)
        InitRectBounds(bounds, 157, 221, 179, 239);
    else
        InitRectBounds(bounds, -1, -1, -1, -1);
}
```

UID00044P at repaired range:
```cpp
void __stdcall SpellInventoryPane2::BuildSpellRowRect(
    short row, RectBounds *bounds)
{
    if ((unsigned short)row < kSpellClickableRows)
        InitRectBounds(bounds, 2, 10 + 23 * row, 170, 33 + 23 * row);
    else
        InitRectBounds(bounds, -1, -1, -1, -1);
}
```

UID00044Q at repaired range:
```cpp
short __stdcall SpellInventoryPane2::HitTestPageButton(int y, int x)
{
    for (short button = 0; button < 2; ++button)
    {
        RectBounds bounds;
        BuildPageButtonRect(button, &bounds);
        if (PointInRect(y, x, &bounds))
            return button;
    }
    return -1;
}
```

UID00044R:
```cpp
short __stdcall SpellInventoryPane2::HitTestSpellRow(int y, int x)
{
    for (short row = 0; row < kSpellClickableRows; ++row)
    {
        RectBounds bounds;
        BuildSpellRowRect(row, &bounds);
        if (PointInRect(y, x, &bounds))
            return row;
    }
    return -1;
}
```

UID00044S:
```cpp
int __stdcall SpellInventoryPane2::VisibleOrdinalToSpellSlot(short visibleOrdinal)
{
    for (int slot = 1; slot <= kSpellSlotCount; ++slot)
    {
        if (!g_pUserPane->GetSpellCommandSlotRecord((unsigned char)slot)->active)
            continue;
        if (--visibleOrdinal == 0)
            return slot;
    }
    return -1;
}
```

- UID0001II exact external support CPP correction:

```cpp
void SpellInputPaneState::SetInputModeFlag(bool active)
{
    m_spellInputActive = active;
}
```

- UID0000DM formal H route for that sole external support definition:

```cpp
class SpellInputPaneState
{
public:
    void SetInputModeFlag(bool active);

private:
    unsigned char m_opaquePrefix[0xfa];
    bool m_spellInputActive;
};
```

The opaque prefix preserves the proven `m_spellInputActive@+0xfa` offset without inventing names or semantics for unaudited preceding layout. The old global `void SetInputModeFlag(bool active);` fragment is rejected because it cannot declare the member definition.

- Reason behavior is preserved: all branches, packet bytes/lengths, row/page counts, record filters, resource frames, vtable-visible methods, field offsets, and compiler/no-code distinctions come directly from current bytes/decompilation. Calls to retained helpers are plausible pre-optimization source whose bodies were inlined in live callers.
- Source shape: C++98/early MSVC-compatible explicit pointers, virtual methods, initializer lists, static private helpers with observed `__stdcall`, project helper APIs, no decompiler labels/adjusted-this arithmetic.
- Third-party import: not applicable; all source is NexusTK project code.

## Final Recommendation
- C-O1-001 through C-O1-050 and C-O1-053 are physically applied and scoped-validated in the accepted ordinary destinations. C-O1-055 records the preserved callback boundary. C-O1-051, C-O1-052, and C-O1-054 remain proposed for supervisor completion.
- The bounded C-O1-004/C-O1-005/C-O1-008/C-O1-010/C-O1-053 repair replaces active nonexistent `class_*`/`simroot_v2` routes with exact canonical current paths, preserves those old strings only as explicit history, and synchronizes UID0000DO's active UID0002RK/UID0001IH score prose to `94/95` and `91/94`.
- The bounded 18-claim destination repair preserves every accepted fact while replacing absent `## Relationship`, `## Summary`, `## Ownership Map`, `## Layout`, `## Behavior`, `## Method Inventory`, `## Reconstruction Notes`, `## Range`, `## Resource/Data Inventory`, `## Dependencies`, and `## Global/Data Inventory` promises with exact stronger physical active headings. C-O1-004 additionally has canonical generated-route wording in UID0001IH's active accepted split section.
- The bounded six-claim Gate 2A repair makes UID0001IH's active Source Route rows current, synchronizes UID0000DN/UID0002RI names/types/source placement with accepted formal source, replaces UID0000DM's invalid global prototype with one coherent formal class/member H route, and corrects UID0002RK's active inbound `OnActivate`/`OnServerMessage` labels while retaining rejected wording only as history.
- The bounded three-claim Gate 2A repair explicitly limits UID0001IH history while keeping synchronized route/ownership sections active, makes `ActivateSpellSlot`/`VisibleOrdinalToSpellSlot` current across the legacy root/class/index chain, makes `Event *`/`kEventKeyDown` current for UID00044J, and aligns UID0002RK's active Event/server-message names and `94/95` rationale while preserving dated rejected labels/scores.
- C-O1-051 is now deterministic: U01.a globally forward-declares incomplete InterfaceEfx, U01.b declares the legacy pane against that global tag, then U02/M01-M21/N01 follow. Every modeled `set_type` call uses the exact proposed function name in a complete declarator and has a separate exact normalized type/name/frame readback before comment. These remain 24 logical actionable rows and exactly 88 primitive mutation calls. F03's direct physical receipt and F14's `>=0.99` parallel inference each require exactly `__return_address@0x0/4:_UNKNOWN *; activationData@0x4/4:const unsigned __int8 *`, preserving the return row and forbidding every other row. Independent F11/F20 probes require public `y, x` but preserved physical `row@0x28/0x4:int; column@0x2c/0x4:int`, with no frame rename; R01-R09/D01-D09 remain explicit no-action/absent-frame protections.
- UID0000O1 remains the sole declared target and file root. UID0000DN/UID0000DO are the only target source emitters.
- UID0002RI/UID0002RK/UID0002RL/UID0001IH remain non-emitting index/compiler pages; UID00026J remains mixed rdata; UID00044H remains no-code.
- Keep UID0001II external, with its separate void-source repair; keep UID0000LU and UID0000NJ separate.
- No removed companion is present or claimed. The active report's own zero-executable-script scan supplies the artifact-hygiene proof; no historical material is reconstructed from memory.
- Bounded required work: no ordinary source implementation remains after the current three-claim repair, six successful scoped file validators, and final waited generated readback. Supervisor work is limited to wholly fresh Gate 1/Gate 2A including C-O1-054, C-O1-051 Gate 2B, and C-O1-052 coverage. Optional future archival work remains recovery of original private spellings/PDB or a direct factory route.

## Recommended Target Doc Changes
- Target path: `source-3/project-documentation/by-file/SpellInventoryPane.md`, UID0000O1.
- Callback disposition: the by-file root changes below are implemented at the stated specificity and were originally validated by command `000000026463`; historical command `000000026502` predates discovery of the UID00044D omission. C-O1-026 was separately completed by scoped command `000000026749`; the current active-name/root route is validated by waited command `000000027183` with completed generated refresh. C-O1-054 remains an independent supervisor check.
- Replace broad three-file contents with the two-class target inventory and explicit NewSpell/Scroll exclusions; add exact function/data/type/resource/compiler counts, deficiencies observed in dated validator command `000000026432`, canonical `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp`/`.h` routes, corrected Pane2 role/range facts, UID0001II exclusion, formal emitter order, no-global finding, and current legacy `ActivateSpellSlot`/`VisibleOrdinalToSpellSlot` identities. Nonexistent `class_*` names and rejected legacy method labels remain only explicit history, not active generated-route or source-name assertions.
- Metadata: `COMPLETION:93`, `CONFIDENCE:94`; retain projected path and `CANONICAL_OWNER:FILE`. Record reconstructable status in prose because the current by-file metadata schema lacks that field.
- Preserve historical source-split evidence as superseded history, not current uncertainty.

## Recommended Support Doc Changes
The following accepted ordinary changes, including the UID00044D correction, are physically implemented. Historical old paths remain named only to preserve exact rename provenance; the destination side is the current physical path.

| Support path / UID | Exact facts incorporated |
| --- | --- |
| `by-class/SpellInventoryPane.md` UID0000DN | `93/94`, position `010`, exact 0x100 layout, active `m_pageIndex`/`OnActivate`/`m_isLastPage`/`InterfaceEfx *m_spellEffect`, `ActivateSpellSlot`, and `VisibleOrdinalToSpellSlot` roles, complete formal CPP/H, source-facing `HitTestSpellRow(int y, int x)`, external UID0001II caveat, canonical current SpellInventoryPane CPP/H route, and explicit historicalization of rejected field/role/type/name and absent simroot paths. F11's protected physical `row, column` names are IDA-only and require no ordinary edit. |
| `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md` UID0002RI | `92/94`, reconstructable false, blank emitters, exact index, active `## ActivateSpellSlot Dispatcher Route Table`, current `VisibleOrdinalToSpellSlot`, resolved field/type/source-placement prose, UID0000DN complete class-formal route, and rejected future-split/unresolved-name wording historicalized. |
| `by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md` UID0001II | source return `void`, AL assignment residue, retain UID0000DM owner and fourteen-call external evidence. |
| `by-class/SpellInputPaneState.md` UID0000DM | one formal H `SpellInputPaneState` declaration with member return `void`, opaque prefix, and proven `m_spellInputActive@+0xfa`; exact UID0001II child remains the sole CPP definition and physical target exclusion. |
| `by-class/SpellInventoryPane2.md` UID0000DO | `93/94`, position `020`, exact 0x100 layout, `OnActivate`/`OnServerMessage`, 13-page/10-clickable distinction, formal H and `[[CHILDREN]]`, canonical shared SpellInventoryPane CPP/H route, absent simroot path historicalized, and active UID0002RK/UID0001IH score prose `94/95`/`91/94`. |
| `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK | `94/95`, full corrected range/gap/path/role inventory; active API uses `Event *`, `OnActivate`, and `OnServerMessage`; active score rationale is `94/95`, while `PaneKeyEvent`/`PaneMouseEvent`/`PaneMessage`, reset-page/pane-message, and `90/92` remain rejected or dated history only. |
| `by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md` UID00044D | Applied C-O1-026: emitter position `100`; formal initializer order `m_pageIndex(0)`, `m_isLastPage(false)`, `m_spellInputActive(false)`; exact packed 16-bit `+0xf8/+0xf9` clear in current reconstruction notes/disposition; scoped validator command `000000026749`; ordinary SHA256 `3D0EA5B60928ED5B6927B648D45E60546FCBC1D2FCCF1B7E62A81A7CF7F0826F`, 4,288 bytes. |
| `by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md` UID00044E | exact destructor CPP and emitter position `110`. |
| UID00044G callback rename from `by-memory/0x0057eae0-0x0057eaee.SpellInventoryPane2SetSpellInputActive.md` -> current `by-memory/0x0057eae0-0x0057eaf0.SpellInventoryPane2SetSpellInputActive.md` | update metadata range/path, `## Status`, `## Range`, `RECONSTRUCTION_CPP CODE`, inbound links, exact setter end, and emitter position `130`. |
| `by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md` UID00044I | exact paint CPP, project APIs, 13-entry page logic, and emitter position `140`. |
| `by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md` UID00044J | exact `Event *`-based key CPP, active `kEventKeyDown`, explicit rejection of historical `PaneKeyEvent`, and emitter position `150`. |
| `by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md` UID00044K | exact Event-based mouse CPP, 13-page/10-row logic, and emitter position `160`. |
| `by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md` UID00044M | exact eight-route activation CPP and emitter position `180`. |
| `by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md` UID00044R | exact ten-row source-facing `HitTestSpellRow(int y, int x)` CPP and emitter position `230`; F20's protected physical `row, column` names are IDA-only and require no ordinary edit. |
| `by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md` UID00044S | exact visible-ordinal CPP and emitter position `240`. |
| UID00044F historical rename provenance from `by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2ResetPage.md` -> current `by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate.md` | current metadata path/title, `## Status`, `## Behavior`, `RECONSTRUCTION_CPP CODE`, and every active inbound path/role reference use `OnActivate`. |
| UID00044L historical rename provenance from `by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnPaneMessage.md` -> current `by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage.md` | current metadata path/title, `## Status`, `## Behavior`, `RECONSTRUCTION_CPP CODE`, and every active inbound path/role reference use `OnServerMessage`. |
| UID00044N callback rename from `by-memory/0x0057f290-0x0057f2ee.SpellInventoryPane2SendDirectSpellPacket.md` -> current `by-memory/0x0057f290-0x0057f2f0.SpellInventoryPane2SendDirectSpellPacket.md` | update metadata range/path, `## Status`, `## Range`, `RECONSTRUCTION_CPP CODE`, and every inbound link. |
| UID00044O callback rename from `by-memory/0x0057f2f0-0x0057f36f.SpellInventoryPane2BuildPageButtonRect.md` -> current `by-memory/0x0057f2f0-0x0057f371.SpellInventoryPane2BuildPageButtonRect.md` | update metadata range/path, `## Status`, `## Range`, `RECONSTRUCTION_CPP CODE`, and every inbound link. |
| UID00044P callback rename from `by-memory/0x0057f380-0x0057f3d1.SpellInventoryPane2BuildSpellRowRect.md` -> current `by-memory/0x0057f380-0x0057f3d3.SpellInventoryPane2BuildSpellRowRect.md` | update metadata range/path, `## Status`, `## Range`, `## Behavior`, ten-row `RECONSTRUCTION_CPP CODE`, and every inbound link. |
| UID00044Q callback rename from `by-memory/0x0057f3e0-0x0057f486.SpellInventoryPane2HitTestPageButton.md` -> current `by-memory/0x0057f3e0-0x0057f488.SpellInventoryPane2HitTestPageButton.md` | update metadata range/path, `## Status`, `## Range`, `RECONSTRUCTION_CPP CODE`, and every inbound link. |
| `by-memory/0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual.md` UID00044H | retain non-emitting, add no-declaration protection. |
| `by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md` UID0002RL | preserve compiler-only state; distinguish target versus NewSpell rows. |
| `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH | corrected child paths/roles/ranges, still non-emitting; only the bounded pre-callback status/covered-range narrative is historical; active Source Route rows state that exact children are already selected/emitted and active Ownership Decision preserves the split; canonical current SpellInventoryPane/NewSpellInventoryPane CPP/H routes and `ActivateSpellSlot` evidence remain active, while nonexistent `class_*`/old method labels remain explicitly historical. |
| `by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md` UID00026J | exact target/excluded vtable/literal ownership map; no raw emission. |
| `by-file/NewSpellInventoryPane.md` UID0000LU and `by-file/ScrollSpellInventoryPane.md` UID0000NJ | cross-reference exclusion only; preserve all accepted source/formal state. |

No by-global, by-item, by-resource, or standalone by-type target page requires creation: no target global exists, resources are literals/dependencies, and exact layouts belong in the two class pages/formal H. Existing external type/file pages receive cross-references only where needed; their ownership/source is unchanged.

## Score And Metadata Recommendation
- UID0000O1: callback physically applied `88/89 -> 93/94`; the C-O1-026 callback does not mutate metadata or add score beyond this defended state. Fresh supervisor generated verification remains C-O1-054, not score work.
- UID0000DN: callback applied `85/88 -> 93/94`, retained owner/emitter UID0000O1, position `010`.
- UID0000DO: callback applied `89/90 -> 93/94`, retained owner/emitter UID0000O1, position `020`.
- UID0002RI: callback applied `88/89 -> 92/94`, retained semantic owner UID0000DN, reconstructable false and blank emitters.
- UID0002RK: callback applied `90/92 -> 94/95`, retained non-emitting split/index.
- UID0001II: callback applied `88/90 -> 92/94` with the void/formal correction; retained UID0000DM owner/emitter.
- UID0002RL remains `91/93`; callback applied UID0001IH `87/90 -> 91/94` after exact child/path sync; UID00026J remains `87/92` because it is intentionally mixed.
- Current support prose is synchronized with those metadata values: UID0000DO `## Evidence Notes` states UID0002RK `94/95` and UID0001IH `91/94`, while UID0002RK's own `## Parent Gate Analysis`/`## Score Rationale` defend current `94/95`; `90/92` and `87/90` remain dated history only.
- Child scores: callback physically applied the itemized `92-94` completion and `94-95` confidence values to source-bearing UID00044D-UID00044S rows; UID00044H stays `86/92`. UID00044D's metadata is unchanged by completed C-O1-026, which receives no additional score credit.
- Why not higher: no original symbols/PDB, no direct constructor callers, one unresolved no-op identity, inferred historical filename/helper spellings, and a mixed rdata parent.
- Score-improvement attempts: direct xrefs, pointer pattern, vtables, wrappers, bytes, stack frames, type inspection, sibling source, resources, and generated readback closed ownership/routing/range/header questions and isolated one concrete source blocker. Command `000000026749` and the corrected UID00044D close that blocker; unavailable original-symbol evidence is the only residual uncertainty.
- The independent F11/F20 physical-frame probes close a deterministic Gate 2B handoff defect but add no ordinary source or metadata score: public/source `y, x` was already correct, and protected physical `row, column` is an IDA presentation fact only.

## Open Questions With Attempted Resolution
| Question | Evidence checked | Resolution / impact |
| --- | --- | --- |
| Was Pane2 a separate `.cpp`? | file routes, code/rdata order, resources, sibling audits, generated structure | Best support is same UID0000O1 file; original filename remains inferred and caps confidence only. |
| Are active generated routes, source names, and support scores physically current? | canonical `auto-generated/NexusTK/ui/inventory/` file existence, bounded nonexistent `class_*`/`simroot_v2` checks, current six-page ordinary reread, UID0002RK/UID0001IH metadata/prose, and waited command-27183 CPP/H readback | Yes. Legacy and Pane2 share `SpellInventoryPane.cpp`/`.h`; excluded NewSpell/Scroll outputs are separate; current legacy names are `ActivateSpellSlot`/`VisibleOrdinalToSpellSlot`; current Pane2 API is Event-based with `OnServerMessage`; old route/type/method/score names are explicit history only; active scores are UID0002RK `94/95` and UID0001IH `91/94`. |
| What is UID00044H? | function object, bytes, xrefs, pointer search, vtables, neighbors | Unresolved identity; safely non-emitting/no declaration, no impact on other source. |
| Are zero-xref raw helpers source? | complete returns/prologues, duplicate/inlined caller behavior, compiler patterns | Yes, retained private/static source; no public route claim. |
| Does UID0001II belong to legacy class? | fourteen caller list, current type/comment, local callers, duplicate setter | No; external shared state helper. |
| Is Pane2 page size 10 or 13? | paint/activation constants, mouse arithmetic, row helper loop | Both roles resolved: page 13, clickable rows 10. |
| Are current child ends exact? | terminal bytes at five raw bodies | Yes. The documented repairs make the current exclusive ends exact at `0x57eaf0`, `0x57f2f0`, `0x57f371`, `0x57f3d3`, and `0x57f488`; current filenames, ranges, and formal dispositions agree. |
| Are all Gate 2B literal prestates current? | full live M01-M21/F01-F21/R01-R09/D01-D09/N01/P01 item, function type, frame, comment, byte/hash, xref, boundary, and collision reread from only `supervisor_uid0000ih_canonical_verify_20260822_1450`; U01/U02 scope absences and parser analogues freshly reread from canonical `supervisor_uid0000mm_canonical_verify_20260822_1745` | Yes for this repaired artifact: each evidence family comes from one identified healthy canonical read-only session and no matrix cell combines sessions. M05 remains `int __thiscall(int this)`; both failed UID0000O1 transactions are historical only. A fresh supervisor transaction must match every repaired literal before mutation. |
| How is U01 guaranteed to bind global rather than nested InterfaceEfx? | failed combined-U01 readback; fresh target/global/nested absences; global-incomplete `FunctionObject0`/`LogoPane` binding; late-global `ObjectPane`/`LightingObjectPane` nested-binding counterexample; accepted formal H order | Use two non-combinable calls: U01.a `struct InterfaceEfx;`, verify the exact global incomplete object and nested absences, then U01.b declare `SpellInventoryPane` and require `m_spellEffect@fc/4:struct InterfaceEfx *` plus continued nested absence. Any nested/full type result fails closed before U02. |
| Are all M01-M21 function-type payloads parser-complete? | current public `set_type` schema with `edits[].signature`; typed fixture `int __fastcall sum_point(struct Point *p)`; isolated M01 `Not a function type` rejection; all 21 proposed names/types/parameters | Yes. Each M payload is now `RETURN CC PROPOSED_NAME(PARAMS)`, while required IDA readback separates the proposed entity name from the normalized anonymous semantic type. Only M01's old payload was attempted; M02-M21 old payloads are historical report text, not runtime failures. |
| Does UID00044D explicitly initialize `m_isLastPage`? | raw R04 bytes, field offsets, current ordinary formal/prose, and command-26749 generated CPP | Yes: the word clear at `+0xf8` covers `m_pageIndex@+0xf8` and `m_isLastPage@+0xf9`; UID00044D and generated CPP now contain `m_isLastPage(false)` between the other two initializers. |
| Are post-type/post-define frames deterministic? | clean current F03/F14 return-address-only prestates; direct unsaved M03 post-type physical frame; identical M03/M14 21-byte body and SHA256 `FE4EABE1DC86355D6DD992105D26E3C01F64AA7A03673E0415C7269659F3C0A5`; corresponding named activation-data declarators; read-only raw no-function/no-frame prestates | Yes: F03 must become exactly `__return_address@0x0/4:_UNKNOWN *; activationData@0x4/4:const unsigned __int8 *` from direct evidence. F14 must produce the same exact two rows at `>=0.99` inference confidence, verified fail-closed before comment/M15. Public type application materializes the named formal; neither body accesses it, so source behavior is unchanged. Raw post-definition frames cannot be proved without mutation, so R01-R09 are narrowed to no action and D01-D09 must remain absent with `No function found`. |
| Must M11/M20 physical argument names follow public `y, x`? | strict M11 failure receipt; independent no-comment F11 probe `supervisor_uid0000o1_f11_probe_20260823_1756`; independent no-comment F20 probe `supervisor_uid0000o1_f20_probe_20260823_1759`; current ordinary/formal source signatures | No. Both exact named types expose public `__int16 __stdcall(int y, int x)` while physical frames preserve `row@0x28/0x4:int; column@0x2c/0x4:int`. Keep source/public `y, x`, protect physical `row, column`, add no stack/local rename, and gate each comment after the exact frame readback. The strict transaction's prematurely batched M11 comment is uncredited. |
| Can scores exceed 95? | all current routes, completed C-O1-026, and missing symbol/factory evidence | No; unavailable original-symbol/PDB/factory proof still caps recommended confidence at 94/95. |

No question is deferred as generic future investigation, and no ordinary source-completeness blocker remains. The three unchecked claims are exact supervisor-owned gate/coverage actions.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
Manual files were read-only. The following payload describes the now-applied post-C-O1-026 ordinary state and must not be applied under C-O1-052 until the supervisor passes fresh Gate 2A. B005 must not edit manual coverage files.

- `by-file/-coverage-report.md`, replace current UID0000O1 row with:

```text
- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) : reconstructable : 93% : very-strong : Whole-file audit routes legacy SpellInventoryPane and SpellInventoryPane2 into NexusTK/ui/inventory/SpellInventoryPane.cpp/.h; resolves complete code/gap/compiler/rdata/resource/type inventory, excludes NewSpellInventoryPane and ScrollSpellInventoryPane, keeps embedded UID0001II external, repairs Pane2 OnActivate/OnServerMessage roles, 13-page/10-hit-row behavior and five raw exclusive ends, includes the Pane2 constructor's observed m_pageIndex/m_isLastPage word-clear initialization, supplies formal CPP/H and deterministic emitter order, and requires coherent generated CPP/H readback with no empty markers, stubs, or initializer omission.
```

- `by-class/-coverage-report.md`, replace UID0000DM, UID0000DN, and UID0000DO rows with:

```text
- [UID:0000DM][SpellInputPaneState](by-class/SpellInputPaneState.md) : reconstructable : 87% : very-strong : Shared spell-input state class routed through TargetSelectionInputPanes; exact externally owned SetInputModeFlag(bool) writes +0xfa and returns source-level void, with fourteen prompt-family callers and legacy SpellInventoryPane non-ownership explicitly preserved.
- [UID:0000DN][SpellInventoryPane](by-class/SpellInventoryPane.md) : reconstructable : 93% : very-strong : Source-ready 0x100 legacy spell inventory class with constructor/ordinary destructor/OnActivate/paint/key/mouse/packet/activation/effect/packet/geometry helpers, exact InterfaceEfx and spell-record dependencies, complete formal CPP/H, external UID0001II exclusion, and compiler-generated vtable/destructor support.
- [UID:0000DO][SpellInventoryPane2](by-class/SpellInventoryPane2.md) : reconstructable : 93% : very-strong : Source-ready 0x100 alternate spell inventory class with exact child routes, constructor initialization of m_pageIndex, m_isLastPage, and m_spellInputActive, corrected OnActivate and OnServerMessage identities, Event APIs, 13-entry page versus 10-row hit-test behavior, repaired raw helper ends, complete formal H/child CPP order, and compiler-generated vtable/destructor support.
```

- `by-memory/-coverage-report.md`, replace UID0001IH, UID0002RI, UID0001II, UID0002RK, and UID0002RL rows with:

```text
    - [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) 0x0057c2d0-0x0057f742 | split/index | SpellInventoryPanes : not reconstructable : 91% : very-strong : Non-emitting physical index split among legacy SpellInventoryPane, separate NewSpellInventoryPane, SpellInventoryPane2, embedded shared input-state helper, exact gaps/tables, and compiler destructor/thunk tail; source emits only through direct class/file children.
        - [UID:0002RI][0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers](by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md) 0x0057c2d0-0x0057cf6b | split/index | SpellInventoryPaneLegacyCoreAndHelpers : not reconstructable : 92% : very-strong : Exact non-emitting legacy code/table/padding index; complete source routes through UID0000DN formal CPP/H, while overlapping UID0001II remains externally owned and compiler/padding bytes emit no handwritten source.
        - [UID:0001II][0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag](by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md) 0x0057c430-0x0057c43f | method | SpellInputPaneStateSetFlag : reconstructable : 92% : very-strong : Exact void source-level setter for shared spell input state at +0xfa; fourteen external prompt-family callers, current IDA void type/comment, AL assignment residue, exact bytes, external UID0000DM ownership, and target-local non-ownership are proved.
        - [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) 0x0057ea60-0x0057f58b | split/index | SpellInventoryPane2CoreAndHelpers : not reconstructable : 94% : very-strong : Non-emitting exact Pane2 parent with constructor/destructor/OnActivate/paint/Event/OnServerMessage/dispatcher/helper children, all gaps and switch data, 13-entry page versus 10-row hit-test proof, and repaired raw exclusive ends through 0x0057f488.
        - [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md) 0x0057f58b-0x0057f742 | destructor/thunk-group | SpellInventoryScalarDeletingDestructors : not reconstructable : 91% : very-strong : Compiler-only six-adjustor/three-scalar-deleting-destructor island; target Pane2/legacy ABI rows regenerate from class declarations and NewSpell rows remain externally owned.
```

- `by-memory/-coverage-report.md`, immediately after the replacement UID0002RK row and before UID0002RL, insert all sixteen currently absent exact children in source order:

```text
            - [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) 0x0057ea60-0x0057eaa0 | constructor | SpellInventoryPane2Constructor : reconstructable : 93% : very-strong : Exact raw source constructor installs all three class vtables; its word clear initializes m_pageIndex@+0xf8 and m_isLastPage@+0xf9, and its byte clear initializes m_spellInputActive@+0xfa; owner UID0000DO, emitter position 100, formal CPP plus class H route.
            - [UID:00044E][0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor](by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md) 0x0057eaa0-0x0057eac0 | destructor | SpellInventoryPane2Destructor : reconstructable : 93% : very-strong : Ordinary source destructor restores Pane2 vtables and delegates PanelPane cleanup; owner UID0000DO, emitter position 110, deleting-wrapper support remains compiler-only.
            - [UID:00044F][0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate](by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate.md) 0x0057eac0-0x0057ead5 | method | SpellInventoryPane2OnActivate : reconstructable : 94% : very-strong : Primary-vtable OnActivate resets page state and invalidates; packet opcodes 23/24 call this slot, disproving ResetPage-only identity; owner UID0000DO, emitter position 120.
            - [UID:00044G][0x0057eae0-0x0057eaf0.SpellInventoryPane2SetSpellInputActive](by-memory/0x0057eae0-0x0057eaf0.SpellInventoryPane2SetSpellInputActive.md) 0x0057eae0-0x0057eaf0 | method | SpellInventoryPane2SetSpellInputActive : reconstructable : 92% : very-strong : Retained private void setter writes Pane2 +0xfa; complete raw body, exact `c2 04 00` end, and inlined behavior support source despite zero direct start xrefs; owner UID0000DO, emitter position 130.
            - [UID:00044H][0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual](by-memory/0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual.md) 0x0057eaf0-0x0057eaf1 | no-route nullsub | SpellInventoryPane2SourceEmptyVirtual : not reconstructable : 86% : very-strong : One-byte ret has no xref, pointer hit, side effect, or stable method identity; preserve blank CPP/H and do not invent a declaration.
            - [UID:00044I][0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint](by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md) 0x0057eb00-0x0057eda4 | method | SpellInventoryPane2OnPaint : reconstructable : 94% : very-strong : Exact EPF paint uses project tile/text APIs, 13-entry page stride, 0x148 spell records, and source literals including the 12/20/22/41 initial rectangle; owner UID0000DO, emitter position 140.
            - [UID:00044J][0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent](by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md) 0x0057edb0-0x0057ee2c | method | SpellInventoryPane2OnKeyEvent : reconstructable : 94% : very-strong : Event-based unmodified Page Up/Page Down handler preserves page bounds and invalidation; owner UID0000DO, emitter position 150.
            - [UID:00044K][0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent](by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md) 0x0057ee30-0x0057eff7 | method | SpellInventoryPane2OnMouseEvent : reconstructable : 94% : very-strong : Event-based page/single/double-click handling uses page stride 13 but exact clickable rows 0..9 and preserves input-lock/active guards; owner UID0000DO, emitter position 160.
            - [UID:00044L][0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage](by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage.md) 0x0057f000-0x0057f028 | method | SpellInventoryPane2OnServerMessage : reconstructable : 94% : very-strong : Secondary-vtable packet method calls primary OnActivate for opcodes 23/24 and always returns false, disproving the prior OnPaneMessage/input-flag interpretation; owner UID0000DO, emitter position 170.
            - [UID:00044M][0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot](by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md) 0x0057f030-0x0057f28c | method/switch | SpellInventoryPane2ActivateSpellSlot : reconstructable : 94% : very-strong : Exact learned-slot dispatcher preserves active guard, eight input-kind routes, direct-packet route, and compiler-lowered switch table; owner UID0000DO, emitter position 180.
            - [UID:00044N][0x0057f290-0x0057f2f0.SpellInventoryPane2SendDirectSpellPacket](by-memory/0x0057f290-0x0057f2f0.SpellInventoryPane2SendDirectSpellPacket.md) 0x0057f290-0x0057f2f0 | helper | SpellInventoryPane2SendDirectSpellPacket : reconstructable : 94% : very-strong : Retained private direct-cast packet helper writes opcode 0x0f and slot then sends length two; corrected exclusive end includes the retn 4 immediate; owner UID0000DO, emitter position 190.
            - [UID:00044O][0x0057f2f0-0x0057f371.SpellInventoryPane2BuildPageButtonRect](by-memory/0x0057f2f0-0x0057f371.SpellInventoryPane2BuildPageButtonRect.md) 0x0057f2f0-0x0057f371 | helper | SpellInventoryPane2BuildPageButtonRect : reconstructable : 94% : very-strong : Static page-button rectangle builder preserves exact previous/next bounds and invalid fallback; corrected exclusive end includes the retn 8 immediate; owner UID0000DO, emitter position 200.
            - [UID:00044P][0x0057f380-0x0057f3d3.SpellInventoryPane2BuildSpellRowRect](by-memory/0x0057f380-0x0057f3d3.SpellInventoryPane2BuildSpellRowRect.md) 0x0057f380-0x0057f3d3 | helper | SpellInventoryPane2BuildSpellRowRect : reconstructable : 94% : very-strong : Static row builder accepts exactly rows 0..9 with 23-pixel geometry and invalid fallback; corrected exclusive end includes the retn 8 immediate; owner UID0000DO, emitter position 210.
            - [UID:00044Q][0x0057f3e0-0x0057f488.SpellInventoryPane2HitTestPageButton](by-memory/0x0057f3e0-0x0057f488.SpellInventoryPane2HitTestPageButton.md) 0x0057f3e0-0x0057f488 | helper | SpellInventoryPane2HitTestPageButton : reconstructable : 94% : very-strong : Static page-button hit-test returns button 0/1 or -1 through exact rectangle tests; corrected exclusive end includes the retn 8 immediate; owner UID0000DO, emitter position 220.
            - [UID:00044R][0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow](by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md) 0x0057f490-0x0057f523 | helper | SpellInventoryPane2HitTestSpellRow : reconstructable : 94% : very-strong : Static hit-test scans exactly ten clickable rows 0..9 rather than the 13-entry page size; owner UID0000DO, emitter position 230.
            - [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md) 0x0057f530-0x0057f58b | helper | SpellInventoryPane2VisibleOrdinalToSpellSlot : reconstructable : 94% : very-strong : Static mapper scans active 0x148 spell records in one-based slots 1..52 and returns the requested visible ordinal or -1; owner UID0000DO, emitter position 240.
```

- `by-memory/-coverage-report.md`, replace UID00026J at its current `0x0062cfd8` anchor with:

```text
    - [UID:00026J][0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData](by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md) 0x0062cfd8-0x0062d418 | mixed-rdata index | SpellInventoryMacroReadOnlyData : not reconstructable : 87% : very-strong : Non-emitting mixed SpellInventory/NewSpell/Pane2/MacroDialogs RTTI-vtable-literal index; exact target clusters and SPELLINV literals regenerate through class/source owners, NewSpell and macro rows remain external, and no raw array is emitted.
```

Exact no-change disposition: current `by-file/-coverage-report.md` rows for UID0000LU and UID0000NJ remain valid because their standalone source paths, scores, and ownership do not change; only ordinary-doc exclusion cross-references are added. No manual by-global/by-item/by-resource/by-type row exists or is needed because the target owns no standalone global/data/type/resource page. Validator-owned generated coverage/tracker refresh remains separate and is not a substitute for these manual replacements/insertions.

## Follow-Up Actions
- Completed same-B005 ordinary callback: UID00044D was leased, corrected, scoped-validated by command `000000026749`, physically reread in generated CPP/H after its deferred refresh completed, reconciled under C-O1-026, and released.
- Completed same-B005 five-claim repair: UID0001IH, UID0000DN, UID0000DO, and UID0000O1 were leased one at a time, corrected only for active route/score prose, scoped-validated with completed generated refreshes by commands `000000026992`, `000000026995`, `000000026997`, and `000000027000`, physically reread, and released. The report twins/receipts are reconciled without changing the named M01-M21 handoff.
- Completed same-B005 18-claim destination repair: only UID0001IH required ordinary content, was leased for its active canonical generated-route paragraph, passed scoped validator command `000000027148`, was physically reread at SHA256 `1A07DB4A361A34F9E971504B0D5E86922DEEA4995E060B2A55148D3D8704446C`, and was released. The other 17 failed contracts were repaired in both twins by naming the stronger physical active H2s already holding the accepted facts; the other 27 ordinary hashes and all formal/generated source remain preserved.
- Completed same-B005 six-claim repair: canonical UID0001IH, UID0000DN, UID0002RI, UID0002RK, and UID0000DM were leased one at a time, repaired only at the failed active headings/formal H route, scoped-validated by commands `000000027168` through `000000027172`, physically reread, and released. Command 27172 completed the final generated refresh; the report twins/receipts are reconciled without changing any passing claim or the 52/3 allocation.
- Completed same-B005 three-claim repair: UID0001IH, UID0002RI, UID0000DN, UID00044J, UID0002RK, and UID0000O1 were leased one at a time, repaired only for active/history scope, accepted legacy names, Event/server-message authority, and current score rationale, scoped-validated by commands `000000027177` through `000000027181` plus final waited command `000000027183`, physically reread, and released. The C-O1-004/C-O1-006/C-O1-032 twins/receipts are reconciled without changing any passing claim, formal source, IDA handoff, or the 52/3 allocation.
- Supervisor fresh Gate 2A/C-O1-054: independently verify generated CPP/H contain the corrected constructor and remain free of markers/stubs. B005 command `000000026749` is callback evidence but does not satisfy the independent supervisor verification.
- Supervisor Gate 2B: keep every failed/unsaved UID0000O1 attempt historical and uncredited; do not reuse or resume either the 14-call dirty prefix or strict U01.a/U01.b/U02+M01-M10 prefix/M11 batch. Open/attest a distinct fresh clean physical copy/session from the authorized canonical, verify every repaired literal against its identified canonical evidence family, then perform the complete 88-call sequence U01.a -> readback -> U01.b -> readback -> U02 -> M01-M21 -> N01. Require the exact global incomplete InterfaceEfx object, global `m_spellEffect` pointer, both nested target spellings absent, every M named declarator accepted, and every separate normalized type/name/frame readback exact before its comment. After M03 type/recompile require observed F03 `__return_address@0x0/4:_UNKNOWN *; activationData@0x4/4:const unsigned __int8 *`; after M14 require the same exact inferred F14 rows. After M11 and M20 type/recompile require public `y, x` with exact preserved physical `row@0x28/0x4:int; column@0x2c/0x4:int`; add no frame rename and do not batch either comment ahead of its frame gate. Keep R01-R09 exact no-action raw spans with D01-D09 absent, and fail closed before the next action on any drift.
- Supervisor coverage/lifecycle: only after fresh Gate 2A, apply C-O1-052 to the exact manual `-coverage-report.md` anchors; retain all independent generated verification, `execute_report`, archive movement, audit, and lifecycle confirmation authority.

## Confidence
- Recommendation confidence: `94/100`.
- Score confidence: `93/100` for the physically applied metadata; completed C-O1-026 adds no new score credit.
- Current documentation/header-route confidence: `Certain` for the six repaired ordinary pages, bounded UID0001IH history/current scope, exact active legacy identities, UID00044J/UID0002RK Event/server-message authority, UID0002RK `94/95` rationale, matching UID0000DM class/member declaration and UID0001II definition, and command-27183 generated readback.
- Gate 2B prestate/action confidence: `Certain` for the complete one-session modeled/raw matrices, separately identified canonical UDT-scope receipts, current public `set_type` schema/typed fixture, all 21 mechanically named declarators, and direct independent F11/F20 physical-frame probes. The next fresh clean transaction remains fail-closed on prestate drift, a nested/full InterfaceEfx result, parser rejection, proposed-name mismatch, normalized semantic-type mismatch, or physical-frame mismatch; no rejected unsaved prefix/batch is reused or credited.
- Deterministic-frame confidence: `Certain` for F03's exact directly observed two-row post-type frame, F11/F20's independently observed zero-delta physical `row, column` frames, and the narrowed R01-R09 no-function/no-frame final state; `>=0.99` for F14's exact same two-row post-type frame from the identical body/hash/current frame/declarator evidence, with fresh fail-closed readback. The old return-address-only F03/F14 and physical-`y`/`x` F11/F20 predictions are failed dated history, and no synthesized D-frame assumption remains.
- Remaining implementation blocker: none in the ordinary callback lane. Remaining uncertainty is stripped original filename/helper symbols, zero direct constructor entry edges, and UID00044H identity only; exact supervisor gate/coverage work remains separately listed.

## Validator Results
- Current C-O1-026 callback receipt: exact command `python .\tools\validator.py --mode file --file by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md --apply --queue-timeout 240` returned command `000000026749` at `2026-08-22T15:14:43-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, registry update `b6beb704727ad264bf68ac5abac4306f7398d20cfb0fd275b9e838a06a9ca92a -> 5a47958838fc7406ead9277ccffc0b0682822b372db857987521562b38972797`, `stats_incremental_noop:1`, and `projected_stats_update:1`. Its generated refresh was initially deferred; public queue-status command `000000026778` at `2026-08-22T15:20:35-04:00` proved zero queued/processing jobs after command 26749 completed.
- Current mixed-session/constructor Gate 1 repair: B005 ran no validator and did not run/probe/dry-run `execute_report`; the pass used only live read-only IDA queries, physical ordinary/generated reads, and this report edit. No IDA mutation/save/start/stop endpoint was called.
- Current deterministic-frame Gate 1 repair: B005 ran no validator and did not run/probe/dry-run `execute_report`; the repair was report-only and used no IDA mutation/save endpoint.
- Current Gate 2B prestate repair: B005 ran no validator and did not run/probe/dry-run `execute_report`; only live read-only IDA queries and report reconciliation were performed.
- Current U01 global-type repair: B005 ran no validator and did not run/probe/dry-run `execute_report`; only canonical `type_inspect` readbacks and this report reconciliation were performed. No rename/type/comment/define/save/start/stop endpoint was called. Failed transaction `UID0000O1-20260822-225300000` is supervisor history: it stopped after old U01 and before U02/M/N/save, its worker was discarded, and canonical/working files remained SHA256 `0180129575CC0E3E0789AD16556A16BF7725101C9C5418834F8483B5DF7A6D09`, `143,211,331` bytes.
- Current missing-companion Gate 1 repair: B005 ran no validator and did not run/probe/dry-run `execute_report`. Exact-name/report-stem searches found no UID0000O1 companion or trustworthy verbatim source, so no companion was created. Physical active-report inspection found 21 `cpp` openings, five `text` openings, 26 matching closes, zero executable-language openings, and no operational package.
- Current named-function-declarator repair: B005 ran no validator, made no IDA call, and did not run/probe/dry-run `execute_report`. The current public tool declaration was read-only inspected; all 21 M action signatures were mechanically checked as complete `RETURN CC PROPOSED_NAME(PARAMS)` declarations, with unchanged semantic types and separate normalized readback contracts.
- Current M03/M14 physical-frame handoff repair: B005 ran no validator, made no IDA call, and did not run/probe/dry-run `execute_report`. The report-only repair used the supervisor's rejected unsaved M03 receipt plus the report's already recorded exact identical M03/M14 body/hash/current-frame/declarator evidence; it grants no current or persisted Gate 2B credit.
- Current F11/F20 physical-frame handoff repair: B005 ran no validator, made no IDA call, and did not run/probe/dry-run `execute_report`. The report-only repair used the supervisor's strict failed-transaction receipt and independent blank-comment F11/F20 probe receipts, preserved public/source `y, x`, protected physical `row, column`, and grants no current or persisted Gate 2B credit.
- Prior destination-contract validator receipt C-O1-004: exact command `python .\tools\validator.py --mode file --file by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md --apply --wait-generated --queue-timeout 240` returned command `000000027148` at `2026-08-22T23:12:45-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, `stats_incremental_noop:1`, `projected_stats_update:1`, and `generated_refresh: completed`. Physical reread found 12 H2 headings and one active canonical generated-route paragraph under `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22`; ordinary SHA256 at that dated point was `1A07DB4A361A34F9E971504B0D5E86922DEEA4995E060B2A55148D3D8704446C`, `34,277` bytes, `175` LF.
- Prior 18-contract physical heading receipt: all 18 checked claims resolved to exact active H2s in their destination cells. The later six-claim failure concerned stale content inside physical headings/formal H, not missing headings.
- Prior five-claim validator receipts: commands `000000026992`, `000000026995`, `000000026997`, and `000000027000` each exited `0` with `ok:1`; their route/score work remains preserved as dated evidence.
- Current six-claim validator receipt C-O1-004: exact command `python .\tools\validator.py --mode file --file by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md --apply --queue-timeout 240` returned command `000000027168` at `2026-08-23T00:17:13-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, `stats_incremental_noop:1`, `projected_stats_update:1`, and deferred generated refresh. Physical reread found 12 H2s and current selected/emitted wording in both stale Source Route rows; SHA256 `4A1F73EEFFDA8BAEB9956CE518E47D550E2166FFDB890E6A9F04E86B51CD2769`, `34,440` bytes, `175` LF.
- Current six-claim validator receipt C-O1-005: exact command `python .\tools\validator.py --mode file --file by-class/SpellInventoryPane.md --apply --queue-timeout 240` returned command `000000027169` at `2026-08-23T00:17:43-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, `stats_incremental_noop:1`, `projected_stats_update:1`, and deferred generated refresh. Physical reread found 8 H2s and exact accepted Field Notes/current-prose roles plus historical alternatives; SHA256 `6E724666245888629FFC873F425528C6E966D3A065705A320B5BAD2E618743E7`, `23,280` bytes, `479` LF.
- Current six-claim validator receipt C-O1-006: exact command `python .\tools\validator.py --mode file --file by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md --apply --queue-timeout 240` returned command `000000027170` at `2026-08-23T00:18:21-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, `stats_incremental_noop:1`, `projected_stats_update:1`, and deferred generated refresh. Physical reread found 10 H2s, current accepted fields/types/source placement, and explicit superseded history; SHA256 `204602E750F73D13E09476FBEF20DC6168ECE36775EF603A2967E67B5CB57990`, `19,742` bytes, `156` LF.
- Current six-claim validator receipt C-O1-028/C-O1-034: exact command `python .\tools\validator.py --mode file --file by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md --apply --queue-timeout 240` returned command `000000027171` at `2026-08-23T00:18:46-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, `stats_incremental_noop:1`, `projected_stats_update:1`, and deferred generated refresh. Physical reread found 14 H2s, active `OnActivate`/`OnServerMessage` inbound labels, and explicit rejected historical aliases; SHA256 `26388235612BFCB9CAF2C9BEC1C5D06E54B83C727BC041DD09388DAE1B700EFC`, `30,217` bytes, `225` LF.
- Current six-claim validator receipt C-O1-007/final owner: exact command `python .\tools\validator.py --mode file --file by-class/SpellInputPaneState.md --apply --queue-timeout 240 --wait-generated` returned command `000000027172` at `2026-08-23T00:19:31-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, two UID0000DM registry updates, `stats_row_update:1`, `projected_stats_update:1`, `autogen_cpp_update:1`, `autogen_header_update:1`, and `generated_refresh: completed`. Physical reread found 9 H2s and the exact formal class/member H route; SHA256 `724160900D382C61CE37FE3D75D21D5264C71D1C12CD55542D712147E06C333B`, `15,410` bytes, `117` LF.
- Current three-claim validator receipt C-O1-004: exact command `python .\tools\validator.py --mode file --file by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md --apply --queue-timeout 240` returned command `000000027177` at `2026-08-23T12:54:26-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, `stats_incremental_noop:1`, `projected_stats_update:1`, and deferred generated refresh. Physical reread found 12 H2s, an explicitly bounded historical snapshot, active Source Route/Ownership Decision sections, and SHA256 `D11DF4F8787BF7EEE7F5D37F26B36E4C00AC7475DF1EC410E576074ED3B5D32A`, `34,698` bytes, `175` LF/zero CR.
- Current three-claim validator receipt C-O1-006 index: exact command `python .\tools\validator.py --mode file --file by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md --apply --queue-timeout 240` returned command `000000027178` at `2026-08-23T12:55:04-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, `stats_incremental_noop:1`, `projected_stats_update:1`, and deferred generated refresh. Physical reread found active `## ActivateSpellSlot Dispatcher Route Table`, no active `CastSpell`, and SHA256 `D7AE16D14E1CC71F2D59BB2103DA545218C1E85F735E4A9F6D0C281C23A32E29`, `19,777` bytes, `156` LF/zero CR.
- Current three-claim validator receipt C-O1-006 class: exact command `python .\tools\validator.py --mode file --file by-class/SpellInventoryPane.md --apply --queue-timeout 240` returned command `000000027179` at `2026-08-23T12:55:35-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, `stats_incremental_noop:1`, `projected_stats_update:1`, and deferred generated refresh. Physical reread found active `ActivateSpellSlot`/`VisibleOrdinalToSpellSlot`, old `CastSpell` only in `## Changes`, and SHA256 `04EBF53B75F3E775D7B5ED55CE039912AC714B6C2C0FB40B87B7010C0CC6FF29`, `23,295` bytes, `479` LF/zero CR.
- Current three-claim validator receipt C-O1-032: exact command `python .\tools\validator.py --mode file --file by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md --apply --queue-timeout 240` returned command `000000027180` at `2026-08-23T12:55:56-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, `stats_incremental_noop:1`, `projected_stats_update:1`, and deferred generated refresh. Physical reread found active `Event *`/`kEventKeyDown`, rejected historical `PaneKeyEvent`, and SHA256 `56AE8B1B5AABC5B727CEC2B0E154A38102ECF33D27F90C33B8F6B2E7D1887CA6`, `3,607` bytes, `71` LF/zero CR.
- Current three-claim related UID0002RK receipt: exact command `python .\tools\validator.py --mode file --file by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md --apply --queue-timeout 240` returned command `000000027181` at `2026-08-23T12:56:36-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, `stats_incremental_noop:1`, `projected_stats_update:1`, and deferred generated refresh. Physical reread found active Event/server-message names, current `94/95` parent/score rationale, historical-only `90/92`, and SHA256 `6D79EF2F39B7B70B1343BDCB71C37A572F439CFC79429B37ACBD9BD5CFD0F7BD`, `30,914` bytes, `225` LF/zero CR.
- Current three-claim root/final owner receipt: an initial identical waited invocation returned only command `000000027182` and timestamp `2026-08-23T12:57:12-04:00` at the 30-second client yield boundary. The immediate bounded repeat `python .\tools\validator.py --mode file --file by-file/SpellInventoryPane.md --apply --wait-generated --queue-timeout 240` returned command `000000027183` at `2026-08-23T12:58:01-04:00`, exit `0`, `ok:1`, one scanned Markdown file, UID/reference phases true, `stats_incremental_noop:1`, `projected_stats_update:1`, validator registry rebuild, and `generated_refresh: completed`. Root SHA256 is `6BE1A246D2B14B796FEBB7B96788CD138C34DA6CC7E45EA627597FFCE95E0D81`, `25,938` bytes, `145` LF/zero CR. Generated CPP/H command headers equal 27183, and the full physical structure/pollution proof is recorded in Current Target State.
- Current final report audit: all 33 H2 headings are present and distinct; all 55 ledger rows and all 55 checklist rows are exact ordered twins; allocation remains 52 checked/3 supervisor-owned unchecked; C-O1-051 occurs exactly once in each twin with identical F11/F20 public-type/physical-frame mechanics; all 28 ordinary hash rows remain preserved; 21 `cpp` plus five `text` openings have 26 matching closes; executable-language openings, operational packages, and lifecycle status-lock tokens are zero; the obsolete physical-`y`/`x` F11/F20 requirement survives only as dated rejected history; and exactly one readiness marker is the physical terminal line with terminal LF.
- Authored-phase receipt (`2026-08-22`): B005 ran no validators because the assigned phase was report-only.
- Callback command form: `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`; the original final root validation and all four current repair validations added `--wait-generated`. Every listed command exited `0` with `ok=1` for its scoped file.
- Initial/final class and root receipts: `000000026461` UID0000DN; `000000026462` and `000000026501` UID0000DO; `000000026463` and final wait-generated `000000026502` UID0000O1; `000000026466` UID0000DM.
- File/index/support receipts: `000000026464` UID0000LU; `000000026465` UID0000NJ; `000000026467` UID0001II; `000000026468` UID0002RI; `000000026487` and `000000026500` UID0002RK; `000000026488` UID0001IH; `000000026489` UID0002RL; `000000026491` UID00026J.
- Pane2 child receipts: `000000026469` UID00044D; `000000026470` UID00044E; `000000026471` UID00044H; `000000026472` UID00044I; `000000026473` UID00044J; `000000026474` UID00044K; `000000026475` UID00044M; `000000026476` UID00044R; `000000026477` UID00044S.
- Rename registration/final receipts: UID00044F `000000026478`/`000000026492`; UID00044G `000000026479`/`000000026494`; UID00044L `000000026480`/`000000026495`; UID00044N `000000026481`/`000000026496`; UID00044O `000000026482`/`000000026497`; UID00044P `000000026484`/`000000026498`; UID00044Q `000000026485`/`000000026499`. Initial rename-registration passes reported only expected not-yet-registered sibling references; all were resolved by the listed final passes and the final parent/root passes.
- Historical generated receipt: command `000000026502`, timestamp `2026-08-22T10:59:56-04:00`; `SpellInventoryPane.cpp` SHA256 `0DD1063835953ACC7DCBCC0071B67711C9CE549ADEB20245CC25B5FABFD1C358`, `19,341` bytes, `622` LF/zero CRLF, terminal LF; `SpellInventoryPane.h` SHA256 `77E053696A2C65D74F376AF0E386188A7D8335F8F7DD96CCAD5AD466CA569C2D`, `2,886` bytes, `81` LF/zero CRLF, terminal LF. Structure and pollution scans passed, but the receipt is not source-complete because UID00044D omitted `m_isLastPage(false)`.
- Gate-1-current generated defect receipt: command `000000026517` evidence, physically snapshotted `2026-08-22T16:28:27Z`; CPP SHA256 `2F56C88DB020C4B5961715F392873C072B142702500046FBD3D1A7ED7ED72281`, 19,341 bytes, 622 LF/zero CRLF, terminal LF; H SHA256 `3803D2B8A1037377CFEDE150CD8C633D3C0ADD3D9A6DD03596EA4384C475CE50`, 2,886 bytes, 81 LF/zero CRLF, terminal LF. The H declares `m_isLastPage`, while the CPP UID00044D initializer list still contains only `m_pageIndex(0)` and `m_spellInputActive(false)`. A later validator-owned `16:38:37Z` retouch changed only the mutable snapshot hashes recorded in Current Target State and preserved the same omission.
- Current callback generated receipt: after command `000000026749` completed, CPP SHA256 `A94AFDFA1B464ACE9D69185DE134D05EB3BF1BA1322B77A94749F7AB99A20548`, 19,366 bytes, 623 LF/zero CR, terminal LF, last-write `2026-08-22T19:20:17.1513748Z`; H SHA256 `AA3F04FD457BDEF5D650A4EDB9FC7E4DC3E8344E30084AE856CA43E8ED12D207`, 2,884 bytes, 81 LF/zero CR, terminal LF, last-write `2026-08-22T19:20:17.1863790Z`. CPP lines 350-353 physically contain the three ordered initializers. Whole-file CPP/H pollution scan count was zero for empty-emitter markers, stubs, TODO, `sub_`, `dword_`, `nullsub_`, `unk_`, and raw `aN`/`vN` names.
- Historical post-C-O1-026 generated readback: the later shared validator-owned `2026-08-22T19:24:18Z` refresh produced CPP SHA256 `977A6C2B497ECD66FEFB8300F7C00CBB7CB39F23102462793E02F139E8131B5A`, 19,368 bytes, 623 LF/zero CR, and H SHA256 `4035174A0DA3153EFB578EA0EE5284DDB103F642E8EDF8C755E9E479745E97E6`, 2,886 bytes, 81 LF/zero CR. Both retained terminal LF, the corrected ordered constructor, and zero pollution matches; this external touch is not attributed to command 26749 and is superseded as mutable readback by command 27000 below.
- Historical five-claim generated receipt: command `000000027000` produced complete 30-definition CPP/H and zero pollution; the exact dated hashes remain above in Current Target State.
- Historical post-destination mutable generated readback: validator-owned command `000000027149` preserved the same structure; it is superseded by the current six-claim generated receipts below.
- Current six-claim waited generated receipt: immediately after command `000000027172` completed, validator-owned `TargetSelectionInputPanes.cpp` was SHA256 `734F200F2349BBCEDDF558E53AD2DF319CC171DC9067FEAFA913E5C7388C92D0`, `46,081` bytes, and H was SHA256 `CF6EE94C17FDA9187B0889F5750D75479ACF4A0C307937945003F4E5A88B2C37`, `1,477` bytes. H contained exactly one `class SpellInputPaneState`, one member declaration, one `m_spellInputActive`, and zero global prototypes; CPP contained exactly one matching member definition. SpellInventory CPP was SHA256 `FD71371B23EE356A2C94B2418D9443BE3408EDA5915CC4544F4B0BA54D1044B3`, `19,368` bytes, and H was SHA256 `69D54FB84469A771D31E571ABD1831C8032F0BDDB9EFC09672073681764A679C`, `2,886` bytes, preserving 30 definitions, both classes, global InterfaceEfx order, both three-initializer sequences, and zero pollution.
- Current mutable generated readback: a later shared validator-owned refresh stamped command `000000027174` at `2026-08-23T00:21:52-04:00`. `TargetSelectionInputPanes.cpp` is SHA256 `2B9F7C8A502107D2984BF2D758A87185335C97F585436C2CB36B9D39BC8EE639`, `46,081` bytes, `1,275` LF; H is SHA256 `7F994DF268B1A0F1574BD5760DB516F96AB3FAF1B86B9F4B5FD56AF20CF6318F`, `1,477` bytes, `47` LF. SpellInventory CPP is SHA256 `3DBD2B0865E107302638244260A28984B7CF663AB0CE408386ABB53979DFF139`, `19,368` bytes, `623` LF; H is SHA256 `1C441E9763C5ED510798CFEB97C96D905B6EAED977637E758B9928B18EA0DE58`, `2,886` bytes, `81` LF. All four have zero CR. Structural results remain identical to command 27172; the command-27174 retouch is external validator-owned mutable evidence, not a B005 direct edit.
- Current three-claim waited generated receipt: command `000000027183`, timestamp `2026-08-23T12:58:01-04:00`, owns the four current hashes/bytes/LF listed in Current Target State. Its SpellInventory CPP/H readback is exactly 15 legacy then 15 Pane2 definitions, two complete constructors, one global InterfaceEfx declaration, two complete class declarations and size guards, and zero excluded-unit/marker/stub/TODO/decompiler pollution. Its TargetSelection CPP/H readback is one `SpellInputPaneState` declaration/member/field and one matching definition, with no global prototype. Generated files were read only and remain supervisor/validator-owned mutable evidence.

## Changed Files
- Historical five-claim repair directly changed only `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`, `by-class/SpellInventoryPane.md`, `by-class/SpellInventoryPane2.md`, `by-file/SpellInventoryPane.md`, and this report. Validator-owned generated/registry/projected-stat refreshes were side effects, not direct edits.
- Current C-O1-026 callback directly changed only `by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md` and this report. The required validator owned the generated CPP/H refresh and registry/projected-stat side effects; B005 did not directly edit those artifacts.
- Current mixed-session/constructor repair changed only this UID0000O1 report. It preserved every ordinary by-* file, generated file, manual coverage file, IDA/session, audit/tracker/catalog, validator/lifecycle, archive, and goal from B005 mutation; no UID0000O1 companion was present to preserve.
- Current deterministic-frame repair changed only this UID0000O1 report. It preserved every ordinary, generated, coverage, IDA/transaction, audit/tracker/catalog, validator/lifecycle, and archive artifact from B005 mutation.
- Current prestate repair changed only this UID0000O1 report. It did not modify any accepted ordinary by-* file or any coverage, generated, IDA, audit/catalog/tracker, validator/lifecycle, archive, or execute state.
- Current U01 global-type repair changed only this UID0000O1 report. Canonical MCP use was read-only; B005 did not edit ordinary by-* files, manual coverage, generated output, audit/catalog/tracker, validator/lifecycle/registry, IDA/session state, archives, the goal, or execute state.
- Current missing-companion repair changed only this UID0000O1 report. It removed the false preservation implication, recorded the physical absence and active-report zero-script proof, and did not create or edit any companion.
- Current named-function-declarator repair changed only this UID0000O1 report. It changed no ordinary by-* doc, generated/coverage/audit/catalog artifact, IDA/session, validator/lifecycle/registry state, archive, companion, goal, or execute state.
- Current M03/M14 physical-frame handoff repair changed only this UID0000O1 report. It reconciled the direct F03 and inferred F14 post-type physical-frame contracts, preserved all ordinary/formal/generated evidence, and did not modify any ordinary by-* doc, coverage/generated/audit/catalog/tracker artifact, IDA/session, validator/lifecycle/registry state, archive, companion, goal, or execute state.
- Current F11/F20 physical-frame handoff repair changed only this UID0000O1 report. Read-only ordinary inspection found no contradiction, so no ordinary exception triggered. The repair preserves all ordinary/formal/generated/coverage evidence and changes no ordinary by-* doc, generated/coverage/audit/catalog/tracker artifact, IDA/session, validator/lifecycle/registry state, archive, companion, note, goal, other report, or execute state.
- Current 18-claim destination repair directly changed only `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` and this report. The ordinary delta is one active canonical generated-route paragraph under the accepted split heading; every other affected physical H2 already contained the accepted detail and therefore required only exact ledger/checklist destination reconciliation. Validator-generated/registry/projected-stat refreshes are validator-owned side effects. B005 directly edited no coverage/generated/audit/catalog/tracker, IDA/session, validator/lifecycle/registry, archive, companion, goal, or other report and did not invoke any `execute_report` variant.
- Current six-claim repair directly changed only `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`, `by-class/SpellInventoryPane.md`, `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md`, `by-class/SpellInputPaneState.md`, `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md`, and this report. Validator-owned generated/registry/projected-stat refreshes are side effects, not direct edits. B005 directly edited no coverage/generated/audit/catalog/tracker, IDA/session, validator/lifecycle/registry, archive, companion, goal, or other report and did not invoke any `execute_report` variant.
- Current three-claim repair directly changed only `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`, `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md`, `by-class/SpellInventoryPane.md`, `by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md`, `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md`, `by-file/SpellInventoryPane.md`, and this report. Validator-owned generated/registry/projected-stat refreshes are side effects, not direct edits. B005 directly edited no coverage/generated/audit/catalog/tracker, IDA/session, validator/lifecycle/registry, archive, companion, goal, or other report and did not invoke any `execute_report` variant.
- B005 directly edited exactly 28 ordinary by-* files plus this report. Each ordinary file was leased only for its edit batch, validated, reread, and released; no ordinary lease remained before the final report reconciliation.
- Renamed paths: UID00044F `SpellInventoryPane2ResetPage.md` -> `SpellInventoryPane2OnActivate.md`; UID00044G end `0x0057eaee` -> `0x0057eaf0`; UID00044L `OnPaneMessage.md` -> `OnServerMessage.md`; UID00044N end `0x0057f2ee` -> `0x0057f2f0`; UID00044O end `0x0057f36f` -> `0x0057f371`; UID00044P end `0x0057f3d1` -> `0x0057f3d3`; UID00044Q end `0x0057f486` -> `0x0057f488`. All old paths are absent and all destination paths exist.
- Direct-edit boundary: B005 did not directly edit generated files, manual coverage, tracker/audit/catalog, validator state/history, IDA, lifecycle/registry, or archive paths and did not run/probe/dry-run `execute_report`. Validator-owned generated refreshes are recorded above as readback only.
- Final ordinary-file SHA256/byte receipts follow; hashes were computed after final validation and physical reread.

| Path | SHA256 | Bytes |
| --- | --- | ---: |
| `by-file/SpellInventoryPane.md` | `6BE1A246D2B14B796FEBB7B96788CD138C34DA6CC7E45EA627597FFCE95E0D81` | 25938 |
| `by-file/NewSpellInventoryPane.md` | `7DD345D6FF6EE849CD7DFF963AE602B3949917D0BD70CF35D2905AF7B7D3E60E` | 25597 |
| `by-file/ScrollSpellInventoryPane.md` | `C885BAA2BE3AB0178EB87723A86D1BA42EB0D12DCB4956C58C0A9D0D97AE0C0E` | 28283 |
| `by-class/SpellInventoryPane.md` | `04EBF53B75F3E775D7B5ED55CE039912AC714B6C2C0FB40B87B7010C0CC6FF29` | 23295 |
| `by-class/SpellInventoryPane2.md` | `CD4415F291D0881592ACB99B7C622C44D84CF642A709880FE3EE7BF6E97FC612` | 20488 |
| `by-class/SpellInputPaneState.md` | `724160900D382C61CE37FE3D75D21D5264C71D1C12CD55542D712147E06C333B` | 15410 |
| `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` | `D11DF4F8787BF7EEE7F5D37F26B36E4C00AC7475DF1EC410E576074ED3B5D32A` | 34698 |
| `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md` | `D7AE16D14E1CC71F2D59BB2103DA545218C1E85F735E4A9F6D0C281C23A32E29` | 19777 |
| `by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md` | `3DAF9F7EF6A9A4DF9AFD17BBC1DBDEFC103739263B418AB59649028751FDD06A` | 18936 |
| `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` | `6D79EF2F39B7B70B1343BDCB71C37A572F439CFC79429B37ACBD9BD5CFD0F7BD` | 30914 |
| `by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md` | `3D0EA5B60928ED5B6927B648D45E60546FCBC1D2FCCF1B7E62A81A7CF7F0826F` | 4288 |
| `by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md` | `12571E0413DD3DA5906300C7400CF7ABF2C4319E07DA9C44EF55E21820FCF9C2` | 3180 |
| `by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate.md` | `93B3006C65449D97BCB853A236ADC940A8D458F1BF07A0C8115BF3BEAD29BDB2` | 2792 |
| `by-memory/0x0057eae0-0x0057eaf0.SpellInventoryPane2SetSpellInputActive.md` | `CF8366D851CF5426FCCC80DB1758985B409739C6304DB9A8488E66D642A1915C` | 2738 |
| `by-memory/0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual.md` | `0F4A62B54226AA605F14E90C0608CC2CC897C2496A5B304B95F195D5AA97FC41` | 2973 |
| `by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md` | `B716309127F19A1637E423BB8755C79181056479A8385B6FE4CAB2CF41782CEF` | 5152 |
| `by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md` | `56AE8B1B5AABC5B727CEC2B0E154A38102ECF33D27F90C33B8F6B2E7D1887CA6` | 3607 |
| `by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md` | `92BB5AA4CE96B139D48BC9E1020E60AFFE18A99305D202A418ECB2BD13459D24` | 4970 |
| `by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage.md` | `9F5FA34EC6D7EF6452939F5A0A9A045DC45FAA4F6D3B029D651DBF92E3C2AC27` | 2732 |
| `by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md` | `0609FD40B8E75296421C3B930FB689F4509FEAE92841352A397438CAEA5B47E2` | 4697 |
| `by-memory/0x0057f290-0x0057f2f0.SpellInventoryPane2SendDirectSpellPacket.md` | `ED9C5A2A25CAA42C32D2D9757561278B1B18A7333D27E94792107E7267EC9602` | 3073 |
| `by-memory/0x0057f2f0-0x0057f371.SpellInventoryPane2BuildPageButtonRect.md` | `FFFD0729A49B572D5C090AD3988FFF885C123732AEE10548D02A9B5B00F8EC1F` | 2957 |
| `by-memory/0x0057f380-0x0057f3d3.SpellInventoryPane2BuildSpellRowRect.md` | `CF1739AE9B9487338DBA869E8DF876E65766C281461F447A047B8811BB5D259C` | 2971 |
| `by-memory/0x0057f3e0-0x0057f488.SpellInventoryPane2HitTestPageButton.md` | `0169BDAF1146A075161C2237FAC2CA53F79D8283074470C5E3B036CCEAB9C9DC` | 2955 |
| `by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md` | `5D7A07F6BDEB3E062F5C1BEF8662AECD55D2A3665C6EC01909C1504D6BF9C4AD` | 2892 |
| `by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md` | `B2FB05CCCAE3B8501A29F30432B22B793FA65FD4F2A8AC298A219F67E7DEAE99` | 3001 |
| `by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md` | `47C9D85A90D68202A064AB913DBA54BFEC061C678BD390CF5A4052BCFFD91EED` | 20742 |
| `by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md` | `94D358396BFE11FDC0ECD6529895219B0869D0FDF7051CD5B391DE4F8B8D2BD9` | 26336 |

- Lease receipt: all historical ordinary leases were explicitly released batch-by-batch. In the current three-claim repair, B005 leased UID0001IH, UID0002RI, UID0000DN, UID00044J, UID0002RK, and UID0000O1 one at a time only for each edit/validator/physical-reread batch; every ordinary unlease returned `Success`. The first short report lease expired during the final physical audit, so cleanup returned `Rejected[No active lease]` and the lease report already showed no active rows. B005 then reacquired only this report to record that exact receipt and releases it immediately after the final audit; the authoritative external lease-report readback supplies the no-B005-row proof.
- Current F11/F20 report lease receipt: the initial report-only edit lease returned `Success` and expired during the required structural audit; cleanup returned `Rejected[No active lease]`, so no active lease remained. B005 reacquired only this report to record that exact receipt and releases it immediately after this edit; the authoritative external successful unlease and no-B005-row readback supply final release proof.
- Report lifecycle boundary: this artifact ends in exactly one physically terminal `READY_FOR_SUPERVISOR_EXECUTE` marker. The marker means ready for supervisor gates only; execution/archive authority remains supervisor/validator-owned and derives from the artifact's physical path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

The following 55 rows are ordered exact twins of the Claim And Incorporation Ledger. Current allocation is 52 checked and 3 unchecked: only supervisor-owned C-O1-051, C-O1-052, and C-O1-054 remain unchecked. Checkbox state records implementation evidence and does not assert lifecycle state.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C-O1-001 | 0000O1 | File contains legacy SpellInventoryPane and SpellInventoryPane2 only. | High | Code/vtable/resource islands and sibling audits. | `by-file/SpellInventoryPane.md` UID0000O1 `## Status`, `## Proposed Contents`, and `## File-Split Guidance` | replace | APPLIED_CALLBACK |
| [x] | C-O1-002 | 0000LU | NewSpellInventoryPane is excluded and remains separate. | High | UID0000LU audit, constructor caller, CPP/H. | `by-file/SpellInventoryPane.md` UID0000O1 `## Proposed Contents`; `by-file/NewSpellInventoryPane.md` UID0000LU `## UID0000O1 Exclusion Cross-Reference - 2026-08-22` | clarify-crossref | APPLIED_CALLBACK |
| [x] | C-O1-003 | 0000NJ | ScrollSpellInventoryPane is excluded and remains separate. | High | UID0000NJ audit and constructor route. | `by-file/SpellInventoryPane.md` UID0000O1 `## Proposed Contents`; `by-file/ScrollSpellInventoryPane.md` UID0000NJ `## UID0000O1 Exclusion Cross-Reference - 2026-08-22` | clarify-crossref | APPLIED_CALLBACK |
| [x] | C-O1-004 | 0001IH | Broad executable page remains a non-emitting split/index; only its bounded pre-callback status/covered-range narrative is historical, while accepted synchronization, Source Route Table, and Ownership Decision are active and state that exact children are already selected/emitted. | High | Mixed legacy/New/Pane2/compiler span; canonical UID0001IH path resolution; current CPP/H existence; command `000000027177` scope/route/ownership readback. | `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22`, `## Historical Pre-Callback Research Snapshot (Superseded 2026-08-15)` exact scope paragraph, `## Source Route Table`, and `## Ownership Decision` | repair-active-history-scope | APPLIED_CALLBACK |
| [x] | C-O1-005 | 0000DN | Legacy class is source-ready, size 0x100, owner/emitter UID0000O1; active prose and formal CPP/H agree on `m_pageIndex`, `OnActivate`, `m_isLastPage`, and `InterfaceEfx *m_spellEffect`, with rejected alternatives historicalized. | High | Constructor/destructor/vtables/wrapper size; accepted formal CPP/H; command `000000027169` physical Field Notes/current-prose readback; canonical generated CPP/H. | `by-class/SpellInventoryPane.md` UID0000DN `## UID0000O1 Accepted Class Reconstruction - 2026-08-22`, `## Status`, `## Method Notes`, `## Field Notes`, `## Evidence Notes`, `RECONSTRUCTION_CPP CODE`, and `RECONSTRUCTION_H CODE` | replace-formal-route | APPLIED_CALLBACK |
| [x] | C-O1-006 | 0002RI | Legacy aggregate remains non-emitting; active dispatcher/mapper identities are `ActivateSpellSlot` and `VisibleOrdinalToSpellSlot`, active names/types/source placement are resolved, and UID0000DN formal CPP/H owns the complete source. | High | Mixed methods/table/padding/external child; commands `000000027178`/`000000027179` plus waited root command `000000027183`; UID0000DN accepted formal source. | `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md` UID0002RI `## UID0000O1 Accepted Non-Emitting Index - 2026-08-22`, `## Covered Range`, `## ActivateSpellSlot Dispatcher Route Table`, and `## Reconstruction Notes`; `by-class/SpellInventoryPane.md` UID0000DN `## Method Notes`/`## Evidence Notes`; `by-file/SpellInventoryPane.md` UID0000O1 `## Behavior Summary`/`## IDA MCP Evidence` | synchronize-active-identities | APPLIED_CALLBACK |
| [x] | C-O1-007 | 0001II | Embedded shared setter remains external and returns source-level void; UID0000DM formal H supplies one coherent `SpellInputPaneState` class/member declaration matching the sole child definition. | High | 14 external callers, AL residue, command `000000027172`; generated H has one class/member and no global prototype, generated CPP has one matching definition. | `by-memory/0x0057c430-0x0057c43f.SpellInputPaneStateSetFlag.md` UID0001II accepted heading/`## Status`/`## Function`/formal CPP; `by-class/SpellInputPaneState.md` UID0000DM `## UID0000O1 External-Helper Correction - 2026-08-22`, `## Status`, `## Method Notes`, `## C++ Gate And Emission`, and `RECONSTRUCTION_H CODE` | repair-support | APPLIED_CALLBACK |
| [x] | C-O1-008 | 0000DO | Pane2 is the size-0x100 owner/emitter for UID0000O1; applied C-O1-026 completes its source-ready constructor and its current CPP/H route is canonical. | High | Constructor/vtables/wrapper/children; corrected UID00044D initializer/generated readback; physical current CPP/H and absent historical simroot file. | `by-class/SpellInventoryPane2.md` UID0000DO metadata header, `## UID0000O1 Accepted Class Reconstruction - 2026-08-22` size/layout/owner/emitter paragraphs, `## Status` current/historical route rows, `## Field And Split Notes`, `RECONSTRUCTION_CPP CODE`, and `RECONSTRUCTION_H CODE`; C-O1-026 exact UID00044D destination | replace-formal-route | APPLIED_CALLBACK |
| [x] | C-O1-009 | 0002RK | Pane2 broad parent remains a non-emitting exact index. | High | Exact child and gap inventory. | `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range` and `## Exact Child Pages` | repair-index | APPLIED_CALLBACK |
| [x] | C-O1-010 | 0000O1 | Dated validator command 000000026432 remains historical incomplete-CPP/absent-H evidence; active route text names the canonical current SpellInventoryPane CPP/H and separate excluded-unit outputs. | Certain | Historical command-26432 physical readback/path absence; current by-file route cells; command-27000 generated CPP/H existence, hashes, inventory, declarations, and zero-pollution readback. | `by-file/SpellInventoryPane.md` UID0000O1 `## UID0000O1 Accepted Whole-File Reconstruction - 2026-08-22`, `## Status`, and `## Proposed Contents`; fresh-gate readback of `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` and `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.h` | replace-generated-route | APPLIED_CALLBACK |
| [x] | C-O1-011 | 0000DN | Legacy constructor initializes packed state and MAGEFX InterfaceEfx. | High | 0x57c2d0 decompile/callees/resources. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` symbol `SpellInventoryPane::SpellInventoryPane` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-012 | 0000DN | Legacy destructor marks effect for deletion then destroys base. | High | 0x57c3a0. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` symbol `SpellInventoryPane::~SpellInventoryPane` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-013 | 0000DN | 0x57c410 is OnActivate, not generic ResetPage. | High | Primary vtable slot +0x48 and packet call. | `by-class/SpellInventoryPane.md` UID0000DN `## Method Notes`, `RECONSTRUCTION_CPP CODE`, and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::OnActivate` | rename-role | APPLIED_CALLBACK |
| [x] | C-O1-014 | 0000DN | 0x57c440 is PlaySpellEffect over InterfaceEfx*. | High | Constructor allocation and tail-call 0x4e9950 Play. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::PlaySpellEffect` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-015 | 0000DN | Legacy OnPaint uses 13-entry pages and EPD resources. | High | 0x57c450 decompile/resource refs. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` symbol `SpellInventoryPane::OnPaint` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-016 | 0000DN | Legacy key virtual uses Event* and page keys. | High | 0x57c710/vtable/Event layout. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::OnKeyEvent` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-017 | 0000DN | Legacy mouse virtual handles page/single/double activation. | High | 0x57c790 and helper xrefs. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::OnMouseEvent` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-018 | 0000DN | Legacy packet virtual calls OnActivate for opcodes 23/24. | High | 0x57c980 and vtable slot. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::OnServerMessage` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-019 | 0000DN | Legacy activation dispatch includes targeted shortcut. | High | 0x57c9b0 switch/callees. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::ActivateSpellSlot` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-020 | 0002RI | Legacy alignment/jump-table/padding is compiler-covered no-code. | Certain | Bytes at 0x57cc42 and exact gaps. | `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md` UID0002RI `## Covered Range` | document-no-code | APPLIED_CALLBACK |
| [x] | C-O1-021 | 0000DN | Legacy raw direct packet helper is retained private source. | High | Complete 0x57cc70 body, zero xrefs, inline duplicate. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::SendDirectSpellPacket` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-022 | 0000DN | Legacy page-rectangle helper is source-owned. | High | 0x57ccd0 and mouse caller. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::BuildPageButtonRect` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-023 | 0000DN | Legacy raw row-rectangle helper is retained source. | High | Complete 0x57cd60 body, zero start xrefs. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::BuildSpellRowRect` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-024 | 0000DN | Legacy raw page hit-test helper is retained source. | High | Complete 0x57cdc0 body, inline duplicate. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbol `SpellInventoryPane::HitTestPageButton` | add-definition | APPLIED_CALLBACK |
| [x] | C-O1-025 | 0000DN | Legacy row hit-test and ordinal mapper are source-owned. | High | 0x57ce70/0x57cf10 two callers each. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` symbols `SpellInventoryPane::HitTestSpellRow` and `SpellInventoryPane::VisibleOrdinalToSpellSlot` | add-definitions | APPLIED_CALLBACK |
| [x] | C-O1-026 | 00044D | Pane2 constructor initializes `m_pageIndex(0)`, `m_isLastPage(false)`, and `m_spellInputActive(false)`; its 16-bit `+0xf8` clear explicitly covers `+0xf9`. | High | Vtable triad; raw bytes `66 C7 86 F8 00 00 00 00 00` and `C6 86 FA 00 00 00 00`; ordinary SHA256 `3D0EA5B60928ED5B6927B648D45E60546FCBC1D2FCCF1B7E62A81A7CF7F0826F`; validator/generated command `000000026749`. | `by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md` UID00044D `RECONSTRUCTION_CPP CODE`, `## Source Reconstruction Notes`, and `## C++ Disposition`; scoped validator and physical generated CPP/H readback | repair-definition-and-prose | APPLIED_CALLBACK |
| [x] | C-O1-027 | 00044E | Pane2 ordinary destructor remains empty source body. | High | Vtable reset/base cleanup. | `by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md` UID00044E `RECONSTRUCTION_CPP CODE` | retain-definition | APPLIED_CALLBACK |
| [x] | C-O1-028 | 00044F | Pane2 child is `OnActivate`; every active inbound role uses that identity and the rejected reset-page label is historical only. | High | Primary vtable/opcode-handler call; command `000000027171` physical UID0002RK inbound-label readback. | Current `by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate.md` UID00044F title/`## Status`/`## Behavior`/formal CPP; historical rename provenance from `SpellInventoryPane2ResetPage.md`; `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Exact Child Pages`, `## Accepted Current Implementation Path`, and `## Cross-References`; UID0001IH accepted split heading | rename-path-role | APPLIED_CALLBACK |
| [x] | C-O1-029 | 00044G | Pane2 raw local input-active setter ends at 0x57eaf0 and remains private source. | High | Exact duplicate body, zero direct xrefs, `c2 04 00` terminal bytes. | UID00044G callback rename from `by-memory/0x0057eae0-0x0057eaee.SpellInventoryPane2SetSpellInputActive.md` -> current `by-memory/0x0057eae0-0x0057eaf0.SpellInventoryPane2SetSpellInputActive.md`: current filename, `# 0x0057eae0-0x0057eaf0 SpellInventoryPane2 SetSpellInputActive` title, `## UID0000O1 Accepted Exact Range - 2026-08-22`, `## Status`, and `RECONSTRUCTION_CPP CODE`; exact parent range rows in `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range`/`## Exact Child Pages` and `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22` | rename-range-definition | APPLIED_CALLBACK |
| [x] | C-O1-030 | 00044H | One-byte nullsub stays non-emitting/no declaration. | High | `ret`, no xrefs/pointer hit/side effects. | `by-memory/0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual.md` UID00044H `## No-Code Proof` | retain-no-code | APPLIED_CALLBACK |
| [x] | C-O1-031 | 00044I | Pane2 paint uses project APIs, page size 13, initial rect constants. | High | 0x57eb00 and rdata 0x62d1d0. | `by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md` UID00044I `RECONSTRUCTION_CPP CODE` | replace-definition | APPLIED_CALLBACK |
| [x] | C-O1-032 | 00044J | Pane2 key method uses `Event *` and `kEventKeyDown`; `PaneKeyEvent` is rejected historical naming, and the UID0002RK active index agrees on `Event *`/`OnServerMessage` authority. | High | 0x57edb0/Event layout/vtable; commands `000000027180`/`000000027181`; current formal child signatures. | `by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md` UID00044J `## UID0000O1 Accepted Source Definition - 2026-08-22`, `## Source Reconstruction Notes`, and `RECONSTRUCTION_CPP CODE`; `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Source-Facing Type And Route Names` | synchronize-event-authority | APPLIED_CALLBACK |
| [x] | C-O1-033 | 00044K | Pane2 mouse uses page stride 13 and hit rows 10. | High | 0x57ee30/0x57f490. | `by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md` UID00044K `RECONSTRUCTION_CPP CODE` | replace-definition | APPLIED_CALLBACK |
| [x] | C-O1-034 | 00044L | Pane2 child is `OnServerMessage`, calls `OnActivate`, and every active inbound role uses that identity; the rejected pane-message label is historical only. | High | 0x57f000/primary slot; command `000000027171` physical UID0002RK inbound-label readback. | Current `by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage.md` UID00044L title/`## Status`/`## Behavior`/formal CPP; historical rename provenance from `SpellInventoryPane2OnPaneMessage.md`; `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Exact Child Pages`, `## Accepted Current Implementation Path`, and `## Cross-References`; UID0001IH accepted split heading | rename-path-role | APPLIED_CALLBACK |
| [x] | C-O1-035 | 00044M | Pane2 activation has eight input-kind routes and owned jump table. | High | 0x57f030 decompile/table bytes. | `by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md` UID00044M `## Spell Input Routes` and `RECONSTRUCTION_CPP CODE` | replace-definition | APPLIED_CALLBACK |
| [x] | C-O1-036 | 00044N | Direct packet child exclusive end is 0x57f2f0. | Certain | `c2 04 00` byte end. | UID00044N callback rename from `by-memory/0x0057f290-0x0057f2ee.SpellInventoryPane2SendDirectSpellPacket.md` -> current `by-memory/0x0057f290-0x0057f2f0.SpellInventoryPane2SendDirectSpellPacket.md`: current filename, `# 0x0057f290-0x0057f2f0 SpellInventoryPane2 SendDirectSpellPacket` title, `## UID0000O1 Accepted Exact Range - 2026-08-22`, `## Status`, and `RECONSTRUCTION_CPP CODE`; exact parent rows in `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range`/`## Exact Child Pages` and `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22` | rename-range | APPLIED_CALLBACK |
| [x] | C-O1-037 | 00044O | Page-rect child exclusive end is 0x57f371. | Certain | `c2 08 00` byte end. | UID00044O callback rename from `by-memory/0x0057f2f0-0x0057f36f.SpellInventoryPane2BuildPageButtonRect.md` -> current `by-memory/0x0057f2f0-0x0057f371.SpellInventoryPane2BuildPageButtonRect.md`: current filename, `# 0x0057f2f0-0x0057f371 SpellInventoryPane2 BuildPageButtonRect` title, `## UID0000O1 Accepted Exact Range - 2026-08-22`, `## Status`, and `RECONSTRUCTION_CPP CODE`; exact parent rows in `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range`/`## Exact Child Pages` and `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22` | rename-range | APPLIED_CALLBACK |
| [x] | C-O1-038 | 00044P | Row-rect child exclusive end is 0x57f3d3 and rows are 0..9. | Certain | Return bytes and bounds loop. | UID00044P callback rename from `by-memory/0x0057f380-0x0057f3d1.SpellInventoryPane2BuildSpellRowRect.md` -> current `by-memory/0x0057f380-0x0057f3d3.SpellInventoryPane2BuildSpellRowRect.md`: current filename, `# 0x0057f380-0x0057f3d3 SpellInventoryPane2 BuildSpellRowRect` title, `## UID0000O1 Accepted Exact Range And Rows - 2026-08-22`, `## Status`, `## Behavior`, and `RECONSTRUCTION_CPP CODE`; exact parent rows in `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range`/`## Exact Child Pages` and `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22` | rename-range | APPLIED_CALLBACK |
| [x] | C-O1-039 | 00044Q | Page-hit child exclusive end is 0x57f488. | Certain | Return bytes. | UID00044Q callback rename from `by-memory/0x0057f3e0-0x0057f486.SpellInventoryPane2HitTestPageButton.md` -> current `by-memory/0x0057f3e0-0x0057f488.SpellInventoryPane2HitTestPageButton.md`: current filename, `# 0x0057f3e0-0x0057f488 SpellInventoryPane2 HitTestPageButton` title, `## UID0000O1 Accepted Exact Range - 2026-08-22`, `## Status`, and `RECONSTRUCTION_CPP CODE`; exact parent rows in `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range`/`## Exact Child Pages` and `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` UID0001IH `## UID0000O1 Exact SpellInventoryPane Split Synchronization - 2026-08-22` | rename-range | APPLIED_CALLBACK |
| [x] | C-O1-040 | 00044R | Pane2 hit-test scans exactly ten rows. | Certain | 0x57f490 loop `<=9`. | `by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md` UID00044R `## Behavior` and `RECONSTRUCTION_CPP CODE` | replace-definition | APPLIED_CALLBACK |
| [x] | C-O1-041 | 00044S | Pane2 ordinal mapper scans active slots 1..52. | High | 0x57f530. | `by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md` UID00044S `RECONSTRUCTION_CPP CODE` | replace-definition | APPLIED_CALLBACK |
| [x] | C-O1-042 | 0002RK | All Pane2 gaps/padding and switch table have exact no-code rows. | Certain | Raw bytes across entire parent. | `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK `## Covered Range` and `## No Aggregate C++ And Tiny-Body Dispositions` | replace-inventory | APPLIED_CALLBACK |
| [x] | C-O1-043 | 0002RL | Target adjustor thunks/wrappers remain compiler-only; NewSpell rows excluded. | Certain | Six thunks/three wrappers and vtables. | `by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md` UID0002RL `## Covered Range` and `## Source-Quality Disposition And No-Code Proof` | clarify-target-split | APPLIED_CALLBACK |
| [x] | C-O1-044 | 00026J | Legacy/P2 vtables are target compiler data; NewSpell/macro data excluded. | High | Exact rdata clusters/store xrefs. | `by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md` UID00026J `## Ownership Map` | update-crossref | APPLIED_CALLBACK |
| [x] | C-O1-045 | 0000O1 | EPD/EPF/format/rect constants emit through source literals, not raw arrays. | High | Resource xrefs and bytes. | `by-file/SpellInventoryPane.md` UID0000O1 `## UID0000O1 Accepted Whole-File Reconstruction - 2026-08-22` target read-only-data/source-literal paragraph; `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE`; `by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md` UID00044I `RECONSTRUCTION_CPP CODE` | add-source-literals | APPLIED_CALLBACK |
| [x] | C-O1-046 | 0000DN | Legacy H fragment opens guard/includes, globally forward-declares InterfaceEfx before the class, and declares the exact 0x100 class. | High | PanelPane 0xf8, wrapper size, accepted formal declaration order, and fresh canonical parser-scope evidence. | `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_H CODE`; this report U01.a/U01.b handoff | add-header-fragment | APPLIED_CALLBACK |
| [x] | C-O1-047 | 0000DO | Pane2 H fragment declares exact 0x100 class and closes guard. | High | PanelPane 0xf8 and wrapper size. | `by-class/SpellInventoryPane2.md` UID0000DO `RECONSTRUCTION_H CODE` | add-header-fragment | APPLIED_CALLBACK |
| [x] | C-O1-048 | 0000O1 | Deterministic emitter order is DN 010, DO 020 with child 100..240. | High | Required preamble/header ordering. | Metadata-header `EMITTER_POSITION_OPTIONAL` in `by-class/SpellInventoryPane.md` UID0000DN and `by-class/SpellInventoryPane2.md` UID0000DO; the same metadata-header field in each exact child `by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md` UID00044D, `by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md` UID00044E, `by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate.md` UID00044F, `by-memory/0x0057eae0-0x0057eaf0.SpellInventoryPane2SetSpellInputActive.md` UID00044G, `by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md` UID00044I, `by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md` UID00044J, `by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md` UID00044K, `by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage.md` UID00044L, `by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md` UID00044M, `by-memory/0x0057f290-0x0057f2f0.SpellInventoryPane2SendDirectSpellPacket.md` UID00044N, `by-memory/0x0057f2f0-0x0057f371.SpellInventoryPane2BuildPageButtonRect.md` UID00044O, `by-memory/0x0057f380-0x0057f3d3.SpellInventoryPane2BuildSpellRowRect.md` UID00044P, `by-memory/0x0057f3e0-0x0057f488.SpellInventoryPane2HitTestPageButton.md` UID00044Q, `by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md` UID00044R, and `by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md` UID00044S; supervisor refresh/readback of `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` and `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.h` | set-order | APPLIED_CALLBACK |
| [x] | C-O1-049 | 0000O1 | Dependencies stay externally owned and are included/forward-declared only. | High | Call graph and current project headers. | `by-file/SpellInventoryPane.md` UID0000O1 `## UID0000O1 Accepted Whole-File Reconstruction - 2026-08-22` external-dependency paragraph; `by-class/SpellInventoryPane.md` UID0000DN `RECONSTRUCTION_CPP CODE` and `RECONSTRUCTION_H CODE` | document-imports | APPLIED_CALLBACK |
| [x] | C-O1-050 | 0000O1 | No target-owned global/static storage definition exists. | High | Entity/global/xref search and constructors. | `by-file/SpellInventoryPane.md` UID0000O1 `## UID0000O1 Accepted Whole-File Reconstruction - 2026-08-22` no-target-global/static-storage paragraph | record-negative | APPLIED_CALLBACK |
| [ ] | C-O1-051 | 0000O1 | Exact IDA handoff is supervisor-only, fresh-canonical gated, orders global incomplete InterfaceEfx before the legacy pane UDT, and supplies complete named function declarators plus deterministic public-type/physical-frame contracts for M01-M21. | Certain | Complete canonical U/M/F/R/D/N/P prestates; fresh canonical type-scope/parser analogues; failed isolated old-U01 nested result; deterministic U01.a/U01.b global readbacks; failed anonymous M01 parser receipt; direct unsaved M03/F03 two-row receipt and M14/F14 `>=0.99` parallel inference; strict M11/F11 failed-batch history plus independent blank-comment F11/F20 probes proving public `y, x` with protected physical `row@0x28/0x4:int; column@0x2c/0x4:int`; 21 exact named-declarator/normalized readbacks; eight current modeled type deltas including M05 `int __thiscall(int this)`; M13 end; R01-R09 no-action/D01-D09 absent. | `tools/leaser/Agents/Agent-B005/research/0000O1-SpellInventoryPane-file-source-quality.md` UID0000O1 `## IDA Rename / Type / Comment Recommendations`, including Gate 2B history/order, U01.a/U01.b/U02, M01-M21, `### Named Function Declarator Parser Contract`, `### Fresh-Current Modeled Receipts`, `### Modeled Frame Contracts` F01-F21 with exact F11/F20 zero-delta protections, `### Raw No-Action Protection Contracts` R01-R09/D01-D09, N01, P01/P0, and final aggregate readback; `tools/leaser/Agents/b-report-validation-audit.md` exact UID0000O1 supervisor Gate 2B audit entry with per-action, named-declarator/normalized-type, F03 observed/F14 inferred frames, F11/F20 public-type versus physical-frame receipts, global-versus-nested type, and raw no-action pre/post/protection receipts | supervisor-ida | PLANNED_GATE1 |
| [ ] | C-O1-052 | 0000O1 | Manual coverage rows are stale and need exact supervisor replacements/insertions. | Certain | Physical manual-row readback. | `by-file/-coverage-report.md` `## Covered Items To Replicate` replace UID0000O1 row; `by-class/-coverage-report.md` `## Covered Items To Replicate` replace UID0000DM/UID0000DN/UID0000DO rows; `by-memory/-coverage-report.md` `## Covered Items` replace UID0001IH/UID0002RI/UID0001II/UID0002RK/UID0002RL and UID00026J rows, then insert UID00044D-UID00044S immediately after UID0002RK and before UID0002RL | supervisor-coverage | PLANNED_GATE1 |
| [x] | C-O1-053 | 0000O1 | Callback score metadata and active support-score prose are physically applied; completed C-O1-026 adds no score beyond the accepted defended state. | High | Applied metadata receipts; UID0000DO active UID0002RK `94/95` and UID0001IH `91/94` prose; corrected constructor/readback; remaining stripped names. | Metadata-header `COMPLETION`/`CONFIDENCE` fields in `by-file/SpellInventoryPane.md` UID0000O1, `by-class/SpellInventoryPane.md` UID0000DN, `by-class/SpellInventoryPane2.md` UID0000DO, `by-memory/0x0057c2d0-0x0057cf6b.SpellInventoryPaneLegacyCoreAndHelpers.md` UID0002RI, and `by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md` UID0002RK; `by-class/SpellInventoryPane2.md` UID0000DO `## Evidence Notes` active support-score rows | update-score | APPLIED_CALLBACK |
| [ ] | C-O1-054 | 0000O1 | After applied C-O1-026, a fresh independent supervisor verification must prove complete CPP/H without markers/stubs or an initializer omission. | Certain | Dated command 000000026432 incomplete-CPP/absent-H snapshot; historical 000000026502/000000026517 omission receipts; B005 callback readback command 000000026749 is complete but does not replace supervisor Gate 2A authority. | Supervisor fresh Gate 2A verification of validator-generated `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` and `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.h` after the accepted C-O1-026 callback | refresh-verify | PLANNED_GATE1 |
| [x] | C-O1-055 | 0000O1 | B005 changed only the named ordinary by-* docs and this report while preserving generated/coverage/IDA/audit/lifecycle state from direct mutation. | Certain | Gate 1 authorization, changed-file hashes, validator receipts, and prohibited-state boundary. | `tools/leaser/Agents/Agent-B005/research/0000O1-SpellInventoryPane-file-source-quality.md` UID0000O1 `## Changed Files` | preserve-boundary | VERIFIED_CALLBACK_BOUNDARY |

Research/report evidence pass:
- [x] Supervisor Gate 1 validation completed before the C-O1-026 implementation for exact SHA256 `87C4B1598D35F33D3455893C46857FE69D1E697FFEA0D785A0116CC8C05233F6`.
- [x] Exhaustive whole-file inventory completed and reconciled against IDA, related by-* pages, generated output, and matching reports.
- [x] Every file-owned item has explicit behavior, owner/emitter/source placement, CPP/H or no-code, metadata/score, destination, ledger, and checklist coverage.
- [x] B005 generated snapshots audited and every ordinary deficiency has an exact disposition; only fresh independent supervisor Gate 2A remains pending under C-O1-054.
- [x] Target/support docs updated at every concrete accepted ordinary path, including the UID00044D formal/prose destination under C-O1-026.
- [x] Additional declared UIDs: not applicable; only UID0000O1 is declared.
- [x] Evidence-time target state and actual evidence checks recorded.
- [x] Claim ledger and ordered exact checklist twins passed Gate 1 and were reconciled after callback verification.
- [x] Metadata/score changes applied.
- [x] Owner/emitter/reconstructable changes applied.
- [x] Split/rename/new-child changes applied; no new UID is required.
- [x] Source-placement/range/padding/reclassification changes applied; IDA actions remain protected for supervisor Gate 2B.
- [ ] Supervisor Gate 2B IDA handoff verified/applied; B005 did not apply it.
- [x] First-draft CPP/H blocks applied, including UID00044D's corrected three-initializer constructor.
- [x] Third-party import not applicable.
- [x] Exact target/support report facts incorporated.
- [x] Historical/stale assumptions and negative evidence preserved.
- [x] Wave3 mention rejected as stale and independently reproved where relevant.
- [x] Open questions retained only with evidence-backed dispositions.
- [x] Scoped validators run during accepted implementation callback.
- [ ] Exact manual coverage replacements and fresh independent generated Gate 2A verification remain supervisor-owned.

Implementation callback pass:
- [x] Supervisor-owned IDA changes remain supervisor-controlled and were not applied by B005 during research or callback.
- [x] All accepted whole-file inventory claims incorporated across target/support pages.
- [x] All accepted routing repairs and CPP/H are applied; current generated CPP/H physically prove the corrected UID00044D constructor.
- [x] Report accepted by supervisor for implementation.
- [x] All target/support details incorporated at report-level specificity.
- [x] Primary UID0000O1 physically verified against ledger and destinations.
- [x] Claim ledger verification states updated after application.
- [x] Metadata/score/owner/emitter/split/rename changes, C-O1-026 CPP/prose, canonical active generated routes, and UID0002RK/UID0001IH support-score prose applied with exact receipts.
- [x] Historical/stale assumptions and negative evidence preserved.
- [x] No concrete ordinary source blocker remains; all true uncertainties remain evidence-backed non-blockers.
- [x] Scoped validators run and recorded.
- [ ] Report-local C-O1-054 remains intentionally unchecked pending fresh independent supervisor Gate 2A generated verification.
- [x] Remaining supervisor-owned C-O1-051, C-O1-052, and C-O1-054 are listed with exact actor and authority boundaries.
- [x] Report body remains lifecycle-neutral, has only balanced `cpp`/`text` fences with zero executable-language scripting, accurately records that no UID0000O1 companion is present, and ends in exactly one physically terminal `READY_FOR_SUPERVISOR_EXECUTE` marker; the marker denotes readiness for supervisor gates and does not assert execution or archive state.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000027235","destination_path":"executed-b-agent-research/B005/0000O1-SpellInventoryPane-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0000O1-SpellInventoryPane-file-source-quality.md","timestamp":"2026-08-23T19:34:37-04:00","uid":"0000O1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
