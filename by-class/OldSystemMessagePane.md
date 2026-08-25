*** UID:00009T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// OldSystemMessagePane belongs to social/SystemMessagePanes.cpp, but the class
// declaration is intentionally withheld here. MCP confirms constructor ownership
// at 0x00588e30, caller 0x004f8861, singleton publication, vtable installs,
// resource/tile setup, message-entry seeding, exact vtable child [UID:0003DM][0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData](by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md),
// and destructor cleanup. A declaration shell would have to invent the scrollable
// base ABI, adjusted-base layout, and ten tile-context member declarations.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OldSystemMessagePane

## Status

- Confidence: strong for class role, live constructor caller, method boundaries, vtable ownership, singleton lifecycle, and destructor support; medium-high for final field/helper names.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Vtable data: [UID:0003DM][0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData](by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md)
- Reconstruction disposition: document and model the class, but do not emit final C++ until the field layout and helper names meet the project bar.
- Parent range disposition: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) is a non-emitting executable split index. This class page, not the broad parent, carries the `OldSystemMessagePane` constructor/destructor/message-list/source-placement evidence.

## Class Purpose

`OldSystemMessagePane` is the legacy scrollable system-message pane. It manages a message collection, fixed 12-pixel line metrics, separator/header drawing, help shortcut handling, and destruction of message entries plus ten tile contexts.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00588e30-0x00589173` | `OldSystemMessagePane::OldSystemMessagePane()` | Constructor called by the legacy main UI graph path; stores the old system-message singleton, installs three vtables, initializes tile contexts, and seeds starter message entries. |
| `0x00589180-0x0058948f` | Message-list support helpers, including `AppendHeaderMarker`, `AppendColoredText`, `AppendFooterMarker`, and refresh/prune paths | Clears singleton/instance state and handles message-entry insertion/update paths used by system-message and old-mode callers. The helper names are source-facing/descriptive until exact original symbols are recovered. |
| `0x00589540-0x00589668` | Scroll metric helpers | Six vtable-backed helpers for range/overflow/page size/scroll offset/content size and canonical `GetScrollDelta` at `0x00589630`, which writes y=`12*(old-new)` for vertical axis and x zero. |
| `0x00589670-0x005896c0` | `HandleHelpShortcut` | Handles the Ctrl+`?` shortcut and calls `OldSystemMessagePane::LoadHelpMessages` only at `0x005896ab`. |
| `0x005896c0-0x005898f3` | Vtable-backed input/scroll helper | Legacy system-message helper reached through the secondary vtable. |
| `0x00589920-0x00589c0c` | `OnDraw` | Paints message entries, separators, and clipped text rows. |
| `0x00589c80-0x00589cea` | `GetTotalLineCount` | Sums message-entry line counts; called by scroll metric helpers. |
| `0x00589d30-0x0058a230` | `OldSystemMessagePane::LoadHelpMessages` | Passes direct `L"HELP.RES"` to `HasDATEntry` at `0x00589d9e` and `DATFile::Open` at `0x00589dcf`; when absent, fills file-static `s_oldSystemMessageHelpMessages[60]` from the validated localization map with five `initialText` separators, then appends header/color/footer entries. The literal is compiler-pooled with the parallel current-pane uses rather than defined as a class/static object. |
| `0x0058ab1d-0x0058ab33` | Adjustor/thunk helpers | Two vtable-referenced destructor adjustor thunks to `0x0058adb0`. |
| `0x0058adb0-0x0058af00` | `~OldSystemMessagePane(int deleteFlags)` | Destroys message collection, tile contexts, and base scrollable pane state. |

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` confirms `0x00588e30-0x00589173` for the constructor, `0x00589540-0x00589668` for the six scroll metric helpers, `0x00589670-0x005896c0` for the help shortcut handler, `0x005896c0-0x005898f3` for a secondary-vtable helper, `0x00589920-0x00589c0c` for drawing, `0x00589c80-0x00589cea` for total line counting, two `0xb` destructor adjustor thunks at `0x0058ab1d` and `0x0058ab28`, and `0x0058adb0-0x0058af00` for the scalar deleting destructor body.
- `xrefs_to 0x00588e30` reports a direct constructor caller at `0x004f8861` inside [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md), immediately after a `0x26c` allocation.
- Constructor disassembly writes [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) slot `0x0069b4c8` at `0x00588e7c` and clears it on the null-adjusted path at `0x00588e83`.
- Constructor and destructor disassembly install the `OldSystemMessagePane` primary and adjusted vtables at `this+0x00`, `this+0xa0`, and `this+0xa4`; the live vtable data refs are `0x0062d8c8`, `0x0062d93c`, and `0x0062d96c`.
- Constructor callsites include the `ScrollablePane` base constructor at `0x0055e660`, ten `EPFTileContext` constructor calls at `0x00457a60`, ten resource-layout/tile copy calls at `0x004d04d0` using `off_62D974`, and starter message-entry setup through `LObject`/system-message entry helpers around `0x00516030`, `0x00516050`, `0x00516220`, and `0x00516170`.
- The help handler narrows the key event and returns true only for key event type `8`, ASCII `?`, and modifier byte `4`, then calls `OldSystemMessagePane::LoadHelpMessages` at `0x00589d30` on `this - 0xa0`. This is its sole caller (`0x005896ab`).
- `OldSystemMessagePane::LoadHelpMessages` checks [UID:0003GP][0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString](by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md)'s UTF-16 `HELP.RES` literal. When the DAT entry is unavailable it writes every entry of `s_oldSystemMessageHelpMessages`, using the same localization-ID sequence as the current pane and `&initialText` at slots 14, 25, 33, 42, and 53, then appends the resulting help entries. Historical IDA labels `sub_589D30`, `sub_4F0350`, `word_60DB20`, and `dword_69BD08` remain evidence aliases only, not current source names. Catalog0376 applied and verified the accepted identities; dated F7/1BC3/5F2679A7 checks and B010's bounded B7CC899D pass found no target-local drift, with fresh supervisor Gate 2B confirmation retained only as the later lifecycle gate.
- The destructor adjustor thunks subtract `0xa0` and `0xa4` from `this` and jump to `0x0058adb0`; `xrefs_to 0x0058adb0` also reports the primary vtable data ref at `0x0062d8c8`.
- Destructor disassembly clears `0x0069b4c8` at `0x0058aeb7`, walks owned message entries through virtual cleanup calls, runs ten tile-context cleanup calls at `0x00458500`, tears down the scrollable-pane base at `0x0055e780`, and optionally frees storage.
- `xrefs_to 0x0069b4c8` also reports a read from the main UI teardown path at `0x005049c4` and an old-mode read from the emotion input path at `0x005b2d5a`, confirming the singleton is part of legacy UI flow.

Checked again on 2026-06-12 by C001:

- `entity_query` over `0x0062d8c4-0x0062d978` confirms [UID:0003DM][0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData](by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md) is exactly the `OldSystemMessagePane` locator plus primary/secondary/tertiary vtable run, with vtable heads at `0x0062d8c8`, `0x0062d93c`, and `0x0062d96c`, followed immediately by resource-string successor `aGbordEpd` at `0x0062d978`.
- `entity_query` over RTTI data identifies `??_R4OldSystemMessagePane@@6B@` at `0x00650f04`, matching the locator word at the start of the vtable-data child.
- `xrefs_to` confirms each vtable head has the same three direct lifecycle refs: constructor `sub_588E30`, reset/helper `sub_589180`, and scalar deleting destructor `sub_58ADB0`; this ties the read-only table child directly to this class rather than to the broader source file.
- `analyze_function 0x00588e30` confirms the constructor caller from `sub_4F7D10` at `0x004f8861`, the singleton publish to `0x0069b4c8`, vtable installs at object offsets `+0x00`, `+0xa0`, and `+0xa4`, ten tile-context constructions, starter message-entry construction, and resource-tail uses of `0x0062d974`.
- `analyze_function 0x0058adb0` confirms destructor-side vtable reinstalls at the same three object offsets, message-entry cleanup, ten tile-context cleanup calls through `0x00458500`, singleton clear at `0x0058aeb7`, scrollable-pane base teardown through `0x0055e780`, and optional storage free.
- 2026-06-25 B006 accepted [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) support sync: parent reclassification does not move constructor ownership. `0x00588e30` remains `OldSystemMessagePane::OldSystemMessagePane`, directly called from the legacy UI graph at `0x004f8861`; it publishes the old singleton at `0x0069b4c8`, installs three class vtable views, runs ten tile-context/resource setup calls, seeds starter message entries, and uses this class's vtable/resource data. The current generated omission of the constructor body remains a generated-output caveat, not evidence against this class owner.
- 2026-06-26 B006 [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) support sync names the legacy-mode `?` menu helper roles used by the Emotion handler's first-draft C++: `AppendHeaderMarker()` for `0x00589330`, `AppendColoredText(...)` for `0x00589350`, `AppendFooterMarker()` for `0x00589470`, and `RefreshAndPruneMessages()` for `0x005892a0`. The handler reads [UID:0003ED][g_pOldSystemMessagePane](by-global/g_pOldSystemMessagePane.md) at `0x005b2d5a`, clears byte `+0x130` before batching the localized emotion menu, appends title string id `31` with arguments `4` and `36`, appends entry string ids `15-30` with arguments `132` and `36`, calls the footer and refresh/prune helpers, and then reopens `EmotionInputPane`. The byte at `+0x130` is documented as inferred `m_refreshOnAppend`, matching the current SystemMessagePane batch-refresh behavior. These are behavior-backed helper/type names only; this class remains owned by [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) and does not own Emotion input logic.

## 2026-07-13 B005 Inherited GetScrollDelta Support

- `0x00589630-0x00589668` is the OldSystemMessagePane override of ScrollablePane primary slot `+0x5c`, vtable word `0x0062d924`.
- Source ABI is `Point *GetScrollDelta(Point *outDelta, char axis, short oldPosition, short newPosition)`. Project `Point` is y/x; x is always zero, vertical axis `0` writes `12 * (oldPosition - newPosition)`, and nonvertical y is zero.
- The evidence-time base/direct-family audit covered all six ScrollablePane constructor families. The surviving ListPane inventory supplies canonical `GetScrollDelta`; historical role-only scroll-delta wording is resolved and `ConvertScrollDelta` is superseded.
- Vtable-only liveness is ordinary virtual dispatch. No method body or class declaration is added because the OldSystemMessagePane class retains broader field/helper declaration blockers outside UID0002ES.
- Scores, metadata, formal no-code comment, singleton/resource/list/destructor evidence, range, and `SystemMessagePanes.cpp` route remain unchanged.
- [UID:0004JD][0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta](by-memory/0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta.md) supplies the exact sibling contract/body proof.

## B009 UID0003GP Direct Help-Resource Use

- `OldSystemMessagePane::LoadHelpMessages` owns the old-pane half of [UID:0003GP][0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString](by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md)'s four-reference source use. It passes direct `L"HELP.RES"` to `HasDATEntry` at `0x00589d9e` and to `DATFile::Open` at `0x00589dcf`.
- The loader range is `[0x00589d30,0x0058a230)` and its sole caller is the old `?` key path at `0x005896ab` inside raw IDA function `sub_589670` `[0x00589670,0x005896c0)`. This class documentation retains descriptive `HandleHelpShortcut`; no IDA key-handler rename is authorized without original-symbol evidence.
- UID0003GP's literal subrange is `[0x0062d98c,0x0062d99e)`, followed by separate alignment `[0x0062d99e,0x0062d9a0)`. The old and current loader tokens pool into that one unique binary occurrence; interior `LP`, `.RES`, and alignment heads have zero refs.
- The source representation is method-local direct use, not a named file-static/class-static resource-name object. UID0003GP emits the formal no-standalone marker, and its H block remains blank. IDA-only `aHelpRes`, `aHe_1`, and `aRes` are prohibited in C++.
- The absent-resource path and file-static `s_oldSystemMessageHelpMessages[60]` declaration remain unchanged. This class does not own the array definition, the current-pane uses, DATFile, LanguageMan, or a duplicate wide literal.

## Source Layout Decision

Keep this class in [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). The direct caller is the old-mode branch of the main UI graph, but the class behavior, vtables, message-entry ownership, and scrollable system-message helpers all sit inside the system-message pane family rather than the main UI graph file.

## B011 Declaration-Shell Audit

Accepted B011 report `0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md` keeps this class source-owned by [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) but resolves the empty emitter with a formal no-code comment. The audit checked constructor `0x00588e30-0x00589173`, support helpers `0x00589180-0x0058948f`, scroll metrics `0x00589540-0x00589668`, help handler `0x00589670-0x005896c0`, secondary helper `0x005896c0-0x005898f3`, draw `0x00589920-0x00589c0c`, total line count `0x00589c80-0x00589cea`, thunks `0x0058ab1d-0x0058ab33`, destructor `0x0058adb0-0x0058af00`, exact vtable child [UID:0003DM][0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData](by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md), global [UID:0003ED][g_pOldSystemMessagePane](by-global/g_pOldSystemMessagePane.md), and direct caller `0x004f8861`.

The constructor publishes old singleton storage at `0x0069b4c8`, installs three vtable views, constructs ten tile contexts, uses resource tail `0x0062d974`, and seeds message entries. The destructor clears the singleton, walks entries, tears down ten tile contexts, and destroys the scrollable pane base. [UID:0003DM][0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData](by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md) proves vtable heads at `0x0062d8c8`, `0x0062d93c`, and `0x0062d96c`, each with constructor/reset/destructor lifecycle refs. The audited offset evidence includes three vtable views at `+0/+0xa0/+0xa4`, message-list/refresh state around `+0x130/+0x134`, and ten tile contexts beginning around `+312`. A declaration shell would have to choose the scrollable base class ABI, adjusted-base inheritance layout, and ten tile-context member declarations; `[[CHILDREN]]` has no exact body children.

## Score Rationale

The score is raised to `85/88` because the page now records current live IDA evidence for the constructor caller, method extents, vtable data child, singleton reads/writes, constructor child initialization, help shortcut conditions, destructor thunk offsets, and destructor cleanup behavior. It clears the strict parent gate for vtable-data ownership, but remains below final reconstruction quality because the exact field names, several helper method names, and final source-quality C++ layout are still provisional.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)
- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)
- [UID:0003DM][0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData](by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md)

## Changes

- 2026-08-14 B009 UID0003GP accepted implementation callback:
  - Preserved `85/88`, owner/emitter [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md), the existing formal declaration-shell comment, blank H, class range, and all unrelated method evidence.
  - Added direct `L"HELP.RES"` calls to `HasDATEntry`/`DATFile::Open` at `0x00589d9e`/`0x00589dcf`, exact loader/key-caller ranges, pooled-literal/no-standalone source placement, zero interior/alignment refs, and the class-versus-file ownership boundary.
- 2026-07-30 B010 UID0002AP accepted pre-IDA support synchronization:
  - Kept class metadata and formal declaration-shell caveat unchanged; added `OldSystemMessagePane::LoadHelpMessages` at `0x00589d30` and the exact sole caller at `0x005896ab` to the method/evidence maps.
  - Recorded the `HELP.RES` branch, complete paired 60-slot fallback role, file-static `s_oldSystemMessageHelpMessages`, five `initialText` separators, and source/file ownership boundary.
  - Preserved every raw loader/getter/fallback/table label as historical IDA evidence. Catalog0376 applied and verified the accepted source-facing identities; dated F7/1BC3/5F2679A7 checks and B010's bounded B7CC899D pass found no target-local drift, with fresh supervisor Gate 2B confirmation retained only as the later lifecycle gate.
- 2026-07-13 B005 UID0002ES support synchronization: preserved `85/88`, metadata, formal no-code disposition, and all OldSystemMessagePane evidence; resolved `0x00589630` / primary `+0x5c` to canonical `GetScrollDelta` with Point y/x, old-before-new, and 12-pixel vertical scaling, retaining `ConvertScrollDelta` only as superseded history.

- 2026-06-30 B011 accepted empty-emitter implementation:
  - Inserted the formal no-code disposition comment into `RECONSTRUCTION_CPP CODE`.
  - Added declaration-shell audit proof for constructor `0x00588e30`, caller `0x004f8861`, singleton, three vtable views, ten tile contexts, [UID:0003DM][0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData](by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md), destructor cleanup, and the rejected adjusted-base/member shell.
- 2026-06-25 B006 accepted [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) support sync:
  - Reconfirmed constructor ownership for `0x00588e30`, direct caller `0x004f8861`, old singleton publication at `0x0069b4c8`, vtable installs, resource/tile setup, starter message-entry construction, destructor cleanup, and the generated constructor-body omission caveat.
  - Recorded that [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) is now a non-emitting split index, so no aggregate parent C++ should be introduced for this legacy class family.
- 2026-06-26 B006 EmotionInputPane support sync:
  - Scores remain `85/88`; owner/emitter [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) and blank formal class C++ are preserved.
  - Added source-facing legacy helper names and `m_refreshOnAppend` interpretation needed by [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md)'s accepted first-draft `OnCharInput` body, with ownership kept on this class for old-mode message-list helpers only.
- Before: completion/confidence metadata were `0/0` despite method-map, constructor evidence, singleton notes, destructor behavior, and source-quality caveats.
- Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
- Evidence: IDA-confirmed constructor, scroll metric helpers, help shortcut, draw, line-count, thunk, and destructor ranges are documented, along with constructor caller/global behavior; confidence remains medium because final field/helper names are not source-quality yet.
- 2026-06-04: Raised the class page from `78/76` to `82/84` without parent attachment or final C++.
  - Before: the page had the right high-level role but relied on stale source-output caveats and lacked current live evidence for vtable slots, singleton xrefs, constructor callsites, help-key conditions, and destructor cleanup details.
  - After: the page records exact live function boundaries, direct old UI graph caller, singleton writes/reads, three vtable installs, tile-context/resource setup, message-entry setup, help shortcut conditions, destructor thunk offsets, and destructor cleanup behavior.
  - Evidence: 2026-06-04 live IDA MCP `lookup_funcs`, `xrefs_to`, disassembly, vtable dword reads, and constructor/destructor callsite checks for `0x00588e30`, `0x00589540-0x00589668`, `0x00589670`, `0x00589920`, `0x00589c80`, `0x0058ab1d`, `0x0058ab28`, `0x0058adb0`, `0x0062d8c8`, `0x0062d93c`, `0x0062d96c`, and `0x0069b4c8`.
- 2026-06-05: Marked reconstructable and attached to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) because the class is `82/84` and the parent is `88/82`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x00588e30`, `0x00589180`, `0x00589540`, `0x00589670`, `0x005896c0`, `0x00589920`, `0x00589c80`, `0x0058ab1d`, and `0x0058adb0`; current `callers` confirms the old UI graph constructor caller at `0x004f8861`.
- 2026-06-12 C001 Batch C001-004: Raised from `82/84` to `85/88` and documented the exact vtable-data child [UID:0003DM][0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData](by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md).
  - Evidence: live IDA confirmed the `OldSystemMessagePane` RTTI locator/vtable names, three constructor/reset/destructor data refs for each vtable head, constructor singleton/resource/tile/message-entry setup, and destructor vtable/message/tile/singleton/base cleanup behavior.
  - Routing effect: the class now clears the strict `85/85` parent gate for assigning its direct vtable-data child; no final C++ was emitted.
