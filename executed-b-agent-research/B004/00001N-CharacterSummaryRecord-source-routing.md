** TARGET-REPORT-UID:00001N **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00001N CharacterSummaryRecord source-routing report

Agent: B004
Assignment: `B004-goal2-character-summary-record-source-routing-00001N-20260619`
Target: `source-3/project-documentation/by-class/CharacterSummaryRecord.md`
Report-only status: no by-* docs were edited. `by-memory/-coverage-report.md` was not edited. No A/C agents were used.

## Final recommendation

Keep [UID:00001N] `CharacterSummaryRecord` as a non-reconstructable generated pseudo-class, not as an original standalone class or source type.

Recommended target metadata:

- `COMPLETION:88`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- formal `RECONSTRUCTION_CPP CODE` blank

The underlying executable code remains reconstructable, but it is already represented by [UID:0001NN] `0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors`, owned by [UID:0000FS] `UserStatusPane`, with file route through [UID:0000P2] `UserStatusPane` / `NexusTK/ui/panels/UserStatusPane.cpp`. The target class page should document the generated alias and no-code proof; it should not emit a `CharacterSummaryRecord` declaration or methods.

Score cap: do not raise this target to 95+. The negative classification is strong, but the surrounding `UserStatusPane` final source field names, the adjacent no-xref signed getter at `0x005b86d0`, and the exact source-level declaration style for the accessor island are still below final-audit quality. Those issues limit final naming confidence, not the non-standalone decision.

## Evidence checked

Required/local instruction evidence:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B004/goal.md`
- `by-structure.md` search for generated-output, reconstructable, score, C++ gate, and source placement rules.
- `inference_research.md` search for source-file and class inference standards.
- `by-project-structure/proposed-source-tree.md` status HUD section.

Target/support documentation checked:

- `by-class/CharacterSummaryRecord.md`
- `by-file/CharacterSummaryRecord.md`
- `by-class/UserStatusPane.md`
- `by-file/UserStatusPane.md`
- `by-memory/0x005b83b0-0x005baafe.UserStatusPane.md`
- `by-memory/0x005b83b0-0x005b8526.UserStatusPaneConstructor.md`
- `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md`
- `by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md`
- `by-memory/0x005ba4a0-0x005baafe.UserStatusPaneStatusPayloadApply.md`
- `by-type/by-struct/UserStatusPaneSummaryFields.md`
- `by-global/g_activeUserStatusPane.md`
- `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`

Generated/report evidence checked:

- `source-3/simroot_v2/class_CharacterSummaryRecord.cpp`
- `source-3/simroot_v2/class_UserStatusPane.cpp`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-type-coverage.md`
- `auto-generated/-ag-global-coverage.md`
- `project-level/-auto-completion-stats.md`
- `project-level/-resolved.md`
- `project-level/-resolved-multple-aliases.md`
- `project-level/-unresolved.md`
- by-class/by-file/by-type/by-memory coverage reports
- prior B-agent research search under B001/B002/B004 research folders; no prior CharacterSummaryRecord B report was found.

Binary evidence checked:

- Local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- Sections used: `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, `.data 0x0066d000-0x0069ce24`
- Manual PE mapping plus Capstone 5.0.7 disassembly/xref scans.

IDA MCP status:

- Attempted `http://127.0.0.1:13337/mcp`.
- Result: `IDA_MCP_UNAVAILABLE: Unable to connect to the remote server`.
- Current report therefore uses local PE disassembly plus existing IDA-backed documentation. The local PE identity matches the MD5 already recorded in the status-pane docs.

## Local PE facts

`UserStatusPane` constructor and singleton:

- `0x005b83b0-0x005b8526` is the `UserStatusPane` constructor body.
- It calls the pane base constructor at `0x00544460`.
- It stores `this` to `0x0069ae0c` at `0x005b83fa`, with a null-adjustment store at `0x005b8401`.
- It installs vtable pointers at complete offsets `+0x00`, `+0xa0`, and `+0xa4`.
- It loads `9X11FONT.BIN` through `0x004bb120`.
- It copies the incoming name to `+0x0fc`.
- In the EPF/new layout branch, it also clears the text lines at `+0x17c` and `+0x1fc`.
- It initializes the summary tail: `+0x27c` word to `0xffff`, `+0x27e` dword to `0x0000ffff`, `+0x282` word to `0`, `+0x284` byte to `0x34` / 52, and dwords `+0x288` through `+0x2a4` to zero.
- It has one local rel32 constructor call at `0x004f837a`, matching `InitializeMainUiGraph`.

Singleton storage:

- Exact storage address is `0x0069ae0c`.
- Local PE absolute scan found 67 dword references to `0x0069ae0c`, matching the current global docs.
- Representative call sites load `ecx` directly from `0x0069ae0c` before calling accessor methods.

Generated `CharacterSummaryRecord` accessors:

| Range | Local PE body | Source interpretation |
| --- | --- | --- |
| `0x005b85b0-0x005b85cc` | `lea eax,[ecx+0xfc]`, pushes source/capacity/destination into `0x005cd657`, `ret 8` | `UserStatusPane` copy-out helper for `+0x0fc`. |
| `0x005b85d0-0x005b85ec` | `lea eax,[ecx+0x1fc]`, same copy helper, `ret 8` | `UserStatusPane` copy-out helper for `+0x1fc`. |
| `0x005b85f0-0x005b85f7` | `mov al,[ecx+0x281]`, `ret` | byte getter at `+0x281`. |
| `0x005b8600-0x005b8607` | `mov al,[ecx+0x282]`, `ret` | byte getter at `+0x282`. |
| `0x005b8610-0x005b8617` | `mov al,[ecx+0x283]`, `ret` | byte getter at `+0x283`. |
| `0x005b8620-0x005b8627` | `mov al,[ecx+0x27c]`, `ret` | nation id getter. |
| `0x005b8630-0x005b8637` | `mov al,[ecx+0x27e]`, `ret` | spirit/totem id getter. |
| `0x005b8640-0x005b8647` | `mov eax,[ecx+0x28c]`, `ret` | dword display-value getter. |
| `0x005b8650-0x005b8657` | `mov eax,[ecx+0x294]`, `ret` | dword display-value getter. |
| `0x005b8660-0x005b8667` | `mov eax,[ecx+0x298]`, `ret` | missing generated sibling: third dword display-value getter. |
| `0x005b8670-0x005b869a` | copies input text to `+0x17c`, then calls vtable slot `+0x20` with `this+0x44` | display-line setter plus refresh/invalidation. |
| `0x005b86a0-0x005b86ca` | copies input text to `+0x1fc`, then calls vtable slot `+0x20` with `this+0x44` | display-line setter plus refresh/invalidation. |

Adjacent raw helper:

- `0x005b86ca-0x005b86d0`: six `0xcc` bytes.
- `0x005b86d0-0x005b86d8`: `movsx eax, byte ptr [ecx+0x27e]; ret`.
- `0x005b86d8-0x005b86e0`: eight `0xcc` bytes.
- Local rel32 and absolute scans found no inbound refs to `0x005b86d0`.
- Best interpretation: a retained/no-route signed getter for the same spirit/totem byte at `+0x27e`; it is a separate follow-up, not part of the current exact [UID:0001NN] range and not evidence for `CharacterSummaryRecord` as a real class.

Setter after the island:

- `0x005b86e0-0x005b86f8` writes byte `+0x27f`, then tail-jumps through vtable slot `+0x20` with `this+0x44`.
- Local rel32 scan found one direct call at `0x005aad65`, matching [UID:0002LP] documentation.

Internal alignment:

- Every internal gap between the modeled accessor functions in `0x005b85b0-0x005b86ca` is `0xcc` padding.
- There is no hidden constructor, destructor, vtable install, allocation, or standalone object setup inside this island.

## Direct caller / receiver evidence

Local rel32 scan results for the main accessor island:

- `0x005b85b0`: callers at `0x004a1e18`, `0x004acb1d`, `0x00566bee`, `0x005705e7`.
- `0x005b85d0`: caller at `0x004acb2d`.
- `0x005b85f0`: callers at `0x00567f97`, `0x0057194c`.
- `0x005b8600`: callers at `0x0056804a`, `0x005719ff`.
- `0x005b8610`: callers at `0x00568103`, `0x00571abe`.
- `0x005b8620`: callers at `0x00567cae`, `0x0059be29`, `0x0059d322`.
- `0x005b8630`: caller at `0x00567e04`.
- `0x005b8640`: callers at `0x00566bf5`, `0x005681be`, `0x005705ee`.
- `0x005b8650`: callers at `0x00566c08`, `0x005683bc`, `0x005705fb`.
- `0x005b8660`: no local rel32 callers and no absolute pointer refs.
- `0x005b8670`: callers at `0x00565a2e`, `0x00570277`.
- `0x005b86a0`: callers at `0x00565b2f`, `0x00570378`.

Representative receiver setup:

- `0x004a1e0a` loads `ecx = [0x0069ae0c]` before calling `0x005b85b0`.
- `0x004acb0c` loads `esi = [0x0069ae0c]`; `0x004acb1b` moves `ecx = esi` before `0x005b85b0`; `0x004acb2a` repeats `ecx = esi` before `0x005b85d0`.
- `0x00567f91`, `0x00571946`, `0x00567ca8`, `0x0059be23`, `0x0059d31c`, and `0x00567dfe` load `ecx = [0x0069ae0c]` before byte getter calls.
- `0x00565a27` / `0x00570270` load `ecx = [0x0069ae0c]` before `SetDisplayLineA`.
- `0x00565b28` / `0x00570371` load `ecx = [0x0069ae0c]` before `SetDisplayLineB`.
- `0x005aad5f` loads `ecx = [0x0069ae0c]` before `SetStatusIconId`.

This is strong negative evidence against an embedded subobject class. If the original source had called methods on an embedded record member, call sites would normally pass `this + fieldOffset` or an address stored inside the pane. Instead, they pass the active `UserStatusPane` object pointer itself and the methods use full `UserStatusPane` offsets.

## Field/name inference

Best current field slice, normalized to the `UserStatusPane` object base:

| Offset | Best source-level role | Confidence / caveat |
| --- | --- | --- |
| `+0x0fc` | primary name/title line, generated `m_nameLineA` | Strong offset; final source name may be `m_nameText` / `m_characterName`. |
| `+0x17c` | mutable display line A / title line | Strong offset; set by `0x005b8670`. |
| `+0x1fc` | secondary/status display line, generated `m_nameLineB` / `m_displayLineB` | Strong offset; copied by `0x005b85d0`, set by `0x005b86a0`. |
| `+0x27c` | nation id | Strong; initialized to `-1` as low byte of word at `+0x27c`. |
| `+0x27d` | adjacent byte in the same constructor word | Unresolved; do not force a final name. |
| `+0x27e` | spirit/totem id | Strong; normal getter at `0x005b8630`, raw signed getter at `0x005b86d0`. |
| `+0x27f` | selected status icon id | Strong; dedicated setter [UID:0002LP]. |
| `+0x280` | layout/status/class byte updated by status payload | Medium; role from payload/paint docs, final name unresolved. |
| `+0x281` | percent/stat byte A | Strong accessor offset, weak final semantic name. |
| `+0x282` | percent/stat byte B | Strong accessor offset, weak final semantic name. |
| `+0x283` | percent/stat byte C | Strong accessor offset, weak final semantic name. |
| `+0x284` | inventory slot count / max selectable item-slot byte, default `52` | Strong behavior from constructor and many inventory/input consumers. |
| `+0x288` | packet-updated display/value dword paired with `+0x290` | Medium; source name unresolved. |
| `+0x28c` | dword display value A | Strong accessor offset, weak final semantic name. |
| `+0x290` | packet-updated display/value dword paired with `+0x288` | Medium; source name unresolved. |
| `+0x294` | dword display value B | Strong accessor offset, weak final semantic name. |
| `+0x298` | dword display value C, missing from generated `CharacterSummaryRecord` | Strong offset; no inbound refs in local PE scan. |
| `+0x29c` | packet-updated display/value dword paired with `+0x298` | Medium; source name unresolved. |
| `+0x2a0` | cleared summary-tail dword | Low/medium; no safe final name. |
| `+0x2a4` | cleared summary-tail dword | Low/medium; no safe final name. |

Source-level naming direction:

- Keep `UserStatusPaneSummaryFields` as a descriptive layout/type doc name.
- Do not create a real `CharacterSummaryRecord` C++ type.
- If a temporary rewrite helper is useful, model it as comments or private `UserStatusPane` field names, not a separate allocated object.

## Heuristic / inference reanalysis and validation

Generated pseudo-class status:

- Evidence checked: generated `class_CharacterSummaryRecord.cpp`, target class/file pages, local PE disassembly, xref scans, constructor field writes, `g_activeUserStatusPane` docs, and UserStatusPane source family docs.
- Decision: confirmed generated pseudo-class. The generated file has method bodies only, no constructor, no destructor, no vtable, no allocation, and omits `0x005b8660`.
- Rejected alternative: standalone original `CharacterSummaryRecord` class. Rejected because every call uses the `UserStatusPane` singleton as receiver and every offset is a full `UserStatusPane` object offset.

Accessor island [UID:0001NN]:

- Evidence checked: local PE exact bytes for each accessor, internal gaps, rel32 callers, generated class output, [UID:0001NN] doc, [UID:0001NM] aggregate doc.
- Decision: [UID:0001NN] remains the exact source-bearing accessor island. It is reconstructable and correctly routes to [UID:0000FS].
- Support update needed: coverage wording still says file page `0000P2` remains below confidence gate; that is stale because [UID:0000P2] is now `88/85`.

Missing sibling getter `0x005b8660`:

- Evidence checked: local PE disassembly, rel32 scan, generated output.
- Decision: it is a real seven-byte getter for dword `+0x298` but has no local direct callers or absolute refs. It should be documented as omitted by generated `CharacterSummaryRecord`, not as a reason to create the pseudo-class.
- Best name: `UserStatusPane::GetDisplayValueC()` or descriptive `GetSummaryDisplayValueC()` until final field names are known.

Adjacent raw signed getter `0x005b86d0`:

- Evidence checked: bytes/gaps around `0x005b86ca-0x005b86e0`, local rel32/absolute xref scans, [UID:0002LP] doc.
- Decision: not part of [UID:0001NN] and not part of `CharacterSummaryRecord`. Best inference is a retained/no-route signed `+0x27e` getter. It can be future-split as an exact tiny by-memory child if the supervisor wants full coverage of that raw helper.

`g_activeUserStatusPane`:

- Evidence checked: global docs, memory storage doc, local absolute refs, constructor/cleanup writes, representative accessor callers.
- Decision: canonical global name and owner route are strong. Generated aliases such as `DAT_0069ae0c`, `dword_69AE0C`, `g_pLocalPlayer`, or `g_pEffectObjImageLib` are alias pollution when they refer to `0x0069ae0c`.

Owner/file routing:

- Evidence checked: [UID:0000FS] class page, [UID:0000P2] file page, proposed source tree, auto-generated coverage reports, constructor caller at `0x004f837a`, global lifecycle docs.
- Decision: underlying code routes through [UID:0000FS] `UserStatusPane` to [UID:0000P2] `UserStatusPane.cpp`. The target pseudo-class itself remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank-emitter.

Task text item [UID:00021I] / "active submitter child page":

- Evidence checked: `rg UID:00021I`, [UID:00021I] target page, `ClanDepMoneyInputDialog` docs, previous B004 `00002A` report.
- Decision: this is stale/cross-assignment text. [UID:00021I] is `0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers`, a Clan packet helper cluster unrelated to `CharacterSummaryRecord` or `UserStatusPane`. There is no CharacterSummaryRecord "active submitter" child page. Do not add any [UID:00021I] cross-reference to this target.

Final C++:

- Evidence checked: active code gate, target metadata, emitter route, generated output, and source-placement evidence.
- Decision: no target C++. The target fails the source-emission preconditions because it is intentionally `RECONSTRUCTABLE:FALSE`, has blank emitters, and has no defensible standalone source entity. The correct source-level inference belongs to `UserStatusPane` / [UID:0001NN].

## Ranked source/ownership analysis

### 1. Generated pseudo-class alias over UserStatusPane accessors

Evidence for:

- Generated file `class_CharacterSummaryRecord.cpp` consists only of scoped installs at `0x005b85b0` through `0x005b86a0`.
- It omits the real sibling getter at `0x005b8660`.
- Local callers pass `g_activeUserStatusPane` directly as `ecx`.
- Constructor `0x005b83b0` initializes the exact fields used by the accessors.
- [UID:0001WF] already models the layout slice under `UserStatusPane`.

Evidence against:

- None material. This is the best explanation.

Decision: accept.

### 2. Original `UserStatusPane` methods or private layout helper

Evidence for:

- Source code must contain the behavior represented by [UID:0001NN].
- The exact code island is reconstructable and already owner/emitter-routed through [UID:0000FS].
- A private layout/helper name such as `UserStatusPaneSummaryFields` is useful for field documentation.

Evidence against:

- This does not create a standalone `CharacterSummaryRecord` class. It only explains where the generated bodies should move.

Decision: accept as source-level inference for the owning class, not as target metadata for [UID:00001N].

### 3. Standalone `CharacterSummaryRecord` class or source file

Evidence for:

- Generated Wave3 split chose that name and emitted method syntax.

Evidence against:

- No constructor, destructor, vtable, allocation, global, RTTI/COL, or embedded subobject receiver evidence.
- Callers use `g_activeUserStatusPane`, not a record pointer or `UserStatusPane + offset`.
- The generated pseudo-class is incomplete because it misses `0x005b8660`.
- The by-file page already has `PROPOSED_RECONSTRUCTION_PATH:"NONE"`.

Decision: reject.

### 4. Clan retained raw helper mirror [UID:00021I]

Evidence for:

- Present only in the assignment text.

Evidence against:

- UID, address, file, and behavior are Clan deposit-money packet helpers, unrelated to this address family.

Decision: reject as stale assignment carryover.

## Source-level inference, not target C++

Do not insert this into [UID:00001N]. This is the best-supported shape for the owning `UserStatusPane` accessor island if [UID:0001NN] or the class page later receives first-draft method C++:

```cpp
void UserStatusPane::CopyNameLineA(wchar_t *destination, size_t capacity) const
{
    wcscpy_s(destination, capacity, m_nameLine);
}

void UserStatusPane::CopyNameLineB(wchar_t *destination, size_t capacity) const
{
    wcscpy_s(destination, capacity, m_secondaryLine);
}

unsigned char UserStatusPane::GetPercentStatA() const { return m_percentStatA; }
unsigned char UserStatusPane::GetPercentStatB() const { return m_percentStatB; }
unsigned char UserStatusPane::GetPercentStatC() const { return m_percentStatC; }
signed char UserStatusPane::GetNationId() const { return m_nationId; }
signed char UserStatusPane::GetSpiritId() const { return m_spiritId; }
unsigned int UserStatusPane::GetDisplayValueA() const { return m_displayValueA; }
unsigned int UserStatusPane::GetDisplayValueB() const { return m_displayValueB; }
unsigned int UserStatusPane::GetDisplayValueC() const { return m_displayValueC; }

void UserStatusPane::SetDisplayLineA(const wchar_t *text)
{
    wcscpy_s(m_displayLineA, 64, text);
    InvalidateSummaryText();
}

void UserStatusPane::SetDisplayLineB(const wchar_t *text)
{
    wcscpy_s(m_displayLineB, 64, text);
    InvalidateSummaryText();
}
```

Caveats:

- `m_nameLine`, `m_secondaryLine`, `m_displayLineA`, and `InvalidateSummaryText` are descriptive placeholders.
- The exact wide-copy helper name should follow the project's existing spelling for `0x005cd657`.
- The `InvalidateSummaryText` call represents the vtable slot `+0x20` call with `this+0x44`; final source may spell that as a pane invalidation/dirty-region method.
- This source-level inference belongs to `UserStatusPane`, not to `CharacterSummaryRecord`.

## Exact no-code proof for [UID:00001N]

Formal target C++ must remain blank because:

1. The target is intentionally `RECONSTRUCTABLE:FALSE`.
2. It has no emitter UID.
3. It has no standalone class lifetime evidence: no constructor, no destructor, no scalar deleting destructor, no vtable, no allocation site, no global instance, no RTTI/COL block, and no embedded-subobject receiver setup.
4. Local PE call-site checks show `ecx` is the active `UserStatusPane` pointer from `0x0069ae0c`, not a `CharacterSummaryRecord *`.
5. The generated pseudo-class omits real code at `0x005b8660`, so it is not even a complete source slice.
6. The real source-bearing item is [UID:0001NN], and its owner/emitter path already routes to [UID:0000FS] / [UID:0000P2].

Therefore, adding a `class CharacterSummaryRecord` declaration or methods to the target would duplicate/misroute `UserStatusPane` source and would make the generated tree less accurate.

## Recommended target doc changes

For `by-class/CharacterSummaryRecord.md`:

- Change score to `COMPLETION:88`, `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.
- Add local PE recheck details:
  - exact PE identity and MCP-unavailable fallback;
  - direct `UserStatusPane` constructor writes at `0x005b83fa` / `0x005b8401`;
  - representative call sites loading `ecx` from `0x0069ae0c`;
  - missing sibling getter `0x005b8660`;
  - adjacent no-xref signed getter `0x005b86d0`;
  - no standalone class/vtable/allocation evidence.
- Replace any wording that sounds like `CharacterSummaryRecord` might later become a migrated class with narrower wording: only if future evidence finds an independently allocated object, which current PE evidence actively rejects.
- Add the [UID:00021I] stale-assignment note only if useful in a "rejected alternatives" section; do not cross-link it as support evidence.

## Recommended support-doc changes

For `by-file/CharacterSummaryRecord.md`:

- Optional score update to `COMPLETION:88`, `CONFIDENCE:92` if the same local PE evidence is incorporated.
- Keep `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE`.
- Add the current local PE no-standalone proof and the missing `0x005b8660` / adjacent `0x005b86d0` findings.

For `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md`:

- Keep metadata `85/90`, owner/emitter [UID:0000FS], reconstructable true.
- Update stale wording that says file page `0000P2` remains below confidence gate; [UID:0000P2] is now `88/85`.
- Add B004 current local PE recheck:
  - exact byte bodies for each accessor are still stable;
  - `0x005b8660` has no local rel32/absolute refs but is a real getter;
  - `0x005b86d0-0x005b86d8` is a separate no-xref signed `+0x27e` getter outside the exact range;
  - representative caller setup uses `g_activeUserStatusPane`.

For `by-type/by-struct/UserStatusPaneSummaryFields.md`:

- No score change required.
- Optional detail: add the current call-site/global receiver evidence and keep final names provisional for `+0x27d`, `+0x288`, `+0x290`, `+0x29c`, `+0x2a0`, and `+0x2a4`.

For `by-class/UserStatusPane.md`:

- No score change required.
- Optional cleanup: replace old "95/95 code-emission gate" wording with current gate language and a target-specific reason final class C++ remains blank: the broad class and large child methods still need first-draft integration and field names, while the generated `CharacterSummaryRecord` slice is not a separate class.

For `by-file/UserStatusPane.md`:

- No score change required.
- Optional cleanup: ensure it says the generated `CharacterSummaryRecord` class and file are reviewed aliases folded into `UserStatusPane.cpp`, not candidate companion source files.

For `by-global/g_activeUserStatusPane.md` and `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`:

- No required change. They already document canonical name, 67 xrefs, lifecycle writers, and alias pollution.

## Exact coverage text

Class coverage replacement row:

```text
- [UID:00001N][CharacterSummaryRecord](by-class/CharacterSummaryRecord.md) : not_reconstructable : 88% : very strong : B004 source-routing recheck keeps this as a generated pseudo-class over UserStatusPane summary accessors; local PE disassembly confirms the methods are direct UserStatusPane accessors over g_activeUserStatusPane, includes missing sibling getter 0x005b8660 and adjacent no-xref signed getter 0x005b86d0 as UserStatusPane evidence, finds no standalone constructor/vtable/allocation/type route, and routes real code through [UID:0001NN] to [UID:0000FS]/[UID:0000P2]; target formal C++ remains blank by standalone-class no-code proof.
```

File coverage replacement row, only if `by-file/CharacterSummaryRecord.md` is updated:

```text
- [UID:0000I4][CharacterSummaryRecord](by-file/CharacterSummaryRecord.md) : not_reconstructable : 88% : very strong : Negative file-placement decision: generated record accessors are assigned to UserStatusPane with current local PE method/field/global evidence, missing 0x005b8660 generated sibling, adjacent 0x005b86d0 no-route signed getter caveat, g_activeUserStatusPane receiver proof, and no standalone source-root evidence.
```

Pending `by-memory/-coverage-report.md` replacement row, only if [UID:0001NN] wording is updated:

```text
    - [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md) 0x005b85b0-0x005b86ca | method cluster | UserStatusPaneSummaryAccessors : reconstructable : 85% : strong : Confidence 90 after current B004 source-routing recheck: modeled functions remain two 0x1c text-copy helpers, eight seven-byte byte/dword getters including the generated-omitted 0x005b8660 +0x298 dword getter, and two 0x2a setters mapping text copies at +0xfc/+0x1fc, byte getters at +0x281/+0x282/+0x283/+0x27c/+0x27e, dword getters at +0x28c/+0x294/+0x298, and setters at +0x17c/+0x1fc followed by vtable-slot +0x20 invalidation with this+0x44; local PE caller checks show g_activeUserStatusPane as receiver, all internal gaps are 0xcc, adjacent raw 0x005b86d0-0x005b86d8 remains a separate no-xref signed +0x27e getter caveat, generated CharacterSummaryRecord is rejected as standalone ownership, and the direct class parent [UID:0000FS] clears 88/88 with file route [UID:0000P2] now at 88/85.
```

No other `by-memory/-coverage-report.md` row is required for this assignment. The [UID:00021I] Clan row is unrelated and should not be changed.

## Validation commands needed after implementation

Run from `source-3/project-documentation` for every touched by-* file:

> Executable block R001 was removed from this report and preserved verbatim in [00001N-CharacterSummaryRecord-source-routing-removed.md](00001N-CharacterSummaryRecord-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Only run validators for support docs actually touched in the implementation callback. No validation was run for this report-only pass.

## IDA rename/type/comment recommendations

Target-level:

- Do not create or rename a real `CharacterSummaryRecord` class in IDA.
- Use `CharacterSummaryRecord` only as an alias/comment in generated-output notes if needed.

Accessor island:

- `0x005b85b0`: `UserStatusPane::CopyNameLineA` / `CopyPrimaryNameLine`.
- `0x005b85d0`: `UserStatusPane::CopyNameLineB` / `CopySecondaryLine`.
- `0x005b85f0`: `UserStatusPane::GetPercentStatA`.
- `0x005b8600`: `UserStatusPane::GetPercentStatB`.
- `0x005b8610`: `UserStatusPane::GetPercentStatC`.
- `0x005b8620`: `UserStatusPane::GetNationId`.
- `0x005b8630`: `UserStatusPane::GetSpiritId`.
- `0x005b8640`: `UserStatusPane::GetDisplayValueA`.
- `0x005b8650`: `UserStatusPane::GetDisplayValueB`.
- `0x005b8660`: `UserStatusPane::GetDisplayValueC`.
- `0x005b8670`: `UserStatusPane::SetDisplayLineA`.
- `0x005b86a0`: `UserStatusPane::SetDisplayLineB`.
- `0x005b86d0`: comment as no-xref raw signed `UserStatusPane` spirit/totem getter, `movsx [this+0x27e]`, not yet promoted to a by-memory child.
- `0x005b86e0`: `UserStatusPane::SetStatusIconId`.

Global/type:

- Keep `0x0069ae0c` as `g_activeUserStatusPane`.
- Keep generated aliases `DAT_0069ae0c`, `dword_69AE0C`, `g_pLocalPlayer`, and `g_pEffectObjImageLib` rejected for this address unless a future pass proves another storage.
- Keep field names in `UserStatusPaneSummaryFields` descriptive/provisional until the status payload and paint methods receive final source-quality names.

## Remaining issues and impact

- Final `UserStatusPane` source field names remain provisional. Impact: cap target confidence below 95 and avoid final source declarations in [UID:0001NN] until accepted by a broader `UserStatusPane` source-quality pass.
- `0x005b86d0-0x005b86d8` remains a no-xref raw signed getter outside [UID:0001NN]. Impact: support docs should keep it as a caveat or future exact child; it does not affect the no-standalone decision for `CharacterSummaryRecord`.
- [UID:0001NN] currently meets the active reconstructable/emitter gate, but formal C++ there should be implemented only after a supervisor callback explicitly scopes the source-accessor island. Impact: [UID:00001N] still stays blank because it is not the emitting source item.
- [UID:00021I] and "active submitter" wording are unrelated stale assignment text. Impact: no CharacterSummaryRecord support doc should mention Clan deposit helpers except possibly as a rejected prompt artifact in this report.

## Changed files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/00001N-CharacterSummaryRecord-source-routing.md`

Modified:

- None.

Moved/archived:

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00001N-CharacterSummaryRecord-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"00001N"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00001N-CharacterSummaryRecord-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00001N-CharacterSummaryRecord-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00001N"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
