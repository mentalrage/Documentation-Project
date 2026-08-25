** TARGET-REPORT-UID:00019L **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00019L EnsureLoginDialogPane Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](../../../../../by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) as a source-authored private login helper, `static void EnsureLoginDialogPane()`, in [UID:0000KX][LoginDialogPane](../../../../../by-file/LoginDialogPane.md) / `login/LoginDialogPane.cpp`.
- Final disposition: keep `CANONICAL_OWNER:0000KX`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000KX`; raise the target from `84/90` to `88/90`; populate first-draft C++ on the by-memory target. The current `95/95 final-source gate` rationale is stale under the active combined-score/emitter rule.
- Support-doc direction: reframe [UID:0000PL][EnsureLoginDialogPane_4F8B30](../../../../../by-global/EnsureLoginDialogPane_4F8B30.md) as a recovered-symbol/alias page for the exact memory target, not a separate code-emitting helper body. Source-facing spelling should be `EnsureLoginDialogPane`; `_4F8B30` is a recovery suffix.
- Confidence: high for behavior, signature, source family, and C++ readiness; not final-audit level because live IDA MCP was unavailable in this session and original PDB/source spelling is not directly proven.

## Target

- Target UID: `00019L`
- Target path: `source-3/project-documentation/by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00019L-EnsureLoginDialogPane-source-quality.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000KX`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KX`, blank C++.
- Generated route checked: `auto-generated/-ag-memory-coverage.md` routes UID `00019L` to `auto-generated/NexusTK/login/LoginDialogPane.cpp`; the file parent [UID:0000KX] is currently `88/86` with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`.

## Executive Recommendation

The best source-facing shape is:

```cpp
static void EnsureLoginDialogPane()
{
    if (g_pLoginDialogPane == NULL)
        new LoginDialogPane;
}
```

This is not a `ForcedInformMessageDialog` method. The two current callers are forced-inform teardown paths, but the function's only meaningful state is the `g_pLoginDialogPane` duplicate-open guard, project-wide `operator new`, and `LoginDialogPane` constructor. The constructor publishes the singleton; the helper does not store the returned pointer. The allocation immediate `620` is `0x26c` (Verified with `int_convert.py`) and should be documented as the compiler-emitted `sizeof(LoginDialogPane)` allocation, not as a handwritten magic constant or local allocator wrapper call.

## Supervisor Active Recheck

- Assignment received as a report-only B-agent task for [UID:00019L].
- No target/support by-* docs were edited.
- `by-memory/-coverage-report.md` was not edited; exact replacement row text is included below.
- Existing B reports were searched under Agent-B research folders; no prior B-agent report for `00019L`, `EnsureLoginDialogPane`, `0x004f8b30`, or `4F8B30` was found.
- Live IDA MCP probe to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`; recommendations therefore rely on existing IDA-backed docs plus prewave exported binary facts. This should cap confidence below final audit, but it does not block first-draft C++ because the target already has strong dated IDA evidence and the prewave export independently matches it.

## Inference Research Guidance Check

`by-structure.md` says source-quality questions are ordinary documentation work even after `85/85`, and current C++ entry requires `RECONSTRUCTABLE:TRUE`, a nonblank emitter route that reaches generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`. This target satisfies the route and source-shape requirements after the stale final-gate blocker is resolved.

`inference_research.md` cautions that address adjacency and consumers are weaker than data flow, constructors, xrefs, and lifecycle writes. Applied here: the forced-inform callers are consumer evidence only; the allocator/constructor/singleton lifecycle evidence is stronger and points to `LoginDialogPane.cpp`.

`proposed-source-tree.md` places `ForcedInformMessageDialog.cpp` and `LoginDialogPane.cpp` in the login family, states that forced-inform teardown can reopen the login dialog through `EnsureLoginDialogPane_4F8B30`, and lists this helper with `SendLoginRequest` as nearby login helper candidates. That supports login-family placement while rejecting forced-inform ownership.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best direction | Rejected alternatives / impact |
| --- | --- | --- | --- |
| Source-facing helper name | Target name, by-global alias, old report text, prewave export name `sub_4F8B30`, behavior as singleton ensure helper | Use `EnsureLoginDialogPane()` as source-facing descriptive name. It is already the stable documentation name minus address suffix and matches the lazy singleton behavior. | Reject `EnsureLoginDialogPane_4F8B30` as source spelling; suffix is recovery provenance. Reject `OpenLoginDialogPane` or `ShowLoginDialogPane` because this helper only allocates/constructs and relies on constructor side effects. |
| Signature | Prewave export: Ghidra `undefined __stdcall FUN_004f8b30(void)`, IDA `void()`. Target doc: no params, singleton side effects only. | `static void EnsureLoginDialogPane()` in `LoginDialogPane.cpp`. Calling convention is compiler/backend detail for a file-local free helper. | Reject member method shape; no `this`, no explicit arguments, no vtable/class dispatch. |
| Source owner / placement | Target owner `0000KX`; LoginDialogPane file `88/86`; LoginDialogPane class `86/88`; constructor caller from helper at `0x004f8b79`; proposed source tree login family. | Keep direct owner/emitter as [UID:0000KX] `LoginDialogPane` because this is a file-level helper, not a class virtual/method body. | Reject [UID:0000JJ] forced-inform ownership: it has only teardown caller refs. Reject mixed aggregate [UID:00019I] as owner: it is a non-emitting index. |
| Global page `EnsureLoginDialogPane_4F8B30` | by-global page is reconstructable/emitting and covers the same exact function as by-memory target; generated reports currently list both UID `0000PL` and `00019L` as emitters to `LoginDialogPane.cpp`. | Reframe by-global as recovered alias/name index for the exact memory page and let [UID:00019L] carry the formal C++ body to avoid duplicate helper emission. | Keeping both pages as code emitters risks duplicate definitions when the memory target receives C++. If supervisor policy prefers by-global to own code, then by-memory should not also emit the same body; one source-bearing page should be selected. |
| Allocation helper spelling | OperatorNewWrapper doc [UID:000196] says `0x004f4aa0` is the MemoryMan-backed global `operator new`, with broad fanout and `GetMemoryMan -> AllocateBufferMemory` callees. | In source C++, write `new LoginDialogPane;`. Document `0x004f4aa0(620)` as compiler output for global `operator new(sizeof(LoginDialogPane))`. | Reject final C++ using `sub_4F4AA0`, `OperatorNewWrapper`, or a feature-local allocator name. Those are reverse/generated names, not likely original source. |
| Allocation size `620` | Target doc, by-global, OperatorNewWrapper, LoginDialogPane file/class/core docs; `int_convert.py` confirms `620 == 0x26c`. | Treat as `sizeof(LoginDialogPane)` allocation. The first-draft source should not hardcode `620`. | A magic-size placement-new draft preserves decompiler shape but is worse mid-2000s source style for this small helper. Keep the null-allocation behavior documented rather than encoding reverse scaffolding in final C++. |
| Singleton guard / constructor side effects | `g_pLoginDialogPane` global and exact storage docs list helper read at `0x004f8b53`, constructor writes at `0x004fa801`/`0x004fa808`, cleanup/destructor clears. | The helper checks `g_pLoginDialogPane == NULL`; `LoginDialogPane::LoginDialogPane` publishes or clears the singleton. | Reject `g_pLoginDialogPane = new LoginDialogPane;`: helper has no global store; assigning in source would add side effects not present in the function. |
| Forced-inform caller context | ForcedInform core/destructor docs list calls at `0x005880db` and `0x0058ac52`; scalar destructor condition is EPF mode, accepted flag, and `g_pMainUiGraph` present. | Document as "accepted forced-inform teardown restoration path calls login helper." | Caller context does not change ownership; forced-inform source should continue to call the helper, not own or inline its construction logic. |
| Login/account dialog split | LoginDialogPane file now covers login/account family but notes smaller account-dialog split remains partly unresolved. | The split question no longer blocks this exact helper. The helper only creates `LoginDialogPane` and belongs in `login/LoginDialogPane.cpp`; account dialog helpers can remain in adjacent files. | Do not keep target C++ blank merely because `NewUserDialogPane` / `ChangePasswordDialogPane` file grouping is still being refined. |
| Compiler/generated/raw names | Current unresolved entries include `sub_4F8B30`, `FUN_004f8b30`, `sub_4F4AA0`, `sub_4FA7A0`, `dword_69B484`/`unk_69B484`. | Replace in target prose with `EnsureLoginDialogPane`, global `operator new`, `LoginDialogPane::LoginDialogPane`, and `g_pLoginDialogPane`; retain raw labels only as evidence aliases. | Leaving raw names in the reconstruction notes would preserve stale source-quality blockers after they have enough contextual resolution. |
| Final C++ readiness | Target is `TRUE`, emitter `0000KX` reaches `auto-generated/NexusTK/login/LoginDialogPane.cpp`, proposed `88/90` average is 89, and the code is one exact function range. | Populate first-draft C++ on [UID:00019L] unless supervisor chooses to make the by-global page the sole source-bearing page. | Hard no-code is no longer justified. Remaining live-IDA unavailability only prevents final-audit confidence, not first-draft source entry. |

## Evidence Standards Used

- Direct existing IDA documentation: target page, by-global symbol page, LoginDialogPane class/core/file pages, ForcedInform file/class/core/destructor pages, `g_pLoginDialogPane` pages, OperatorNewWrapper/MemoryMan pages.
- Cached/exported binary facts: prewave JSON for `0x004f8b30`, `0x004fa7a0`, `0x004f4aa0`, `0x00588080`, and `0x0058abf0`.
- Generated coverage state: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-global-coverage.md`, current `by-memory/-coverage-report.md` row.
- Numeric checks: `int_convert.py` verified `620 == 0x26c`, `0x5d == 93`, and `0xc2 == 194`.
- Negative evidence: live IDA unavailable; direct PE byte read from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` was denied by the OS despite the file existing. Existing docs contain prior byte/padding checks, so implementation should only need a fresh live/raw recheck if the supervisor wants final-audit confidence.

## IDA / Binary Facts

- Function/range facts: prewave export records `0x004f8b30`, size `93` / `0x5d`, non-thunk, no-return false, two callers, two callees. Target docs record exact range `0x004f8b30-0x004f8b8d` and padding `0x004f8b8d-0x004f8b90` before [UID:00019M].
- Decompile facts: Ghidra and IDA both reduce the body to `if (DAT_0069b484 == 0)` / `if (!dword_69B484)`, allocate `0x26c` / `620`, null-check the allocation result, and call the `LoginDialogPane` constructor.
- Caller facts: prewave export and current docs list two caller functions: non-deleting `ForcedInformMessageDialog` destructor at `0x00588080` with call site `0x005880db`, and scalar deleting destructor at `0x0058abf0` with call site `0x0058ac52`.
- Callee facts: prewave export and current docs list only `0x004f4aa0` global operator-new wrapper and `0x004fa7a0` `LoginDialogPane::LoginDialogPane`.
- Global/lifecycle facts: `g_pLoginDialogPane` exact storage at `0x0069b484-0x0069b488` is read by this helper at `0x004f8b53`; constructor publishes/fallback-clears at `0x004fa801`/`0x004fa808`; cleanup/destructor paths clear later.
- Constructor facts: LoginDialogPane core docs say the constructor builds the `DLGLOGIN.EPF` dialog, stores the singleton, writes vtables, initializes controls, and attaches through main UI layer/screen state. That supports relying on constructor side effects rather than assigning in the helper.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f8b30-0x004f8b8d` | [UID:00019L](../../../../../by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) | Exact login-dialog ensure helper | TRUE | [UID:0000KX] | Recommend `88/90` | Add first-draft C++; keep owner/emitter. |
| `0x004f8b8d-0x004f8b90` | same page / padding note | Alignment before `00019M` | FALSE as behavior | none | unchanged | Keep as padding note only. |
| `EnsureLoginDialogPane_4F8B30` | [UID:0000PL](../../../../../by-global/EnsureLoginDialogPane_4F8B30.md) | Recovered global-function symbol/alias | Recommend non-emitting alias or no duplicate code | [UID:0000KX] or [UID:00019L] as index target | Recommend `88/90` if reframed | Remove stale no-code rationale and address-suffix source spelling. |

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x004f8b53` | read `g_pLoginDialogPane` / `dword_69B484` | Duplicate-open guard. |
| `0x004f4aa0` | callee | MemoryMan-backed global `operator new`; project-wide allocator plumbing. |
| `0x004fa7a0` | callee | `LoginDialogPane::LoginDialogPane`; publishes singleton and creates login UI. |
| `0x005880db` | caller from `ForcedInformMessageDialog::~ForcedInformMessageDialog` | Accepted forced-inform teardown can restore login. |
| `0x0058ac52` | caller from scalar deleting destructor | Same restoration path in deleting destructor wrapper. |
| `0x004f8b8d-0x004f8b90` | padding | Boundary before `ComputeMenuItemRect`; no helper behavior. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target page already records exact bounds, singleton guard, allocation-null guard, constructor call, two forced-inform callers, callee set, and LoginDialogPane ownership.
  - [UID:0000KX] `LoginDialogPane` is `88/86`, has `NexusTK/login/`, and lists this helper as a login-dialog source-family helper.
  - [UID:00007F] `LoginDialogPane` is `86/88` and records constructor reachability from this helper.
  - [UID:0000RE] / [UID:0002XI] `g_pLoginDialogPane` document the exact singleton lifecycle and this helper's read.
  - [UID:0000JJ], [UID:00005E], [UID:0001J7], and [UID:0001JA] record forced-inform as caller/consumer only.
  - [UID:000196] and [UID:0000T8] resolve `sub_4F4AA0` to MemoryMan-backed global `operator new`.
- Existing docs that are stale or incomplete:
  - Target and by-global pages still cite old `95/95 final-source gate` / final helper spelling / account-dialog split as C++ blockers. The current gate is combined-score + emitter route, and the source spelling and placement have enough evidence for a first draft.
  - The by-global page currently presents `EnsureLoginDialogPane_4F8B30` as source-facing. It should separate recovered alias from source-facing helper name.
  - Project unresolved reports still list raw names `sub_4F8B30`, `FUN_004f8b30`, `sub_4F4AA0`, `sub_4FA7A0`, and `unk_69B484`; target/support text should use canonical names first and raw labels only as evidence aliases.

## Ranked Ownership Analysis

### 1. [UID:0000KX] `LoginDialogPane` file

- Evidence for: function reads `g_pLoginDialogPane`; allocates and constructs `LoginDialogPane`; constructor writes the singleton; file parent is `88/86`; generated route lands in `auto-generated/NexusTK/login/LoginDialogPane.cpp`; proposed source tree includes this as a login helper candidate.
- Evidence against: current direct callers are in forced-inform destructors, not login menu activation.
- Decision: accept. Caller evidence is a consumer/restoration path, while callee/lifecycle evidence identifies the source helper's owner.

### 2. [UID:00007F] `LoginDialogPane` class

- Evidence for: target constructs the class and class page now clears `86/88`.
- Evidence against: helper has no `this`, no member signature, no vtable relationship, no class method dispatch. It is a file-local/free helper around singleton creation.
- Decision: use class as context only. Direct owner should remain file [UID:0000KX].

### 3. [UID:0000JJ] / [UID:00005E] `ForcedInformMessageDialog`

- Evidence for: only current direct callers are its non-deleting and scalar deleting destructors.
- Evidence against: no forced-inform fields/resources are touched by the helper; forced-inform docs themselves say the callee stays owned by LoginDialogPane support; the destructor condition simply invokes login restoration after acceptance.
- Decision: reject as owner. Document as caller context only.

### 4. [UID:00019I] `MainMenuLoginAndAccountDialogs` aggregate

- Evidence for: physical address neighborhood contains main-menu/login/account helper range.
- Evidence against: aggregate is `RECONSTRUCTABLE:FALSE`, mixed-owner, and intentionally non-emitting; exact children carry source ownership.
- Decision: reject as owner. Keep as index/cross-reference only.

## Negative Evidence Summary

- No direct parameter, return, or object state supports a class method signature.
- No prompt strings, packet writes, resource refs, accepted flag reads, or `g_pForcedInformMessageDialog` accesses exist in the helper; forced-inform is only a caller.
- No helper-local store to `g_pLoginDialogPane` exists; constructor side effects own singleton publication.
- No feature-local allocator is supported; `0x004f4aa0` has broad project-wide fanout and MemoryMan ownership.
- Account-dialog split uncertainty affects broader `LoginDialogPane` file planning, but not this exact login singleton helper.

## Recommended Target Changes

Apply these only after supervisor implementation callback.

### Metadata

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Formal C++ Block

```cpp
static void EnsureLoginDialogPane()
{
    if (g_pLoginDialogPane == NULL)
        new LoginDialogPane;
}
```

### Exact Target Prose Replacements / Additions

Replace the stale status bullets:

```text
- Rebuild handling: `source-authored`; recreate as a private/static login-source helper in `login/LoginDialogPane.cpp`, not as forced-inform dialog code.
- Source-facing name/signature: `static void EnsureLoginDialogPane()`. The recovered `EnsureLoginDialogPane_4F8B30`, `sub_4F8B30`, and `FUN_004f8b30` names are evidence aliases, not final source spelling.
- Corrected source module and emitter: [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md). The file page is `88/86`, the target is recommended `88/90`, and the route surfaces to `auto-generated/NexusTK/login/LoginDialogPane.cpp`.
- First-draft C++ is now ready under the active combined-score/emitter gate. The old `95/95 final-source gate` note is superseded by the current rule in `by-structure.md`.
```

Add/replace behavior note:

```text
Source form should be `if (g_pLoginDialogPane == NULL) new LoginDialogPane;`. The compiled body calls the MemoryMan-backed global `operator new` wrapper at `0x004f4aa0` with `620` bytes (`0x26c`, Verified with `int_convert.py`) and null-checks the result before calling `LoginDialogPane::LoginDialogPane` at `0x004fa7a0`. The helper itself does not store the returned pointer; the constructor publishes or clears `g_pLoginDialogPane`.
```

Add caller/source-placement note:

```text
The two current direct callers are forced-inform teardown paths (`0x005880db` and `0x0058ac52`) that restore the login dialog after an accepted EPF forced-inform flow. Those callers are consumer context only. Ownership stays with `LoginDialogPane.cpp` because the helper touches only the login-dialog singleton, global allocation, and the login-dialog constructor.
```

Replace reconstruction notes:

```text
Recreate this as a private/static helper near the `LoginDialogPane` constructor and login singleton declarations. Use source-level `new LoginDialogPane;`, not raw `sub_4F4AA0(620)` or a feature-local allocator name. The account-dialog source split is still a broader file-planning caveat, but it no longer blocks first-draft C++ for this exact helper.
```

## Recommended Support-Doc Updates

### [UID:0000PL] `by-global/EnsureLoginDialogPane_4F8B30.md`

Recommended metadata if the supervisor accepts the no-duplicate-emission model:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended title/status replacement:

```text
# EnsureLoginDialogPane

## Status

- Source-facing helper name: `EnsureLoginDialogPane`.
- Recovered/global alias: `EnsureLoginDialogPane_4F8B30`.
- Exact source-bearing range: [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md).
- Likely owner source: [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) / `login/LoginDialogPane.cpp`.
- Rebuild handling for this by-global page: non-emitting symbol/index page if [UID:00019L] carries the formal helper body, to avoid duplicate `EnsureLoginDialogPane()` emission.
```

Recommended role replacement:

```text
`EnsureLoginDialogPane()` lazily creates a [UID:00007F][LoginDialogPane](by-class/LoginDialogPane.md) when [UID:0000RE][g_pLoginDialogPane](by-global/g_pLoginDialogPane.md) is null. The compiled body calls the project-wide MemoryMan-backed global `operator new` wrapper at `0x004f4aa0` with `620` bytes (`0x26c`, Verified with `int_convert.py`) and then calls `LoginDialogPane::LoginDialogPane` at `0x004fa7a0` if allocation returns non-null. The constructor publishes the singleton.
```

If the supervisor chooses to keep [UID:0000PL] as the sole code-bearing symbol page instead, do not also enter the same C++ body on [UID:00019L]. One exact helper body should emit once.

### [UID:0000KX] `by-file/LoginDialogPane.md`

Replace the proposed contents row for the helper:

```markdown
| `EnsureLoginDialogPane` | `0x004f8b30-0x004f8b8d` | private helper in `login/LoginDialogPane.cpp` | Ensures the login dialog singleton exists by checking `g_pLoginDialogPane` and constructing `LoginDialogPane` through source-level `new LoginDialogPane;`; recovered alias `EnsureLoginDialogPane_4F8B30`. |
```

Add boundary/source-quality note:

```text
[UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) is ready for first-draft helper C++ under the current combined-score/emitter gate. Its old final-code blocker was the address-suffixed recovered name and broader account-dialog source split; current evidence supports `static void EnsureLoginDialogPane()` as a file-local login helper, while the account-dialog split remains a broader file-planning issue.
```

### [UID:0000JJ] `by-file/ForcedInformMessageDialog.md`

Replace the proposed contents row wording:

```markdown
| `EnsureLoginDialogPane` call | `0x004f8b30-0x004f8b8d` | Calls [UID:00019L][EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) during accepted EPF teardown; keep the helper implemented with `LoginDialogPane` code. Recovered alias: `EnsureLoginDialogPane_4F8B30`. |
```

Add/retain note:

```text
The forced-inform destructor paths are caller context only. They should invoke the login helper after the accepted forced-inform flow requires returning to login; they should not absorb or rename the helper as forced-inform-owned source.
```

### [UID:0000RE] `by-global/g_pLoginDialogPane.md`

Small wording update:

```text
`g_pLoginDialogPane` is read by source helper `EnsureLoginDialogPane()` (recovered alias `EnsureLoginDialogPane_4F8B30`) before login-dialog creation. The helper relies on `LoginDialogPane::LoginDialogPane` to publish or clear the singleton; it does not assign this global directly.
```

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly during B-agent report pass. Replace the current UID `00019L` row with:

```markdown
    - [UID:00019L][0x004f8b30-0x004f8b8d.EnsureLoginDialogPane](by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md) 0x004f8b30-0x004f8b8d | helper | EnsureLoginDialogPane : reconstructable : 88% : strong : B001 source-quality report resolves the stale no-code blocker: private `login/LoginDialogPane.cpp` helper `EnsureLoginDialogPane()` with no parameters, `g_pLoginDialogPane` duplicate-open guard, MemoryMan-backed global `operator new` allocation of `sizeof(LoginDialogPane)` / `620` bytes (`0x26c`, Verified with `int_convert.py`), constructor-published singleton side effects, two forced-inform accepted-teardown callers only, LoginDialogPane owner/emitter route, and first-draft C++ readiness.
```

If [UID:0000PL] is reframed as non-emitting alias, also refresh `by-global/-coverage-report.md` separately; that file was not part of the current by-memory coverage ban request.

## Validator / Refresh Needs

After supervisor implementation callback and edits:

> Executable block R001 was removed from this report and preserved verbatim in [00019L-EnsureLoginDialogPane-source-quality-removed.md](00019L-EnsureLoginDialogPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended live IDA/read-only validation before final-audit scoring, if MCP becomes available:

```text
lookup_funcs 0x004f8b30, 0x004f8b8d, 0x004f8b90
decompile 0x004f8b30
callers 0x004f8b30
callees 0x004f8b30
xrefs_to 0x0069b484
```

Fresh raw-byte validation is also useful because direct PE read was denied in this session.

## Final Recommendation

- Update target metadata to `88/90`, owner/emitter unchanged.
- Add first-draft C++ on [UID:00019L] exactly as shown above.
- Remove stale `95/95 final-source gate` blocker from target prose.
- Rename/reframe source-facing helper as `EnsureLoginDialogPane()`; keep `EnsureLoginDialogPane_4F8B30`, `sub_4F8B30`, and `FUN_004f8b30` only as evidence aliases.
- Document `0x004f4aa0` as MemoryMan-backed global `operator new`, not a local allocator helper.
- Reframe [UID:0000PL] as a recovered-symbol alias/index or otherwise ensure only one of [UID:0000PL] and [UID:00019L] emits the helper body.

## Confidence

- Recommendation confidence: high.
- Score confidence: `88/90` is justified. The function is tiny and well documented, the route is valid, and the first-draft source is straightforward. Confidence should stay below `95` until live IDA/raw-byte checks are refreshed and the by-global duplicate-emission policy is resolved.
- Remaining uncertainty: original source file spelling cannot be directly proven without debug/source metadata; `EnsureLoginDialogPane` is a high-probability descriptive source name. Broader account-dialog file grouping remains a file-level planning caveat but does not block this helper.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00019L-EnsureLoginDialogPane-source-quality.md`
- Modified: none
- Target/support by-* docs edited: none
- Coverage edited: none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00019L-EnsureLoginDialogPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"00019L"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00019L-EnsureLoginDialogPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00019L-EnsureLoginDialogPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00019L"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
