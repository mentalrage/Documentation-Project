** TARGET-REPORT-UID:000245 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000245 StlTreeStringMapSupport Source Routing

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000245] `0x00578f70-0x005797ae.StlTreeStringMapSupport` non-emitting and no-owner, but revise the page because the current "pure STL helper island" wording is overbroad.
- Final disposition: mixed compiler/runtime support tail. The STL/Dinkumware wide-string tree helpers are real, non-source library/template output, but the half-open range also contains existing exact child [UID:0001I6] `ClearPacketSenderGlobal`, the Socket scalar deleting destructor at `0x005795a0-0x005796c7`, and a CRT stdout wide formatted-output wrapper at `0x00579780-0x005797ae`.
- Required action: update the target with an exact function inventory, caller spread, node layout, standard-STL inference, generated-name rejection, and no-code proof. Add or update support docs so later source reconstruction models owner containers in Socket/FriendNameListSync and VirusChecker rather than porting this helper island.
- Score recommendation after target-only documentation repair: `84/88 -> 86/90`.
- Score cap: keep the current full-range page capped at `86/90` until the non-STL children are split or explicitly documented in exact child pages. If the Socket scalar deleting destructor and stdout wrapper receive exact pages and this target is reframed as a reviewed mixed container, `88/91` is the practical cap. It should not become source-bearing.
- Metadata recommendation:
  - `CANONICAL_OWNER:NONE` stays unchanged.
  - `RECONSTRUCTABLE:FALSE` stays unchanged.
  - `EMITTER_UIDS:` stays blank.
  - `RECONSTRUCTION_CPP CODE` stays blank.
- Confidence: high for physical bounds, function identities, caller spread, 0x14-byte node layout, and no-code routing. Remaining uncertainty is original source typedef spelling for the string container and whether the STL helper subranges should stay under this full filename or be split into narrower exact support pages.

## Target Paths

- Target UID: `000245`
- Target by-memory path: `source-3/project-documentation/by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/000245-StlTreeStringMapSupport-source-routing.md`
- Parent aggregate currently containing the range: [UID:0001I1] `source-3/project-documentation/by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`
- Existing exact child inside the range: [UID:0001I6] `source-3/project-documentation/by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md`
- Important related pages:
  - [UID:0001HX] `source-3/project-documentation/by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md`
  - [UID:0001HT] `source-3/project-documentation/by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md`
  - [UID:0001NU] `source-3/project-documentation/by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`
  - [UID:0001NW] `source-3/project-documentation/by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`
  - [UID:00026H] `source-3/project-documentation/by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md`
  - [UID:00026G] `source-3/project-documentation/by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md`
  - [UID:0001QA] `source-3/project-documentation/by-meta/client_containers.md`

## Evidence Checked

- Read the current target page [UID:000245] `0x00578f70-0x005797ae.StlTreeStringMapSupport.md`.
- Read B-agent rules, `.codex/AGENTS.md`, `Agent-B012/goal.md`, `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Read related support docs listed above, plus [UID:0000NS] `Socket`, [UID:0000I0] `CashShopRequest`, [UID:0000P5] `VirusChecker`, [UID:0001I8] `SoundManagerAudioHelperCluster`, [UID:000243] through [UID:000244] Socket/PacketBuffer neighbors, [UID:0001I0] `PacketNonceInitialization`, and the executed B001 packet-name-table report.
- Checked generated and coverage state:
  - `by-memory/-coverage-report.md` current [UID:000245] row.
  - `by-memory/-ignored.md` current `0x00578f70-0x005797ae` and `0x005797ae-0x005797b0` entries.
  - `by-meta/client_containers.md` current [UID:000245] summary.
  - `tools/leaser/Agents/Agent-C001/notes.md` prior barrier repair notes.
- Checked local function exports under:
  - `hooks-generation/tests/function_data/ida/*.json`
  - `hooks-generation/tests/function_data/ghidra/*.json`
  - `hooks-generation/tests/function_data/combined/functions/*.json`
  - `resources/exported_data/functions/*.json`
- Ran a local raw PE scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` to verify section mapping, bytes, padding, function half-open bounds, rel32 call/jump targets, and absolute VA/RVA hits.
- Checked IDA MCP availability on 2026-06-19. It was unavailable: `Unable to connect to the remote server`. This report therefore relies on local PE bytes plus checked-in IDA/Ghidra exports, not live MCP output.
- Ran `int_convert.py` for numeric constants used in the conclusions:
  - `0x14` = 20 (Verified with `int_convert.py`).
  - `0x101` = 257 (Verified with `int_convert.py`).
  - `0x7e` = 126 (Verified with `int_convert.py`).
  - `0x73` = 115 (Verified with `int_convert.py`).
  - `0x0ccccccb` = 214748363 (Verified with `int_convert.py`).

## Boundary And Function Inventory

The current target is physically bounded correctly as a container, but its body table is incomplete and its classification is too broad.

| Half-open range | Classification | Evidence and source-routing conclusion |
| --- | --- | --- |
| `0x00578f6c-0x00578f70` | predecessor boundary | End of the raw packet logger body is `ret 8` plus one `0xcc`; not part of [UID:000245]. |
| `0x00578f70-0x00578fea` | STL value-node create helper | Allocates a 0x14-byte tree node, zeroes the color/nil word, constructs/copies the string payload at `node + 0x10`, and has EH cleanup through `0x00579760`. No handwritten project source. |
| `0x00578fea-0x00578ff0` | padding | Six `0xcc` bytes. |
| `0x00578ff0-0x00579144` | STL tree insert/rebalance helper | Calls `0x00578f70`, performs red-black rotations, and guards max size at `0x0ccccccb` / 214748363 (Verified with `int_convert.py`) with the `"map/set<T> too long"` throw path. Missing from the current target table. |
| `0x00579144-0x00579150` | padding | Twelve `0xcc` bytes. |
| `0x00579150-0x005792f8` | STL insert-with-hint / emplace dispatcher | Called from the friend-name send helper at `0x00575017` and `0x005751c7`; calls comparator `0x00579540`, lower-bound/insert helper `0x00579300`, and insert/rebalance `0x00578ff0`. Missing from the current target table. |
| `0x005792f8-0x00579300` | padding | Eight `0xcc` bytes. |
| `0x00579300-0x005794b4` | STL lower-bound / unique insert helper | Uses string length/compare helpers, then inserts through `0x00578ff0`; catch label at `0x005794ab` is EH-internal, not a child function. Missing from the current target table. |
| `0x005794b4-0x005794c0` | padding | Twelve `0xcc` bytes. |
| `0x005794c0-0x005794cb` | [UID:0001I6] `ClearPacketSenderGlobal` | Exact child already exists. Body is `g_packetSender = 0; return;` reached from Socket constructor unwind at `0x0060805e`. This is not STL and should not be described as part of the STL helper island. |
| `0x005794cb-0x005794d0` | padding | Five `0xcc` bytes. |
| `0x005794d0-0x00579539` | STL tree tidy/free-header helper | Recursively destroys nodes via `0x00579710`, resets header links/count, and frees the header. Correctly listed but should be tied to STL tree cleanup, not Socket source. |
| `0x00579539-0x00579540` | padding | Seven `0xcc` bytes. |
| `0x00579540-0x00579591` | wide-string less-than comparator | Six direct calls from `0x00579150`; compares the string payload through the local string helpers. Current page labels it only loosely. |
| `0x00579591-0x005795a0` | padding | Fifteen `0xcc` bytes. |
| `0x005795a0-0x005796c7` | Socket scalar deleting destructor | Data xref from Socket vtable slot `0x00624f20`; calls Socket transport cleanup, `closesocket`, transform/key frees, base `Thread` destructor, `OperatorDeleteWrapper`, and clears `g_packetSender`. This is not STL and lacks an exact standalone by-memory child. |
| `0x005796c7-0x005796d0` | padding | Nine `0xcc` bytes, previously checked by C001. |
| `0x005796d0-0x005796e9` | STL header/sentinel allocator | Allocates 0x14 / 20 bytes (Verified with `int_convert.py`), self-links left/parent/right, and stores `0x0101` / 257 (Verified with `int_convert.py`) across the color/nil bytes. |
| `0x005796e9-0x005796f0` | padding | Seven `0xcc` bytes. |
| `0x005796f0-0x0057970d` | STL node-shell allocator | Allocates a 0x14-byte node and copies header links; shared by this island and VirusChecker helper code. |
| `0x0057970d-0x00579710` | padding | Three `0xcc` bytes. |
| `0x00579710-0x00579751` | STL recursive node erase helper | Recurses on children until nil/header flag, destroys the string at `node + 0x10`, and frees the node. |
| `0x00579751-0x00579760` | padding | Fifteen `0xcc` bytes. |
| `0x00579760-0x00579774` | STL single-node free helper | Frees one 0x14-byte node; used by local EH cleanup and VirusChecker node-allocation failure cleanup. |
| `0x00579774-0x00579780` | padding | Twelve `0xcc` bytes. |
| `0x00579780-0x005797ae` | CRT stdout wide formatted-output wrapper | Calls `__acrt_iob_func(1)`, `0x0041b9a0`, and common backend `0x005d2208`; only local call found is the retained raw packet logger at `0x00578f63`. This is CRT/runtime output support, not STL tree support. |
| `0x005797ae-0x005797b0` | successor padding | Two `0xcc` bytes before [UID:0001I8] `SoundManagerAudioHelperCluster`. |

## Direct Caller And Xref Spread

- `0x00578f70`: one direct local call from `0x00579008` in the insert/rebalance helper.
- `0x00578ff0`: calls from `0x005791a1` and `0x00579412`, both inside the same STL insertion family.
- `0x00579150`: direct calls from `0x00575017` and `0x005751c7` in [UID:0001HX] `BuildAndSendFriendNameListSync`.
- `0x00579300`: direct call from `0x005792cf` inside `0x00579150`.
- `0x005794c0`: one jump/call from `0x0060805e`, a Socket constructor-unwind cleanup path already documented by [UID:0001I6].
- `0x005794d0`: two EH/unwind jumps from `0x006080a9` and `0x006080b4`, tied to cleanup after the friend-name set construction/use path.
- `0x00579540`: six calls from `0x00579150`, all comparator use inside STL tree insertion.
- `0x005795a0`: no rel32 calls were found; one absolute data hit is the Socket vtable slot at `0x00624f20`.
- `0x005796d0`: calls from the friend-name helper at `0x00574eb3` and `0x00575077`, and from the VirusChecker constructor at `0x005c04c6`.
- `0x005796f0`: calls from `0x00578f9e` and VirusChecker tree-node construction at `0x005c0aee`.
- `0x00579710`: calls from friend-name cleanup at `0x005752c7` and `0x00575316`, from `0x005794d0`, and recursively from itself.
- `0x00579760`: calls from local EH cleanup at `0x00578fdc` and VirusChecker cleanup at `0x005c0b2c`.
- `0x00579780`: direct call from raw no-function packet logger `0x00578f30-0x00578f6c`.

I did not find direct EventDispatcher calls into this exact island. The current target page's EventDispatcher caller lead appears to be generated/template pollution from a separate tree-helper family and should be removed or softened until a concrete xref is documented.

## Node Layout And Container Type Inference

The STL helper subset uses a 0x14-byte node:

| Offset | Meaning | Evidence |
| --- | --- | --- |
| `+0x00` | left child / leftmost link | Header allocator self-links this field; insertion/erase traverses it. |
| `+0x04` | parent / root/header link | Header allocator self-links this field; insertion/rebalance uses it as parent/root. |
| `+0x08` | right child / rightmost link | Header allocator self-links this field; insertion/erase traverses it. |
| `+0x0c` | color byte | Header stores `0x0101`; value nodes zero this word; rebalance writes root black. |
| `+0x0d` | nil/header flag byte | Recursive cleanup stops on the nil/header marker. |
| `+0x0e` | padding/unused byte pair remainder | Written as part of the `WORD` at `+0x0c`; no source payload seen. |
| `+0x10` | value payload | A 4-byte `SimpleUString`/`LObject`-style string handle constructed/destructed by adjacent string helpers. |

The tree object visible to the helpers is a two-word wrapper:

- `tree + 0x00`: header/sentinel pointer.
- `tree + 0x04`: node count.

Best container inference: MSVC/Dinkumware `std::_Tree` support for a wide-string ordered set, likely source-level `std::set<SimpleUString>` or a typedef over the project's string wrapper. "String map" is not proven for this exact island because the node payload visible here is only a single 4-byte string object at `+0x10`; no paired mapped value was observed. Keep `std::map` wording only as a possible generated-family label, not as the preferred source shape for these callers.

Standard STL versus project wrapper:

- Strong standard-STL evidence: red-black tree header/sentinel shape, color/nil bytes, `map/set<T> too long` throw string, max-size guard `0x0ccccccb`, insert/rebalance helper pattern, and cross-module template-helper reuse.
- Project wrapper evidence: weak. The source may have used a local typedef or project string class, but no central project tree class, vtable, owned source file, or hand-authored wrapper body was found.
- Best wording: "MSVC/Dinkumware wide-string ordered tree/set helpers emitted from owning source containers."

## Ownership And Source-Routing Analysis

Do not assign [UID:000245] to a source owner or emitter. The correct source reconstruction path is owner containers and ordinary compiler/runtime output:

- [UID:0001HX] `BuildAndSendFriendNameListSync`: reconstruct as a temporary ordered string set used to deduplicate/prepare friend-name strings before the send/queue path. This helper is currently documented through the CashShopRequest send-queue page for historical reasons, but current Socket docs route the low-level send/network behavior to Socket. Do not let the generated `CashShopRequest` helper name become a source module owner for the STL helpers.
- [UID:0001NU] and [UID:0001NW] `VirusChecker`: reconstruct the process/module path tracking as an owning container in VirusChecker. This island supplies shared allocation/free routines; VirusChecker also has local tree helper bodies at `0x005c0b40+`, so the full tree behavior is not centralized here.
- [UID:0001I6] `ClearPacketSenderGlobal`: keep as the existing exact Socket cleanup child. It is source-facing Socket lifetime behavior, not STL.
- `0x005795a0-0x005796c7`: route to Socket as a scalar deleting destructor exact child or Socket destructor support note. It is not part of the STL target even though it lies inside the current file range.
- `0x00579780-0x005797ae`: route as CRT/stdout formatted-output wrapper support. Its only observed local caller is the raw packet logger tied to [UID:00026H] `ServerPacketNameTable`, but the wrapper body itself should remain runtime/no-code.

Rejected alternatives:

- Standalone source file `StlTreeStringMapSupport.cpp`: rejected. The helpers are library/template output generated from real source containers.
- Central project-owned tree wrapper: rejected as unproven. No class/vtable/global owner evidence was found.
- Pure Socket-owned handwritten code: rejected. Physical placement in the Socket neighborhood is not ownership evidence, and direct helper callers cross Socket/FriendNameListSync and VirusChecker.
- Pure STL helper page for the full `0x00578f70-0x005797ae` range: rejected. The exact range includes a Socket cleanup child, Socket scalar deleting destructor, and CRT stdout wrapper.
- EventDispatcher ownership: rejected for this exact target until a direct xref into this island is shown.

## Generated-Name And Template Pollution

Treat these as descriptive labels only, not original source names:

- `sub_578F70`, `meth_0x578f70`, and `cls_0x436260` OOAnalyzer class labels.
- `CreateTreeSentinelNode_5796D0`, `WideStringMap_436260::DestroyNodes_579710`, and similar generated helper names.
- Historical `CashShopRequest` ownership for the friend-name helper path.
- The target title phrase "string map" if it implies a proven source `std::map`; "ordered string set/tree" is better supported.
- Ghidra `Catch_All@00578fd6`, `Catch_All@005792ef`, and `Catch_All@005794ab` labels. They are EH internal fragments within the IDA-modeled function bodies, not standalone children.

Useful documentation/IDA descriptive names, if comments are desired:

| Address | Suggested descriptive name | Confidence |
| --- | --- | --- |
| `0x00578f70` | `StlWideStringTreeCreateValueNode` | high as descriptive, low as original symbol |
| `0x00578ff0` | `StlWideStringTreeInsertRebalance` | high as descriptive |
| `0x00579150` | `StlWideStringTreeInsertWithHint` | medium-high; exact STL internal name not proven |
| `0x00579300` | `StlWideStringTreeLowerBoundOrInsertUnique` | medium-high |
| `0x005794c0` | `ClearPacketSenderGlobal` | high; exact child already uses it |
| `0x005794d0` | `StlWideStringTreeTidyAndFreeHeader` | high as descriptive |
| `0x00579540` | `WideStringTreeLessThan` | high as descriptive |
| `0x005795a0` | `SocketScalarDeletingDestructor` | high |
| `0x005796d0` | `StlWideStringTreeAllocateHeader` | high as descriptive |
| `0x005796f0` | `StlWideStringTreeAllocateNodeShell` | high as descriptive |
| `0x00579710` | `StlWideStringTreeEraseNodes` | high as descriptive |
| `0x00579760` | `StlWideStringTreeFreeNode` | high as descriptive |
| `0x00579780` | `CrtStdoutWidePrintfWrapper` | high as descriptive |

Do not apply source-owner comments that imply these STL helper names are original NexusTK functions.

## Missing Exact Children Or Support Docs

Required or strongly recommended before considering the area complete:

- Add an exact child or exact routing note for `0x005795a0-0x005796c7.SocketScalarDeletingDestructor`. It is referenced by Socket vtable `0x00624f20`, not by STL callers. A future B pass may decide whether this is a no-code scalar deleting destructor wrapper or whether ordinary Socket destructor semantics need a source-bearing page, but it should not remain hidden inside `StlTreeStringMapSupport`.
- Add an exact ignored child/page or at least a target/support-doc row for `0x00579780-0x005797ae.CrtStdoutWidePrintfWrapper`. It matches the sibling [UID:0001JL] PhoneBook formatted-output wrapper family and is not tree support.
- Keep [UID:0001I6] `0x005794c0-0x005794cb.ClearPacketSenderGlobal` as an exact child; target [UID:000245] should explicitly exclude it from STL ownership.
- Update [UID:0001I1] `SocketTransportCore` so the row `0x00578f70-0x005797ae` is a mixed support tail or a set of exact subrows, not one STL/string-map support block.
- Update [UID:0001QA] `client_containers` to say the STL helper subranges are standard-library generated helpers inside a mixed tail and that owner code should use standard containers or project typedefs.
- Update [UID:00026H] `ServerPacketNameTable` and related packet logger wording to call `0x00579780` a CRT/stdout wide formatted-output wrapper, not an STL diagnostic helper.
- Update [UID:0001HX] and [UID:0001HT] with precise helper roles for the friend-name set path, and avoid treating generated CashShopRequest names as final source ownership if Socket/social-send ownership remains preferred.
- Update [UID:0001NU] and [UID:0001NW] to record that `0x005796d0`, `0x005796f0`, and `0x00579760` are shared Dinkumware-style tree allocation/free helpers, while VirusChecker's local tree helpers still own VirusChecker-specific behavior.

Optional split path:

- Split the STL support into narrower exact pages if supervisor wants cleaner coverage:
  - `0x00578f70-0x005794b4.StlWideStringTreeInsertHelpers.md`
  - `0x005794d0-0x00579591.StlWideStringTreeClearAndCompareHelpers.md`
  - `0x005796d0-0x00579774.StlWideStringTreeAllocationCleanupHelpers.md`
  - `0x00579780-0x005797ae.CrtStdoutWidePrintfWrapper.md`
  - `0x005795a0-0x005796c7.SocketScalarDeletingDestructor.md`
- If split, the current full-range [UID:000245] can become a non-emitting mixed support-tail index or be narrowed/renamed by the supervisor. Do not leave the full file title implying only STL after the split.

## Exact No-Code Proof

[UID:000245] should remain `RECONSTRUCTABLE:FALSE` with blank formal C++:

- The source-level construct for the STL subranges is ordinary container declaration/use in owners, not a handwritten function body.
- The helper bodies are compiler/STL output: red-black insertion, comparator dispatch, header allocation, node recursion/free, and exception cleanup.
- The only source-relevant behavior for the friend-name path is the use of an ordered unique string container while building/sending the friend-name list.
- The only source-relevant behavior for VirusChecker is use of an ordered path/string container while tracking process/module paths.
- `0x005794c0` source effect is already covered by [UID:0001I6] Socket constructor-unwind cleanup, not by the target.
- `0x005795a0` is ABI destructor glue for Socket and should be handled through Socket destructor/source docs, not emitted here.
- `0x00579780` is a CRT stdout wrapper and should be regenerated by toolchain/runtime or replaced by normal source formatted output at its owner use site, not ported into NexusTK source.
- The `0xcc` gaps and `0x005797ae-0x005797b0` are linker/compiler alignment bytes.

No first-draft C++ should be added to this target. The highest-quality source guidance is prose: owners should express `std::set<SimpleUString>`-style containers or the project typedef that compiles to equivalent Dinkumware tree code.

## Recommended Exact Target Changes

For `by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md`:

- Change the title or summary to acknowledge this is a mixed support tail unless the page is split. Suggested title if filename is retained: `0x00578f70-0x005797ae STL Tree / Socket / CRT Support Tail`.
- Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank C++.
- Change completion/confidence to `86/90` after the evidence is incorporated.
- Replace "Entity kind: MSVC STL/Dinkumware tree/string template support" with "Entity kind: mixed non-emitting support tail; STL/Dinkumware wide-string tree helpers plus exact Socket/runtime children."
- Replace the current covered-range table with the exact function/padding inventory from this report.
- Add the node layout table from this report.
- Add direct caller/xref spread and explicitly reject EventDispatcher as unconfirmed for this exact island.
- Replace "string-map" wording with "wide-string ordered tree/set helpers" unless a mapped payload is later proven.
- Add the standard-STL versus project-wrapper inference: standard Dinkumware `std::_Tree` helper output is strongly supported; central project tree wrapper is not.
- Add missing-child notes for Socket scalar deleting destructor and CRT stdout wrapper.
- Replace open questions so they do not passively block:
  - Original container typedef spelling remains open, but best direction is `std::set<SimpleUString>` or project typedef over it.
  - Exact child split remains a documentation-routing choice, not a blocker for no-code status.

For `by-memory/0x00575d90-0x005797ae.SocketTransportCore.md`:

- Replace the single `0x00578f70-0x005797ae` "STL tree/string-map support" row with a mixed-tail summary or exact subrows.
- Add that `0x005795a0-0x005796c7` is the Socket scalar deleting destructor via `0x00624f20`, and `0x00579780-0x005797ae` is a CRT/stdout output wrapper.
- Keep the aggregate endpoint at `0x005797ae`; the boundary repair remains valid.

For `by-meta/client_containers.md`:

- Replace the current line with:

```text
- [UID:000245][0x00578f70-0x005797ae.StlTreeStringMapSupport](by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md) covers the STL/Dinkumware wide-string ordered-tree helper subranges inside a mixed Socket/STL/runtime support tail; reconstruct owner containers in Socket/FriendNameListSync and VirusChecker, and do not port the generated tree helper bodies, Socket scalar deleting destructor, or CRT stdout wrapper as a standalone project module.
```

For `by-memory/-ignored.md`, replace the current broad `0x00578f70-0x005797ae` entry with entries like:

```text
- `0x00578f70-0x005794b4`, `0x005794d0-0x00579591`, and `0x005796d0-0x00579774` - MSVC/Dinkumware wide-string ordered-tree helpers.
  - Why ignored: generated STL tree allocation, insertion, comparison, cleanup, and node-free helper bodies emitted from owner source containers; not handwritten NexusTK code.
  - Evidence: B012 2026-06-19 raw PE/local IDA-Ghidra export recheck confirms exact helper boundaries, 0x14-byte node/header allocation, color/nil bytes at `+0x0c/+0x0d`, string payload construction/destruction at `+0x10`, `map/set<T> too long` guard, friend-name and VirusChecker caller spread, and no direct EventDispatcher xrefs into this exact island.
  - Replacement/procurement: reconstruct owner containers in Socket/FriendNameListSync and VirusChecker, likely `std::set<SimpleUString>` or a project typedef over that shape; let the selected MSVC-compatible STL/runtime regenerate helper output.
  - Owner docs: [UID:000245][0x00578f70-0x005797ae.StlTreeStringMapSupport](by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md), [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md), [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md), and [UID:0001QA][client_containers](by-meta/client_containers.md).

- `0x00579780-0x005797ae` - CRT/stdout wide formatted-output wrapper.
  - Why ignored: MSVC/UCRT-style stdout formatter wrapper, not STL tree support or handwritten packet logging logic.
  - Evidence: B012 2026-06-19 raw PE/local export recheck shows calls to `__acrt_iob_func(1)`, local stdio option helper `0x0041b9a0`, and common formatted-output backend `0x005d2208`; the only observed local caller is the retained no-function raw packet logger at `0x00578f30`.
  - Replacement/procurement: regenerated by CRT/toolchain or expressed through normal formatted output at the owner call site; do not create handwritten NexusTK source for this wrapper.
  - Owner docs: [UID:000245][0x00578f70-0x005797ae.StlTreeStringMapSupport](by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md), [UID:00026H][0x00625008-0x0062ce50.ServerPacketNameTable](by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md), and [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md).
```

Do not include `0x005794c0-0x005794cb` or `0x005795a0-0x005796c7` in the ignored STL entry. `0x005794c0` is an exact reconstructable child, and `0x005795a0` needs a Socket scalar deleting destructor routing decision.

For `by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md`:

- Keep the raw logger source policy unchanged.
- Change the helper wording from "diagnostic/output helper" only if desired to "CRT/stdout wide formatted-output wrapper at `0x00579780`." Do not call it STL.

For Socket and Socket read-only data docs:

- Add a pending exact-child note that `0x005795a0-0x005796c7` is the Socket scalar deleting destructor selected by vtable slot `0x00624f20`. The ordinary source semantics should route through Socket destructor/lifecycle docs, not [UID:000245].

## Exact Coverage-Report Replacement Row

Do not edit `by-memory/-coverage-report.md` in this phase. If the supervisor applies the target-only documentation repair without immediately splitting children, replace the existing [UID:000245] row with:

```text
    - [UID:000245][0x00578f70-0x005797ae.StlTreeStringMapSupport](by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md) 0x00578f70-0x005797ae | mixed STL tree / Socket destructor / CRT output support tail | StlTreeStringMapSupport : ignored : 86% : very-strong : B012 2026-06-19 raw PE/local IDA-Ghidra export recheck confirms the current range is not a pure STL island: STL/Dinkumware wide-string ordered-tree helpers occupy `0x00578f70-0x005794b4`, `0x005794d0-0x00579591`, and `0x005796d0-0x00579774`; exact child [UID:0001I6] `0x005794c0-0x005794cb` is Socket constructor-unwind `g_packetSender` cleanup; `0x005795a0-0x005796c7` is the Socket scalar deleting destructor via vtable slot `0x00624f20`; `0x00579780-0x005797ae` is a CRT/stdout wide formatted-output wrapper reached from the retained raw packet logger at `0x00578f30`; all internal gaps are `0xcc` padding and `0x005797ae-0x005797b0` is final boundary padding. Keep this container no-owner/non-emitting/no-code, reconstruct owner behavior through Socket/FriendNameListSync and VirusChecker containers, and add/split exact support docs before treating the full filename as a pure STL helper.
```

If the supervisor creates new exact child pages before refreshing coverage, assign real UIDs through the validator first, then add separate rows for `SocketScalarDeletingDestructor` and `CrtStdoutWidePrintfWrapper`. I cannot provide exact final UID-bearing rows for those new pages until the UID allocator creates them.

## Future Implementation Checklist

1. Lease and edit only the supervisor-approved target/support docs.
2. Update [UID:000245] with the inventory, node layout, caller spread, generated-name rejection, no-code proof, and `86/90` score.
3. Update `by-memory/-ignored.md` broad entry as described above, excluding [UID:0001I6] and the Socket scalar deleting destructor.
4. Update `by-meta/client_containers.md`, [UID:0001I1] `SocketTransportCore`, [UID:00026H] `ServerPacketNameTable`, and owner docs for Socket/FriendNameListSync and VirusChecker.
5. Decide whether to create exact children for `0x005795a0-0x005796c7` and `0x00579780-0x005797ae`. If yes, validate and refresh UID links before coverage rows.
6. Do not edit `by-memory/-coverage-report.md` outside supervisor-owned coverage workflow.
7. Run validators and memory range report.

## Validation Commands Needed After Implementation

Run the relevant subset for files the supervisor actually edits:

> Executable block R001 was removed from this report and preserved verbatim in [000245-StlTreeStringMapSupport-source-routing-removed.md](000245-StlTreeStringMapSupport-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If new exact child pages are created, also validate them explicitly, for example:

> Executable block R002 was removed from this report and preserved verbatim in [000245-StlTreeStringMapSupport-source-routing-removed.md](000245-StlTreeStringMapSupport-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename / Type / Comment Recommendations

No required IDA database edit for this report-only phase.

Optional comments or descriptive names, if a later IDA cleanup pass is authorized:

- Mark `0x00578fd6`, `0x005792ef`, and `0x005794ab` as EH internal catch fragments, not functions.
- Rename/comment `sub_5795A0` as `SocketScalarDeletingDestructor` and add a comment that vtable `0x00624f20` is the data xref.
- Rename/comment `sub_579780` as `CrtStdoutWidePrintfWrapper`.
- Add comments to STL helper bodies saying "Dinkumware/MSVC tree support, generated from owner containers; not source-emitting."
- Avoid original-symbol-looking names for the STL helpers unless PDB/source evidence appears.

## Changed Files

- Created report only: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/000245-StlTreeStringMapSupport-source-routing.md`
- Did not edit target by-memory docs.
- Did not edit support docs.
- Did not edit `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/000245-StlTreeStringMapSupport-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"000245"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000245-StlTreeStringMapSupport-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/000245-StlTreeStringMapSupport-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000245"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
