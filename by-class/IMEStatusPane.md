*** UID:00006I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class Pane;

class IMEStatusPane : public Pane
{
public:
    IMEStatusPane();
    virtual ~IMEStatusPane();

    void SetText(const wchar_t *text, int length);

protected:
    virtual bool OnIMEModeChange(const Event *event);
    virtual void OnPaintFrame();

private:
    wchar_t statusText[256];
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# IMEStatusPane

## UID00029O IME-Layer Dependency - 2026-07-21

The constructor consumes independent [UID:0004VG][g_pIMEPaneLayer](by-global/g_pIMEPaneLayer.md). Its complete Pane inheritance, `statusText[256]`, `SetText(L"Closed", 6)`, zero bounds, pane ordering, methods, vtable, caller caveat, and formal declaration remain unchanged. Dated aggregate-spelling passages below are historical evidence and are superseded only as to the layer expression.

## Status

- Likely source file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Address range: [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md), with destructor wrappers in [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- Current recovered file: `source-3/simroot_v2/class_IMEStatusPane.cpp`
- Confidence: very strong for the status-pane role, method boundaries, vtable evidence, and pane-family source ownership.

## Class Purpose

`IMEStatusPane` is the small ENG/IME mode label. It measures and positions status text near the lower-right screen edge, updates text on IME mode-change events, and paints a compact framed status indicator.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SetText` | [UID:0004BW][0x004e70f0-0x004e71bc.IMEStatusPaneSetText](by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md) | `89/91`; formal C++ populated. Upper-only 255 clamp, counted width/line-height measurement, lower-right `RectBounds` placement, `statusText[256]` copy with explicit terminator, and inherited invalidation. |
| `IMEStatusPane` | [UID:0004BX][0x004e71c0-0x004e728a.IMEStatusPaneConstructor](by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md) | `88/90`; formal C++ populated. Constructs `Pane(0)`, clears `statusText[256]`, calls `SetText(L"Closed", 6)`, initializes zero `RectBounds`, attaches through `g_pIMEPaneLayer`, and preserves zero inbound constructor xrefs as a caveat. |
| `~IMEStatusPane` | [UID:0004BY][0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor](by-memory/0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor.md) | `88/91`; exact empty source destructor definition. Binary restores three IMEStatusPane vptrs and tail-transfers to Pane teardown; UID00031L owns only compiler deleting-wrapper evidence. |
| `OnIMEModeChange` | `0x004e72b0-0x004e72f8` | Handles IME mode event type `11` and switches text between `IME` and `ENG`. |
| `OnPaintFrame` | `0x004e7300-0x004e737b` | Paints background, outline, and current status text. |
| `ScalarDeletingDestructor` | [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) | `92/94`; class-owned compiler ABI wrapper, non-reconstructable/non-emitting with blank formal C++. Primary and -0xa0/-0xa4 vtable routes reach it; it adds only hidden delete flags, MemoryMan-backed free, and the 0x2f8 no-op runtime branch. |

## Evidence Notes

- IDA MCP confirms all listed starts and sizes.
- IDA xrefs to `SetText` come from the constructor and mode-change handler.
- `class_IMEStatusPane.cpp.disabled` emits one adjustor thunk body but omits sibling thunk `0x004e8629`; IDA confirms both are real thunks.
- 2026-05-26 IDA MCP recheck records the omitted `0x004e8629` sibling in [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md); treat it as compiler-generated layout evidence, not a handwritten method.
- 2026-06-07 Batch 090 live IDA MCP on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed the status-pane method boundaries: `SetText` `0x004e70f0-0x004e71bc`, constructor `0x004e71c0-0x004e728a`, ordinary destructor `0x004e7290-0x004e72af`, mode-change handler `0x004e72b0-0x004e72f8`, paint handler `0x004e7300-0x004e737b`, and scalar deleting destructor `0x004e8800-0x004e8855`, with `0xcc` alignment after each body.
- The constructor, ordinary destructor, and scalar deleting destructor reference the three `IMEStatusPane` vtable views at `0x0061c364`, `0x0061c3b0`, and `0x0061c3e0`; `OnIMEModeChange` and `OnPaintFrame` are vtable-referenced from that same table family.
- `SetText` has exactly two direct code callers in this class (`0x004e7249` from the constructor and `0x004e72ec` from the mode-change handler), supporting a compact status-label helper rather than a shared text utility.
- The scalar deleting destructor is reached from the primary status vtable and exact adjustor thunks at `0x004e861e` and `0x004e8629`. Those thunks subtract `0xa0` / 160 and `0xa4` / 164 and tail-jump to the complete-object wrapper; all three routes are compiler ABI liveness, not separate source calls.
- Direct source parent remains [UID:0000K5][IMEPanes](by-file/IMEPanes.md). This class retains `88/90`, owner/emitter `0000K5`, position 0, and the complete current formal class union; UID00031L remains semantic class evidence but has no emitter route.
- Historical 2026-06-08 A001 Batch131 split [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) as the exact scalar wrapper at then-current `85/89`. Fresh 2026-07-15 target analysis supersedes only its score/source disposition: it is now `92/94`, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal, with the old proof-comment mechanism removed.
- Fresh target evidence hashes UID00031L's 85 bytes to `36DB541414B33304808CE4E9E26E9EF5CA275766ACE5125F3C6ED2874F5716E2` and closes 28 instructions/five blocks. The body restores status vptrs `0x0061c364`, `0x0061c3b0`, and `0x0061c3e0`; calls Pane teardown; applies hidden bit-1/bit-4 storage policy; uses MemoryMan-backed normal free or a one-byte runtime no-op with complete size `0x2f8`; and returns complete `this`.
- [UID:0004BY][0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor](by-memory/0x004e7290-0x004e72af.IMEStatusPaneOrdinaryDestructor.md) is the sole source destructor definition. Its exact 31-byte binary body, SHA256 `CACDD06C35C6C88FCD078F5BE400AFB1BAFD0C40CDAA9D2F855154E3F6782915`, stores the same vptr triplet and tail-transfers to Pane with no derived cleanup. Inline `statusText[256]` at `+0xf8` makes the highest-probability human body literally empty.
- UID00031L reads/writes no status-specific field or resource. Explicit hidden flags, vptr stores, base call, delete call, `0x2f8`, adjustors, scalar-wrapper method, and reverse-engineering proof comments are excluded from the class source contract.
- 2026-06-30 B008 callback uses current MCP decompilation of `0x004e70f0`, `0x004e71c0`, and `0x004e72b0` to add `statusText[256]` at `+0xf8`: `SetText` copies into `this+0xf8` with 256-wchar capacity, the constructor clears `0x200` bytes at that offset and initializes `Closed`, and mode-change chooses `IME` or `ENG` for Event type `11`.
- 2026-06-30 B009 implementation callback resolves [UID:0004BW][0x004e70f0-0x004e71bc.IMEStatusPaneSetText](by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md) as a formal emitting child through this class. Current MCP confirmed `sub_4E70F0` size `0xcc`, `0xcc` padding before/after, exactly two direct class-local callers (`0x004e7249` constructor and `0x004e72ec` mode-change), upper-only length clamp, `statusText[256]` at `+0xf8`, lower-right screen `RectBounds`, inherited `SetBounds` vtable slot `+0x2c`, and inherited `InvalidateRect` vtable slot `+0x20` with `m_bounds`.
- 2026-07-01 B011 implementation callback resolves [UID:0004BX][0x004e71c0-0x004e728a.IMEStatusPaneConstructor](by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md) as a formal emitting constructor through this class. Current MCP proved `sub_4E71C0` size `0xca`, padding before/after, `Pane(0)` base construction, compiler-only vtable stores, `statusText[256]` clear, `SetText(L"Closed", 6)`, zero `RectBounds` initialization, inherited layer-slot attachment through `g_mainUiLayerSlots.fpsOverlayLayerContext`, inherited `SetPaneOrder(0, 0)`, zero inbound constructor xrefs as a caveat, and no direct `g_pIMEPane` xref.

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md)
- [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md)

## Changes

- 2026-07-15 B004 UID00031L implementation callback:
  - Preserved: class `88/90`, owner/emitter `0000K5`, position 0, source route, complete formal class bytes including `virtual ~IMEStatusPane();`, all unrelated methods/fields/evidence, and historical Changes content.
  - Changed support text: linked UID0004BY as the `88/91` exact empty source destructor and described UID00031L as `92/94`, class-owned but false/non-emitting/blank compiler ABI evidence with primary/two-adjustor liveness.
  - Summary/evidence: target range/hash/CFG, three-vptr constructor/ordinary/wrapper parity, Pane teardown, hidden flags, MemoryMan free, `0x2f8` one-byte no-op branch, inline `statusText[256]`, and zero target-specific cleanup.

- 2026-07-01 B011 implementation callback:
  - Changed support text without changing class metadata.
  - Summary/evidence: [UID:0004BX][0x004e71c0-0x004e728a.IMEStatusPaneConstructor](by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md) now emits formal `IMEStatusPane::IMEStatusPane()` C++ through this class. B011 current MCP proved the exact `0xca` body, `statusText[256]` clear, `SetText(L"Closed", 6)`, zero bounds setup, layer-slot attachment, order registration, zero-xref caveat, and no direct `g_pIMEPane` dependency.
- 2026-06-30 B009 implementation callback:
  - Changed support text without changing class metadata.
  - Summary/evidence: [UID:0004BW][0x004e70f0-0x004e71bc.IMEStatusPaneSetText](by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md) now emits formal `IMEStatusPane::SetText` C++ through this class. B009 current MCP ids `40`-`46` and `60`-`69` proved the 0xcc-byte body, constructor/mode-change caller closure, upper-only clamp, `statusText[256]` copy, lower-right bounds math, and inherited Pane helper route.
- 2026-06-30 B008 implementation callback:
  - Before: score was `86/89`, `EMITTER_POSITION_OPTIONAL` was blank, and formal C++ was blank.
  - Changed to: score `88/90`, `EMITTER_POSITION_OPTIONAL:0`, and a formal declaration-level class shell with `[[CHILDREN]]`, `SetText`, mode/paint prototypes, and `wchar_t statusText[256]` at `+0xf8`.
  - Summary/evidence: accepted B008 report with current MCP `decompile 0x004e70f0`, `0x004e71c0`, and `0x004e72b0`, confirming status-text copy capacity, constructor clear, `Closed` initialization, and `IME`/`ENG` mode labels.
- 2026-06-08 A001 Batch131 scalar-destructor split:
  - Before: score was `85/88`.
  - Changed to: score `86/89`.
  - Summary/evidence: exact child page [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) now documents the scalar deleting destructor with live IDA adjustor-caller and callee evidence, strengthening the class-level lifecycle inventory.
- Completion/confidence score update: existed before as `0/0`; changed to `78/86`. Summary: IME status label purpose, text update/paint lifecycle, constructor/destructor, mode-change handling, and adjustor-thunk caveat are documented with strong confidence; remaining work is detailed field naming and final C++ reconstruction. Evidence: `IMEPaneFamily`, `IMECandidateQueueAndDestructors`, and `IMEAdjustorThunks` cross-references plus IDA-confirmed method starts.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the IME status label pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE`; left `AUTOGEN_PARENT_UID` blank because the class score is `78/86`, below the 80 completion attachment gate.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004e70f0`, `0x004e71c0`, `0x004e7290`, `0x004e72b0`, `0x004e7300`, and `0x004e8800`, with `SetText` callers from the constructor and mode-change handler.
- 2026-06-07 Batch 090 parent-gate refresh:
  - Before: scores were `78/86`, and `AUTOGEN_PARENT_UID` was blank.
  - Changed to: scores `85/88` and `AUTOGEN_PARENT_UID:0000K5`.
  - Summary/evidence: live IDA MCP reconfirmed method bounds, `SetText` caller closure, vtable refs at `0x0061c364`/`0x0061c3b0`/`0x0061c3e0`, scalar-destructor thunk refs, and the direct [UID:0000K5][IMEPanes](by-file/IMEPanes.md) parent. Final C++ stays blank because detailed field/message-structure names and exact source declarations remain below the 95/95 final-code gate.
