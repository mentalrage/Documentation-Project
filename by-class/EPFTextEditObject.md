*** UID:00004H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TextEditPane;

class EPFTextEditObject : public TextEditObject
{
public:
    EPFTextEditObject(TextEditPane *owner, unsigned char symbolIndex);

    virtual void OnUpdate();

private:
    EPFTileContext m_frame;
};

typedef char EPFTextEditObjectSizeMustBe3C[
    (sizeof(EPFTextEditObject) == 0x3c) ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EPFTextEditObject

## Status

- Current UID0000OJ incorporation: the complete `0x3c` declaration is authoritative formal H after `TextEditObject` and the required `EPFTileContext` include. It emits directly to UID0000ON at explicit file-root position 20 after UID0000EO and TextBoxPane, then closes the shared include guard; UID0003M8 owns the constructor and `OnUpdate` definitions in UID0000ON source order. Destruction is implicit and virtual through the `TextEditObject` base; the compiler-generated scalar deleting wrapper remains no-code.
- Confidence: strong for function boundaries, five-slot vtable identity, caller fan-in, resource selection, and `TextEditPane` support-object ownership; medium for final field names and exact original header/source split.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Main address ranges: `0x005954c0-0x00595590`, `0x005955a0-0x00595622`, and `0x00595630-0x0059566e`
- Reconstruction status: the accepted UID0003RK callback supplies the complete declaration while preserving ownership through TextEditPane.cpp. The older blanket 95/95/blank-block policy is historical and superseded.
- Resolved declaration: `EPFTextEditObject` is a 60-byte `TextEditObject` derivative with an exact 40-byte `EPFTileContext m_frame` at `+0x14`, a `(TextEditPane *owner, unsigned char symbolIndex)` constructor, and live `OnUpdate` override. It does not declare an out-of-line destructor; the virtual base destructor makes the implicit derived destructor virtual.

## UID0000OJ Whole-File Incorporation - 2026-08-16

| Claim | Incorporated disposition |
| --- | --- |
| C0000OJ-425 | Shared `SYMBOLS.EPF` remains an external resource literal rather than local TextEdit storage. |
| C0000OJ-464 | Exact `EPFTextEditObject` `0x3c` layout/declaration moved from CPP to H. |
| C0000OJ-495 | The pre-include CPP declaration and empty child marker are removed from the emitted source route. |
| C0000OJ-504 | Constructor and `OnUpdate` emit through UID0003M8; no handwritten EPF destructor emits because the derived destructor is implicit, and `0x00595630` remains compiler-generated scalar deleting glue. |
| C0000OJ-507 | Complete methods, `EPFTileContext` member, and size assertion are preserved once on this authoritative formal-H page at UID0000ON position 20. |

## Class Purpose

`EPFTextEditObject` is a [UID:0000EN][TextEditObject](by-class/TextEditObject.md) derivative that attaches a symbol image frame to a text-edit object. It constructs the base text-edit payload, initializes the embedded frame-like object at `this + 0x14`, chooses `SYMBOLS.EPF` or `SYMBOLS.EPD` based on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`, checks the frame count through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), and loads the requested frame when the byte-sized frame index is in range.

## Method Families

| Address | Function | Role |
| --- | --- | --- |
| `0x005954c0-0x00595590` | `EPFTextEditObject::EPFTextEditObject` | Initializes `TextEditObject`, installs the EPF text-object vtable, initializes the embedded frame storage, and loads the requested symbol frame when present. |
| `0x005955a0-0x00595622` | `EPFTextEditObject::OnUpdate` | Uses the owner payload at `this + 0x08`, computes a rectangle from stored bounds, invokes the embedded `EPFTileContext` at `this + 0x14`, and returns through the payload owner. [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) proves the derived slot is live for inline objects. |
| `0x00595630-0x0059566e` | scalar deleting destructor | Reinstalls the base `TextEditObject` vtable, releases base storage, and handles scalar-delete flags, including the 0x3c-byte sized-delete path. |

## Evidence Notes

2026-06-04 live IDA pass:

- Binary identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA functions are `0x005954c0-0x00595590` for the constructor and `0x00595630-0x0059566e` for the scalar deleting destructor.
- Direct constructor callers are `0x00566da3` in function `0x00565890`, `0x005707c1` in function `0x005700e0`, and `0x005a0277` in function `0x0059f610`.
- The UID0003RK call at `0x005a0277` allocates exactly `0x3c` bytes, passes the `LegendPane`/TextEditPane owner and one-byte symbol index, then inserts the object at exactly `12 x 12` into rich text. This resolves the constructor surface and target-facing ownership contract.
- The constructor calls the base initializer at `0x004f4a80`, writes `0` to `+0x04`, stores the caller argument at `+0x08`, clears `+0x0c/+0x10`, writes vtable `0x0062e124`, and initializes frame storage at `this + 0x14` through `0x00457a60`.
- The constructor reads [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`; when it is `1`, it checks and loads from `SYMBOLS.EPF` at `0x00610ca4`, otherwise it checks and loads from `SYMBOLS.EPD` at `0x0062e16c`.
- Both branches read [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) at `0x0067a744`, call `0x004d1780` to get the frame count, compare the byte-sized frame index against that count, and call `0x004d02f0` to load into `this + 0x14`.
- 2026-06-12 A004 live IDA MCP confirms exact vtable-data child [UID:0003GG][0x0062e120-0x0062e138.EPFTextEditObjectVtableData](by-memory/0x0062e120-0x0062e138.EPFTextEditObjectVtableData.md): slot targets `0x00595630`, `0x004f4b10`, `0x0041b6c0`, `0x005955a0`, and `0x00594f20`. The constructor stores the vtable at `0x00595517`, and the scalar deleting destructor restores the base [UID:0000EN][TextEditObject](by-class/TextEditObject.md) vtable at `0x0062e048`.
- Fresh read-only canonical IDA evidence on 2026-08-18 resolves the destructor source shape. Session `supervisor_uid0000hf_i0505_discard_retry_20260818` attested exact canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The sole EPF destructor vtable slot `0x0062e124 -> 0x00595630` enters a scalar deleting wrapper that restores the `TextEditObject` vtable, calls `LObject_destructor`, tests delete flags, and performs sized delete `0x3c`; no distinct EPF ordinary-destructor function exists. Because `TextEditObject::~TextEditObject` is virtual, omission of an explicit derived destructor declaration is the correct C++03 source and still regenerates virtual destruction.
- 2026-06-12 A004 `analyze_function` on `0x005955a0` shows this previously unmodeled body is an `EPFTextEditObject` virtual helper: it reads the payload owner from `this + 0x08`, builds a rectangle from `this + 0x24` through `this + 0x30`, calls the embedded frame object at `this + 0x14`, and returns through the payload owner.
- 2026-06-26 B006 [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) implementation adds live TextEditPane draw-callback evidence for this derived vtable slot. When `TextRunFormatData::object` is non-null, the draw callback dispatches the base slot `+0x0c`; for EPF inline objects that slot resolves to `0x005955a0`, so the helper is a live draw/layout hook for inline symbol frames. This does not by itself resolve final source names for the frame helper or class fields, so class formal C++ remains blank.
- 2026-06-12 A004 split the nearby read-only data into exact children [UID:0003GG][0x0062e120-0x0062e138.EPFTextEditObjectVtableData](by-memory/0x0062e120-0x0062e138.EPFTextEditObjectVtableData.md) and [UID:0003GJ][0x0062e16c-0x0062e184.EPFTextEditObjectSymbolsEpdString](by-memory/0x0062e16c-0x0062e184.EPFTextEditObjectSymbolsEpdString.md), both routed here after the class cleared the strict gate.
- Boundary bytes show `0x005954b3-0x005954c0` is `0xcc` padding before the constructor and `0x0059566e-0x00595670` is padding before the next text-edit deleting destructor. The space between the constructor and deleting destructor includes the now-identified `0x005955a0` EPF virtual helper plus alignment before `0x00595630`.

## Current Caveats

- Historical caveat, superseded by the accepted callback: `this + 0x14` was previously left as generic frame storage. Exact base-size, constructor initialization, frame-helper calls, and the established 40-byte [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) layout now support `EPFTileContext m_frame`; original lexical spelling remains a confidence cap rather than a C++ blocker.
- Source placement remains [UID:0000ON][TextEditPane](by-file/TextEditPane.md). UserLookPane.cpp is only a caller/consumer through legend insertion and does not acquire class ownership.
- The current-asset `SYMBOLS.EPF` literal at `0x00610ca4` is shared by other symbol/icon consumers, while [UID:0003GJ][0x0062e16c-0x0062e184.EPFTextEditObjectSymbolsEpdString](by-memory/0x0062e16c-0x0062e184.EPFTextEditObjectSymbolsEpdString.md) covers the legacy `SYMBOLS.EPD` literal local to the text-edit read-only-data block.
- The stale support declaration shape with `RectBounds` fields or direct `Draw`/`GetBounds`/`SetBounds` class members remains rejected. The accepted declaration uses the payload-oriented [UID:0000EN][TextEditObject](by-class/TextEditObject.md) base, exact owner/symbol constructor, `OnUpdate`, and embedded `EPFTileContext` only.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EN][TextEditObject](by-class/TextEditObject.md)
- [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)
- [UID:0003GG][0x0062e120-0x0062e138.EPFTextEditObjectVtableData](by-memory/0x0062e120-0x0062e138.EPFTextEditObjectVtableData.md)
- [UID:0003GJ][0x0062e16c-0x0062e184.EPFTextEditObjectSymbolsEpdString](by-memory/0x0062e16c-0x0062e184.EPFTextEditObjectSymbolsEpdString.md)

## Changes

- 2026-08-22 Agent-B009 UID0000OJ Gate 2A repair: routed the authoritative EPFTextEditObject formal H directly to UID0000ON at position 20 after UID0000EO and TextBoxPane, and placed the shared guard close here as the final ordered H fragment. The class body and implicit-destructor disposition are unchanged.

- 2026-07-13 B005 UID0003RK accepted callback:
  - Raised `86/90 -> 89/92`; owner/emitter/reconstructable route remains UID0000ON/true.
  - Replaced the blank formal block with the then-accepted `0x3c` declaration, `TextEditPane *` owner constructor, explicit virtual-destructor declaration, live `OnUpdate`, `EPFTileContext m_frame`, size assertion, and `[[CHILDREN]]` placement. The explicit destructor declaration is historical and superseded by the 2026-08-18 binary/compiler-shape resolution above.
  - Preserved constructor/helper/destructor ranges, five-slot vtable, all three callers, EPF/EPD resource selection, boundary evidence, old generic-frame assumption as superseded history, and rejection of RectBounds/direct-draw alternatives.
- 2026-06-30 B004 corrected TextEditPane implementation callback:
  - Score unchanged at `86/90`; owner/emitter remain [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and formal C++ remains blank.
  - Added the corrected support-order disposition: this page is the EPF inline-object derivative over current payload-oriented [UID:0000EN][TextEditObject](by-class/TextEditObject.md), with embedded frame storage at `this + 0x14`, constructor/helper/destructor ranges `0x005954c0-0x00595590`, `0x005955a0-0x00595622`, and `0x00595630-0x0059566e`, and no accepted `RectBounds`/direct-draw class declaration.
  - Evidence: the revised B004 [UID:0000ON][TextEditPane](by-file/TextEditPane.md) report reconfirmed the existing EPF constructor/resource/frame evidence, the live draw-callback route through derived vtable slot `+0x0c`, and the remaining exact frame-helper/type-name blocker.

- 2026-06-12 A004 Batch 283:
  - Before: `84/88`, with evidence describing only the first vtable slot and treating the body between the constructor and deleting destructor as separate unmodeled code.
  - After: `86/90`, still attached to [UID:0000ON][TextEditPane](by-file/TextEditPane.md), with exact vtable and legacy resource-string children routed here.
  - Summary/evidence: live IDA MCP confirmed the five-slot vtable child [UID:0003GG][0x0062e120-0x0062e138.EPFTextEditObjectVtableData](by-memory/0x0062e120-0x0062e138.EPFTextEditObjectVtableData.md), identified `0x005955a0-0x00595622` as an EPF virtual helper, and confirmed [UID:0003GJ][0x0062e16c-0x0062e184.EPFTextEditObjectSymbolsEpdString](by-memory/0x0062e16c-0x0062e184.EPFTextEditObjectSymbolsEpdString.md) as the constructor's legacy `SYMBOLS.EPD` literal. Final C++ remains blank because field/type names are not final-source quality.

- 2026-06-20 B005 Rule 26 source-quality incorporation:
  - Score unchanged at `86/90`; final C++ remains blank.
  - Synced the field-name caveat with the TextEditPane support-object report: use descriptive `m_frame` / embedded frame storage at `+0x14`, but do not overclaim the exact original type.
  - Evidence: B005 report confirmed [UID:0000ON][TextEditPane](by-file/TextEditPane.md) placement and support-object ownership while leaving final helper/API type names open.
- 2026-06-26 B006 DrawTextRunCallback inline-object support sync:
  - Score, owner/emitter, and class formal C++ unchanged at `86/90`, [UID:0000ON][TextEditPane](by-file/TextEditPane.md).
  - Added [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) as a live draw-callback callsite for derived slot `+0x0c` / `0x005955a0`.
  - Evidence: B006 MCP session `80de0a67` confirmed the optional `TextRunFormatData::object` dispatch in the draw callback; EPF vtable data routes that slot to `0x005955a0`, strengthening its inline-object draw/layout role while preserving existing final-C++ blockers.
- 2026-06-07 A008 alias cleanup: normalized the constructor's `byte_66DA97` resource branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-06-04:
  - Before: scored `72/80`, left unattached for autogen, used stale provenance/caveats, and recorded end addresses one byte short of the IDA exclusive function bounds.
  - After: scored `84/88`, marked `RECONSTRUCTABLE:TRUE`, attached to [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and kept final C++ blank because the page remains below 95/95.
  - Summary/evidence: live IDA MCP confirmed the binary identity, exact constructor/destructor ranges, three direct constructor callers, the single `EPFTextEditObject` vtable slot at `0x0062e124`, base-vtable restoration at `0x0062e048`, resource branch between `SYMBOLS.EPF` and `SYMBOLS.EPD`, `g_pEPFLib` use through `0x004d1780`/`0x004d02f0`, object/frame offsets, delete-size evidence, and boundary padding.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: symbol-frame text-edit object role, constructor/destructor ranges, EPF/EPD resource selection, and constructor callers were documented; remaining work was exact original file split and fuller embedded frame layout detail.
