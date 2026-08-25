** TARGET-REPORT-UID:00010T **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00010T ClanDestructorBand Source Routing

Status: FINISHED

Agent: B014

Target: [UID:00010T] `source-3/project-documentation/by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md`

Report-only assignment: no by-* docs or coverage files were edited.

## Recommendation

Keep the aggregate as non-reconstructable and non-emitting:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

The current aggregate is useful, but stale. The direct PE byte pass shows that `0x0048c260-0x0048c314` is not one continuous adjustor-thunk strip. The correct physical split is:

- `0x0048c260-0x0048c26b`: 11-byte singleton-clear cleanup helper for `g_pClanBankPane`.
- `0x0048c26b-0x0048c270`: padding.
- `0x0048c270-0x0048c27b`: 11-byte singleton-clear cleanup helper for `g_pClanStatusPane`.
- `0x0048c27b-0x0048c341`: compiler-generated destructor adjustor thunks.
- `0x0048c341-0x0048c350`: padding.
- `0x0048c350-0x0048c63f`: several scalar-deleting destructor wrappers and padding owned by different class/source families.

No single source owner or handwritten C++ body is valid for the whole band. The aggregate should stay a routing/boundary map, not a source reconstruction target.

## Evidence Checked

- Read current target doc `by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md`.
- Read current rows in `by-memory/-coverage-report.md` and stale ignored row in `by-memory/-ignored.md`.
- Read relevant exact child docs:
  - [UID:00010U] `0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md`
  - [UID:00010V] `0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md`
  - [UID:00030O] `0x0048c32b-0x0048c341.ClanStatusPaneDestructorAdjustorThunks.md`
  - [UID:00010W] `0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md`
  - [UID:00030P] `0x0048c590-0x0048c63f.ClanStatusPaneDestructor.md`
- Read support docs for `Clan`, `ClanBank`, `ClanDialogs`, `DialogPane`, `AlertPane`, `ClanStatusPane`, `ClanAttrInputDialog`, `ClanBankPane`, `ClanBankItemListPane`, `ClanItemDialog`, `ClanItemListPane`, `TextEditPane`, `ClanDialogVtableFamily`, `ClanBankVtables`, `ClanPaneListVtableData`, `UiChatClanSingletonSlots`, `g_pClanStatusPane`, and `g_pClanBankPane`.
- Searched B014/B001/B002 research folders for prior `00010T` or `ClanDestructorBand` B-agent reports; no prior B report found.
- Tried local IDA MCP at `http://127.0.0.1:13337/mcp`; it was unavailable (`Unable to connect to the remote server`), so this report uses existing IDA-backed docs plus a direct read-only PE scan.
- Direct PE scan target: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, md5 `4247e04e20b65d6414c7238aa8ff5515`, sha256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, image base `0x00400000`.

## Direct PE Facts

The direct byte pass contradicts the current aggregate's `0x0048c260-0x0048c314` thunk-strip label.

```text
0x0048c260: c7 05 e8 ad 67 00 00 00 00 00 c3
             mov dword ptr [0x0067ade8], 0
             ret

0x0048c26b-0x0048c270: cc cc cc cc cc

0x0048c270: c7 05 e4 ad 67 00 00 00 00 00 c3
             mov dword ptr [0x0067ade4], 0
             ret
```

The true 11-byte `sub ecx, imm; jmp target` adjustor strip begins at `0x0048c27b`.

The only rel32 code references to the two clear helpers are:

| Target | Rel32 caller | Interpretation |
|---|---:|---|
| `0x0048c260` | `0x005fc9f3` | Constructor-unwind or cleanup route for the `g_pClanBankPane` singleton slot; not a vtable thunk. |
| `0x0048c270` | `0x005fc481` | Constructor-unwind or cleanup route for the `g_pClanStatusPane` singleton slot; not a vtable thunk. |

The vtable/dword refs support the actual thunk and destructor split:

| Address | Confirmed dword/vtable refs |
|---:|---|
| `0x0048c27b` | `0x0061595c`, `0x006159fc`, `0x00615a9c`, `0x00615b3c`, `0x00615bdc`, `0x00615c7c`, `0x00615d1c`, `0x00618ac4`, `0x00618ca8`, `0x0062db0c`, `0x0062dba8`, `0x0062e1f0` |
| `0x0048c286` | `0x0061598c`, `0x00615a2c`, `0x00615acc`, `0x00615b6c`, `0x00615c0c`, `0x00615cac`, `0x00615d4c`, `0x00618af4`, `0x00618cd8`, `0x0062db3c`, `0x0062dbd8`, `0x0062e220` |
| `0x0048c291` / `0x0048c29c` | `0x00615dbc`, `0x00615e5c`, `0x00615efc` / `0x00615dec`, `0x00615e8c`, `0x00615f2c` |
| `0x0048c2a7` / `0x0048c2b2` | `0x006163a4` / `0x006163d4` |
| `0x0048c2bd` / `0x0048c2c8` | `0x006162e0` / `0x00616310` |
| `0x0048c2d3` / `0x0048c2de` | `0x00616040`, `0x006160e0`, `0x00616180` / `0x00616070`, `0x00616110`, `0x006161b0` |
| `0x0048c2e9` / `0x0048c2f4` | `0x00615670`, `0x0061e81c`, `0x0062428c`, `0x00624400`, `0x0062e00c`, `0x0062e0e8`, `0x0062edd0`, `0x0062ee84` / `0x006156a0`, `0x0061e84c`, `0x006242bc`, `0x00624430`, `0x0062e03c`, `0x0062e118`, `0x0062ee00`, `0x0062eeb4` |
| `0x0048c2ff` / `0x0048c30a` | `0x00616244` / `0x00616274` |
| `0x0048c315` / `0x0048c320` | `0x00615fa0`, `0x00618b68`, `0x0061dd40`, `0x00622ee4`, `0x0062f148` / `0x00615fd0`, `0x00618b98`, `0x0061dd70`, `0x00622f14`, `0x0062f178` |
| `0x0048c32b` / `0x0048c336` | `0x006155bc` / `0x006155ec` |
| `0x0048c350` | `0x006158f8`, `0x00615998`, `0x00615a38`, `0x00615ad8`, `0x00615b78`, `0x00615c18`, `0x00615cb8`, `0x00618a64`, `0x00618c48`, `0x0062daac`, `0x0062db48`, `0x0062e190` |
| `0x0048c390` | `0x00615d58`, `0x00615df8`, `0x00615e98` |
| `0x0048c3d0` | `0x0061631c` |
| `0x0048c410` | `0x00616280` |
| `0x0048c470` | `0x00615fdc`, `0x0061607c`, `0x0061611c` |
| `0x0048c4d0` | `0x006155f8`, `0x0061e7a4`, `0x00624214`, `0x00624388`, `0x0062df94`, `0x0062e070`, `0x0062ed58`, `0x0062ee0c` |
| `0x0048c510` | `0x006161bc` |
| `0x0048c550` | `0x00615f38`, `0x00618b00`, `0x0061dcd8`, `0x00622e7c`, `0x0062f0e0` |
| `0x0048c590` | `0x00615570` |

## Exact Subrange Map

All ranges below are half-open.

| Range | Classification | Best source route |
|---|---|---|
| `0x0048c260-0x0048c26b` | Singleton-clear cleanup helper: `g_pClanBankPane = 0; return;` | Compiler/EH cleanup support for `ClanBankPane` lifecycle. Do not treat as a source method or adjustor thunk. |
| `0x0048c26b-0x0048c270` | Padding | Ignore. |
| `0x0048c270-0x0048c27b` | Singleton-clear cleanup helper: `g_pClanStatusPane = 0; return;` | Compiler/EH cleanup support for `ClanStatusPane` lifecycle. Do not treat as a source method or adjustor thunk. |
| `0x0048c27b-0x0048c286` | Adjustor thunk: `sub ecx, 0xa0; jmp 0x0048c350` | `DialogPane` secondary-base destructor thunk, generated from inheritance. |
| `0x0048c286-0x0048c291` | Adjustor thunk: `sub ecx, 0xa4; jmp 0x0048c350` | `DialogPane` tertiary-base destructor thunk, generated from inheritance. Existing [UID:00010U] filename should be corrected to end at `0x0048c291`. |
| `0x0048c291-0x0048c29c` | Adjustor thunk: `sub ecx, 0xa0; jmp 0x0048c390` | `ClanAttrInputDialog` family secondary-base destructor thunk. |
| `0x0048c29c-0x0048c2a7` | Adjustor thunk: `sub ecx, 0xa4; jmp 0x0048c390` | `ClanAttrInputDialog` family tertiary-base destructor thunk. |
| `0x0048c2a7-0x0048c2b2` | Adjustor thunk: `sub ecx, 0xa0; jmp 0x0048c3d0` | `ClanBankItemListPane` secondary-base destructor thunk. |
| `0x0048c2b2-0x0048c2bd` | Adjustor thunk: `sub ecx, 0xa4; jmp 0x0048c3d0` | `ClanBankItemListPane` tertiary-base destructor thunk. |
| `0x0048c2bd-0x0048c2c8` | Adjustor thunk: `sub ecx, 0xa0; jmp 0x0048c410` | `ClanBankPane` secondary-base destructor thunk. |
| `0x0048c2c8-0x0048c2d3` | Adjustor thunk: `sub ecx, 0xa4; jmp 0x0048c410` | `ClanBankPane` tertiary-base destructor thunk. |
| `0x0048c2d3-0x0048c2de` | Adjustor thunk: `sub ecx, 0xa0; jmp 0x0048c470` | `ClanItemDialog`/`ClanDepItemDialog`/`ClanWidItemDialog` family thunk. |
| `0x0048c2de-0x0048c2e9` | Adjustor thunk: `sub ecx, 0xa4; jmp 0x0048c470` | `ClanItemDialog`/`ClanDepItemDialog`/`ClanWidItemDialog` family thunk. |
| `0x0048c2e9-0x0048c2f4` | Adjustor thunk: `sub ecx, 0xa0; jmp 0x0048c4d0` | Shared compact/TextEdit/ListPane-family thunk; not a ClanBank item/dialog thunk. |
| `0x0048c2f4-0x0048c2ff` | Adjustor thunk: `sub ecx, 0xa4; jmp 0x0048c4d0` | Shared compact/TextEdit/ListPane-family thunk; not a ClanBank item/dialog thunk. |
| `0x0048c2ff-0x0048c30a` | Adjustor thunk: `sub ecx, 0xa0; jmp 0x0048c510` | `ClanItemListPane` secondary-base destructor thunk. |
| `0x0048c30a-0x0048c315` | Adjustor thunk: `sub ecx, 0xa4; jmp 0x0048c510` | `ClanItemListPane` tertiary-base destructor thunk. |
| `0x0048c315-0x0048c320` | Adjustor thunk: `sub ecx, 0xa0; jmp 0x0048c550` | Existing [UID:00010V] `AlertPane` thunk child. |
| `0x0048c320-0x0048c32b` | Adjustor thunk: `sub ecx, 0xa4; jmp 0x0048c550` | Existing [UID:00010V] `AlertPane` thunk child. |
| `0x0048c32b-0x0048c336` | Adjustor thunk: `sub ecx, 0xa0; jmp 0x0048c590` | Existing [UID:00030O] `ClanStatusPane` thunk child. |
| `0x0048c336-0x0048c341` | Adjustor thunk: `sub ecx, 0xa4; jmp 0x0048c590` | Existing [UID:00030O] `ClanStatusPane` thunk child. |
| `0x0048c341-0x0048c350` | Padding | Ignore. |
| `0x0048c350-0x0048c38b` | `DialogPane` scalar-deleting destructor wrapper | Source route: `DialogPane`, likely no standalone C++ because wrapper is compiler-generated from `virtual ~DialogPane()`. |
| `0x0048c38b-0x0048c390` | Padding | Ignore. |
| `0x0048c390-0x0048c3cb` | `ClanAttrInputDialog` family scalar-deleting destructor wrapper | Source route: `Clan` file, shared by `ClanAttrInputDialog`, `ClanEnlistInputDialog`, and `ClanChangeInputDialog`. Existing class docs should use the `0x0048c3cb` exclusive end. |
| `0x0048c3cb-0x0048c3d0` | Padding | Ignore. |
| `0x0048c3d0-0x0048c40b` | `ClanBankItemListPane` scalar-deleting destructor wrapper | Source route: `ClanBank` file. Existing class docs should use `0x0048c40b` exclusive end. |
| `0x0048c40b-0x0048c410` | Padding | Ignore. |
| `0x0048c410-0x0048c46f` | `ClanBankPane` scalar-deleting destructor wrapper | Source route: `ClanBank` file; clears `g_pClanBankPane`. Existing class docs should use `0x0048c46f` exclusive end. |
| `0x0048c46f-0x0048c470` | Padding | Ignore. |
| `0x0048c470-0x0048c4c5` | `ClanItemDialog` family scalar-deleting destructor wrapper | Source route: `ClanBank` file, shared by item/deposit/withdraw item dialogs. Existing class docs should use `0x0048c4c5` exclusive end. |
| `0x0048c4c5-0x0048c4d0` | Padding | Ignore. |
| `0x0048c4d0-0x0048c50b` | Shared compact/TextEdit/ListPane scalar-deleting destructor wrapper | Source route unresolved but not Clan/ClanBank. `TextEditPane` docs already list this destructor range, and dword refs include TextEdit/TextBox/SelfSaveOK/GroupList/Legend-like vtables. Needs its own source-quality child/follow-up. |
| `0x0048c50b-0x0048c510` | Padding | Ignore. |
| `0x0048c510-0x0048c54b` | `ClanItemListPane` scalar-deleting destructor wrapper | Source route: `ClanBank` file. Existing class docs already use the correct `0x0048c54b` exclusive end. |
| `0x0048c54b-0x0048c550` | Padding | Ignore. |
| `0x0048c550-0x0048c58b` | Existing [UID:00010W] `AlertPane` shared scalar-deleting destructor | Source route: `AlertPane`; no standalone wrapper C++. |
| `0x0048c58b-0x0048c590` | Padding | Ignore. |
| `0x0048c590-0x0048c63f` | Existing [UID:00030P] `ClanStatusPane` scalar-deleting destructor | Source route: `Clan` file; destroys status child panes and clears `g_pClanStatusPane`. |
| `0x0048c63f-0x0048c640` | Padding after aggregate | Already recorded as ignored boundary padding. |

## Owner Split

`ClanDestructorBand` is a physical code-band name, not a source-facing class or function name. Use it only for the aggregate page.

Best source-facing routing:

| Source owner | Ranges |
|---|---|
| `DialogPane` / [UID:0000IT] | `0x0048c27b-0x0048c291`, `0x0048c350-0x0048c38b` |
| `Clan` / [UID:0000I8] | `0x0048c291-0x0048c2a7`, `0x0048c390-0x0048c3cb`, `0x0048c270-0x0048c27b` as cleanup support, `0x0048c32b-0x0048c341`, `0x0048c590-0x0048c63f` |
| `ClanBank` / [UID:0000I9] | `0x0048c2a7-0x0048c2e9`, `0x0048c2ff-0x0048c315`, `0x0048c3d0-0x0048c4c5`, `0x0048c510-0x0048c54b`, `0x0048c260-0x0048c26b` as cleanup support |
| `AlertPane` / alert-dialog file family | `0x0048c315-0x0048c32b`, `0x0048c550-0x0048c58b` |
| Shared compact/TextEdit/ListPane family | `0x0048c2e9-0x0048c2ff`, `0x0048c4d0-0x0048c50b` |
| None / aggregate only | Padding and the full `0x0048c260-0x0048c63f` wrapper map |

The current target language saying the `0x0048c4d0` body is still in the Clan item/dialog family should be replaced. The dword fanout includes non-Clan vtables, and `by-class/TextEditPane.md` explicitly lists construction/destruction at `0x0058dce0-0x0058e227`, `0x0048c4d0-0x0048c50a`; update that end to `0x0048c50b` and route the body as shared compact/TextEdit/ListPane support until a dedicated source-quality pass resolves the precise class name.

## Heuristic Reanalysis

### `0x0048c260` and `0x0048c270`

These were previously treated as 11-byte thunks. They are not thunks because they do not read or adjust `ecx` and do not jump. They are `mov [global], 0; ret` helpers.

Best-supported names:

- `ClearClanBankPaneSingletonCleanup` for `0x0048c260`.
- `ClearClanStatusPaneSingletonCleanup` for `0x0048c270`.

Confidence: high for behavior and global names; medium for whether docs should create exact by-memory child pages or keep them in `-ignored.md`. The one caller each from the high `0x005fc...` area looks like compiler cleanup/unwind glue, not a source-authored helper a developer would call.

### Adjustor thunks

All `0x0048c27b-0x0048c341` entries are compiler-generated multiple-inheritance destructor adjustors. They should stay no-code and should be regenerated from class inheritance and virtual destructor declarations.

The existing [UID:00010U] child is semantically correct but its filename/link range is stale: the exact half-open range is `0x0048c27b-0x0048c291`, not `0x0048c27b-0x0048c290`.

### Scalar-deleting destructor wrappers

The bodies at `0x0048c350`, `0x0048c390`, `0x0048c3d0`, `0x0048c410`, `0x0048c470`, `0x0048c4d0`, `0x0048c510`, `0x0048c550`, and `0x0048c590` are scalar-deleting destructor wrappers. Some contain source destructor semantics, but the wrapper entrypoint itself is compiler-generated. Source C++ should be expressed as class destructors on exact class pages, not as emitted C++ on the aggregate.

The `0x0048c4d0` wrapper is the main unresolved middle label. The best defensible direction is "shared compact/TextEdit/ListPane destructor support, not Clan." The vtable refs and `TextEditPane` class doc make a ClanBank owner unsafe.

## Aggregate No-Code Proof

Do not emit C++ from [UID:00010T].

Reason:

- The aggregate includes two singleton-clear cleanup helpers, not one function.
- The aggregate includes compiler-generated adjustor thunks.
- The aggregate includes scalar-deleting destructor wrappers from multiple source owners.
- The aggregate includes shared base or neighbor-family destructors (`DialogPane`, `AlertPane`, and shared compact/TextEdit/ListPane support).
- The aggregate includes padding between functions.
- A single C++ body here would duplicate or misroute behavior that should be recovered through normal class declarations, exact destructor children, or compiler-regenerated thunks.

The correct C++ policy is:

- Aggregate [UID:00010T]: blank C++.
- Adjustor-thunk children: blank C++.
- Scalar-deleting destructor wrapper children: usually blank C++ at wrapper level; source shape belongs in the owning class destructor declaration/body when a specific exact class page justifies it.
- `ClanStatusPane` and `ClanBankPane` source destructor behavior can be documented in their class/source docs, but the binary wrapper should not be rewritten as aggregate C++.

## Recommended Target Doc Changes

For `by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md`:

1. Raise metadata to `COMPLETION:88`, `CONFIDENCE:91`; keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank C++.
2. Replace "Clan vtable thunk and destructor band" wording with "mixed destructor/cleanup/thunk boundary map."
3. Replace the stale `0x0048c260-0x0048c314` row with the exact subrange map from this report.
4. Correct the true thunk strip to `0x0048c27b-0x0048c341`.
5. Correct body half-open endpoints:
   - `0x0048c350-0x0048c38b`
   - `0x0048c390-0x0048c3cb`
   - `0x0048c3d0-0x0048c40b`
   - `0x0048c410-0x0048c46f`
   - `0x0048c470-0x0048c4c5`
   - `0x0048c4d0-0x0048c50b`
   - `0x0048c510-0x0048c54b`
   - `0x0048c550-0x0048c58b`
   - `0x0048c590-0x0048c63f`
6. Add the direct byte evidence for `0x0048c260` and `0x0048c270`.
7. Replace the statement that `0x0048c4d0` is a Clan item/dialog destructor family with the shared compact/TextEdit/ListPane classification and open follow-up.
8. Preserve the no-code proof: the aggregate is not a source-level object and cannot have a single emitter.

## Recommended Support Changes

Existing docs to update in a later implementation callback:

- `by-memory/-ignored.md`: replace the stale `0x0048c260-0x0048c314` ignored entry with accurate cleanup-helper, thunk, and padding entries. Do not leave it saying the whole range is Clan dialog/list/status adjustor thunks.
- `by-memory/-coverage-report.md`: supervisor-owned update only; use the pending row text below.
- `by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md`: rename or refit to `0x0048c27b-0x0048c291.DialogPaneAdjustorThunks.md`; update metadata if the validator requires it after the filename/range repair.
- `by-class/DialogPane.md`: update the [UID:00010U] link range to `0x0048c27b-0x0048c291` and add the `0x0048c350-0x0048c38b` wrapper as DialogPane destructor support if not already covered by `DialogPaneVtables`.
- `by-class/ClanAttrInputDialog.md`: update destructor/support range to `0x0048c390-0x0048c3cb`; document that `0x0048c291/0x0048c29c` are generated thunks for the shared modal input-dialog destructor.
- `by-class/ClanBankItemListPane.md`: update destructor range to `0x0048c3d0-0x0048c40b`.
- `by-class/ClanBankPane.md`: update destructor range to `0x0048c410-0x0048c46f`; include `0x0048c260` as singleton-clear cleanup support, not source C++.
- `by-class/ClanItemDialog.md`: update destructor range to `0x0048c470-0x0048c4c5`; keep the shared item/deposit/withdraw dialog source-route note.
- `by-class/ClanItemListPane.md`: confirm existing `0x0048c510-0x0048c54b` range and add thunk pair `0x0048c2ff/0x0048c30a` if missing.
- `by-class/ClanStatusPane.md`: keep `0x0048c590-0x0048c63f`, add `0x0048c270` as constructor-cleanup/singleton-clear support, and preserve `0x0048c32b/0x0048c336` as generated thunks.
- `by-class/TextEditPane.md`: change the listed destructor range from `0x0048c4d0-0x0048c50a` to `0x0048c4d0-0x0048c50b`; add caveat that this is shared compact/TextEdit/ListPane scalar-deleting destructor support rather than an exclusive TextEditPane source body.
- `by-file/Clan.md`: add a short note that the physical destructor band includes Clan modal/status wrappers but begins with two cleanup helpers and includes non-Clan source owners.
- `by-file/ClanBank.md`: add a short note that `0x0048c260` clears `g_pClanBankPane` as cleanup support, and `0x0048c4d0` is not a ClanBank item/dialog destructor.
- `by-type/by-vtable/ClanDialogVtableFamily.md`: update the thunk-strip statement from `0x0048c260-0x0048c341` to `0x0048c27b-0x0048c341`; note the preceding cleanup helpers.
- `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`, `g_pClanStatusPane`, and `g_pClanBankPane` docs: add the two clear-helper addresses if a later implementation touches singleton lifecycle docs.

Recommended new exact children or follow-up pages:

| Proposed child | Disposition |
|---|---|
| `0x0048c260-0x0048c26b.ClearClanBankPaneSingletonCleanup.md` | Compiler cleanup helper; no C++; likely ignored or exact support child. |
| `0x0048c270-0x0048c27b.ClearClanStatusPaneSingletonCleanup.md` | Compiler cleanup helper; no C++; likely ignored or exact support child. |
| `0x0048c291-0x0048c2a7.ClanAttrInputDialogDestructorAdjustorThunks.md` | Generated thunk pair; no C++. |
| `0x0048c2a7-0x0048c2bd.ClanBankItemListPaneDestructorAdjustorThunks.md` | Generated thunk pair; no C++. |
| `0x0048c2bd-0x0048c2d3.ClanBankPaneDestructorAdjustorThunks.md` | Generated thunk pair; no C++. |
| `0x0048c2d3-0x0048c2e9.ClanItemDialogDestructorAdjustorThunks.md` | Generated thunk pair; no C++. |
| `0x0048c2e9-0x0048c2ff.CompactPaneDestructorAdjustorThunks.md` | Generated thunk pair; shared non-Clan route, needs follow-up. |
| `0x0048c2ff-0x0048c315.ClanItemListPaneDestructorAdjustorThunks.md` | Generated thunk pair; no C++. |
| `0x0048c350-0x0048c38b.DialogPaneScalarDeletingDestructor.md` | Wrapper support for `DialogPane`; source shape `virtual ~DialogPane()`, wrapper C++ blank. |
| `0x0048c390-0x0048c3cb.ClanAttrInputDialogScalarDeletingDestructor.md` | Wrapper support for modal Clan input-dialog base; wrapper C++ blank unless a class destructor source pass justifies a body. |
| `0x0048c3d0-0x0048c40b.ClanBankItemListPaneScalarDeletingDestructor.md` | Wrapper support; wrapper C++ blank. |
| `0x0048c410-0x0048c46f.ClanBankPaneScalarDeletingDestructor.md` | Wrapper support; wrapper C++ blank or class destructor source body only on class page. |
| `0x0048c470-0x0048c4c5.ClanItemDialogScalarDeletingDestructor.md` | Wrapper support; wrapper C++ blank. |
| `0x0048c4d0-0x0048c50b.CompactPaneSharedScalarDeletingDestructor.md` | Needs B follow-up; currently source owner unresolved but not Clan/ClanBank. |
| `0x0048c510-0x0048c54b.ClanItemListPaneScalarDeletingDestructor.md` | Wrapper support; wrapper C++ blank. |

## Future Implementation Checklist

1. Edit only after supervisor callback.
2. Update [UID:00010T] metadata to `88/91`, owner none, reconstructable false, blank emitter/C++.
3. Replace target map and evidence with the exact ranges in this report.
4. Repair the [UID:00010U] exact range/filename/link to `0x0048c27b-0x0048c291`.
5. Update class/file/vtable support docs listed above.
6. Replace stale `-ignored.md` row text; do not preserve `0x0048c260-0x0048c314` as a single thunk strip.
7. Leave `by-memory/-coverage-report.md` for supervisor-owned application only, using the exact row text below.
8. Run validators for every edited file and autogen if filenames, routing, or generated links change.

## Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` as part of this report. Recommended exact replacement for the existing [UID:00010T] row:

```text
    - [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md) 0x0048c260-0x0048c63f | destructor/cleanup/thunk aggregate | ClanDestructorBand : ignored : 88% : very strong : B014 source-routing recheck keeps this as a non-emitting mixed boundary map: direct PE bytes show two singleton-clear cleanup helpers at `0x0048c260-0x0048c26b` and `0x0048c270-0x0048c27b`, the true compiler adjustor-thunk strip at `0x0048c27b-0x0048c341`, shared `DialogPane` and `AlertPane` destructor wrappers, Clan/ClanBank destructor wrappers, a non-Clan shared compact/TextEdit/ListPane destructor wrapper at `0x0048c4d0-0x0048c50b`, exact existing children for AlertPane and ClanStatusPane, and padding through `0x0048c63f`; no single source owner or C++ body is valid for the aggregate.
```

Recommended exact replacement for the current stale [UID:0000VN] coverage row immediately below it:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) : ignored : 88% : strong : Replace the stale `0x0048c260-0x0048c314` Clan-thunk entry with corrected local ignored/support spans: `0x0048c260-0x0048c26b` clears `g_pClanBankPane` as compiler cleanup support, `0x0048c26b-0x0048c270` is padding, `0x0048c270-0x0048c27b` clears `g_pClanStatusPane` as compiler cleanup support, `0x0048c27b-0x0048c341` is the generated destructor adjustor-thunk strip split by exact children/backlog, and the intra-band padding spans are `0x0048c341-0x0048c350`, `0x0048c38b-0x0048c390`, `0x0048c3cb-0x0048c3d0`, `0x0048c40b-0x0048c410`, `0x0048c46f-0x0048c470`, `0x0048c4c5-0x0048c4d0`, `0x0048c50b-0x0048c510`, `0x0048c54b-0x0048c550`, and `0x0048c58b-0x0048c590`.
```

Recommended replacement for current [UID:00010U] coverage row after filename/range repair:

```text
    - [UID:00010U][0x0048c27b-0x0048c291.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c291.DialogPaneAdjustorThunks.md) 0x0048c27b-0x0048c291 | compiler thunk pair | DialogPaneAdjustorThunks : ignored : 88% : strong : Exact secondary/tertiary `DialogPane` destructor adjustor thunks; dword refs include `DialogPane` vtables at `0x00618ac4`/`0x00618af4` plus dialog-derived tables, and source reconstruction should regenerate them from inheritance and `virtual ~DialogPane()`.
```

Current [UID:00010V], [UID:00030O], [UID:00010W], and [UID:00030P] rows can remain conceptually valid, but use these range-exact replacement rows if the supervisor refreshes the whole block:

```text
    - [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md) 0x0048c315-0x0048c32b | compiler thunk pair | AlertPaneAdjustorThunks : ignored : 85% : strong : Exact secondary/tertiary `AlertPane` destructor adjustor thunks reused by ClanLeaveConfirmDialog, AlertPane, BlueAlertPane, CopyWindow, and QuitDialog vtables; no handwritten source C++.
    - [UID:00030O][0x0048c32b-0x0048c341.ClanStatusPaneDestructorAdjustorThunks](by-memory/0x0048c32b-0x0048c341.ClanStatusPaneDestructorAdjustorThunks.md) 0x0048c32b-0x0048c341 | compiler thunk pair | ClanStatusPaneDestructorAdjustorThunks : ignored : 85% : strong : Exact secondary/tertiary `ClanStatusPane` destructor adjustor thunks into [UID:00030P][0x0048c590-0x0048c63f.ClanStatusPaneDestructor](by-memory/0x0048c590-0x0048c63f.ClanStatusPaneDestructor.md); source reconstruction should regenerate them from normal inheritance/destructor declarations.
    - [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) 0x0048c550-0x0048c58b | scalar-deleting-destructor | AlertPaneSharedScalarDestructor : reconstructable : 86% : strong : Exact shared alert-family scalar-deleting destructor wrapper; source shape belongs to `virtual ~AlertPane()` and wrapper C++ remains blank.
    - [UID:00030P][0x0048c590-0x0048c63f.ClanStatusPaneDestructor](by-memory/0x0048c590-0x0048c63f.ClanStatusPaneDestructor.md) 0x0048c590-0x0048c63f | scalar-deleting destructor | ClanStatusPaneDestructor : reconstructable : 86% : strong : Exact `ClanStatusPane` scalar-deleting destructor wrapper; destroys child panes, clears `g_pClanStatusPane`, and preserves compiler-wrapper no-code guidance unless a separate class destructor implementation pass emits source-level destructor C++.
```

If new exact child pages are created, add validator-assigned UID rows for those child pages instead of expanding the [UID:0000VN] ignored summary. The filenames and dispositions are listed in "Recommended new exact children or follow-up pages."

## Validation Commands Needed

After implementation callback edits, run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00010T-ClanDestructorBand-source-routing-removed.md](00010T-ClanDestructorBand-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If generated routing, filenames, child pages, or support indices change:

> Executable block R002 was removed from this report and preserved verbatim in [00010T-ClanDestructorBand-source-routing-removed.md](00010T-ClanDestructorBand-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Supervisor-owned coverage update only:

> Executable block R003 was removed from this report and preserved verbatim in [00010T-ClanDestructorBand-source-routing-removed.md](00010T-ClanDestructorBand-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

No validators were run for this report-only task.

## IDA Rename, Type, and Comment Recommendations

High-confidence renames:

- `0x0048c260`: `ClearClanBankPaneSingletonCleanup`
- `0x0048c270`: `ClearClanStatusPaneSingletonCleanup`
- `0x0048c27b`: `DialogPane_dtor_adjustor_minusA0`
- `0x0048c286`: `DialogPane_dtor_adjustor_minusA4`
- `0x0048c291`: `ClanAttrInputDialog_dtor_adjustor_minusA0`
- `0x0048c29c`: `ClanAttrInputDialog_dtor_adjustor_minusA4`
- `0x0048c2a7`: `ClanBankItemListPane_dtor_adjustor_minusA0`
- `0x0048c2b2`: `ClanBankItemListPane_dtor_adjustor_minusA4`
- `0x0048c2bd`: `ClanBankPane_dtor_adjustor_minusA0`
- `0x0048c2c8`: `ClanBankPane_dtor_adjustor_minusA4`
- `0x0048c2d3`: `ClanItemDialog_dtor_adjustor_minusA0`
- `0x0048c2de`: `ClanItemDialog_dtor_adjustor_minusA4`
- `0x0048c2ff`: `ClanItemListPane_dtor_adjustor_minusA0`
- `0x0048c30a`: `ClanItemListPane_dtor_adjustor_minusA4`
- `0x0048c315`: `AlertPane_dtor_adjustor_minusA0`
- `0x0048c320`: `AlertPane_dtor_adjustor_minusA4`
- `0x0048c32b`: `ClanStatusPane_dtor_adjustor_minusA0`
- `0x0048c336`: `ClanStatusPane_dtor_adjustor_minusA4`

Medium-confidence rename/comment pair for unresolved middle route:

- `0x0048c2e9`: `CompactPaneShared_dtor_adjustor_minusA0`
- `0x0048c2f4`: `CompactPaneShared_dtor_adjustor_minusA4`
- `0x0048c4d0`: `CompactPaneShared_scalar_deleting_destructor`
- Comment: "Shared compact/TextEdit/ListPane scalar-deleting destructor wrapper; vtable fanout includes TextEdit/TextBox/SelfSaveOK/GroupList/Legend-like classes. Do not route to ClanBank without a dedicated source-quality pass."

Scalar-deleting wrapper names:

- `0x0048c350`: `DialogPane_scalar_deleting_destructor`
- `0x0048c390`: `ClanAttrInputDialog_scalar_deleting_destructor`
- `0x0048c3d0`: `ClanBankItemListPane_scalar_deleting_destructor`
- `0x0048c410`: `ClanBankPane_scalar_deleting_destructor`
- `0x0048c470`: `ClanItemDialog_scalar_deleting_destructor`
- `0x0048c510`: `ClanItemListPane_scalar_deleting_destructor`
- `0x0048c550`: `AlertPane_scalar_deleting_destructor`
- `0x0048c590`: `ClanStatusPane_scalar_deleting_destructor`

Type guidance:

- Clear helpers: `void __cdecl ClearClanBankPaneSingletonCleanup(void)` and `void __cdecl ClearClanStatusPaneSingletonCleanup(void)` if typed at all.
- Adjustor thunks: leave as generated thunks or annotate; no source-facing prototype.
- Scalar-deleting wrappers: use compiler-wrapper prototypes if IDA needs types, but source docs should describe source-facing `virtual ~ClassName()` instead of pretending the wrapper is handwritten C++.

## Open Questions

- Exact source owner/name for `0x0048c4d0-0x0048c50b`: unresolved after this pass. Evidence strongly rejects Clan/ClanBank. Best direction is shared compact/TextEdit/ListPane destructor support, with `TextEditPane` currently the strongest documented route but not exclusive enough for a final owner.
- Whether to create exact child pages for the two singleton-clear cleanup helpers versus keeping them in `-ignored.md`: both are defensible. They are exact and useful lifecycle evidence, but they are compiler/EH cleanup support and should not emit C++ either way.
- Whether exact scalar-deleting destructor children should be created for all missing wrappers: recommended for audit precision, but they should remain wrapper/no-code pages unless a separate class-source pass writes class destructor C++.

## Changed Files

Created this report only:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/00010T-ClanDestructorBand-source-routing.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/00010T-ClanDestructorBand-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"00010T"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00010T-ClanDestructorBand-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/00010T-ClanDestructorBand-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00010T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
