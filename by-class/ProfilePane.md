*** UID:0000AV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class ProfilePane : public TextEditPane
{
public:
    ProfilePane();
    virtual ~ProfilePane();

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProfilePane

## ObjectStatusBlob consumer boundary

- ProfilePane participates in the UserLook/Profile display family but does not own or parse ObjectStatusBlob source. UserLook's exact full/partial member calls are UID0004LL at `0x0059f8dc` and UID0004LM at `0x0059f901`; ObjectStatusBlob remains UID00009S/UID0000M6.
- The decoded 68-byte value has exact kind/appearance/variant, equipment, context-alias, action/display, riding, color, invisibility/face-shape, and padding fields. Riding `+0x2a..+0x30` is RidableAnimals metadata and `0x0067a760` is NewHumanImageLib/HAIRCOL state.
- Therefore any inherited use of "profile" as a generic name for ObjectStatusBlob tail fields, or any title/generic-remap interpretation, is historical and superseded. Legitimate ProfilePane UI/profile behavior remains current. The accepted callback preserves metadata/route, raises the class to `90/92`, and installs its complete declaration.


## Status

- Confidence: strong for behavior; strong that this is the `UserLookPane` child pane, not the profile-edit dialog.
- Likely source file: [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- Address range: [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- Historical generated lead: `source-3/simroot_v2/class_ProfilePane.cpp`; stale simroot/Wave material is not current evidence or source authority.

## Class Purpose

`ProfilePane` is a minimal read-only child pane shared by `UserLookPane` mode 1 equipment/profile display and mode 2 Bio/profile-text/portrait presentation. It should not be confused with `ProfileDialog`, which owns the profile editing/storage UI.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor | [UID:0003S0][0x005a2360-0x005a23bd.ProfilePaneRawConstructor](by-memory/0x005a2360-0x005a23bd.ProfilePaneRawConstructor.md) | Constructor-shaped raw body with base/setup calls and ProfilePane vtable stores; no direct start xref. |
| `HandleKeyOrTextEvent` | [UID:0003S1][0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA](by-memory/0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA.md) | EventHandler secondary `+0x08` override; ignores Event and returns false. Historical `OnKeyEvent`/generic labels are superseded. |
| `OnMouseEvent` | [UID:0003S2][0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB](by-memory/0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB.md) | Primary `+0x60` bool mouse-event override; ignores Event and returns false. |

## Evidence Notes

- Historical Wave3 reported `ProfilePane` grade `97.5`, two active methods, and no missing refs; that stale artifact is retained as history only and was not used as authority.
- IDA xrefs to the two functions are vtable slots at `0x0062ee8c` and `0x0062ee6c`.
- Slot parity closes the contracts: primary `0x0062ee6c` is `+0x60` and secondary `0x0062ee8c` is `+0x08`; adjacent primary `+0x64` and secondary `+0x04` remain inherited TextEditPane key and ScrollablePane pointer/mouse dispatch.
- IDA decompilation of `UserLookPane::UserLookPane` allocates a `372`-byte pane, calls the common pane constructor, installs `ProfilePane` vtables, and stores it at `UserLookPane::this[63]`.
- `UserLookPane::ShowProfileView` and `UserLookPane::ShowBioView` both lay out this child pane through the stored pointer. Shared child use is intentional and does not make both public modes the same view.
- 2026-06-16 B001 audit confirms raw constructor-shaped body `0x005a2360-0x005a23bd`, false virtual stubs at `0x005a23c0` and `0x005a23d0`, ProfilePane vtable/data refs, and no direct or hidden route to the raw constructor start. The accepted callback supersedes the old blank-final-C++ disposition: complete retained constructor source is emitted while the no-direct-start fact remains confidence history.

## Shared Mode-1 And Mode-2 Use

- UID0003RS mode 1 is the equipment/profile-display page. UID0003RT mode 2 is the Bio page combining the packet-populated profile text in this pane with UID0003RM's `PFLOOK.EPF`/`PFLOOK.PAL` portrait or fallback rendering. The shared `ProfilePane` class name is therefore storage/presentation evidence, not a reason to rename mode 2 to `ShowProfileView`.
- UID0003RK clears this pane, converts the byte-length ANSI profile string into `m_profileText[256]`, stores `m_profileTextLength`, replaces pane text, and resets selection before a view-switch method is called.
- UID0003RT reads this pane's current axis-0 scroll position, applies target zero, then attaches it at `RectBounds(17,120,174,240)` with order 0, parent UserLookPane, and the root pane layer context before ordering it against the parent.
- UID0003RT does not clear, repopulate, focus, hide, allocate, or destroy this pane. Those tasks belong to parser/construction/destruction or do not occur. The view helper only resets vertical position and changes layer placement.
- ProfilePane remains owned/emitted by UID0000P0 with its declaration and child bodies unchanged. UID0003RT is owned/emitted by UID0000FP; consuming this child does not transfer method ownership to ProfilePane or ProfileDialog.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | The complete `TextEditPane`-derived declaration, fixed constructor tuple, exact key/mouse overrides, UserLookPane construction/store context, ProfilePane vtables, and ProfileDialog separation are documented and emitted. |
| Confidence | 92 | Independent executable, vtable-family, raw-byte, constructor-context, and view-consumer evidence agree on the class surface and local UserLookPane ownership. |
| Parent | [UID:0000P0][UserLookPane](by-file/UserLookPane.md) | Child `90/92` and parent `90/90` clear the strict gate; ownership remains direct as a local read-only child pane of the user-look panel, never the editable ProfileDialog. |

## Cross-References

- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- [UID:0003S0][0x005a2360-0x005a23bd.ProfilePaneRawConstructor](by-memory/0x005a2360-0x005a23bd.ProfilePaneRawConstructor.md)
- [UID:0003S1][0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA](by-memory/0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA.md)
- [UID:0003S2][0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB](by-memory/0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB.md)

## Changes

- 2026-07-16 B001 UID00023W accepted implementation callback: kept `90/92` and UID0000P0 ownership, changed the two declarations to bool `HandleKeyOrTextEvent(Event *)` and bool `OnMouseEvent(Event *)`, added exact slot evidence, and preserved constructor/no-start/ProfileDialog/file/mode-sharing history.
- 2026-07-13 B001 UID0003RT accepted callback support sync: preserved `90/92`, UID0000P0 ownership/emission, and the complete declaration/child bodies; clarified intentional mode-1/mode-2 sharing, exact mode-2 scroll/layout use, packet-populated text plus PFLOOK portrait role, non-ownership, and negative behavior without changing class C++.
- 2026-07-13 B005 UID0003RK accepted callback: raised `85/89 -> 90/92`, preserved UID0000P0 ownership/emission, installed the complete declaration, synchronized `TextEditPane` inheritance and exact key/mouse overrides, and retained raw-route/ProfileDialog/history evidence.
- 2026-06-16 B001 UserLookPane split execution:
  - Before: score `82/88`; the class was below the strict 85 completion gate even though ownership was known.
  - After: score `85/89`; added exact child links [UID:0003S0][0x005a2360-0x005a23bd.ProfilePaneRawConstructor](by-memory/0x005a2360-0x005a23bd.ProfilePaneRawConstructor.md), [UID:0003S1][0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA](by-memory/0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA.md), and [UID:0003S2][0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB](by-memory/0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB.md) plus raw constructor no-xref caveat and score rationale.
  - Evidence: B001 report `tools/leaser/Agents/Agent-B001/research/0001KK-userlookpane-profile-source-split-audit.md` confirmed raw constructor bytes, false-virtual vtable refs, no direct/hidden constructor-start route, ProfileDialog separation, and direct UserLookPane source ownership.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and assigned parent `0000P0`.
  - Before: reconstruction autogen classification and parent were blank despite documented vtable-backed virtual gate methods in the remote user-look/profile pane family.
  - After: classified as reconstructable source attached to [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
  - Evidence: live IDA MCP `lookup_funcs` confirms modeled starts at `0x005a23c0` and `0x005a23d0`; existing [UID:0000P0][UserLookPane](by-file/UserLookPane.md) evidence keeps `ProfilePane` as a read-only child pane rather than the editable `ProfileDialog`. The class score is `82/88` and parent file score is `88/80`, satisfying the 80/80 attach gate.

- 2026-05-30: Changed completion/confidence from `0/0` to `82/88`.
  - Before: The page was unevaluated even though it described the pane's narrow purpose and two confirmed virtual gates.
  - After: Scored as high confidence and good completion for a small child pane, with no claim that it is the editable profile dialog.
  - Evidence: Existing evidence notes tie both functions to vtable slots and to `UserLookPane` construction/show-profile/show-bio usage.
