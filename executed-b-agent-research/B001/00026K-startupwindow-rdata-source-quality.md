** TARGET-REPORT-UID:00026K **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00026K StartupWindow Read-Only Data Source-Quality Report

Agent: B001  
Assignment: `B001-goal2-startupwindow-rdata-source-quality-00026K-20260617`  
Date: 2026-06-17  
Scope: report-only. No by-* docs, generated reports/source, IDA database, source files, or `by-memory/-coverage-report.md` were edited.

## Finalized Report / Current Recommendation

Current recommendation:

- Keep [UID:00026K] as StartupWindow-owned reconstructable read-only data, but correct its exclusive end from `0x0062d5ac` to `0x0062d5a8`.
- Rename/range-correct the target to `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md`.
- Move `0x0062d5a8-0x0062d5ac`, the `StdioFile` complete-object-locator pointer, into [UID:00026L] by expanding that successor range to `0x0062d5a8-0x0062d5f8`.
- Keep [UID:00026K] `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`.
- Raise [UID:00026K] from `82/88` to `88/92`.
- Do not populate formal C++ in [UID:00026K]. The source-facing constants should be represented through the owning `StartupWindow.cpp` methods/global-pointer pages and the compiler-emitted vtable should be regenerated from the class declaration, not hand-authored in this data page.

Confidence: high for source owner and constants; high for the boundary correction; medium-high for exact original source spelling of the constants.

## Target

- Target UID: [UID:00026K]
- Current target path: `by-memory/0x0062d418-0x0062d5ac.StartupWindowReadOnlyData.md`
- Recommended target path: `by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md`
- Current scores: `82/88`
- Current owner/emitter: [UID:0000O5] `StartupWindow`
- Current reconstructable state: `RECONSTRUCTABLE:TRUE`
- Output route: [UID:0000O5] `StartupWindow` -> `auto-generated/NexusTK/app/StartupWindow.cpp`

## Evidence Reviewed

Docs reviewed:

- [UID:00026K] target page.
- [UID:0000O5] `by-file/StartupWindow.md`.
- [UID:0000DZ] `by-class/StartupWindow.md`.
- [UID:0001IO] `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`.
- [UID:0001RO] `by-resource/startup-update-notice-resources.md`.
- [UID:000288] `by-memory/0x00670260-0x00670268.StartupWindowNoticePointerData.md`.
- [UID:0002AM] `by-memory/0x0069bac4-0x0069bacc.StartupWindowUpdateStateGlobals.md`.
- [UID:0000SW] `by-global/g_useEpfAssets.md`.
- Neighbor pages [UID:00026J] and [UID:00026L], plus enclosing [UID:0001Z7] `.rdata` section map.
- `by-project-structure/proposed-source-tree.md`, which places `StartupWindow.cpp` under `NexusTK/app/`.
- `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `by-memory/-coverage-report.md`, and generated `simroot_v2/class_StartupWindow.cpp`.

Live IDA MCP evidence:

- Active database: `b003_00018a_ime_comp_20260617`, `NexusTK.exe`, image base `0x400000`, Hex-Rays ready, auto-analysis ready.
- `get_string` confirmed all strings in the target range, including the omitted `updvr` registry value at `0x0062d49c`.
- `entity_query strings` reported 15 strings in `0x0062d418-0x0062d5ac`.
- `entity_query names` reported the StartupWindow vtable at `0x0062d470`, `updvr` at `0x0062d49c`, and `StdioFile` vtable at `0x0062d5ac`.
- `xrefs_to` confirmed the notice strings, URLs, parse literals, minimap key, PCX literals, base URL, vtable, and successor vtable refs.
- `get_bytes` confirmed the StartupWindow COL/vtable prefix at `0x0062d46c-0x0062d474` and the StdioFile COL/vtable prefix at `0x0062d5a8-0x0062d5b0`.
- `entity_query names` confirmed `0x00650938` as `??_R4StartupWindow@@6B@` and `0x006509d4` as `??_R4StdioFile@@6B@`.
- `decompile 0x00580870` confirmed `RunUpdateCheck` uses the notice class/title pointer slots, browser/news URL, registry value `L"updvr"`, update URL, `version` parse path, `invalid stoi argument` / `stoi argument out of range` throw literals, minimap key, minimap hash-list URL, and minimap manager update path.

## IDA MCP Facts

### String And Vtable Inventory

| Address | Live value / name | Best source role |
| --- | --- | --- |
| `0x0062d418` | `"BaramNoticeWnd_Class"` | Notice HWND class-name literal, reached through pointer slot [UID:000288]. |
| `0x0062d430` | `"Notice"` | Notice HWND title literal, reached through pointer slot [UID:000288]. |
| `0x0062d438` | `"invalid stoi argument"` | Runtime/STL parse-exception literal reached from `RunUpdateCheck` version parsing. |
| `0x0062d450` | `"stoi argument out of range"` | Runtime/STL parse-exception literal reached from `RunUpdateCheck` version parsing. |
| `0x0062d46c` | pointer to `??_R4StartupWindow@@6B@` | StartupWindow vtable complete-object-locator pointer. |
| `0x0062d470` | `??_7StartupWindow@@6B@`, slot value `0x00581d30` | StartupWindow vtable; compiler-emitted from the class declaration. |
| `0x0062d474` | `"http://www.nexustk.com/news/news.asp"` | Embedded browser/news panel URL. |
| `0x0062d49c` | `L"updvr"` | Registry value name for stored update version. This is missing from the current target table. |
| `0x0062d4a8` | `"https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver"` | Remote update-version metadata URL. |
| `0x0062d4e8` | `"minimap"` | Update metadata key for remote minimap hash-list version. |
| `0x0062d4f0` | `"https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt"` | Remote minimap hash-list URL. |
| `0x0062d530` | `"brm_main.pcx"` | Startup notice background PCX. |
| `0x0062d540` | `"brm_st_a.pcx"` | Start/update button normal PCX. |
| `0x0062d550` | `"brm_st_b.pcx"` | Start/update button hover PCX. |
| `0x0062d560` | `"brm_st_c.pcx"` | Start/update button pressed PCX. |
| `0x0062d570` | `"brm_ex_a.pcx"` | Exit/close button normal PCX. |
| `0x0062d580` | `"brm_ex_b.pcx"` | Exit/close button pressed PCX. |
| `0x0062d590` | `"http://www.nexustk.com"` | Top-banner/home link opened by the notice WndProc. |
| `0x0062d5a8` | pointer to `??_R4StdioFile@@6B@` | StdioFile complete-object-locator pointer; should move to [UID:00026L]. |
| `0x0062d5ac` | `??_7StdioFile@@6B@` | StdioFile vtable start; successor boundary. |

### Xref Summary

| Address | Live xref evidence | Meaning |
| --- | --- | --- |
| `0x0062d418` | one data xref from `0x00670260` | The class string is referenced through the writable pointer slot, not directly by code. |
| `0x0062d430` | one data xref from `0x00670264` | The title string is referenced through the writable pointer slot. |
| `0x0062d438` | `0x005810e9` in `StartupWindow_RunUpdateCheck` | Invalid parse throw path after `strtol`/`std::stoi`-style parsing. |
| `0x0062d450` | `0x005810f3` in `StartupWindow_RunUpdateCheck` | Out-of-range parse throw path. |
| `0x0062d470` | `0x005807ed`, raw `0x00580817`, `0x00581d3a` | Constructor/destructor vtable writes. |
| `0x0062d474` | `0x00580b3e` in `RunUpdateCheck` | Browser panel construction URL. |
| `0x0062d49c` | `0x00580bde` in `RunUpdateCheck` | Registry query value `L"updvr"`. |
| `0x0062d4a8` | `0x00580c49` in `RunUpdateCheck` | libcurl update-version fetch. |
| `0x0062d4e8` | `0x00580dab` in `RunUpdateCheck` | `minimap` metadata key lookup. |
| `0x0062d4f0` | `0x00580ed5` in `RunUpdateCheck` | libcurl minimap hash-list fetch. |
| `0x0062d530`-`0x0062d580` | WndProc refs plus raw asset-loader refs | First-paint and raw helper notice PCX loads. |
| `0x0062d590` | `0x00581583` in `UpdateCheckWindowProc` | ShellExecute/top-link URL. |
| `0x0062d5a8` | no direct xrefs to the dword; one xref from it to `??_R4StdioFile@@6B@` | Vtable-prefix data for the following StdioFile vtable. |
| `0x0062d5ac` | StdioFile constructor/destructor/scalar-deleting refs | Successor StdioFile vtable, not StartupWindow data. |

## Heuristic / Inference Reanalysis And Validation

### Range And Split Decision

Best defensible range:

- [UID:00026K] should be `0x0062d418-0x0062d5a8`.
- [UID:00026L] should be `0x0062d5a8-0x0062d5f8`.

Evidence:

- Live bytes at `0x0062d46c-0x0062d474` are `38 09 65 00 30 1d 58 00`, meaning a pointer to `??_R4StartupWindow@@6B@` followed by the single StartupWindow vtable slot `0x00581d30`.
- Live bytes at `0x0062d5a8-0x0062d5b0` are `d4 09 65 00 a0 24 58 00`, meaning a pointer to `??_R4StdioFile@@6B@` followed by the first StdioFile vtable slot `0x005824a0`.
- [UID:00026L] already describes `0x0062d5a8` as the StdioFile RTTI/complete-object-locator pointer, but its current path starts at `0x0062d5ac`, leaving the four-byte prefix inside [UID:00026K].

Rejected alternatives:

- Do not leave [UID:00026K] ending at `0x0062d5ac`. That keeps a StdioFile-owned RTTI pointer in the StartupWindow page.
- Do not split `0x0062d5a8-0x0062d5ac` into a standalone child. It is just the standard MSVC vtable-prefix dword for the following StdioFile vtable and belongs naturally with [UID:00026L].
- Do not reclassify the whole [UID:00026K] range as a mixed non-emitting index after the boundary fix. Once the StdioFile prefix moves out, the remaining source-authored literals and StartupWindow vtable prefix all route to `StartupWindow.cpp`.

Impact:

- This boundary fix is the only structural repair needed.
- It does not change [UID:00026K]'s owner/emitter; it increases confidence by removing the only different-owner tail.

### Notice Class And Title Constants

Best source-facing names:

- `kStartupNoticeWindowClassName` for `"BaramNoticeWnd_Class"`.
- `kStartupNoticeWindowTitle` for `"Notice"`.
- Existing pointer-slot names `g_szBaramNoticeWndClass` and `g_szNoticeTitle` remain acceptable for [UID:000288], but the literal names above are clearer for [UID:00026K].

Evidence:

- The literals have only pointer-slot xrefs from `0x00670260` and `0x00670264`.
- [UID:000288] records those pointer slots feeding `WNDCLASSEXA.lpszClassName`, `RegisterClassExA`, and `CreateWindowExA`.
- Live decompilation of `RunUpdateCheck` uses `lpClassName` and `lpWindowName` in the notice class registration/window creation path.

Rejected alternatives:

- Do not treat these as generic application window strings. The class string is specific to the startup notice HWND.
- Do not make [UID:00026K] own the pointer variables. The writable pointer slots are separately documented in [UID:000288].

### URL, Registry, And Parser Constants

Best source-facing names:

- `kStartupNewsUrl` for `http://www.nexustk.com/news/news.asp`.
- `kStartupUpdateVersionUrl` for `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver`.
- `kStartupRegistryUpdateVersionValue` for `L"updvr"`.
- `kStartupUpdateMinimapKey` for `"minimap"`.
- `kStartupMinimapHashListUrl` for `https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt`.
- `kStartupNoticeHomeUrl` or `kNexusTkHomeUrl` for `http://www.nexustk.com`.

Evidence:

- Live decompilation shows the news URL passed to the embedded BrowserWindow constructor.
- Live decompilation shows `L"updvr"` passed to the registry-query function after opening `Software\\KRU\\NexusTK`.
- Live decompilation shows the update URL passed to libcurl, response parsing for `version` and `minimap`, and then the minimap hash-list URL passed to libcurl if the minimap version differs.
- Live xrefs tie the base/home URL to `0x00581583` in the WndProc top-link path.

Rejected alternatives:

- Do not move the minimap URL/key to [UID:00008H] `MiniMapVersionManager`. StartupWindow owns the remote fetch trigger and URL; MiniMapVersionManager owns persistence and hash-list processing after the fetch.
- Do not move the news/base URLs to [UID:0000HV] `Browser`. Browser owns the COM/OLE hosting implementation, while StartupWindow owns the startup notice content endpoints.
- Do not omit `updvr` from the target contents. It is live in the target range at `0x0062d49c` and has a `RunUpdateCheck` xref at `0x00580bde`.
- Do not treat IDA's `File` label at `0x0062d590` as source-facing. The string is the NexusTK home URL.

### `std::stoi` Exception Literals

Best source-facing interpretation:

- `0x0062d438` and `0x0062d450` are runtime/STL parse-exception message literals emitted in the StartupWindow object context.
- They are evidence that the source used a `std::stoi`-style numeric parse for the remote update `version` value, not deliberate StartupWindow configuration constants.

Evidence:

- Live decompilation shows `strtol`, `_errno`, and exception helper calls:
  - no converted characters -> `sub_5C5E8C("invalid stoi argument")`;
  - `errno == 34` -> `sub_5C5ECC("stoi argument out of range")`.
- Both strings have exactly one xref each, both in `RunUpdateCheck`.

Rejected alternatives:

- Do not make these normal StartupWindow named constants in first-draft C++. They should fall out of using the same standard-library parse path or exception helper.
- Do not split them into a separate runtime page in this pass. They are tiny inline/runtime-adjacent literals in the middle of a compact StartupWindow object-file island, and no separate source-use context is proven.

Impact:

- These literals justify keeping formal C++ blank for this data page and keeping the score below final-audit levels.
- They do not justify changing owner/emitter away from [UID:0000O5].

### PCX Resource Names

Best source-facing names:

- `kStartupNoticeBackgroundPcx` = `brm_main.pcx`.
- `kStartupNoticeStartButtonNormalPcx` = `brm_st_a.pcx`.
- `kStartupNoticeStartButtonHoverPcx` = `brm_st_b.pcx`.
- `kStartupNoticeStartButtonPressedPcx` = `brm_st_c.pcx`.
- `kStartupNoticeExitButtonNormalPcx` = `brm_ex_a.pcx`.
- `kStartupNoticeExitButtonPressedPcx` = `brm_ex_b.pcx`.

Evidence:

- Live xrefs show each PCX string referenced by the WndProc and by the raw asset-loader helper.
- [UID:0001RO] records `baramst.dat` package provenance for exactly these six PCX assets.

Rejected alternatives:

- Do not assign these string literals to [UID:0000K3] `ImageLoaders`. StartupWindow names and requests the notice assets; ImageLoaders owns PCX decoding.
- Do not promote adjacent `brm_n_*` / `brm_o_*` DAT entries into this target. They are not in [UID:00026K] and [UID:0001RO] leaves them unpromoted until raw helper evidence proves use.

### Vtable And RTTI Data

Best source-facing treatment:

- Keep the StartupWindow COL pointer/vtable slot in [UID:00026K] as `source-declared/generated-binary`.
- Do not hand-author the vtable in formal C++.
- Move the StdioFile COL pointer at `0x0062d5a8` to [UID:00026L].

Evidence:

- `0x0062d46c` points to `??_R4StartupWindow@@6B@`; `0x0062d470` is `??_7StartupWindow@@6B@`.
- `0x0062d5a8` points to `??_R4StdioFile@@6B@`; `0x0062d5ac` is `??_7StdioFile@@6B@`.
- Constructor/destructor xrefs to `0x0062d470` are StartupWindow-owned; successor xrefs to `0x0062d5ac` are StdioFile-owned.

Rejected alternatives:

- Do not model `0x0062d470` as a source-authored function pointer table. It is a compiler-emitted vtable from the class declaration.
- Do not let the StdioFile RTTI pointer remain in the StartupWindow page for convenience; boundary correctness matters here because the neighbor page is already a mixed vtable index.

### Source Placement

Best placement: [UID:0000O5] `StartupWindow` / `NexusTK/app/StartupWindow.cpp`.

Evidence:

- [UID:0001IO] documents the constructor, `RunUpdateCheck`, WndProc, raw notice helpers, curl callback, parse helpers, and destructor all in the StartupWindow executable neighborhood.
- [UID:0000O5] and `proposed-source-tree.md` place StartupWindow in `NexusTK/app/StartupWindow.cpp`.
- Live xrefs for every remaining [UID:00026K] literal after the boundary fix lead to `RunUpdateCheck`, WndProc, raw notice asset setup, or StartupWindow constructor/destructor vtable writes.

Rejected alternatives:

- `MiniMapVersionManager.cpp`: owns local minimap state/hash persistence, not the remote startup fetch URL/key.
- `Browser.cpp`: owns browser implementation, not the StartupWindow news URL constant.
- `ImageLoaders.cpp` / resource docs: own decoding/resource packaging, not the source literals used by StartupWindow.
- `StdioFile.cpp`: only owns the four-byte tail that should move into [UID:00026L].
- `CANONICAL_OWNER:NONE` with multiple emitters: unnecessary after the StdioFile tail is removed; no remaining literal has a proven independent source-use context outside StartupWindow.

## First-Draft C++ Recommendation

Do not populate formal C++ in [UID:00026K].

Reason:

- The range is read-only data, not a method body.
- The StartupWindow vtable/COL data must be regenerated by the compiler from the `StartupWindow` class declaration and virtual destructor, not hand-authored as a pointer table.
- The notice class/title pointer variables are already covered by [UID:000288]; if formal C++ is added there, it should emit the initialized pointer declarations or equivalent source-level variables.
- The URLs, registry value, minimap key, and PCX names should appear in the `StartupWindow.cpp` method/helper source when [UID:0001IO] and exact helper children get final C++, or as file-local constants on an exact constants page if the supervisor later creates one.
- The two `std::stoi` exception strings should not be emitted as StartupWindow constants. They are runtime/STL parse-path literals and should fall out of the chosen parse implementation.

Recommended source-facing constants for future StartupWindow source, but not to paste into [UID:00026K]'s formal block:

```cpp
static const char kStartupNoticeWindowClassName[] = "BaramNoticeWnd_Class";
static const char kStartupNoticeWindowTitle[] = "Notice";
static const char kStartupNewsUrl[] = "http://www.nexustk.com/news/news.asp";
static const wchar_t kStartupRegistryUpdateVersionValue[] = L"updvr";
static const char kStartupUpdateVersionUrl[] =
    "https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver";
static const char kStartupUpdateMinimapKey[] = "minimap";
static const char kStartupMinimapHashListUrl[] =
    "https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt";
static const char kStartupNoticeBackgroundPcx[] = "brm_main.pcx";
static const char kStartupNoticeStartButtonNormalPcx[] = "brm_st_a.pcx";
static const char kStartupNoticeStartButtonHoverPcx[] = "brm_st_b.pcx";
static const char kStartupNoticeStartButtonPressedPcx[] = "brm_st_c.pcx";
static const char kStartupNoticeExitButtonNormalPcx[] = "brm_ex_a.pcx";
static const char kStartupNoticeExitButtonPressedPcx[] = "brm_ex_b.pcx";
static const char kStartupNoticeHomeUrl[] = "http://www.nexustk.com";
```

If the supervisor prefers a constants-only emitting page later, create an exact source constants child after the boundary correction instead of putting a partial constants draft into the mixed vtable/string [UID:00026K] page.

## Score And Metadata Recommendations

### [UID:00026K]

Recommended changes:

- Rename/range-correct to `0x0062d418-0x0062d5a8.StartupWindowReadOnlyData`.
- `COMPLETION:88`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000O5`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000O5`
- Keep formal `RECONSTRUCTION_CPP` blank with the explicit reason above.

Score rationale:

- Completion rises because the page can now list all live strings including `updvr`, classify the vtable/COL prefix, resolve the `std::stoi` literals, define source-facing names for all URL/resource constants, and correct the StdioFile tail boundary.
- Confidence rises because live IDA MCP confirmed the current string inventory, xrefs, decompilation evidence, vtable prefix bytes, RTTI names, and successor boundary.
- Confidence stays below `95` because final source spelling for the constants is inferred, not recovered, and raw notice helper exact children are still not promoted.

### [UID:00026L]

Recommended support boundary change:

- Rename/range-correct to `0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData`.
- Keep `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
- Add `0x0062d5a8-0x0062d5ac` as the StdioFile COL pointer in its observed contents.

### [UID:00026J]

No target-doc change is required by this assignment, but the current shared coverage row is stale. Keep the existing doc metadata (`87/92`, non-emitting mixed index) and update the coverage row if the supervisor applies the local block replacement below.

## Support Docs To Update

Supervisor should update:

- [UID:00026K] target page:
  - change range/path to `0x0062d418-0x0062d5a8`;
  - add `0x0062d46c` StartupWindow COL pointer;
  - add `0x0062d49c` `L"updvr"`;
  - change end-boundary text to say `0x0062d5a8` is the StdioFile COL pointer and successor [UID:00026L] now starts there;
  - add the explicit no-formal-C++ policy.

- [UID:00026L] successor page:
  - change range/path to `0x0062d5a8-0x0062d5f8`;
  - include the StdioFile COL pointer at `0x0062d5a8`;
  - update boundary and score rationale text to remove "just before this page" wording.

- [UID:0000O5] `StartupWindow` file:
  - add [UID:00026K] as the source constants/vtable-prefix rdata page;
  - record source-facing constant names above;
  - note that `updvr` is inside [UID:00026K] at `0x0062d49c`.

- [UID:0000DZ] `StartupWindow` class:
  - add `0x0062d46c` COL pointer plus `0x0062d470` single-slot vtable evidence;
  - keep final class C++ blank until raw helper and member names are final-source quality.

- [UID:0001IO] `StartupWindowUpdateCheck`:
  - add or refresh `updvr` exact address/xref;
  - record that `invalid stoi argument` and `stoi argument out of range` are parse-exception literals, not source configuration constants.

- [UID:0001RO] startup update notice resources:
  - add exact [UID:00026K] address `0x0062d49c` for the `updvr` registry value string.

- [UID:000288] notice pointer data:
  - no score change required; optional wording can say the pointed-to strings live in the corrected [UID:00026K] range `0x0062d418-0x0062d5a8`.

- [UID:0001Z7] `.rdata` section:
  - optional child inventory update for the corrected [UID:00026K]/[UID:00026L] boundary.

No [UID:0000SW] `g_useEpfAssets` metadata change is required from this assignment. It remains relevant StartupWindow support evidence but is not part of [UID:00026K].

## Supervisor-Owned Coverage Rows

Do not edit `by-memory/-coverage-report.md` directly from B001. Replace the local [UID:00026J]-[UID:00026L] block with the following exact rows after renaming/range-correcting [UID:00026K] and [UID:00026L].

Placement context: immediately after [UID:00026I] `NetworkAndAudioReadOnlyData` and before [UID:00026M] `SystemMessageReadOnlyData`.

```markdown
    - [UID:00026J][0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData](by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md) 0x0062cfd8-0x0062d418 | mixed-rdata index | SpellInventoryMacroReadOnlyData : ignored : 87% : very strong : Non-emitting mixed `.rdata` index starting at the `SpellInventoryPane` primary RTTI locator after Batch 225; documents SpellInventoryPane/NewSpellInventoryPane/SpellInventoryPane2 vtables, spell inventory resource strings/constants, exact MacroEditControlPane vtable child, macro hotkey/mode strings, and StartupWindow successor boundary at `0x0062d418`. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/final C++ because source emission belongs to exact spell inventory and MacroDialogs children.
    - [UID:00026K][0x0062d418-0x0062d5a8.StartupWindowReadOnlyData](by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md) 0x0062d418-0x0062d5a8 | vtable/string-data | StartupWindowReadOnlyData : reconstructable : 88% : very strong : B001 2026-06-17 source-quality reanalysis keeps StartupWindow owner/emitter [UID:0000O5], corrects the end from `0x0062d5ac` to `0x0062d5a8` so the following `StdioFile` COL pointer moves to [UID:00026L], and live IDA MCP confirms notice class/title strings, `std::stoi` parse exception literals, StartupWindow COL/vtable prefix at `0x0062d46c-0x0062d474`, news/update/minimap URLs, registry value `updvr`, notice PCX names, base URL, executable xrefs from RunUpdateCheck/WndProc/raw asset setup, and formal C++ intentionally blank because vtable/runtime literals and source constants should be regenerated through StartupWindow declarations and exact method/global pages.
    - [UID:00026L][0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData](by-memory/0x0062d5a8-0x0062d5f8.StdioFileStringIterReadOnlyData.md) 0x0062d5a8-0x0062d5f8 | mixed-rdata index | StdioFileStringIterReadOnlyData : ignored : 89% : very strong : Non-emitting mixed `.rdata` index corrected to begin at the `StdioFile` complete-object-locator pointer `0x0062d5a8`, followed by the StdioFile vtable, whitespace/LF/CR literal bytes, `0xffffffff` parser/string sentinel, StringIter RTTI/vtable bytes, and the `SystemMessagePane` successor boundary at `0x0062d5f8`; keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/final C++ because the page crosses StdioFile, string-utility, StringIter, and sentinel ownership.
```

## Validation Commands For Supervisor

After applying the recommended by-memory renames/range edits, support-doc edits, and coverage rows:

> Executable block R001 was removed from this report and preserved verbatim in [00026K-startupwindow-rdata-source-quality-removed.md](00026K-startupwindow-rdata-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor does not rename the files in the same pass, validate the current paths first, then run the renamed-path scans after the move.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B001/research/00026K-startupwindow-rdata-source-quality.md`

No other files were changed by B001.

## Remaining Follow-Up

- Promote exact raw StartupWindow notice helper children in `0x005815b0-0x00581b7f` when a split-capable executable pass is assigned. That work affects method-level final C++, not the [UID:00026K] data-owner decision.
- If a future constants-only source page is desired, create an exact StartupWindow constants child after the `0x0062d5a8` boundary repair rather than putting partial constants into [UID:00026K]'s formal C++ block.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00026K-startupwindow-rdata-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"00026K"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00026K-startupwindow-rdata-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00026K-startupwindow-rdata-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00026K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
