** TARGET-REPORT-UID:0001CR **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001CR CreateUserDialogVariants Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](../../../../../by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) as a non-emitting source-family split/index under the create-user dialog family, not as a reconstructable aggregate source body.
- Final disposition: keep `CANONICAL_OWNER:0000IK` only as family/context ownership, change `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, keep aggregate C++ blank, and move source-bearing C++ to exact child pages.
- Required action after supervisor acceptance: update the aggregate, the exact children, and the supporting class/file/global pages so the generated output no longer emits a synthetic `CreateUserDialogs.cpp` for the parent/lifecycle glue.
- Confidence: high for split/emission policy and class/file routing; medium-high for final field names because original symbols are not available and live IDA MCP was unavailable in this report session.

## Target

- Target UID: `0001CR`
- Target path: `source-3/project-documentation/by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/0001CR-CreateUserDialogVariants-source-quality.md`
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000IK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IK`, blank C++.
- Current coverage row: `mixed executable island`, `reconstructable`, `82%`, with a stale source-split blocker.
- Current auto-generated state checked: `auto-generated/-ag-memory-coverage.md` emits the aggregate and lifecycle child through `0000IK` to `auto-generated/NexusTK/login/CreateUserDialogs.cpp`. The proposed source tree lists concrete files `CreateUserDialogPane.cpp`, `NewCreateUserDialogPane.cpp`, `NewUserDialogPane2.cpp`, and related control files, not `CreateUserDialogs.cpp`.

## Supervisor Active Recheck

- The user assigned a B-preferred report-only source-quality task for [UID:0001CR] after the completed 00019J report. I did not modify the target, support docs, generated files, project-level files, or `by-memory/-coverage-report.md`.
- The assigned item already has four exact child pages. No new split is required before a report checkpoint; the needed repair is reclassification of the broad parent and lifecycle island plus child/source-quality updates.
- Existing B010 reports were preserved. No older research report was overwritten.
- Prior executed research search for `0001CR` / `CreateUserDialogVariants` in B001/B002/B010 executed research folders found no matching executed report.
- Live IDA MCP note: the current session could not reach `http://127.0.0.1:13337/mcp` (`IDA_MCP_ERROR: Unable to connect to the remote server`). This report therefore relies on current by-* documentation that records prior live IDA MCP evidence, generated coverage, source-tree docs, and the existing PE-scan/no-xref findings already written into the exact child pages.

## Executive Recommendation

The aggregate should not emit source. It is a physical address-family inventory that crosses three dialog classes plus compiler-generated destructor/thunk support:

- [UID:0002QR] `0x0052a540-0x0052c325` belongs to `NewUserDialogPane2` and emits through [UID:00009E] / [UID:0000LW] to `login/NewUserDialogPane2.cpp`.
- [UID:0002QS] `0x0052c360-0x0052dcf5` belongs to `NewCreateUserDialogPane` and should route through [UID:00008Z] / [UID:0000LP] to `login/NewCreateUserDialogPane.cpp`.
- [UID:0002QT] `0x0052dd30-0x0052f6e5` belongs to `CreateUserDialogPane` and emits through [UID:00003B] / [UID:0000IJ] to `login/CreateUserDialogPane.cpp`.
- [UID:0002QU] `0x0052f710-0x0052f94c` is compiler lifecycle/thunk support and should be non-emitting; normal source should express class destructors and let the compiler regenerate scalar deleting destructors and adjustor thunks.

This makes [UID:0001CR] a non-emitting split/index with `RECONSTRUCTABLE:FALSE`. Its score can rise because the old "source split remains unresolved" blocker is now resolved as "child-only emission with non-emitting parent."

## Recommended Metadata Changes

| UID | Current | Recommended | C++ decision |
| --- | --- | --- | --- |
| `0001CR` | `85/86`, owner/emitter `0000IK`, `RECONSTRUCTABLE:TRUE` | `88/89`, keep `CANONICAL_OWNER:0000IK` as family context, set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS` | Keep blank. This is a split/index, not a source body. |
| `0002QR` | `86/87`, owner/emitter `00009E`, blank C++ | `88/88`, keep owner/emitter `00009E` | Add first-draft child C++ for constructor/method cluster after accepted callback. |
| `0002QS` | `85/89`, metadata owner/emitter `0000LP`, body says class owner `00008Z` | `86/89`, change metadata owner/emitter to `00008Z` for direct class routing, class emits through `0000LP` | Add first-draft child C++; retain no-direct-caller caveat. |
| `0002QT` | `85/88`, owner/emitter `00003B`, blank C++ | `87/89`, keep owner/emitter `00003B` | Add first-draft child C++ for old dialog methods. |
| `0002QU` | `85/88`, owner/emitter `0000IK`, `RECONSTRUCTABLE:TRUE` | `88/90`, keep `CANONICAL_OWNER:0000IK` only as family context or use `NONE`, set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS` | Keep blank. This is ABI/lifecycle glue. |
| `0000IK` | by-file family page emits `CreateUserDialogs.cpp` via `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"` | Preferred: convert to family/quarantine index with `PROPOSED_RECONSTRUCTION_PATH:"NONE"` if validator accepts; fallback: keep as folder context but ensure no memory children emit through it | No source body. Concrete class files own emitted code. |

## Heuristic / Inference Reanalysis And Validation

### Aggregate Source Shape

- Issue: current parent is marked reconstructable and emitting, while exact children already carry source-bearing ranges.
- Evidence checked: target metadata, child pages, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-file-coverage.md`, and `by-project-structure/proposed-source-tree.md`.
- Best inference: `0001CR` is an index/container over exact source-bearing children and compiler glue. It should not generate a physical source file.
- Rejected alternative: keep `CreateUserDialogs.cpp` as a generated source file. This duplicates child output and contradicts the proposed source tree, which names concrete dialog files rather than an umbrella source.
- Impact: target formal C++ must stay blank; score improves because the split policy is now resolved.

### Variant Source Split And File Placement

- `NewUserDialogPane2`: exact constructor callers at `0x004f7ad0` and `0x004f9041`, singleton/vtable group `0x0069b4a4` / `0x0061fd04`, and file route [UID:0000LW] support `login/NewUserDialogPane2.cpp`.
- `NewCreateUserDialogPane`: constructor `0x0052c360` has no direct caller after xref and PE absolute/RVA/direct-branch scans, but it has a complete constructor/method/vtable/singleton cluster at `0x0069b4a8` / `0x0061fda0`. It should remain a retained/newer variant in `login/NewCreateUserDialogPane.cpp`, not be merged into the parent or renamed away.
- `CreateUserDialogPane`: constructor callers at `0x004f7a82` and `0x004f8ff8`, singleton/vtable group `0x0069b890` / `0x0061fe3c`, and older appearance-control construction support `login/CreateUserDialogPane.cpp`.
- Rejected alternative: one monolithic `CreateUserDialogs.cpp`. The binary has separate class vtables, singleton slots, child-control families, and file pages already modeled for the three variants.

### NewCreateUserDialogPane No-Caller Status

- Evidence checked: [UID:0002QS] records zero `xrefs_to 0x0052c360`; the local PE scan found zero little-endian absolute VA hits for `0x0052c360`, zero RVA hits for `0x0012c360`, and zero direct `E8`/`E9` branch/call hits.
- Best inference: `NewCreateUserDialogPane` is retained/newer source code or an indirect/config path not recovered as a direct call in this binary. The no-caller result is real, but it does not justify collapsing the class into `CreateUserDialogs` or blocking child source C++ for its method bodies.
- Rejected alternative: call it dead/unowned and blank all child implementation. Constructor, vtables, singleton writes, selector helpers, packet helpers, and scalar destructor all form a coherent class cluster.
- Source-quality impact: mention retained/no-direct-caller in the child and class pages, but do not treat it as a passive blocker for helper names, source placement, or first-draft method C++.

### Main-Menu Open/Create-User Reconciliation

- Active and retained main-menu open routes call `CreateUserDialogPane` and `NewUserDialogPane2`, not `NewCreateUserDialogPane`: `0x004f7a82` / `0x004f8ff8` call `0x0052dd30`, and `0x004f7ad0` / `0x004f9041` call `0x0052a540`.
- [UID:00019J] cleanup evidence reads `g_pNewCreateUserDialogPane` at `0x0069b4a8` or `g_pNewUserDialogPane2` at `0x0069b4a4` based on `g_useEpfAssets`. It does not prove a direct constructor route to `NewCreateUserDialogPane`.
- Best inference: document this as a source-evolution/reachability asymmetry. The cleanup slot and the retained constructor cluster prove the class exists; the menu open path evidence proves only the old and 640x480 variants are directly constructed in the current binary.
- Rejected alternative: rename `g_pNewCreateUserDialogPane` or `NewCreateUserDialogPane` to `CreateUserDialogPane` solely because the direct menu route constructs the old class. The singleton/vtable/class evidence is distinct.

### Singleton Slots And Raw Global Names

- `0x0069b4a4` should be `g_pNewUserDialogPane2`, type `NewUserDialogPane2 *`, owner [UID:0000LW]/[UID:00009E], global page [UID:0002X3].
- `0x0069b4a8` should be `g_pNewCreateUserDialogPane`, type `NewCreateUserDialogPane *`, owner [UID:0000LP]/[UID:00008Z], global page [UID:0002X7].
- `0x0069b890` should be `g_pCreateUserDialogPane`, type `CreateUserDialogPane *`, owner [UID:0000IJ]/[UID:00003B]. Current evidence exists on the by-memory singleton slot [UID:0002B3]; there is no by-global page. A support implementation may create `by-global/g_pCreateUserDialogPane.md` for parity or keep [UID:0002B3] as the canonical storage page.
- Rejected alternative: leave raw `dword_69B4A4`, `dword_69B4A8`, and `dword_69B890` names in source-facing prose. The class and singleton evidence supports canonical names.

### Packet Helper Roles And Names

- Three account-registration helpers at `0x0052bbc0`, `0x0052d5b0`, and `0x0052ef50` are duplicated opcode-`0x02` packet encoders. Best source-facing name: file-local `SendCreateAccountRequest` or `SendCreateUserAccountRequest`.
- Three character-create payload builders at `0x0052bdd0`, `0x0052d7c0`, and `0x0052f160` are variant-specific opcode-`0x04` builders. Best method name: `SendCreateCharacterRequest`.
- Three reply handlers at `0x0052bfd0`, `0x0052d9a0`, and `0x0052f390` process the two-phase reply state and call the local `SendCreateCharacterRequest`. Best method name: `OnCreateUserReply` or `HandleCreateUserReply`; prefer `OnCreateUserReply` if existing dialog packet handlers use `On...`.
- Historical raw names `dword_67A7EC`, `sub_575380`, `sub_516220`, and `sub_574BB0` should be described as `g_packetSender` and packet-buffer append/send helpers unless the packet-buffer type pages provide exact method names during implementation.
- Rejected alternative: model a single shared helper in one source file. The binary has three separate helper bodies adjacent to their class methods, consistent with file-local static helper duplication or copy/paste source.

### Appearance Selector And Field Names

- `this[127]` / offset `+0x1fc` is the child/control lookup container used by submit validation to read edit fields 1, 2, and 3.
- Shared trailing fields are strongly inferred:
  - `+0x26c` / 620: first selected create-user option, likely gender/nation/body family depending on variant.
  - `+0x270` / 624: second selected option, likely totem/style/body variant depending on variant.
  - `+0x274` / 628: visible-shape/preview base index for `NewUserDialogPane2`.
  - `+0x278` / 632: two-phase create-user reply flag, best source name `m_createCharacterPhase` or `m_sentCreateCharacter`.
  - `+0x27c` / 636: stored created account/user name, best source name `m_createdUserName`.
- `NewUserDialogPane2` uses `DLGNEW02.EPD`, `NPAL3.PAL`, `DIREC.EPD`, `NNATION.EPD`, and repeated `UserShapeSelectControlPane`/shape preview construction.
- `NewCreateUserDialogPane` uses `DLGNEW.EPF`, `GENDER.EPF`, `DIREC.EPF`, `NEWBUTT.PAL`, and `NewUserShapeSelectControlPane`.
- `CreateUserDialogPane` uses `DLGNEW3` and the older `UserHairSelectControlPane`, `UserFaceSelectControlPane`, `UserCreatePreviewControlPane`, and color-list controls in [UID:0000OX] `UserCreateAppearanceControls`.
- Rejected alternative: keep "field names unknown" as a blocker. Exact original member names remain unavailable, but descriptive source fields are now strong enough for first-draft child C++.

### Destructor / Thunk Island

- [UID:0002QU] contains:
  - `0x0052f710`, `0x0052f720`, `0x0052f730`: 11-byte singleton clear helpers for `g_pCreateUserDialogPane`, `g_pNewCreateUserDialogPane`, and `g_pNewUserDialogPane2`.
  - Six 11-byte adjustor thunks at `0x0052f73b` through `0x0052f772`, subtracting `this` by `0xa0` or `0xa4` and jumping to scalar deleting destructors.
  - Helper-object scalar deleting destructors at `0x0052f780` and `0x0052f7c0`.
  - MSVC scalar deleting destructors at `0x0052f800`, `0x0052f870`, and `0x0052f8e0`.
- Best source decision: non-emitting compiler/lifecycle index. Class pages may mention ordinary destructors, but formal source should not handwrite scalar deleting destructor wrappers or adjustor thunks.
- Rejected alternative: emit C++ wrappers for `sub_52F800`, `sub_52F870`, or `sub_52F8E0`. These are ABI artifacts regenerated by the compiler.

### Stale Code-Gate Language

- Several support pages still say C++ is blank because the old `90/90+` or `95/95` gate was not met.
- Current rule: final-output C++ is eligible when `RECONSTRUCTABLE:TRUE`, emitter route is nonblank and valid, and `(COMPLETION + CONFIDENCE) / 2 > 85`.
- Best implementation direction: remove old gate wording from child/class/global pages. If C++ remains blank, state the real reason: parent is a non-emitting split/index, lifecycle island is compiler glue, or exact child source still needs accepted first-draft insertion.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Current Score | Recommended Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0052a540-0x0052f94c` | `0001CR` `CreateUserDialogVariants` | Physical create-user family index | Currently true | `0000IK` | `85/86` | `RECONSTRUCTABLE:FALSE`, non-emitting split/index, `88/89` |
| `0x0052a540-0x0052c325` | `0002QR` `NewUserDialogPane2CreateUserVariant` | 640x480 create-user constructor/method cluster | True | `00009E` | `86/87` | Keep emitting child, add first-draft C++, `88/88` |
| `0x0052c360-0x0052dcf5` | `0002QS` `NewCreateUserDialogPaneCore` | Retained/newer full-screen create-user cluster | True | currently metadata `0000LP`, body says `00008Z` | `85/89` | Route through direct class `00008Z`, add first-draft C++, `86/89` |
| `0x0052dd30-0x0052f6e5` | `0002QT` `CreateUserDialogPaneCore` | Old DLGNEW3 create-user cluster | True | `00003B` | `85/88` | Keep emitting child, add first-draft C++, `87/89` |
| `0x0052f710-0x0052f94c` | `0002QU` `CreateUserDialogDestructorAndThunkIsland` | Singleton clear helpers, adjustor thunks, scalar deleting destructors | Currently true | `0000IK` | `85/88` | `RECONSTRUCTABLE:FALSE`, non-emitting compiler lifecycle island, `88/90` |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0052a540` | callers `0x004f7ad0`, `0x004f9041` | `NewUserDialogPane2` constructor is directly used by active/retained main-menu create-user paths. |
| `0x0052c360` | no direct xrefs; no PE VA/RVA/direct branch hits | `NewCreateUserDialogPane` is retained/no-direct-caller in current binary, but still a coherent class cluster. |
| `0x0052dd30` | callers `0x004f7a82`, `0x004f8ff8` | `CreateUserDialogPane` constructor is directly used by active/retained main-menu create-user paths. |
| `0x004f8fa0` | retained helper with no inbound xrefs | `OpenCreateUserDialog` duplicates active main-menu case behavior and belongs to `MainMenuPane.cpp`. |
| `0x004f69a0` | cleanup helper callers `0x004f695c`, `0x004f6aa8`, `0x005028a3` | `CloseMainMenuDialogSingletons` consumes create-user singleton slots but does not own them. |
| `0x0069b4a4` | constructor/destructor/cleanup refs | `g_pNewUserDialogPane2`. |
| `0x0069b4a8` | constructor/destructor/cleanup refs | `g_pNewCreateUserDialogPane`. |
| `0x0069b890` | constructor/destructor/clear-helper refs | `g_pCreateUserDialogPane`. |

## First-Draft C++ Recommendation

Do not put this C++ in [UID:0001CR]. The aggregate should stay blank. These are child-level source drafts to seed the implementation callback for `0002QR`, `0002QS`, and `0002QT`.

Use one file-local packet helper per variant file because the binary contains three duplicated encoder bodies adjacent to each class:

```cpp
namespace
{
    void SendCreateAccountRequest(const wchar_t *accountName,
                                  const wchar_t *password,
                                  const wchar_t *profileText)
    {
        PacketBuffer packet;
        packet.WriteByte(0x02);
        packet.WriteLengthPrefixedMbcs(accountName);
        packet.WriteLengthPrefixedMbcs(password);
        packet.WriteLengthPrefixedMbcs(profileText);
        g_packetSender->QueuePacket(packet.Data(), packet.Size());
    }
}
```

Shared submit-path source shape for each dialog variant:

```cpp
void NewUserDialogPane2::SubmitCreateUser()
{
    wchar_t accountName[16];
    wchar_t password[16];
    wchar_t confirmPassword[16];

    GetEditText(1, accountName, 15);
    GetEditText(2, password, 15);
    GetEditText(3, confirmPassword, 15);

    if (!StringContainsDigit(password))
    {
        ShowCreateUserAlert(kPasswordMustContainDigitText);
        FocusEditControl(2);
        return;
    }

    if (wcscmp(password, confirmPassword) != 0)
    {
        ShowCreateUserAlert(kPasswordMismatchText);
        FocusEditControl(2);
        return;
    }

    CreateScreenDimmerForLogin();
    SendCreateAccountRequest(accountName, password, L"");
}
```

Variant-specific create-character methods should stay as class methods because each reads different selector/control state:

```cpp
void NewUserDialogPane2::SendCreateCharacterRequest()
{
    PacketBuffer packet;
    packet.WriteByte(0x04);
    packet.WriteByte(0xc8);
    packet.WriteByte(m_selectedShapeBase);
    packet.WriteByte(m_selectedGenderOrNation);
    packet.WriteByte(m_selectedTotem);
    packet.WriteLengthPrefixedMbcs(m_createdUserName.c_str());
    g_packetSender->QueuePacket(packet.Data(), packet.Size());
}

void NewCreateUserDialogPane::SendCreateCharacterRequest()
{
    PacketBuffer packet;
    packet.WriteByte(0x04);
    m_shapeSelector->AppendCreateUserAppearance(packet);
    packet.WriteByte(m_selectedGenderOrNation);
    packet.WriteByte(m_selectedTotem);
    packet.WriteLengthPrefixedMbcs(m_createdUserName.c_str());
    g_packetSender->QueuePacket(packet.Data(), packet.Size());
}

void CreateUserDialogPane::SendCreateCharacterRequest()
{
    PacketBuffer packet;
    packet.WriteByte(0x04);
    m_previewPane->AppendCreateUserAppearance(packet);
    packet.WriteByte(m_selectedBodyShape);
    packet.WriteByte(m_selectedGender);
    packet.WriteByte(m_hairColorIndex);
    packet.WriteByte(m_faceColorIndex);
    packet.WriteLengthPrefixedMbcs(m_createdUserName.c_str());
    g_packetSender->QueuePacket(packet.Data(), packet.Size());
}
```

Shared reply handler source shape:

```cpp
void NewUserDialogPane2::OnCreateUserReply(PacketReader &packet)
{
    const unsigned char result = packet.ReadByte();

    if (!m_sentCreateCharacter)
    {
        if (result == 0)
        {
            m_sentCreateCharacter = true;
            m_createdUserName = GetEditText(1);
            SendCreateCharacterRequest();
            return;
        }

        ShowCreateUserServerError(packet);
        ResetCreateUserState();
        return;
    }

    if (result == 0)
    {
        CloseDialog();
        return;
    }

    ShowCreateUserServerError(packet);
    ResetCreateUserState();
}
```

Implementation should substitute existing project class names for `PacketBuffer`, `PacketReader`, `GetEditText`, `ShowCreateUserAlert`, and `CreateScreenDimmerForLogin` once the surrounding packet/control docs provide exact names. The structure above is source-style and intentionally avoids compiler-generated labels.

## Recommended Target And Support Doc Changes

### `by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md`

- Change metadata to `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000IK`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
- Rewrite the disposition: "non-emitting create-user source-family split/index; exact children carry source ownership."
- Remove text that says the aggregate is reconstructable or that source split is capped below final reconstruction.
- Add the child-only emission policy and explain why the parent formal C++ must stay blank.
- Add the no-direct-caller status for `NewCreateUserDialogPane` as a resolved retained/reachability caveat, not an open blocker.
- Add the three singleton groups and class/file routes listed in this report.

### Child Memory Pages

- `0002QR`: keep direct owner/emitter `00009E`; add source-quality names for constructor, selector helpers, `OnCommand`, `SubmitCreateUser`, file-local `SendCreateAccountRequest`, `SendCreateCharacterRequest`, and `OnCreateUserReply`; add first-draft C++; raise to `88/88` if the implementation carries the C++ and field-name notes.
- `0002QS`: change metadata owner/emitter from `0000LP` to direct class `00008Z`; keep file route through `0000LP`; add no-direct-caller proof as resolved retained-code status; add first-draft C++; raise to `86/89`.
- `0002QT`: keep owner/emitter `00003B`; add old appearance-control method names and first-draft C++; raise to `87/89`.
- `0002QU`: set `RECONSTRUCTABLE:FALSE`, clear emitter, keep C++ blank, and describe the island as compiler lifecycle support. Raise to `88/90` because the no-code proof is now target-specific.

### Class And File Pages

- `by-file/CreateUserDialogs.md`: convert from an emitting source root to a family/index page. Preferred exact metadata change is `PROPOSED_RECONSTRUCTION_PATH:"NONE"` because `CreateUserDialogs.cpp` is not listed in `proposed-source-tree.md`. If supervisor chooses a smaller implementation, at minimum add a strong note that no memory child should emit through `0000IK`.
- `by-class/NewCreateUserDialogPane.md`: remove passive final-C++ blocker wording; keep the no-direct-caller status as a documented reachability caveat; add the packet helper names and field-name candidates.
- `by-class/NewUserDialogPane2.md`: replace stale generated constructor/destructor-name caveat with source-facing constructor naming; add packet helper names and field candidates.
- `by-class/CreateUserDialogPane.md`: replace stale `90/90+` gate wording with the active 85/85 combined-score gate and the real current blocker/source plan; add packet helper names and old appearance-control field candidates.
- `by-file/NewUserDialogPane2.md`, `by-file/NewCreateUserDialogPane.md`, `by-file/CreateUserDialogPane.md`: ensure each concrete file page owns the corresponding child cluster and not the broad aggregate.
- `by-global/g_pCreateUserDialogPane.md`: create this page for parity if supervisor accepts a new global page; otherwise update [UID:0002B3] as the canonical global storage reference. Do not leave only raw `dword_69B890` in source-facing target prose.
- `by-global/g_pNewUserDialogPane2.md` and `by-global/g_pNewCreateUserDialogPane.md`: ensure the pages explicitly mention the aggregate is non-emitting and the exact child classes own declarations.

### Main-Menu Support Docs

- `by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md` and `by-global/OpenCreateUserDialog_4F8FA0.md`: replace old `95/95` code-gate wording with active gate wording. Since these pages are emitting and meet the numeric gate, either add first-draft retained-helper C++ under `MainMenuPane.cpp` or explicitly document that supervisor has not accepted retained-helper C++ yet because inbound callback reachability remains unresolved.
- `by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md` and `by-global/CloseMainMenuDialogSingletons_4F69A0.md`: if the 00019J report is accepted, keep the cleanup helper in `MainMenuPane.cpp` and cross-link its create-user singleton branch to `g_pNewCreateUserDialogPane` / `g_pNewUserDialogPane2`; do not treat it as owning these dialog declarations.

## Exact Pending `by-memory/-coverage-report.md` Replacement Rows

Replace the existing row block for `0001CR` and its four child rows with the following text. Do not edit `by-memory/-coverage-report.md` from B010 while the shared-file ban is active.

```text
    - [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) 0x0052a540-0x0052f94c | source-family split index | CreateUserDialogVariants : ignored/non-emitting : 88% : strong : B010 source-quality reanalysis reclassifies this broad create-user executable island as a non-emitting split/index under [UID:0000IK] CreateUserDialogs; exact children carry source ownership for NewUserDialogPane2 [UID:0002QR], retained NewCreateUserDialogPane [UID:0002QS], old CreateUserDialogPane [UID:0002QT], and compiler lifecycle/destructor/thunk support [UID:0002QU]. Current evidence confirms constructor callers for `0x0052a540` and `0x0052dd30`, no direct caller for `0x0052c360`, vtable/singleton groups `0x0061fd04`/`0x0069b4a4`, `0x0061fda0`/`0x0069b4a8`, and `0x0061fe3c`/`0x0069b890`, duplicated opcode-`0x02` account-register packet helpers, variant-specific opcode-`0x04` create-character payload builders, and blank aggregate C++ to avoid duplicate generated `CreateUserDialogs.cpp` output.
        - [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) 0x0052a540-0x0052c325 | executable child | NewUserDialogPane2CreateUserVariant : reconstructable : 88% : strong : Exact alternate 640x480 create-user dialog child owned by NewUserDialogPane2 with constructor callers at `0x004f7ad0`/`0x004f9041`, selector helpers, command dispatcher, submit validator, duplicated opcode-`0x02` account-register packet encoder, opcode-`0x04` create-character payload builder using selected shape/body/totem state, reply handler, singleton/vtable evidence `0x0069b4a4`/`0x0061fd04`, and first-draft child C++ readiness.
        - [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) 0x0052c360-0x0052dcf5 | executable child | NewCreateUserDialogPaneCore : reconstructable : 86% : strong : Exact retained/newer create-user dialog child with no direct constructor caller after xref and PE pointer/branch scans, but strong source ownership from constructor, selector helpers, command dispatcher, submit/packet/reply helpers, NewUserShapeSelectControlPane construction, singleton/vtable lifecycle evidence `0x0069b4a8`/`0x0061fda0`, and recommended direct class routing through NewCreateUserDialogPane rather than the umbrella.
        - [UID:0002QT][0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore](by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md) 0x0052dd30-0x0052f6e5 | executable child | CreateUserDialogPaneCore : reconstructable : 87% : strong : Exact old DLGNEW3 CreateUserDialogPane child with constructor callers at `0x004f7a82`/`0x004f8ff8`, older appearance-control construction, body/gender/hair/face/color handlers, submit validator, duplicated opcode-`0x02` account-register packet encoder, opcode-`0x04` create-character payload builder from preview/appearance state, reply handler, singleton/vtable evidence `0x0069b890`/`0x0061fe3c`, and source placement in `login/CreateUserDialogPane.cpp`.
        - [UID:0002QU][0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland](by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md) 0x0052f710-0x0052f94c | compiler lifecycle island | CreateUserDialogDestructorAndThunkIsland : ignored/non-emitting : 88% : strong : B010 source-quality reanalysis keeps this as non-emitting lifecycle/thunk support for the three create-user variants: 11-byte singleton clear helpers for `g_pCreateUserDialogPane`/`g_pNewCreateUserDialogPane`/`g_pNewUserDialogPane2`, six 11-byte `this-0xa0`/`this-0xa4` adjustor thunks, helper-object scalar wrappers, and MSVC scalar deleting destructors at `0x0052f800`/`0x0052f870`/`0x0052f8e0`; normal source should declare/define ordinary class destructors on the owning class pages and let the compiler regenerate these wrappers.
```

## Validation Commands Needed After Implementation Callback

Run from `source-3/project-documentation` for every file actually changed. Minimum expected commands if the recommendations above are accepted:

> Executable block R001 was removed from this report and preserved verbatim in [0001CR-CreateUserDialogVariants-source-quality-removed.md](0001CR-CreateUserDialogVariants-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `by-global/g_pCreateUserDialogPane.md` is created, validate that new file as well. If the implementation changes `by-file/CreateUserDialogs.md` to `PROPOSED_RECONSTRUCTION_PATH:"NONE"`, check generated side effects and report whether `auto-generated/-ag-file-coverage.md` stops listing `CreateUserDialogs.cpp`.

## Remaining Issues

- Fresh live IDA MCP could not be run in this session. The report is based on current docs that already record live MCP facts, generated coverage, and PE scans. This prevents a final-audit score but does not undermine the split/index recommendation.
- Exact original field names for the create-user option bytes are not recoverable from binary evidence alone. Descriptive names are strong enough for first-draft C++ and should not block source routing.
- `NewCreateUserDialogPane` remains no-direct-caller in the current binary. This should remain documented as retained/no-direct-caller evidence, not as an ownership blocker.
- Whether `CreateUserDialogs.md` can be changed to `PROPOSED_RECONSTRUCTION_PATH:"NONE"` should be validator-confirmed during implementation. Existing by-file pages show `NONE` is a valid convention for rejected or non-standalone file roots.

## Validator Results

- Commands run: none. This was a report-only assignment and no target/support docs were edited.
- Validation required after implementation: listed above.
- Expected generated/project-level side effects: if accepted changes are applied, `auto-generated/-ag-memory-coverage.md` should stop emitting `0001CR` and `0002QU` to `auto-generated/NexusTK/login/CreateUserDialogs.cpp`. If `0000IK` path is set to `NONE`, `auto-generated/-ag-file-coverage.md` should stop listing a by-file generated root for `CreateUserDialogs.cpp`.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/0001CR-CreateUserDialogVariants-source-quality.md`
- Modified: none
- Renamed: none
- Moved to executed: none
- Leases used: none; no lease is required for B010 research-folder report creation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0001CR-CreateUserDialogVariants-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0001CR"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001CR-CreateUserDialogVariants-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0001CR-CreateUserDialogVariants-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001CR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
