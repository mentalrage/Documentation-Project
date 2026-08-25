** TARGET-REPORT-UID:00026T **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00026T UserInfoReadOnlyData Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00026T] as source-bearing read-only data for `UserInfoDialogPane`, but correct the range to stop at `0x0062e8fc`.
- Final disposition: `UserInfoDialogPane` vtables/RTTI are source-declared and compiler-emitted; the title, validation messages, resource literal, and option lists are source/resource literals owned by `NexusTK/login/UserInfoDialogPane.cpp`. Do not hand-code raw vtable dwords.
- Required action if accepted: rename/shrink the target from `0x0062e624-0x0062e960` to `0x0062e624-0x0062e8fc`, remove the stale `ERINFO.EPF`/`CD`/trailing text-island wording, add decoded label/resource semantics, and update UserList support docs so the `UserListDialogPane` primary COL/vtable lead-in starts at `0x0062e8fc`.
- Confidence: strong for owner/emitter route, corrected boundary, vtable identity, constructor string consumers, validation message roles, option-list roles, and generated-binary treatment; medium for original source spellings of class fields/helper APIs and for the unresolved constructor launch/factory path.

Recommended target metadata:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `92` |
| `CANONICAL_OWNER` | keep `0000OY` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `EMITTER_UIDS` | keep `0000OY` |
| Formal C++ | populate only declaration/resource-literal C++ if supervisor accepts; do not emit raw vtable/RTTI dwords |

## Target

- Target UID: [UID:00026T]
- Current target path: `source-3/project-documentation/by-memory/0x0062e624-0x0062e960.UserInfoReadOnlyData.md`
- Recommended target path: `source-3/project-documentation/by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/00026T-UserInfoReadOnlyData-source-quality.md`
- Current target score/state: `84/90`, `CANONICAL_OWNER:0000OY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OY`, blank C++.
- Current coverage row: `0x0062e624-0x0062e960`, `84%`, describes a title/resource/label string island and blank final C++.
- Generated state: `auto-generated/NexusTK/login/UserInfoDialogPane.cpp` currently contains empty emitter markers for [UID:0000FM], [UID:0001KG], and [UID:00026T]. `auto-generated/-ag-memory-coverage.md` routes [UID:00026T] to `auto-generated/NexusTK/login/UserInfoDialogPane.cpp`.

## Supervisor Active Recheck

- User assigned a B-agent report-only source-quality / heuristic pass for [UID:00026T] `UserInfoReadOnlyData`.
- Report-only pass: no target/support by-* docs were edited, no generated/project files were edited, and `by-memory/-coverage-report.md` was not edited.
- Completed B007 reports `000125`, `00015G`, `00018P`, `00019M`, and `0001C0` were preserved. This report file did not already exist before creation.
- B001/B002/B007 research folders were searched for `00026T`, `UserInfoReadOnlyData`, `0x0062e624`, `UserInfoDialogPane`, and related resource/string labels. No prior direct B-agent report for this UID was found.

## Evidence Standards Used

- Direct binary-derived evidence: existing live IDA notes in target/support docs plus local IDA export `.lst`, `.c`, and `.map` files under `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS`.
- Documentation evidence: target page, [UID:0000OY] `UserInfoDialogPane` file page, [UID:0000FM] `UserInfoDialogPane` class page, [UID:0001KG] executable page, [UID:0001KH] adjustor-thunk page, predecessor [UID:00026S], successor [UID:00026U], [UID:0003E6] UserList vtable child, `proposed-source-tree.md`, generated coverage tables, and current coverage rows.
- Inference guidance: `.rdata` can be reconstructable as source-declared/generated-binary vtables and source literals; compiler-generated vtables/RTTI should rebuild through class declarations, not handwritten dword arrays.
- IDA MCP status: a fresh request to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`. This report therefore relies on existing live-IDA documentation plus local IDA exports.

## IDA / Export Facts

- Local `.lst` export shows the `UserInfoDialogPane` read-only data starts at `0x0062e624` with `dd offset ??_R4UserInfoDialogPane@@6B@`, followed by the primary vtable at `0x0062e628`.
- Local `.map` export lists three `UserInfoDialogPane::vftable` bases at `0x0062e628`, `0x0062e688`, and `0x0062e6b8`, plus the title label `aUserInformatio` at `0x0062e6c0`.
- Local `.c` export records the constructor `sub_599CC0` storing the three vtable bases at `this`, `this+0xa0`, and `this+0xa4`, and copying validation strings into eight `0x80`-wide buffers starting at `this+0x26c`.
- `int_convert.py` verified: `0xa0` is decimal `160`, `0xa4` is decimal `164`, `0x26c` is decimal `620`, `0x80` is decimal `128`, and packet opcode `0x53` is decimal `83` / ASCII `S`.
- Existing executable docs and local exports agree on method starts:
  - constructor `0x00599cc0-0x0059aff0`;
  - command handler `0x0059b000-0x0059b0ed`;
  - input/key/focus callbacks `0x0059b0f0`, `0x0059b110`, `0x0059b130`;
  - OK-state updater `0x0059b150-0x0059b253`;
  - validation helper `0x0059b260-0x0059b5b4`;
  - packet sender `0x0059b5c0-0x0059bc2c`;
  - adjustor thunks `0x0059bc2d` and `0x0059bc38`;
  - scalar deleting destructor `0x0059bc50-0x0059bc8b`.
- Export search found no direct `call sub_599CC0`; this agrees with [UID:0000OY]'s live IDA note that the constructor launch path is unresolved and likely indirect through a packet/dialog factory path.

## Corrected Range / Boundary

The current target end `0x0062e960` is too late. The precise UserInfo end is `0x0062e8fc`.

Evidence:

- The last UserInfo source literal is the discovery/referral option at `0x0062e8f0`; bytes decode as UTF-16 `CD방터`, terminated/aligned through `0x0062e8fb`.
- The dword at `0x0062e8fc` is bytes `68 1c 65 00`, i.e. pointer `0x00651c68`.
- Local `.lst` identifies `0x00651c68` as `??_R4UserListDialogPane@@6B@`, the primary `UserListDialogPane` complete-object locator.
- `0x0062e900` is `off_62E900 dd offset sub_59F110`; local `.c` shows it is stored by the `"Users Dialog Pane"` constructor and restored by the `UserListDialogPane` destructor.
- `0x0062e95c`, `0x0062e960`, `0x0062e98c`, and `0x0062e990` are the secondary/tertiary `UserListDialogPane` COL/vtable records already modeled by [UID:0003E6].

Verified sizes:

| Span | Meaning | Size |
| --- | --- | ---: |
| `0x0062e624-0x0062e8fc` | corrected `UserInfoReadOnlyData` | `0x2d8` / decimal `728` |
| `0x0062e8fc-0x0062e900` | `UserListDialogPane` primary COL word | `0x4` / decimal `4` |
| `0x0062e8fc-0x0062e960` | misplaced UserList primary COL + primary vtable lead-in currently inside 00026T | `0x64` / decimal `100` |

Rejected alternatives:

- Keep current end `0x0062e960`: rejected because it includes the UserList primary COL and primary vtable.
- End at `0x0062e900`: rejected because it still includes the UserList primary COL at `0x0062e8fc`.
- Merge with [UID:00026U]: rejected for UserInfo-owned `0x0062e624-0x0062e8fc`; only the misplaced tail belongs to UserList.

## Vtable Slot Meaning

The vtables are not handwritten source arrays. They should be regenerated from the `UserInfoDialogPane` declaration, its base classes, and its virtual overrides.

| Address | Slot/value | Source meaning |
| --- | --- | --- |
| `0x0062e624` | `??_R4UserInfoDialogPane@@6B@` | primary complete-object locator pointer |
| `0x0062e628` | `sub_59BC50` | scalar deleting destructor slot |
| `0x0062e62c-0x0062e66c` | shared/inherited UI slots | inherited dialog/control behavior |
| `0x0062e670` | `sub_59B000` | `UserInfoDialogPane::OnButtonCommand` / OK-cancel command handler |
| `0x0062e674` | `sub_59B150` | `UpdateOkButtonState` |
| `0x0062e678-0x0062e67c` | shared/inherited focus/control slots | inherited behavior |
| `0x0062e680` | `sub_59B130` | focus-change callback that refreshes OK state |
| `0x0062e684` | `??_R4UserInfoDialogPane@@6B@_0` | secondary complete-object locator pointer |
| `0x0062e688` | `sub_59BC2D` | `this -= 0xa0` destructor adjustor thunk |
| `0x0062e68c` | `sub_59B0F0` | input event forwarding callback |
| `0x0062e690` | `sub_59B110` | key event forwarding callback |
| `0x0062e694-0x0062e6b0` | shared/inherited UI slots | inherited behavior |
| `0x0062e6b4` | `??_R4UserInfoDialogPane@@6B@_1` | tertiary complete-object locator pointer |
| `0x0062e6b8` | `sub_59BC38` | `this -= 0xa4` destructor adjustor thunk |
| `0x0062e6bc` | `sub_544E90` | inherited tertiary-interface slot |

## Resource / String Meanings

The current target under-describes the string region. The local `.lst` and constructor consumers support the following map.

### Dialog And Validation Strings

| Address | Literal | Consumer / role |
| --- | --- | --- |
| `0x0062e6c0` | `User Information Dialog Pane` | constructor title passed to dialog base setup |
| `0x0062e6fc` | `이름이 잘못 입력되었습니다.` | validation error 0; name contains digits or is empty/invalid |
| `0x0062e71c` | `주민등록번호가 잘못 입력되었습니다.` | validation errors 1 and 2; resident-registration number half/checksum invalid |
| `0x0062e744` | `부모님 이름이 잘못 입력되었습니다.` | validation error 3; parent-name field is numeric/invalid |
| `0x0062e76c` | `혈액형을 입력하십시요.` | validation error 4; blood-type selection required |
| `0x0062e788` | `거주지를 입력하십시요.` | validation error 5; residence/region selection required |
| `0x0062e7a4` | `주로하는 방법을 입력하십시요.` | validation error 6; primary access/play method selection required |
| `0x0062e7c8` | `처음하게된 동기를 입력하십시요.` | validation error 7; first-discovery/referral reason selection required |

`OnButtonCommand` indexes the message table as `this + 0x26c + error * 0x100` and focuses control `error + 3`; this proves the error-to-control mapping. Status `10` is success.

### Resource Literal And Selection Options

| Address | Literal(s) | Recommended source role |
| --- | --- | --- |
| `0x0062e7ec` | `USERINFO.EPF` | background/image resource for the user-info dialog |
| `0x0062e808-0x0062e814` | `A`, pooled `B`, `AB`, `O` | blood-type options; `B` is likely pooled as a substring of `AB`, not a separate top-level IDA label |
| `0x0062e818-0x0062e880` | `서울시`, `광주시`, `대구시`, `대전시`, `부산시`, `울산시`, `인천시`, `강원도`, `경기도`, `경상도`, `전라도`, `제주도`, `충청도`, `해외` | residence/region options |
| `0x0062e888-0x0062e8b0` | `게임방 및 인터넷카페`, `통신사`, `인포샵`, `인터텟(PPP)` | primary access/play method options; keep binary spelling `인터텟` unless product localization later proves a typo correction is source-intended |
| `0x0062e8c4-0x0062e8f0` | `친구`, `게임방`, `검색엔진`, `통신사`, `신문이나 잡지`, `CD방터` | first-discovery/referral reason options |

Generated-name issues:

- `ERINFO.EPF` is not a standalone source resource. IDA starts a substring label at `0x0062e7f0`, but the dword at `0x0062e7ec` plus the following bytes decode to full `USERINFO.EPF`.
- `aUs_1` / `off_62E7EC` are data-definition artifacts. Treat the source literal as `L"USERINFO.EPF"`.
- `aCd` / `off_62E8F0` is also a truncated IDA artifact. The full UTF-16 literal at `0x0062e8f0` is `CD방터`.

## Source Placement / Ownership

- Keep [UID:00026T] attached to [UID:0000OY] `UserInfoDialogPane`, emitted through `auto-generated/NexusTK/login/UserInfoDialogPane.cpp`.
- Keep source path hypothesis `NexusTK/login/UserInfoDialogPane.cpp`. `proposed-source-tree.md` places this with the login/account UI family and explicitly separates it from adjacent `UserListDialogPane`.
- Do not route the corrected `0x0062e624-0x0062e8fc` span to social/user-list ownership. Only the current tail `0x0062e8fc-0x0062e960` belongs to UserList.
- Do not route the option strings to generic control infrastructure. The control classes own list/choice mechanics; `UserInfoDialogPane` owns this form's validation messages and option literals.

## Field / Helper Name Recommendations

High-probability source names:

| Binary evidence | Recommended source name | Confidence |
| --- | --- | --- |
| control id `3`, text field, non-numeric validation | `m_nameEdit` / `kNameEdit` | high |
| control ids `4` and `5`, numeric/checksum validation | `m_residentIdPrefixEdit`, `m_residentIdSuffixEdit` | high |
| control id `6`, non-numeric parent-name validation | `m_parentNameEdit` | high |
| control id `7`, `A/B/AB/O` options | `m_bloodTypeCombo` | high |
| control id `8`, Korean region list | `m_residenceCombo` or `m_regionCombo` | high |
| control id `9`, PC room/telecom/InfoShop/PPP list | `m_primaryAccessMethodCombo` | medium-high |
| control id `10`, friend/PC room/search/telecom/newspaper/CD list | `m_discoveryReasonCombo` / `m_referralSourceCombo` | medium-high |
| `this+0x26c`, eight `0x80` wchar buffers | `m_validationMessages[8][128]` | high |
| `this[127]` child-control lookup host | `m_controlHost` / `m_controls` | medium |

Helper names that should replace raw `sub_` labels in target/support prose:

- `sub_498C10`: text-control get/copy text helper.
- `sub_498C60`: text-control empty check.
- `sub_4981A0`: choice-control selected-index getter.
- `sub_498180`: choice-control item getter.
- `sub_498220`: choice-control selected-index setter, with `-1` as no-selection.
- `sub_517070`: copy selected/list item label text into a bounded wide buffer.
- `sub_516030`, `sub_575380`, `sub_516220`, `sub_574BB0`: packet initialization, byte/length write, payload copy/encode, and session send helpers already documented by [UID:0001KG].

## First-Draft Declaration / Resource C++

This is appropriate as a source-style declaration/resource sketch for `UserInfoDialogPane.cpp`. It is not a raw `.rdata` dword reconstruction.

```cpp
namespace {

enum UserInfoControlId {
    kUserInfoOkButton = 1,
    kUserInfoCancelButton = 2,
    kUserInfoNameEdit = 3,
    kUserInfoResidentIdPrefixEdit = 4,
    kUserInfoResidentIdSuffixEdit = 5,
    kUserInfoParentNameEdit = 6,
    kUserInfoBloodTypeCombo = 7,
    kUserInfoResidenceCombo = 8,
    kUserInfoPrimaryAccessMethodCombo = 9,
    kUserInfoDiscoveryReasonCombo = 10,
};

enum UserInfoValidationResult {
    kUserInfoNameInvalid = 0,
    kUserInfoResidentIdPrefixInvalid = 1,
    kUserInfoResidentIdSuffixInvalid = 2,
    kUserInfoParentNameInvalid = 3,
    kUserInfoBloodTypeRequired = 4,
    kUserInfoResidenceRequired = 5,
    kUserInfoPrimaryAccessMethodRequired = 6,
    kUserInfoDiscoveryReasonRequired = 7,
    kUserInfoValidationSucceeded = 10,
};

static const wchar_t kUserInfoDialogTitle[] = L"User Information Dialog Pane";
static const wchar_t kUserInfoBackgroundResource[] = L"USERINFO.EPF";

static const wchar_t *const kUserInfoValidationMessages[] = {
    L"이름이 잘못 입력되었습니다.",
    L"주민등록번호가 잘못 입력되었습니다.",
    L"주민등록번호가 잘못 입력되었습니다.",
    L"부모님 이름이 잘못 입력되었습니다.",
    L"혈액형을 입력하십시요.",
    L"거주지를 입력하십시요.",
    L"주로하는 방법을 입력하십시요.",
    L"처음하게된 동기를 입력하십시요.",
};

static const wchar_t *const kBloodTypeOptions[] = { L"A", L"B", L"AB", L"O" };

static const wchar_t *const kResidenceOptions[] = {
    L"서울시", L"광주시", L"대구시", L"대전시", L"부산시", L"울산시", L"인천시",
    L"강원도", L"경기도", L"경상도", L"전라도", L"제주도", L"충청도", L"해외",
};

static const wchar_t *const kPrimaryAccessMethodOptions[] = {
    L"게임방 및 인터넷카페", L"통신사", L"인포샵", L"인터텟(PPP)",
};

static const wchar_t *const kDiscoveryReasonOptions[] = {
    L"친구", L"게임방", L"검색엔진", L"통신사", L"신문이나 잡지", L"CD방터",
};

} // namespace

class UserInfoDialogPane : public DialogPane {
public:
    explicit UserInfoDialogPane(const unsigned char *packet);
    ~UserInfoDialogPane() override;

private:
    void OnButtonCommand(int commandId, int eventArg);
    bool OnInputEvent(InputEvent *event) override;
    bool OnKeyEvent(KeyEvent *event) override;
    void OnFocusChanged(int controlId) override;
    void UpdateOkButtonState();
    UserInfoValidationResult ValidateInput() const;
    void SendUserInfo();

    wchar_t m_validationMessages[8][128]; // offset 0x26c in current binary layout
};
```

Readiness note: exact base-class names and virtual callback parameter types are still inferred. The literal arrays and control/error IDs are ready for first-draft source; method bodies remain better owned by [UID:0001KG] or exact method children until helper API names are finalized.

## Source-Bearing Versus Generated-Binary Treatment

- Best classification: source-bearing read-only data, not `RECONSTRUCTABLE:FALSE` no-code.
- Vtables/RTTI: source-declared/generated-binary. The source responsibility is the `UserInfoDialogPane` class declaration, virtual destructor, overrides, and base-class layout. The compiler emits `??_7` and `??_R4` records.
- Strings: source/resource literals. The constructor consumes them directly to set the dialog title, create the background asset, copy validation messages, populate choices, and select packet-provided defaults.
- Do not hand-write `.rdata` dword arrays for the vtables, `off_62E7EC`, `off_62E8F0`, or `off_62E900`.
- Do not downgrade this page to no-code. Unlike scalar deleting destructor glue, the range includes feature-owned source literals with direct constructor semantics.

Generated-data proof for vtables:

- All vtable symbols use MSVC `??_7` and RTTI `??_R4` names.
- Constructor stores the three table bases into the object; adjustor-thunk docs show secondary/tertiary destructor routing.
- The vtable slots reference ordinary method bodies and inherited base functions; no source file should declare the vtable bytes manually.

## Rejected Alternatives

- `ERINFO.EPF` as a second resource: rejected. It is the suffix of `USERINFO.EPF` produced by IDA's incorrect data split.
- `CD` as the final option literal: rejected. Full bytes at `0x0062e8f0` decode as `CD방터`.
- "Trailing deployment text island": rejected. The tail after `CD방터` is the `UserListDialogPane` primary complete-object locator and vtable, not UserInfo text.
- Parent as [UID:0000OZ] `UserListDialogPane`: rejected for `0x0062e624-0x0062e8fc`; only the current overrun tail belongs there.
- Parent as reusable controls: rejected. Control helper APIs are dependencies, not owners of these form-specific literals.
- Keep blank final C++ because "below 95/95": rejected as stale gate wording. Active guidance is reconstructable true, emitter present, and average score above 85 when source shape is safe. Here the safe source shape is declarations/literals, not raw `.rdata`.

## Recommended Target Doc Changes

Apply only after supervisor implementation callback:

- Rename `source-3/project-documentation/by-memory/0x0062e624-0x0062e960.UserInfoReadOnlyData.md` to `source-3/project-documentation/by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md`.
- Header: set `COMPLETION:88`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:0000OY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OY`.
- Range section: change address range to `0x0062e624-0x0062e8fc`; state size `0x2d8` / decimal `728`.
- Summary: replace "trailing user-info text island before the next user-list dialog vtables" with "UserInfoDialogPane RTTI/vtables, title, validation messages, background resource literal, and user-info choice-option literals; the successor UserListDialogPane primary COL begins at `0x0062e8fc`."
- Observed Contents: replace current table with the decoded table from this report, including validation strings, `USERINFO.EPF`, blood types, region options, primary access method options, and discovery reason options.
- Boundary Evidence: add the `0x0062e8fc -> 0x00651c68 -> ??_R4UserListDialogPane@@6B@` proof and `off_62E900` constructor/destructor store evidence.
- Reconstruction Notes: remove "below old 95/95" and say declaration/resource C++ is ready while raw vtable/RTTI dwords remain compiler-generated.
- Related docs: update successor link text to the recommended `0x0062e8fc-0x0062eccc.UserListReadOnlyData.md` if support update is performed in the same callback.

## Recommended Support Doc Changes

These are support updates required by the corrected boundary. They should be handled in the same implementation callback or a dedicated UserList boundary repair callback.

- Rename/update [UID:00026U] from `0x0062e960-0x0062eccc.UserListReadOnlyData.md` to `0x0062e8fc-0x0062eccc.UserListReadOnlyData.md`.
  - Start boundary becomes `0x0062e8fc`, not `0x0062e960`.
  - First child span should be `0x0062e8fc-0x0062e998` for `UserListDialogPane` vtable data.
  - Keep `RECONSTRUCTABLE:FALSE` for the mixed aggregate; exact children carry source ownership.
- Rename/update [UID:0003E6] from `0x0062e960-0x0062e998.UserListDialogPaneVtableLeadInData.md` to `0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md`.
  - Add `0x0062e8fc` primary COL pointer to `??_R4UserListDialogPane@@6B@`.
  - Add primary table at `0x0062e900`, first slot `sub_59F110`, stored at `this` in the UserList constructor/destructor.
  - Keep secondary table at `0x0062e960` and tertiary table at `0x0062e990`.
  - Recommended support metadata: `COMPLETION:88`, `CONFIDENCE:92`, owner/emitter `0000FN`, `RECONSTRUCTABLE:TRUE`.
- Update [UID:0000FN] `by-class/UserListDialogPane.md` and [UID:0000OZ] `by-file/UserListDialogPane.md` links from `0x0062e960-0x0062e998` to `0x0062e8fc-0x0062e998`.
- Update [UID:0001KI] `0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md` read-only data references to mention `0x0062e8fc`, `0x0062e900`, `0x0062e960`, and `0x0062e990`.
- Update [UID:0000OY] and [UID:0000FM] UserInfo support docs to reference the corrected [UID:00026T] path/range and decoded strings.

## Exact Pending Coverage Text

Replace the current [UID:00026T] row in `by-memory/-coverage-report.md` with:

```text
    - [UID:00026T][0x0062e624-0x0062e8fc.UserInfoReadOnlyData](by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md) 0x0062e624-0x0062e8fc | vtable/string-data | UserInfoReadOnlyData : reconstructable : 88% : strong : Attached to UserInfoDialogPane.cpp; documents the UserInfoDialogPane RTTI/vtable slice, dialog title, validation-message literals, corrected USERINFO.EPF asset literal, blood-type/residence/access-method/discovery option strings, and source-declared/generated-binary handling; boundary corrected to stop before the UserListDialogPane primary RTTI/vtable lead-in at 0x0062e8fc, with declaration/resource C++ ready and raw vtable dwords left to the compiler.
```

If the support boundary is accepted in the same callback, also replace the current [UID:00026U] row with:

```text
    - [UID:00026U][0x0062e8fc-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md) 0x0062e8fc-0x0062eccc | vtable/string-data | UserListReadOnlyData : ignored : 88% : strong : Mixed non-emitting user-list read-only-data aggregate; boundary corrected to include the UserListDialogPane primary COL at 0x0062e8fc and primary vtable at 0x0062e900, while exact children carry the UserListDialogPane, CheckBoxTextControlPane, PartySearchEditPane, UserListPane, and resource-string source ownership before the UserLook successor boundary.
```

Recommended replacement text for the [UID:0000FN] class coverage row if support links are updated:

```text
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md) : reconstructable : 88% : strong : Social user-list dialog class with file-parent attachment, corrected exact vtable child [UID:0003E6][0x0062e8fc-0x0062e998.UserListDialogPaneVtableData](by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md), packed `0x414` `UserListRecord` layout, constructor packet fields, opcode `0x83` hunters-list flag update, opcode `0x84` source-text update, corrected status/name sort helper names, singleton/filter globals, local UserListPane/PartySearch ownership, and class-level first-draft C++ declaration ready.
```

## Validation Needed

No validator was run because this was report-only and no target/support docs were edited.

Recommended implementation/validation commands after supervisor callback:

> Executable block R001 was removed from this report and preserved verbatim in [00026T-UserInfoReadOnlyData-source-quality-removed.md](00026T-UserInfoReadOnlyData-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Manual checks to rerun if IDA MCP is available:

- `xrefs_to 0x00599cc0` for constructor launch path.
- `xrefs_to 0x0062e7ec`, `0x0062e8f0`, `0x0062e8fc`, and `0x0062e900`.
- `get_bytes 0x0062e7ec 0x114` to confirm `USERINFO.EPF` through the `UserListDialogPane` primary COL boundary.

## IDA Rename / Type / Comment Recommendations

High-confidence renames/comments:

- `sub_599CC0` -> `UserInfoDialogPane::UserInfoDialogPane`.
- `sub_59B000` -> `UserInfoDialogPane::OnButtonCommand` or `OnControlCommand`.
- `sub_59B0F0` -> `UserInfoDialogPane::OnInputEvent`.
- `sub_59B110` -> `UserInfoDialogPane::OnKeyEvent`.
- `sub_59B130` -> `UserInfoDialogPane::OnFocusChanged`.
- `sub_59B150` -> `UserInfoDialogPane::UpdateOkButtonState`.
- `sub_59B260` -> `UserInfoDialogPane::ValidateInput`.
- `sub_59B5C0` -> `UserInfoDialogPane::SendUserInfo`.
- `sub_59BC50` -> `UserInfoDialogPane` scalar deleting destructor, compiler-generated.
- `sub_59BC2D` / `sub_59BC38` -> `UserInfoDialogPane` destructor adjustor thunks for `this-0xa0` and `this-0xa4`.
- `0x0062e7ec`: undefine `off_62E7EC`, create UTF-16 string `aUserinfoEpf`, comment `full USERINFO.EPF literal; ERINFO.EPF is only a suffix label`.
- `0x0062e8f0`: undefine `off_62E8F0`, create UTF-16 string `aUserInfoDiscoveryCdBangteo` or `aDiscoveryCdBangteo`, comment `full literal CD방터; aCd is truncated`.
- `0x0062e8fc`: define as `dd offset ??_R4UserListDialogPane@@6B@`, comment `UserListDialogPane primary COL; successor boundary for UserInfoReadOnlyData`.
- `0x0062e900`: rename `off_62E900` to the primary `UserListDialogPane` vtable label if IDA permits.

Medium-confidence comments/names:

- `word_62E6FC` -> name-invalid validation message.
- `word_62E71C` -> resident-registration-number invalid validation message.
- `word_62E744` -> parent-name invalid validation message.
- `word_62E76C` -> blood-type required validation message.
- `word_62E788` -> residence required validation message.
- `word_62E7A4` -> primary access method required validation message.
- `word_62E7C8` -> discovery reason required validation message.
- `word_62E818-0x0062e880`: residence option strings.
- `word_62E888-0x0062e8b0`: primary access method option strings.
- `word_62E8C4-0x0062e8f0`: discovery/referral option strings.

## Open Questions / Attempted Resolution

- Constructor launch path: still open. Existing live docs found no direct xrefs to `0x00599cc0`; local `.lst/.c` export search likewise found no direct `call sub_599CC0`. Keep as likely indirect packet/dialog factory route.
- Original helper/class field names: binary supports strong descriptive names for controls and validation buffers, but not original source spellings. Use descriptive names with inferred-note until real symbols/source appear.
- Base virtual callback signatures: vtable slot roles are clear from bodies, but exact project types such as `InputEvent`, `KeyEvent`, and command-event arguments remain source-style placeholders.
- Whether support boundary repair should be bundled with target implementation: evidence says yes, but it touches [UID:00026U] and [UID:0003E6]. If supervisor wants narrower implementation, update [UID:00026T] first and leave explicit TODOs to move `0x0062e8fc-0x0062e960` into UserList docs.

## Report Status

FINISHED. Report-only task completed; no by-* docs, generated docs, validator files, or coverage reports were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00026T-UserInfoReadOnlyData-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"00026T"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00026T-UserInfoReadOnlyData-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/00026T-UserInfoReadOnlyData-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00026T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
