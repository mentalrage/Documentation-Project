*** UID:0000E8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:11 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class StringMenuItem : public MenuItem
{
public:
    explicit StringMenuItem(const wchar_t *text);

    errno_t CopyText(wchar_t *destination, size_t sizeInWords) const;

    virtual MenuItemMetrics GetItemSize(GrafPort *port) const;
    virtual errno_t GetText(wchar_t *destination, size_t sizeInWords) const;
    virtual void DrawItem(GrafPort *port);

protected:
    wchar_t m_text[0x80];
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StringMenuItem

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Main address range: [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- Vtables: [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- Layout docs: [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- Current recovered file: `source-3/simroot_v2/class_StringMenuItem.cpp`

## Class Purpose

`StringMenuItem` is a text menu entry. It stores an object-owned fixed wide-character label, reports its required size to the owning pane, copies its label into caller-owned buffers for direct and virtual consumers, and draws selected/highlighted or normal text. Both copy methods return the exact `wcscpy_s` `errno_t` status rather than a string or pointer.

IDA confirms the inline label buffer begins at byte offset `+0x18` and is copied with capacity `0x80` wide characters. Text-copy helpers at `0x00517070` and `0x005170d0` both read from that same offset. B003's 2026-06-23 MCP-backed copy-text implementation resolves the direct helper at `0x00517070` as `StringMenuItem::CopyText(...)`, while the vtable-backed sibling at `0x005170d0` is `errno_t StringMenuItem::GetText(wchar_t *destination, size_t sizeInWords) const`. The latter is physically slot `+0x10` at `0x0061ebc4`; `PopupMenuControlPane::OnDraw` dispatches it at `0x00498414` with a caller-owned `wchar_t[256]` and count `0x100`, then intentionally ignores EAX and consumes the destination.

## Hierarchy And Virtual Contract

- RTTI proves the three-entry single-inheritance chain `StringMenuItem -> MenuItem -> LObject`; the CHD attributes are `0` and every PMD is `0,-1,0`.
- The class is concrete. Its six-slot table supplies a String-only deleting wrapper, inherited `GetRuntimeClass`, inherited `OnChangeMessage`, and concrete `GetItemSize`, `GetText`, and `DrawItem` implementations.
- The complete size is `0x118`: `MenuItem` base `0x18` plus inline `wchar_t m_text[0x80]` (`0x100`) at `+0x18`. The `0x118` delete-size immediate independently confirms the extent.
- `CopyText` is a direct nonvirtual helper and is not a vtable slot; exact table cells point to `0x00517090`, `0x005170d0`, and `0x005170f0`, not `0x00517070`.

## Method Map

| Memory page | Method | Role |
| --- | --- | --- |
| [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) | `StringMenuItem::StringMenuItem(const wchar_t *text)` | Initializes the base menu item and copies label text into inline `m_text[0x80]`; first-draft C++ is now present on the target page. |
| [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) | `errno_t CopyText(wchar_t *destination, size_t sizeInWords) const` | Direct non-virtual label-copy helper; first-draft C++ is now present on the target page. `CopyTextToWideBuffer` is retained only as a historical/generated alias. |
| [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) | `MenuItemMetrics GetItemSize(GrafPort *port) const` | Measures label width and returns height-first item dimensions; first-draft C++ is now present on the target page. |
| [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) | `errno_t GetText(wchar_t *destination, size_t sizeInWords) const` | Virtual slot `+0x10`; copies object-owned inline `m_text[128]` to caller storage, preserves exact CRT status/failure clearing, and is concretely dispatched by `PopupMenuControlPane::OnDraw` at `0x00498414`. |
| [UID:0002JA][0x005170f0-0x005171a2.StringMenuItemDrawItem](by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md) | `DrawItem(...)` | Draws normal or selected text. |
| [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) | compiler-generated scalar deleting destructor wrapper | Reviewed `RECONSTRUCTABLE:FALSE`, non-emitting support. The existing class declaration needs no explicit derived destructor; implicit virtual derived destruction regenerates the wrapper. |

## B003 Source-Quality Incorporation

B003 rechecked the string-item family as a source-quality/naming issue and accepted these high-probability roles:

| Item | Best current source role | Evidence | Caveat |
| --- | --- | --- | --- |
| `+0x18` label storage | `wchar_t m_text[0x80]` | Constructor calls `_wcscpy_s(this+0x18, 0x80, source)`; copy/get-text/measure/draw helpers all read the same offset. | Exact member name remains inferred, but heap/caller-owned/string-object alternatives are rejected. |
| `0002J7` direct helper | `errno_t StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const` | MCP session `b880584f` confirms exact `0x00517070-0x00517089` range, 25-byte body, SHA256 prefix `a858cb8bb45508d2`, one `_wcscpy_s` callee, `retn 8`, eleven direct code xrefs, and no vtable data xref. | `CopyTextToWideBuffer` remains a historical alias from old Wave2/import notes, but its old `void` signature is superseded; `GetText` is rejected for this direct helper because `0002J9` already owns the vtable slot. |
| `0002J9` vtable slot `+0x10` | `errno_t StringMenuItem::GetText(wchar_t *destination, size_t sizeInWords) const` | `_wcscpy_s(destination, sizeInWords, m_text)`, `retn 8`, no mutation, vtable xref at `0x0061ebc4`; `PopupMenuControlPane::OnDraw` pushes `0x100` and a 256-wide local before the `0x00498414` dispatch and ignores status. | Original method spelling could differ, but the typed slot and concrete consumer make `GetText` the strongest source role. |
| `0002JA` vtable slot `+0x14` | `void StringMenuItem::DrawItem(GrafPort *port)` | Selected branch tests `m_selected`, fills item bounds through the shared render callback, sets background state, moves to the padded baseline, and draws `m_text`. | GrafPort and Surface helper names remain descriptive until their source-quality pass. |
| `0002JG` vtable slot `+0x00` | implicit virtual derived destruction, compiler-generated deleting wrapper in binary | Wrapper resets the base vtable, calls cleanup/delete helpers, uses `0x118` object size, and has no label cleanup because `m_text` is inline. | UID0002JG is false/non-emitting with literally blank CPP/H; no explicit destructor declaration or wrapper source is added. |

## B003 CopyText Source-Quality Resolution

B003 rechecked [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) under live IDA MCP session `b880584f` and resolved the prior source-name/C++ blocker. The active MCP schema required an explicit `database` argument, and `server_health(database=b880584f)` reported the `NexusTK.exe.i64` IDB healthy with auto-analysis, Hex-Rays, and strings ready.

The target is an exact 25-byte method body from `0x00517070` through `0x00517089` (Verified with `int_convert.py`), with SHA256 prefix `a858cb8bb45508d2`. It is followed by seven `0xcc` bytes before [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md). The body loads `this+0x18`, pushes source/size/destination for `_wcscpy_s`, returns with `retn 8`, and has eleven direct code xrefs from FolderSelectDialog, MusicControlDialog, TerminalPane/TerminalSetup, and UserInfoDialogPane consumers.

The direct helper is distinct from [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md). MCP vtable reads place [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) at `StringMenuItem` slot `+0x10` / `0x0061ebc4`; no vtable cell points to `0x00517070`. `CopyTextToWideBuffer` remains a historical/generated alias from older Wave2 notes, but its stale `void` signature is rejected because the current body returns `_wcscpy_s`'s `errno_t`. Caller-feature ownership, direct file ownership, base `MenuItem` ownership, merge with [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md), and no-owner/non-emitting status are all rejected for this helper. It remains owned/emitted by [UID:0000E8] and routes to [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) as the source-file root.

## B013 Metric Source-Quality Resolution

B013 rechecked [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) and resolved the prior no-C++ caveat. The accepted source shape is `MenuItemMetrics StringMenuItem::GetItemSize(GrafPort *port) const`: MSVC lowers the value return into a hidden `MenuItemMetrics *` out argument, but source should expose a normal height-first metrics return.

The method scans inline `m_text[0x80]`, calls `GrafPort::GetTextWidth(const wchar_t *text, int charCount)` at `0x004ba9a0`, returns height `14`, and returns width `textWidth + 24`. The `24` is interpreted as total horizontal padding, supported by [UID:0002JA][0x005170f0-0x005171a2.StringMenuItemDrawItem](by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md)'s `m_bounds.left + 12` text origin. `MenuItemMetrics` remains a descriptive source type rather than proven original spelling, but it is preferred over `SIZE` because both string and separator metric helpers write `[0] = height`, `[1] = width`.

## B012 Constructor Source-Quality Resolution

B012 rechecked [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) and resolved the prior constructor-source follow-up. The source should be represented as `StringMenuItem::StringMenuItem(const wchar_t *text) : MenuItem() { wcscpy_s(m_text, _countof(m_text), text); }`. The binary expands the inherited construction sequence, including `LObject::LObject`, the temporary `MenuItem` vtable store, `InitRectBounds(&m_bounds, 0, 0, 0, 0)`, the adjacent-byte state store for `m_enabled=true` and `m_selected=false`, and the final `StringMenuItem` vtable store; source reconstruction should not duplicate that vtable/EH/security-cookie scaffolding inside the derived constructor body.

The constructor remains owned by this class and emitted through [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md). B012 rejected feature-dialog ownership (`FolderSelectDialog`, `MusicControlDialog`, `TerminalSetupPane`, and `UserInfoDialogPane`) because the 54 direct construction xrefs are consumers of the reusable string-menu-item class. Remaining uncertainty is only exact original parameter spelling and array-count macro spelling; it does not block first-draft C++.

## Destructor Source Policy

[UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) is reviewed compiler-only, `RECONSTRUCTABLE:FALSE`, non-emitting scalar deleting-destructor support. B009 2026-06-19 raw PE recheck confirms the wrapper object-size path is `0x118` / 280 bytes, matching `MenuItem` base size `0x18` plus inline `wchar_t m_text[0x80]` at `+0x18`. No heap label cleanup exists, and its formal CPP/H channels are intentionally blank.

## Reachability And Destruction

The constructor at `0x00516ff0` has 54 direct code xrefs across FolderSelectDialog, MusicControlDialog, TerminalSetupPane, UserInfoDialogPane, and related reusable consumers. Those callers establish live concrete construction without transferring source ownership to any feature. The final vptr store is `0x0061ebb4`.

[UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) is referenced only by String slot 0 and carries delete size `0x118`. Inline `wchar_t[0x80]` needs no authored cleanup, and virtual base destruction already supplies the virtual destructor contract. The accepted H declaration therefore omits an explicit derived destructor and relies on implicit virtual derived destruction; MSVC regenerates deleting-flag checks, base-vptr reset, base cleanup, and optional delete. The earlier explicit `virtual ~StringMenuItem()` draft is retained as a superseded assumption, not silently discarded.

## Evidence Notes

- IDA MCP `lookup_funcs` confirms all listed starts and extents as exact functions.
- Constructor xrefs come from several dialog/menu creation paths, making this reusable infrastructure rather than one feature's private item class.
- 2026-05-26 IDA MCP resolves the decorated `StringMenuItem` vtable symbol to `0x0061ebb4`; generated metadata still reports `vtable_count: 0`.
- Vtable data xrefs place `GetItemSize`, `GetText`, and `DrawItem` at slots `+0x0c`, `+0x10`, and `+0x14`.
- Current target type is `errno_t __thiscall(const StringMenuItem *this, wchar_t *destination, rsize_t sizeInWords)`. The physical `GetText` cell is `0x0061ebc4 -> 0x005170d0`; the external dispatch at `0x00498414` passes count `0x100` and a 256-wide local, ignores EAX, and immediately draws the copied text. This proves concrete use without transferring ownership to the consumer.
- 2026-06-07 A010 Batch096 parent-gate review confirms this class already clears the corrected child gate at `88/90`. Associated parent work raised [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) to `86/85` by synchronizing the newer menu aggregate/type evidence and proposed-source-tree ownership.

## Assignment Gate

`AUTOGEN_PARENT_UID` remains [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md). The class is now `92/94`, and the direct source-file parent is recommended at `88/88`. `StringMenuItem` is a reusable concrete menu item, not a caller-feature-local type. UID0001Y4 owns the shared table semantics and routes UID00036I while this class owns its declarations and exact child method definitions.

## Ownership And History

- The complete class declaration now emits from the H channel; CPP contains only `[[CHILDREN]]`, keeping qualified child definitions at namespace scope.
- UID0000MN remains the current `PopupMenuControls.h/.cpp` source root. A historical separate `MenuItem` source pair remains possible but does not justify rerouting or duplication.
- `CopyTextToWideBuffer` and its old `void` signature remain historical aliases rejected by the current `errno_t` body. `GetText` is a distinct virtual sibling, and direct-file, base-class, caller-feature, merge, raw-wrapper, and no-owner alternatives remain rejected.

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md)

## Changes

- 2026-08-11 B010 UID0002J9 ordinary implementation callback:
  - Preserved `92/94`, UID0000MN ownership/emission, position `11`, complete formal H declaration, CPP `[[CHILDREN]]`, inline layout, and all prior source-quality history.
  - Added the exact `GetText` ABI/status/ownership contract, physical slot `0x0061ebc4`, and concrete `PopupMenuControlPane::OnDraw` dispatch at `0x00498414` with a 256-wide caller buffer and ignored status.
  - Reconciled UID0002JG as false/non-emitting compiler support regenerated by implicit virtual derived destruction; no explicit destructor declaration, proof marker, or wrapper body was added.
- 2026-08-01 B003 UID00036I ordinary implementation callback:
  - Raised `89/91 -> 92/94` while preserving owner/emitter UID0000MN, reconstructable true, position `11`, all method routes, inline text evidence, and prior history.
  - Moved the complete declaration to H, left CPP as `[[CHILDREN]]` only, removed the unsupported explicit destructor declaration, and documented implicit virtual derived destruction for the String-only `0x118` wrapper.
  - Added the exact three-class RTTI chain, concrete six-slot contract, 54-constructor-caller reachability, `0x118` layout proof, and UID0001Y4 -> UID00036I semantic-data route.
  - Preserved the rejected `CopyTextToWideBuffer`, ownership, merge, and raw-wrapper alternatives as explicit history.

- 2026-07-15 B003 UID0002JH callback structural repair:
  - Applied exact R6 by closing the complete `StringMenuItem` declaration before `[[CHILDREN]]`; qualified child definitions now belong at namespace scope rather than inside the class body.
  - Preserved `89/91`, owner/emitter UID0000MN, reconstructable true, position `11`, every declaration/field/route, inline `m_text[0x80]` layout, constructor/copy/metric/text/draw/destructor evidence, rejected alternatives, and all unrelated historical content.

- 2026-06-30 B008 empty-emitter implementation:
  - Raised from `88/90` to `89/91`, set `EMITTER_POSITION_OPTIONAL:11`, and populated the formal declaration shell with constructor/destructor declarations, `CopyText`, virtual metric/text/draw overrides, inline `wchar_t m_text[0x80]`, and `[[CHILDREN]]`.
  - Evidence: existing accepted constructor/copy/measure/get-text/draw child pages and the B008 vtable check keep `StringMenuItem` routed through [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md) to [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md); the scalar deleting wrapper remains compiler-generated source-declared/generated-binary support rather than handwritten wrapper logic.
  - Source-quality decision: preserve the inline-label model at `+0x18`, keep `CopyTextToWideBuffer` only as historical/generated alias text in child evidence, and do not split caller-specific dialog ownership from this reusable menu-item class.
- 2026-06-07 A010 Batch096 class coverage toss-up:
  - Before: score `88/90`, `AUTOGEN_PARENT_UID` blank because the likely direct parent was below the corrected gate.
  - After: score remains `88/90`, `AUTOGEN_PARENT_UID:0000MN`.
  - Evidence: exact constructor/copy/measure/get-text/draw/destructor child pages, inline label-layout evidence, and vtable slot refs already cleared the child gate; associated parent work raised [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) to `86/85`, satisfying the strict child-and-parent gate.
- 2026-06-17 B003 source-quality incorporation:
  - Recorded `m_text[0x80]`, `GetText`, `DrawItem`, and ordinary/default destructor policy as high-probability source roles.
  - Rerouted exact StringMenuItem child pages from direct file owner/emitter to [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md) where applicable, while keeping [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) as the source-file root.
- 2026-06-19 B009 accepted source-quality implementation:
  - Added the target-specific destructor source policy for [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md), including raw PE object-size proof `0x118` / 280, inline `wchar_t m_text[0x80]` no-extra-cleanup proof, and the no-code wrapper policy that leaves scalar deleting destructor generation to MSVC.
- 2026-06-21 B012 constructor source-quality incorporation:
  - Recorded [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) as first-draft C++ ready with `StringMenuItem::StringMenuItem(const wchar_t *text) : MenuItem()` and `wcscpy_s(m_text, _countof(m_text), text)`.
  - Evidence: exact `0x80` / 128-byte constructor, `thiscall` one-argument `retn 4` ABI, 54 direct construction xrefs, final vtable store `0x0061ebb4`, inline `m_text[0x80]` at byte offset `+0x18`, sibling string-item buffer consumers, and the current [UID:0000E8] -> [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) source route.
- 2026-06-22 B013 metric source-quality incorporation:
  - Recorded [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) as first-draft C++ ready with `MenuItemMetrics StringMenuItem::GetItemSize(GrafPort *port) const`.
  - Evidence: exact `0x40` body, `StringMenuItem` vtable slot `+0x0c` at `0x0061ebc0`, hidden-return/out-buffer ABI, inline `m_text[0x80]` scan, accepted `GrafPort::GetTextWidth` dependency, height-first metrics order, and 24-pixel horizontal padding tied to the draw helper's 12-pixel left inset.
- 2026-06-23 B003 copy-text source-quality implementation:
  - Recorded [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) as first-draft C++ ready with `errno_t StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const`.
  - Evidence: live MCP session `b880584f`, exact 25-byte body/range, SHA256 prefix `a858cb8bb45508d2`, seven-byte `0xcc` successor padding, `_wcscpy_s` callee, `retn 8`, eleven direct code xrefs, accepted `m_text[0x80]` source field at byte offset `+0x18`, and vtable-sibling comparison proving [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) remains slot `+0x10` / `0x0061ebc4`.
  - Historical/stale correction: `CopyTextToWideBuffer` remains only a search alias; the old `void` signature is rejected in favor of `errno_t`. `GetText`, caller-feature ownership, base `MenuItem` ownership, direct file ownership, merge with [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md), and no-owner/non-emitting status are rejected.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `88`, confidence `90`.
- Evidence: the page documents the menu-item role, buffer offset/capacity, exact method map, reusable caller evidence, vtable symbol, and slot refs; remaining completion gap is source-ready C++ detail.
- Reconstructable metadata update: existed before as blank; changed to `TRUE`. Summary: IDA evidence confirms this is NexusTK-owned source infrastructure. This older note predates B003's method-level first-draft C++ pass; current source bodies are attached to exact child pages where evidence supports them.
- Method-map split update: existed before as raw address rows; changed to UID links for exact by-memory child pages. Evidence: IDA MCP exact function-boundary lookup and vtable slot xrefs support the child pages.
