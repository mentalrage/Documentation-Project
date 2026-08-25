*** UID:0000EA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// SystemMessagePane is the current scrollable system-message viewport in
// social/SystemMessagePanes.cpp. Constructor/destructor, append/prune helpers,
// packet handling, rendering, line metrics, and g_pChattingViewport lifecycle are
// documented, including exact vtable child [UID:0003DI][0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData](by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md), +0x130 refresh behavior,
// +0x134 message list, and three vtable views. A declaration shell would have to
// invent inherited scroll/tile APIs, adjusted-base declarations, and member types.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SystemMessagePane

## Status

- Confidence: strong for class role, IDA boundaries, vtable ownership, and lifecycle behavior; inherited slot names and final field names remain provisional.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Exact read-only data: [UID:0003DI][0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData](by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md)
- Parent range disposition: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) is a non-emitting executable split index. This class page remains the source-bearing owner for constructor/destructor, packet handling, rendering, scroll metrics, insert/prune helpers, and `g_pChattingViewport` lifecycle facts; formal class C++ remains blank for its broader field/helper/declaration blockers, while inherited slot `+0x5c` is now specifically resolved as `GetScrollDelta`.

## Class Purpose

`SystemMessagePane` is the shared scrollable system-message viewport used by the old and new system-message panel wrappers. It publishes the current viewport through `g_pChattingViewport`, maintains a capped list of color/header/footer message entries, computes scroll extents in 12-pixel rows, supports high-resolution and normal EPF-backed layouts, handles the `?` help shortcut, decodes several system-message packet forms, and paints visible rows/separators with clipping.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00584ea0-0x005851d9` | `SystemMessagePane::SystemMessagePane(...)` | Constructs the scrollable pane, initializes message slots/list, and stores `g_pChattingViewport`. |
| `0x005851e0-0x00585358` | `~SystemMessagePane()` | Destroys message entries, list storage, tile contexts, and base scrollable pane state. |
| `0x00585360-0x005854ac` | `RefreshAndPruneMessages` / refresh-prune helper | Recomputes scroll geometry, sets the append-refresh byte, and prunes the oldest entries while the message list exceeds 200 items. |
| `0x005854b0-0x005854cf` | `AppendHeaderMarker` / header marker append helper | Builds and submits a `HeaderSystemMessage` marker entry. |
| `0x005854d0-0x0058555a` | `AppendColoredText` / colored text append helper | Wraps a text/color/style pair in `ColorStringSystemMessage` and appends it to the list. |
| `0x00585560-0x0058557f` | `AppendFooterMarker` / footer marker append helper | Builds and submits a `FooterSystemMessage` marker entry. |
| `0x00585580-0x005856e9` | message-entry insert helper | Inserts a cloned entry, refreshes scroll geometry, and prunes excess entries. |
| `0x005856f0-0x005858c8` | scroll metric helpers | Computes scroll extent, overflow/page count, row offsets, content size, and canonical `GetScrollDelta` at `0x00585890`, which writes y=`12*(old-new)` for vertical axis and x zero. |
| `0x005858d0-0x00585920` | `OnKeyEvent` | Handles the `?` help shortcut and calls `SystemMessagePane::LoadHelpMessages` only from `0x0058590b`. |
| `0x00585920-0x00585b53` | system-message packet handler | Dispatches packet/message cases `0x0a`, `0x0f`, `0x10`, and `0x17`, including header/footer insertion around formatted player text. |
| `0x00585b80-0x00586200` | `OnPaint` | Paints visible message entries, separators, and clipped text rows. |
| `0x00586370-0x0058643b` | `GetTotalContentHeight` | Sums rendered row height across message entries. |
| `0x00586480-0x00586af5` | `SystemMessagePane::LoadHelpMessages` | Passes direct `L"HELP.RES"` to `HasDATEntry` at `0x00586538` and `DATFile::Open` at `0x00586569`; when absent, fills file-static `s_systemMessageHelpMessages[60]` from the validated localization map with five `initialText` separators, then appends header/color/footer entries. The literal is compiler-pooled with the parallel old-pane uses rather than defined as a class/static object. |
| `0x0058ab33-0x0058ab49` | Adjustor/thunk helpers | Small vtable helpers currently omitted from emitted source. |
| `0x0058af00-0x0058af3b` | `ScalarDeletingDestructor` | Destructor wrapper with scalar-delete flag handling. |

## Evidence Notes

- 2026-06-12 A002 live IDA MCP `py_eval` enumerated exact function starts from `0x00584ea0` through `0x0058643b`, including the previously under-documented helper block at `0x00585360-0x005856e9`.
- 2026-06-12 live IDA MCP `py_eval` corrected [UID:0003DI][0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData](by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md) to `0x0062d5f8-0x0062d6a8`. The page now covers the primary, secondary, and tertiary `SystemMessagePane` complete-object-locator/vtable pairs. The successor dword at `0x0062d6a8` belongs to `HeaderSystemMessage`.
- Live xrefs to the three vtable bases are constructor/destructor stores: `0x00584f08`/`0x0058520d` for the primary base, `0x00584f0e`/`0x00585213` for the `this+0xa0` view, and `0x00584f18`/`0x0058521d` for the `this+0xa4` view.
- Live decompilation of `0x00584ea0` confirms constructor behavior: it publishes `dword_67adc4`, installs the three vtable bases, initializes ten normal-layout resource contexts from `MSGBORD.EPD` when not in high-resolution mode, builds a message-entry list at `this+0x134`, and handles the high-resolution branch via dynamic color-message entries.
- Live decompilation of `0x005851e0` confirms destructor behavior: it restores the three vtable bases, deletes message entries from the list, frees list storage, tears down the ten normal-layout contexts, clears `dword_67adc4`, and then tears down the base pane state.
- Live decompilation of `0x005858d0` confirms the `?` help shortcut: it narrows the key byte, checks the expected event/modifier fields, calls the help/resource loader at `0x00586480` only for the shortcut, and otherwise returns false.
- 2026-07-04 B003 current MCP session `cbc24146` ties that help shortcut directly to [UID:0002ZV][0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable](by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md): `xrefs_to 0x00586480` returns the sole call at `0x0058590b` in `OnKeyEvent` (historical IDA label `sub_5858D0`). `SystemMessagePane::LoadHelpMessages` at `0x00586480` (historical IDA label `sub_586480`) is size `0x675`, checks [UID:0003GP][0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString](by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md)'s `HELP.RES`, and otherwise writes all 60 entries of `s_systemMessageHelpMessages` from the localization map through `0x0069bd04`; slots 14, 25, 33, 42, and 53 use `&initialText`, and the base is loaded at `0x00586a08`. This is current-pane class behavior, while the array definition belongs at file scope and UID0002AP remains a non-source index.
- Live decompilation of `0x00585920` confirms packet/message dispatch for cases `0x0a`, `0x0f`, `0x10`, and `0x17`; the `0x0f` branch converts a multibyte name to wide text, formats it, inserts header/footer markers, and appends the text entry.
- Live decompilation of `0x00585b80` and `0x00586370` confirms the render/content model: visible entries are iterated from the list, row height is accumulated as `12 * lineCount`, widths differ between high-resolution and normal modes, and clipped draw calls are skipped outside the pane rectangle.
- The remaining confidence cap is final-source naming quality, not ownership: inherited base slot names, exact field names for offsets such as `0x134`, `0x130`, and `0x2c8`, and helper names for the base scroll/tile APIs remain provisional.
- B014's [UID:0003UD][0x005a58c0-0x005a5983.UserPaneTryPerformAction](by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md) reanalysis adds a concrete external caller path for the message insertion helpers: when the selected-target/action mode is nonzero and the secondary equipment classifier is not bucket `2`, `TryPerformAction` clears `g_pChattingViewport +0x130`, appends [UID:0003JN][0x006309dc-0x006309f4.UserPaneArrowShortageWarningString](by-memory/0x006309dc-0x006309f4.UserPaneArrowShortageWarningString.md) through the colored-text append helper `0x005854d0` with arguments `0x84` and `0x24`, then refreshes/prunes through `0x00585360`. This is a SystemMessagePane dependency of a LivingObjectPane action method, not SystemMessagePane ownership of the action logic.
- 2026-06-25 B006 accepted [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) support sync: live MCP session `80de0a67` confirmed the broad range is a 91-function non-emitting split index with ForcedInform islands, clear helpers, adjustor thunks, and successor-boundary padding. This class keeps the source-bearing route for the `SystemMessagePane` method islands only; do not emit a parent aggregate or comment-only marker through [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md).
- 2026-06-26 B006 [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) support sync names the current-mode `?` menu helper roles used by the Emotion handler's first-draft C++: `AppendHeaderMarker()` for `0x005854b0`, `AppendColoredText(...)` for `0x005854d0`, `AppendFooterMarker()` for `0x00585560`, and `RefreshAndPruneMessages()` for `0x00585360`. The handler reads [UID:0002WV][g_pChattingViewport](by-global/g_pChattingViewport.md) at `0x005b2b35`, clears byte `+0x130` before batching the localized emotion menu, appends title string id `31` with arguments `4` and `36`, appends entry string ids `15-30` with arguments `132` and `36`, calls the footer and refresh/prune helpers, and then reopens `EmotionInputPane`. The byte at `+0x130` is documented as inferred `m_refreshOnAppend`: callers clear it to suppress per-append refresh during a batch, while refresh/insert helpers set or test it. These are behavior-backed source-facing names, not recovered debug symbols, and they support the Emotion target C++ only; they do not make this class owner of the Emotion command logic.

## 2026-07-13 B005 Inherited GetScrollDelta Support

- `0x00585890-0x005858c8` is the SystemMessagePane override of ScrollablePane primary slot `+0x5c`, table word `0x0062d658`.
- Source ABI is `Point *GetScrollDelta(Point *outDelta, char axis, short oldPosition, short newPosition)`. Project `Point` is y/x; x is zero, vertical axis `0` writes `12 * (oldPosition - newPosition)`, and nonvertical y is zero.
- The evidence-time base/direct-family audit covered all six ScrollablePane constructor families. Every body shares output/axis/old/new shape, and the surviving ListPane inventory establishes canonical `GetScrollDelta`; historical `ConvertScrollDelta` is superseded.
- The method's vtable-only data xref is ordinary virtual liveness, not dead/generated/free-helper evidence. No method body or class declaration is added in this callback because the SystemMessagePane aggregate retains separate field/helper blockers.
- Scores, metadata, formal no-code comment, source route, lifecycle/global/resource evidence, range, and every other unresolved class item remain unchanged.
- [UID:0004JD][0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta](by-memory/0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta.md) supplies the exact sibling contract/body proof.

## B009 UID0003GP Direct Help-Resource Use

- `SystemMessagePane::LoadHelpMessages` owns the current-pane half of [UID:0003GP][0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString](by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md)'s four-reference source use. It passes direct `L"HELP.RES"` to `HasDATEntry` at `0x00586538` and to `DATFile::Open` at `0x00586569`.
- The loader range is `[0x00586480,0x00586af5)` and its sole caller is the `?` key path at `0x0058590b` inside raw IDA function `sub_5858D0` `[0x005858d0,0x00585920)`. This class documentation retains source-facing `OnKeyEvent`; no IDA key-handler rename is authorized without original-symbol evidence.
- UID0003GP's literal subrange is `[0x0062d98c,0x0062d99e)`, followed by separate alignment `[0x0062d99e,0x0062d9a0)`. The current and old loader tokens pool into that one unique binary occurrence; interior `LP`, `.RES`, and alignment heads have zero refs.
- The source representation is method-local direct use, not a named file-static/class-static resource-name object. UID0003GP emits the formal no-standalone marker, and its H block remains blank. IDA-only `aHelpRes`, `aHe_1`, and `aRes` are prohibited in C++.
- The absent-resource path and file-static `s_systemMessageHelpMessages[60]` declaration remain unchanged. This class does not own the array definition, the old-pane uses, DATFile, LanguageMan, or a duplicate wide literal.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)
- [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md)
- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)

## B011 Declaration-Shell Audit

Accepted B011 report `0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md` keeps this class source-owned by [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) but resolves the empty emitter with a formal no-code comment. The audit checked constructor `0x00584ea0-0x005851d9`, destructor `0x005851e0-0x00585358`, refresh/prune `0x00585360-0x005854ac`, append helpers `0x005854b0`, `0x005854d0`, `0x00585560`, insert helper `0x00585580-0x005856e9`, scroll metrics `0x005856f0-0x005858c8`, key handler `0x005858d0-0x00585920`, packet handler `0x00585920-0x00585b53`, paint `0x00585b80-0x00586200`, content-height `0x00586370-0x0058643b`, thunks `0x0058ab33-0x0058ab49`, scalar deleting destructor `0x0058af00-0x0058af3b`, exact vtable child [UID:0003DI][0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData](by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md), and global [UID:0002WV][g_pChattingViewport](by-global/g_pChattingViewport.md).

The constructor publishes `g_pChattingViewport`, installs three vtable views, initializes ten normal-mode tile contexts or high-resolution dynamic entries, and creates the message list. The destructor deletes entries/list storage, tears down tile contexts, clears `g_pChattingViewport`, and destroys base pane state. [UID:0003DI][0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData](by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md) proves primary/secondary/tertiary vtable heads at `0x0062d5fc`, `0x0062d670`, and `0x0062d6a0`, with constructor/destructor store pairs and the `HeaderSystemMessage` successor boundary. Current docs prove `m_refreshOnAppend` behavior around `+0x130`, message list at `+0x134`, adjusted vtable views at `+0xa0/+0xa4`, and tile contexts around `+312`, but not enough to declare the full base/subobject layout. A declaration shell would need inherited scroll/tile API names, adjusted-base declarations, list/member types, and virtual prototypes; `[[CHILDREN]]` cannot carry the method bodies.

## Changes

- 2026-08-14 B009 UID0003GP accepted implementation callback:
  - Preserved `86/87`, owner/emitter [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md), the existing formal declaration-shell comment, blank H, class range, and all unrelated method evidence.
  - Added direct `L"HELP.RES"` calls to `HasDATEntry`/`DATFile::Open` at `0x00586538`/`0x00586569`, exact loader/key-caller ranges, pooled-literal/no-standalone source placement, zero interior/alignment refs, and the class-versus-file ownership boundary.
- 2026-07-30 B010 UID0002AP accepted pre-IDA support synchronization:
  - Kept class metadata and its formal declaration-shell caveat unchanged; added `SystemMessagePane::LoadHelpMessages` at `0x00586480` to the method map and synchronized `OnKeyEvent` to its sole call at `0x0058590b`.
  - Recorded exact `HELP.RES` versus 60-slot localization fallback behavior, file-static `s_systemMessageHelpMessages`, five `initialText` separators, and source/file ownership boundaries.
  - Retained `sub_5858D0`, `sub_586480`, `word_60DB20`, and raw table names only as historical IDA evidence. Catalog0376 applied and verified the accepted source-facing identities; dated F7/1BC3/5F2679A7 checks and B010's bounded B7CC899D pass found no target-local drift, with fresh supervisor Gate 2B confirmation retained only as the later lifecycle gate.
- 2026-07-13 B005 UID0002ES support synchronization: preserved `86/87`, metadata, formal no-code disposition, all class/resource/lifecycle evidence, and broader blockers; resolved `0x00585890` / primary `+0x5c` prose to canonical `GetScrollDelta` with Point y/x, old-before-new, and 12-pixel vertical scaling, retaining `ConvertScrollDelta` only as superseded history.

- 2026-06-30 B011 accepted empty-emitter implementation:
  - Inserted the formal no-code disposition comment into `RECONSTRUCTION_CPP CODE`.
  - Added declaration-shell audit proof for constructor/destructor/helper family, [UID:0003DI][0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData](by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md), `+0x130`, `+0x134`, three vtable views, `g_pChattingViewport`, and the rejected scroll/tile ABI shell.
- 2026-07-04 B003 [UID:0002ZV][0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable](by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md) support update:
  - Added current `cbc24146` proof that `OnKeyEvent`/`sub_5858D0` reaches `sub_586480` at `0x0058590b` for the help shortcut, and that `sub_586480` initializes the first system-message resource pointer table emitted by [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md).
- 2026-06-25 B006 accepted [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) support sync:
  - Recorded that the broad memory parent is now a non-emitting executable split index.
  - Preserved this class page as the source-bearing owner for `SystemMessagePane` constructor/destructor/packet/render/helper facts, with formal C++ still blank because field names, inherited slot names, and scroll/tile helper names remain provisional.
- 2026-06-26 B006 EmotionInputPane support sync:
  - Scores remain `86/87`; owner/emitter [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) and blank formal class C++ are preserved.
  - Added source-facing helper names and `m_refreshOnAppend` interpretation needed by [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md)'s accepted first-draft `OnCharInput` body, with ownership kept on this class for message-list helpers only.
- 2026-06-22 Rule 26 support sync from B014 [UID:0003UD][0x005a58c0-0x005a5983.UserPaneTryPerformAction](by-memory/0x005a58c0-0x005a5983.UserPaneTryPerformAction.md):
  - Added the arrow-shortage warning caller path to the colored-text append helper `0x005854d0` and refresh/prune helper `0x00585360`, with ownership kept on SystemMessagePane for the UI helpers only.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `82`.
- Evidence: the page documents scrollable message-pane role, constructor/destructor/scroll/key/paint/content/destructor methods, IDA-confirmed starts, generated omissions, and sibling message-pane relationships; confidence remains capped by provisional helper names.
- 2026-06-05: Marked reconstructable and attached to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) because the class is `84/82` and the parent is `88/82`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x00584ea0`, `0x005851e0`, `0x005856f0`, `0x005858d0`, `0x00585b80`, `0x00586370`, `0x0058ab33`, `0x0058ab3e`, and `0x0058af00`; current `callers` confirms constructor references from `0x0058875e` and `0x005889b6`.
- 2026-06-12 A002 Batch269 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:82`; direct children such as [UID:0003DI][0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData](by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md) could not route to the class under the strict `85/85` gate.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:87`, parent unchanged at [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md).
  - Summary/evidence: live IDA MCP corrected the vtable-data child boundaries, confirmed three constructor/destructor vtable-store pairs, enumerated the exact class-owned helper starts through the message packet and render helpers, and sampled constructor/destructor/key/message/paint/content-height decompilation. The class now clears the strict direct-parent gate while final C++ remains blank pending field and inherited-slot naming quality.
