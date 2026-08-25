*** UID:000081 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct PaneMouseEvent;
struct Rect;
class MenuVarietySelectPane;

class MenuVarietyPane : public Pane
{
public:
    MenuVarietyPane();
    virtual ~MenuVarietyPane();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual void OnPaint();
    virtual int RefreshMenuButton();

private:
    unsigned char m_menuButtonPressed;    // +0xf8
};

extern MenuVarietyPane *g_pMenuVarietyPane;
extern MenuVarietySelectPane *g_pMenuVarietySelectPane;

static void GetMenuVarietyButtonRect(int row, Rect *rect);

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MenuVarietyPane

## Status

- Confidence: strong for class role, boundaries, declaration-level source shape, vtable coverage, singleton lifecycle, and the `+0xf8` button-pressed field; remaining uncertainty is limited to exact original helper/method spellings.
- Likely source file: [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- Main address range: [UID:0001NP][0x005bc610-0x005c0034.MenuVarietyPanes](by-memory/0x005bc610-0x005c0034.MenuVarietyPanes.md)
- Current recovered file: `source-3/simroot_v2/class_MenuVarietyPane.cpp`
- Shared destructor/thunk tail: [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)

## Class Purpose

`MenuVarietyPane` is the in-game menu button pane. It draws `MENUVAR.EPF`, opens or refreshes `MenuVarietySelectPane`, and pulses its owner when the selector state changes.

## Source Reconstruction Policy

The formal C++ block is intentionally declaration-only. It declares the `Pane`-derived class, confirmed `+0xf8` state byte as `m_menuButtonPressed`, singleton externs, the file-local button-rect helper prototype, and `[[CHILDREN]]` so exact child method/helper pages emit the source bodies. This mirrors the accepted nearby `VoteMenuPane` source shape: class declaration/prototypes appear before child bodies, globals emit on by-global pages, and compiler-generated vtable bytes are covered by class declarations rather than raw dword arrays.

Current MCP session `3fa0535f` supports this source shape: `0x005bc610` calls `Pane::Pane(mode=1)`, publishes [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md), clears byte `+0xf8`, and installs vtables at `0x00630d3c`, `0x00630d8c`, and `0x00630dbc`. `0x005bc690` owns the click path that creates or refreshes [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md), and `0x005bc800` owns `MENUVAR` artwork drawing.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005bc610-0x005bc65f` | `MenuVarietyPane::MenuVarietyPane()` | Constructs the dialog/pane state and sets `g_pMenuVarietyPane`. |
| `0x005bc660-0x005bc688` | cleanup body | Reinstalls vtables, clears [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md), and runs pane base cleanup. |
| `0x005bc690-0x005bc7f9` | `HandleClick(int inputEvent)` | Opens or refreshes the selector pane when the menu button is clicked. |
| `0x005bc800-0x005bc874` | `DrawMenuArtwork()` | Draws `MENUVAR.EPF` using selected/open frame. |
| `0x005bc880-0x005bc88a` | Tiny virtual helper | Vtable helper currently not named by Wave3. |
| `0x005bc890-0x005bc96a` | [UID:0003AH][0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers](by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md) | Raw button rectangle helper pair for fixed menu-button bounds and point hit testing. |
| `0x005bfc0b-0x005bfc21` | Adjustor/thunk helpers | Destructor adjustor thunks. |
| `0x005bfc80-0x005bfcdf` | `ScalarDeletingDestructor(...)` | Clears global pointer, destroys base pane, and optionally deletes. |

## Evidence Notes

- Wave3 grades the class at effective `97.5`.
- IDA MCP confirms all listed starts as exact functions.
- Current emitted source omits `0x005bc880`, `0x005bfc0b`, and `0x005bfc16` bodies/markers.
- 2026-06-11 A002 live IDA MCP raw-gap audit split [UID:0003AH][0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers](by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md) from the broad menu-variety range: the first helper builds the fixed `0..0x3d` by `0..0x18` menu-button rectangle through `sub_4B7C50`, while the second helper tests that rectangle through `sub_4B7E80`; boundary bytes around the helper pair are `0xcc` padding.
- 2026-06-29 B003 implementation callback raises this page to `87/90` and resolves the empty formal block with a declaration/prototype layer. Current MCP session `3fa0535f` reconfirmed constructor field setup, singleton publish, vtable stores, click-handler selector construction, and the generated-output need for class-level declarations before child output.

## Cross-References

- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md)
- [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md)
- [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md)
- [UID:0003AH][0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers](by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)

## Changes

- 2026-06-29 B003 implementation callback:
  - Changed to `COMPLETION:87`, `CONFIDENCE:90`, `EMITTER_POSITION_OPTIONAL:0`, and inserted the formal declaration/prototype C++ block with `[[CHILDREN]]`.
  - Summary/evidence: current MCP session `3fa0535f` reconfirmed the `MenuVarietyPane` constructor at `0x005bc610`, `Pane::Pane(mode=1)`, `g_pMenuVarietyPane` publish, `+0xf8` pressed-byte initialization, vtable stores at `0x00630d3c/0x00630d8c/0x00630dbc`, and selector creation/refresh from the click handler. Vtable bytes now emit through [UID:0002Z1][0x00630d3c-0x00630dc8.MenuVarietyPaneVtableData](by-memory/0x00630d3c-0x00630dc8.MenuVarietyPaneVtableData.md)'s marker-only coverage, not as raw table arrays.
- 2026-06-11 A002 Batch 199 parent-gate refresh: raised completion/confidence from `80/86` to `86/88` after splitting and documenting the raw menu-button rectangle helper pair as [UID:0003AH][0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers](by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md). Evidence: live IDA MCP raw-byte/disassembly audit confirmed the exact helper boundaries, fixed button rectangle constants, point-test call path, and `0xcc` boundary padding, so this class now clears the corrected `85/85` direct-parent gate for that child.
- 2026-06-05: Marked reconstructable and attached to [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) because the class is `80/86` and the parent is `86/82`, satisfying the 80/80 parent gate. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x005bc610`, `0x005bc660`, `0x005bc690`, `0x005bc800`, `0x005bc880`, and `0x005bfc80`; `callers` confirms constructor use from `0x004f82fc` inside the main UI graph setup path.
- Completion/confidence score update: existed before as `0/0`; changed to `80/86`. Summary: the in-game menu button pane has strong class role, singleton, method boundary, artwork, click/selector behavior, destructor/thunk, and omission notes, with final helper naming and source-level rewrite still incomplete. Evidence: linked `MenuVarietyPanes` and shared destructor/thunk ranges, IDA-confirmed starts, `g_pMenuVarietyPane`, `g_pMenuVarietySelectPane`, and generated omitted-body notes.
