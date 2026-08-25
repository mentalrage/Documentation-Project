*** UID:00008Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class MoreInfoPane : public TextEditPane
{
public:
    MoreInfoPane();
    virtual ~MoreInfoPane();

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MoreInfoPane

## Status

- Confidence: strong for two-method behavior, vtable placement, inline construction, user-look-local ownership, and high-probability source-retained singleton alias evidence; medium-high for exact global spelling/linkage.
- Likely source file: [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- Address range: [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- Historical generated lead: `source-3/simroot_v2/class_MoreInfoPane.cpp`; stale simroot/Wave material is not current evidence or source authority.

## Class Purpose

`MoreInfoPane` is a minimal read-only child pane used by `UserLookPane` for the more-info view. It is constructed inline by `UserLookPane::UserLookPane` after a generic text/edit pane setup call, then receives its own vtable.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor | [UID:0003RX][0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor](by-memory/0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor.md) | Constructor-shaped raw body with base/setup calls and MoreInfoPane vtable stores; no direct start xref. |
| `HandleKeyOrTextEvent` | [UID:0003RY][0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA](by-memory/0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA.md) | EventHandler secondary `+0x08` override; ignores Event and returns false. Historical `OnKeyEvent`/generic labels are superseded. |
| `OnMouseEvent` | [UID:0003RZ][0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB](by-memory/0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB.md) | Primary `+0x60` bool mouse-event override; ignores Event and returns false. The old generic label is historical only. |

## Evidence Notes

- IDA xrefs to the two functions are vtable slots at `0x0062edd8` and `0x0062edb8`.
- Slot parity closes the contracts: primary `0x0062edb8` is `+0x60` and secondary `0x0062edd8` is `+0x08`; adjacent primary `+0x64` remains inherited TextEditPane key handling and adjacent secondary `+0x04` remains the ScrollablePane pointer/mouse dispatcher.
- IDA decompilation of `UserLookPane::UserLookPane` allocates a `372`-byte pane, calls the common pane constructor, installs `MoreInfoPane` vtables, stores it at `UserLookPane + 0xf8`, and writes the same pointer to [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md).
- [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md) records the `MoreInfoPane` vtable family at `0x0062ed58`, `0x0062edd0`, and `0x0062ee00`, between the `UserLookPane` and `ProfilePane` table families.
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md) independently records the same MoreInfoPane vtable bases, slot targets, and local child-pane placement.
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) records `UserLookPane::ShowMoreInfoView` at `0x005a1cd0-0x005a1dee`, which activates mode `0` and lays out the MoreInfo child pane.
- 2026-06-16 B001 audit confirms raw constructor-shaped body `0x005a22e0-0x005a233d`, false virtual stubs at `0x005a2340` and `0x005a2350`, vtable/data refs, and no direct or hidden route to the raw constructor start. The accepted callback supersedes the old blank-final-C++ disposition: the complete retained constructor source is emitted while the no-direct-start fact remains liveness/confidence history.
- 2026-06-20 B004 PE recheck confirms [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md) is a zero-filled `.data` `MoreInfoPane*` slot with exactly one whole-executable reference: the `UserLookPane::UserLookPane` write at `0x0059f35c`. No `MoreInfoPane` method reads, clears, or takes the address of this storage.

## Ownership And Parent Gate

This class is assigned to [UID:0000P0][UserLookPane](by-file/UserLookPane.md). The accepted callback leaves the direct file route intact, raises this class to `90/92`, and raises the file page to `90/90`; both sides remain above the strict attachment gate.

The ownership is direct because `MoreInfoPane` is constructed inline by `UserLookPane::UserLookPane`, stored as a UserLookPane child at `m_moreInfoPane` / `this + 0xf8`, represented in the UserLook read-only vtable island, and activated by the UserLookPane more-info view switcher. The singleton slot no longer remains an open source-retention caveat: the best current inference is a source-retained `MoreInfoPane *g_pMoreInfoPane = 0;` declaration in `UserLookPane.cpp`, with no runtime consumers in the final executable. That global alias does not broaden ownership to the `MoreInfoPane` class because the class methods never access the storage.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | The complete `TextEditPane`-derived declaration, fixed constructor tuple, exact key/mouse overrides, constructor/store context, vtable bases, read-only-data range, singleton-alias conclusion, view-switch use, and direct parent route are documented and emitted. |
| Confidence | 92 | Independent executable, read-only-data, vtable-family, singleton-slot, raw-byte, and source-neighborhood evidence agree on the class surface and local UserLookPane ownership; only original global spelling/linkage remains inferred. |
| Parent | [UID:0000P0][UserLookPane](by-file/UserLookPane.md) | Child `90/92` and parent `90/90` clear the strict gate; by-structure ownership is direct as a local read-only child pane of the user-look panel. |

## Cross-References

- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- [UID:0003RX][0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor](by-memory/0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor.md)
- [UID:0003RY][0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA](by-memory/0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA.md)
- [UID:0003RZ][0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB](by-memory/0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB.md)
- [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md)
- [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md)

## Changes

- 2026-07-16 B001 UID00023W accepted implementation callback: kept `90/92` and UID0000P0 ownership, changed the two declarations to bool `HandleKeyOrTextEvent(Event *)` and bool `OnMouseEvent(Event *)`, added exact secondary/primary slot evidence, and preserved constructor/no-start/singleton/file/history detail.
- 2026-07-13 B005 UID0003RK accepted callback: raised `86/89 -> 90/92`, preserved UID0000P0 ownership/emission, installed the complete declaration, synchronized exact `TextEditPane` inheritance and `OnKeyEvent`/`OnMouseEvent` names, and retained raw-start/singleton/history evidence.
- 2026-06-16 B001 UserLookPane split execution:
  - Before: score `85/88`; method notes listed only two address ranges.
  - After: score `86/89`; added exact child links [UID:0003RX][0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor](by-memory/0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor.md), [UID:0003RY][0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA](by-memory/0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA.md), and [UID:0003RZ][0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB](by-memory/0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB.md) plus raw constructor no-xref caveat.
  - Evidence: B001 report `tools/leaser/Agents/Agent-B001/research/0001KK-userlookpane-profile-source-split-audit.md` confirmed raw constructor bytes, false-virtual vtable refs, no direct/hidden constructor-start route, and direct UserLookPane source ownership.
- 2026-06-07 Batch 093 parent-gate refresh:
  - Before: `COMPLETION:74`, `CONFIDENCE:86`, and no parent because the class page was too concise and the direct parent was below the stricter confidence gate.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, and parent [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
  - Why: [UID:0000P0][UserLookPane](by-file/UserLookPane.md) was refreshed to `88/85`; the executable aggregate, read-only vtable-data page, vtable-family page, singleton-slot page, and view-switch evidence all support direct user-look-local ownership.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the two always-false virtual methods at `0x005a2340` and `0x005a2350`. Left `AUTOGEN_PARENT_UID` blank at that time because this concise class page had not yet cleared the attachment gate even though [UID:0000P0][UserLookPane](by-file/UserLookPane.md) was the likely source-module parent.
- 2026-06-20 B004 MoreInfoPane singleton-slot incorporation:
  - Score unchanged at `86/89`.
  - Evidence: replaced the older singleton-retention caveat with the high-probability source-retained `g_pMoreInfoPane` conclusion, while preserving that the storage is module-level `UserLookPane.cpp` state and not owned by `MoreInfoPane` methods.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: the small user-look child pane has clear inline construction, vtable, storage, and two-method behavior evidence, but the page is inherently concise because the class only exposes two always-false virtual gates. Evidence: linked UserLookPane/profile range, `UserLookPane::UserLookPane` allocation/store evidence, vtable xrefs, and current Wave3 grade/method count.
