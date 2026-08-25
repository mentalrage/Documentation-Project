** TARGET-REPORT-UID:000179 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID000179 ObjectStatusBlobParsers Ownership / Split Research


## Finalized Report / Current Recommendation
- Implemented callback state: UID000179 is now a reviewed `92/93` non-emitting split index; validator-issued children UID0004LK, UID0004LL, and UID0004LM own `ParseTaggedStatus`, `ParseFullStatus`, and `ParsePartialStatus`; complete class UID00009S emits the naturally aligned 68-byte declaration and children through file UID0000M6.
- Final disposition: UID000179 retains exact range `0x004d1f30-0x004d2697`, owner UID00009S, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal body, and `Nested:-4`. The three exact children carry positions 10/20/30 and scores `92/94`, `91/93`, `92/94`; UID00017A closes cumulative nesting at `-4`.
- Callback completion: accepted C01-C33 and Destinations 1-9 were applied without compression, all 38 changed by-* pages reached final scoped `ok: 1`, all B005 leases were released, final waited refresh command `000000009679` completed, and generated ObjectStatusBlob/HeadSelectDialog/MessageDialogs/SelfLookPane source was verified read-only.
- Confidence: very strong for boundaries, split, signatures, parse behavior, field offsets/types, caller families, globals, source route, and first-draft bodies; strong for the inferred original member spellings and the exact semantic labels of a few shared/overloaded status bytes.

## Supporting Research
- This artifact originated as the independent report-only UID000179 research pass assigned after UID00011U and now also records the accepted same-report implementation callback. No prior B report directly audits UID000179; older references use it only as a dependency, field-alias source, consumer, or predecessor boundary.
- The main parser evidence was collected against adopted NexusTK IDB database session `c81909be` on 2026-07-13. That worker disappeared only during the final SelfLook raw-helper support recheck, so work paused without substituting fallback evidence. After the supervisor restored MCP, a fresh `idb_list` discovered the sole active adopted `NexusTK.exe.i64` session as `29ca807d`; `server_health` returned `status=ok`, image base `0x00400000`, and ready auto-analysis, Hex-Rays, and 2067-entry string cache state. The interrupted lookup/raw-byte/xref/decompile checks were then repeated successfully against `29ca807d`. These are evidence-time facts and do not assert either session remains live later.
- Current Wave2/Wave3 material was not used as authority. Historical `by-memory/-report.old.md` rows were found and treated only as naming/search provenance after every substantive claim was rechecked against current documentation, current generated output, IDA MCP, raw resources, or direct consumer behavior.
- Comparative protocol vocabulary was checked in the public Hybrasyl [`DisplayUser.cs`](https://github.com/hybrasyl/server/blob/develop/hybrasyl/Networking/ServerPackets/DisplayUser.cs) source. Its helmet/body/weapon/shield/hair/accessory/overcoat/skin/invisible/face concepts corroborate field vocabulary only; packet version/order differs and it is explicitly rejected as exact NexusTK layout proof.

### Prior B-report search record (2026-07-13 Gate 1 repair)

- Search method: case-insensitive literal filename/content searches with `rg -i -l -F --glob '*.md'` were run once per exact term, followed by a case-insensitive combined-union `rg` pass. Every unique matching Markdown artifact was opened and its matching lines plus report target/provenance were read before classification below.
- Exact target/address/name terms searched: `000179`, `0x004d1f30`, `ObjectStatusBlobParsers`, `ObjectStatusBlob`, `sub_4D1F30`, `sub_4D1FA0`, and `sub_4D2640`.
- Exact owner/file/source-family terms searched: `00009S`, `0000M6`, `by-class/ObjectStatusBlob.md`, `by-file/ObjectStatusBlob.md`, `NexusTK/map/ObjectStatusBlob.cpp`, and `ObjectStatusBlob.cpp`.
- Exact existing/proposed source-facing names searched: `ParseTaggedStatus`, `ParseFullStatus`, and `ParsePartialStatus`.
- Roots checked: central `executed-b-agent-research/**/*.md` including its invalidated subtree; every active `tools/leaser/Agents/Agent-B*/research/**/*.md` tree; and the entire legacy `archived/**/*.md` tree, which subsumes `archived/b-agent-reports-20260623/**` (including per-agent `research/executed/older` trees) and `archived/duplicate-loose-b-agent-reports/**`.
- Root results: central executed reports produced 28 unique prior matches; active Agent-B research trees produced only this current B005 report; the complete legacy archived tree produced zero matches. No other active report matched.
- Per-term result counts, including the current report where it matched: `000179` 11; `0x004d1f30` 12; `ObjectStatusBlobParsers` 10; `ObjectStatusBlob` 19; `sub_4D1F30` 3; `sub_4D1FA0` 5; `sub_4D2640` 3; `00009S` 4; `0000M6` 5; `by-class/ObjectStatusBlob.md` 3; `by-file/ObjectStatusBlob.md` 2; `NexusTK/map/ObjectStatusBlob.cpp` 2; `ObjectStatusBlob.cpp` 2; `ParseTaggedStatus` 8; `ParseFullStatus` 1; `ParsePartialStatus` 1. The last two names occur only in this current report.

| Matching report opened | Classification | Stale / superseded disposition | Useful finding retained |
| --- | --- | --- | --- |
| `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch8.md` | Incidental callee evidence; target is MapPane packet splitting. | Raw names `sub_4D1FA0`/`sub_4D2640` are superseded by the member-method names in this report; call behavior remains useful. | A MapPane packet body calls both full and partial status decoders. |
| `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch9.md` | Incidental consumer/ownership evidence; target is a different MapPane packet leaf. | Raw decoder names are superseded; its dependency-not-owner conclusion remains current. | MapPane selects between the two status encodings, while `ObjectStatusBlob` is a dependency rather than MapPane-owned parser source. |
| `executed-b-agent-research/B001/0001BR-SpellMenuDialogs-source-quality.md` | Incidental consumer evidence. | Compatible with the current member API; no target-specific stale claim retained. | Emitted SpellMenu source constructs an `ObjectStatusBlob` and advances through `objectStatus.ParseTaggedStatus(cursor)`. |
| `executed-b-agent-research/B001/0001D5-objectpane-core-source-quality.md` | Incidental negative/disambiguation evidence. | Current and not superseded. | `ObjectPane+0x108` is a separate 16-byte rectangle record, explicitly not the 68-byte ObjectStatusBlob. |
| `executed-b-agent-research/B001/0001FI-HeadSelectDialogCore-source-quality.md` | Incidental but directly relevant HeadSelect consumer support. | Its static two-argument `ObjectStatusBlob::ParseTaggedStatus(&m_previewObject, ...)` form and unresolved broad field model are superseded by Destinations 2 and 6. | Confirms a 68-byte preview blob at `HeadSelectDialog+0x278`, compact `headIndex`/`headDrawOffset` aliases, and parser-driven cursor advance. |
| `executed-b-agent-research/B001/0001FJ-textdialog-core-source-split-audit.superseded-by-quality.md` | Incidental caller evidence. | The artifact is explicitly superseded by a later quality report; only the bounded call fact is retained. | TextDialog construction calls parser entry `0x004d1f30`, adding one UI caller-family lead. |
| `executed-b-agent-research/B002/00007Q-MapPane-class-source-quality.md` | Incidental owner-exclusion evidence. | Current and not superseded for ownership. | Treats ObjectStatusBlob as a MapPane dependency and rejects moving MapPane packet-handler ownership to the blob. |
| `executed-b-agent-research/B002/0001BV-ObjectImageButtonPaneCore-source-quality.md` | Incidental object-image consumer support. | Compatible; later ObjectImageControl evidence supplies the stronger exact copied-layout proof. | The button constructor forwards `const ObjectStatusBlob *` and bounds to its base, preserving the shared descriptor type. |
| `executed-b-agent-research/B002/0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality.md` | Incidental but substantial MapPane consumer support. | Its `+0x2a..+0x30` title interpretation and broad tail labels are stale and explicitly superseded by this report's riding/Part/color map; kind and consumer facts remain useful. | Links UID000179/class/file support, resolves status kinds and compact `+4/+6` use, and confirms MapPane create/update consumes rather than owns the blob. |
| `executed-b-agent-research/B002/00030R-FittingRoomItemEntryVectorInsert-source-quality.md` | Incidental numeric false positive. | No target claim; match is validator command id `000000000179`. | None for UID000179. |
| `executed-b-agent-research/B003/0002E3-SimpleUStringAssignWideCount-source-quality.md` | Incidental callee inventory. | Raw caller label `sub_4D1FA0` is superseded; helper-use addresses remain exact supporting evidence. | Records nine `SimpleUStringAssignWideCount` uses inside the full parser, supporting normal string assignment in riding metadata handling. |
| `executed-b-agent-research/B003/0002IZ-0002J1-maptileimagelib-source-quality.md` | Incidental predecessor/boundary evidence. | Current boundary facts retained; it does not analyze parser bodies. | Confirms `sub_4D1F30` is the next function after fourteen `0xcc` bytes at `0x004d1f22-0x004d1f30` and marks a new ObjectStatusBlob owner family. |
| `executed-b-agent-research/B004/00012T-DialogCategorySwitch-source-quality.md` | Incidental duplicated HeadSelect consumer source. | Static two-argument parser call is superseded by Destination 6. | Preserves the HeadSelect packet offset and parser-consumed-length control flow. |
| `executed-b-agent-research/B005/00017N-ItemObjImageLibLocalMethodCluster-source-quality.md` | Incidental numeric false positive. | No target claim; match is validator command id `000000001794`. | None for UID000179. |
| `executed-b-agent-research/B005/0002DV-SimpleUStringClear-source-quality.md` | Incidental callee inventory. | Raw caller label `sub_4D1FA0` is superseded; cleanup addresses remain useful. | Records fourteen normal/EH `SimpleUStringClear` references from the full parser, supporting source-level RAII cleanup rather than manual raw calls. |
| `executed-b-agent-research/B006/0001BL-MerchantDialogPaneBase-source-quality.md` | Incidental consumer and owner-exclusion evidence. | Compatible with the current member API; no retained stale target claim. | Merchant action parsing calls tagged status at string offset `+8`, uses its consumed length, and treats ObjectStatusBlob as a callee dependency. |
| `executed-b-agent-research/B006/0002RN-StringBaseShareAssignAndAccess-source-quality.md` | Incidental numeric false positive. | No target claim; match is validator command id `000000001799`. | None for UID000179. |
| `executed-b-agent-research/B008/0001BU-ObjectImageControlPane-source-quality.md` | Incidental but strong direct consumer/layout support. | Its admitted unresolved original spellings and any inherited incomplete field labels are superseded by this report; exact copy/dispatch evidence remains current. | Confirms a `0x44`-byte ObjectStatusBlob copy at control `+0x108..+0x14b`, kind `0/1/2` render dispatch, display byte `+0x28`, and compact `+4/+6` consumers. |
| `executed-b-agent-research/B008/0001FK-NexonclubProxyDialogConstructor-source-quality.md` | Incidental UI consumer evidence. | Compatible with the current member API; no target-body analysis to retain as authority. | Confirms `sub_4D1F30` as tagged parse, local `ObjectStatusBlob` default byte `0x50`, packet offset `+6`, and consumed-length cursor advance. |
| `executed-b-agent-research/B009/000088-MetaMan-class-source-quality.md` | Incidental evidence-list match only. | No stale parser claim; it merely lists the parser page among MetaMan support checked. | Establishes only that a prior MetaMan audit consulted the parser support page; it contributes no direct parser-body finding. |
| `executed-b-agent-research/B009/0001MJ-GroupInputPane-empty-emitter-source-quality.md` | Incidental numeric false positive. | No target claim; match is validator command id `000000000179`. | None for UID000179. |
| `executed-b-agent-research/B010/0000LA-MessageDialogs-empty-emitter-family-source-quality.md` | Incidental but directly relevant MessageDialog consumer support. | Free `ParseTaggedStatus(&objectStatus, ...)` and `fields[40]` are stale and superseded by Destination 7's member call and `m_displayStatusByte`; payload behavior remains useful. | Confirms payload `+8` tagged status, default `0x50`, consumed-length trailer offsets, two BE16 fields, and opcode `0x3a` response flow. |
| `executed-b-agent-research/B010/00022D-PatchPane2DownloadPathJoinHelper-source-quality.md` | Incidental UID false positive. | No target claim; `0000M6` there identifies `by-meta/client_string_handling.md`, not the ObjectStatusBlob file UID context. | None for UID000179. |
| `executed-b-agent-research/B011/0000L5-MapTileImageLib-empty-emitter-family-source-quality.md` | Incidental predecessor/boundary support. | Current and not superseded for the boundary; it does not audit parser bodies. | Confirms fourteen `0xcc` bytes before `0x004d1f30` and that UID000177 ends before a different ObjectStatusBlob owner. |
| `executed-b-agent-research/B013/00002P-ClientItemMenuDialog-class-source-quality.md` | Incidental menu consumer and owner-exclusion evidence. | Compatible with the current tagged member name; no target layout authority claimed. | ClientItemMenuDialog parses an object-status blob at payload `+6`, advances by the result, and treats ObjectStatusBlob as a dependency rather than dialog-owned code. |
| `executed-b-agent-research/B013/0000NT-SoftwareBlend16-empty-emitter-family-source-quality.md` | Incidental numeric false positive. | No target claim; matches are validator command ids in the `000000001790`-`000000001799` range. | None for UID000179. |
| `executed-b-agent-research/B014/0001OF-equipment-slot-keys-empty-emitter-source-quality.md` | Incidental generated-path false positive. | No semantic parser claim; the only match is a historical validator `PermissionError` while replacing generated `NexusTK/map/ObjectStatusBlob.cpp`. | Confirms only the generated source route string, not ownership, layout, or parser behavior. |
| `executed-b-agent-research/B015/000177-MapTileImageLibLocalMethodCluster-source-quality.md` | Incidental but strong predecessor/boundary support. | Current and not superseded for the boundary; it explicitly stops short of parser analysis. | Confirms the hard `0x004d1f30` owner boundary, fourteen-byte predecessor padding, many calls into the new parser family, and rejects merging UID000177 with UID000179. |
| `tools/leaser/Agents/Agent-B005/research/000179-ObjectStatusBlobParsers-source-quality.md` | Direct current-artifact self-match, not a prior report. | Current report under repair; excluded from prior-report evidence and direct-report counts. | Contains the only complete three-body/layout/source-quality audit and is the only match for `ParseFullStatus` and `ParsePartialStatus`. |

- Evidence-based prior-report conclusion: no prior direct UID000179 report exists in any searched root. None of the 28 prior matches has `TARGET-REPORT-UID:000179`, a UID000179 assignment/title, or a three-parser-body/layout audit. Exact UID/path/name matches occur only as support, consumer, predecessor boundary, evidence-list, stale API/field assumption, or false-positive command/UID text. The absence of `ParseFullStatus` and `ParsePartialStatus` from every prior artifact, together with the path-by-path classifications above, independently confirms that this report is the first direct standalone audit rather than a duplicate of prior B-agent work.

- Lifecycle/status: the original report-only pass and its prior-report search remain preserved historically. The accepted callback subsequently changed only the exact by-* pages listed below; validator-owned registry/reference/generated/coverage outputs changed only as command side effects. B005 ran no execute_report, lifecycle, move, archive, tracker edit, coverage edit, generated edit, supervisor-state edit, or IDA mutation.

## Target
- Target UID: `000179`.
- Target path: `by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, current `86/90`, report count `0` at assignment selection time.
- Assignment-time supervisor classification: reconstructable empty emitter requiring direct source-quality research, complete layout recovery, exact split disposition, and final-source first draft.
- Assignment baseline: target `86/90`, owner/emitter UID0000M6, reconstructable true, blank formal C++, `Nested:-4`; class UID00009S `86/90` with blank formal C++; file UID0000M6 `86/88` at `NexusTK/map/`. The implemented current state is recorded below.

## Current Target State
- Current metadata: UID000179 is `92/93`, owner UID00009S, reconstructable false, non-emitting, position/formal body blank, range/UID/path preserved, and `Nested:-4`.
- Current split: UID0004LK `0x004d1f30-0x004d1f99` is `92/94`, position 10, `Nested:+4`; UID0004LL `0x004d1fa0-0x004d2637` is `91/93`, position 20, `Nested:0`; UID0004LM `0x004d2640-0x004d2697` is `92/94`, position 30, `Nested:0`. All are reconstructable and owned/emitted by UID00009S. UID00017A is unchanged except `Nested:-4` plus closure note.
- Current class/file: UID00009S is `92/93`, still owned/emitted by UID0000M6, with complete 68-byte Destination 2 and registered children. UID0000M6 is `90/91`, FILE-owned at `NexusTK/map/`, with complete module inventory and no by-file formal block.
- Current source: generated `ObjectStatusBlob.cpp` has the class shell and exactly the three child markers/bodies, no UID000179 marker, and no Empty Emitter Marker. HeadSelect uses the instance call, MessageDialogs uses the instance call/resolved display field, and SelfLookPane uses the exact ObjectStatusBlob member/full/partial surface without placeholder decoders.
- Resolved blockers: complete field/resource/caller/global/source evidence replaces the old title/profile/general-tail model; context aliases qualify `+0x21/+0x22`; canonical `g_useEpfAssets`, `g_pNewHumanImageLib`, MetaMan, PacketBuffer, Part.tbl, HAIRCOL, and RidableAnimals roles are synchronized across support pages.
- Stale assumptions corrected: `+0x2a` is a riding appearance key and `+0x2c/+0x2e/+0x30` are `RidableAnimals` metadata outputs, not title fields. `dword_67A760` is `g_pNewHumanImageLib`, not a generic appearance-remap table. `byte_66DA97` is the accepted `g_useEpfAssets` mode selector. `+0x22` is consumed by the NewHuman renderer as a composition/render mode, not safely a universal posture field.
- Related target/support docs checked: UID00009S and UID0000M6; MapPane file/class and UID0003TX/UID0003TT/UID0002QN object packet paths; UID0001BU ObjectImageControlPane; UID0001FI HeadSelectDialog; UID0001FF MessageDialog response; UID0002RB SelfLookPane raw helpers and class UID0000CU; UID00039M SelfLookPane2 update helpers; UID0003RK UserLookPane parser; MetaMan class/file/global; PacketBuffer UID0003YK; NewHumanImageLib class/layout/file, composition/bounds consumers, and `Part.tbl`/`HAIRCOL.TBL` resource evidence.
- Current artifact/lifecycle status: the supervisor accepted exact pre-callback SHA `2623085B6785CC349D0F711C0A97CB786047AEF34B8DB31BE3901F4603C90FFA`; B005 responsibilities for the authorized callback are complete. External report execution/lifecycle state remains supervisor-owned and is not asserted here.

## Executive Recommendation
- Direct owner: class UID00009S `ObjectStatusBlob` is the narrowest semantic owner of all three thiscall parser methods. File UID0000M6 remains the generated source root at `NexusTK/map/ObjectStatusBlob.cpp`.
- Split disposition: retain UID000179 as a non-emitting index and create exact children `0x004d1f30-0x004d1f99`, `0x004d1fa0-0x004d2637`, and `0x004d2640-0x004d2697`. Internal `0xcc` gaps remain outside child bodies but inside the aggregate's documented span.
- Layout disposition: replace class UID00009S's blank formal block with a naturally aligned 68-byte class declaration, explicit parser methods, status-kind aliases required by existing MapPane/ObjectImage source, field aliases required by HeadSelect compact mode, all equipment/color/riding fields, and an old-toolchain size assertion.
- Source disposition: the three child methods emit through UID00009S; UID00009S emits through UID0000M6. Do not move the helper to MapPane, NewHumanImageLib, PacketBuffer, MetaMan, a UI dialog, or a new protocol-only source root.
- Support disposition: correct three existing emitted call surfaces to the member API: HeadSelectDialog, MessageDialogs, and SelfLookPane. Add `ObjectStatusBlob m_selfLookObjectStatus` to the existing SelfLookPane declaration. Synchronize remaining consumers in prose without changing their formal blocks or scores.
- Acceptance history: supervisor Gate 1 accepted all nine literal managed destinations and C01-C33. The serial registration plan issued UIDs 0004LK/0004LL/0004LM before references and was then implemented exactly.

## Supervisor Active Recheck
- Supervisor Gate 1 accepted the exact report SHA named above and authorized the same-report callback. Main parser evidence was gathered during session `c81909be`; the interrupted SelfLook support pass was completed after fresh discovery and health checks during restored session `29ca807d`. Those remain evidence-time facts, not claims that either session is currently live.
- The required split is implemented: three normal functions have exact registered children, explicit alignment remains outside bodies, and the aggregate no longer emits.
- Every source-bearing function has its exact range, method signature, literal formal body, owner/emitter route, score, summary, and cumulative nesting delta. Bounded raw successors remain explicitly excluded rather than deferred into this split.
- The original report-only pass used no by-* edits/leases/validators. The accepted callback used only short one-file leases, scoped file validators, serial UID-only registrations, and one authorized waited autogen refresh. No execute_report, lifecycle, move, archive, manual generated/coverage/tracker/supervisor edit, or IDA mutation occurred.

## Inference Research Guidance Check
- `by-structure.md` requires exact memory children for independently source-bearing bodies and prohibits aggregate pages from carrying child code. That rule drives the non-emitting parent plus three-child design and the `[[CHILDREN]]` placement after the class declaration.
- Existing documentation assumptions were treated as provisional. In particular, title metadata, generic appearance remap, direction/posture, profile bytes, aggregate emission, and raw byte-reader naming were all rechecked and corrected where binary consumers contradicted them.
- IDA facts are exact ranges, instructions, byte writes, constants, calls, xrefs, and global addresses. Documentation evidence supplies accepted canonical names and source routes. Inference supplies human member spellings, union aliases, and the original module shape. Each inference is identified as descriptive where no source symbols survive.
- Address order and `Nested` are relative cumulative indentation deltas, not child counts. The implemented plan follows validator sort order `(start ascending, end descending, path)` and preserves the surrounding hierarchy before and after the new children.
- Historical Wave2/Wave3 names were encountered only in `-report.old.md`. They were ignored as stale authority and retained nowhere as proof.

## Heuristic / Inference Reanalysis And Validation
- Generated method names: IDA still exposes `sub_4D1F30`, `sub_4D1FA0`, and `sub_4D2640`. Existing docs, thiscall data flow, recursive call relation, and all consumers support `ObjectStatusBlob::ParseTaggedStatus`, `ParseFullStatus`, and `ParsePartialStatus`. These are strong descriptive source names, not recovered symbols.
- Signature/return types: all three receive `this` plus one packet pointer and return consumed byte counts as `int`. No body mutates the input. Best source signatures are `int Method(const unsigned char *packet)`. Tagged returns `ParseFullStatus(packet+1)+1`, `4`, or `0`; full returns `43`; partial returns `5`.
- Status kind: `+0x00` is a 32-bit enum because all stores are dword stores and consumers compare integer values 0/1/2. Aliases `HumanObject`/`FullLivingObject`, `MonsterObject`/`CompactLivingObject`, and `ItemObject` preserve all accepted consumer spellings without changing values.
- Compact aliases: `+0x04` and `+0x06` carry generic appearance/variant data for compact monster/item modes, but HeadSelect mode 2 uses the same fields as `headIndex` and `headDrawOffset`, while full-human mode uses them as face/hair selectors. Anonymous unions are the least lossy source-facing representation.
- Human part IDs: direct `Part.tbl` parsing and `BuildCompositionDrawCommands` tag dispatch resolve `+0x08` Body, `+0x0a` weapon family, `+0x0c` Shield/Arrow, `+0x0e` Helmet, `+0x10/+0x14` two FaceDec slots, `+0x12` HairDec, `+0x16` Mantle, `+0x18` Neck, `+0x1a` Shoes, `+0x1c` Coat, and `+0x1e` All/full-body. These are strong source-facing inferences grounded in table row names and exact consumers.
- Headgear/render bytes: `+0x20` controls parser normalization: value 0 hides Helmet, values 1/2 hide Hair. `m_headgearMode` is descriptive. `+0x21` is a gender boolean in full-human normalization and a direction byte in compact object paths, so a union preserves both proven interpretations. `+0x22` is copied and consumed by NewHuman composition as a render/composition mode, while compact users may treat it as posture/state; `m_compositionMode` is primary and `m_posture` remains an alias.
- Action state: `+0x24` is a 32-bit state initialized to 11 by full/partial parsers and normalized by map/local-player consumers. `m_actionState` is the best descriptive name; exact original spelling remains inferred but type/offset/default are exact.
- Display/default byte: `+0x28` is copied from full packet byte 4 and seeded to `0x50` by partial/ObjectImage callers. `m_displayStatusByte` with `defaultByte` alias preserves current source. Its exact narrow protocol label is not proven, so no stronger lantern/body-style claim is made.
- Riding metadata: `+0x2a` is a 16-bit riding appearance id. Nonzero values are forced to 1 in legacy asset mode, formatted with UTF-16 `%d`, and looked up in exact table `RidableAnimals`; columns 1, 2, and 3 are converted with `_wtol` into words `+0x2c`, `+0x2e`, and `+0x30`. NewHuman composition uses them as riding definition index, packed palette/render flags, and signed Y offset. The former title interpretation is rejected.
- Colors and tail: exact Part-tag consumers resolve `+0x32` face color, `+0x33` hair color, `+0x34` shared skin/tint, `+0x35` body color, `+0x36` weapon color, `+0x37` shield/arrow color, `+0x38` helmet color, `+0x39` first face-decoration color, `+0x3a` hair-decoration color, `+0x3b` second face-decoration color, `+0x3c` mantle color, `+0x3d` neck color, and `+0x3e` shoes color. Comparative protocol source and payload tail order support `+0x3f` invisibility byte and `+0x40` face shape. Bytes `+0x41..+0x43` are natural trailing padding and are never written/read by these parsers or checked consumers.
- Face normalization: the full parser reads face/appearance word at payload `+5`; non-`0xffff` values satisfying the binary's exact `<=199 || 900..999 || >399` condition move their low byte into Hair/variant `+0x06` and force face id `+0x04` to 200. The redundant middle interval is preserved in draft source because it is present in the lowered predicate.
- Hair-color remap: `g_pNewHumanImageLib+0x54/+0x58` is the `HAIRCOL.TBL` vector begin/end. When the hair index is in range, the low five hair-color bits are offset by the table entry modulo 32 while upper three bits are preserved. `dword_67A760` is therefore not a standalone remap global.
- Body/coat sentinel: payload word `+11` selects Body when `<=9999`, otherwise Coat as modulo 10000; the unused counterpart becomes `0xffff`. Zero Body becomes gender boolean. `m_fullBodyId` is always initialized to `0xffff` later. Shoes are invalidated for most Body values when no Coat exists, or default to gender boolean when Coat exists and Shoes is `0xffff`.
- Parser reader identity: `0x00575480` is `PacketBufferReadUInt16BE`; `0x00575470` is the compiler/runtime narrow-character trait byte conversion, not a source-level packet reader. Draft code uses direct byte indexing plus the accepted 16-bit helper.
- String/metadata identity: `0x0041b9b0` is secure wide formatting, `0x00421590`/`0x00421310` are SimpleUString assign/clear lowering, `0x00523120` is `MetaMan::FindEntry`, and `0x005cea43` is CRT `_wtol`. Source draft uses normal RAII string objects instead of manually reproducing lowered cleanup.
- Source placement: local address adjacency to image libraries is not ownership. Broad parser callers and an already coherent ObjectStatusBlob class/file route support `NexusTK/map/ObjectStatusBlob.cpp`; dependencies remain in PacketBuffer, MetaMan, and NewHumanImageLib.
- Split/range: normal function metadata and all-`0xcc` internal gaps require three exact children. The aggregate is an audit/index, not a fourth source object. Raw three-byte setters at `0x004d26a0` and `0x004d26e0` have no modeled functions/xrefs and lie outside the assigned exclusive endpoint; they are rejected from this split.
- Existing emitted caller defects: HeadSelect uses a nonexistent static two-argument method call, MessageDialog uses a free parser call plus `fields[40]`, and SelfLook uses placeholder decode functions and a placeholder status type. Destinations 6-9 make these member calls and fields consistent with the complete class surface.
- Rejected alternatives: title metadata, generic profile tail, direct MapPane ownership, NewHumanImageLib ownership, PacketBuffer ownership, MetaMan ownership, one UI-dialog owner, three free functions, static parser overload wrappers, raw `fields[68]`, packed class layout, absorbing raw successors, keeping the aggregate emitting, and leaving blank formal C++ are all weaker or behaviorally/source structurally wrong.
- Remaining uncertainty: exact original spellings of `m_headgearMode`, `m_actionState`, `m_displayStatusByte`, and some color members are not symbol-proven. Their offsets/types/uses are resolved, descriptive names are coherent, union aliases preserve required current callers, and this uncertainty caps scores below 95 without blocking source reconstruction.

### Complete 68-byte layout

| Offset | Size | Recommended source member/type | Exact parser/consumer disposition |
| --- | --- | --- | --- |
| `+0x00` | 4 | `StatusKind m_statusKind` | Dword 0/1/2; Human/Monster/Item and Full/Compact aliases. |
| `+0x04` | 2 | union `m_appearanceId` / `m_faceId` / `headIndex` | Compact appearance, full face selector, HeadSelect head index. |
| `+0x06` | 1 | union `m_variantOrPalette` / `m_hairId` / `headDrawOffset` | Compact variant, full hair selector, HeadSelect vertical offset. |
| `+0x07` | 1 | explicit padding | Required to align `+0x08`; not written by parsers. |
| `+0x08` | 2 | `m_bodyId` | Body Part row 0; Body/Coat split and sentinel normalization. |
| `+0x0a` | 2 | `m_weaponId` | Sword/Spear/Bow/Fan and Back classification source. |
| `+0x0c` | 2 | `m_shieldOrArrowId` | Shield/Arrow selector. |
| `+0x0e` | 1 | `m_helmetId` | Helmet selector; becomes `0xff` when headgear mode is 0. |
| `+0x0f` | 1 | explicit padding | Aligns next word; not written by parsers. |
| `+0x10` | 2 | `m_faceDecorationId` | First FaceDec slot. |
| `+0x12` | 2 | `m_hairDecorationId` | HairDec slot. |
| `+0x14` | 2 | `m_secondFaceDecorationId` | Second FaceDec slot. |
| `+0x16` | 2 | `m_mantleId` | Mantle slot. |
| `+0x18` | 2 | `m_neckId` | Neck slot. |
| `+0x1a` | 2 | `m_shoesId` | Shoes slot with body/coat sentinel normalization. |
| `+0x1c` | 2 | `m_coatId` | Coat Part row 1 or `0xffff`. |
| `+0x1e` | 2 | `m_fullBodyId` | All/full-body Part row 17; full parser initializes `0xffff`. |
| `+0x20` | 1 | `m_headgearMode` | 0 hides Helmet; 1/2 hide Hair. |
| `+0x21` | 1 | union `m_gender` / `m_direction` | Full-human boolean tests; compact direction interpretation. |
| `+0x22` | 1 | union `m_compositionMode` / `m_posture` | NewHuman render mode; compact posture/state interpretation. |
| `+0x23` | 1 | explicit padding | Aligns dword state; not written by parsers. |
| `+0x24` | 4 | `unsigned int m_actionState` | Full/partial initialize 11; map/local-player state consumer. |
| `+0x28` | 1 | union `m_displayStatusByte` / `defaultByte` | Full payload byte 4; partial/ObjectImage seed `0x50`. |
| `+0x29` | 1 | explicit padding | Aligns riding word. |
| `+0x2a` | 2 | `m_ridingAppearanceId` | Packet riding key, forced to 1 in legacy asset mode. |
| `+0x2c` | 2 | `m_ridingDefinitionIndex` | `RidableAnimals` column 1 and NewHuman riding definition. |
| `+0x2e` | 2 | `m_ridingPaletteFlags` | Column 2 and NewHuman packed palette/render flags. |
| `+0x30` | 2 | `short m_ridingYOffset` | Column 3 and signed riding vertical offset. |
| `+0x32` | 1 | `m_faceColor` | Face/Emotion palette. |
| `+0x33` | 1 | `m_hairColor` | Hair palette, low five bits HAIRCOL-remapped. |
| `+0x34` | 1 | `m_skinColor` | Shared skin/tint consumed by selected Part tags. |
| `+0x35` | 1 | `m_bodyColor` | Body/Coat palette. |
| `+0x36` | 1 | `m_weaponColor` | Sword/Spear/Bow/Fan palette. |
| `+0x37` | 1 | `m_shieldOrArrowColor` | Shield/Arrow palette. |
| `+0x38` | 1 | `m_helmetColor` | Helmet palette. |
| `+0x39` | 1 | `m_faceDecorationColor` | First FaceDec palette. |
| `+0x3a` | 1 | `m_hairDecorationColor` | HairDec palette. |
| `+0x3b` | 1 | `m_secondFaceDecorationColor` | Second FaceDec palette. |
| `+0x3c` | 1 | `m_mantleColor` | Mantle palette. |
| `+0x3d` | 1 | `m_neckColor` | Neck palette. |
| `+0x3e` | 1 | `m_shoesColor` | Shoes palette. |
| `+0x3f` | 1 | `m_invisible` | Raw invisibility/status byte; kept byte-sized to avoid bool normalization. |
| `+0x40` | 1 | `m_faceShape` | Final parsed appearance byte. |
| `+0x41..+0x43` | 3 | `m_trailingPadding[3]` | Required for exact 68-byte size; no checked parser/consumer field access. |

### Exact parser payload maps

| Full payload bytes | ObjectStatusBlob destination | Transformation |
| --- | --- | --- |
| `0`, `1` | `+0x21`, `+0x22` | direct bytes; gender/direction and composition/posture aliases |
| `2..3` | `+0x2a` | BE16 riding appearance id, optional legacy force/metadata lookup |
| `4` | `+0x28` | direct display/default byte |
| `5..6`, `7` | `+0x04`, `+0x06` | BE16 face/appearance plus hair/variant; special face normalization |
| `8`, `9`, `10` | `+0x33`, `+0x32`, `+0x34` | hair, face, and skin/shared tint colors; hair remap follows |
| `11..12` | `+0x08` or `+0x1c` | BE16 Body/Coat split at 9999 with `0xffff` counterpart |
| `13` | `+0x35` | body/coat color |
| `14..15`, `16` | `+0x0a`, `+0x36` | weapon id/color |
| `17..18`, `19` | `+0x0c`, `+0x37` | shield/arrow id/color |
| `20`, `21`, `22` | `+0x20`, `+0x0e`, `+0x38` | headgear mode, helmet id, helmet color |
| `23..24`, `25` | `+0x10`, `+0x39` | first FaceDec id/color |
| `26..27`, `28` | `+0x12`, `+0x3a` | HairDec id/color |
| `29..30`, `31` | `+0x14`, `+0x3b` | second FaceDec id/color |
| `32..33`, `34` | `+0x16`, `+0x3c` | Mantle id/color |
| `35..36`, `37` | `+0x18`, `+0x3d` | Neck id/color |
| `38..39`, `40` | `+0x1a`, `+0x3e` | Shoes id/color |
| `41`, `42` | `+0x3f`, `+0x40` | invisibility/status and face shape |

- Tagged compact map: tag byte 0 delegates full payload at `packet+1` and returns 44 total; tags 1/2 write kind, BE16 bytes 1-2 to `+0x04`, byte 3 to `+0x06`, and return 4; other tags return 0 without writes.
- Partial map: dword kind 1, dword action state 11, display byte `0x50`, packet bytes 0/1 to `+0x21/+0x22`, BE16 bytes 2-3 to `+0x04`, byte 4 to `+0x06`, return 5.

### Part.tbl consumer map

| Row | Exact Part.tbl name/range | ObjectStatusBlob selector/color |
| --- | --- | --- |
| 0 | `Body`, `0..19999` | `m_bodyId`, `m_bodyColor` |
| 1 | `Coat`, `20000..39999` | normalized `m_coatId`, `m_bodyColor` |
| 2 | `Face`, `200..999` | `m_faceId`, `m_faceColor` |
| 3 | `Emotion`, `1` | face/emotion selector family at `m_faceId`, `m_faceColor` |
| 4 | `FaceDec`, `0..9999` | first/second FaceDec ids and corresponding colors |
| 5 | `Hair`, `1` | `m_hairId`, `m_hairColor` |
| 6 | `Helmet`, `1` | `m_helmetId`, `m_helmetColor` |
| 7 | `HairDec`, `10000..19999` | `m_hairDecorationId`, `m_hairDecorationColor` |
| 8 | `Sword`, `0..9999` | `m_weaponId`, `m_weaponColor` |
| 9 | `Spear`, `10000..19999` | normalized weapon id, `m_weaponColor` |
| 10 | `Bow`, `20000..29999` | normalized weapon id, `m_weaponColor` |
| 11 | `Fan`, `30000..39999` | normalized weapon id, `m_weaponColor` |
| 12 | `Shield`, `0..9999` | `m_shieldOrArrowId`, `m_shieldOrArrowColor` |
| 13 | `Arrow`, `10000..19999` | normalized shield/arrow id, same color |
| 14 | `Mantle` | `m_mantleId`, `m_mantleColor` |
| 15 | `Shoes` | `m_shoesId`, `m_shoesColor` |
| 16 | `Neck` | `m_neckId`, `m_neckColor` |
| 17 | `All` | `m_fullBodyId`, no separate packet color byte |
| 18 | `Back` | alternate weapon/back classification from `m_weaponId` |

## Evidence Standards Used
- Direct evidence: IDA MCP `idb_list`, `server_health`, `lookup_funcs`, decompilation, function analysis, xrefs/callers/callees, global/string references, and bounded successor checks; raw `Part.tbl` and `HAIRCOL.TBL` resource parsing; generated source inspection; exact by-* metadata/formal blocks.
- Strong corroboration: NewHuman composition/bounds consumers, ObjectImageControlPane's exact 68-byte copy and kind dispatch, MapPane object creation/update paths, HeadSelect aliases, SelfLook/SelfLook2/UserLook callers, and metadata/packet helper docs.
- Lower-tier corroboration: Hybrasyl `DisplayUser.cs` vocabulary for equipment/colors/invisible/face fields. It is not used for exact ordering, offsets, parser lengths, ownership, or score by itself.
- Negative evidence: no vtable/RTTI/constructor/destructor in this range, no separate title global, no standalone remap table at `0x0067a760`, no functions/xrefs at bounded raw successors, no fourth parser body, no UI-only ownership, and no evidence that internal alignment is source data.
- Evidence ladder: binary behavior and raw project resources control exact behavior; accepted canonical docs control cross-module names; consumer agreement supports descriptive member names; comparative external source is only vocabulary corroboration. Tool limitations affect original spelling confidence, not the recovered layout or behavior.

## Evidence Checked
- IDA MCP/manual checks: fresh `idb_list`; healthy `server_health`; exact function lookups at `0x004d1f30`, `0x004d1fa0`, `0x004d2640`, negative function lookup at `0x004d26a0`, successor lookup at `0x004d2720`; decompilation of all three parsers and bounded NewHuman consumers including `0x004e06a0`, `0x004e09e0`, and `0x004e21d0`; caller/xref/callee/global/string checks; raw internal/successor bytes from the main MCP evidence pass. After recovery, fresh lookup reconfirmed all three parser starts/sizes, no function objects at raw starts `0x0056a500`/`0x0056a5c0`, modeled handler `0x005693d0`, and successor `0x0056a640`; bounded raw reads covered `0x0056a500` for 192 bytes and `0x0056a5c0` for 128 bytes; xrefs reconfirmed zero raw-start references and the 12/11 full/partial caller sets; decompilation of `0x005693d0` reconfirmed both inline mirror cases and `SelfLookPane+0x108` storage.
- Documentation checked: assigned target, ObjectStatusBlob class/file, current generated `ObjectStatusBlob.cpp`, MapPane object handlers/create-update source, ObjectImage control, HeadSelect, MessageDialog, SelfLook/SelfLook2, UserLook/Profile, NewHuman class/layout/composition/bounds docs, MetaMan, `g_pMetaMan`, `g_pNewHumanImageLib`, `g_useEpfAssets`, PacketBuffer scalar readers, ignored padding, auto coverage/tracker rows, and historical old report rows for search provenance only.
- Prior-report search checked: the exact 16-term, three-root search record and every one of its 29 opened matches are recorded under `Supporting Research`. The 28 prior artifacts are all incidental/support/boundary/stale-assumption/false-positive matches; none is a direct UID000179 target report.
- Resource checks: current `char.dat` `Part.tbl` records resolved 19 tags and source names; `HAIRCOL.TBL` constructor/destructor/layout evidence resolves the vector at NewHumanImageLib `+0x54/+0x58`.
- Comparative check: official public Hybrasyl server source `hybrasyl/Networking/ServerPackets/DisplayUser.cs`; accepted only for concept vocabulary, rejected as exact client/version packet proof.
- Negative checks: raw successor entries, predecessor ownership/padding, following HumanImageLib boundary, title interpretation, generic remap global, free/static parser API, packed layout, fourth method, and consumer-owned source placement.
- Failed/unavailable/skipped evidence history: session `c81909be` disappeared during the final report-only support recheck, and the attempted raw-start `lookup_funcs(0x0056a500,0x0056a560,0x0056a5c0,0x0056a600)` and `decompile(0x0056a500)` calls returned `Session not found`; work stopped at that point. The supervisor restored MCP, fresh discovery selected session `29ca807d`, and the interrupted evidence was repeated with function lookups, bounded raw bytes, xrefs, and modeled-handler decompilation. Expected negative `Not a function` results for `0x0056a500`/`0x0056a5c0` describe raw-body classification rather than MCP failure. IDA mutation/renames/comments remained intentionally skipped. Implementation validators/leases/generated refresh were absent only in that historical report-only phase; the accepted callback command evidence is recorded below.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID000179 is a non-emitting split index, not a fourth source body. | very strong | Three functions, two alignment gaps, source rules | UID000179 metadata/status/formal | incorporate | applied |
| C02 | Exact child 1 is `0x004d1f30-0x004d1f99`. | confirmed | MCP size `0x69` | UID0004LK ParseTagged child | incorporate | applied |
| C03 | Exact child 2 is `0x004d1fa0-0x004d2637`. | confirmed | MCP size `0x697` | UID0004LL ParseFull child | incorporate | applied |
| C04 | Exact child 3 is `0x004d2640-0x004d2697`. | confirmed | MCP size `0x57` | UID0004LM ParsePartial child | incorporate | applied |
| C05 | Gaps `1f99-1fa0` and `2637-2640` are 7/9 `0xcc` bytes. | confirmed | raw-byte checks | Parent and child boundary prose | incorporate | applied |
| C06 | All parser signatures are member `int(const unsigned char *)`. | strong | thiscall lowering, no packet writes, return use | Class and three children | incorporate | applied |
| C07 | Tagged parser behavior/returns are exact. | confirmed | full decompile/call relation | UID0004LK | incorporate | applied |
| C08 | Full parser consumes 43 bytes and all writes/normalizations below are exact. | confirmed | full decompile | UID0004LL/target/class/file | incorporate | applied |
| C09 | Partial parser consumes 5 bytes and writes exact defaults/fields. | confirmed | decompile | UID0004LM | incorporate | applied |
| C10 | ObjectStatusBlob is naturally aligned and exactly 68 bytes. | very strong | offsets, 68-byte copies, size assertion math | Class UID00009S | incorporate | applied |
| C11 | Status enum values/aliases are 0/1/2 dword values. | very strong | stores and Map/ObjectImage consumers | Class UID00009S | incorporate | applied |
| C12 | Compact/full/HeadSelect offset aliases at `+4/+6` are intentional unions. | strong | parser modes and callers | Class/HeadSelect/ObjectImage docs | incorporate | applied |
| C13 | Complete Part.tbl equipment ID map is resolved. | very strong | current resource rows plus 4e21d0 | Target/class/file/NewHuman support | incorporate | applied |
| C14 | Complete color/tail map `+50..+64` is resolved. | strong | parser writes, command consumers, comparative tail | Target/class/file/support | incorporate | applied |
| C15 | `+42..+48` is riding metadata, not title metadata. | very strong | `RidableAnimals`, MetaMan columns, NewHuman use | Target/class/file/MetaMan/NewHuman | incorporate | applied |
| C16 | `dword_67A760` is `g_pNewHumanImageLib`; its hair vector performs remap. | very strong | singleton docs/layout/decompile | Target/class/file/NewHuman/global | incorporate | applied |
| C17 | `byte_66DA97` is `g_useEpfAssets`. | very strong | canonical global plus direct compare | Target/class/file/global | incorporate | applied |
| C18 | Packet bytes use direct indexing; only word reads call UID0003YK. | confirmed | callee/decompile | Three children/PacketBuffer support | incorporate | applied |
| C19 | MetaMan/SimpleUString/formatter/_wtol callee route is resolved. | very strong | callees/string/global docs | Full child/MetaMan support | incorporate | applied |
| C20 | Complete direct caller families are shared map/look/dialog/menu consumers. | confirmed | xrefs and caller decompiles | Target/class/file/support docs | incorporate | applied |
| C21 | Source route stays `NexusTK/map/ObjectStatusBlob.cpp`. | strong | shared role, existing source tree, direct class | Class/file/children | incorporate | applied |
| C22 | New children own/emit through class UID00009S. | very strong | thiscall methods, owner rule | Three child metadata | incorporate | applied |
| C23 | Parent score becomes `92/93`; children `92/94`, `91/93`, `92/94`. | strong | resolved scope and complexity | Parent/children | incorporate | applied |
| C24 | Class score becomes `92/93`; file score becomes `90/91`. | strong | complete layout/API/route | UID00009S/UID0000M6 | incorporate | applied |
| C25 | Cumulative nesting is parent `-4`, children `+4/0/0`, UID00017A `-4`. | confirmed | validator sort/render algorithm and current deltas | Parent/new children/UID00017A | incorporate | applied |
| C26 | Raw setters at `0x004d26a0`/`0x004d26e0` remain outside target/split. | strong | no modeled functions/xrefs, endpoint | Parent boundary/negative evidence | incorporate | applied |
| C27 | Predecessor MapTile range and 14-byte padding remain unchanged. | confirmed | UID000177/UID0002J1/raw docs | Parent boundary | already-present | already-present |
| C28 | HeadSelect must call `m_previewObject.ParseTaggedStatus`. | very strong | actual thiscall and current generated defect | UID0001FI formal/prose | incorporate | applied |
| C29 | MessageDialog must use member call and `m_displayStatusByte`. | very strong | actual thiscall/layout | UID0001FF formal/prose | incorporate | applied |
| C30 | SelfLook placeholder surface is ObjectStatusBlob full/partial parsing into exact member `this+0x108..+0x14b`. | very strong | raw bytes, zero raw-start xrefs, exact calls, modeled mirrors | UID0000CU/UID0002RB | incorporate | applied |
| C31 | SelfLook2/UserLook/MapPane/ObjectImage/Profile support needs the complete field map but no formal change. | strong | direct callers/consumers | Listed support docs | incorporate | applied |
| C32 | MetaMan/PacketBuffer/NewHuman support names remain owned by their existing modules. | very strong | canonical support docs and binary calls | Listed support docs | incorporate | applied |
| C33 | No IDA DB rename/type/comment mutation is required for documentation implementation. | confirmed | callback scope and descriptive names | Report/target IDA recommendations | not-applicable | excluded-with-reason |

Callback verification notes preserve the accepted action detail and completed proof that previously occupied the enum columns:

| Claim ID | Accepted action detail | Callback verification notes |
| --- | --- | --- |
| C01 | Set false, clear emitter, blank block | Implemented; command 000000009620 `ok:1`; generated has no UID000179/empty marker. |
| C02 | Create/register serially | Implemented; UID-only 000000009614 then scoped 000000009615 `ok:1`. |
| C03 | Create/register serially | Implemented second; UID-only 000000009616 then scoped 000000009617 `ok:1`. |
| C04 | Create/register serially | Implemented third; UID-only 000000009618 then scoped 000000009619 `ok:1`. |
| C05 | Preserve/exclude from bodies | Implemented in parent/all children; block equality and ranges verified. |
| C06 | Apply Destinations 2-5 | Implemented byte-for-byte; generated class plus all three member signatures verified. |
| C07 | Apply Destination 3 | Implemented; block equality true; generated marker/body present. |
| C08 | Apply Destination 4 and prose | Implemented; block equality true; full payload/resource/normalization tables preserved. |
| C09 | Apply Destination 5 | Implemented; block equality true; generated body present. |
| C10 | Apply Destination 2 | Implemented; command 000000009621 `ok:1`; generated size-checked declaration present. |
| C11 | Apply aliases | Implemented in Destination 2 and synchronized Map/ObjectImage prose. |
| C12 | Apply/preserve aliases | Implemented; generated HeadSelect member call and class unions verified. |
| C13 | Incorporate full map | Implemented in parent/class/file/full child/NewHuman composition and support pages. |
| C14 | Incorporate full map | Implemented with exact decimal/hex mapping across target and consumers. |
| C15 | Correct stale prose | Implemented; residual current MapPane shorthand repaired and revalidated by 000000009667. |
| C16 | Correct stale global role | Implemented across target/NewHuman/global pages; old generic role labeled superseded. |
| C17 | Normalize alias | Implemented; UID0000SW records exact legacy riding-id force. |
| C18 | Use canonical helper | Implemented in bodies and scalar/by-item/file support; `0x00575470` rejected as packet API. |
| C19 | Use source APIs | Implemented in Destination 4 and MetaMan class/file/global prose. |
| C20 | Incorporate inventory | Implemented in parent/children and all accepted consumer families. |
| C21 | Preserve path and route | Implemented; UID0000M6 remains FILE at `NexusTK/map/`; generated path verified. |
| C22 | Set owner/emitter 00009S | Implemented; scoped validator metadata and generated child markers verified. |
| C23 | Apply scores | Implemented; commands 000000009615/000000009617/000000009619/000000009620 all `ok:1`. |
| C24 | Apply scores | Implemented; commands 000000009621/000000009622 `ok:1`. |
| C25 | Apply exact deltas | Implemented; metadata reread verified; UID00017A command 000000009623 `ok:1`. |
| C26 | Preserve exclusion | Implemented in parent/children/class/file negative evidence; no child/reference created. |
| C27 | Preserve | Verified unchanged; parent/children retain exact predecessor padding evidence. |
| C28 | Apply Destination 6 | Implemented; 000000009624 `ok:1`; generated member call count 1, stale static count 0. |
| C29 | Apply Destination 7 | Implemented; 000000009625 `ok:1`; generated field/member counts 1/1, stale counts 0/0. |
| C30 | Apply Destinations 8-9 | Implemented; 000000009626/000000009627 `ok:1`; generated member/local/full/partial present and placeholder decoder/type absent. |
| C31 | Prose sync, scores unchanged | Implemented; commands `000000009628`, `000000009630`, `000000009631`, `000000009632`, `000000009634`, `000000009635`, `000000009637`, `000000009638`, `000000009640`, `000000009641`, `000000009642`, `000000009644`, `000000009645`, `000000009647`, and corrective `000000009667` all `ok:1`. |
| C32 | Prose cross-link only | Implemented; commands `000000009649`, `000000009650`, `000000009651`, `000000009653`, `000000009654`, `000000009656`, `000000009657`, `000000009658`, `000000009660`, `000000009661`, `000000009662`, `000000009663`, and `000000009664` all `ok:1`; formal blocks/scores/routes preserved. |
| C33 | Do not mutate | Verified: no IDA mutation or MCP management call occurred during callback. |

## Positive Evidence Summary
- Three modeled thiscall functions exactly fill the source bodies in the aggregate; each returns a consumed byte count and shares one 68-byte receiver layout.
- Full decompilation exposes every packet read, object write, sentinel, lookup, normalization, and return. Partial/tagged bodies are small and fully resolved.
- NewHuman composition is a high-quality independent consumer: it names all 19 Part rows, maps every equipment ID/color offset, consumes riding definition/palette/Y fields, and gives `+0x22` a render-mode role.
- ObjectImageControlPane independently copies exactly `0x44` bytes and dispatches kind 0/1/2; HeadSelect independently confirms compact head aliases; MapPane independently confirms living/item kind aliases.
- `RidableAnimals`, `%d`, MetaMan `FindEntry`, `_wtol`, `g_useEpfAssets`, and NewHuman hair-vector references form a coherent exact callee/global chain.
- Exact pre-callback generated output proved the practical blocker during the report-only phase: ObjectStatusBlob source was empty while support source already assumed a class/member surface.
- The split, ownership, source route, complete layout, and draft bodies all converge without raw labels, offset indexing, decompiler temporaries, or modern-only source constructs.

## IDA MCP Facts
- Function facts: `lookup_funcs` during the main `c81909be` evidence pass returned `sub_4D1F30` size `0x69`, `sub_4D1FA0` size `0x697`, and `sub_4D2640` size `0x57`; `0x004d26a0` is not a function; `0x004d2720` is the next modeled HumanImageLib function. Fresh restored-session lookup in `29ca807d` independently reconfirmed the same three target function starts and sizes.
- Tagged facts: switch on `packet[0]`; case 0 invokes the full parser on `packet+1`; cases 1/2 dword-store kind, read BE16 at `packet+1`, read byte 3, return 4; default returns 0.
- Full facts: dword kind 0, dword state 11, bytes 0/1 to object `+33/+34`, BE16 byte 2 to `+42`, byte 4 to `+40`; optional riding metadata; all remaining exact writes through `+64`; return 43.
- Partial facts: dword kind 1, dword state 11, byte `+40=0x50`, packet bytes 0/1 to `+33/+34`, BE16 byte 2 to `+4`, byte 4 to `+6`; return 5.
- Padding facts: seven `0xcc` bytes at `0x004d1f99-0x004d1fa0`, nine at `0x004d2637-0x004d2640`, and existing predecessor padding `0x004d1f22-0x004d1f30` remains 14 `0xcc` bytes.
- Callee facts: direct byte conversion lowers through `0x00575470`; BE16 reads use `0x00575480`; full adds `0x0041b9b0`, `0x00421590`, `0x00421310`, `0x00523120`, and `0x005cea43`.
- String/global facts: exact UTF-16 `%d` at `0x00610660`; exact `RidableAnimals` 14-character string at `0x0061c2c4`; `g_useEpfAssets` at `0x0066da97`; `g_pNewHumanImageLib` at `0x0067a760`; `g_pMetaMan` at `0x0069b410`.
- Consumer facts: `0x004e21d0` copies four 16-byte chunks of the status input, consumes byte `+34`, equipment words/bytes, colors `+50..+62`, shared tint `+52`, riding metadata `+44/+46/+48`, and builds Part-tag commands. `0x004e06a0` reads byte `+34` as render/composition mode.
- Negative IDA facts: no vtable/RTTI or lifecycle body belongs to this range; no modeled function at either bounded raw successor; no data xref establishes a title object/global; no fourth parser; no evidence that the aggregate itself was a source declaration separate from the class and methods.
- Recovered SelfLook support facts: `0x0056a500` and `0x0056a5c0` are raw bodies with no modeled functions and zero start xrefs. Their bytes call full parser `0x004d1fa0` at `0x0056a55d`/`0x0056a600` and partial parser `0x004d2640` at `0x0056a56f`/`0x0056a627`, write or copy exactly `0x44` bytes at `SelfLookPane+0x108..+0x14b`, and invalidate inherited bounds at `+0x44`. Modeled packet handler `0x005693d0` independently mirrors both shapes in cases `0x33` and `0x1d`, including the selected-object key check, exact parser choice, destination, and redraw.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004d1f30-0x004d2697` | UID000179 existing | split/index over three parser methods and two alignment gaps | false | class UID00009S as semantic container; no emitter | `92/93` | keep path/UID, non-emitting |
| `0x004d1f30-0x004d1f99` | new `by-memory/0x004d1f30-0x004d1f99.ObjectStatusBlobParseTaggedStatus.md` | `ObjectStatusBlob::ParseTaggedStatus` | true | owner/emitter UID00009S | `92/94` | create/register first |
| `0x004d1f99-0x004d1fa0` | existing ignored-padding mechanism | seven-byte alignment | false | none | unchanged | do not create source body |
| `0x004d1fa0-0x004d2637` | new `by-memory/0x004d1fa0-0x004d2637.ObjectStatusBlobParseFullStatus.md` | `ObjectStatusBlob::ParseFullStatus` | true | owner/emitter UID00009S | `91/93` | create/register second |
| `0x004d2637-0x004d2640` | existing ignored-padding mechanism | nine-byte alignment | false | none | unchanged | do not create source body |
| `0x004d2640-0x004d2697` | new `by-memory/0x004d2640-0x004d2697.ObjectStatusBlobParsePartialStatus.md` | `ObjectStatusBlob::ParsePartialStatus` | true | owner/emitter UID00009S | `92/94` | create/register third |
| `0x004d26a0`, `0x004d26e0` | no new page in this assignment | raw three-byte setters outside endpoint | unresolved/non-target | none | unchanged | exclude, bounded negative evidence only |
| class declaration | UID00009S `by-class/ObjectStatusBlob.md` | exact class/API/layout and child insertion point | true | owner/emitter UID0000M6 | `92/93` | replace blank formal block |
| source root | UID0000M6 `by-file/ObjectStatusBlob.md` | source module | n/a by-file | FILE | `90/91` | preserve `NexusTK/map/` |
| following row | UID00017A HumanImageLib aggregate | following address-order item | false | unchanged | `85/90` unchanged | `Nested:0 -> -4` only |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004d1f8d` | Tagged -> Full | mode 0 delegation proves same class/member family |
| `0x00517dfd`; `0x0051802e`, `0x005185b5`; `0x005199de`, `0x00519e81` | Merchant/text menu/dialog tagged calls | shared variable-length object descriptor parsing |
| `0x0051a5ea`; `0x0051b95c`, `0x0051be8f`; `0x0051cb17`, `0x0051d05e`; `0x0051dc1c`, `0x0051e0c2`; `0x0051ea6a` | item/spell/menu tagged calls | broad dialog/menu consumption, not ownership |
| `0x0054cb6d`; `0x0054cedd`, `0x0054d505`; `0x0054dc5d`, `0x0054e288`; `0x0054e9f9`, `0x0054f16b`; `0x0054fc09`, `0x0055037e`; `0x0055166b`, `0x00551b7e`; `0x005521e3`, `0x0055297f`; `0x005536d2` | message/head/Nexonclub tagged calls | UI consumers establish compact aliases and variable cursor use |
| `0x0050fba3`, `0x00513354` | MapPane full calls | full object-status packet handlers |
| `0x0050fbbc`, `0x0051336d` | MapPane partial calls | reduced object-status packet handlers |
| `0x0056949b`, `0x00569540`, raw sites `0x0056a55d`, `0x0056a600` | SelfLook full calls | full appearance update into local/copied blob |
| `0x005694b1`, `0x0056956b`, raw sites `0x0056a56f`, `0x0056a627` | SelfLook partial calls | compact appearance update |
| `0x005721e7`, `0x00572294`, raw sites `0x00572bbd`, `0x00572c60` | SelfLookPane2 full calls | second look-pane full update family |
| `0x005721f9`, `0x005722b4`, raw sites `0x00572bcf`, `0x00572c87` | SelfLookPane2 partial calls | second look-pane compact update family |
| `0x0059f8dc`, `0x0059f901` | UserLookPane full/partial calls | public look/profile display consumer |
| `0x00575480` | PacketBufferReadUInt16BE | exact big-endian 16-bit decoder used for every word |
| `0x00575470` | narrow-char trait conversion | compiler/runtime lowering for direct byte loads, not source API |
| `0x00523120` | MetaMan::FindEntry | resolves RidableAnimals columns 1-3 |
| `0x0041b9b0`, `0x00421590`, `0x00421310`, `0x005cea43` | swprintf_s, SimpleUString assign/clear, `_wtol` | source-level riding key and integer conversion chain |

## Documentation Evidence And IDA Status
- Supporting docs correctly establish a shared 68-byte ObjectStatusBlob, source root UID0000M6, class UID00009S, ObjectImage kind aliases, MapPane living/item aliases, HeadSelect compact head aliases, accepted MetaMan/global names, and PacketBuffer read helper names.
- Stale/incomplete docs are UID000179/UID00009S/UID0000M6 title/profile/remap wording; MapPane inherited field summaries copied from that old model; NewHuman docs that refer to `+4` only as body; MessageDialog's raw `fields[40]` and free parser call; HeadSelect's static call; SelfLook's placeholder `SelfLookRectState` and decoder calls.
- Report-only baseline generated `NexusTK/map/ObjectStatusBlob.cpp` contained two Empty Emitter Markers; HeadSelectDialog/MessageDialogs exposed static/free call inconsistencies and SelfLookPane exposed placeholder decoders. That historical baseline motivated Destinations 2-9.
- Callback generated state after final waited command 000000009679: ObjectStatusBlob class and UID0004LK/UID0004LL/UID0004LM bodies are present, UID000179 and Empty Emitter Markers are absent, and all three caller surfaces are corrected. Auto-generated coverage/tracker/source remains validator-owned; B005 made no manual edit.

## Ranked Ownership Analysis

### 1. ObjectStatusBlob class UID00009S through file UID0000M6
- Evidence for: all three functions are thiscall methods over the same 68-byte receiver; existing class/file pages already model the shared map/look/dialog structure; broad consumers and direct class semantics fit a dedicated helper; source tree already has `NexusTK/map/ObjectStatusBlob.cpp`.
- Evidence against: exact original path could have been a broader object/protocol folder, and member spellings are inferred.
- Decision: accepted. It is the narrowest direct owner and the existing path is stronger than inventing a new source module.

### 2. MapPane or map packet-handler ownership
- Evidence for: MapPane has direct full/partial callers and object creation consumes the kind/id fields.
- Evidence against: many independent look/profile/dialog/menu consumers call the same API; methods mutate ObjectStatusBlob, not MapPane; current dedicated class/file route is coherent.
- Decision: reject direct ownership; keep MapPane as a high-value consumer/support destination.

### 3. NewHumanImageLib, PacketBuffer, MetaMan, or UI-dialog ownership
- Evidence for: NewHuman consumes most full fields; PacketBuffer supplies BE16 reads; MetaMan supplies riding metadata; dialogs have many tagged calls.
- Evidence against: each is a dependency or consumer, none is the parser receiver, and compact monster/item modes extend beyond NewHuman.
- Decision: reject all as owners. Preserve their existing owners and document dependency boundaries.

### Proposed new file/grouping, if applicable
- Applied disposition: no new by-file page. UID0000M6 `ObjectStatusBlob` remains at `NexusTK/map/ObjectStatusBlob.cpp`.
- Likely full contents: class declaration from UID00009S and exact three method children in address/source order.
- Candidate related items that belong: only the three source-authored parser methods in UID000179.
- Candidate related items rejected: raw setters at `0x004d26a0`/`0x004d26e0`, MapPane handlers, NewHuman renderers, metadata manager, PacketBuffer helpers, and all caller bodies.
- Source-file inference: narrow standalone helper source within the map/object subsystem, shared by UI and profile code through a header.

## Source Placement
- Implemented source file/class/global/module placement: `ObjectStatusBlob` declaration in the class/header surface and methods in `NexusTK/map/ObjectStatusBlob.cpp`, routed UID child -> UID00009S -> UID0000M6.
- Why it fits: current source tree already names the file; map object packets are primary producer paths; non-map callers consume the same shared object appearance representation; the class has no UI/base inheritance or global lifetime.
- Rejected placements: `MapPane.cpp` is too consumer-specific; `NewHumanImageLib.cpp` excludes monster/item compact modes; `PacketBuffer.cpp` owns scalar codecs, not packet schema; `MetaMan.cpp` only supplies table data; UI dialog/look files are callers; a new `protocol/ObjectStatusBlob.cpp` lacks stronger repository evidence than the accepted current route.
- Remaining placement uncertainty: exact original folder spelling is not source-symbol-proven. This caps file confidence at 91 but does not justify moving a coherent accepted path.

## Range / Split / Padding / Reclassification Analysis
- Exact parent range stays `0x004d1f30-0x004d2697` exclusive. Children use modeled function ends exactly: `1f99`, `2637`, and `2697`.
- Internal spans `1f99-1fa0` and `2637-2640` remain documented as alignment and are not copied into any child C++.
- Parent UID000179 becomes `RECONSTRUCTABLE:FALSE`, keeps direct semantic class context in prose, clears `EMITTER_UIDS`, and has a blank managed body. Exact children carry source ownership/emission.
- Serial creation order: create first child with TMP-free self-contained references and validate/register it; then second; then third. Only after all real UIDs exist, replace parent/class/support references with those real UIDs. Do not guess UIDs.
- Cumulative nesting in validator address order: UID000179 keeps `Nested:-4`; first same-start child gets `Nested:+4`; second and third get `Nested:0`; following UID00017A changes `Nested:0 -> -4`. This returns the cumulative indent to the pre-split level. New child count is not stored in `Nested`.
- Predecessor UID000177 and its final child remain unchanged. Fourteen bytes `0x004d1f22-0x004d1f30` remain predecessor-to-target padding.
- `0x004d2697-0x004d2720` is outside the target. Bounded raw setter leads at `0x004d26a0`/`0x004d26e0` are not silently absorbed. HumanImageLib begins at modeled `0x004d2720`.
- No rename of UID000179 is needed; its name accurately describes the index after split.

## Negative Evidence Summary
- No constructor/destructor/vtable/RTTI is present in the target; class layout comes from exact parser/consumer storage, not fabricated lifecycle code.
- No title string/table/global is referenced. Exact `RidableAnimals` and NewHuman riding consumption reject the title interpretation.
- No standalone appearance-remap table exists at `0x0067a760`; canonical singleton and vector-layout docs identify NewHumanImageLib.
- No evidence supports a generic raw `fields[68]` source representation. Named members and explicit aliases are required by current formal consumers and complete evidence.
- No packed layout is required; normal 4/2/1-byte alignment plus explicit padding yields exactly 68 bytes.
- No free/static parser wrapper is observed. Calls lower as thiscall with an ObjectStatusBlob receiver.
- No single caller family owns the source. Broad xrefs are use evidence, not ownership transfer.
- No modeled function/xref at bounded raw successors proves they belong to this class or aggregate. Their proximity alone is insufficient.
- No generated output, old report, or comparative server source was treated as binary authority.
- No unresolved field is deferred as `field_XX`, `sub_`, `dword_`, or generic profile bytes. A few spellings remain descriptive, but every byte has a type, offset, and best supported role or explicit padding disposition.

## IDA Rename / Type / Comment Recommendations
- Source-facing function names: `ObjectStatusBlob::ParseTaggedStatus`, `ParseFullStatus`, `ParsePartialStatus`.
- Source-facing globals/callees: `g_useEpfAssets`, `g_pNewHumanImageLib`, `g_pMetaMan`, `PacketBufferReadUInt16BE`, `MetaMan::FindEntry`, `RidableAnimals`, and CRT `_wtol`/`swprintf_s`.
- Type recommendation: apply `ObjectStatusBlob *this` and `const unsigned char *packet` to the three method views; model the receiver with the exact 68-byte class from Destination 2. Treat `+44/+46` as unsigned 16-bit values and `+48` as signed 16-bit Y offset.
- Comment recommendation: annotate the two internal `0xcc` gaps, the exact 43/5/4 consumed lengths, full parser body/coat and sentinel normalization, hair-color low-five-bit remap, and riding metadata table columns.
- Items intentionally unchanged: raw successor names/definitions at `0x004d26a0`/`0x004d26e0` because there is no target ownership/xref proof; exact original spellings of descriptive members because no symbol source survives.
- IDA DB edits: not requested or bundled into either phase. C33 records documentation/source findings only; no rename/type/comment mutation was performed.

## First-Draft C++ Recommendation
- Eligible for draft C++: class UID00009S, all three new exact method children, and the three existing support emitters whose current calls/types contradict the recovered member API. UID000179 itself is not eligible after split because it is only an index.
- Applied code: the following nine destination-specific managed blocks were installed literally. Destinations 6-9 preserve all unrelated accepted formal content and change only the parser/type/member lines required by this report. A post-callback byte-for-byte comparison returned true for Destinations 1-9.
- Third-party import directive: not applicable. All code is project-owned and no `third_party_embeds/...` source is involved.
- Behavior preservation: the method bodies retain exact packet byte offsets, BE16 reads, return lengths, sentinels, riding lookups, hair remap, body/coat conversion, shoe/headgear normalization, and untouched-field behavior. No blanket initialization was added.
- Source-shape rationale: member methods, RAII SimpleUString locals, named fields, direct byte indexing, old-style enum aliases, anonymous unions, and a typedef size assertion are plausible Visual C++ 6/7-era human source. No `sub_`, raw globals, decompiler temporaries, offsets, lambdas, `auto`, `nullptr`, or modern layout features remain.
- Naming convention: existing NexusTK `m_` members, `g_` globals, PascalCase methods, and accepted packet helper names. Descriptive/inferred spellings are identified in the report and capped below final-audit scores.
- Parent no-code proof: UID000179 represents no independent source-level declaration/body after exact children exist. Its literal body must therefore remain blank, not carry a covered-by comment that would emit a fourth artifact.

### Destination 1 - UID000179 aggregate managed block
Exact destination: `by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md`. This is intentionally blank with `RECONSTRUCTABLE:FALSE` and no emitters.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - UID00009S complete ObjectStatusBlob class
Exact destination: `by-class/ObjectStatusBlob.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ObjectStatusBlob
{
public:
    enum StatusKind
    {
        HumanObject = 0,
        FullLivingObject = HumanObject,
        MonsterObject = 1,
        CompactLivingObject = MonsterObject,
        ItemObject = 2
    };

    int ParseTaggedStatus(const unsigned char *packet);
    int ParseFullStatus(const unsigned char *packet);
    int ParsePartialStatus(const unsigned char *packet);

    StatusKind m_statusKind;                       // +0x00
    union                                           // +0x04
    {
        unsigned short m_appearanceId;
        unsigned short m_faceId;
        unsigned short headIndex;
    };
    union                                           // +0x06
    {
        unsigned char m_variantOrPalette;
        unsigned char m_hairId;
        unsigned char headDrawOffset;
    };
    unsigned char m_padding07;                      // +0x07
    unsigned short m_bodyId;                        // +0x08
    unsigned short m_weaponId;                      // +0x0a
    unsigned short m_shieldOrArrowId;               // +0x0c
    unsigned char m_helmetId;                       // +0x0e
    unsigned char m_padding0f;                      // +0x0f
    unsigned short m_faceDecorationId;              // +0x10
    unsigned short m_hairDecorationId;              // +0x12
    unsigned short m_secondFaceDecorationId;        // +0x14
    unsigned short m_mantleId;                      // +0x16
    unsigned short m_neckId;                        // +0x18
    unsigned short m_shoesId;                       // +0x1a
    unsigned short m_coatId;                        // +0x1c
    unsigned short m_fullBodyId;                    // +0x1e
    unsigned char m_headgearMode;                   // +0x20
    union                                           // +0x21
    {
        unsigned char m_gender;
        unsigned char m_direction;
    };
    union                                           // +0x22
    {
        unsigned char m_compositionMode;
        unsigned char m_posture;
    };
    unsigned char m_padding23;                      // +0x23
    unsigned int m_actionState;                     // +0x24
    union                                           // +0x28
    {
        unsigned char m_displayStatusByte;
        unsigned char defaultByte;
    };
    unsigned char m_padding29;                      // +0x29
    unsigned short m_ridingAppearanceId;            // +0x2a
    unsigned short m_ridingDefinitionIndex;         // +0x2c
    unsigned short m_ridingPaletteFlags;            // +0x2e
    short m_ridingYOffset;                          // +0x30
    unsigned char m_faceColor;                      // +0x32
    unsigned char m_hairColor;                      // +0x33
    unsigned char m_skinColor;                      // +0x34
    unsigned char m_bodyColor;                      // +0x35
    unsigned char m_weaponColor;                    // +0x36
    unsigned char m_shieldOrArrowColor;             // +0x37
    unsigned char m_helmetColor;                    // +0x38
    unsigned char m_faceDecorationColor;            // +0x39
    unsigned char m_hairDecorationColor;            // +0x3a
    unsigned char m_secondFaceDecorationColor;      // +0x3b
    unsigned char m_mantleColor;                    // +0x3c
    unsigned char m_neckColor;                      // +0x3d
    unsigned char m_shoesColor;                     // +0x3e
    unsigned char m_invisible;                      // +0x3f
    unsigned char m_faceShape;                      // +0x40
    unsigned char m_trailingPadding[3];             // +0x41
};

typedef char ObjectStatusBlobSizeMustBe68[
    (sizeof(ObjectStatusBlob) == 68) ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - new ParseTaggedStatus child
Exact destination: new `by-memory/0x004d1f30-0x004d1f99.ObjectStatusBlobParseTaggedStatus.md` after serial UID registration.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int ObjectStatusBlob::ParseTaggedStatus(const unsigned char *packet)
{
    switch (packet[0])
    {
    case 0:
        return ParseFullStatus(packet + 1) + 1;

    case 1:
    case 2:
        m_statusKind = static_cast<StatusKind>(packet[0]);
        m_appearanceId = PacketBufferReadUInt16BE(packet + 1);
        m_variantOrPalette = packet[3];
        return 4;

    default:
        return 0;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - new ParseFullStatus child
Exact destination: new `by-memory/0x004d1fa0-0x004d2637.ObjectStatusBlobParseFullStatus.md` after serial UID registration.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int ObjectStatusBlob::ParseFullStatus(const unsigned char *packet)
{
    const unsigned short kNoPart = 0xffff;

    m_statusKind = HumanObject;
    m_actionState = 11;
    m_gender = packet[0];
    m_compositionMode = packet[1];
    m_ridingAppearanceId = PacketBufferReadUInt16BE(packet + 2);
    m_displayStatusByte = packet[4];

    if (m_ridingAppearanceId != 0)
    {
        if (!g_useEpfAssets)
            m_ridingAppearanceId = 1;

        wchar_t ridingKeyText[128];
        swprintf_s(ridingKeyText,
                   sizeof(ridingKeyText) / sizeof(ridingKeyText[0]),
                   L"%d",
                   static_cast<int>(m_ridingAppearanceId));

        SimpleUString tableName;
        tableName.Assign(L"RidableAnimals", 14);

        SimpleUString ridingKey;
        ridingKey.Assign(ridingKeyText,
                         static_cast<unsigned int>(wcslen(ridingKeyText)));

        const SimpleUString *value =
            g_pMetaMan->FindEntry(&tableName, &ridingKey, 1);
        m_ridingDefinitionIndex =
            static_cast<unsigned short>(_wtol(value->c_str()));

        value = g_pMetaMan->FindEntry(&tableName, &ridingKey, 2);
        m_ridingPaletteFlags =
            static_cast<unsigned short>(_wtol(value->c_str()));

        value = g_pMetaMan->FindEntry(&tableName, &ridingKey, 3);
        m_ridingYOffset = static_cast<short>(_wtol(value->c_str()));
    }

    m_faceId = PacketBufferReadUInt16BE(packet + 5);
    m_hairId = packet[7];
    m_hairColor = packet[8];
    m_faceColor = packet[9];
    m_skinColor = packet[10];

    if (m_faceId != kNoPart &&
        (m_faceId <= 199 ||
         (m_faceId >= 900 && m_faceId <= 999) ||
         m_faceId > 399))
    {
        m_hairId = static_cast<unsigned char>(m_faceId);
        m_faceId = 200;
    }

    if (m_hairId < g_pNewHumanImageLib->m_hairColorEntries.size())
    {
        m_hairColor = static_cast<unsigned char>(
            (m_hairColor & 0xe0) +
            (m_hairColor +
             g_pNewHumanImageLib->m_hairColorEntries[m_hairId]) % 32);
    }

    const unsigned short bodyOrCoatId =
        PacketBufferReadUInt16BE(packet + 11);
    if (bodyOrCoatId <= 9999)
    {
        m_bodyId = bodyOrCoatId;
        m_coatId = kNoPart;
        if (m_bodyId == 0)
            m_bodyId = (m_gender != 0);
    }
    else
    {
        m_coatId = static_cast<unsigned short>(bodyOrCoatId % 10000);
        m_bodyId = kNoPart;
    }

    m_bodyColor = packet[13];
    m_weaponId = PacketBufferReadUInt16BE(packet + 14);
    m_weaponColor = packet[16];
    m_shieldOrArrowId = PacketBufferReadUInt16BE(packet + 17);
    m_shieldOrArrowColor = packet[19];
    m_headgearMode = packet[20];
    m_helmetId = packet[21];
    m_helmetColor = packet[22];
    m_faceDecorationId = PacketBufferReadUInt16BE(packet + 23);
    m_faceDecorationColor = packet[25];
    m_hairDecorationId = PacketBufferReadUInt16BE(packet + 26);
    m_hairDecorationColor = packet[28];
    m_secondFaceDecorationId = PacketBufferReadUInt16BE(packet + 29);
    m_secondFaceDecorationColor = packet[31];
    m_mantleId = PacketBufferReadUInt16BE(packet + 32);
    m_mantleColor = packet[34];
    m_neckId = PacketBufferReadUInt16BE(packet + 35);
    m_neckColor = packet[37];
    m_shoesId = PacketBufferReadUInt16BE(packet + 38);
    m_shoesColor = packet[40];
    m_invisible = packet[41];
    m_faceShape = packet[42];
    m_fullBodyId = kNoPart;

    if (m_coatId == kNoPart)
    {
        if (m_bodyId != 0 &&
            m_bodyId != 1 &&
            m_bodyId != 57 &&
            m_bodyId != 58 &&
            m_bodyId != 160 &&
            m_bodyId != 161)
        {
            m_shoesId = kNoPart;
        }
    }
    else if (m_shoesId == kNoPart)
    {
        m_shoesId = (m_gender != 0);
    }

    if (m_headgearMode == 0)
        m_helmetId = 0xff;
    else if (m_headgearMode == 1 || m_headgearMode == 2)
        m_hairId = 0xff;

    return 43;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - new ParsePartialStatus child
Exact destination: new `by-memory/0x004d2640-0x004d2697.ObjectStatusBlobParsePartialStatus.md` after serial UID registration.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int ObjectStatusBlob::ParsePartialStatus(const unsigned char *packet)
{
    m_statusKind = CompactLivingObject;
    m_actionState = 11;
    m_displayStatusByte = 0x50;
    m_direction = packet[0];
    m_posture = packet[1];
    m_appearanceId = PacketBufferReadUInt16BE(packet + 2);
    m_variantOrPalette = packet[4];
    return 5;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - UID0001FI HeadSelectDialog member-call correction
Exact destination: `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`. This preserves the complete current accepted block and changes only the static-shaped parser call to `m_previewObject.ParseTaggedStatus(packet + 6)`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {

const int kHeadsPerPage = 10;
const int kHeadButtonCount = 10;
const int kFirstHeadButtonControlIndex = 7;
const int kPreviewControlIndex = 5;

int LowSignedByte(int value)
{
    return static_cast<signed char>(value & 0xff);
}

void PatchNormalHeadOffsets()
{
    s_normalHeadVerticalOffsets[900] = -5;
    s_normalHeadVerticalOffsets[901] = -8;
    s_normalHeadVerticalOffsets[902] = -2;
}

void PatchHighResHeadOffsets()
{
    static const int kTail[] = {
        -5, -8, -2, -7, -8, -9, -3, -2, -9, -2, -10, -3, -3
    };

    for (int i = 0; i < static_cast<int>(sizeof(kTail) / sizeof(kTail[0])); ++i) {
        s_highResHeadVerticalOffsets[900 + i] = kTail[i];
    }
}

const int *CurrentHeadOffsetTable()
{
    return (g_useEpfAssets == 1)
        ? s_highResHeadVerticalOffsets
        : s_normalHeadVerticalOffsets;
}

RectBounds PreviewRect()
{
    return (g_useEpfAssets == 1)
        ? RectBounds(36, 40, 73, 95)
        : RectBounds(36, 40, 71, 88);
}

RectBounds BottomButtonRect(int slot)
{
    static const RectBounds kHighRes[] = {
        RectBounds(40, 266, 103, 290),
        RectBounds(114, 266, 177, 290),
        RectBounds(188, 266, 251, 290),
        RectBounds(262, 266, 325, 290),
    };

    static const RectBounds kNormal[] = {
        RectBounds(40, 266, 112, 282),
        RectBounds(114, 266, 186, 282),
        RectBounds(188, 266, 260, 282),
        RectBounds(262, 266, 334, 282),
    };

    return (g_useEpfAssets == 1) ? kHighRes[slot] : kNormal[slot];
}

RectBounds HeadButtonRect(int slot)
{
    const int x = 54 * (slot % 5) + 58;
    const int y = ((slot / 5) << 6) + 113;
    return RectBounds(x, y, x + 41, y + 54);
}

} // namespace

HeadSelectDialog::HeadSelectDialog(const unsigned char *packet)
    : DialogPane(L"", true, true),
      m_dialogSubtype(0),
      m_headPrice(0),
      m_npcId(0),
      m_objectId(0),
      m_headCount(0),
      m_selectedHead(0),
      m_currentPage(0),
      m_baseHeadDrawOffset(0),
      m_previewPane(0),
      m_confirmButton(0),
      m_nextPageButton(0),
      m_prevPageButton(0)
{
    m_previewObject.defaultByte = 0x50;

    if (g_useEpfAssets == 1) {
        PatchHighResHeadOffsets();
    } else {
        PatchNormalHeadOffsets();
    }

    m_dialogSubtype = packet[0];
    m_headPrice = PacketBufferReadUInt32BE(packet + 1);

    if (packet[5] == 2) {
        const_cast<unsigned char *>(packet)[6] = 2;
    }

    const int objectBytes = m_previewObject.ParseTaggedStatus(packet + 6);
    if (objectBytes < 0) {
        return;
    }

    const int *offsetTable = CurrentHeadOffsetTable();
    m_baseHeadDrawOffset =
        static_cast<unsigned char>(m_previewObject.headDrawOffset) -
        offsetTable[m_previewObject.headIndex];

    int pos = objectBytes + 10;
    m_npcId = PacketBufferReadUInt16BE(packet + pos);
    pos += 2;

    m_objectId = PacketBufferReadUInt16BE(packet + pos);
    pos += 2;

    packet[pos++];
    packet[pos++];

    const unsigned int messageLength = PacketBufferReadUInt16BE(packet + pos);
    pos += 2;

    char messageText[32768];
    wchar_t wideMessageText[32768];

    CopyBytes(messageText, packet + pos, messageLength);
    if (messageLength >= sizeof(messageText)) {
        ReportRangeCheckFailure();
    }
    messageText[messageLength] = 0;

    const unsigned int wideLength = MultiByteToWideChar(
        0,
        0,
        messageText,
        messageLength,
        wideMessageText,
        32768);
    if (wideLength >= 32768) {
        ReportRangeCheckFailure();
    }
    wideMessageText[wideLength] = 0;

    m_headCount = g_pNewHumanImageLib->GetHeadCount();
    m_selectedHead = m_previewObject.headIndex;
    if (m_selectedHead >= m_headCount) {
        m_selectedHead = m_headCount - 1;
    }
    if (m_selectedHead < 0) {
        m_selectedHead = 0;
    }

    m_currentPage = m_selectedHead / kHeadsPerPage;

    AddControl(new EPFImageControlPane(
        L"DLGMSGH.EPF",
        0,
        true,
        RectBounds(0, 0, 374, 316),
        L"NPAL8.PAL"));

    m_confirmButton = new ImageButtonControlPane(14, BottomButtonRect(0));
    AddControl(m_confirmButton);

    m_prevPageButton = new ImageButtonControlPane(18, BottomButtonRect(1));
    AddControl(m_prevPageButton);

    m_nextPageButton = new ImageButtonControlPane(19, BottomButtonRect(2));
    AddControl(m_nextPageButton);

    AddControl(new ImageButtonControlPane(15, BottomButtonRect(3)));

    UpdatePageButtonStates();

    m_previewPane = new ObjectImageControlPane(&m_previewObject, PreviewRect());
    AddControl(m_previewPane);

    AddControl(new StaticTextControlPane(
        wideMessageText,
        true,
        128,
        143,
        RectBounds(86, 29, 336, 92),
        false,
        0));

    for (int i = 0; i < kHeadButtonCount; ++i) {
        m_headButtons[i] = 0;
    }

    SetFocusedControl(1);
    SetPendingControl(4);
    SetBackgroundResource(L"DLGMSGH.EPF", 0);
    OnShow(0, 0);

    PopulateHeadButtons(m_currentPage, false);
}

HeadSelectDialog::~HeadSelectDialog()
{
    OnDialogDestroying();
    RemoveDialogControls();
}

void HeadSelectDialog::RefreshHeadPreview()
{
    ObjectImageControlPane *oldPreview = m_previewPane;
    const int *offsetTable = CurrentHeadOffsetTable();

    m_previewObject.headIndex = static_cast<unsigned short>(m_selectedHead);
    m_previewObject.headDrawOffset = static_cast<unsigned char>(
        m_baseHeadDrawOffset + LowSignedByte(offsetTable[m_selectedHead]));

    m_previewPane = new ObjectImageControlPane(&m_previewObject, PreviewRect());
    ControlPane **previewSlot = static_cast<ControlPane **>(
        m_controlManager->GetElementAt(kPreviewControlIndex));
    *previewSlot = m_previewPane;

    DestroyPane(oldPreview);
    Invalidate();
    Repaint(RectBounds(0, 0, 374, 316), 0, 0, g_transparentColor);
}

void HeadSelectDialog::UpdatePageButtonStates()
{
    if (m_currentPage < 1) {
        m_prevPageButton->Disable();
    } else {
        m_prevPageButton->Enable();
    }

    if (m_currentPage >= m_headCount / kHeadsPerPage) {
        m_nextPageButton->Disable();
    } else {
        m_nextPageButton->Enable();
    }
}

void HeadSelectDialog::NextHeadPage()
{
    ++m_currentPage;
    if (m_currentPage * kHeadsPerPage >= m_headCount) {
        --m_currentPage;
    }

    PopulateHeadButtons(m_currentPage, true);
    UpdatePageButtonStates();
}

void HeadSelectDialog::PreviousHeadPage()
{
    --m_currentPage;
    if (m_currentPage < 0) {
        m_currentPage = 0;
    }

    PopulateHeadButtons(m_currentPage, true);
    UpdatePageButtonStates();
}

void HeadSelectDialog::PopulateHeadButtons(int page, bool removeExistingButtons)
{
    if (removeExistingButtons && GetControlCount() != kFirstHeadButtonControlIndex) {
        do {
            RemoveControl(kFirstHeadButtonControlIndex);
        } while (GetControlCount() != kFirstHeadButtonControlIndex);
    }

    const int firstHead = page * kHeadsPerPage;
    const int *offsetTable = CurrentHeadOffsetTable();

    for (int slot = 0; slot < kHeadButtonCount; ++slot) {
        if (m_headButtons[slot] != 0) {
            DestroyPane(m_headButtons[slot]);
            m_headButtons[slot] = 0;
        }

        const int head = firstHead + slot;
        m_previewObject.headIndex = static_cast<unsigned short>(head);
        m_previewObject.headDrawOffset = static_cast<unsigned char>(
            m_baseHeadDrawOffset + LowSignedByte(offsetTable[head]));

        if (head >= m_headCount) {
            break;
        }

        ObjectImageButtonPane *button =
            new ObjectImageButtonPane(&m_previewObject, HeadButtonRect(slot));
        m_headButtons[slot] = button;

        if (head == m_selectedHead) {
            button->SetButtonHighlight(true);
        }

        AddControl(button);
    }

    Invalidate();
    Repaint(RectBounds(0, 0, 374, 316), 0, 0, g_transparentColor);
}

void HeadSelectDialog::OnAction(int actionId, int /*unused*/)
{
    switch (actionId) {
    case 1:
    case 4:
        CloseDialog();
        break;

    case 2:
        PreviousHeadPage();
        break;

    case 3:
        NextHeadPage();
        break;

    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16: {
        ObjectImageButtonPane *oldButton =
            m_headButtons[m_selectedHead % kHeadsPerPage];
        if (oldButton != 0) {
            oldButton->SetButtonHighlight(false);
        }

        m_selectedHead = actionId + (m_currentPage * kHeadsPerPage) - 7;

        ObjectImageButtonPane *newButton =
            m_headButtons[m_selectedHead % kHeadsPerPage];
        if (newButton != 0) {
            newButton->SetButtonHighlight(true);
        }

        RefreshHeadPreview();
        PopulateHeadButtons(m_currentPage, true);
        break;
    }

    default:
        break;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7 - UID0001FF MessageDialog member/field correction
Exact destination: `by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md`. This preserves all current accepted behavior while replacing the raw field array and nonexistent free parser call.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool PursuitMessageDialogPane::HandleDialogObjectResponse(const DialogObjectAction *action)
{
    const unsigned char *payload = action->payload;

    if (payload[0] == 0x2f)
        return true;
    if (payload[0] != 0x30)
        return false;

    ObjectStatusBlob objectStatus;
    objectStatus.m_displayStatusByte = 0x50;

    const unsigned char responseType = payload[2];
    const unsigned int objectId = PacketBufferReadUInt32BE(payload + 3);
    const int parsedStatusLength = objectStatus.ParseTaggedStatus(payload + 8);
    const int trailingOffset = (parsedStatusLength >= 0) ? parsedStatusLength + 12 : 12;
    const unsigned short responseValue1 = PacketBufferReadUInt16BE(payload + trailingOffset);
    const unsigned short responseValue2 = PacketBufferReadUInt16BE(payload + trailingOffset + 2);

    unsigned char packet[11];
    PacketBufferWriteUInt8(0x3a, packet);
    PacketBufferWriteUInt8(responseType, packet + 1);
    PacketBufferWriteUInt32BE(objectId, packet + 2);
    PacketBufferWriteUInt16BE(responseValue1, packet + 6);
    PacketBufferWriteUInt16BE(responseValue2, packet + 8);
    packet[10] = 0;

    g_packetSender->QueueAndSendPacket(packet, 10);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8 - UID0000CU SelfLookPane declaration synchronization
Exact destination: `by-class/SelfLookPane.md`. This preserves the complete current declaration byte-for-byte and appends the resolved ObjectStatusBlob member required by Destination 9. Raw bytes and the modeled handler place the backing state at binary offset `SelfLookPane+0x108`; this intentionally partial source-facing declaration skeleton does not claim that omitted earlier fields are represented.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// First-draft declaration skeleton. Method bodies are documented on exact child pages.
class SelfLookPane : public PanelPane {
public:
    bool OnMouseClick(const PanelMouseEvent *event);
    bool OnPacketEvent(const PanelPacketEvent *event);

    bool SendSelfLookOptionRequest(unsigned char optionSubtype);
    bool ApplySelfLookRectRecord(const unsigned char *packet);
    bool ApplySelfLookRectStateRecord(const unsigned char *packet);
    bool ApplyEquipmentSlotRecord(const unsigned char *packet);
    bool ClearEquipmentSlotRecord(const unsigned char *packet);
    bool ApplySelfLookSummaryRecord(const unsigned char *packet);
    bool DispatchSpelledText(const unsigned char *packet);
    void ToggleSelfLookViewCache();

private:
    enum EquipmentSlotId {
        SelfLookEquipmentSlot_FaceAccessory1 = 7,
        SelfLookEquipmentSlot_Head = 8,
        SelfLookEquipmentSlot_HeadAccessory2 = 9,
        SelfLookEquipmentSlot_RightHand = 10,
        SelfLookEquipmentSlot_Body = 11,
        SelfLookEquipmentSlot_LeftHand = 12,
        SelfLookEquipmentSlot_RightAccessory = 13,
        SelfLookEquipmentSlot_Mantle = 14,
        SelfLookEquipmentSlot_LeftAccessory = 15,
        SelfLookEquipmentSlot_LeftSubAccessory = 16,
        SelfLookEquipmentSlot_Coat = 17,
        SelfLookEquipmentSlot_RightSubAccessory = 18,
        SelfLookEquipmentSlot_Necklace = 19,
        SelfLookEquipmentSlot_Foot = 20
    };

    SpelledPane *m_spelledPane;
    LegendPane *m_legendPane;
    ObjectStatusBlob m_selfLookObjectStatus;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9 - UID0002RB SelfLookPane parser-call correction
Exact destination: `by-memory/0x0056a500-0x0056a63e.SelfLookPaneRectUpdateRawHelpers.md`. This replaces the placeholder type/decoders with the exact full/partial member API and preserves all surrounding accepted behavior.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelfLookPane::ApplySelfLookRectRecord(const unsigned char *packet)
{
    PacketBufferReadUInt16BE(packet + 1);
    PacketBufferReadUInt16BE(packet + 3);

    if (PacketBufferReadUInt32BE(packet + 6) != g_pCollectionData->m_selectedObjectKey)
        return false;

    const unsigned char mode = packet[10];
    ObjectStatusBlob decoded;
    if (mode == 0)
        decoded.ParseFullStatus(packet + 11);
    else if (mode == 1)
        decoded.ParsePartialStatus(packet + 11);
    else
        return false;

    m_selfLookObjectStatus = decoded;
    InvalidateRect(&m_bounds);
    return false;
}

bool SelfLookPane::ApplySelfLookRectStateRecord(const unsigned char *packet)
{
    if (PacketBufferReadUInt32BE(packet + 1) != g_pCollectionData->m_selectedObjectKey)
        return false;

    const unsigned char mode = packet[5];
    if (mode == 0)
        m_selfLookObjectStatus.ParseFullStatus(packet + 6);
    else if (mode == 1)
        m_selfLookObjectStatus.ParsePartialStatus(packet + 6);
    else
        return false;

    InvalidateRect(&m_bounds);
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact managed destination count: 9. Destination 1 remains intentionally blank; Destinations 2-9 contain every declaration/body modification applied by this callback. No other C++ edit was introduced in prose, recommendations, ledger, or checklist.

## Final Recommendation
- Implemented final state: UID000179 is split into exact registered children UID0004LK/UID0004LL/UID0004LM; parent is a `92/93` non-emitting index; Destinations 1-9 are byte-identical to the accepted report; stale title/profile/remap/general direction-posture claims are replaced by complete layout, riding, NewHuman, caller, sentinel, and negative evidence; the source root is preserved.
- Exact parent assignments: UID000179 canonical owner changes from file UID0000M6 to class UID00009S but has no emitters; each new child has `CANONICAL_OWNER:00009S` and `EMITTER_UIDS:00009S`; class UID00009S remains owned/emitted by file UID0000M6; file UID0000M6 remains `CANONICAL_OWNER:FILE` at `NexusTK/map/`.
- Exact items left no-owner/non-emitting: UID000179 is class-owned but non-emitting because it is only an index. The raw entries at `0x004d26a0` and `0x004d26e0` remain outside this assignment without invented ownership or code.
- External bounded work, if independently assigned, may investigate the two raw successors; this callback creates no pending obligation and they do not block the implemented parsers, layout, owner, source route, or C++.
- Formal block completeness: nine exact literal destinations cover every applied class/declaration/body change. Remaining support changes are prose/metadata only and preserve their formal blocks.

## Recommended Target Doc Changes
- Applied/verified callback record: every transition below is complete in the named destination; the section heading remains the required report-template heading.
- Target path `by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md`:
  - Scores `86/90 -> 92/93`.
  - `CANONICAL_OWNER:0000M6 -> 00009S`.
  - `RECONSTRUCTABLE:TRUE -> FALSE`.
  - `EMITTER_UIDS:0000M6 -> blank`; optional position remains blank.
  - Keep range, UID, filename, and `Nested:-4` unchanged.
  - Blank Destination 1 applied.
  - Item Summary replaced with: `Reviewed non-emitting split index over exact ObjectStatusBlob tagged/full/partial parser children; preserves 68-byte layout evidence, internal alignment, caller/global/consumer analysis, and excludes bounded raw successors without duplicating source.`
  - Exact function/child table, complete 68-byte offset table, packet read/write table, full normalization, riding metadata, global/callee/caller inventory, source route, cumulative nesting plan, score rationale, stale-assumption corrections, and all positive/negative evidence incorporated.
  - Predecessor padding, both internal alignment spans, assigned exclusive endpoint, and raw-successor exclusion preserved.
- New target child 1 `by-memory/0x004d1f30-0x004d1f99.ObjectStatusBlobParseTaggedStatus.md`:
  - Registered first through validator workflow as UID0004LK; no UID was guessed.
  - `92/94`, owner/emitter UID00009S, reconstructable true, emitter position `10`, `Nested:+4`, Destination 3.
  - Item Summary: `Source-ready ObjectStatusBlob tagged parser dispatches full mode, decodes compact monster/item/head modes, preserves exact 0/4/full-plus-one return lengths, and uses canonical big-endian packet helpers.`
  - Exact boundary/padding, switch/default behavior, all direct tagged callers, source name/signature rationale, and rejected free/static/raw alternatives included.
- New target child 2 `by-memory/0x004d1fa0-0x004d2637.ObjectStatusBlobParseFullStatus.md`:
  - Registered second as UID0004LL; `91/93`, owner/emitter UID00009S, reconstructable true, emitter position `20`, `Nested:0`, Destination 4.
  - Item Summary: `Source-ready 43-byte full ObjectStatusBlob parser with complete 68-byte field writes, RidableAnimals metadata, HAIRCOL remap, Body/Coat and sentinel normalization, equipment/color tail, and exact caller/callee evidence.`
  - Every read/write/constant/normalization, the redundant observed face predicate, untouched padding/conditional riding outputs, all full callers, exact globals/strings/callees, and lower score rationale preserved.
- New target child 3 `by-memory/0x004d2640-0x004d2697.ObjectStatusBlobParsePartialStatus.md`:
  - Registered third as UID0004LM; `92/94`, owner/emitter UID00009S, reconstructable true, emitter position `30`, `Nested:0`, Destination 5.
  - Item Summary: `Source-ready five-byte partial ObjectStatusBlob parser writes compact kind, action/display defaults, direction/posture aliases, appearance id, and variant byte with exact caller and boundary evidence.`
  - Exact field writes, return, callers, following raw-successor exclusion, source signature, and rejected wrapper/free-function alternatives included.
- Historical/stale assumptions to preserve as explicitly rejected: title metadata at `+42..+48`, generic appearance-remap global at `0x0067a760`, profile tail, universal direction/posture naming, aggregate source emission, and the obsolete 95/95-only blank-code rationale.

## Recommended Support Doc Changes
- Applied/verified callback record: all named support changes are complete; scores/formal blocks/routes were preserved except the four accepted formal Destinations 6-9 and explicitly listed UID00009S/UID0000M6 score transitions.
- `by-class/ObjectStatusBlob.md` UID00009S:
  - Raised `86/90 -> 92/93`; owner/emitter UID0000M6 and reconstructable true preserved; complete Destination 2 applied with `[[CHILDREN]]` after the declaration.
  - Incomplete field table replaced with every byte/word/dword from `+0x00` through trailing padding `+0x43`; exact Part-tag mapping, aliases, real child links, globals/callees/callers, stale-assumption corrections, source route, score rationale, and no-lifecycle/vtable evidence added.
- `by-file/ObjectStatusBlob.md` UID0000M6:
  - Raised `86/88 -> 90/91`; preserved `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"` and FILE ownership.
  - Title/profile/remap prose replaced with complete parser/layout/riding/NewHuman/consumer/source inventory; class and three real child UIDs listed; UID000179 recorded as non-emitting. No by-file formal block exists.
- `by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md` UID00017A:
  - Changed only `Nested:0 -> -4` plus the exact relative-delta closure note; range, metadata, score `85/90`, body, and formal state preserved.
- `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md` UID0001FI:
  - Destination 6 applied byte-for-byte; `87/89`, owner/emitter, all HeadSelect evidence, and every unrelated formal line preserved.
  - Mode-2 aliases, default byte `+0x28`, and member API documented; only stale static-call claim removed.
- `by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md` UID0001FF:
  - Destination 7 applied; `90/92`, owner/emitter, packet behavior, eight-vtable-ref evidence, and unrelated formal lines preserved.
  - Historical `fields[40]` caveat replaced with resolved member and member parse call.
- `by-class/SelfLookPane.md` UID0000CU and `by-memory/0x0056a500-0x0056a63e.SelfLookPaneRectUpdateRawHelpers.md` UID0002RB:
  - Destinations 8 and 9 applied. Scores `89/91` and `87/90`, owners/emitters, and unrelated methods/evidence preserved.
  - Placeholder type/decoders replaced; exact binary backing, zero raw-start xrefs, modeled-handler mirrors, and fixed-layout ignored returns documented.
- `by-memory/0x00572b60-0x00572f25.SelfLookPane2LookUpdateRawHelpers.md` UID00039M:
  - Score/formal block unchanged. Added full/partial mapping, complete 68-byte model, and exact raw callsites; no formal body synthesized.
- `by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md` UID0003RK and related UserLook/Profile aggregate/file/class pages:
  - Scores/formal blocks unchanged. Inherited field summaries replaced; exact callsites and consumer-not-owner disposition recorded.
- `by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md` UID0003TX, `by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md` UID0003TT, `by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md` UID0002QN, and MapPane class/file:
  - Scores/formal blocks unchanged. Old shorthand replaced, all consumed lengths distinguished, living/item aliases preserved, and real child UIDs linked.
- `by-memory/0x00520540-0x00520816.ObjectImageControlPane.md` UID0001BU plus ObjectImage class/file:
  - Scores/formal blocks unchanged. Exact copy/dispatch/offset evidence preserved and complete unions documented; no C++ edit made.
- NewHuman support: `by-class/NewHumanImageLib.md`, `by-type/by-struct/NewHumanImageLibLayout.md`, `by-file/NewHumanImageLib.md`, `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md`, and appropriate current composition method prose:
  - Scores/formal blocks unchanged. Full Part map, composition/riding/color/shared-tint/HAIRCOL roles added; universal-Body and generic-remap claims corrected.
- MetaMan support: `by-class/MetaMan.md`, `by-file/MetaMan.md`, and `by-global/g_pMetaMan.md`:
  - Scores/formal blocks unchanged. Direct `FindEntry`/RidableAnimals consumer evidence added and title metadata rejected; no MetaMan declaration/API change made.
- Packet reader support: `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md` UID0003YK, class-level helper item `by-item/PacketBufferHelpers.md` UID0000V1 (the project has no `by-class/PacketBuffer.md`), and `by-file/PacketBuffer.md` UID0000M8:
  - Scores/formal blocks unchanged. All three real children added as BE16 consumers; `0x00575470` compiler/runtime exclusion recorded on scalar/by-item/file support.
- Globals `g_useEpfAssets` UID0000SW and `g_pNewHumanImageLib` UID0000RT:
  - Scores/formal blocks unchanged. Full parser read roles added with exact riding-id force and HAIRCOL vector remap; owner/emitter decisions preserved.
- All support prose preserves historical evidence and labels the old title/generic-remap model rejected/superseded. No support destination beyond Destinations 6-9 received a C++ change.

## Score And Metadata Recommendation
- Assignment baseline: UID000179 `86/90`, owner/emitter file UID0000M6, reconstructable true, blank formal block, `Nested:-4`.
- Implemented target score/metadata: UID000179 `92/93`, owner class UID00009S, reconstructable false, no emitter, blank Destination 1, same range/path/UID and `Nested:-4`; children/support metadata are exactly the verified values above.
- Score rationale: parent completion rises because the split, layout, functions, callers, globals, source route, padding, rejected successors, and all blockers are fully documented. Parent confidence remains 93 because exact original field spellings and original folder cannot be source-symbol-proven. Full child is `91/93`, one point below simple siblings, because its large body depends on more descriptive member/API spellings despite exact behavior.
- Class rationale: `92/93` reflects a complete size-checked declaration, every offset/type, all three method signatures, required aliases, and exact child plan. It remains below 95 because several original spellings are inferred and there is no debug type.
- File rationale: `90/91` reflects a coherent complete module and route; it remains below class confidence because exact original source folder/file boundary is inferred from project organization and consumers.
- Score-improvement attempt: final member names were pursued through all parser writes, MapPane/ObjectImage/HeadSelect/SelfLook/UserLook consumers, NewHuman draw/bounds behavior, `Part.tbl`, `HAIRCOL.TBL`, metadata strings, globals, and comparative primary protocol source. This resolves all types/roles and yields coherent source names; only unrecoverable original spellings remain.
- Score-improvement attempt: title/equipment/profile ambiguity was removed by exact `RidableAnimals` columns, NewHuman riding consumers, all 19 Part rows, and complete color dispatch.
- Score-improvement attempt: blank-C++ blockers were removed by exact class/method bodies plus literal support caller corrections. Aggregate emission was resolved by split, not by putting multiple bodies in one range.
- Metadata fields unchanged unless explicitly listed: file path, class/file ownership route, target UID/path/range, child source ranges, optional parent position blank, all support owner/emitter/reconstructable fields, and support scores.

## Open Questions With Attempted Resolution
- Exact original spelling of a few members:
  - Evidence checked: every current parser, render/bounds consumer, map/look/dialog caller, resource table, canonical global, and comparative source listed above.
  - Resolution: use `m_headgearMode`, `m_actionState`, `m_displayStatusByte`, `m_skinColor`, and explicit aliases where contexts genuinely differ. These are descriptive/inferred names with exact types/roles. No raw placeholder remains.
  - Remaining impact: confidence cap only; no C++ behavior, size, owner, split, source route, or caller remains blocked.
- `+0x21/+0x22` single universal labels:
  - Evidence checked: full and partial writes, body/shoes gender tests, MapPane compact consumers, and NewHuman mode reads.
  - Resolution: anonymous aliases `gender/direction` and `compositionMode/posture` express proven context-dependent use without inventing two physical fields.
  - Remaining impact: none on layout or bodies; exact original union/typedef spelling is unknowable without debug/source symbols.
- `+0x28` narrow protocol name:
  - Evidence checked: full packet byte 4, partial/ObjectImage default `0x50`, and current consumers.
  - Resolution: retain established `m_displayStatusByte/defaultByte` alias and reject unproven stronger labels such as lantern size or body style.
  - Remaining impact: one naming-confidence cap only.
- Trailing `+0x3f/+0x40` names:
  - Evidence checked: exact packet tail, NewHuman copies, comparative protocol tail, and no writes after `+0x40`.
  - Resolution: `m_invisible` and `m_faceShape` are the strongest coherent source names; the former remains `unsigned char` to preserve raw byte semantics rather than normalizing through C++ `bool`.
  - Remaining impact: source spelling confidence only.
- Raw successors `0x004d26a0/0x004d26e0`:
  - Evidence checked: bounded lookup, raw form, lack of xrefs, assigned endpoint, and next modeled function.
  - Resolution: exclude. A future independently assigned raw-helper audit would need a real caller/signature route before attachment.
  - Remaining impact: none on UID000179 or its three children.
- No question in assigned scope remains deferred as generic future research or blocks C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- File/placement: not applicable. The affected auto-generated coverage and research tracker files are validator-owned.
- Exact replacement/insert/delete text: none. Source-page Item Summary/Nested metadata was applied in by-* pages and validator commands refreshed their owned registry/generated reports. No scoped command reported a `by-memory/-coverage-report.md` change; final autogen reported validator-owned `auto-generated/-ag-coverage-report-by-memory.md` refresh.
- Reason B agent did not apply it directly: workflow prohibits manual generated/coverage/tracker edits. No separate manual tracker/coverage row is required for this split, and this statement remains neutral to later supervisor lifecycle state.

## Follow-Up Actions
- B005 callback responsibilities are complete: no accepted claim, destination, support sync, validator, lease release, report update, or generated check remains unapplied.
- IDA rename/type/comment mutation was neither required nor performed. Raw successors remain an explicitly excluded independent scope, not pending work in this artifact.
- Report execution and any later lifecycle/archival/tracker state are external supervisor-owned state; this artifact neither directs nor predicts those actions.

## Confidence
- Recommendation confidence: very strong (`93`) for split/owner/layout/behavior; strong for exact original naming.
- Score confidence: strong. Implemented values deliberately remain below 95 final-audit territory.
- Remaining uncertainty: original symbol spellings and exact historical source folder only. Every assigned behavioral, field, global, caller, boundary, split, route, and first-draft blocker is resolved.

## Validator Results
- Historical report-only phase: no implementation validator was run before Gate 1. Callback commands below are the completed implementation evidence.

Serial child registration before references:

| Command | Timestamp | Scope/result |
| --- | --- | --- |
| `000000009614` | `2026-07-13T10:03:43-04:00` | UID-only apply created UID0004LK; exit 0; generated refresh skipped by UID-only. |
| `000000009616` | `2026-07-13T10:05:18-04:00` | UID-only apply created UID0004LL second; exit 0; generated refresh skipped. |
| `000000009618` | `2026-07-13T10:07:45-04:00` | UID-only apply created UID0004LM third; exit 0; generated refresh skipped. |

Scoped by-* validation (each command exit 0 and `ok:1`; each file was leased only for its edit/validation and immediately released):

| Command / timestamp | Final scoped page | Warnings |
| --- | --- | --- |
| `000000009615` / `2026-07-13T10:04:55-04:00` | UID0004LK tagged child | none |
| `000000009617` / `2026-07-13T10:07:19-04:00` | UID0004LL full child | none |
| `000000009619` / `2026-07-13T10:08:29-04:00` | UID0004LM partial child | none |
| `000000009620` / `2026-07-13T10:10:27-04:00` | UID000179 parent | none |
| `000000009621` / `2026-07-13T10:12:01-04:00` | `by-class/ObjectStatusBlob.md` | none |
| `000000009622` / `2026-07-13T10:13:10-04:00` | `by-file/ObjectStatusBlob.md` | none |
| `000000009623` / `2026-07-13T10:13:33-04:00` | UID00017A | pre-existing missing-reference count 1 |
| `000000009624` / `2026-07-13T10:14:20-04:00` | UID0001FI HeadSelect | none |
| `000000009625` / `2026-07-13T10:14:56-04:00` | UID0001FF MessageDialog | none |
| `000000009626` / `2026-07-13T10:15:35-04:00` | `by-class/SelfLookPane.md` | pre-existing missing-reference count 35 |
| `000000009627` / `2026-07-13T10:17:03-04:00` | UID0002RB SelfLook raw | none |
| `000000009628` / `2026-07-13T10:18:34-04:00` | UID00039M SelfLook2 raw | none |
| `000000009630` / `2026-07-13T10:19:47-04:00` | UID0003RK UserLook parse | pre-existing missing-reference count 2 |
| `000000009631` / `2026-07-13T10:19:50-04:00` | UserLook/Profile aggregate | pre-existing missing-reference count 25 |
| `000000009632` / `2026-07-13T10:20:02-04:00` | `by-class/UserLookPane.md` | pre-existing missing-reference count 21 |
| `000000009634` / `2026-07-13T10:20:13-04:00` | `by-class/ProfilePane.md` | pre-existing missing-reference count 9 |
| `000000009635` / `2026-07-13T10:20:16-04:00` | `by-file/UserLookPane.md` | pre-existing missing-reference count 27 |
| `000000009637` / `2026-07-13T10:21:13-04:00` | UID0003TX MapPane info | pre-existing missing-reference count 6 |
| `000000009638` / `2026-07-13T10:21:16-04:00` | UID0003TT MapPane status | pre-existing missing-reference count 2 |
| `000000009640` / `2026-07-13T10:21:28-04:00` | UID0002QN MapPane create/update initial | none |
| `000000009641` / `2026-07-13T10:21:31-04:00` | `by-class/MapPane.md` | pre-existing missing-reference count 81 |
| `000000009642` / `2026-07-13T10:21:43-04:00` | `by-file/MapPane.md` | pre-existing missing-reference count 92 |
| `000000009644` / `2026-07-13T10:22:19-04:00` | UID0001BU ObjectImage | none |
| `000000009645` / `2026-07-13T10:22:28-04:00` | `by-class/ObjectImageControlPane.md` | none |
| `000000009647` / `2026-07-13T10:22:39-04:00` | `by-file/ObjectImageControlPane.md` | none |
| `000000009649` / `2026-07-13T10:23:34-04:00` | `by-class/NewHumanImageLib.md` | none |
| `000000009650` / `2026-07-13T10:23:37-04:00` | NewHuman layout | none |
| `000000009651` / `2026-07-13T10:23:45-04:00` | `by-file/NewHumanImageLib.md` | none |
| `000000009653` / `2026-07-13T10:23:53-04:00` | NewHuman composition aggregate | pre-existing missing-reference count 2 |
| `000000009654` / `2026-07-13T10:23:56-04:00` | NewHuman bounds | none |
| `000000009656` / `2026-07-13T10:24:25-04:00` | `by-class/MetaMan.md` | none |
| `000000009657` / `2026-07-13T10:24:34-04:00` | `by-file/MetaMan.md` | none |
| `000000009658` / `2026-07-13T10:24:45-04:00` | `by-global/g_pMetaMan.md` | none |
| `000000009660` / `2026-07-13T10:25:15-04:00` | UID0003YK PacketBuffer scalar | none |
| `000000009661` / `2026-07-13T10:25:21-04:00` | `by-item/PacketBufferHelpers.md` | pre-existing missing-reference count 2 |
| `000000009662` / `2026-07-13T10:25:32-04:00` | `by-file/PacketBuffer.md` | pre-existing missing-reference count 1 |
| `000000009663` / `2026-07-13T10:26:00-04:00` | `by-global/g_useEpfAssets.md` | pre-existing missing-reference count 5 |
| `000000009664` / `2026-07-13T10:26:03-04:00` | `by-global/g_pNewHumanImageLib.md` | none |
| `000000009667` / `2026-07-13T10:27:26-04:00` | UID0002QN final corrective consistency revalidation | none; final state `ok:1` |
| `000000009677` / `2026-07-13T10:41:28-04:00` | `by-class/ProfilePane.md` ASCII correction revalidation | pre-existing missing-reference count 9; final state `ok:1` |
| `000000009678` / `2026-07-13T10:41:48-04:00` | `by-item/PacketBufferHelpers.md` ASCII correction revalidation | pre-existing missing-reference count 2; final state `ok:1` |

- All timestamps above are `2026-07-13` America/New_York (`-04:00`). Normal scoped commands reported deferred generated refresh and validator-owned projected-stats/registry/reference updates as applicable. No scoped command reported a coverage-file update.
- Initial waited refresh command `000000009668` completed at `2026-07-13T10:28:25-04:00`; it rebuilt 4648 metadata nodes/3783 edges, refreshed 279 generated metadata entries and by-memory generated coverage, and reported the same global warning classes plus an unrelated concurrent GrafPort generated update.
- Controlling final waited refresh: command `000000009679`, timestamp `2026-07-13T10:41:55-04:00`, `--mode autogen --apply --wait-generated`, exit 0, `generated_refresh: completed`. Validator-owned side effects were registry rebuild (4650 metadata nodes/3785 edges), two autogen report updates, 277 generated metadata refreshes, one research-tracker update, global existing warnings (15 child fallback insertions, 83 missing child markers, 206 emitters with no code), and an unrelated concurrent `NexusTK/ui/dialogs/ItemDialogs.cpp` generated update. None was manually edited by B005.
- Generated read-only proof: `ObjectStatusBlob.cpp` contains the class and exactly UID0004LK/UID0004LL/UID0004LM markers, with zero UID000179 and zero Empty Emitter Marker counts. HeadSelect member-call count is 1/static-stale count 0. MessageDialogs resolved-field/member-call counts are 1/1 and stale-array/free-call counts 0/0. SelfLookPane has one ObjectStatusBlob member, one decoded local, two full and two partial member calls, and zero placeholder decoder/type counts.
- Lease proof: the generated current-leases report after all B005 work contained no B005 row. Another agent's unrelated lease was not overridden.

## Changed Files
- Created during this lifecycle: this report artifact and exact registered child pages `by-memory/0x004d1f30-0x004d1f99.ObjectStatusBlobParseTaggedStatus.md`, `by-memory/0x004d1fa0-0x004d2637.ObjectStatusBlobParseFullStatus.md`, and `by-memory/0x004d2640-0x004d2697.ObjectStatusBlobParsePartialStatus.md`.
- Modified target/core pages: `by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md`; `by-class/ObjectStatusBlob.md`; `by-file/ObjectStatusBlob.md`; `by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md`; `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`; `by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md`; `by-class/SelfLookPane.md`; `by-memory/0x0056a500-0x0056a63e.SelfLookPaneRectUpdateRawHelpers.md`.
- Modified look/profile support: `by-memory/0x00572b60-0x00572f25.SelfLookPane2LookUpdateRawHelpers.md`; `by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md`; `by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md`; `by-class/UserLookPane.md`; `by-class/ProfilePane.md`; `by-file/UserLookPane.md`.
- Modified Map/ObjectImage support: `by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md`; `by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md`; `by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md`; `by-class/MapPane.md`; `by-file/MapPane.md`; `by-memory/0x00520540-0x00520816.ObjectImageControlPane.md`; `by-class/ObjectImageControlPane.md`; `by-file/ObjectImageControlPane.md`.
- Modified NewHuman/MetaMan/PacketBuffer/global support: `by-class/NewHumanImageLib.md`; `by-type/by-struct/NewHumanImageLibLayout.md`; `by-file/NewHumanImageLib.md`; `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`; `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md`; `by-class/MetaMan.md`; `by-file/MetaMan.md`; `by-global/g_pMetaMan.md`; `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md`; `by-item/PacketBufferHelpers.md`; `by-file/PacketBuffer.md`; `by-global/g_useEpfAssets.md`; `by-global/g_pNewHumanImageLib.md`.
- Modified report artifact: `tools/leaser/Agents/Agent-B005/research/000179-ObjectStatusBlobParsers-source-quality.md` with current callback ledger, validator/generated proof, changed files, and completed checklist.
- Renamed: none.
- Validator-owned side effects only: `tools/validator.ini`, validator reference/projected-stat indexes, generated source/metadata, and generated coverage described above. B005 did not manually edit those files and ran no report execution/lifecycle/move/archive command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 acceptance recorded by exact pre-callback SHA.
- [x] Target/support scope completed: UID000179; three serially registered children; UID00009S; UID0000M6; UID00017A; Destinations 6-9; every exact prose support page listed above.
- [x] Current target state and every MCP/resource/generated/doc evidence fact retained and reconciled.
- [x] C01-C33 ledger updated claim by claim with implementation and proof state.
- [x] Scores applied: parent `92/93`; children `92/94`, `91/93`, `92/94`; class `92/93`; file `90/91`; all other scores preserved.
- [x] Score blockers resolved and naming-only caps retained below 95.
- [x] Owner/emitter/reconstructable state applied exactly; class/file route preserved.
- [x] Children allocated/registered serially as UID0004LK/UID0004LL/UID0004LM before references; no guessed UID or target rename; raw successors excluded.
- [x] Exact source placement, ranges, padding, cumulative nesting, and no-IDA-mutation disposition applied.
- [x] Literal Destinations 1-9 applied; exact managed destination count 9; post-callback block comparison true for all nine.
- [x] Third-party import confirmed not applicable; no import directive.
- [x] Complete field/read/write/caller/global/callee/resource/normalization/source/support detail incorporated without compression.
- [x] Historical title/profile/generic-remap/static/free/aggregate/raw-successor/ownership rejections preserved and labeled superseded.
- [x] Wave2/Wave3 references remain historical-only and non-authoritative.
- [x] Open questions retain exact naming-only/source-folder caps; no behavior or C++ blocker remains.
- [x] Scoped validators recorded for every final changed by-* page; UID0002QN consistency and ProfilePane/PacketBufferHelpers ASCII corrective revalidations recorded; leases released immediately.
- [x] Final waited generated refresh and ObjectStatusBlob/HeadSelectDialog/MessageDialogs/SelfLookPane/non-emitting-parent checks completed read-only; no manual generated/tracker/coverage edit.

Implementation callback pass:
- [x] Exact accepted callback scope applied to the same report.
- [x] All target/support details incorporated at report-level detail.
- [x] C01-C33 ledger completed with claim-specific proof.
- [x] Metadata/score/owner/emitter/split/nesting/C++ changes applied exactly; no rename required.
- [x] Historical assumptions, rejected alternatives, predecessor/internal padding, raw-successor exclusion, and negative evidence preserved.
- [x] Open questions resolved or retained only as evidence-backed naming/source-history confidence caps.
- [x] Registration/scoped/final-refresh command ids, timestamps, exit/ok, warnings, side effects, and lease release recorded.
- [x] Generated refresh and exact read-only source checks completed.
- [x] Remaining unapplied accepted items: none. External report lifecycle state is supervisor-owned, not pending B005 report work.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000009807","destination_path":"executed-b-agent-research/B005/000179-ObjectStatusBlobParsers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/000179-ObjectStatusBlobParsers-source-quality.md","timestamp":"2026-07-13T11:41:55-04:00","uid":"000179"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
