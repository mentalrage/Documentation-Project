** TARGET-REPORT-UID:0004HH **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004HH ClanAttrInputDialogConstructor Source-Quality Report




## Finalized Report / Current Recommendation

The accepted C01-C16 callback is implemented. [UID:0004HH] `0x00489600-0x00489de1.ClanAttrInputDialogConstructor` is now a source-emitting first-draft constructor with the complete ABI/body, six counted packet strings, all eleven controls, inherited helper calls, resource and layer dependencies, object fields, caller family, and exact range. The old helper/control/UI-label no-code blocker is superseded in the target and support documentation.

Canonical owner/emitter [UID:000024] `ClanAttrInputDialog`, emitter position `1`, and source route [UID:0000I8] `Clan` / `NexusTK/social/Clan.cpp` are preserved. No split, rename, or one-off `ClanDialogs` move was applied. Current scores are target `90/92`, class support `88/90`, layout support `87/91`, parent `90/92`, and file `90/85`.

All ledger entries below have callback verification states. Five accepted `by-*` files were edited under short leases and passed one scoped validator each; the final Clan validator waited for generated output. No lifecycle, report-move/archive, manual generated/coverage/tracker/supervisor, or IDB command was run.

## Supporting Research

- The current target page and [UID:00010L] parent split report exact bounds and the earlier no-code decision. Their stale blocker list was treated as a research queue, not as proof that source-quality C++ is impossible.
- [UID:00010J] `ClanNameInputDialogCore` and [UID:00012U] `DialogPaneSlideAnimation` provide accepted family conventions for counted CP_ACP packet text, dialog controls, modal setup, and horizontal slide opening.
- [UID:0003B9] `ClanModalDialogResourceStrings` proves the full `DLGCLAN2.EPF` string and both target references.
- [UID:00021S] `ClanStatusPacketDialogHandlers`, [UID:0002O3] `ClanEnlistInputDialogSubmitEnlistment`, [UID:0002O5] `ClanChangeInputDialogSubmitClanChange`, and their class/layout pages constrain live derived construction and inherited field semantics.
- The executed B009 `00010L-ClanAttrInputDialogCore-source-quality.md` report was searched and opened as a historical lead. Its helper-name blocker is superseded by current MCP plus accepted `DialogPane`, `Pane`, control-constructor, layer-slot, and global support.
- Prior B003/B004/B012 submitter research was used only to locate support pages. Every recommendation material to this target was rechecked against the active IDB.
- No Wave 3 notice was needed to resolve this assignment.

## Target

| Field | Value |
| --- | --- |
| UID | `0004HH` |
| Page | `by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md` |
| IDA function | `sub_489600` |
| Exact half-open range | `0x00489600-0x00489de1` |
| Size | `0x7e1` / 2017 bytes |
| Source-facing entity | `ClanAttrInputDialog::ClanAttrInputDialog(const unsigned char *packet)` |
| Current owner/emitter | [UID:000024] `ClanAttrInputDialog` |
| Current source route | [UID:0000I8] `Clan` / `NexusTK/social/Clan.cpp` |
| Pre-callback score | `86/90` |
| Current score | `90/92` |

## Current Target State

- `RECONSTRUCTABLE:TRUE`, canonical owner `000024`, emitter `000024`, optional position `1`, exact range, and parent relationship remain unchanged.
- The managed formal block contains the accepted constructor and exactly matches this report's formal insertion text.
- The target now records exact padding, ABI, six-string packet contract, complete control geometry/order, helper/resource/global mapping, `0x870` caller allocations, modeled/raw caller distinction, no-constructor-singleton result, Clan source route, and compiler exclusions.
- The target is `90/92`; class UID000024 is `88/90` with four protected fields, layout UID0001TY is `87/91`, and parent/file wording is synchronized at unchanged scores.
- Validator-generated `auto-generated/NexusTK/social/Clan.cpp` carries command id `000000008315`, contains the four fields and constructor exactly once, and contains no duplicate raw Enlist/Change constructor body.

## Heuristic / Inference Reanalysis And Validation

The assignment triggers constructor-body, class-layout, control-layout, source-placement, owner/emitter, function-boundary, caller-liveness, and first-draft-C++ analysis. Each inference was tested as follows:

1. **Constructor ABI:** IDA's `int __thiscall(int this, int)` display was compared with `retn 4`, base-constructor forwarding, sibling signatures, and all five call sites. The source argument is a single `const unsigned char *packet`; the implicit return of `this` is compiler ABI behavior, not a source return type.
2. **Class identity:** primary/secondary/tertiary vtable stores at complete-object offsets `+0`, `+0xa0`, and `+0xa4` were matched to accepted `ClanAttrInputDialog` vtable support and derived post-base stores.
3. **Packet contract:** the decompile was followed through all six sequential `{ unsigned-byte length, bytes[length] }` records beginning at `packet+3`. Pointer advancement, local byte termination, CP_ACP conversion, and wide termination were checked for every record.
4. **Label uncertainty:** the five visible strings are supplied by the server packet. Their literal text therefore cannot be recovered from the executable and is not a missing resource blocker. Local names are descriptive source-facing names based on control order and geometry; behavior does not depend on reconstructing literal labels.
5. **Control identities:** insertion order was cross-checked with action/validation methods. It proves logical ids `0` through `10`, with OK `1`, Cancel `2`, static texts `3`-`7`, and required edit controls `8`-`10`. Image indices `14` and `22` are constructor resources, not logical ids.
6. **Helper names:** each old raw helper was matched to current accepted support and/or independently analyzed behavior. No raw `sub_*` name is required in formal C++.
7. **Reachability:** three modeled callers and two raw derived-constructor callers were inspected. The modeled sites inline base construction and then install derived vtables; the raw starts contain equivalent source constructor bodies but have no direct inbound xref/pointer route.
8. **Singleton route:** the constructor has no read/write of `g_pClanStatusPane` or a dialog singleton. `g_pClanStatusPane` belongs to later event/submit paths. This constructor attaches to the overlay layer and shows relative to `g_pBackPane`.
9. **Ownership:** class, packet-handler, resource, vtable, and current file-parent evidence all favor the existing `ClanAttrInputDialog -> Clan.cpp` route. `ClanDialogs` remains only a coordinated family-split candidate.
10. **Compiler lowering:** SEH state, security-cookie checks, allocation null paths, explicit vptr stores, and the implicit `this` return are compiler output. Source reconstruction should use base/member/control constructors and omit that lowering.

## Evidence Standards Used

- Current active-IDB MCP facts are primary evidence for bytes, function bounds, decompilation, xrefs, callers, callees, and globals.
- Accepted project support pages are primary for source-facing framework declarations only when the current target's calls agree with them.
- Historical reports and generated output are navigation/comparison evidence, never substitutes for the current MCP pass.
- Negative claims use explicit xref and pointer-byte checks and are narrowly worded.
- Inferred local/member names are labeled descriptive; ABI, offsets, control order, coordinates, resource names, and helper calls are stated as observed facts.
- No claim relies on a decompiler-generated local name as original-symbol proof.

## Evidence Checked

### Current MCP session

- `idb_list` request `202`: active session `359c7886`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `13016`, active and not analyzing.
- `server_health` request `203`: status `ok`, module `NexusTK.exe`, image base `0x00400000`, analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` request `205`: `sub_489600` starts at `0x00489600`, size `0x7e1`; neither `0x004895fe` nor `0x00489de1` is a function start. Successor `sub_489DF0` starts at `0x00489df0`, size `0xc7`.
- `analyze_function` request `206` and full `decompile` request `211`: base call, three vtable stores, six decodes, eleven controls, all modal setup calls, and exact tail were reviewed.
- `xrefs_to` request `207`: five target references; two `DLGCLAN2.EPF` references; one constructor store to each base vtable.
- `get_bytes` request `208`: two preceding `0xcc` bytes, constructor tail through `retn 4` at exclusive end `0x00489de1`, fifteen following `0xcc` bytes, and full UTF-16 `DLGCLAN2.EPF` at `0x0061644c`.
- Caller/decompile requests `212`-`214`: modeled sites `sub_484F70`, `sub_487EA0`, and `sub_488370` allocate `0x870`, call the target, and install Enlist/Change derived vtables.
- Raw-constructor requests `215`-`217`: starts `0x00489f80` and `0x00489ff0` have no inbound xrefs or exact address-pointer hits; their 53-byte bodies call this base and install derived vtables.
- Type request `218`: no recovered `ClanAttrInputDialog` UDT and no recovered `TextEditControlPane` UDT. This caps original-name certainty but does not block the body because class/control declarations are already reconstructed by accepted docs.
- Helper requests `219`-`222`: independently confirmed `SetHoverControl`, `OnCreate`, `OnShow`, and `SlideOpenHorizontal`; existing accepted docs cover the remaining helper names.

### Documentation and repository checks

- Opened current target, class, parent split index, layout, `Clan` file page, resource child, vtable support, DialogPane declaration/helpers, Pane mode helper, layer slots, `g_pBackPane`, sibling clan constructors, and derived submitter/caller pages.
- Searched report trees for `0004HH`, `0x00489600`, `sub_489600`, `ClanAttrInputDialogConstructor`, `DLGCLAN2`, `ClanAttrInputDialog`, and `00010L`; relevant historical reports were opened before conclusions were drawn.
- Confirmed the assigned report path did not exist before this report was created.
- UID0004DH and its implemented files were outside this callback; no B003 edit, validator, move, execution, or incorporation action targeted them.

## Claim And Incorporation Ledger

| Claim | Disposition | Destination | Required incorporation | Evidence | State |
| --- | --- | --- | --- | --- | --- |
| C01 | incorporate | UID0004HH metadata/status | Preserved owner `000024`, emitter `000024`, position `1`, reconstructable true; changed disposition to emitting first draft. | Target header/status; validator `000000008304` | applied |
| C02 | incorporate | UID0004HH formal C++ | Replaced the no-code comment with the exact managed constructor below; exact report/target body comparison passed. | Target formal block; generated Clan lines `67-161` | applied |
| C03 | incorporate | UID0004HH range | Preserved `0x00489600-0x00489de1`, size `0x7e1`; documented two-byte predecessor and fifteen-byte successor padding exclusions. | Target Covered Range; parent inventory | applied |
| C04 | incorporate | UID0004HH ABI | Documented one explicit `const unsigned char *packet`, implicit `this`, constructor source return, and binary `retn 4`. | Target Status/Behavior | applied |
| C05 | incorporate | UID0004HH behavior | Added all six sequential counted CP_ACP strings from `packet+3`; first output persists at `+0x26c`. | Target Behavior/formal C++ | applied |
| C06 | incorporate | UID0004HH control inventory | Added insertion order, logical ids, image indices, and all eleven rectangles. | Target Control Inventory; layout support | applied |
| C07 | incorporate | UID0004HH helper map | Replaced raw helper blockers with accepted constructor/control/dialog helpers. | Target Helper And Route Resolution/formal C++ | applied |
| C08 | incorporate | UID0004HH resource/global notes | Added both resource uses, overlay layer, `g_pBackPane`, and no `g_pClanStatusPane` constructor dependency. | Target Behavior/route notes; Clan row | applied |
| C09 | incorporate | UID0004HH caller/liveness notes | Added three modeled inline derived constructions and two separate raw constructor calls with no-route caveats. | Target MCP/route notes; layout and Clan support | applied |
| C10 | incorporate | UID0004HH reconstruction notes | Excluded vptr/EH/cookie/allocation lowering and implicit `this` return from source. | Target Reconstruction Notes | applied |
| C11 | incorporate | UID000024 class | Added four protected fields, emitting constructor state, `0x870` context, and retained inference/compiler caveats. | Class declaration/status/evidence; validator `000000008311` | applied |
| C12 | incorporate | UID0001TY layout | Added `0x870`, six-record packet contract, control geometry/order, label roles, overlay/back-pane route, and raw/live caller distinction. | Layout ClanAttr sections; validator `000000008313` | applied |
| C13 | incorporate | UID00010L parent index | Replaced stale constructor wording; kept `90/92`, non-emitting parent, exact children and padding. | Parent status/range/reconstruction notes; validator `000000008314` | applied |
| C14 | incorporate | UID0000I8 Clan | Synchronized constructor emission/helper/caller route; retained `90/85` and `social/Clan.cpp`. | Clan Proposed Contents/Changes; validator `000000008315` | applied |
| C15 | reject-invalid | UID0000IA ClanDialogs | No one-off source move or emitter change; rejection is explicit in target/class/layout/parent/file. | Current Clan route and coordinated-split policy | excluded-with-reason |
| C16 | already-present | resource/vtable/DialogPane/Pane/global supports | Stable supports already carried same-or-greater dependency detail; no duplicate edits were needed. | Current support review and target cross-references | already-present |

## Positive Evidence Summary

- Exact modeled function, complete decompile, and unambiguous half-open boundary.
- Three direct modeled callers and two source-shaped derived constructor callers.
- Exact class vtable family and complete-object secondary offsets.
- Six complete packet-string decode sequences with bounded one-byte lengths.
- Exact resource string, two code references, control constructors, geometry, and insertion order.
- Accepted helper declarations for every constructor dependency.
- Existing class, layout, resource, global, and source-file ownership supports all clear the source route.
- Derived action/validation/submitter methods independently consume the constructor's control ids and persistent fields.

## Negative Evidence Summary

- No function object begins at the two raw derived constructor starts, and no direct xref or exact address-pointer hit reaches either raw start. This does not negate the three live inline derived construction sites.
- No recovered IDA UDT supplies original class/control/member spellings. Current names remain source-facing reconstructions, not symbol claims.
- No executable string contains the five visible labels because the server packet supplies them.
- No constructor reference to `g_pClanStatusPane` or a dedicated dialog singleton was found.
- No evidence supports moving this one method to `ClanDialogs.cpp`, splitting the exact target, or emitting explicit vtable/EH/security-cookie code.

## Function / Child Inventory

| Range / address | Classification | Source disposition |
| --- | --- | --- |
| `0x004895fe-0x00489600` | two `0xcc` predecessor alignment bytes | exclude |
| `0x00489600-0x00489de1` | modeled `ClanAttrInputDialog` constructor, 2017 bytes | emit as this exact child |
| `0x00489de1-0x00489df0` | fifteen `0xcc` alignment bytes | exclude |
| `0x00489df0-0x00489eb7` | adjacent `OnDialogAction` exact child | keep separate UID0004HI |
| `0x00489f80-0x00489fb5` | raw `ClanEnlistInputDialog` constructor body | keep separate UID00021W |
| `0x00489ff0-0x0048a025` | raw `ClanChangeInputDialog` constructor body | keep separate UID0002O4 |

There is no nested handwritten child inside `0x00489600-0x00489de1`. The rectangle helpers, allocator, control constructors, dialog helpers, Win32 conversion call, EH state, and security-cookie check are dependencies or compiler lowering, not split candidates from this range.

## Direct Xref And Caller Closure

| Target xref | Containing function | Construction result |
| --- | --- | --- |
| `0x004852e9` | `sub_484F70` | allocates `0x870`, calls base constructor, installs `ClanChangeInputDialog` vtables |
| `0x00487f2f` | `sub_487EA0` | allocates `0x870`, calls base constructor, installs `ClanEnlistInputDialog` vtables |
| `0x004883e8` | `sub_488370` | allocates `0x870`, calls base constructor, installs `ClanChangeInputDialog` vtables |
| `0x00489f8d` | raw start `0x00489f80` | base call inside retained `ClanEnlistInputDialog` constructor body |
| `0x00489ffd` | raw start `0x00489ff0` | base call inside retained `ClanChangeInputDialog` constructor body |

All modeled live uses construct a derived Enlist/Change object rather than a pure base object. At source level this still requires a real `ClanAttrInputDialog` base constructor; compiler inlining/duplication at opener sites is not a reason to suppress the source body.

## Class, Field, And Inheritance Layout

| Complete-object offset | Meaning | Confidence |
| --- | --- | --- |
| `+0x000` | primary `ClanAttrInputDialog`/`DialogPane` view | direct vtable evidence |
| `+0x0a0` | secondary inherited interface view | direct vtable evidence |
| `+0x0a4` | tertiary inherited interface view | direct vtable evidence |
| `+0x1fc` | inherited dialog control-manager pointer | accepted DialogPane layout |
| `+0x26c` | `wchar_t m_submittedClanName[256]` | constructor write plus submitter use |
| `+0x46c` | `wchar_t m_submittedDescriptionText[256]` | action write plus submitter use |
| `+0x66c` | `wchar_t m_submittedAttributeText[256]` | action write plus submitter use |
| `+0x86c` | `unsigned short m_submittedAttributeType` | action write plus submitter use |
| `0x870` | allocated complete-object size for derived Enlist/Change instances | three modeled callers |

The accepted source shape is `ClanAttrInputDialog : public DialogPane`, with Enlist/Change classes deriving from it and adding no currently observed instance fields. Explicit vtable fields must not be declared.

## Control And Resource Inventory

| Logical id | Constructed control | Source/value | Rect `(left,top,right,bottom)` |
| --- | --- | --- | --- |
| `0` | `EPFImageControlPane` | `DLGCLAN2.EPF` | `(0,0,259,288)` |
| `1` | `ImageButtonControlPane` | image index `14` / OK | `(53,228,125,244)` |
| `2` | `ImageButtonControlPane` | image index `22` / Cancel | `(130,228,202,244)` |
| `3` | `StaticTextControlPane` | packet string 2, heading/prompt | `(41,20,231,45)` |
| `4` | `StaticTextControlPane` | packet string 3, clan/context caption | `(41,49,231,74)` |
| `5` | `StaticTextControlPane` | packet string 4, description prompt | `(41,66,231,91)` |
| `6` | `StaticTextControlPane` | packet string 5, attribute prompt | `(41,116,231,141)` |
| `7` | `StaticTextControlPane` | packet string 6, attribute-type prompt | `(41,166,231,191)` |
| `8` | `TextEditControlPane` | empty initial text | `(41,91,218,104)` |
| `9` | `TextEditControlPane` | empty initial text | `(41,141,218,154)` |
| `10` | `TextEditControlPane` | empty initial text | `(41,191,218,204)` |

After insertion, the constructor selects hover control `8`, focused/default action `1`, pending/cancel action `2`, background `DLGCLAN2.EPF`, pane mode `1`, dialog bounds `(174,12,433,300)`, overlay layer context, `g_pBackPane` show ordering, and horizontal slide direction `0`.

## Helper Resolution

| Binary target | Accepted source-facing use |
| --- | --- |
| `0x0049d8a0` | `DialogPane(L"", -1, true)` |
| `0x004f4aa0` | compiler implementation of control `new` allocations |
| `0x004991f0` | `EPFImageControlPane` constructor |
| `0x00499030` | `StaticTextControlPane` constructor |
| `0x00498920` | `TextEditControlPane` constructor |
| `0x0049dc10` | `AddControl(ControlPane *)` |
| `0x0049fc00` | `SetHoverControl(8)` |
| `0x0049dd80` | `SetFocusedControl(1)` |
| `0x0049ddd0` | `SetPendingControl(2)` |
| `0x0049db60` | `SetBackgroundResource(...)` |
| `0x005446b0` | `Pane::SetMode(1)` |
| `0x004b7c50` / `0x00516030` / `0x00516220` | accepted rectangle initialization/construction lowering |
| `0x0049dfd0` | `OnCreate(&bounds, 0, NULL, overlay layer)` |
| `0x0049e190` | `OnShow(NULL, g_pBackPane)` |
| `0x0049ec80` | `SlideOpenHorizontal(0)` |

## Ranked Ownership Analysis

1. **[UID:000024] `ClanAttrInputDialog` - accepted direct owner/emitter.** The function constructs that exact base, installs its three vtable views, initializes its persistent fields, and is called as the base constructor for two derived classes.
2. **[UID:0000I8] `Clan` - accepted source-file route.** Clan packet handlers, sibling dialogs, submitters, resources, globals, and current generated route already converge on `NexusTK/social/Clan.cpp`.
3. **[UID:0000IA] `ClanDialogs` - rejected current route.** It is a plausible coordinated future modal-family split, but moving one constructor now would conflict with existing ownership and create a one-off split.
4. **[UID:00010L] parent memory aggregate - rejected emitter.** It is correctly a non-emitting split index for four exact method children.
5. **Framework/resource/global supports - rejected owners.** They own dependencies, not this class-specific constructor behavior.

## Source Placement

Retain the emitted constructor under [UID:000024] in [UID:0000I8] at optional position `1`, producing source in `NexusTK/social/Clan.cpp`. Keep the class declaration and four persistent fields on `by-class/ClanAttrInputDialog.md`. Do not introduce a new file, direct file-level bypass, duplicate body on the parent aggregate, or one-off `ClanDialogs.cpp` migration.

## Range / Split / Padding / Reclassification Analysis

- Preserve exact half-open range `0x00489600-0x00489de1` and filename.
- Preserve parent split relationship to UID00010L and separation from UID0004HI/4HJ/4HK.
- Preserve the proven predecessor disposition: `0x004895fe-0x00489600` is two bytes of `0xcc` alignment padding and remains excluded from UID0004HH.
- Preserve the proven successor disposition: `0x00489de1-0x00489df0` is fifteen bytes of `0xcc` alignment padding and remains excluded from UID0004HH.
- Do not create nested children; the body is one source constructor.
- Do not reclassify the constructor or either padding run; no byte ownership change is recommended.
- A future IDA rename from `sub_489600` to a constructor-style name would be reasonable, but this assignment must not perform IDB changes and the documentation does not depend on that rename.

## First-Draft C++ Recommendation

This is the exact formal-block recommendation for UID0004HH. Descriptive local names do not claim recovered originals. Explicit vptr stores, EH/cookie machinery, allocator null branches, and the implicit constructor return are intentionally omitted.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ClanAttrInputDialog::ClanAttrInputDialog(const unsigned char *packet)
    : DialogPane(L"", -1, true)
{
    char textBytes[256];
    wchar_t headingText[256];
    wchar_t clanCaptionText[256];
    wchar_t descriptionPromptText[256];
    wchar_t attributePromptText[256];
    wchar_t attributeTypePromptText[256];

    const unsigned char *textPacket = packet + 3;
    unsigned int textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textPacket += textLength;
    textBytes[textLength] = '\0';
    unsigned char wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, m_submittedClanName, 256));
    m_submittedClanName[wideLength] = L'\0';

    textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textPacket += textLength;
    textBytes[textLength] = '\0';
    wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, headingText, 256));
    headingText[wideLength] = L'\0';

    textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textPacket += textLength;
    textBytes[textLength] = '\0';
    wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, clanCaptionText, 256));
    clanCaptionText[wideLength] = L'\0';

    textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textPacket += textLength;
    textBytes[textLength] = '\0';
    wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, descriptionPromptText, 256));
    descriptionPromptText[wideLength] = L'\0';

    textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textPacket += textLength;
    textBytes[textLength] = '\0';
    wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, attributePromptText, 256));
    attributePromptText[wideLength] = L'\0';

    textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textBytes[textLength] = '\0';
    wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, attributeTypePromptText, 256));
    attributeTypePromptText[wideLength] = L'\0';

    AddControl(new EPFImageControlPane(
        L"DLGCLAN2.EPF", Rect(0, 0, 259, 288), 0, true));
    AddControl(new ImageButtonControlPane(14, Rect(53, 228, 125, 244)));
    AddControl(new ImageButtonControlPane(22, Rect(130, 228, 202, 244)));
    AddControl(new StaticTextControlPane(
        headingText, true, 128, Rect(41, 20, 231, 45)));
    AddControl(new StaticTextControlPane(
        clanCaptionText, true, 128, Rect(41, 49, 231, 74)));
    AddControl(new StaticTextControlPane(
        descriptionPromptText, true, 128, Rect(41, 66, 231, 91)));
    AddControl(new StaticTextControlPane(
        attributePromptText, true, 128, Rect(41, 116, 231, 141)));
    AddControl(new StaticTextControlPane(
        attributeTypePromptText, true, 128, Rect(41, 166, 231, 191)));
    AddControl(new TextEditControlPane(
        L"", true, 128, Rect(41, 91, 218, 104)));
    AddControl(new TextEditControlPane(
        L"", true, 128, Rect(41, 141, 218, 154)));
    AddControl(new TextEditControlPane(
        L"", true, 128, Rect(41, 191, 218, 204)));

    SetHoverControl(8);
    SetFocusedControl(1);
    SetPendingControl(2);
    SetBackgroundResource(L"DLGCLAN2.EPF", NULL);
    SetMode(1);

    RectBounds dialogBounds;
    InitRectBounds(&dialogBounds, 174, 12, 433, 300);
    OnCreate(
        &dialogBounds,
        0,
        NULL,
        g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenHorizontal(0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The final packet pointer need not be advanced after copying string six because it is not consumed again. `wideLength` may safely be an `unsigned char`: each input length is one byte, `MultiByteToWideChar` receives a 256-wide-character output capacity, and the binary truncates the returned index to one byte before writing the terminator.

## Final Recommendation

C01-C16 are resolved as applied, already present, or excluded with the accepted reason. UID0004HH is the exact emitting constructor child with current class/file ownership and range retained; the class carries the four submitted fields, the layout/parent/file supports are synchronized, and no duplicate raw-derived body or source move was introduced.

## Recommended Target Doc Changes

1. Applied the formal constructor body exactly as accepted.
2. Applied source-emitting disposition/item-summary wording.
3. Applied ABI, packet contract, controls/geometry, helper map, caller closure, object size, singleton-route result, compiler exclusions, and MCP session `359c7886` evidence.
4. Preserved UID, filename/range, owner/emitter, position, reconstruction flag, parent relationship, and cross-references.
5. Raised `86/90` to current `90/92`.

## Recommended Support Doc Changes

- **UID000024 `ClanAttrInputDialog`:** applied four protected fields, emitting constructor/formal-state wording, and `86/89 -> 88/90`.
- **UID0001TY `ClanInputDialogLayouts`:** applied `0x870`, exact controls/geometry, six-string contract, overlay/back-pane setup, and `85/90 -> 87/91`.
- **UID00010L parent split index:** applied wording only; retained non-emitting state, children/ranges, and `90/92`.
- **UID0000I8 `Clan`:** applied constructor/caller route wording only; retained `social/Clan.cpp` and `90/85`.
- **No edit required:** UID0000IA `ClanDialogs`, DialogPane/Pane/control classes, resource/vtable children, `MainUiLayerSlots`, and `g_pBackPane` already carry adequate support.

## Score And Metadata Recommendation

| Page | Before | Current | Reason |
| --- | --- | --- | --- |
| UID0004HH target | `86/90` | `90/92` | complete body, ABI, controls, helpers, callers, route, and exact formal C++ |
| UID000024 class | `86/89` | `88/90` | declaration gains required fields and accurate emitting state |
| UID0001TY layout | `85/90` | `87/91` | complete size and exact constructor/control layout added |
| UID00010L parent | `90/92` | `90/92` | wording sync only; remains non-emitting index |
| UID0000I8 Clan | `90/85` | `90/85` | route already correct; evidence sync does not change source confidence |

No canonical owner, emitter UID, emitter position, reconstruction flag, filename, range, or source path changed.

## Open Questions With Attempted Resolution

1. **Original names for five packet labels:** not recoverable from executable literals because text is packet-provided. Resolved for reconstruction by descriptive locals tied to observed order/geometry; this is a naming confidence cap only.
2. **Original constructor argument wrapper type:** no recovered UDT proves a richer packet class. `const unsigned char *packet` is the narrowest ABI-correct source type and matches sibling accepted code.
3. **Original helper spelling for modal create/show convenience wrappers:** sibling pages sometimes use `SetDisplayRect`/`ShowDialog`. This target directly calls accepted virtual `OnCreate` and `OnShow`; using those declared names is more evidence-bound and preserves exact global arguments.
4. **Raw derived constructor liveness:** direct xref/pointer checks remain negative. Resolved by retaining their separate no-route wording while recognizing three modeled inline constructions as the live source route.
5. **Pure base instantiation:** none observed. This does not block a protected/public base constructor required by derived source construction.
6. **Future `ClanDialogs.cpp` split:** plausible only as a coordinated family migration. No present evidence justifies a one-off move.

## Validator Results

Each edited `by-*` file received exactly one scoped callback validator from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command details | Result |
| --- | --- | --- |
| UID0004HH target | `python .\tools\validator.py --mode file --file by-memory\0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md --apply --queue-timeout 240`; id `000000008304`; `2026-07-12T17:14:21-04:00` | exit `0`, `ok: 1`, generated refresh deferred |
| UID000024 class | `python .\tools\validator.py --mode file --file by-class\ClanAttrInputDialog.md --apply --queue-timeout 240`; id `000000008311`; `2026-07-12T17:15:13-04:00` | exit `0`, `ok: 1`, generated refresh deferred |
| UID0001TY layout | `python .\tools\validator.py --mode file --file by-type\by-struct\ClanInputDialogLayouts.md --apply --queue-timeout 240`; id `000000008313`; `2026-07-12T17:16:15-04:00` | exit `0`, `ok: 1`, generated refresh deferred |
| UID00010L parent | `python .\tools\validator.py --mode file --file by-memory\0x00489600-0x00489f80.ClanAttrInputDialogCore.md --apply --queue-timeout 240`; id `000000008314`; `2026-07-12T17:16:55-04:00` | exit `0`, `ok: 1`, generated refresh deferred |
| UID0000I8 Clan | `python .\tools\validator.py --mode file --file by-file\Clan.md --apply --queue-timeout 240 --wait-generated`; id `000000008315`; `2026-07-12T17:17:35-04:00` | exit `0`, `ok: 1`, generated refresh completed |

The waited Clan validation reported existing broad-project diagnostics (`missing_ref_uid`, `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code`) while still returning `ok: 1`; no out-of-scope repair was attempted. Validator-owned registry, projected stats, coverage metadata, and generated C++ refreshed as side effects. `auto-generated/NexusTK/social/Clan.cpp` has command id `000000008315` and timestamp `2026-07-12T17:17:35-04:00`, contains the four submitted fields and accepted constructor exactly once, contains no raw Enlist/Change constructor body, and has SHA256 `8EC62EA6661389F96E9DACBCD4392CE3BA67CE292C53A3383AE8283AB37057DB`.

## Changed Files

- `by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md` - target C01-C10 and `86/90 -> 90/92`.
- `by-class/ClanAttrInputDialog.md` - C11 fields/state and `86/89 -> 88/90`.
- `by-type/by-struct/ClanInputDialogLayouts.md` - C12 layout evidence and `85/90 -> 87/91`.
- `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md` - C13 wording only; score/structure unchanged.
- `by-file/Clan.md` - C14 wording only; score/route unchanged.
- `tools/leaser/Agents/Agent-B003/research/0004HH-ClanAttrInputDialogConstructor-source-quality.md` - callback ledger, validators, changed files, and checklist updated.
- Validator-owned generated/registry/stats artifacts refreshed through the scoped commands; none was manually edited. No coverage/tracker/supervisor/goal/IDB/lifecycle file was manually changed.

## Implementation Tracking Checklist

- [x] Gate 1 accepted repaired report SHA256 `39ED25714665DDE278C299DECA15F706E48F02D12A57BA3F37AB749F1921581E`.
- [x] UID0004HH leased, C01-C10 applied, validated as `000000008304`, and released.
- [x] UID000024 leased, C11 fields/state applied, validated as `000000008311`, and released.
- [x] UID0001TY leased, C12 complete-size/control/packet/route evidence applied, validated as `000000008313`, and released.
- [x] UID00010L leased, C13 wording-only sync applied with score/structure preserved, validated as `000000008314`, and released.
- [x] UID0000I8 leased, C14 source-route row/evidence applied with score/route preserved, wait-validated as `000000008315`, and released.
- [x] C15 one-off ClanDialogs move remained explicitly rejected; C16 stable supports were verified already present and left unchanged.
- [x] Every lease was released immediately after its file's edit/validator batch; final lease report has no active B003 row.
- [x] One scoped validator ran per edited `by-*` file; command ids, timestamps, exit codes, `ok` counts, diagnostics, and generated state are recorded above.
- [x] Final generated Clan output is current for command `000000008315`, contains the accepted constructor exactly once, and omits duplicate raw-derived bodies.
- [x] No `by-*` file outside the accepted ledger was edited; no generated/coverage/tracker/supervisor file was manually edited.
- [x] Report wording, ledger, validator section, changed-file list, and checklist are callback-complete and archive-neutral.
- [x] Report SHA256 recomputed for supervisor Gate 2 verification; no implementation blocker remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000008334","destination_path":"executed-b-agent-research/B003/0004HH-ClanAttrInputDialogConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0004HH-ClanAttrInputDialogConstructor-source-quality.md","timestamp":"2026-07-12T17:27:47-04:00","uid":"0004HH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
