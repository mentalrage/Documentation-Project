*** UID:0000P0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# UserLookPane

## ObjectStatusBlob source boundary

- This file is the UserLook/Profile consumer module. It calls ObjectStatusBlob full child UID0004LL at `0x0059f8dc` and partial child UID0004LM at `0x0059f901`, but parser class/file ownership remains UID00009S/UID0000M6 at `NexusTK/map/ObjectStatusBlob.cpp`.
- The exact 68-byte descriptor includes kind/appearance/variant, all Part-tag equipment ids, gender/direction and composition/posture aliases, action/display, RidableAnimals riding words, all color bytes including shared skin/tint, invisibility/face shape, and explicit padding. Full/partial returns are 43/5.
- Historical title metadata at `+0x2a..+0x30`, generic profile-tail labels, and a generic remap object at `0x0067a760` are superseded. The address is `g_pNewHumanImageLib`; its HAIRCOL vector performs the remap. UID0003RK supplies complete packet/layout source, UID0003RI supplies the complete constructor, and UID0003RM supplies complete OnDraw source. This file remains prose-only at `92/93` and gains no by-file reconstruction metadata.


## Status

- Confidence: very strong for `UserLookPane`, local `MoreInfoPane`/`ProfilePane`, constructor/global/source order, source-live file-local packet-helper grouping, and direct local-child ownership; strong for descriptive source names. Shared `LegendPane` remains separately owned through UID0000KM.
- Proposed module: `ui/panels/UserLookPane.cpp`
- Historical class-first generated leads: `class_UserLookPane.cpp`, `class_MoreInfoPane.cpp`, `class_ProfilePane.cpp`, and shared `class_LegendPane.cpp`. They do not prove original one-class-per-file placement; accepted source groups UserLookPane plus local MoreInfoPane/ProfilePane declarations in `NexusTK/ui/panels/UserLookPane.cpp`.
- Main address doc: [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md), now a non-emitting split index with exact children [UID:0003RI][0x0059f260-0x0059f4fd.UserLookPaneConstructor](by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md) through [UID:0003S4][0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor](by-memory/0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor.md).
- Related shared pane doc: [UID:0000KM][LegendPane](by-file/LegendPane.md)
- Vtable/layout anchor: [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)

## File Role

`UserLookPane.cpp` owns the remote-character look/profile panel created by `GeneralPurposePanel`. It parses the server look/profile payload, stores strings, appearance fields, option fields, and portrait payload data, renders the selected look/profile page, and switches among mode 0 MoreInfo, mode 1 equipment/profile display, mode 2 Bio/profile-text plus PFLOOK portrait, and mode 3 Legend views.

Portrait payloads use two decode paths: a non-`JPF` legacy bitmap path and a `JPF` path that calls the shared [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) at `0x004d07b0` to decode embedded JPEG into the panel's portrait tile context.

`MoreInfoPane` and `ProfilePane` are tiny child pane classes allocated directly by the `UserLookPane` constructor. They only override two virtual gate methods to return false, so they should migrate with the user-look source unless later original-file evidence proves they were reusable elsewhere.

IDA confirms `UserLookPane`, `MoreInfoPane`, and `ProfilePane` vtables at `0x0062eccc-0x0062eeb4`. Current generated metadata reports `vtable_count: 0` for all three, so use the IDA-backed family page for layout evidence.

Historical Batch 093 evidence first separated local MoreInfo/Profile ownership from a provisional LegendPane caveat. Current exact constructor callers and accepted UID0000KM/UID000074 routing resolve LegendPane as a shared external look-pane class. The executable aggregate, [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md), [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md), singleton-slot docs, and UID0003RI independently support this file as the direct parent for UserLookPane plus local MoreInfo/Profile source without absorbing LegendPane.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `UserLookPane` | `0x0059f260-0x005a2523` | Complete source-ready `0xddc` panel: UID0003RI constructs base/member state, three children, global mirror, and exact defaults at position 10; primary `+0x44` `OnDraw` renders the four-mode look/profile UI; primary `+0x48` `OnActivate` parses the look packet; sibling virtuals navigate, switch views, and tear down children/portrait storage. |
| `MoreInfoPane` | constructor `0x005a22e0`; overrides `0x005a2340`, `0x005a2350` | Local read-only `TextEditPane` derivative created at `this + 0xf8`, with exact fixed constructor and false `HandleKeyOrTextEvent`/`OnMouseEvent` bool overrides. |
| `ProfilePane` | constructor `0x005a2360`; overrides `0x005a23c0`, `0x005a23d0` | Local read-only `TextEditPane` derivative created at `this + 0xfc`, with exact fixed constructor and false `HandleKeyOrTextEvent`/`OnMouseEvent` bool overrides; distinct from ProfileDialog. |
| `g_pMoreInfoPane` / MoreInfo child alias slot | [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md) | Zero-initialized `MoreInfoPane*` global alias written once by `UserLookPane::UserLookPane` after constructing the local `MoreInfoPane` child at `this + 0xf8`; no direct reads remain in the final executable, so the live owner is the member while the global is retained source/debug/compatibility state. |
| `UserLookPane` non-deleting destructor | `0x0059f500-0x0059f604` | IDA-confirmed destructor body used for cleanup/EH semantics, but currently unknown to Wave3. |
| `LegendPane` | constructor `0x0056c400-0x0056c493` | Shared external look legend child used by UserLookPane and self-look paths; declaration/body ownership remains [UID:000074][LegendPane](by-class/LegendPane.md) through [UID:0000KM][LegendPane](by-file/LegendPane.md). |

## Exact Executable Children

| Child | Role |
| --- | --- |
| [UID:0003RI][0x0059f260-0x0059f4fd.UserLookPaneConstructor](by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md) | Complete constructor at source position 10: exact base/member/portrait setup, MoreInfo/Profile/Legend creation, sole MoreInfo member/global mirror, child mode/state sequence, typed defaults, and compiler-only cleanup exclusion. |
| [UID:0003RJ][0x0059f500-0x0059f604.UserLookPaneNonDeletingDestructor](by-memory/0x0059f500-0x0059f604.UserLookPaneNonDeletingDestructor.md) | Non-deleting cleanup helper. |
| [UID:0003RK][0x0059f610-0x005a0626.UserLookPaneParseLookPacket](by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md) | Primary-vtable `+0x48` `UserLookPane::OnActivate(const unsigned char *)`; complete look/profile packet population body. The document title remains behavior-oriented. |
| [UID:0003RL][0x005a0630-0x005a0631.UserLookPaneNullStub](by-memory/0x005a0630-0x005a0631.UserLookPaneNullStub.md) | Non-emitting null stub. |
| [UID:0003RM][0x005a0640-0x005a157d.UserLookPaneOnDraw](by-memory/0x005a0640-0x005a157d.UserLookPaneOnDraw.md) | Complete source-ready primary-vtable `+0x44` `void OnDraw()` body with four background modes, ordered text, human/monster status, fourteen equipment images, portrait/fallback resources, action and navigation state, unknown-mode blit/return, and mode-3 invalid-rectangle tail. It is a required use-site emitter for shared [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md): B001/B003 live IDA evidence shows two direct `push offset aStatbutEpf` refs from `sub_5A0640`, with `L"STATBUT.EPF"` in remote-user stat-button frame calls. This supports UserLookPane emission without making the physical pooled literal UserLookPane-owned. |
| [UID:0003RN][0x005a1580-0x005a1985.UserLookPaneOnMouseEvent](by-memory/0x005a1580-0x005a1985.UserLookPaneOnMouseEvent.md), [UID:0003RO][0x005a19a0-0x005a1a6f.UserLookPaneHandleKeyEvent](by-memory/0x005a19a0-0x005a1a6f.UserLookPaneHandleKeyEvent.md) | Complete mouse and translated-key source over the shared four-view state machine: cursor ButtonFrame state, action packet gates, previous/next view graph, right-click help lifetime/resources, PageUp/PageDown transitions, and exact return semantics. |
| [UID:0003RP][0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect](by-memory/0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect.md), [UID:0003RQ][0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton](by-memory/0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton.md) | Complete source-ready signed-short action geometry and canonical `(int y,int x)` first-hit helpers; source calls the rectangle helper while the optimizer inlines its switch in the hit-test binary. |
| [UID:0003RR][0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView](by-memory/0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView.md), [UID:0003RS][0x005a1df0-0x005a1f16.UserLookPaneShowProfileView](by-memory/0x005a1df0-0x005a1f16.UserLookPaneShowProfileView.md), [UID:0003RT][0x005a1f20-0x005a1fe3.UserLookPaneShowBioView](by-memory/0x005a1f20-0x005a1fe3.UserLookPaneShowBioView.md), [UID:0003RU][0x005a1ff0-0x005a2188.UserLookPaneShowLegendView](by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md) | Complete source-ready modes 0/1/2/3, preserving each EPF/legacy teardown, bounds, scroll, inherited-offset, attach/order, invalidation, and intentionally asymmetric child behavior. |
| [UID:0003RV][0x005a2190-0x005a2272.UserLookPaneSendNameCommandPacket](by-memory/0x005a2190-0x005a2272.UserLookPaneSendNameCommandPacket.md), [UID:0003RW][0x005a2280-0x005a22da.UserLookPaneSendTargetActionPacket](by-memory/0x005a2280-0x005a22da.UserLookPaneSendTargetActionPacket.md) | Source-live file-local static `__stdcall` packet helpers at positions 80/90. UID0003RN's behavior-identical inline copies prove liveness despite no direct raw-start xrefs; exact cookie/range-check/alignment remains compiler-owned. |
| [UID:0003RX][0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor](by-memory/0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor.md), [UID:0003RY][0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA](by-memory/0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA.md), [UID:0003RZ][0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB](by-memory/0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB.md) | Emitting local `MoreInfoPane` constructor plus exact false key/mouse overrides; raw-start no-xref remains historical liveness evidence. |
| [UID:0003S0][0x005a2360-0x005a23bd.ProfilePaneRawConstructor](by-memory/0x005a2360-0x005a23bd.ProfilePaneRawConstructor.md), [UID:0003S1][0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA](by-memory/0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA.md), [UID:0003S2][0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB](by-memory/0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB.md) | Emitting local `ProfilePane` constructor plus exact false key/mouse overrides; raw-start no-xref and ProfileDialog exclusion remain explicit. |
| [UID:0003S3][0x005a23d5-0x005a23eb.UserLookPaneAdjustorThunks](by-memory/0x005a23d5-0x005a23eb.UserLookPaneAdjustorThunks.md), [UID:0003S4][0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor](by-memory/0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor.md) | Compiler adjustor thunks and real scalar deleting destructor. |

## Exact Key Input And View Navigation Source

- UID0003RN is the complete `bool UserLookPane::OnMouseEvent(Event *event)` source at `[0x005a1580,0x005a1985)`, `93/94`, secondary EventHandler slot `+0x04`. It consumes vertical-first payload coordinates `y +0x08`, `x +0x0c`; cursor movement preserves outside reset/false, Next-before-Previous hit order, inside-neither no-invalidation fast path, and stale-frame clear/invalidate behavior.
- Left Group and Exchange actions deliberately share `m_exchangeActionState != ButtonVisualState_Disabled`; recognized actions return true even when disabled. Previous/Next preserve the exact 3->2->1->0 EPF-gated and 0->1->2->3 view graph, write pressed/normal ButtonFrame pairs, invalidate, and return true. Right-click deletes prior `g_pSimpleHelpPane` before action filtering, then creates resource-200/201 help at `(this,x,y,5000)` for Group/Exchange or returns false after the deletion.
- UID0003RO is the complete `bool UserLookPane::HandleKeyOrTextEvent(Event *event)` source body at `[0x005a19a0,0x005a1a6f)`. The secondary EventHandler vtable route is base `0x0062ed1c`, slot `+0x08` at `0x0062ed24`; the receiver is complete `UserLookPane + 0xa0`, so raw field `+0xd24` is `m_viewMode +0xdc4`.
- Source dependencies are the accepted Event fields `m_type +0x04`, key `+0x08`, modifiers `+0x10a`; `kEventKeyDown`; `g_pEventMan->TranslateEventKey`; internal `kPaneKeyPageUp`/`kPaneKeyPageDown` values `0x93`/`0x94`; `g_useEpfAssets`; and the four UserLook view helpers. Event/EventHandler/EventMan and globals remain separately owned dependencies, not file ownership transfers.
- Translation occurs before event-type filtering. Only unmodified translated PageUp/PageDown are accepted. PageUp moves modes 3 -> 2 Bio, 2 -> 1 Profile/equipment, and 1 -> 0 MoreInfo only under `g_useEpfAssets`; PageDown moves 0 -> 1 Profile/equipment, 1 -> 2 Bio/profile text, and 2 -> 3 Legend. Recognized zero-modifier keys are consumed even when already at the edge or when the EPF previous-view gate prevents a call; unsupported/type/modifier cases return false.
- Direct helper stores prove MoreInfo/Profile/Bio/Legend modes 0/1/2/3. The prior UID0003RS mode-2 wording is superseded by its store of 1, while ProfileDialog remains separate and shared LegendPane ownership is unchanged. UID0003RN mouse cases 2/3 independently mirror the previous/next graph.
- Source boundaries preserve compiler lowering outside UID0003RO: after UID0003RN ends at `0x005a1985`, a 3-byte NOP, the four-entry mouse switch table `0x005a1789/0x005a16b1/0x005a17d9/0x005a1833`, and 8-byte `0xcc` alignment occupy `[0x005a1985,0x005a19a0)`. A single `0xcc` byte follows UID0003RO at `0x005a1a6f` before UID0003RP at `0x005a1a70`. These are compiler data/padding, not another source body or new child.
- No ordinary caller, target string/table, direct mode write, base fallback, raw packet role, child-pane ownership transfer, alternate source module, or second C++ destination exists. Stale `std::ctype`, unresolved-key/blank-body, Win32-key, helper-rename, edge-false, and generic-input-owner interpretations remain rejected historical evidence.
- This by-file page remains prose-only. The class declaration is emitted through UID0000FP; exact source bodies are emitted by their by-memory children, including UID0003RN/RR/RS/RT/RU, while UID0003RV/RW emit the sole file-local definitions at positions 80/90. Read-only/vtable storage and compiler padding are regenerated or non-emitting.

## Exact View And Packet Helper Source

- UID0003RR `ShowMoreInfoView` stores mode 0 and preserves EPF/legacy Profile/Legend teardown, the legacy-only MoreInfo teardown, exact `(7,205,182,266)` versus `(17,192,174,251)` bounds, current-to-zero MoreInfo scroll pass, root attach/order, and final invalidation.
- UID0003RS `ShowProfileView` stores mode 1 and deliberately repeats Profile/MoreInfo/Legend teardown in both branches. EPF mode ends after teardown; legacy mode alone uses `(17,192,174,251)` and resets/reattaches/orders MoreInfoPane before the common invalidation. This observed oddity is not normalized to ProfilePane.
- UID0003RT `ShowBioView` remains the complete mode-2 source. UID0003RU `ShowLegendView` stores mode 3, removes MoreInfo then Profile without Legend teardown, uses `(7,15,182,265)` or `(17,36,174,251)`, resets Legend scroll, writes inherited `m_verticalScrollBarOffset = 49` only in EPF mode, attaches/orders, and performs the EPF-only maximum/current-to-maximum scroll pass before invalidation.
- UID0003RV `SendUserLookNameCommandPacket` is a position-80 file-local static `__stdcall` helper. It obtains MemoryMan before the empty-name return, converts signed-short `wcslen` through `CP_ACP` into 256 bytes, emits opcode `0x2e` plus one-byte converted length, copies exactly that count, retains local and packet NUL writes, and sends `textLength + 2` without a conversion or sender failure branch.
- UID0003RW `SendUserLookTargetActionPacket` is a position-90 file-local static `__stdcall` helper. It uses a 16-byte local, emits opcode `0x4a`, zero subtype, big-endian target id, explicit byte-six zero, and exactly six sent bytes. Both helpers retain no-start-xref history, but their standalone ABIs and inlined live copies in UID0003RN close the liveness blocker.

## Exact OnDraw, Geometry, And Resource Source

- UID0003RM is one exact source method at `[0x005a0640,0x005a157d)`: 3,901 bytes, SHA256 `7838C2B5B07A811FE20282A537BDD01692FF9B5ADD38AB4DAA24A03B3AC9C373`, 1,356 instructions, 97 blocks, complexity 46, 25 unique callees, no direct code caller, and one primary-vtable data xref. Source ABI is `virtual void UserLookPane::OnDraw()` at primary slot `+0x44`; historical `RenderUserLook` and int-return decompiler residue are superseded.
- Source order is the four-mode background selection, common background blit, ordered five-string text work with repeated width scans, mode-specific HumanObject/NewHuman or MonsterObject status rendering, fourteen independent equipment glyph/palette branches, mode-0 Exchange/Group action controls, mode-2 PFLOOK portrait/FACE fallback and result-unused NATION lookup, then common INVENBUT previous/next frames. Unknown modes blit the initialized context before return; mode 3 intentionally reaches the common tail with invalid action rectangles.
- Mode 1 intentionally calls `Application::GetVersionMajor()` and discards the result. Mode 2 initializes only `SurfaceSpriteBlitOptions::mode` before use; do not value-initialize or invent the rest of the shared record. Zero equipment ids skip their own branch, and repeated source work is retained rather than normalized into a loop.
- `GetActionButtonRect(short actionId, RectBounds&) const` owns Group/Exchange/Previous/Next geometry and invalid `-1` behavior. `HitTestActionButton(int y,int x) const` loops ids 0-3, calls the geometry helper, uses canonical `PointInRect(y,x)`, returns the first hit, else `-1`; binary switch duplication is compiler inlining.
- `+0xdd0/+0xdd4` are `ButtonFrame m_nextButtonFrame` and `ButtonFrame m_previousButtonFrame`. UID0003RN writes each independently as normal/hover/pressed values, and OnDraw uses each for its corresponding navigation frame. Historical hover-action/pressed-action-index names are superseded.
- Exact use-site resource literals are `L"USERLOOK.PAL"`, `L"PFLOOK.EPF"`, and `L"NATION.EPF"` from UID00038X; `L"INVENBUT.EPF"` remains target-local, while shared `L"STATBUT.EPF"` retains owner NONE and emitters UID0000NL/UID0000P0. No standalone resource data/global is handwritten.
- Source/header dependencies remain the complete UID0000FP declaration plus GrafPort, SurfaceSpriteBlitOptions, RectBounds, ObjectStatusBlob/HumanObject/MonsterObject, NewHuman/Monster/Item image libraries, palette/EPF libraries, FontStyle, Application, and accepted globals. Dependency ownership does not transfer into this file.
- Raw vtables/RTTI, cookie checks, EAX residue, switch tables, NOP/alignment, adjustor thunks, scalar wrappers, and physical literal storage are compiler/linker output. This by-file page remains prose-only and must never gain `RECONSTRUCTION_CPP` metadata; UID0000FP and exact by-memory children emit the declaration and methods.

## Exact Constructor And Source Order

- UID0003RI is one 669-byte source-authored constructor at `[0x0059f260,0x0059f4fd)`, SHA256 `C1979834C4EE1FCF5E2895A87F965755A7DB71F8BC103B7F85DD2DE5A0D32F81`. The sole GeneralPurposePanel caller allocates `0xddc`, constructs it, and stores the child at caller `+0x08`; the source remains this UserLookPane module.
- Deterministic emitter metadata is UID0000FP class position 0, UID0002A8 file-level position 5, and UID0003RI class-child position 10 before later UserLookPane child methods. Because class children expand at UID0000FP's `[[CHILDREN]]` marker before later file-level emitters, current generated output places the constructor before the global definition; the class's sole extern provides compile visibility. No duplicate global or target body belongs on this by-file page.
- Source construction is implicit PanelPane and `_AUTOBUF<unsigned char>` setup, ObjectStatusBlob display byte `0x50`, portrait `EPFTileContext::Initialize`, then ordinary `new` expressions for local MoreInfoPane/ProfilePane and shared LegendPane.
- MoreInfo is stored in the member and mirrored once to `g_pMoreInfoPane`, receives mode 1 and false/false edit-active state. Profile receives the same mode/state. Legend receives mode 1, after which the binary intentionally repeats false/false on MoreInfo at `0x0059f44e`; this receiver must not be normalized by symmetry.
- The common tail sets HumanObject status, exact observed appearance/equipment/color/composition defaults, head/right-accessory/left-accessory ids, wide-string terminators, target object id, portrait fallback, `0xff` exchange/group state, view mode 1, profile text terminator, and normal next/previous ButtonFrame values. Fields without observed constructor stores remain untouched.
- MoreInfo/Profile fixed derived constructor sequences are compiler-inlined here but remain source-owned by UID0003RX/UID0003S0. Legend remains source-owned by UID0001HB/UID0000KM. UserLook vptr stores, child vptr stores, allocation guards/frees, returned `this`, EH/cookie/cleanup funclets, RTTI, scalar/adjustor wrappers, and padding are compiler output and are not handwritten.
- UID0003RJ reverse cleanup proves child/portrait/AUTOBUF/base lifetime. Whole-image scans find one target rel32 caller and no absolute target pointer routes, duplicate body, hidden source file, or source null/catch/cleanup branch.
- Five predecessor and three successor `0xcc` bytes remain alignment outside UID0003RI. UID0001KK remains a blank false/non-emitting split index; exact children alone emit source.
- Original lexical spellings and exact global linkage remain confidence caps. Layout, types, behavior, ownership, file placement, one-definition route, and compile order are source-ready.

## Exact UID0003RT Mode-2 Source

- `UserLookPane::ShowBioView()` is one nonvirtual no-argument `void` method at `[0x005a1f20,0x005a1fe3)`, placed after mode-1 `ShowProfileView` and before mode-3 `ShowLegendView` in this source family. UID0003RT alone owns its complete method body; UID0001KK remains a blank non-emitting aggregate.
- Exact body order is mode store 2; MoreInfoPane remove/unregister; LegendPane remove/unregister; `RectBounds(17,120,174,240)`; ProfilePane axis-0 current-position read and reset to zero; root-layer attachment with order 0 and parent `this`; `SetPaneOrder(0,this)`; owner-bounds invalidation.
- Exact members are `m_moreInfoPane +0xf8`, `m_profilePane +0xfc`, `m_legendPane +0x100`, inherited `m_bounds +0x44`, and `m_viewMode +0xdc4`. Root-layer dependency remains `g_mainUiLayerSlots.rootPaneLayerContext`; Pane, ScrollablePane, RectBounds, and ProfilePane stay dependency-owned.
- Three direct calls establish liveness and navigation: mouse previous from mode 3 at `0x005a17e6`, mouse next from mode 1 at `0x005a184d`, and the shared key call at `0x005a1a42` reached by PageUp mode 3 or PageDown mode 1. No parser/programmatic caller, vtable/data route, or duplicate body exists.
- UID0003RK populates `m_profileText[256]`, `m_profileTextLength`, and ProfilePane before switching. UID0003RM mode 2 loads `PFLOOK.EPF`/`PFLOOK.PAL` and paints portrait or fallback state. These complementary consumers fix mode 2 as the Bio/profile-text/portrait page, while mode 1 remains equipment/profile display even though both modes use ProfilePane.
- The source-facing name remains `ShowBioView`. Longer `ShowBiographyView` lacks lexical proof; `ShowProfileTextView` omits portrait presentation; duplicate `ShowProfileView` collides with mode 1; `ShowDescriptionView` is unsupported. The exact original token is only a confidence cap.
- No source statement clears or repopulates ProfilePane, mutates portrait state, focuses the child, branches, null-checks, allocates/frees, or represents the security cookie. Ten leading and thirteen trailing `0xcc` bytes remain alignment outside the method.

## Boundaries

- Keep [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) as the owner of page composition and tab switching. It constructs `UserLookPane`, but it should not own the look/profile parser or rendering code.
- Keep [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md) separate. `ProfileDialog` is profile storage/edit UI; `ProfilePane` here is a read-only child pane used by the remote look panel.
- Do not merge `MoreInfoPane` or `ProfilePane` into generic text editor/control files. They are created by `UserLookPane::UserLookPane` after `sub_58DCE0` child pane construction and have only user-look vtable stubs.
- Treat `LegendPane` as shared look UI. IDA xrefs from self-look and user-look paths (`0x0056571c`, `0x0056ff6e`, and `0x0059f428`) support its accepted separate [UID:0000KM][LegendPane](by-file/LegendPane.md) route; UserLookPane constructs the dependency but does not absorb its source.

## Evidence Notes

- Historical Wave3 reported `UserLookPane` grade `97.2` and no missing refs. That stale generated artifact is retained only as history and was not used as authority.
- IDA confirms `UserLookPane::UserLookPane` at `0x0059f260-0x0059f4fd`, with a direct constructor xref from `GeneralPurposePanel` at `0x004b8477`.
- IDA decompilation of the constructor shows allocation of two `372`-byte child panes, vtable installation for `MoreInfoPane` and `ProfilePane`, and construction of a third `LegendPane` child through `0x0056c400`.
- 2026-06-13 A001 live IDA MCP refresh confirms [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md) is zero-initialized and has exactly one direct xref: the constructor write at `0x0059f35c` storing the just-created `MoreInfoPane*` into `dword_69BED4`.
- 2026-06-20 B004 PE recheck closes the old direct-read/retention caveat for [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md): the slot has no raw file offset and is loader-zeroed in writable `.data`; little-endian immediate search finds only the `0x0059f35c` constructor write; the constructor writes the same `MoreInfoPane*` to member `this + 0xf8` and then global `g_pMoreInfoPane`; no direct read, clear, destructor reset, address-taken reference, or second writer was found. UID0002A8 owns the sole managed definition, UID0000FP owns its extern, and UID0003RI owns the assignment.
- IDA confirms the view-switch methods `0x005a1cd0`, `0x005a1df0`, `0x005a1f20`, and `0x005a1ff0`; each hides/shows child panes, sets mode field `this[881]`, lays out the active child, and invalidates the panel.
- Historical Wave3 did not model IDA function `0x0059f500`; current documentation retains it as the non-deleting cleanup body used inside the scalar deleting destructor at `0x005a23f0`.
- IDA caller checks show `DecodeJpfImageToTileContext` at `0x004d07b0` has a direct caller at `0x0059fff4` inside `UserLookPane::OnActivate` (documented by UID0003RK as packet parsing behavior).

## UID0003RK Accepted Packet And Layout Synchronization

- `UserLookPane::OnActivate(const unsigned char *packetData)` is one exact 4,118-byte, 1,080-instruction, 31-block primary-vtable body at `[0x0059f610,0x005a0626)`. It begins at packet byte 1, reads five byte-length ANSI strings into three 256-wide and two 128-wide destinations, dispatches status encoding to the 43-byte full or 5-byte partial ObjectStatusBlob parser, and preserves zero consumption for unknown status tags.
- Fourteen unrolled equipment records each consume a big-endian id, palette, two skipped byte-length strings, and six fixed bytes. Renderer and SelfLook consumers resolve the accepted Body/LeftHand/RightHand/Head/accessory/necklace/foot/coat/mantle source order; original lexical spellings for several descriptive display fields remain confidence caps.
- More-info/profile/legend text uses TextEditPane APIs owned by TextEditPane.cpp. Portrait storage uses `_AUTOBUF<unsigned char>` plus either JPF decode or a two-argument raw ResourceLayout helper; malformed non-JPF header bytes deliberately zero the stored length and suppress cursor advance. ResourceLayout UID0002KQ remains blank because its own next-row/sentinel source boundary is unresolved.
- Final state includes target object id, exchange/group action bytes, portrait fallback, descriptive trailing/server-profile scalars, target-name highlight, 40-byte portrait EPFTileContext, four-value view mode, hover/pressed indices, and exact padding to `0xddc`. No packet length, defensive bounds checks, unknown-tag rejection, catch block, duplicate parser body, or source ownership transfer may be invented.
- Source exclusions remain exact: UID0003RV/UID0003RW are file-local source definitions, not class methods; their absent direct raw-start routes remain negative evidence and their cookie/range-check tails remain compiler output. LegendPane remains shared; ObjectStatusBlob, PacketBuffer, AUTOBUF, JPF/ImageDecode, ResourceLayout, TextEditPane, EPFTextEditObject, EPFTileContext, MemoryMan, resources/globals, vtables/RTTI, EH, destructors, padding, and rangecheck support remain dependency/compiler owned.

## Caveats

The class-first recovered-source model splits `MoreInfoPane`, `ProfilePane`, and `LegendPane` into separate class artifacts. That is not evidence that the original source used four standalone `.cpp` files. MoreInfoPane and ProfilePane are local classes in `ui/panels/UserLookPane.cpp`; LegendPane is the accepted separately owned shared look-pane dependency through UID0000KM.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | The file page documents the complete split inventory, source-ready constructor/global/class order, exact `OnActivate` packet/layout, complete `OnDraw` and geometry helpers, full `0xddc` surface, local MoreInfo/Profile definitions, shared Legend route, resources/dependencies, portrait behavior, and every source/compiler boundary. |
| Confidence | 93 | IDA/raw-byte/PE, primary/secondary vtables, callers/xrefs, full render/helper CFGs, constructor/destructor, global xref, packet progression, class size, resource uses, and local source-island evidence converge; stripped lexical names remain explicit caps. |
| Parent-gate use | Supports [UID:00008Q][MoreInfoPane](by-class/MoreInfoPane.md) | This file can serve as the direct parent for the local child panes under the strict 85/85 gate; the `LegendPane` uncertainty is a separate shared-child caveat rather than a blocker for MoreInfoPane/ProfilePane ownership. |

## Cross-References

- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:00008Q][MoreInfoPane](by-class/MoreInfoPane.md)
- [UID:0000AV][ProfilePane](by-class/ProfilePane.md)
- [UID:000074][LegendPane](by-class/LegendPane.md)
- [UID:0000KM][LegendPane](by-file/LegendPane.md)
- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md)
- [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md)
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md)
- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)
- [UID:0003F4][0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString](by-memory/0x00624b90-0x00624ba8.SharedStatButtonEpfResourceString.md)

## 2026-08-16 ResourceLayout Dependency Closure

[UID:0003RK][0x0059f610-0x005a0626.UserLookPaneParseLookPacket](by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md) retains its complete parser body and sole external UID0002KQ portrait lookup. Its formal CPP now includes `../../render/ResourceLayoutTable.h` instead of redeclaring `ResourceLayoutRawBufferLookupEntry` locally. The helper remains owned and emitted by [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md); this file only consumes that owner declaration.

Generated `NexusTK/ui/panels/UserLookPane.cpp` must therefore contain the owner include, exactly one parser call, and no local KQ prototype. `UserLookPane.h` remains intentionally absent for this dependency-only correction because no UserLook declaration moves and this by-file page remains prose-only. The file score, parser behavior, child inventory, packet/layout evidence, source order, and all unrelated dependencies remain unchanged.

## Changes

- 2026-08-16 B001 ResourceLayoutTable whole-file implementation: score unchanged at `92/93`. Added the direct UID0002KQ owner-header dependency for UID0003RK, required one parser call with no local helper prototype, and preserved intentional absence of `UserLookPane.h`. No formal by-file channel, source ownership transfer, or parser behavior change was introduced.

- 2026-07-20 B002 UID0003RM additive source-closure callback: retained `92/93`, FILE ownership, and `NexusTK/ui/panels/`; added the complete UID0003RN/RR/RS/RU method inventory, source-live UID0003RV/RW position-80/90 static packet definitions, exact Event/view/teardown/scroll/help/packet/compiler evidence, and source ordering without adding by-file reconstruction metadata or losing the prior OnDraw/constructor/OnActivate/local-pane/global union.
- 2026-07-20 B002 UID0003RM accepted callback: raised `91/92 -> 92/93`; preserved FILE ownership and `NexusTK/ui/panels/` route; added complete OnDraw/geometry/helper/resource/header/source-order/compiler evidence, corrected next/previous ButtonFrame state, and retained all constructor/packet/input/view/local-pane/global history without adding by-file reconstruction metadata.

- 2026-07-19 B002 UID0003RI accepted callback: raised `90/90 -> 91/92`, retained FILE ownership and `NexusTK/ui/panels/` route, added complete constructor/global/class/source order, exact child setup and repeated MoreInfo receiver, typed defaults, reverse lifetime, compiler exclusions, boundaries, negative evidence, and resolved shared Legend disposition. This page remains prose-only and gained no reconstruction metadata.
- 2026-07-16 B001 UID00023W accepted callback: synchronized the current UserLook, MoreInfo, and Profile event source names and bool returns while preserving the complete file inventory, ownership, bodies, layout, dependencies, and historical evidence.
- 2026-07-13 B001 UID0003RT accepted callback support sync: preserved `90/90`, FILE ownership, `NexusTK/ui/panels/` route, and blank by-file formal state; added the exact source-ready mode-2 body/name disposition, parser/renderer role, three caller routes, dependencies, source order, negative evidence, and historicalized the earlier UID0003RO-only source-body statement.
- 2026-07-13 B005 UID0003RO accepted callback: preserved `90/90`, FILE ownership, and `NexusTK/ui/panels/` route while adding the complete key-handler source inventory, Event/EventMan/global/helper dependencies, exact four-view/EPF-gate behavior, compiler table/padding boundaries, negative evidence, and no-owner-transfer disposition. No by-file formal block was added.
- 2026-07-13 B005 UID0003RK accepted callback: raised `89/88 -> 90/90`, preserved FILE ownership and `NexusTK/ui/panels/` route, synchronized the exact `OnActivate` packet/layout, local MoreInfo/Profile declarations and bodies, TextEdit/EPF/image/status dependencies, and all raw/compiler/shared-owner exclusions. No by-file formal block was added.
- 2026-06-16 B001 UserLookPane split execution:
  - Before: score `88/85`; [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) was still a broad reconstructable aggregate.
  - After: score `89/88`; added exact executable children [UID:0003RI][0x0059f260-0x0059f4fd.UserLookPaneConstructor](by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md) through [UID:0003S4][0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor](by-memory/0x005a23f0-0x005a2523.UserLookPaneScalarDeletingDestructor.md) and documented [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) as a non-emitting source-family split index.
  - Evidence: B001 report `tools/leaser/Agents/Agent-B001/research/0001KK-userlookpane-profile-source-split-audit.md` confirmed exact function/raw-helper/thunk boundaries, constructor caller, vtable routes, internal call graph, raw packet/helper bodies, local child-pane constructor/stub evidence, and `UserPane` successor boundary.
- 2026-06-07 Batch 093 parent-gate refresh:
  - Before: `COMPLETION:88`, `CONFIDENCE:80`; strong grouping was documented, but the page did not separate the local child-pane gate from the shared `LegendPane` caveat.
  - After: `COMPLETION:88`, `CONFIDENCE:85`.
  - Why: the executable aggregate, read-only-data page, vtable-family page, and singleton-slot docs agree that `MoreInfoPane` and `ProfilePane` are local children constructed and used by `UserLookPane`. `LegendPane` remains a shared look-pane caveat, so confidence is capped at 85 rather than raised further.
- 2026-06-13 A001 refreshed low-score batch:
  - Score unchanged at `88/85`.
  - Evidence: added [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md) to the proposed contents/cross-references after live IDA confirmed a zero-initialized slot with one constructor write at `0x0059f35c` and no direct reads.
- 2026-06-20 B004 MoreInfoPane singleton-slot incorporation:
  - Score unchanged at `89/88`.
  - Evidence: updated the [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md) row and evidence notes to use source-facing `g_pMoreInfoPane`, close the old source-retention question as a high-probability retained global alias, and keep the live ownership on `UserLookPane::m_moreInfoPane` at `this + 0xf8`.
- 2026-06-02: Set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"` to match the documented `ui/panels/UserLookPane.cpp` placement. The page already records strong UserLookPane/MoreInfoPane/ProfilePane grouping, with the final LegendPane ownership still called out as the remaining caveat.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/80`. Summary/evidence: the page gives detailed source grouping for `UserLookPane`, `MoreInfoPane`, `ProfilePane`, and shared `LegendPane`, with IDA/JPF evidence and memory/global refs; final ownership of shared legend behavior is still a caveat.
