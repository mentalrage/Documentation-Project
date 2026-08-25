** TARGET-REPORT-UID:0001JU **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Report: [UID:0001JU] TextFilterAndSanitizer Source Quality

## Finalized Report / Current Recommendation

Assignment `B003-implement-text-filter-and-sanitizer-source-quality-0001JU-mcp-20260623` has completed the supervisor-accepted implementation callback for the MCP-backed source-quality revision of [UID:0001JU] `by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md`.

Current implemented disposition:

- Keep [UID:0001JU] owned/emitted by [UID:0000OO] `TextFilter`, with `CANONICAL_OWNER:0000OO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OO`, blank emitter position, and blank aggregate `RECONSTRUCTION_CPP`.
- [UID:0001JU] was raised from `86/86` to `88/90` after incorporating current IDA MCP session `ff68e691` evidence, exact bytes/SHA16 values, padding, vtable/global facts, caller sets, and the current code-entry gate analysis. Prior session `261fb29b` is stale and superseded.
- Do not add aggregate C++ to [UID:0001JU]. The range is a source-cluster aggregate over a constructor, destructor body, sanitizer helper, scalar deleting destructor, and padding. Emitting one C++ block on the aggregate would either duplicate child/source output or harden compiler-generated destructor artifacts as handwritten source.
- The accepted split package was executed before source C++ was added:
  - [UID:00041H] `by-memory/0x00595760-0x00595795.TextFilterConstructor.md`.
  - [UID:00041I] `by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md`.
  - [UID:00041J] `by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md`.
  - [UID:00041K] `by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md`.
  - Preserve padding `0x00595795-0x005957a0`, `0x005957b1-0x005957c0`, `0x005958ca-0x005958d0`, and existing ignored tail padding `0x005958fe-0x00595900` as non-source spans linked from the parent/coverage inventory, not as source-emitting children.
- First-draft C++ is now present on the constructor child, the non-deleting destructor-body child as the single source representation of `TextFilter::~TextFilter()`, the sanitizer child, and the exact storage child [UID:0002XT] for `g_pTextFilter = nullptr`. The scalar deleting destructor child remains `RECONSTRUCTABLE:FALSE`, ownerless, blank-C++, compiler-generated glue.
- Refine source placement to keep `NexusTK/ui/controls/TextFilter.cpp` as the best current source route. `util/TextFilter.cpp` remains a documented rejected/low-confidence alternative because no recovered source path, symbol, or non-UI consumer proves a generic utility source root.
- Corrected stale support text that said the current source-C++ blocker was the old 95+ gate or that `g_pTextFilter` was initialized to `0xffffffff`. Current MCP bytes show `0x0067adc8` is `00 00 00 00`, and the storage child now emits `TextFilter *g_pTextFilter = nullptr;`.

By-* docs were edited only under the accepted implementation callback scope and scoped validators. B003 did not edit generated/project-level files manually, did not edit IDA DB state or tool process state, and did not edit any `-coverage-report.md` file. Leases were used only for the existing-doc edit/validator batch and were released; the final lease report shows no active leases.

## Assignment And Current State

- Agent: B003.
- Target: [UID:0001JU] `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00595760-0x005958fe.TextFilterAndSanitizer.md`.
- Current metadata: `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000OO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OO`, blank emitter position, blank `RECONSTRUCTION_CPP`.
- Current owner route: [UID:0000OO] `by-file/TextFilter.md`, projected to `NexusTK/ui/controls/`.
- Related pages checked:
  - [UID:0000OO] `by-file/TextFilter.md`.
  - [UID:0000EQ] `by-class/TextFilter.md`.
  - [UID:0000TK] `by-global/SanitizeWideTextForChat.md`.
  - [UID:0000SG] `by-global/g_pTextFilter.md`.
  - [UID:0002XT] `by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md`.
  - [UID:0001YY] `by-type/by-vtable/TextFilterVtable.md`.
  - [UID:0002OZ] `by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md`.
  - [UID:0001JT] `by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md`.
  - `by-project-structure/proposed-source-tree.md`.
  - Current memory/file/class/global/vtable coverage rows.
  - Relevant executed/archived B-agent reports that reference `SanitizeWideTextForChat` and `g_pTextFilter`.

## MCP Session And Health

IDA MCP was available and used. This report must not be treated as a fallback-only report.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Active session/database used for this revision: `ff68e691`.
- Stale session explicitly superseded: `261fb29b`.
- Safe flow used: `initialize` -> `tools/list` -> bounded `tools/call`.
- Current health sanity check during revision:
  - `server_health(database='ff68e691')` returned HTTP 200 with `status:"ok"`.
  - IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
  - Module: `NexusTK.exe`.
  - Image base: `0x400000`.
  - Auto-analysis ready: `true`.
  - Hex-Rays ready: `true`.
  - Strings cache ready: `true`, size `2067`.
  - `lookup_funcs(database='ff68e691', queries=['0x005957c0'])` returned `sub_5957C0`, size `0x10a`.
- `idb_list` records active session `ff68e691`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, backend `worker`, and worker PID `14256`.
- Schema note: current `ff68e691` decompile/disasm tools require singular `addr`; `get_bytes` requires `regions`; `get_int` requires `queries` with `ty`. Two stale-schema requests were rejected with invalid-parameter errors before the corrected bounded calls. Those were request-shape errors, not MCP unavailability.

MCP tool families used in the current `ff68e691` revision: `idb_list`, `server_health`, `tools/list`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`, `get_int`, and `entity_query`. Queries were bounded to the target functions, direct globals/vtable cells, and representative startup/shutdown callers.

## Exact Range And Byte Evidence

MCP confirms the target is four modeled functions with padding gaps and a successor `TextPad` function at `0x00595900`.

| Range | Size | SHA16 from MCP bytes | Role | Boundary result |
| --- | ---: | --- | --- | --- |
| `0x00595760-0x00595795` | `0x35` / 53 bytes | `0de8157fbaa29517` | `TextFilter::TextFilter` constructor | Modeled function starts at `0x00595760`; no function at exclusive end `0x00595795`. |
| `0x00595795-0x005957a0` | `0x0b` / 11 bytes | `3682c0a625150501` | padding | All `0xcc`. |
| `0x005957a0-0x005957b1` | `0x11` / 17 bytes | `c020601bb4db048c` | non-deleting destructor-like body | Modeled function starts at `0x005957a0`; no function at exclusive end `0x005957b1`. |
| `0x005957b1-0x005957c0` | `0x0f` / 15 bytes | `54cc9dd9593316e8` | padding | All `0xcc`. |
| `0x005957c0-0x005958ca` | `0x10a` / 266 bytes | `d06aa427134dc3d3` | `SanitizeWideTextForChat` | Modeled function starts at `0x005957c0`; no function at exclusive end `0x005958ca`. |
| `0x005958ca-0x005958d0` | `0x06` / 6 bytes | `33cc4a00a0f04735` | padding | All `0xcc`. |
| `0x005958d0-0x005958fe` | `0x2e` / 46 bytes | `decc5293dda7446a` | scalar deleting destructor wrapper | Modeled function starts at `0x005958d0`; no function at exclusive end `0x005958fe`. |
| `0x005958fe-0x00595900` | `0x02` / 2 bytes | `e3966e3275be536a` | tail padding | All `0xcc`; [UID:0000VN] already owns this ignored alignment span before [UID:0001JV] `TextPad`. |

Exact leading/body bytes checked:

- Constructor bytes start `55 8b ec 51 8d 41 04 89 4d fc 85 c0 74 14 83 c0 fc a3 c8 ad 67 00 ...` and contain two writes to `0x0067adc8` plus two vtable stores to `0x0062e188`.
- Non-deleting destructor body bytes are `c7 01 88 e1 62 00 c7 05 c8 ad 67 00 00 00 00 00 c3`.
- Scalar deleting destructor bytes are `55 8b ec f6 45 08 01 56 8b f1 c7 06 88 e1 62 00 c7 05 c8 ad 67 00 00 00 00 00 74 0b 6a 04 56 e8 32 1c 03 00 83 c4 08 8b c6 5e 5d c2 04 00`.

## Function Behavior Evidence

### Constructor `0x00595760-0x00595795`

MCP `lookup_funcs` reports `sub_595760`, size `0x35`. Decompilation models an optimized `__thiscall` body that stores the singleton pointer and installs `TextFilter::vftable`. The disassembly is the stronger source for the source-level interpretation:

- `0x00595764` computes `ecx + 4`, then the decompiler emits a strange `this == -4` branch. This is compiler/lowering evidence, not source code to reproduce literally.
- `0x00595771` stores `eax` into `0x0067adc8` (`g_pTextFilter`).
- `0x00595778` stores `0x0062e188` into `[ecx]`.
- The alternate branch at `0x00595782` clears `g_pTextFilter` and also writes the vtable. This branch is likely an optimized constructor/base-adjustment artifact and should be documented, not source-authored as `MEMORY[0xFFFFFFFC]`.
- `xrefs_to 0x00595760` reports one code xref at `0x004f615f` inside startup `sub_4F5FB0`.
- Startup disassembly around `0x004f6148-0x004f6170` shows allocation of 4 bytes, `mov ecx,eax`, then `call sub_595760`, proving a tiny startup singleton object.

Source-facing interpretation: `TextFilter::TextFilter()` publishes `this` to `g_pTextFilter`; the vtable write and `-4` modeled branch are compiler details.

### Non-deleting destructor body `0x005957a0-0x005957b1`

MCP `lookup_funcs` reports `sub_5957A0`, size `0x11`.

- Decompilation: writes `TextFilter::vftable` to `*this` and clears `0x0067adc8`.
- Disassembly is exactly one vtable store, one singleton clear, and `retn`.
- `xrefs_to 0x005957a0` reports zero direct code xrefs.
- The only apparent route evidence is the vtable base immediate in the first instruction, not an active caller.

Source-facing interpretation: this is destructor-body/lowering evidence. If exact children are created, this range should not emit a separate second source destructor if the scalar deleting destructor child also represents the same `~TextFilter` source body.

### Sanitizer `0x005957c0-0x005958ca`

MCP `lookup_funcs` reports `sub_5957C0`, size `0x10a`. Decompilation shows a two-stack-argument helper that scans UTF-16 code units in place:

- Prototype recovered by decompiler: `void __stdcall sub_5957C0(int text, unsigned int textLength)`.
- It loops while index `< textLength`.
- It stops at NUL.
- It preserves CR (`0x000d`), LF (`0x000a`), printable ASCII `0x20-0x7f`, and a fixed Latin-1 lowercase accent allowlist:
  `0x00e9`, `0x00e8`, `0x00e0`, `0x00f9`, `0x00f4`, `0x00ee`, `0x00eb`, `0x00ef`, `0x00fb`, `0x00fa`, `0x00e2`, `0x00e7`.
- It writes `0x003f` (`?`) for any other nonzero code unit.
- There are no callees and no strings.
- The callee does not read `ecx`; several callers load `g_pTextFilter` into `ecx` before the call, but the body is not a `thiscall` member and has no `TextFilter *` stack parameter. The `retn 8` stack cleanup confirms exactly two stack arguments.

Best source-facing signature:

```cpp
void SanitizeWideTextForChat(wchar_t *text, unsigned int textLength);
```

The existing `unsigned short *` documentation remains behaviorally equivalent for Windows UTF-16, but `wchar_t *` is the better source-facing type because callers operate on wide-character buffers and prior accepted chat/article reports write this helper as a wide-text sanitizer. Keep `unsigned int` for the length because the binary uses a 32-bit unsigned loop bound and `retn 8`.

### Scalar deleting destructor `0x005958d0-0x005958fe`

MCP `lookup_funcs` reports `sub_5958D0`, size `0x2e`.

- Decompilation writes `TextFilter::vftable`, clears `g_pTextFilter`, and calls `sub_5C7526(Block)` when the deleting flag has bit `1` set.
- Disassembly:
  - `0x005958d3` tests `[ebp+arg_0] & 1`.
  - `0x005958da` writes vtable `0x0062e188`.
  - `0x005958e0` clears `0x0067adc8`.
  - `0x005958ef` calls delete helper `0x005c7526` after pushing size `4` and `this`.
  - Returns with `retn 4`.
- `xrefs_to 0x005958d0` reports the vtable data xref at `0x0062e188`.
- `callees 0x005958d0` reports the delete helper `0x005c7526`.
- Shutdown disassembly around `0x004f6668-0x004f6690` reads `g_pTextFilter`, tests it, pushes deleting flag `1`, and calls through the vtable slot. This proves normal teardown reaches the scalar deleting destructor indirectly through the singleton vtable, not through a direct rel32 call.

Source-facing interpretation: the underlying handwritten source is `TextFilter::~TextFilter()` clearing the singleton. The deleting flag, size push, and delete helper call are compiler-generated scalar deleting destructor mechanics and should not be emitted as handwritten source.

## Xrefs, Callers, And Negative Reachability

### Direct target-function xrefs

- `xrefs_to 0x00595760`: one code xref, `0x004f615f` in startup `sub_4F5FB0`.
- `xrefs_to 0x005957a0`: zero refs. Preserve this caveat in docs; this modeled body is destructor-lowering evidence rather than a directly routed source function.
- `xrefs_to 0x005957c0`: 14 code xrefs across 12 functions:
  - `0x0047762b` and `0x00477641` in `sub_477590`.
  - `0x0047de2c` and `0x0047de3f` in `sub_47DCB0`.
  - `0x0053fe34` in `sub_53FDC0`.
  - `0x0059e4ae` in `sub_59E3D0`.
  - `0x005ae0cf` in `sub_5AE060`.
  - `0x005b16af` in `sub_5B1640`.
  - `0x005b1acf` in `sub_5B1A60`.
  - `0x005b1fef` in `sub_5B1F80`.
  - `0x005b23ff` in `sub_5B2390`.
  - `0x005b3700` in `sub_5B3670`.
  - `0x005b3ad0` in `sub_5B3A40`.
  - `0x005b42e1` in `sub_5B4260`.
- `xrefs_to 0x005958d0`: one data xref at `0x0062e188`, the `TextFilter` vtable slot.

### Singleton pointer xrefs

`xrefs_to 0x0067adc8` reports 19 data refs:

- Article caller refs: `0x00477617`, `0x00477630`.
- Mail caller refs: `0x0047de1d`, `0x0047de31`.
- Shutdown read: `0x004f667d` in `sub_4F6490`.
- Profile caller ref: `0x0053fe22`.
- Constructor writes: `0x00595771`, `0x00595784`.
- Destructor clears: `0x005957a6`, `0x005958e0`.
- Other sanitizer caller refs: `0x0059e4a7`, `0x005ae0c8`, `0x005b16a8`, `0x005b1ac8`, `0x005b1fe8`, `0x005b23f8`, `0x005b36f9`, `0x005b3ac9`, `0x005b42da`.

These xrefs prove the singleton/global relationship but not caller-feature ownership. The submit/dialog callers consume the helper; they do not own the TextFilter file or global.

### Vtable xrefs

- `xrefs_to 0x0062e188`: four refs at `0x00595778`, `0x0059578b`, `0x005957a0`, and `0x005958da`.
- `xrefs_to 0x0062e184`: zero direct xrefs; it is the RTTI-adjacent complete-object-locator pointer immediately before the vtable base.
- `xrefs_to 0x0062e18c`: zero direct xrefs; it is the next `TextPad` metadata boundary, not part of `TextFilter`.

## Vtable, RTTI, Global, And Data Evidence

MCP `get_bytes`/`get_int` results:

- `0x0062e184-0x0062e18c` bytes: `18 15 65 00 d0 58 59 00`, SHA16 `50df7549f68dce6b`.
- `get_int 0x0062e184`: `0x00651518`, the `??_R4TextFilter@@6B@` complete-object-locator pointer. This corrects/supersedes any support-page typo that names `0x00651718`.
- `get_int 0x0062e188`: `0x005958d0`, the scalar deleting destructor.
- `get_int 0x0062e18c`: `0x006517b4`, the next `TextPad` RTTI-adjacent word and exclusive boundary.
- `0x0067adc8-0x0067adcc` bytes: `00 00 00 00`, SHA16 `df3f619804a92fdb`.
- `get_int 0x0067adc8`: `0x00000000`.

This means current support text and coverage text saying `g_pTextFilter` has a static image value of `0xffffffff` are stale. The source-facing declaration should be a zero-initialized/null singleton pointer, not an initialized sentinel:

```cpp
TextFilter *g_pTextFilter = nullptr;
```

MCP name/type evidence:

- `entity_query names *TextFilter*` returns decorated vtable/RTTI names for `TextFilter` and `Singleton<TextFilter>`:
  - `??_7TextFilter@@6B@` at `0x0062e188`.
  - `??_R4TextFilter@@6B@` at `0x00651518`.
  - `??_R0?AVTextFilter@@@8` and related `TextFilter` RTTI names.
  - `??_R13?0A@EA@?$Singleton@VTextFilter@@@@8` and related `Singleton<TextFilter>` RTTI names.
- `entity_query names *Sanit*` returns no source symbol.
- `type_query *TextFilter*`, `*Sanit*`, and `*Singleton*TextFilter*` return no UDT/source type.
- `list_globals *TextFilter*` confirms RTTI/vtable names but not source-facing function names.

Inference: `TextFilter` and `Singleton<TextFilter>` are IDA-backed class/template names. `SanitizeWideTextForChat` is a project-level recovered source-facing helper name, not a recovered IDA symbol; it is nevertheless the best current name because it matches behavior and is already used consistently by accepted chat/article support reports.

## Source Placement Reanalysis

### Accepted route: `NexusTK/ui/controls/TextFilter.cpp`

Evidence for keeping the current [UID:0000OO] `TextFilter` file route:

- `by-file/TextFilter.md` is already a valid source root with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`.
- `by-project-structure/proposed-source-tree.md` lists `ui/controls/TextFilter.cpp` beside `TextEditPane.cpp` and `TextEditControlPane.cpp`.
- The code is address-adjacent to the text edit/text pad support block, and [UID:0001JT] already keeps the `TextFilter` child split from `TextEditPane` support objects.
- The class has `TextFilter`/`Singleton<TextFilter>` RTTI, a one-slot class vtable, startup construction, and application shutdown destruction. This is not a caller-local helper.
- The sanitizer call sites are all user-interface text-entry/submission flows: article, mail, profile, party-search, spell string input, say-target variants, say, chat, and shout.
- Existing accepted reports use `SanitizeWideTextForChat` as a shared dependency of input/dialog submit paths, not as a packet, socket, or chat-pane owner.

### Rejected or lower-confidence placements

1. `TextEditPane.cpp`:
   - Rejected. Physical adjacency is real, but the constructor is reached from startup, shutdown is via `g_pTextFilter`, and sanitizer callers span many non-editor features. [UID:0001JT] correctly treats `TextFilter` as a split child, not a TextEditPane support method.

2. `util/TextFilter.cpp` or generic text utility source:
   - Rejected as the primary route for now. The sanitizer is broad, but there is no recovered source path, symbol, import, or non-UI utility consumer proving a utility folder. The function enforces client user-text policy before submission; it is not a generic Unicode library routine.
   - Keep as a residual caveat because original folder names are not recovered and the helper is used beyond the nearest text-edit controls.

3. Caller-feature files such as NewArticleDialog, NewMailDialog, ProfileDialog, PartySearchEditPane, SayInputPanes, SayInputPane, Chatting, or ShoutInputPane:
   - Rejected. Callers consume the shared sanitizer. Their references prove call flow and argument shape, not ownership.

4. Packet/socket/network modules:
   - Rejected. The sanitizer executes before packet serialization in several callers, but it does not construct packets, touch socket state, or own protocol fields.

5. No-owner/non-emitting:
   - Rejected. The class/global/vtable/helper cluster has a coherent owner file, a valid emitter route, and active source behavior. Remaining folder/signature uncertainty is not enough to make it ownerless.

## Source-Facing Names, Signatures, And Types

Recommended source-facing names:

- Class: `TextFilter`.
- Base/template context: likely `Singleton<TextFilter>` from RTTI; exact header declaration remains unresolved, so do not overstate the final inheritance/source header until class support docs are updated.
- Global pointer: `g_pTextFilter`.
- Sanitizer: `SanitizeWideTextForChat`.
- Constructor: `TextFilter::TextFilter()`.
- Destructor source body: `TextFilter::~TextFilter()`, clearing the singleton.
- Scalar deleting destructor: compiler-generated wrapper, no handwritten source function name.

Recommended signatures/decls:

```cpp
class TextFilter
{
public:
    TextFilter();
    virtual ~TextFilter();
};

extern TextFilter *g_pTextFilter;

void SanitizeWideTextForChat(wchar_t *text, unsigned int textLength);
```

The final class declaration should likely include `Singleton<TextFilter>` once the support docs decide the exact public declaration shape. Do not emit a decompiler-shaped constructor branch for `this == -4`, do not invent a `TextFilter *` sanitizer parameter, and do not model the sanitizer as a virtual method.

Rejected names/signatures:

- `sub_595760`, `sub_5957A0`, `sub_5957C0`, `sub_5958D0`: IDA labels only.
- `NormalizeChatText` / `ApplyOutboundChatFilter`: useful older local descriptions from caller-centered reports, but superseded by the established shared helper page and broader caller set.
- `g_chatTextFilter`: older local placeholder; superseded by [UID:0000SG] `g_pTextFilter`.
- `TextFilter::SanitizeWideTextForChat(...)` or `SanitizeWideTextForChat(TextFilter *, wchar_t *, int)`: rejected by current MCP decompilation/disassembly because the callee has two stack args, does not read `ecx`, and stack-cleans 8 bytes.
- Treating `SanitizeWideTextForChat` as a vtable method: rejected; [UID:0001YY] has one slot only, at `+0x00`, pointing to the scalar deleting destructor.

## C++ Readiness And No-Code Proof

### [UID:0001JU] aggregate C++ decision

Keep [UID:0001JU] aggregate C++ blank.

Target-specific no-code proof:

- The range is not one source function. It contains four modeled functions plus three internal padding gaps and tail alignment before `TextPad`.
- One contained range is a free helper (`SanitizeWideTextForChat`), while the other executable ranges are class lifecycle/destructor lowering for `TextFilter`.
- The scalar deleting destructor is compiler-generated wrapper code. Emitting its flag test, size push, and delete-helper call as handwritten source would be wrong.
- The non-deleting destructor-like body has zero direct code xrefs. It is evidence for the source destructor body, not proof of a separate source method to emit in addition to the scalar deleting destructor.
- The source code that should exist belongs on exact child/global/class pages and through the [UID:0000OO] file route. Aggregate C++ would either duplicate child output or mix function bodies into a non-source aggregate.

### First-draft C++ ready after split/support sync

Sanitizer helper first-draft C++ is safe on an exact child/global helper page:

```cpp
void SanitizeWideTextForChat(wchar_t *text, unsigned int textLength)
{
    for (unsigned int i = 0; i < textLength; ++i) {
        wchar_t ch = text[i];
        if (ch == 0)
            break;

        if (ch == L'\n' || ch == L'\r' || (ch >= L' ' && ch <= 0x7f))
            continue;

        switch (ch) {
        case 0x00e9:
        case 0x00e8:
        case 0x00e0:
        case 0x00f9:
        case 0x00f4:
        case 0x00ee:
        case 0x00eb:
        case 0x00ef:
        case 0x00fb:
        case 0x00fa:
        case 0x00e2:
        case 0x00e7:
            continue;
        default:
            text[i] = L'?';
            break;
        }
    }
}
```

Global declaration first-draft C++ is safe on [UID:0000SG]/[UID:0002XT] after stale initializer text is corrected:

```cpp
TextFilter *g_pTextFilter = nullptr;
```

Lifecycle source first-draft C++ is behaviorally safe, but placement must avoid duplicate destructor output:

```cpp
TextFilter::TextFilter()
{
    g_pTextFilter = this;
}

TextFilter::~TextFilter()
{
    g_pTextFilter = nullptr;
}
```

If exact destructor children are created, choose one source representation for `~TextFilter()` and mark the scalar deleting wrapper as compiler-generated/no-code. Do not add separate handwritten C++ to both destructor ranges.

Vtable and RTTI data C++ remains blank. The vtable/data bytes should be regenerated by the final class declaration and compiler.

## Concrete Split Execution Package

This report now recommends executing the child split in the first accepted implementation callback. Do not use a no-split implementation plan if the supervisor accepts this report. The parent [UID:0001JU] remains the aggregate/inventory page with blank C++; exact child pages carry source-bearing code or compiler-glue no-code disposition.

Validator-created UIDs are now known from the accepted implementation callback:

- [UID:00041H] for `by-memory/0x00595760-0x00595795.TextFilterConstructor.md`.
- [UID:00041I] for `by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md`.
- [UID:00041J] for `by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md`.
- [UID:00041K] for `by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md`.

Implementation handling after child creation:

- Each new child was validated first so the validator allocated real UIDs.
- Parent/support documentation and supervisor-owned coverage text in this report now use the real validator-assigned UIDs.
- Do not create standalone by-memory child pages for internal padding spans. Preserve them as parent inventory rows and coverage rows tied to [UID:0000VN] `by-memory/-ignored.md` / padding evidence. The existing `0x005958fe-0x00595900` tail padding row remains [UID:0000VN].

### Proposed Child Metadata

| Proposed child path | Initial metadata | C++/no-code disposition |
| --- | --- | --- |
| `by-memory/0x00595760-0x00595795.TextFilterConstructor.md` | `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000EQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EQ`, blank emitter position | Emits `TextFilter::TextFilter()` first-draft C++ through [UID:0000EQ] to [UID:0000OO]. |
| `by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md` | `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000EQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EQ`, blank emitter position | Emits the single source representation of `TextFilter::~TextFilter()` through [UID:0000EQ] to [UID:0000OO]. It owns source destructor C++; the scalar deleting wrapper does not. |
| `by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md` | `COMPLETION:91`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000TK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000TK`, blank emitter position | Emits `SanitizeWideTextForChat(wchar_t *, unsigned int)` first-draft C++ through [UID:0000TK] to [UID:0000OO]. |
| `by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md` | `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter UID and blank emitter position | No C++. Compiler-generated MSVC scalar deleting destructor wrapper generated from `TextFilter::~TextFilter()` and class/vtable declarations. |

### Child C++ And No-Code Details

`by-memory/0x00595760-0x00595795.TextFilterConstructor.md` should carry this exact first-draft C++:

```cpp
TextFilter::TextFilter()
{
    g_pTextFilter = this;
}
```

Do not emit the decompiler's `this == -4` / `MEMORY[0xFFFFFFFC]` branch. That branch is compiler/base-adjustment artifact evidence. The vtable write is compiler lowering from the class declaration.

`by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md` should carry this exact first-draft C++:

```cpp
TextFilter::~TextFilter()
{
    g_pTextFilter = nullptr;
}
```

This page is the single source representation of the destructor body. Its zero direct xrefs are acceptable because destructor-body reachability is represented by compiler scalar deleting/vtable glue. This follows the established project pattern used by ordinary non-deleting destructor body pages: source C++ belongs to the ordinary destructor body, while scalar deleting wrappers are no-code compiler artifacts.

`by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md` should carry this exact first-draft C++:

```cpp
void SanitizeWideTextForChat(wchar_t *text, unsigned int textLength)
{
    for (unsigned int i = 0; i < textLength; ++i) {
        wchar_t ch = text[i];
        if (ch == 0)
            break;

        if (ch == L'\n' || ch == L'\r' || (ch >= L' ' && ch <= 0x7f))
            continue;

        switch (ch) {
        case 0x00e9:
        case 0x00e8:
        case 0x00e0:
        case 0x00f9:
        case 0x00f4:
        case 0x00ee:
        case 0x00eb:
        case 0x00ef:
        case 0x00fb:
        case 0x00fa:
        case 0x00e2:
        case 0x00e7:
            continue;
        default:
            text[i] = L'?';
            break;
        }
    }
}
```

This helper must remain a free helper, not a `TextFilter` member or virtual function. Current MCP evidence confirms two stack arguments, no `ecx` use in the callee, and stack cleanup `retn 8`.

`by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md` should keep its formal C++ block blank and document this no-code proof:

- The vtable at `0x0062e188` points to this wrapper, proving it is the ABI-facing deleting destructor entry.
- The body repeats the ordinary destructor effect by restoring the vtable and clearing `g_pTextFilter`.
- It tests the deleting flag at `[ebp+8] & 1`, conditionally pushes object size `4`, calls delete helper `0x005c7526`, and returns with `retn 4`.
- Shutdown reaches this body through an indirect vtable call after reading `g_pTextFilter`, not through a source-level direct call.
- Source emission belongs to `by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md`; duplicating `TextFilter::~TextFilter()` here would generate two destructor definitions and harden compiler ABI glue into source.

[UID:0002XT] `by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md` should carry this exact first-draft C++ after correcting the stale static value:

```cpp
TextFilter *g_pTextFilter = nullptr;
```

[UID:0000SG] `by-global/g_pTextFilter.md` should document and route this declaration but should not also emit a duplicate C++ definition if [UID:0002XT] carries the code. [UID:0000TK] `by-global/SanitizeWideTextForChat.md` should likewise remain the helper owner/index while the exact by-memory child emits the helper body.

## Score And Metadata Recommendation

Target [UID:0001JU]:

- Before: `86/86`.
- Recommended after accepted implementation: `88/90`.
- Owner/emitter: keep `CANONICAL_OWNER:0000OO`, `EMITTER_UIDS:0000OO`.
- Reconstructable: keep `TRUE`.
- Emitter position: keep blank.
- Aggregate C++: keep blank.

Rationale for `88/90`:

- Completion improves because the target can now record current MCP session `ff68e691`, function/range sizes, exact padding, SHA16 byte hashes, direct xref/caller/callee sets, startup/shutdown indirect destructor routes, vtable cells, global storage bytes, source-name/signature decisions, and child split/no-code policy.
- Confidence improves because behavior, caller sets, vtable route, singleton state, and boundary facts all agree across MCP decompilation, disassembly, xrefs, bytes, and current support docs.
- Scores stay below 95+ because original source filename/folder proof is still absent, exact `Singleton<TextFilter>` header shape is inferred from RTTI rather than recovered source, and aggregate-level C++ must remain blank pending exact child/support implementation.

Exact support metadata/content decisions:

| UID / path | Decision | Metadata result | Required content result |
| --- | --- | --- | --- |
| [UID:0000OO] `by-file/TextFilter.md` | Required change | `86/88 -> 88/90`; keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"` and `CANONICAL_OWNER:FILE` | Record `ff68e691` evidence, concrete child split, current source-output policy, and `ui/controls` over `util` decision. |
| [UID:0000EQ] `by-class/TextFilter.md` | Required change | `86/88 -> 88/90`; keep owner/emitter [UID:0000OO] | Record `TextFilter`/`Singleton<TextFilter>` RTTI, constructor child C++, non-deleting destructor-body child as the single `~TextFilter()` source representation, scalar deleting wrapper no-code policy, and sanitizer as non-member/non-virtual. Keep class-page C++ blank unless a later class-declaration pass settles exact `Singleton<TextFilter>` header spelling. |
| [UID:0000TK] `by-global/SanitizeWideTextForChat.md` | Required change | `90/86 -> 91/90`; keep owner/emitter [UID:0000OO] | Record two-stack-argument free-helper evidence, `wchar_t *` signature, rejected member/`TextFilter *` signatures, and that the exact new by-memory child emits the helper body while this global page remains the owner/index. |
| [UID:0000SG] `by-global/g_pTextFilter.md` | Required change | `86/88 -> 88/90`; keep owner/emitter [UID:0000OO] | Correct stale `0xffffffff` initializer to current zero/null evidence, record declaration readiness, and document that exact storage child [UID:0002XT] emits the definition to avoid duplicate global C++. |
| [UID:0002XT] `by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md` | Required change | `86/88 -> 88/90`; keep owner/emitter [UID:0000SG] | Correct static image bytes/value to `00 00 00 00` / `0x00000000`; add first-draft C++ `TextFilter *g_pTextFilter = nullptr;`. |
| [UID:0001YY] `by-type/by-vtable/TextFilterVtable.md` | Only-if-stale change | No score change required; keep `86/90`, owner/emitter [UID:0000EQ] | Edit only if implementation finds stale session/no-code wording while wiring child links. Do not add C++; vtable bytes are compiler-emitted from the class declaration. |
| [UID:0002OZ] `by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md` | Required content-only change | No score change required; keep `87/91`, owner/emitter [UID:0001YY] | Correct the stale `0x0062e184 -> 0x00651718` typo to `0x00651518`, add `ff68e691` byte/int confirmation, and keep C++ blank. |
| [UID:0001JT] `by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md` | Required content-only change | No score change required; keep `88/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++ | Sync stale TextFilter child rows to the new child inventory and end-exclusive ranges while preserving the mixed audit/non-emitting split decision. |

## Recommended Target Doc Changes

If accepted for implementation, update `by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md` at report-level detail:

- Metadata: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged, aggregate C++ blank.
- Replace old "2026-06-04 live IDA" lead text with current session `ff68e691` evidence while preserving useful historical notes.
- Replace old 95+ C++-blocker language with the current combined-score/emitter gate and target-specific no-code proof.
- Add exact range table with sizes, SHA16 byte hashes, and padding spans from this report.
- Add constructor/disassembly facts, startup caller `0x004f615f`, global writes at `0x00595771`/`0x00595784`, vtable stores at `0x00595778`/`0x0059578b`, and the decompiler `-4` branch as compiler artifact.
- Add non-deleting destructor zero-xref fact and no-duplicate-destructor-source policy.
- Add sanitizer decompilation, `retn 8` / two-stack-argument/free-helper evidence, allowlist, 14 call sites, and rejected member-helper signatures.
- Add scalar deleting destructor data-xref/vtable route, shutdown indirect call route, delete helper `0x005c7526`, and compiler-generated wrapper no-code policy.
- Add current vtable/global data evidence: `0x0062e184 -> 0x00651518`, `0x0062e188 -> 0x005958d0`, `0x0062e18c -> 0x006517b4`, `0x0067adc8 -> 0x00000000`.
- Add source placement decision matrix: keep `ui/controls/TextFilter.cpp`, reject `TextEditPane`, reject caller owners, reject packet/socket owners, reject forced `util` move, reject no-owner.
- Add exact child split plan and padding preservation.
- Add first-draft C++ readiness summary with aggregate blank-C++ proof.

## Recommended Support Doc Changes

If accepted, update support docs as follows. Do not compress the facts to one-line summaries.

1. `by-file/TextFilter.md`
   - Record current MCP session `ff68e691`.
   - Keep `NexusTK/ui/controls/`.
   - Replace "possible later utility-folder migration" as the lead conclusion with "utility route checked and rejected as primary; retained as a residual caveat only."
   - Record exact target child split and source-output policy.
   - Record that sanitizer/global/lifecycle code are first-draft candidates after exact child/support placement, while the aggregate and scalar deleting destructor stay no-code.

2. `by-class/TextFilter.md`
   - Record `TextFilter` and `Singleton<TextFilter>` RTTI/name evidence.
   - Record object allocation size `4`, one-slot vtable, startup constructor route, shutdown indirect destructor route, non-deleting body zero-xref caveat, and scalar deleting destructor wrapper policy.
   - Clarify that `SanitizeWideTextForChat` is not a virtual method and not a member function under current binary evidence.
   - Add declaration-level C++ readiness caveat: constructor/destructor behavior is understood, but exact header/base declaration remains inferred.

3. `by-global/SanitizeWideTextForChat.md`
   - Record current MCP decompilation/disassembly evidence.
   - Prefer source-facing signature `void SanitizeWideTextForChat(wchar_t *text, unsigned int textLength)`.
   - Preserve the allowlist and 14 call sites.
   - Add `retn 8`/two-stack-argument/no-`ecx` evidence and reject `TextFilter *`/member signatures.
   - Add first-draft C++ readiness and keep source root [UID:0000OO].

4. `by-global/g_pTextFilter.md`
   - Correct stale `0xffffffff` initial value text to current `0x00000000`.
   - Record MCP bytes/SHA16 for [UID:0002XT], constructor/destructor/shutdown/sanitizer-user refs, and declaration readiness.
   - Preserve the physical-adjacency warning for the UI/chat/clan singleton slot run.

5. `by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md`
   - Correct `Static image value: 0xffffffff` to `0x00000000`.
   - Add bytes `00 00 00 00`, SHA16 `df3f619804a92fdb`, `TextFilter *g_pTextFilter = nullptr;` source declaration readiness, and 19 xref categories.

6. `by-type/by-vtable/TextFilterVtable.md`
   - Record current session `ff68e691`, one-slot layout, four vtable-base xrefs, data xref from `0x0062e188` to `0x005958d0`, and no source C++ for vtable bytes.
   - Keep owner/emitter through [UID:0000EQ].

7. `by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md`
   - Record bytes/SHA16 and current `get_int` values.
   - Correct any stale `0x00651718` value for the TextFilter COL pointer to `0x00651518`.
   - Keep compiler-emitted/no-code policy.

8. `by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md`
   - If edited, sync historical child rows to end-exclusive TextFilter child ranges:
     `0x00595760-0x00595795`, `0x005957a0-0x005957b1`, `0x005957c0-0x005958ca`, and `0x005958d0-0x005958fe`.
   - Preserve the audit-only mixed-source-owner decision and TextFilter/TextEditPane split.

9. Caller pages
   - No required edit during the first implementation unless the supervisor wants stale caller-local names corrected. Current accepted Say/NewArticle reports already use `SanitizeWideTextForChat`. Older archived local names such as `NormalizeChatText`, `ApplyOutboundChatFilter`, `g_chatTextFilter`, or `g_pTextFilter->SanitizeWideTextForChat(...)` should be treated as superseded leads, not current authority.

## Supervisor-Owned Coverage Text

B003 must not edit coverage reports. The following text is supervisor-owned and now uses the real validator-assigned child UIDs from the accepted implementation callback.

Replace the current [UID:0001JU] row in `by-memory/-coverage-report.md` with this parent/nested block after child validation:

```text
        - [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md) : reconstructable : 88% : very strong : B003 2026-06-23 split-ready MCP-backed source-quality recheck with session ff68e691 confirms the TextFilter singleton/sanitizer aggregate as a non-C++ parent inventory over exact constructor, destructor-body, sanitizer, scalar-deleting-wrapper, and padding children; owner/emitter stay [UID:0000OO] TextFilter with ui/controls/TextFilter.cpp route, aggregate C++ stays blank, source C++ moves to exact child/support pages, and TextEditPane/caller/packet/util/no-owner routes are rejected.
            - [UID:00041H][0x00595760-0x00595795.TextFilterConstructor](by-memory/0x00595760-0x00595795.TextFilterConstructor.md) 0x00595760-0x00595795 | constructor | TextFilterConstructor : reconstructable : 88% : very strong : Exact 0x35/53-byte TextFilter startup constructor (SHA16 0de8157fbaa29517) with one direct startup caller at 0x004f615f, g_pTextFilter writes at 0x00595771/0x00595784, vtable stores to 0x0062e188 at 0x00595778/0x0059578b, decompiler -4 branch rejected as compiler/base-adjustment artifact, owner/emitter [UID:0000EQ], and first-draft TextFilter::TextFilter() C++ emitted here.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00595795-0x005957a0 | padding | TextFilter constructor to non-deleting destructor-body alignment : ignored : 100% : strong : ff68e691 get_bytes confirms eleven 0xcc bytes (SHA16 3682c0a625150501); no source child or emitter.
            - [UID:00041I][0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody](by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md) 0x005957a0-0x005957b1 | destructor body | TextFilterNonDeletingDestructorBody : reconstructable : 88% : very strong : Exact 0x11/17-byte ordinary TextFilter destructor body (SHA16 c020601bb4db048c) with vtable restore to 0x0062e188, g_pTextFilter clear at 0x005957a6, zero direct code xrefs, scalar wrapper parity, owner/emitter [UID:0000EQ], and the single first-draft TextFilter::~TextFilter() source representation emitted here.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005957b1-0x005957c0 | padding | TextFilter destructor-body to sanitizer alignment : ignored : 100% : strong : ff68e691 get_bytes confirms fifteen 0xcc bytes (SHA16 54cc9dd9593316e8); no source child or emitter.
            - [UID:00041J][0x005957c0-0x005958ca.SanitizeWideTextForChat](by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md) 0x005957c0-0x005958ca | helper | SanitizeWideTextForChat : reconstructable : 91% : very strong : Exact 0x10a/266-byte free helper (SHA16 d06aa427134dc3d3) with 14 code call sites across 12 submit/dialog functions, no callees, two stack arguments with retn 8, no ecx/this use, UTF-16 in-place filtering, ASCII/CR/LF/lowercase-accent allowlist, rejected TextFilter member/virtual signatures, owner/emitter [UID:0000TK], and first-draft SanitizeWideTextForChat C++ emitted here.
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005958ca-0x005958d0 | padding | Sanitizer to TextFilter scalar deleting destructor alignment : ignored : 100% : strong : ff68e691 get_bytes confirms six 0xcc bytes (SHA16 33cc4a00a0f04735); no source child or emitter.
            - [UID:00041K][0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor](by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md) 0x005958d0-0x005958fe | compiler deleting destructor glue | TextFilterScalarDeletingDestructor : ignored : 86% : very strong : Exact 0x2e/46-byte scalar deleting destructor wrapper (SHA16 decc5293dda7446a) reached by vtable cell 0x0062e188 and shutdown indirect call through g_pTextFilter, clears the singleton, tests delete flag, pushes object size 4, calls delete helper 0x005c7526, returns with retn 4, carries CANONICAL_OWNER:NONE/RECONSTRUCTABLE:FALSE/blank emitter, and leaves C++ blank because the source destructor body is emitted only by [UID:00041I].
            - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005958fe-0x00595900 | padding | TextFilter scalar deleting destructor to TextPad alignment : ignored : 100% : strong : Existing ignored row; ff68e691 get_bytes reconfirms two 0xcc bytes (SHA16 e3966e3275be536a) before [UID:0001JV].
```

Replace/update these support coverage rows if the corresponding support docs are changed:

`by-file/-coverage-report.md`:

```text
- [UID:0000OO][TextFilter](by-file/TextFilter.md) : reconstructable : 88% : very strong : B003 2026-06-23 split-ready MCP recheck with session ff68e691 keeps `NexusTK/ui/controls/TextFilter.cpp` as the source root over a forced util move, records exact child split for TextFilter constructor/destructor/sanitizer/scalar deleting wrapper, routes constructor/destructor children through [UID:0000EQ], sanitizer through [UID:0000TK], g_pTextFilter storage through [UID:0002XT]/[UID:0000SG], rejects TextEditPane/caller/packet/no-owner routes, and keeps aggregate/scalar-wrapper/vtable C++ blank while exact source children/support carry first-draft C++.
```

`by-class/-coverage-report.md`:

```text
- [UID:0000EQ][TextFilter](by-class/TextFilter.md) : reconstructable : 88% : very strong : B003 2026-06-23 split-ready MCP recheck with session ff68e691 confirms TextFilter/Singleton<TextFilter> RTTI, startup constructor route, one-slot vtable 0x0062e188, shutdown indirect scalar-deleting route, non-deleting destructor-body zero-xref caveat, constructor child [UID:00041H] first-draft C++, destructor-body child [UID:00041I] as the single TextFilter::~TextFilter() source representation, scalar wrapper [UID:00041K] no-code, and sanitizer as a neighboring free helper rather than a member or virtual method.
```

`by-global/-coverage-report.md`:

```text
- [UID:0000TK][SanitizeWideTextForChat](by-global/SanitizeWideTextForChat.md) : reconstructable : 91% : very strong : B003 2026-06-23 split-ready MCP recheck with session ff68e691 confirms exact helper child [UID:00041J], two stack arguments/retn 8, no ecx/this use, 14 code call sites across 12 submit/dialog functions, UTF-16 in-place ASCII/CR/LF/lowercase-accent allowlist behavior, rejected TextFilter member/virtual signatures, first-draft helper C++ emitted on the exact by-memory child, and owner/emitter route through [UID:0000OO].
- [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md) : reconstructable : 88% : very strong : B003 2026-06-23 split-ready MCP recheck with session ff68e691 corrects stale 0xffffffff initializer to current zero-filled bytes, preserves 19 data xrefs across constructor/destructor/shutdown/sanitizer callers, keeps owner/emitter [UID:0000OO], and routes the first-draft `TextFilter *g_pTextFilter = nullptr;` definition through exact storage child [UID:0002XT] to avoid duplicate global C++.
```

`by-type/by-vtable/-coverage-report.md`, only if [UID:0001YY] is edited:

```text
- [UID:0001YY][TextFilterVtable](by-type/by-vtable/TextFilterVtable.md) : reconstructable : 86% : strong : IDA-confirmed one-slot `TextFilter` vtable attached to [UID:0000EQ][TextFilter](by-class/TextFilter.md), with exact [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md) child range, ff68e691 vtable cell confirmation 0x0062e188 -> 0x005958d0, constructor/destructor xrefs, predecessor/successor boundaries, and no hand-authored vtable C++.
```

Additional `by-memory/-coverage-report.md` support replacements:

```text
    - [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md) 0x00594e60-0x005958fe | split-audit aggregate | TextEditSupportObjectsAndFilter : ignored : 88% : very strong : Audit-only mixed source-owner island retained for history; split children now separate the pre-TextBoxPane TextEditObject/TextEditScrap island, the TextBoxPane constructor, the post-TextBoxPane TextEdit support island, and the split-ready TextFilter singleton/sanitizer child inventory under [UID:0001JU] with constructor [UID:00041H], destructor body [UID:00041I], sanitizer [UID:00041J], scalar deleting wrapper [UID:00041K], and padding preserved as ignored spans.
        - [UID:0002OZ][0x0062e184-0x0062e18c.TextFilterVtableData](by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md) 0x0062e184-0x0062e18c | vtable-data | TextFilterVtableData : reconstructable : 87% : very strong : Exact one-slot TextFilter RTTI-adjacent vtable data; ff68e691 get_bytes/get_int confirms bytes SHA16 50df7549f68dce6b, 0x0062e184 -> 0x00651518, 0x0062e188 -> 0x005958d0, 0x0062e18c -> 0x006517b4, constructor/destructor xrefs, and generated/no-code vtable policy.
        - [UID:0002XT][0x0067adc8-0x0067adcc.g_pTextFilter](by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md) 0x0067adc8-0x0067adcc | global pointer | g_pTextFilter : reconstructable : 88% : very strong : Exact four-byte TextFilter singleton storage with current zero-filled static bytes `00 00 00 00` (SHA16 df3f619804a92fdb), 19 xrefs, constructor/destructor/shutdown/sanitizer-user evidence, parent [UID:0000SG][g_pTextFilter](by-global/g_pTextFilter.md), and first-draft `TextFilter *g_pTextFilter = nullptr;` emitted here.
```

## Open Questions And Score Impact

1. Exact original source folder:
   - Evidence supports `NexusTK/ui/controls/TextFilter.cpp` as the current route, but no source path or PDB metadata proves the original folder.
   - Impact: confidence stays below final-audit level; no forced move to `util`.

2. Exact `Singleton<TextFilter>` header shape:
   - RTTI proves a `Singleton<TextFilter>` relationship, but IDA has no UDT or source declaration.
   - Impact: declaration-level class C++ can be drafted, but final class header should not overfit the decompiler's constructor artifact.

3. Exact sanitizer helper spelling:
   - IDA has no sanitizer symbol. `SanitizeWideTextForChat` is established project terminology and behaviorally accurate.
   - Impact: source-facing name is strong enough for first-draft C++, but the absence of a recovered symbol keeps confidence below 95+.

4. Destructor child placement:
   - The source destructor body and scalar deleting destructor wrapper are intertwined by compiler lowering.
   - Impact: do not add duplicate destructor C++. Represent `~TextFilter()` once and mark wrapper/no-route variants as compiler-generated/no-code as needed.

No MCP blocker occurred during the report pass. The implementation callback did not require new MCP calls because the accepted report already supplied the current `ff68e691` MCP-backed evidence. No fallback-only evidence was added.

Lease status during implementation:

- Before the existing-doc edit batch, `tools/leaser/Agents/current_leases.md` showed no active leases.
- B003 leased the exact existing parent/support docs immediately before the edit/validator batch: `by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md`, `by-file/TextFilter.md`, `by-class/TextFilter.md`, `by-global/SanitizeWideTextForChat.md`, `by-global/g_pTextFilter.md`, `by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md`, `by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md`, `by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md`, and `by-type/by-vtable/TextFilterVtable.md`; the lease command returned `Success` for all nine paths.
- B003 released the same nine paths immediately after the scoped validator batch; the unlease command returned `Success` for all nine paths, and the follow-up `current_leases.md` check showed `No active leases.`

## Validators

All validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240`.

Child creation and final validation:

- `python .\tools\validator.py --mode file --file by-memory\0x00595760-0x00595795.TextFilterConstructor.md --apply --queue-timeout 240`
  - Initial allocation: exit code `0`; validator assigned [UID:00041H]; side effects included `autogen_report_update: 1`, `autogen_backup_create: 1`, `uid_link_insert: 17`, `reference_index_add: 7`, and `projected_stats_update: 1`.
  - Final validation after metadata/C++ edit: exit code `0`, `ok: 1`; side effects included completion/confidence/owner updates to `88/90` and [UID:0000EQ], registry code-hash/block updates, `autogen_cpp_update 0000OO auto-generated/NexusTK/ui/controls/TextFilter.cpp`, generated report updates, and projected stats update.

- `python .\tools\validator.py --mode file --file by-memory\0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md --apply --queue-timeout 240`
  - Initial allocation: exit code `0`; validator assigned [UID:00041I]; side effects included `autogen_report_update: 1`, `autogen_backup_create: 1`, `uid_link_insert: 19`, `reference_index_add: 7`, and `projected_stats_update: 1`.
  - Final validation after metadata/C++ edit: exit code `0`, `ok: 1`; side effects included completion/confidence/owner updates to `88/90` and [UID:0000EQ], registry code-hash/block updates, `autogen_cpp_update 0000OO auto-generated/NexusTK/ui/controls/TextFilter.cpp`, generated report updates, and projected stats update.

- `python .\tools\validator.py --mode file --file by-memory\0x005957c0-0x005958ca.SanitizeWideTextForChat.md --apply --queue-timeout 240`
  - Initial allocation: exit code `0`; validator assigned [UID:00041J]; side effects included `autogen_report_update: 1`, `autogen_backup_create: 1`, `uid_link_insert: 20`, `reference_index_add: 8`, and `projected_stats_update: 1`.
  - Final validation after metadata/C++ edit: exit code `0`, `ok: 1`; side effects included completion/confidence/owner updates to `91/90` and [UID:0000TK], registry code-hash/block updates, `autogen_cpp_update 0000OO auto-generated/NexusTK/ui/controls/TextFilter.cpp`, generated report updates, and projected stats update.

- `python .\tools\validator.py --mode file --file by-memory\0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md --apply --queue-timeout 240`
  - Initial allocation: exit code `0`; validator assigned [UID:00041K]; side effects included `autogen_report_update: 1`, `autogen_backup_create: 1`, `uid_link_insert: 16`, `reference_index_add: 8`, and `projected_stats_update: 1`.
  - Final validation after metadata/no-code edit: exit code `0`, `ok: 1`; side effects included completion/confidence updates to `86/91`, reconstructable/registry no-code state, and projected stats update; no generated C++ was emitted for this compiler-generated wrapper.

Parent/support validation:

- `python .\tools\validator.py --mode file --file by-memory\0x00595760-0x005958fe.TextFilterAndSanitizer.md --apply --queue-timeout 240`
  - Result: exit code `0`, `ok: 1`; side effects included `completion_update 0001JU ... 88`, `confidence_update 0001JU ... 90`, `uid_link_insert: 23`, `reference_index_add: 5`, `stats_row_remove: 3`, `stats_rescore_recommended: 1`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, `autogen_cpp_update 0000OO auto-generated/NexusTK/ui/controls/TextFilter.cpp`, and `autogen_backup_create .../20260623-131450`.

- `python .\tools\validator.py --mode file --file by-file\TextFilter.md --apply --queue-timeout 240`
  - Result: exit code `0`, `ok: 1`; side effects included `completion_update 0000OO ... 88`, `confidence_update 0000OO ... 90`, `uid_link_insert: 8`, `reference_index_add: 6`, `stats_incremental_noop: 1`, `projected_stats_update: 1`, and generated-output noops.

- `python .\tools\validator.py --mode file --file by-class\TextFilter.md --apply --queue-timeout 240`
  - Result: exit code `0`, `ok: 1`; side effects included `completion_update 0000EQ ... 88`, `confidence_update 0000EQ ... 90`, `uid_link_insert: 9`, `reference_index_add: 7`, `stats_incremental_noop: 1`, `projected_stats_update: 1`, `autogen_cpp_update 0000OO auto-generated/NexusTK/ui/controls/TextFilter.cpp`, and `autogen_backup_create .../20260623-131526`.

- `python .\tools\validator.py --mode file --file by-global\SanitizeWideTextForChat.md --apply --queue-timeout 240`
  - Result: exit code `0`, `ok: 1`; side effects included `completion_update 0000TK ... 91`, `confidence_update 0000TK ... 90`, `uid_link_insert: 3`, `reference_index_add: 1`, `stats_row_remove: 2`, `stats_rescore_recommended: 1`, `projected_stats_update: 1`, `autogen_cpp_update 0000OO auto-generated/NexusTK/ui/controls/TextFilter.cpp`, and `autogen_backup_create .../20260623-131538`.

- `python .\tools\validator.py --mode file --file by-global\g_pTextFilter.md --apply --queue-timeout 240`
  - Result: exit code `0`, `ok: 1`; side effects included `completion_update 0000SG ... 88`, `confidence_update 0000SG ... 90`, `uid_link_insert: 3`, `reference_index_add: 3`, `stats_row_remove: 1`, `stats_rescore_recommended: 1`, `projected_stats_update: 1`, `autogen_cpp_update 0000OO auto-generated/NexusTK/ui/controls/TextFilter.cpp`, and `autogen_backup_create .../20260623-131551`.

- `python .\tools\validator.py --mode file --file by-memory\0x0067adc8-0x0067adcc.g_pTextFilter.md --apply --queue-timeout 240`
  - Result: exit code `0`, `ok: 1`; side effects included `completion_update 0002XT ... 88`, `confidence_update 0002XT ... 90`, `autogen_registry_update: 2` for the C++ hash/block state, `uid_link_insert: 2`, `reference_index_add: 5`, `stats_incremental_noop: 1`, `projected_stats_update: 1`, `autogen_cpp_update 0000OO auto-generated/NexusTK/ui/controls/TextFilter.cpp`, and `autogen_backup_create .../20260623-131604`.

- `python .\tools\validator.py --mode file --file by-memory\0x0062e184-0x0062e18c.TextFilterVtableData.md --apply --queue-timeout 240`
  - Result: exit code `0`, `ok: 1`; side effects included `uid_link_insert: 2`, `reference_index_add: 3`, `stats_incremental_noop: 1`, `projected_stats_update: 1`, and generated reports unchanged.

- `python .\tools\validator.py --mode file --file by-memory\0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md --apply --queue-timeout 240`
  - Result: exit code `0`, `ok: 1`; side effects included `uid_link_insert: 13`, `reference_index_add: 4`, `stats_incremental_noop: 1`, `projected_stats_update: 1`, and generated reports unchanged.

- `python .\tools\validator.py --mode file --file by-type\by-vtable\TextFilterVtable.md --apply --queue-timeout 240`
  - Result: exit code `0`, `ok: 1`; side effects included `uid_link_insert: 2`, `reference_index_add: 2`, `stats_incremental_noop: 1`, `projected_stats_update: 1`, and generated reports unchanged.

Recurring validator warnings/side effects across the scoped runs:

- Unrelated stale registry warnings remained for [UID:0003E6] `by-memory/0x0062e960-0x0062e998.UserListDialogPaneVtableLeadInData.md` and [UID:00026U] `by-memory/0x0062e960-0x0062eccc.UserListReadOnlyData.md` because their registered files are missing.
- Existing `autogen_cpp_conflict` warnings remained for [UID:0000JH] `FontImageLib.cpp`, [UID:0000JQ] `GeneralPurposePanel.cpp`, [UID:0000JW] `HistoryViewingPane.cpp`, [UID:0000JX] `HourPane.cpp`, and [UID:0000K5] `IMEPanes.cpp`; these are unrelated nonempty generated files lacking the validator sentinel.
- Validator-owned side effects included `validator.ini` registry rebuilds, projected stats updates in `project-level/-auto-completion-stats.md`, generated report noops/updates under `auto-generated/`, generated TextFilter C++ refreshes under `auto-generated/NexusTK/ui/controls/TextFilter.cpp`, and backup directories under `tools/validator_autogen_backup/`.
- B003 did not manually edit generated/project-level files or any `-coverage-report.md` file.

## Changed Files During Implementation Callback

Created or changed by-* docs:

- `by-memory/0x00595760-0x00595795.TextFilterConstructor.md`
- `by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md`
- `by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md`
- `by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md`
- `by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md`
- `by-file/TextFilter.md`
- `by-class/TextFilter.md`
- `by-global/SanitizeWideTextForChat.md`
- `by-global/g_pTextFilter.md`
- `by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md`
- `by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md`
- `by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md`
- `by-type/by-vtable/TextFilterVtable.md`

Report file updated:

- `tools/leaser/Agents/Agent-B003/research/0001JU-TextFilterAndSanitizer-source-quality.md`

Coverage reports were not edited. IDA DB state and MCP/tool process state were not changed.

## Implementation Tracking Checklist

Report-only pass:

- [x] Report revision evidence updated in this file only.
  - Proof: report records MCP session `ff68e691`, stale `261fb29b` superseded, server health ok, tool schema note, target `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`, `get_int`, and `entity_query` evidence.

Accepted implementation package:

- [x] Lease only the immediate by-* edit batch after checking current leases; release immediately after edits and scoped validators.
  - Proof: initial `current_leases.md` showed no active leases; B003 lease command returned `Success` for nine existing docs; B003 unlease command returned `Success` for the same nine docs; final `current_leases.md` showed `No active leases.`

- [x] Create `by-memory/0x00595760-0x00595795.TextFilterConstructor.md`.
  - Proof: validator allocated [UID:00041H]; metadata set to `88/90`, `CANONICAL_OWNER:0000EQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EQ`, blank emitter position; first-draft `TextFilter::TextFilter()` C++ added; range/size/SHA16/startup caller/vtable/global-write/decompiler-artifact facts recorded; final validator exit `0`, `ok: 1`.

- [x] Create `by-memory/0x005957a0-0x005957b1.TextFilterNonDeletingDestructorBody.md`.
  - Proof: validator allocated [UID:00041I]; metadata set to `88/90`, `CANONICAL_OWNER:0000EQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EQ`, blank emitter position; first-draft single source `TextFilter::~TextFilter()` C++ added; range/size/SHA16/vtable restore/singleton clear/zero-xref/scalar-sibling facts recorded; final validator exit `0`, `ok: 1`.

- [x] Create `by-memory/0x005957c0-0x005958ca.SanitizeWideTextForChat.md`.
  - Proof: validator allocated [UID:00041J]; metadata set to `91/90`, `CANONICAL_OWNER:0000TK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000TK`, blank emitter position; exact first-draft `SanitizeWideTextForChat(wchar_t *, unsigned int)` C++ body added; range/size/SHA16/14 callers/no callee/two stack args/no ecx/allowlist/rejected member facts recorded; final validator exit `0`, `ok: 1`.

- [x] Create `by-memory/0x005958d0-0x005958fe.TextFilterScalarDeletingDestructor.md`.
  - Proof: validator allocated [UID:00041K]; metadata set to `86/91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters and blank C++; no-code proof records vtable-facing compiler scalar deleting destructor wrapper, shutdown indirect route, delete flag, object-size push `4`, delete helper `0x005c7526`, `retn 4`, and single source destructor representation on [UID:00041I]; final validator exit `0`, `ok: 1`.

- [x] Update parent `by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md`.
  - Proof: metadata updated `86/86 -> 88/90`; kept `CANONICAL_OWNER:0000OO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OO`, blank emitter position, blank aggregate C++; current `ff68e691` evidence, real child UID inventory, padding spans, aggregate no-code proof, source placement matrix, and rejected alternatives incorporated; validator exit `0`, `ok: 1`.

- [x] Update `by-file/TextFilter.md`.
  - Proof: metadata updated `86/88 -> 88/90`; retained `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`; incorporated current MCP evidence, child inventory, `ui/controls` over forced `util`, child/source-output policy, aggregate/scalar/vtable no-code policy, and exact emitting child/support pages; validator exit `0`, `ok: 1`.

- [x] Update `by-class/TextFilter.md`.
  - Proof: metadata updated `86/88 -> 88/90`; retained owner/emitter route through [UID:0000OO]; incorporated RTTI, object size `4`, startup/shutdown routes, non-deleting destructor as the single source representation, scalar wrapper no-code, sanitizer not member/virtual, and blank class C++ pending exact header/base spelling; validator exit `0`, `ok: 1`.

- [x] Update `by-global/SanitizeWideTextForChat.md`.
  - Proof: metadata updated `90/86 -> 91/90`; retained owner/emitter through [UID:0000OO]; linked exact child [UID:00041J], free-helper signature, two stack args/retn 8/no ecx, allowlist, 14 call sites, child-only C++ emission, and no duplicate global-page code; validator exit `0`, `ok: 1`.

- [x] Update `by-global/g_pTextFilter.md`.
  - Proof: metadata updated `86/88 -> 88/90`; retained owner/emitter through [UID:0000OO]; stale `0xffffffff` corrected to zero/null evidence; 19 xrefs and constructor/destructor/shutdown/sanitizer refs preserved; [UID:0002XT] named as sole C++ definition emitter; validator exit `0`, `ok: 1`.

- [x] Update `by-memory/0x0067adc8-0x0067adcc.g_pTextFilter.md`.
  - Proof: metadata updated `86/88 -> 88/90`; retained owner/emitter [UID:0000SG]; exact `TextFilter *g_pTextFilter = nullptr;` C++ added; bytes `00 00 00 00`, SHA16 `df3f619804a92fdb`, `get_int` zero, xref categories, and stale `0xffffffff` rejection recorded; validator exit `0`, `ok: 1`.

- [x] Update `by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md`.
  - Proof: kept `87/91`, owner/emitter [UID:0001YY], blank C++; corrected stale `0x00651718` COL typo to `0x00651518`; recorded bytes `18 15 65 00 d0 58 59 00`, SHA16 `50df7549f68dce6b`, `0x0062e188 -> 0x005958d0`, `0x0062e18c -> 0x006517b4`, and no-code vtable policy; validator exit `0`, `ok: 1`.

- [x] Update `by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md`.
  - Proof: kept `88/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; stale TextFilter child endpoints replaced with real child UID inventory and ranges while preserving the mixed aggregate/audit-only decision; validator exit `0`, `ok: 1`.

- [x] Update `by-type/by-vtable/TextFilterVtable.md`.
  - Proof: stale wording was found, so the file was updated; kept `86/90`, owner/emitter [UID:0000EQ], blank C++; recorded current `ff68e691` vtable cell/data child route and generated/no-code policy; validator exit `0`, `ok: 1`.

- [x] Preserve rejected alternatives and stale assumptions in target/support docs.
  - Proof: target/support docs preserve or explicitly reject old 95+ gate, stale `g_pTextFilter` `0xffffffff`, old local names `NormalizeChatText`/`ApplyOutboundChatFilter`/`g_chatTextFilter`, `TextFilter *` sanitizer/member signature, `TextEditPane`, caller-feature, packet/socket, forced utility, no-owner routes, non-deleting body zero-xref caveat, scalar deleting destructor compiler-generated status, and stale `0x00651718` vtable COL typo.

- [x] Supervisor-owned coverage actions.
  - Proof: this report supplies exact supervisor-owned coverage text with real child UIDs [UID:00041H], [UID:00041I], [UID:00041J], and [UID:00041K]; B003 did not edit any `-coverage-report.md` file.

- [x] Validators recorded after accepted implementation.
  - Proof: validator commands, exit codes, `ok` counts, UID allocation, relevant warnings, generated side effects, and release state are recorded in the `Validators` section above.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] Required leases checked/taken only immediately before by-* edits and released immediately after edit/scoped-validator batch.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001JU-TextFilterAndSanitizer-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0001JU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
