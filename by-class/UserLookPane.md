*** UID:0000FP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class MoreInfoPane;
class ProfilePane;
class LegendPane;

extern MoreInfoPane *g_pMoreInfoPane;

class UserLookPane : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_MoreInfo = 0,
        ViewMode_Profile = 1,
        ViewMode_Bio = 2,
        ViewMode_Legend = 3
    };

    enum ActionButtonId
    {
        ActionButton_Group = 0,
        ActionButton_Exchange = 1,
        ActionButton_Previous = 2,
        ActionButton_Next = 3
    };

    enum ButtonVisualState
    {
        ButtonVisualState_Disabled = 0xff
    };

    enum ButtonFrame
    {
        ButtonFrame_Normal = 0,
        ButtonFrame_Hover = 1,
        ButtonFrame_Pressed = 2
    };

    UserLookPane();
    virtual ~UserLookPane();

    virtual void OnDraw();
    virtual void OnActivate(const unsigned char *packetData);
    virtual bool OnMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

    void GetActionButtonRect(short actionId, RectBounds *bounds) const;
    short HitTestActionButton(int y, int x) const;
    void ShowMoreInfoView();
    void ShowProfileView();
    void ShowBioView();
    void ShowLegendView();

private:
    MoreInfoPane *m_moreInfoPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_identityLine3[256];
    wchar_t m_headerText[128];
    wchar_t m_targetUserName[128];
    wchar_t m_moreInfoText[256];
    ObjectStatusBlob m_status;
    unsigned short m_bodyId;
    unsigned char m_bodyPalette;
    unsigned char m_bodyPadding;
    unsigned short m_leftHandId;
    unsigned char m_leftHandPalette;
    unsigned char m_leftHandPadding;
    unsigned short m_rightHandId;
    unsigned char m_rightHandPalette;
    unsigned char m_rightHandPadding;
    unsigned short m_headId;
    unsigned char m_headPalette;
    unsigned char m_headPadding;
    unsigned short m_rightAccessoryId;
    unsigned char m_rightAccessoryPalette;
    unsigned char m_rightAccessoryPadding;
    unsigned short m_leftAccessoryId;
    unsigned char m_leftAccessoryPalette;
    unsigned char m_leftAccessoryPadding;
    unsigned short m_faceAccessory1Id;
    unsigned short m_headAccessory2Id;
    unsigned char m_faceAccessory1Palette;
    unsigned char m_headAccessory2Palette;
    unsigned short m_leftSubAccessoryId;
    unsigned short m_rightSubAccessoryId;
    unsigned char m_leftSubAccessoryPalette;
    unsigned char m_rightSubAccessoryPalette;
    unsigned short m_necklaceId;
    unsigned char m_necklacePalette;
    unsigned char m_necklacePadding;
    unsigned short m_footId;
    unsigned char m_footPalette;
    unsigned char m_footPadding;
    unsigned short m_coatId;
    unsigned char m_coatPalette;
    unsigned char m_coatPadding;
    unsigned short m_mantleId;
    unsigned char m_mantlePalette;
    unsigned char m_trailingProfileState;
    unsigned char m_targetNameHighlighted;
    unsigned char m_paddingB7D[3];
    unsigned int m_targetObjectId;
    unsigned char m_exchangeActionState;
    unsigned char m_groupActionState;
    unsigned char m_portraitFallbackFrame;
    unsigned char m_moreInfoLength;
    unsigned short m_portraitPayloadLength;
    unsigned char m_paddingB8A[2];
    _AUTOBUF<unsigned char> m_portraitBuffer;
    unsigned char m_profileTextLength;
    unsigned char m_paddingB99;
    wchar_t m_profileText[256];
    unsigned char m_paddingD9A[2];
    EPFTileContext m_portraitImage;
    int m_viewMode;
    unsigned char m_statusEncoding;
    unsigned char m_paddingDC9[7];
    ButtonFrame m_nextButtonFrame;
    ButtonFrame m_previousButtonFrame;
    unsigned short m_serverProfileValue;
    unsigned char m_paddingDDA[2];
};

typedef char UserLookPaneSizeMustBeDDC[
    (sizeof(UserLookPane) == 0xddc) ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserLookPane

## ObjectStatusBlob consumer synchronization

- UserLookPane is a consumer, not owner, of the complete 68-byte ObjectStatusBlob UID00009S. Its packet parser invokes full child UID0004LL at `0x0059f8dc` and partial child UID0004LM at `0x0059f901`; source remains UID0000M6.
- Current fields are kind/appearance/variant; exact Body/Coat/equipment ids; context aliases gender/direction and composition/posture; action/display; riding appearance/definition/palette/Y; complete face/hair/skin/body/equipment colors; invisibility/face shape; and explicit padding to byte 68. Full consumes 43 bytes; partial consumes 5.
- Riding metadata comes from MetaMan `RidableAnimals` columns 1-3. `g_pNewHumanImageLib` owns HAIRCOL remap. Historical title/profile-tail/generic-remap field summaries are superseded and must not be read as present class semantics. The accepted UID0003RK callback preserved owner/emitter routing, raised the class to `90/92`, and installed the complete `0xddc` declaration.


## Status

- Confidence: strong for class purpose, exact child method boundaries, vtable routing, and source placement; medium-high for final field/helper names.
- Likely source file: [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- Address range: [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md), with exact source-bearing children [UID:0003RI][0x0059f260-0x0059f4fd.UserLookPaneConstructor](by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md) through [UID:0003RU][0x005a1ff0-0x005a2188.UserLookPaneShowLegendView](by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md) and [UID:0003S4][0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor](by-memory/0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor.md).
- Historical generated lead: `source-3/simroot_v2/class_UserLookPane.cpp`; stale simroot/Wave material is not current evidence and was not used as authority for the accepted declaration.

## Class Purpose

`UserLookPane` is the remote-character look/profile panel. It is constructed by the general-purpose side panel, receives a server-provided look/profile packet, converts multiple text fields to wide strings, parses the character appearance blob, stores portrait payload data, populates text-edit child panes, renders the look overview, and switches among mode 0 MoreInfo, mode 1 equipment/profile display, mode 2 Bio/profile-text plus PFLOOK portrait, and mode 3 Legend views.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | [UID:0003RI][0x0059f260-0x0059f4fd.UserLookPaneConstructor](by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md) | Complete source-ready constructor: implicit PanelPane/AUTOBUF setup, explicit portrait context initialization, three child creations, one member/global MoreInfo mirror, exact child mode/state order, and typed status/string/action/view defaults. |
| non-deleting destructor | [UID:0003RJ][0x0059f500-0x0059f604.UserLookPaneNonDeletingDestructor](by-memory/0x0059f500-0x0059f604.UserLookPaneNonDeletingDestructor.md) | IDA-confirmed cleanup body for child panes, portrait buffer, auxiliary object at `this + 0xd9c`, and base `PanelPane`; no direct xref. |
| `OnActivate` | [UID:0003RK][0x0059f610-0x005a0626.UserLookPaneParseLookPacket](by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md) | Primary-vtable `+0x48` override; parses server look/profile payload strings, appearance blob, fourteen equipment rows, portrait data, rich-text rows, and child text panes before restoring the overview. The document title `ParseLookPacket` remains a behavior label only. |
| null stub | [UID:0003RL][0x005a0630-0x005a0631.UserLookPaneNullStub](by-memory/0x005a0630-0x005a0631.UserLookPaneNullStub.md) | Non-emitting one-byte no-op stub retained as range evidence. |
| `OnDraw` | [UID:0003RM][0x005a0640-0x005a157d.UserLookPaneOnDraw](by-memory/0x005a0640-0x005a157d.UserLookPaneOnDraw.md) | Primary-vtable `+0x44` override with complete source for four backgrounds, repeated text, human/monster status, fourteen equipment images, portrait/fallback, action buttons, and common navigation. `RenderUserLook` is retained only as the historical behavior title. |
| `OnMouseEvent` | [UID:0003RN][0x005a1580-0x005a1985.UserLookPaneOnMouseEvent](by-memory/0x005a1580-0x005a1985.UserLookPaneOnMouseEvent.md) | Complete `93/94` secondary-facet source: cursor ButtonFrame state, action hit tests and packet gates, exact previous/next view graph, delete-before-filter right-click help, and bool returns. |
| `HandleKeyOrTextEvent` | [UID:0003RO][0x005a19a0-0x005a1a6f.UserLookPaneHandleKeyEvent](by-memory/0x005a19a0-0x005a1a6f.UserLookPaneHandleKeyEvent.md) | Secondary EventHandler `+0x08` override: translates Event key/modifier bytes, accepts unmodified internal PageUp/PageDown, traverses modes 0-3 with the EPF previous-view gate, and consumes recognized keys at view boundaries. |
| `GetActionButtonRect` | [UID:0003RP][0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect](by-memory/0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect.md) | Computes action-button rectangles used by paint and hit-test paths. |
| `HitTestActionButton` | [UID:0003RQ][0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton](by-memory/0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton.md) | Maps mouse coordinates to action-button ids. |
| `ShowMoreInfoView` | [UID:0003RR][0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView](by-memory/0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView.md) | Complete `92/93` mode-0 source preserving EPF/legacy teardown asymmetry, exact bounds, MoreInfo current-to-zero reset, root attach/order, and invalidation. |
| `ShowProfileView` | [UID:0003RS][0x005a1df0-0x005a1f16.UserLookPaneShowProfileView](by-memory/0x005a1df0-0x005a1f16.UserLookPaneShowProfileView.md) | Complete `92/93` mode-1 source preserving duplicate three-child teardown, EPF no-reattach behavior, and the legacy MoreInfo reset/attach/order oddity. |
| `ShowBioView` | [UID:0003RT][0x005a1f20-0x005a1fe3.UserLookPaneShowBioView](by-memory/0x005a1f20-0x005a1fe3.UserLookPaneShowBioView.md) | Selects mode `2`; removes and unregisters MoreInfoPane/LegendPane, resets ProfilePane vertical scroll, attaches it at `(17,120,174,240)` through the root pane layer context, orders it, and invalidates `m_bounds`. The page presents packet-populated Bio/profile text with renderer-owned PFLOOK portrait/fallback state. |
| `ShowLegendView` | [UID:0003RU][0x005a1ff0-0x005a2188.UserLookPaneShowLegendView](by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md) | Complete `92/93` mode-3 source preserving exact teardown, both bounds, scroll passes, EPF-only inherited vertical-offset 49, attach/order, and invalidation while leaving LegendPane separately owned. |
| adjustor thunks | [UID:0003S3][0x005a23d5-0x005a23eb.UserLookPaneAdjustorThunks](by-memory/0x005a23d5-0x005a23eb.UserLookPaneAdjustorThunks.md) | Non-emitting compiler adjustor thunks forwarding to the scalar deleting destructor. |
| scalar deleting destructor | [UID:0003S4][0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor](by-memory/0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor.md) | Deletes owned child panes, releases portrait storage, tears down auxiliary state, destroys base pane, and optionally frees `this`. |

### Exact OnDraw and geometry contract

- UID0003RM is exactly `[0x005a0640,0x005a157d)`, 3,901 bytes, SHA256 `7838C2B5B07A811FE20282A537BDD01692FF9B5ADD38AB4DAA24A03B3AC9C373`, 1,356 instructions, 97 blocks, complexity 46, and 25 unique callees. Its sole liveness xref is primary vtable cell `0x0062ed10` at relative `+0x44`; there is no direct code caller or competing owner.
- `virtual void OnDraw()` is the source contract. Branch-dependent EAX residue is ignored, and the historical `RenderUserLook` title is not a source method name.
- `ViewMode` values are MoreInfo 0, Profile 1, Bio 2, Legend 3. `ActionButton` values are Group 0, Exchange 1, Previous 2, Next 3. `ButtonFrame` values are Normal 0, Hover 1, Pressed 2. `StatusKind` values consumed here are HumanObject 1 and MonsterObject 2.
- Mode backgrounds are USERLOOK frames 0/1/3 for modes 0/1/3 and PFLOOK frame 0 for mode 2. Unknown modes preserve the initialized-context background callback and return; mode 3 intentionally reaches the common tail with invalid action rectangles.
- Mode 0 preserves repeated width scans, dark/light text order and positions, HumanObject NewHuman composition, MonsterObject selector 7/frame 0 rendering, Exchange/Group disabled fill behavior, and enabled frames.
- Mode 1 preserves fourteen independent item id/palette branches and the exact body/hand/head/accessory/necklace/foot/coat/mantle centers. Item glyph bounds and draws are singleton-qualified `g_pItemObjImageLib` member calls.
- Mode 2 preserves stored portrait drawing, FACE fallback with only `SurfaceSpriteBlitOptions::mode = 4` assigned, null-palette blit, and the result-unused NATION lookup. The shared options type remains 32 bytes; no invented initialization is accepted.
- Common Next and Previous formulas are `7 * m_nextButtonFrame + 6` and `7 * m_previousButtonFrame + 5`. Mouse writes 0/1/2 prove these fields are visual frames, not hovered/pressed action indices.
- UID0003RP source is `void GetActionButtonRect(short, RectBounds *) const`; UID0003RQ source is `short HitTestActionButton(int y, int x) const`. The latter uses vertical-first coordinates to match `PointInRect(y,x,...)` and factors the optimized binary geometry switch back through the rectangle helper.
- `m_portraitFallbackFrame` remains a bounded source-facing label because its only render use is a result-unused NATION frame lookup. Descriptive identity-string and enum spellings remain confidence caps without changing layout or behavior.
- Security cookies, explicit vptr writes, RTTI/vtable arrays, switch tables, alignment, adjustors, scalar wrappers, and decompiler labels are compiler-owned and absent from class/source declarations.
- Physical USERLOOK/PFLOOK/NATION/STATBUT string and vtable pages remain declaration/use-site generated. They do not own or duplicate UserLookPane source.

### Exact constructor contract

- UID0003RI is exactly `[0x0059f260,0x0059f4fd)`, 669 bytes, SHA256 `C1979834C4EE1FCF5E2895A87F965755A7DB71F8BC103B7F85DD2DE5A0D32F81`. Live IDA MCP and local PE extraction are byte-equal; no range split or merge is required.
- GeneralPurposePanel is the sole constructor caller. It allocates `0xddc`, calls UID0003RI, and stores the resulting UserLookPane child at its own `+0x08`; this composition does not transfer class or source ownership.
- Implicit source construction is `PanelPane` followed by the embedded `_AUTOBUF<unsigned char>` at `+0xb8c`. The explicit portrait operation initializes the 40-byte `EPFTileContext` at `+0xd9c`.
- The constructor creates MoreInfoPane, ProfilePane, and shared LegendPane at `+0xf8/+0xfc/+0x100`. MoreInfo/Profile fixed TextEditPane setup appears inline in the binary because their ordinary derived constructors were compiler-inlined; their separate exact source bodies remain UID0003RX and UID0003S0.
- The MoreInfo child is mirrored once to module state `g_pMoreInfoPane`. The complete declaration therefore includes one compile-visible extern before class emission, while UID0002A8 owns the sole definition at source position 5 and UID0003RI owns the assignment at position 10.
- Child setup order is exact: MoreInfo mode 1 plus false/false edit-active state; Profile mode 1 plus false/false state; Legend mode 1; then a second false/false call on MoreInfo. The final receiver is proven by `[edi+0xf8]` at `0x0059f444` and must not be changed to Legend by symmetry.
- ObjectStatusBlob display/default byte starts at numeric `0x50`. The typed common tail sets HumanObject kind and clears appearance, body, weapon, body color, shield/arrow, full-body, and composition fields; it separately clears UserLook head/right-accessory/left-accessory ids and leaves fields without observed stores untouched.
- String/default order is identity line 2, identity line 1, header, target user name, target object id, portrait fallback, exchange/group action bytes `0xff`, view mode 1, profile text, then next/previous `ButtonFrame` values zero. The historical hover/pressed-action interpretation is rejected by UID0003RN's independent next/previous mouse writes.
- Destructor parity confirms ownership: UID0003RJ removes and destroys all three children, releases portrait context and AUTOBUF storage, and tears down PanelPane in reverse lifetime order.
- Primary/secondary/tertiary vptr stores for UserLook/MoreInfo/Profile, returned `this`, allocation null guards, custom allocator/free calls, SEH registration, cookie, cleanup funclets, RTTI, adjustor/scalar wrappers, and padding are compiler-generated. They are class/source evidence but never handwritten statements.
- Five predecessor and three successor `0xcc` bytes remain outside UID0003RI. No second caller, constructor vtable entry, absolute pointer route, duplicate body, hidden owner, source null branch, catch, or cleanup statement exists.
- Exact original spellings for several descriptive fields and global linkage remain confidence caps only. Accepted types, offsets, layout, behavior, ownership, emitter order, and compile visibility are complete.

### Exact key-handler contract

- The UserLook secondary EventHandler vtable starts at `0x0062ed1c`; slots `+0x00`, `+0x04`, and `+0x08` point to destructor adjustor `0x005a23d5`, `OnMouseEvent` `0x005a1580`, and `HandleKeyOrTextEvent` `0x005a19a0`. The secondary receiver is complete object `+0xa0`; target raw `+0xd24` therefore resolves to `m_viewMode` at complete offset `+0xdc4`.
- `HandleKeyOrTextEvent` is a one-argument `__thiscall` ending in `retn 4` and returning truth through `AL`. It calls `g_pEventMan->TranslateEventKey(event->m_payload.m_key.m_key, event->m_payload.m_key.m_modifiers)` before checking `event->m_type == kEventKeyDown`.
- The accepted Event layout is type `+0x04`, key `+0x08`, and modifiers `+0x10a`. Translated `kPaneKeyPageUp`/`kPaneKeyPageDown` are internal values `0x93`/`0x94`, not Win32 virtual-key codes. Either recognized key requires modifiers zero.
- PageUp moves 3 -> 2 via `ShowBioView`, 2 -> 1 via `ShowProfileView`, and 1 -> 0 via `ShowMoreInfoView` only when `g_useEpfAssets`; PageDown moves 0 -> 1 via `ShowProfileView`, 1 -> 2 via `ShowBioView`, and 2 -> 3 via `ShowLegendView`. A recognized unmodified key returns true even at a boundary or when the EPF gate suppresses the mode-1 previous transition; all other cases return false.
- Direct helper stores fix modes independently: MoreInfo 0 at `0x005a1cf4`, Profile/equipment display 1 at `0x005a1e14`, Bio/profile text 2 at `0x005a1f39`, and Legend 3 at `0x005a2010`. UID0003RN mouse cases 2/3 mirror the previous/next graph. The earlier mode-2 description for `ShowProfileView`, unresolved-key/blank-body state, `std::ctype`, Win32-key, helper-rename, boundary-false, and generic-input-owner alternatives are superseded or rejected.
- Historical callback scope: UID0003RO was the only source-body change in the earlier key-handler pass. The later accepted UID0003RT callback adds its exact method body without changing the complete class declaration above; Event, EventHandler, EventMan, globals, and child panes remain dependencies rather than class/source owners.

### Exact mouse, view, and file-local packet contract

- UID0003RN is exactly `[0x005a1580,0x005a1985)`, 1,029 bytes, secondary EventHandler slot `+0x04`, returning bool through `AL`. It uses Event pointer coordinates in vertical-first order, resets and hit-tests Next before Previous on cursor motion, preserves the already-normal fast path, and invalidates only on observed state changes/hits.
- Left Group and Exchange actions deliberately share the exchange-state disabled gate; both recognized cases return true even when sending is suppressed. Previous and Next preserve the exact four-view graph and frame writes. Right-click performs `delete g_pSimpleHelpPane` before action filtering, then creates five-second resource-200/201 help for Group/Exchange or returns false after the deletion.
- UID0003RR/RS/RT/RU are the four complete member view bodies. Their exact EPF/legacy teardown differences, local bounds, scroll current/target calls, root-layer attach/order, inherited Legend offset 49, and final invalidations remain source behavior; no branch, child, or seemingly mismatched MoreInfoPane operation is normalized.
- UID0003RV `SendUserLookNameCommandPacket` and UID0003RW `SendUserLookTargetActionPacket` are file-local static `__stdcall` definitions emitted through UID0000P0 at positions 80/90, not class declarations. Their behavior-identical UID0003RN inline copies prove liveness despite no start xrefs. The first preserves CP_ACP conversion, narrowed lengths, MemoryMan copy, NUL writes, and exact send length; the second preserves opcode/subtype/big-endian id, explicit byte-six zero, and six-byte send.
- Source order is class declaration, exact member children including OnMouseEvent and all views, then file-local packet helpers. UID0001KK remains non-emitting. Cookie/range-check/switch-table/alignment, vtable/RTTI, adjustor, and scalar-wrapper output remains compiler-owned.

### Exact mode-2 ShowBioView contract

- UID0003RT is one nonvirtual no-argument `void UserLookPane::ShowBioView()` method at `[0x005a1f20,0x005a1fe3)`, 195 bytes, 63 instructions, one basic block, and complexity 1. Owner/emitter remains this class through UID0000P0 `UserLookPane.cpp`; no declaration token, child split, or explicit emitter position is added.
- Exact source order is: store `m_viewMode = 2`; remove then unregister `m_moreInfoPane`; remove then unregister `m_legendPane`; construct bounds `(17,120,174,240)`; read `m_profilePane` axis-0 current scroll and apply target zero; add ProfilePane to the root pane layer with order 0 and parent `this`; call `SetPaneOrder(0,this)`; invalidate inherited `m_bounds`.
- Exact fields are `m_moreInfoPane +0xf8`, `m_profilePane +0xfc`, `m_legendPane +0x100`, inherited `m_bounds +0x44`, and `m_viewMode +0xdc4`. The layer context is accepted `g_mainUiLayerSlots.rootPaneLayerContext` at `0x0069b368`.
- Exactly three calls reach it: UID0003RN at `0x005a17e6` for mouse previous from mode 3 and `0x005a184d` for mouse next from mode 1, plus UID0003RO at `0x005a1a42` for PageUp mode 3 or PageDown mode 1. No parser/programmatic caller, data pointer, vtable entry, callback route, or duplicate body exists.
- Mode 1 and mode 2 intentionally share ProfilePane. Mode 1 remains the equipment/profile-display page; mode 2 is the Bio page whose ProfilePane text was populated by UID0003RK while UID0003RM renders `PFLOOK.EPF`/`PFLOOK.PAL` portrait or fallback state.
- `ShowBioView` is retained as the stable source-facing name. `ShowBiographyView` has no stronger symbol/literal support, `ShowProfileTextView` omits portrait behavior, duplicate `ShowProfileView` conflicts with mode 1, and `ShowDescriptionView` has no supporting lexical evidence. Exact original spelling remains a confidence cap, not a body blocker.
- Negative behavior is explicit: this method does not clear/repopulate/focus ProfilePane, mutate portrait state or text, branch, null-check, allocate/free, add EH source, or return an authored value. Security-cookie lowering and the ten/thirteen surrounding `0xcc` alignment bytes remain compiler-only/non-source.

## Child Panes

- [UID:00008Q][MoreInfoPane](by-class/MoreInfoPane.md) is allocated by the constructor and stored at `this[62]` / `this + 0xf8`, best named `m_moreInfoPane`; the constructor then mirrors that same pointer into [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md), best named `g_pMoreInfoPane`.
- [UID:0000AV][ProfilePane](by-class/ProfilePane.md) is allocated by the constructor and stored at `this[63]`.
- [UID:000074][LegendPane](by-class/LegendPane.md) is allocated through `0x0056c400` and stored at `this[64]`, but is shared with self-look paths and needs a broader owner review.

## Evidence Notes

- Wave3 reports no missing refs for `UserLookPane`.
- IDA confirms the constructor xref from `GeneralPurposePanel` at `0x004b8477`.
- IDA confirms the packet/render/input/view-switch/destructor function starts listed above.
- IDA reports `0x0059f500` as a real function with no normal code xrefs; its body matches the scalar deleting destructor cleanup body without the final conditional delete.
- 2026-06-14 C001 IDA MCP session `b001_0003gy` reconfirmed the method starts and sizes for constructor `0x0059f260` (`0x29d`), non-deleting destructor `0x0059f500` (`0x104`), `ParseLookPacket` `0x0059f610` (`0x1016`), `RenderUserLook` `0x005a0640` (`0xf3d`), mouse/key handlers, action-rect and hit-test helpers, all four view-switch helpers, local child-pane stubs at `0x005a2340`/`0x005a2350`/`0x005a23c0`/`0x005a23d0`, adjustor thunks at `0x005a23d5`, scalar deleting destructor `0x005a23f0` (`0x133`), and successor `0x005a2530`; `0x005a2523` is not a function.
- `analyze_component` confirms constructor calls to child pane setup and `LegendPane` construction, `ParseLookPacket` uses the `JPF` path and calls `0x004d07b0`, and render/input paths call the local action-button/view-switch helpers.
- `xrefs_to 0x0059f260` shows the single constructor call at `0x004b8477` from `GeneralPurposePanel`. The parse/render/mouse/key methods are vtable-referenced from the `UserLookPane` read-only data, while view-switch helpers are called from parse, mouse, and key paths.
- `xrefs_to` for `MoreInfoPane` and `ProfilePane` vtable heads shows constructor installation and cleanup/destructor references; `xrefs_to 0x0069bed4` remains the single constructor write at `0x0059f35c`; `xrefs_to 0x004d07b0` includes the `ParseLookPacket` call at `0x0059fff4`.
- 2026-06-20 B004 PE recheck confirms `0x0069bed4` is zero-filled writable `.data` storage with exactly one whole-executable immediate reference, the constructor write at `0x0059f35c`. No direct read, address-taken use, clear/reset path, or second writer was found. Treat `g_pMoreInfoPane` as a retained source-level singleton/debug/compatibility alias of the live member `m_moreInfoPane`, not as proof that `MoreInfoPane` owns module state or that GeneralPurposePanel/adjacent `.data` owners should absorb the slot.
- `entity_query(kind=names)` over `0x0062eccc-0x0062ef0c` confirms the ordered read-only sequence for `UserLookPane`, `MoreInfoPane`, `ProfilePane`, user-look resource strings, and the `UserPane` successor boundary at `0x0062ef0c`.

## 2026-07-13 Accepted UID0003RK Layout And Vtable Evidence

### Vtable and class facts

- UserLook primary vtable starts `0x0062eccc`; target cell is `0x0062ed14`, relative `+0x48`. Primary `+0x44` points to renderer `0x005a0640`.
- Secondary and tertiary UserLook vtables begin `0x0062ed1c` and `0x0062ed4c`. Constructor allocation caller at `0x004b8457` pushes `0xddc`, proving exact class size.
- MoreInfo vtable cells route `0x005a2340` to secondary key-event slot and `0x005a2350` to primary mouse-event slot. Profile equivalents are `0x005a23c0` and `0x005a23d0`.
- MoreInfo/Profile raw constructors each use the fixed TextEditPane argument tuple `145,108,145,108,128,0,0,1,6,IsLegacyAssetMode(),1,0` and install primary/secondary/tertiary local vtables.
- EPFTextEditObject allocation is 60 bytes. Base TextEditObject is 20 bytes; embedded EPFTileContext at `+0x14` is 40 bytes. EPF vtable slot `+0x0c` points to live helper `0x005955a0`.

### Complete target field map

| Offset | Size | Recommended field / exact role |
| --- | ---: | --- |
| `+0x0f8/+0x0fc/+0x100` | 12 | `m_moreInfoPane`, `m_profilePane`, `m_legendPane` pointers |
| `+0x104/+0x304/+0x504` | 512 each | three 256-wide-character identity/display lines |
| `+0x704/+0x804` | 256 each | 128-wide-character header and target-user-name strings |
| `+0x904` | 512 | 256-wide-character more-info text |
| `+0xb04` | 68 | exact `ObjectStatusBlob m_status` |
| `+0xb48..+0xb5e` | 24 | Body, LeftHand, RightHand, Head, RightAccessory, LeftAccessory id/palette pairs |
| `+0xb60/+0xb62/+0xb64/+0xb65` | 6 | FaceAccessory1 and HeadAccessory2 ids then palettes |
| `+0xb66/+0xb68/+0xb6a/+0xb6b` | 6 | LeftSubAccessory and RightSubAccessory ids then palettes |
| `+0xb6c/+0xb6e` | 3 | Necklace id/palette; `+0xb6f` padding |
| `+0xb70/+0xb72` | 3 | Foot id/palette; `+0xb73` padding |
| `+0xb74/+0xb76` | 3 | Coat id/palette; `+0xb77` padding |
| `+0xb78/+0xb7a` | 3 | Mantle id/palette |
| `+0xb7b/+0xb7c` | 2 | trailing profile state; target-name highlight flag |
| `+0xb7d..+0xb7f` | 3 | alignment padding |
| `+0xb80` | 4 | target object id |
| `+0xb84/+0xb85/+0xb86/+0xb87` | 4 | exchange action, group action, portrait fallback frame, converted more-info length |
| `+0xb88/+0xb8a` | 4 | portrait payload length plus two-byte padding |
| `+0xb8c` | 12 | embedded `_AUTOBUF<unsigned char>` |
| `+0xb98/+0xb99` | 2 | converted profile length and padding |
| `+0xb9a` | 512 | profile text; followed by two-byte alignment at `+0xd9a` |
| `+0xd9c` | 40 | portrait `EPFTileContext` |
| `+0xdc4` | 4 | view mode: 0 MoreInfo overview, 1 equipment/profile display, 2 Bio/profile text plus PFLOOK portrait, 3 legend |
| `+0xdc8/+0xdc9..+0xdcf` | 8 | status encoding byte plus alignment |
| `+0xdd0/+0xdd4` | 8 | `ButtonFrame m_nextButtonFrame` / `m_previousButtonFrame`; render formulas and mouse writes prove normal/hover/pressed values 0/1/2 |
| `+0xdd8/+0xdda` | 4 | server profile word plus final padding to size `0xddc` |

### Name confidence and exclusions

- `m_identityLine1`, `m_identityLine2`, `m_identityLine3`, `m_headerText`, `m_trailingProfileState`, and `m_serverProfileValue` are descriptive source-facing names because stripped symbols and all sibling consumers do not recover the original product wording. Their exact types, widths, offsets, and packet behavior are resolved; this lexical uncertainty caps confidence without blocking C++.
- `m_status` is the complete 68-byte dependency-owned `ObjectStatusBlob`. UserLookPane consumes the full/partial parsers and does not own their source. `_AUTOBUF<unsigned char>`, the JPF decoder, the raw ResourceLayout loader, TextEditPane, EPFTextEditObject, EPFTileContext, and LegendPane likewise remain dependency-owned.
- UID0003RV/UID0003RW are source-live file-local definitions rather than class methods; their absent start xrefs remain historical negative evidence. Scalar/adjustor destructors, EH cleanup, vtables/RTTI, strings, padding, cookie, and rangecheck machinery remain compiler/linker output beyond the declarations and exact child source already represented here.

## Cross-References

- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- [UID:00008Q][MoreInfoPane](by-class/MoreInfoPane.md)
- [UID:0000AV][ProfilePane](by-class/ProfilePane.md)
- [UID:000074][LegendPane](by-class/LegendPane.md)
- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md)

## Changes

- 2026-07-20 B002 UID0003RM additive source-closure callback: retained `92/94`, UID0000P0 owner/emitter, position 0, complete `0xddc` formal and all prior source; synchronized complete UID0003RN/RR/RS/RU member behavior, source-live UID0003RV/RW file-local nonmember disposition, exact source order, and compiler exclusions without altering the accepted class block.
- 2026-07-20 B002 UID0003RM accepted callback: raised `91/93 -> 92/94`; preserved UID0000P0 ownership, position 0, the complete `0xddc` layout, all prior packet/input/view/local-pane/global declarations, and closing brace before `[[CHILDREN]]`; installed the complete class formal with `ViewMode`, `ActionButton`, `ButtonFrame`, and `StatusKind` enums; synchronized primary `OnDraw`, y/x hit testing, and typed next/previous frame fields; and retained the old RenderUserLook/hover-action/pressed-action spellings as rejected historical labels.

- 2026-07-19 B002 UID0003RI accepted callback: raised `90/92 -> 91/93`, retained UID0000P0 owner/emitter and reconstructable state, set position 0, preserved the complete `0xddc` class block, added the sole compile-visible `g_pMoreInfoPane` extern, and incorporated the exact constructor range/caller/base/member/child/global/field/order/lifetime/compiler/negative-evidence contract without changing existing packet/render/input/view content.
- 2026-07-16 B001 UID00023W accepted callback: preserved the complete `0xddc` declaration and all fields while correcting only the primary mouse return to `bool` and the secondary EventHandler `+0x08` declaration to `bool HandleKeyOrTextEvent(Event *)`; historical `int OnMouseEvent` and `OnKeyEvent` spellings are superseded by the direct ABI/vtable contract.
- 2026-07-13 B001 UID0003RT accepted callback support sync: preserved `90/92`, UID0000P0 ownership/emission, and the complete managed declaration byte-for-byte; corrected the four-mode map and incorporated the exact mode-2 body order, fields, geometry, scroll/layer behavior, three callers, parser/renderer role, selected name, negative evidence, and historicalized provisional naming/body assumptions.
- 2026-07-13 B005 UID0003RO accepted callback: preserved `90/92`, UID0000P0 ownership/emission, exact `0xddc` layout, and the managed class declaration byte-for-byte while adding the complete secondary-slot/receiver, Event/translation, PageUp/PageDown transition-and-consume, mode-store, mouse-corroboration, and rejected-alternative contract.
- 2026-07-13 B005 UID0003RK accepted callback: raised `88/90 -> 90/92`, preserved UID0000P0 ownership/emission, replaced the blank formal block with the complete `0xddc` `PanelPane` derivative, and synchronized the `OnActivate` slot, fields, local panes, target consumers, confidence caps, and rejected historical aliases.
- 2026-06-16 B001 UserLookPane split execution:
  - Before: score `86/86`; methods were listed as address ranges under the broad [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) aggregate.
  - After: score `88/90`; method table links to exact child pages [UID:0003RI][0x0059f260-0x0059f4fd.UserLookPaneConstructor](by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md)-[UID:0003RU][0x005a1ff0-0x005a2188.UserLookPaneShowLegendView](by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md) and [UID:0003S4][0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor](by-memory/0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor.md), with [UID:0003S3][0x005a23d5-0x005a23eb.UserLookPaneAdjustorThunks](by-memory/0x005a23d5-0x005a23eb.UserLookPaneAdjustorThunks.md) kept as non-emitting compiler thunk context.
  - Summary/evidence: B001 report `tools/leaser/Agents/Agent-B001/research/0001KK-userlookpane-profile-source-split-audit.md` confirmed exact child boundaries, vtable refs, constructor caller, internal call graph, raw-byte/PE checks, and source placement through [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the constructor, packet parse, render, input, view-switch, adjustor thunk, and destructor starts from `0x0059f260` through `0x005a23f0`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because field naming and source placement were below the final-source code-entry bar.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the constructor, packet parse, render, input, action-button, view-switch, destructor, child-pane, xref, and boundary documentation; confidence remains capped by medium confidence on some generated field names and the `LegendPane` ownership caveat.
- 2026-06-14 C001 refreshed low-confidence batch:
  - Before: `COMPLETION:86`, `CONFIDENCE:82`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA MCP reconfirmed all method/stub boundaries, the `0x005a2523` exclusive end, the single `GeneralPurposePanel` constructor caller, parse/render/input vtable references, local child vtable writes/cleanup refs, `MoreInfoPane` singleton-slot write, JPF decode call, and read-only-data successor boundary. Confidence clears the strict gate, while final C++ remains blank because exact field names and shared `LegendPane` placement are not final-source complete.
- 2026-06-20 B004 MoreInfoPane singleton-slot incorporation:
  - Score unchanged at `88/90`.
  - Summary/evidence: recorded source-facing `m_moreInfoPane` at `this + 0xf8` and `g_pMoreInfoPane` at `0x0069bed4`; PE scan confirms the global has exactly one constructor write and no direct consumers, so the member remains the live ownership mechanism while the global is retained source-level module state emitted through [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
