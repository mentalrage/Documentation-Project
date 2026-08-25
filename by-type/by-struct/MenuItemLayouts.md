*** UID:0001V5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "PopupMenuControls.h"

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include <errno.h>
#include <stddef.h>

#include "../../util/LObject.h"
#include "../core/RectBounds.h"

class GrafPort;

struct MenuItemMetrics
{
    int height;
    int width;
};

struct MenuItemStyleFlags
{
    unsigned short bits;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Menu Item Layouts

## Status

- Confidence: very strong for the exact `0x18` base layout, bool roles, natural tail padding, `StringMenuItem` extension, and separator no-field model; exact original field/type spellings remain inferred.
- Current entity kind: recovered layout notes for [UID:00007V][MenuItem](by-class/MenuItem.md), [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md), and [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md).
- Likely owner header/source: `ui/menu/MenuItem.h` / [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md).
- Autogen parent: attached to [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md); the file is recommended at `88/88` and this multi-class layout is `92/94`. File-level attachment is used because the layout spans `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem`.
- Evidence basis: IDA MCP decompilation/disassembly, function-boundary lookup, vtable xrefs, and [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md). `simroot_v2` remains only a lead source and is not used as authority.

## Shared MenuItem Base

| Offset | Size | Meaning | Evidence |
| --- | --- | --- | --- |
| `+0x00` | `4` | primary vtable pointer | Constructors write `MenuItem`, `StringMenuItem`, or `SeparatorMenuItem` vtables here. |
| `+0x04` | `16` | `RectBounds m_bounds` with `{left, top, right, bottom}` | Constructors call the rectangle initializer on `this + 4`; draw helpers read left/top/right/bottom; [UID:0002JJ][0x00516fb0-0x00516fc1.MenuItemGetBounds](by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md) copies the whole field to caller storage and returns that pointer, while [UID:0002JK][0x00516fd0-0x00516fe1.MenuItemSetBounds](by-memory/0x00516fd0-0x00516fe1.MenuItemSetBounds.md) replaces it from a read-only caller rectangle. [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) reads all four dwords to build a centered separator rect with `left+3`, `right-3`, and vertical span around `(top+bottom)/2`. |
| `+0x14` | `2` | state flags word | [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) writes word `1`; [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) writes word `0`. |
| `+0x14` | `1` | bool `m_enabled`, enabled/interactable state | [UID:0002J4][0x00516f70-0x00516f74.MenuItemIsEnabled](by-memory/0x00516f70-0x00516f74.MenuItemIsEnabled.md) returns this byte; [UID:0002JH][0x00516f80-0x00516f8d.MenuItemSetEnabled](by-memory/0x00516f80-0x00516f8d.MenuItemSetEnabled.md) writes it; normal/string constructors set it true, separator construction sets it false, and six MenuPane consumers test it. |
| `+0x15` | `1` | bool `m_selected`, selected/highlighted state | [UID:0002J5][0x00516f90-0x00516f94.MenuItemIsSelected](by-memory/0x00516f90-0x00516f94.MenuItemIsSelected.md) returns this byte; [UID:0002JI][0x00516fa0-0x00516fad.MenuItemSetSelected](by-memory/0x00516fa0-0x00516fad.MenuItemSetSelected.md) writes it; the five-routed selection updater clears/sets it and `StringMenuItem::DrawItem` consumes it. |
| `+0x16` | `2` | natural tail/alignment padding | Base deleting-wrapper size immediate is `0x18`, String storage begins at `+0x18`, and no independent access or source field exists in these bytes. Do not model raw padding members. |

B003 source-quality reanalysis rejects generic `stateFlag0`/`stateFlag1` as current names. The exact original spellings remain inferred, but bool `m_enabled` at `+0x14` and bool `m_selected` at `+0x15` are implementation-ready; `selected/highlighted draw state` remains a semantic alias rather than a separate field.

B002's 2026-06-20 [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) pass confirms how the shared word store should be read in source: `word ptr [this+0x14] = 1` is MSVC coalescing for `m_enabled = true` and `m_selected = false`. This is a layout/storage artifact, not proof of a handwritten `m_stateWord` member assignment. The separator constructor's word clear remains the complementary proof that separators start disabled and unselected without introducing separator-only state fields.

B012's 2026-06-21 [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) pass confirms the same interpretation for the derived string-item constructor. The `StringMenuItem` binary contains the base setup sequence and writes the same `word ptr [this+0x14] = 1` before installing the final string-item vtable and copying `text` into `m_text[0x80]`; source reconstruction should model the state as inherited `MenuItem()` initialization rather than a string-item-specific state word.

2026-06-13 live IDA MCP refresh:

- `lookup_funcs` reconfirmed the modeled `MenuItem` constructor at `0x00516f00` as `0x67` / 103 bytes, the two accessors at `0x00516f70` and `0x00516f90` as `0x04` / 4 bytes each, and the base scalar deleting destructor at `0x005172e0` as `0x3e` / 62 bytes (all decimal values Verified with `int_convert.py`).
- `tools/int_convert.py` also verified `0x10` as 16 bytes for the copied bounds rectangle and `0x11` as 17 bytes for the raw bounds-helper method bodies discussed by the exact child pages and pending coverage rows.
- `get_bytes` and `insn_query` over `0x00516f67-0x00516fe1` reconfirmed the exact raw helper bytes: low-state setter writes `[ecx+14h]`, high-state setter writes `[ecx+15h]`, bounds getter copies `xmmword ptr [ecx+4]` to the caller buffer, and bounds setter copies the caller xmmword into `[ecx+4]`.
- `analyze_function 0x00516400` confirmed `MenuPane` relayout calls each item metric virtual, computes the maximum width, and writes a 16-byte rectangle into `item+0x04` for each entry.
- `insn_query 0x00516c40-0x00516cf3` confirmed previous/next-enabled scans compare `byte ptr [item+14h]`; `insn_query 0x005170f0-0x005171a2` confirmed `StringMenuItem` drawing compares `byte ptr [item+15h]` before the highlighted drawing path.
- `xrefs_to 0x0061eb98/0x0061ebb4/0x0061ebd0` reconfirmed base, string, and separator vtable writes at the constructor/destructor sites recorded in [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md).

2026-07-15 B003 fresh MCP session `64c11373` closes the remaining state-layout blocker:

- Exact four-method bytes and hashes confirm independent byte access at `+0x14` and `+0x15`; setters receive bool-compatible byte values in four-byte x86 stack argument slots, while getters return the bool byte in `al`.
- Six checks at `0x005169af`, `0x00516a47`, `0x00516afe`, `0x00516b4b`, `0x00516c7e`, and `0x00516cde` consume `m_enabled`.
- The selection updater at `0x00516e50`, with five code xrefs, clears old `m_selected` at `0x00516e95`, sets new `m_selected` at `0x00516ec2`, and invalidates both affected bounds; `StringMenuItem::DrawItem` reads `m_selected` at `0x00517109`.
- Zero state-method vtable cells, direct start xrefs, pointer encodings, local address operands, and whole-file PE VA/RVA/raw-offset/rel32 routes preserve the methods as nonvirtual retained source with likely inlined consumers. These negatives do not support compiler/no-code or a packed bitfield.
- `char`, `unsigned char`, a handwritten `m_stateWord`, bitfields, visibility, active-state, and style-flag models are rejected. The two-byte stores are compiler coalescing of adjacent bool initialization.

## Whole-Object Bounds Access

The `+0x04..+0x13` region is a live 16-byte `RectBounds` object, not an opaque SIMD field or four unrelated integers. UID0002JJ and UID0002JK each perform a complete unaligned 16-byte copy with `movups`, while constructor, relayout, and draw consumers independently address the same left/top/right/bottom members. The SIMD instructions are compiler lowering for a source-level structure assignment and should not appear as an intrinsic member or raw vector in reconstructed source.

UID0002JJ is exactly 17 bytes with SHA-256 `EA9AEECC35E759BF98B38B96CC4E91ED0B2D7916497F84EC4F663FDF693AB315`; UID0002JK is exactly 17 bytes with SHA-256 `C21224F940494FD4BBCB8BBC163A8652492375B88E6A936AFAC51678977F7076`. Exact `int3` fences delimit both retained methods. The getter leaves the explicit output pointer in `eax`, supporting `RectBounds *GetBounds(RectBounds *outBounds) const`; the setter reads but never writes its input, supporting `void SetBounds(const RectBounds *bounds)`.

Neither method appears in the exact `MenuItem` vtable, and exhaustive start-route scans found no direct xref, pointer encoding, vtable cell, or relative-call route. Those negative results constrain liveness confidence but do not weaken the field layout: complete paired bodies, field producers/consumers, and non-wrapper shape preserve an authored nonvirtual API. The byte-identical getter at `0x00554ae0` belongs to a separately modeled Region/motion comparator and is not a second `MenuItem` field accessor.

The final source model therefore keeps a normal `RectBounds m_bounds` member and ordinary `GetBounds`/`SetBounds` methods. `CopyBounds`, `GetRect`/`SetRect`, reference-return, no-argument value return, raw `xmmword`, and padding interpretations are rejected. The exact original lexical spellings remain inferred, but no compiler-generated address/name is required in authored C++.

## StringMenuItem Extension

| Offset | Size | Meaning | Evidence |
| --- | --- | --- | --- |
| `+0x18` | `0x100` | inline UTF-16 label buffer, `wchar_t[0x80]` | [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) calls `wcscpy_s(this + 0x18, 0x80, source)`; [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) and [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) copy from byte offset `+0x18`; [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) scans the same buffer as `m_text` before calling `GrafPort::GetTextWidth`; [UID:0002JA][0x005170f0-0x005171a2.StringMenuItemDrawItem](by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md) draws from the same buffer. |

The minimum recovered `StringMenuItem` object size is therefore `0x118` bytes before allocator padding or compiler bookkeeping.

The `m_text` array is object-owned inline storage, not a heap pointer, borrowed pointer, ref-counted string, STL string, or global. Constructor `0x00516ff0` writes it in place with capacity `0x80`; UID0002J7 and UID0002J9 only read it; measure/draw consume the same field; and UID0002JG's deleting wrapper performs no label cleanup. The source remains valid for the `StringMenuItem` object's lifetime.

Copy destinations remain caller-owned. UID0002J9's concrete `PopupMenuControlPane::OnDraw` consumer passes a `wchar_t[256]` local and count `0x100` through virtual slot `+0x10` at `0x00498414`; the method returns `_wcscpy_s` status and never exposes a pointer/reference/string object to `m_text`. Direct sibling UID0002J7 follows the same ownership rule for its eleven callers. These facts preserve the exact `0x118` layout and require no additional pointer, length, capacity, cleanup, or padding member.

## SeparatorMenuItem Extension

No class-specific data fields are confirmed beyond the shared `MenuItem` base. Its behavior differs through vtable slots: [UID:0002JC][0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions](by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md), [UID:0002JD][0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags](by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md), and [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md), whose source-facing virtual name is `DrawItem(GrafPort *port)`.

[UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) is the concrete constructor proof for separator non-interactivity: it clears the shared state word at `+0x14` after base setup. Current source-style wording should describe this as `m_enabled = false`; no separator-specific data member is introduced, and `m_selected` remains false through the same word clear.

The separator metric and style result structures are modeled as source-level support types:

| Type | Draft layout | Evidence |
| --- | --- | --- |
| `MenuItemMetrics` | `{ int height; int width; }` | [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md), source-facing `StringMenuItem::GetItemSize(GrafPort *port) const`, writes `[0]=14`, `[1]=GrafPort::GetTextWidth(m_text, length)+24`; [UID:0002JC][0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions](by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md) writes `[0]=6`, `[1]=20`. This rejects Win32 `SIZE {cx, cy}` ordering for current docs, and [UID:0002JA][0x005170f0-0x005171a2.StringMenuItemDrawItem](by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md)'s `left+12` text origin supports reading `24` as total horizontal padding. |
| `MenuItemStyleFlags` | `{ unsigned short bits; }`, size `0x02` | `SeparatorMenuItemGetStyleFlags` writes a zero 16-bit result through the hidden result pointer and returns with `retn 4`; that ABI is incompatible with a primitive AX return and resolves the source shape as a small UDT. Exact type/member spellings remain high-probability inference. |

The separator draw slot uses the same `DrawItem(GrafPort *port)` virtual as `StringMenuItem`: it does not add layout fields, but it proves all four inherited bounds members participate in rendering. B004 rejects a separate `DrawSeparator(FittingRoomListPane *)` source contract; the filename remains a visible-behavior label only.

## Complete Class Layout Summary

| Class | Size | Exact recovered source-visible shape |
| --- | --- | --- |
| `MenuItem` | `0x18` | primary vptr `+0x00`; `RectBounds m_bounds` `+0x04..+0x13`; `bool m_enabled` `+0x14`; `bool m_selected` `+0x15`; natural tail padding `+0x16..+0x17` |
| `StringMenuItem` | `0x118` | complete `MenuItem` base followed by `wchar_t m_text[0x80]` at `+0x18..+0x117` |
| `SeparatorMenuItem` | `0x18` | complete `MenuItem` base only; no derived field, secondary vptr, or authored padding member |

The `0x18` and `0x118` scalar-wrapper size constants and the folded Menu/Separator wrapper independently confirm these sizes. Raw vptr stores, adjacent-byte coalescing, and tail padding are compiler layout, not authored fields.

## IDA Type State

| Type | Accepted live prestate | Source/documentation disposition |
| --- | --- | --- |
| `MenuItem` | present, size `0x18`; custom fields match this layout except `lpVtbl` points at unrelated imported COM `MenuItemVtbl` | preserve size/offsets; supervisor Gate 2B repairs only the project vtable pointer type |
| `RectBounds` | present, size `0x10` | preserve unchanged |
| imported `MenuItemVtbl` | present, size `0x34`, 13 COM slots | protect unchanged; not NexusTK's six-slot table |
| `StringMenuItem` | absent | proposed flattened IDA UDT: `MenuItem` base at `0`, inline text at `+0x18`, size `0x118` |
| `SeparatorMenuItem` | absent | proposed flattened IDA UDT: `MenuItem` base only, size `0x18` |
| `MenuItemMetrics` | absent | proposed two-int UDT, `height +0`, `width +4`, size `0x08` |
| `MenuItemStyleFlags` | absent | proposed `unsigned short bits` UDT, size `0x02` |

This page records the accepted read-only state. IDA creation/repair remains supervisor Gate 2B work and is not performed by the ordinary callback.

## Header And Source Contract

The formal H channel owns the support declarations and dependencies needed by all three class pages. The formal CPP channel contains only one `#include "PopupMenuControls.h"`. Class declarations are emitted by their class H channels, and exact method definitions remain in their by-memory CPP children. This prevents support declarations from being emitted into `PopupMenuControls.cpp`, avoids duplicate definitions, and preserves ordinary late-1990s/2000s header/source organization.

## Source-Layout Impact

These layouts support grouping menu item declarations together in the reusable popup-menu/menu-pane source rather than keeping generated one-class files. `StringMenuItem` is a fixed-buffer menu entry, and `SeparatorMenuItem` is a data-light subclass that changes behavior through virtual slots.

## Cross-References

- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md)
- [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md)

## Changes

- 2026-08-11 B010 UID0002J9 layout synchronization:
  - Preserved `92/94`, UID0000MN ownership/emission, position `1`, exact formal support declarations, and all `0x18/0x118/0x18` layout evidence.
  - Added the exact object-owned inline-text lifetime, caller-owned destination, 256-wide virtual consumer, no-pointer-return semantics, and deleting-wrapper no-cleanup proof.
  - Rejected heap/borrowed/ref-counted/STL/global storage and any added pointer/length/capacity/cleanup member without changing physical offsets or sizes.
- 2026-08-01 B003 UID00036I ordinary implementation callback:
  - Raised `89/92 -> 92/94` while preserving owner/emitter UID0000MN, reconstructable true, and position `1`.
  - Moved `MenuItemMetrics` and `MenuItemStyleFlags` from CPP to the exact H block with required includes/forward declaration; CPP now contains only `#include "PopupMenuControls.h"`.
  - Added the exact `0x18/0x118/0x18` class layout summary, resolved the two-byte style result as a UDT through its hidden-result ABI, and recorded the current present/absent/colliding IDA type state without mutating IDA.
  - Preserved all bounds/state/String/Separator layout evidence, hashes, consumers, rejected alternatives, and changes history.

- 2026-07-24 B005 accepted UID0002JJ support sync:
  - Score and metadata remain `89/92`, owner/emitter UID0000MN, reconstructable true, and position `1`; the support-type formal is unchanged.
  - Synchronized the UID-preserving bounds-page paths and incorporated exact whole-object `RectBounds` layout, getter pointer-return ABI, const setter input, hashes/fences, exhaustive no-route and no-slot evidence, producer/consumer proof, duplicate-comparator separation, source-level structure-assignment interpretation, and rejected raw-vector/name/ABI alternatives.
  - Preserved the complete state-byte, StringMenuItem, SeparatorMenuItem, metric/style, padding, source-layout, and historical evidence.

- 2026-07-15 B003 accepted UID0002JH callback:
  - Raised `86/90 -> 89/92`; preserved owner/emitter UID0000MN, reconstructable true, position `1`, exact support-type formal, and every unrelated layout/type fact.
  - Made the exact `0x18` base layout current: vptr/inherited state `+0x00`, 16-byte `RectBounds` `+0x04..+0x13`, bool `m_enabled` `+0x14`, bool `m_selected` `+0x15`, and natural tail padding `+0x16..+0x17`; retained the two-byte store row as binary/codegen evidence rather than source structure.
  - Added fresh method ABI/hash/no-route/vtable evidence, six enabled consumers, five-routed selection-update and draw consumption, rejected type/layout alternatives, and source/compiler distinctions. Original lexical spelling remains the score cap.

- 2026-06-30 B008 empty-emitter implementation:
  - Raised from `85/89` to `86/90` and set `EMITTER_POSITION_OPTIONAL:1` so the shared menu support types appear before menu-item class declarations in [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) generated output.
  - Added the accepted formal `RECONSTRUCTION_CPP CODE` block for `MenuItemMetrics { int height; int width; }` and `MenuItemStyleFlags { unsigned short bits; }`.
  - Evidence: current `SeparatorMenuItem::GetDefaultDimensions` and `StringMenuItem::GetItemSize` bodies use height-first metrics, `SeparatorMenuItem::GetStyleFlags` uses a 16-bit wrapper, and the 2026-06-30 B008 MCP pass preserves the existing `RectBounds` dependency as a broader geometry type rather than duplicating it here.
- 2026-06-20 B002 MenuItem constructor source-quality incorporation:
  - Score unchanged at `85/89`.
  - Evidence: [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) now records the exact `66 c7 46 14 01 00` store, source-ready constructor C++, and rejected `m_stateWord=1` interpretation.
  - Layout decision: keep the two-byte storage row for binary evidence, but source-facing docs should model the constructor initialization as `m_enabled=true` and `m_selected=false`.
- 2026-06-13 A003 Goal 2 support refresh:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:88`, with the shared offsets documented but no fresh consumer proof for both state bytes in this page.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:89`.
  - Evidence: live IDA MCP reconfirmed modeled function extents, raw state/bounds helper bytes, `MenuPane` bounds and enabled-byte consumers, `StringMenuItem` highlighted-byte consumer, and vtable write refs. Completion only moves to the low gate because final source-facing flag names remain unresolved.
- 2026-06-17 B003 source-quality incorporation:
  - Replaced generic state-byte wording with high-probability `m_enabled` and `m_selected` roles, while preserving exact-spelling caveats.
  - Added `MenuItemMetrics` and `MenuItemStyleFlags` draft layout notes from the separator metric/style target analysis, including rejected `SIZE` ordering and primitive-result caveats.
- 2026-06-19 B015 SeparatorMenuItem constructor source-quality implementation:
  - Score unchanged at `85/89`.
  - Evidence: [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) now documents the shared state-word clear as source-level `m_enabled=false`, with `m_selected` left false and no separator-specific field introduced.
- 2026-06-20 B004 SeparatorMenuItem draw source-quality implementation:
  - Score unchanged at `85/89`.
  - Evidence: [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) now documents `DrawItem(GrafPort *port)` and its use of all four `m_bounds` fields to build the inset centered separator rectangle. This strengthens the shared bounds-field evidence without adding separator-specific data.
- 2026-06-21 B012 StringMenuItem constructor source-quality incorporation:
  - Score unchanged at `85/89`.
  - Evidence: [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) now records source-ready constructor C++, the inherited `MenuItem()` state interpretation for the `+0x14` word write, and the `m_text[0x80]` inline buffer copy through `wcscpy_s`.
- 2026-06-22 B013 StringMenuItem metric source-quality incorporation:
  - Score unchanged at `85/89`.
  - Evidence: [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) now records source-ready `StringMenuItem::GetItemSize(GrafPort *port) const` C++, confirms the hidden-return `MenuItemMetrics { int height; int width; }` ABI, ties text measurement to `GrafPort::GetTextWidth`, and uses the draw helper's `left+12` origin to support 24 pixels of total horizontal padding.
- 2026-06-06: Attached the shared menu item layouts to [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md). Scores remained `84/88` at that time; this multi-class layout is better parented to the source file than to one subclass.
- Before: layout confidence relied partly on generated `simroot_v2` source and the state word was only summarized broadly.
- Changed to: IDA MCP is the stated authority; exact child memory pages now support the state bytes, string buffer, and separator behavior slots.
- Evidence: IDA MCP `lookup_funcs`, raw disassembly, byte review, decompilation, and vtable xrefs confirmed the child ranges and the byte/field accesses recorded above.
