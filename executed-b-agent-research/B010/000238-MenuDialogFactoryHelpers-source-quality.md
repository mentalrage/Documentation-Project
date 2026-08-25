** TARGET-REPORT-UID:000238 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000238 MenuDialogFactoryHelpers Source-Quality Report

Assignment: `B010-report-000238-menu-dialog-factory-helpers-20260625`  
Agent: `Agent-B010`  
Mode: report-only research first  
Target: [UID:000238] `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md`

## Recommendation

Formal first-draft C++ is safe now for [UID:000238], with two important corrections to the current sketch:

- The dispatcher should be modeled as a `void` source function. Both live callers discard the return value, and the decompiler's default-case "return subtype" is leftover `EAX`, not a source-level `DialogPane *` result.
- The current body `## Reconstruction Sketch` C++ block should be removed as code outside the formal block. Its behavior should be superseded by the exact formal `RECONSTRUCTION_CPP CODE` insertion below; any remaining sketch prose should be non-code only.

Recommended metadata after implementation:

| Field | Recommended value | Reason |
| --- | --- | --- |
| `COMPLETION` | `90` | Formal code can now be populated, source/file route is resolved, rectangle type is resolved, and wrapper/raw-helper evidence is current. |
| `CONFIDENCE` | `93` | Live IDA MCP reconfirms boundaries, callers, constructor targets, wrapper no-xrefs, raw helper no-xrefs, and no VA-literal route to raw/wrapper starts. |
| `CANONICAL_OWNER` | `0000OP` | Keep direct documentation owner as [UID:0000OP][TextMenuDialogs](../../../by-file/TextMenuDialogs.md). |
| `EMITTER_UIDS` | `0000OP` | Keep emitted route through [UID:0000OP][TextMenuDialogs](../../../by-file/TextMenuDialogs.md). |
| Formal C++ | Populate with insertion below. | Current combined score and emitter route pass the active gate; names and source placement are now implementation-ready. |

## IDA MCP Status

Live MCP was available and used. No fallback-only evidence was used.

| Check | Result |
| --- | --- |
| MCP endpoint | `http://127.0.0.1:13337/mcp` responded to `initialize` and `tools/list`. |
| Active database | `idb_list` returned session `80de0a67`, `NexusTK.exe.i64`, backend `worker`, PID/worker PID `26892`, active, not analyzing. |
| Health | `server_health` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, module `NexusTK.exe`, imagebase `0x400000`. |

## Current Target State

Source page state read during this report:

- `COMPLETION:87`, `CONFIDENCE:92`
- `CANONICAL_OWNER:0000OP`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OP`
- Formal `RECONSTRUCTION_CPP CODE` block is blank.
- A separate body-level `## Reconstruction Sketch` contains C++ code. This violates the active code placement rule because any draft/example/source C++ for the target must be in the formal block or provided as exact insertion text.

The target is currently a clean direct-owner/emitter candidate, not a no-owner or non-emitting research item.

## Evidence Summary

### Function And Boundary Evidence

Live `lookup_funcs` on session `80de0a67`:

| Address | IDA function | Size/result |
| --- | --- | --- |
| `0x00517450` | `sub_517450` | `0x321` dispatcher |
| `0x00517771` | none | switch table / data tail, not a function |
| `0x005177a0` | `sub_5177A0` | `0x8a` text wrapper, variant false |
| `0x00517830` | `sub_517830` | `0x8a` text wrapper, variant true |
| `0x005178c0` | `sub_5178C0` | `0x8a` text-input wrapper, variant false |
| `0x00517950` | `sub_517950` | `0x8a` text-input wrapper, variant true |
| `0x005179e0` | `sub_5179E0` | `0x9e` server item wrapper |
| `0x00517a80` | `sub_517A80` | `0x88` client item wrapper |
| `0x00517b10` | `sub_517B10` | `0x88` server spell wrapper |
| `0x00517ba0` | `sub_517BA0` | `0x88` client spell wrapper |
| `0x00517c30` | `sub_517C30` | `0x88` argumented menu wrapper |
| `0x00517cc0` | none | raw rectangle helper |
| `0x00517ce0` | none | raw rectangle helper |
| `0x00517d00` | none | raw rectangle helper |
| `0x00517d23` | none | post-range padding |
| `0x004b7c50` | `sub_4B7C50` | `0x1f`, shared `InitRectBounds` helper |

`get_bytes` confirms:

- `0x00517441-0x00517450`: fifteen `0xcc` bytes before dispatcher.
- `0x00517771-0x005177a0`: switch table/data tail starts with `0f 1f 00` and table entries into dispatcher blocks.
- `0x00517cc0-0x00517ce0`: raw body pushes `455, 416, 100, 100`, calls `0x004b7c50`, returns with `retn 4`.
- `0x00517ce0-0x00517d00`: raw body pushes `328, 416, 100, 100`, calls `0x004b7c50`, returns with `retn 4`.
- `0x00517d00-0x00517d23`: raw body pushes `420, 480, 20, 160`, calls `0x004b7c50`, returns with `retn 4`.
- `0x00517d23-0x00517d30`: thirteen `0xcc` bytes after the range.

### Dispatcher And Caller Evidence

`decompile 0x00517450` confirms:

- Reads selector from `packet[1]` through `std::_Narrow_char_traits<char,int>::to_char_type(packet + 1)`.
- Uses payload pointer `packet + 2` for all constructors.
- Allocates:
  - `652` bytes for `TextMenuDialog` at `0x00517f30`
  - `644` bytes for `TextInputMenuDialog` at `0x005198e0`
  - `632` bytes for item/spell/argumented menu dialogs at `0x0051a520`, `0x0051b880`, `0x0051ca40`, `0x0051db40`, and `0x0051e9a0`
- Uses `InitRectBounds` style calls through `0x004b7c50`.
- For subtype `4`, adjusts the merchant bounds to `right = left + 425` and `bottom = top + 354`, producing `(100,100,525,454)`.
- The default path leaves the subtype byte in `EAX`.

`decompile 0x00507c90` confirms packet opcode `0x2f` sets a stack `MerchantDialogCreator::vftable` at `0x0061e8e0`, calls `sub_517450` at `0x00507df4`, then discards the return and returns `1`.

`decompile 0x00510320` confirms the smaller route sets the same `MerchantDialogCreator::vftable`, calls `sub_517450` at `0x0051035f`, discards the return, and returns `1`.

`xrefs_to 0x00517450` reports exactly two code refs:

- `0x00507df4` in `sub_507C90`
- `0x0051035f` in `sub_510320`

`xrefs_to 0x0061e8e0` reports the matching vtable data refs at `0x00507ddc` and `0x0051034b`.

This supports a source shape of:

```cpp
void CreateMerchantMenuDialog(const unsigned char *packet);
```

not a source-returned `DialogPane *`. The created pane pointer is a construction side effect; the known caller route does not consume it.

### Wrapper Evidence

`analyze_component` over the dispatcher plus nine wrappers reports:

- `interface_functions`: only `0x517450`
- `internal_only`: all nine wrapper starts
- `internal_call_graph.edges`: empty
- shared global only `___security_cookie`

`xrefs_to` reports zero incoming xrefs for every wrapper start:

- `0x005177a0`
- `0x00517830`
- `0x005178c0`
- `0x00517950`
- `0x005179e0`
- `0x00517a80`
- `0x00517b10`
- `0x00517ba0`
- `0x00517c30`

`find_bytes` for each wrapper VA as little-endian dword also found no absolute pointer/table references.

The wrappers are retained file-local helper functions with duplicated construction bodies, not dispatcher callees. The formal code should not make the dispatcher call the wrappers because that would introduce internal call edges absent from the binary.

### Constructor Target Evidence

Live constructor analyses confirm the factory signatures:

| Constructor | Live prototype shape | Callers from target |
| --- | --- | --- |
| `0x00517f30` `TextMenuDialog` | `this`, `bool`/variant, rect pointer, payload, mode byte | dispatcher `0x5174df/0x51752d`, wrappers `0x517809/0x517899` |
| `0x005198e0` `TextInputMenuDialog` | `this`, `bool hasExtraString`, rect pointer, payload, mode byte | dispatcher `0x51757b/0x5175c9`, wrappers `0x517929/0x5179b9` |
| `0x0051a520` `ServerItemMenuDialog` | `this`, rect pointer, payload, mode byte | dispatcher `0x51762b`, wrapper `0x517a5d` |
| `0x0051b880` `ClientItemMenuDialog` | `this`, rect pointer, payload, mode byte | dispatcher `0x517677`, wrapper `0x517ae7` |
| `0x0051ca40` `ServerSpellMenuDialog` | `this`, rect pointer, payload, mode byte | dispatcher `0x5176c3`, wrapper `0x517b77` |
| `0x0051db40` `ClientSpellMenuDialog` | `this`, rect pointer, payload, mode byte | dispatcher `0x51770b`, wrapper `0x517c07` |
| `0x0051e9a0` `ArgumentedMenuMenuDialog` | `this`, rect pointer, payload, mode byte | dispatcher `0x517750`, wrapper `0x517c97` |

Current support docs already expose `ClientItemMenuDialog`, `ServerSpellMenuDialog`, and `ClientSpellMenuDialog` first drafts as `const Rect& bounds, const unsigned char* payload, unsigned char menuMode`. The target implementation should normalize this target to `RectBounds`/`const RectBounds&` and include support-doc updates for stale `RECT *outRect` and `Rect` aliases.

### Rectangle Type Evidence

Do not keep the target sketch's generic `Rect(...)` spelling.

Support docs resolve the type and helper:

- [UID:0001VP][RectBoundsLayout](../../../by-type/by-struct/RectBoundsLayout.md) documents `RectBounds` as the four-int `left, top, right, bottom` record.
- [UID:00015S][RectGeometryHelpers](../../../by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) documents `0x004b7c50` as `InitRectBounds`.
- Live `decompile 0x004b7c50` writes `a1[0]=left`, `a1[1]=top`, `a1[2]=right`, `a1[3]=bottom`.

Recommended source-facing rectangle names:

| Body | Source-facing helper name | Bounds |
| --- | --- | --- |
| `0x00517cc0-0x00517ce0` | `InitDlgMerc1Bounds` | `(100,100,416,455)` |
| `0x00517ce0-0x00517d00` | `InitDlgMerc2Bounds` | `(100,100,416,328)` |
| `0x00517d00-0x00517d23` | `InitCenteredMerchantDialogBounds` | `(160,20,480,420)` |
| inline subtype `4` adjustment | `InitServerItemMenuBounds` | `(100,100,525,454)` |

`DLGMERC1` and `DLGMERC2` names are supported by the text/input menu resource docs. The third raw body has no current resource-name proof, so do not call it `InitDlgMerc3Bounds` in the formal target. Use `InitCenteredMerchantDialogBounds` and preserve its no-route caveat.

### Raw Rectangle Helper Reachability

`xrefs_to` reports zero incoming xrefs to:

- `0x00517cc0`
- `0x00517ce0`
- `0x00517d00`

`find_bytes` found no absolute VA pointer/table entries for those starts:

- `c0 7c 51 00`
- `e0 7c 51 00`
- `00 7d 51 00`

The raw helpers are exact, source-shaped retained file-local helpers. They can be represented in the formal block because their behavior, source file, and rectangle type are resolved. The report must preserve that they are not live dispatcher callees and currently have no pointer/vtable/table route.

## Source Placement And Ownership Decision

Keep [UID:000238] physically routed through [UID:0000OP][TextMenuDialogs](../../../by-file/TextMenuDialogs.md) now.

Rationale:

- Both known callers install `MerchantDialogCreator` and then invoke the dispatcher.
- The dispatcher owns the cross-family packet subtype switch, but the current source tree already groups merchant/NPC text menu creation under `TextMenuDialogs.cpp`.
- [UID:0000OP][TextMenuDialogs](../../../by-file/TextMenuDialogs.md) already lists [UID:000238] as proposed contents.
- [UID:0000KF][ItemMenuDialogs](../../../by-file/ItemMenuDialogs.md), [UID:0000O2][SpellMenuDialogs](../../../by-file/SpellMenuDialogs.md), and [UID:0000HI][ArgumentedMenuDialogs](../../../by-file/ArgumentedMenuDialogs.md) document [UID:000238] as a shared creator/dispatcher dependency, not their direct owner.
- [UID:0000L9][MerchantDialogPane](../../../by-file/MerchantDialogPane.md) documents the adjacent base-class range and explicitly keeps the factory island separate.

Do not create or move to a new shared `MenuDialogFactory.cpp` during this callback. If the project later introduces a shared menu-dialog factory file, that should be a supervisor-level source-tree/package decision after related owners are coordinated. It is not a blocker for [UID:000238] formal C++ now.

## Exact Formal C++ Insertion Text

Insert this between the existing formal `RECONSTRUCTION_CPP CODE:BEGIN` and `END` lines for [UID:000238].

```cpp
enum MerchantMenuDialogSubtype {
    kTextMenu = 0,
    kTextMenuWithExtraString = 1,
    kTextInputMenu = 2,
    kTextInputMenuWithExtraString = 3,
    kServerItemMenu = 4,
    kClientItemMenu = 5,
    kServerSpellMenu = 6,
    kClientSpellMenu = 8,
    kArgumentedItemMenu = 10
};

namespace {

void InitDlgMerc1Bounds(RectBounds *bounds)
{
    InitRectBounds(bounds, 100, 100, 416, 455);
}

void InitDlgMerc2Bounds(RectBounds *bounds)
{
    InitRectBounds(bounds, 100, 100, 416, 328);
}

void InitCenteredMerchantDialogBounds(RectBounds *bounds)
{
    InitRectBounds(bounds, 160, 20, 480, 420);
}

void InitServerItemMenuBounds(RectBounds *bounds)
{
    InitDlgMerc1Bounds(bounds);
    bounds->right = bounds->left + 425;
    bounds->bottom = bounds->top + 354;
}

} // namespace

void CreateMerchantMenuDialog(const unsigned char *packet)
{
    const unsigned char subtype = packet[1];
    const unsigned char *payload = packet + 2;

    switch (subtype) {
    case kTextMenu:
    {
        RectBounds bounds;
        InitDlgMerc1Bounds(&bounds);
        new TextMenuDialog(false, bounds, payload, 0);
        break;
    }

    case kTextMenuWithExtraString:
    {
        RectBounds bounds;
        InitDlgMerc1Bounds(&bounds);
        new TextMenuDialog(true, bounds, payload, 0);
        break;
    }

    case kTextInputMenu:
    {
        RectBounds bounds;
        InitDlgMerc2Bounds(&bounds);
        new TextInputMenuDialog(false, bounds, payload, 2);
        break;
    }

    case kTextInputMenuWithExtraString:
    {
        RectBounds bounds;
        InitDlgMerc2Bounds(&bounds);
        new TextInputMenuDialog(true, bounds, payload, 2);
        break;
    }

    case kServerItemMenu:
    {
        RectBounds bounds;
        InitServerItemMenuBounds(&bounds);
        new ServerItemMenuDialog(bounds, payload, 0);
        break;
    }

    case kClientItemMenu:
    {
        RectBounds bounds;
        InitDlgMerc1Bounds(&bounds);
        new ClientItemMenuDialog(bounds, payload, 0);
        break;
    }

    case kServerSpellMenu:
    {
        RectBounds bounds;
        InitDlgMerc1Bounds(&bounds);
        new ServerSpellMenuDialog(bounds, payload, 0);
        break;
    }

    case kClientSpellMenu:
    {
        RectBounds bounds;
        InitDlgMerc1Bounds(&bounds);
        new ClientSpellMenuDialog(bounds, payload, 0);
        break;
    }

    case kArgumentedItemMenu:
    {
        RectBounds bounds;
        InitDlgMerc1Bounds(&bounds);
        new ArgumentedMenuMenuDialog(bounds, payload, 0);
        break;
    }

    default:
        break;
    }
}

DialogPane *CreateTextMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new TextMenuDialog(false, bounds, payload, 0);
}

DialogPane *CreateTextMenuDialogWithExtraString(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new TextMenuDialog(true, bounds, payload, 0);
}

DialogPane *CreateTextInputMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc2Bounds(&bounds);
    return new TextInputMenuDialog(false, bounds, payload, 2);
}

DialogPane *CreateTextInputMenuDialogWithExtraString(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc2Bounds(&bounds);
    return new TextInputMenuDialog(true, bounds, payload, 2);
}

DialogPane *CreateServerItemMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitServerItemMenuBounds(&bounds);
    return new ServerItemMenuDialog(bounds, payload, 0);
}

DialogPane *CreateClientItemMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new ClientItemMenuDialog(bounds, payload, 0);
}

DialogPane *CreateServerSpellMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new ServerSpellMenuDialog(bounds, payload, 0);
}

DialogPane *CreateClientSpellMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new ClientSpellMenuDialog(bounds, payload, 0);
}

DialogPane *CreateArgumentedMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new ArgumentedMenuMenuDialog(bounds, payload, 0);
}
```

### Insertion Notes

- The formal block intentionally duplicates dispatcher construction bodies instead of calling the wrapper functions. Live `analyze_component` reports no internal call edges, and every wrapper has zero xrefs.
- `InitCenteredMerchantDialogBounds` is included because `0x00517d00-0x00517d23` is an exact retained raw body inside the target range. It remains unused in the current live routes; document this explicitly in the target prose.
- The old informal sketch should not remain as a C++ block after this insertion. Delete it, or replace it with prose such as: "The former reconstruction sketch was incorporated into the formal reconstruction block; this section now records behavioral notes only."

## Target Changes To Apply If Accepted

Modify only [UID:000238] during the implementation callback unless the supervisor explicitly accepts the listed support updates too.

Required target updates:

- Replace the blank formal block with the exact insertion above.
- Replace the current `## Reconstruction Sketch` code block with prose-only notes or remove the section.
- Update metadata to `COMPLETION:90`, `CONFIDENCE:93`; keep owner/emitter at `0000OP`.
- Update status/source placement to say current physical route remains `TextMenuDialogs.cpp`; no new shared factory file is created now.
- Update the dispatcher role from "returns original subtype byte for unsupported selectors" to "known callers ignore the return; source-level dispatcher should be `void`; unsupported selectors do nothing, while the binary leaves the subtype byte in `EAX` as an ignored artifact."
- Update "Dispatch Mapping" to use the enum names above.
- Update rectangle wording from generic `Rect(...)` / `DLGMERC1 rectangle` to `RectBounds` plus `InitRectBounds`.
- Add raw-helper route evidence:
  - zero xrefs to the three raw starts,
  - zero VA-literal matches for those starts,
  - exact `InitRectBounds` constants,
  - `InitCenteredMerchantDialogBounds` name is descriptive because no current resource-name proof ties `(160,20,480,420)` to `DLGMERC3`.
- Preserve stale/generated-output note: generated tracker/coverage rows may be stale and should refresh through validator only.

## Support Docs To Update If Accepted

These are implementation checklist targets, not report-only edits.

| File | Required support update |
| --- | --- |
| `by-file/TextMenuDialogs.md` | Record that [UID:000238] now has formal first-draft C++ in `TextMenuDialogs.cpp`, using `CreateMerchantMenuDialog`, retained wrapper helpers, `MerchantMenuDialogSubtype`, and `RectBounds`/`InitRectBounds`. |
| `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md` | Replace stale `RECT *outRect` constructor wording for `TextInputMenuDialog` with `const RectBounds& bounds` or explicitly document `RectBounds` as the source type and `RECT` as a stale/historical alias. Add [UID:000238] formal factory names if useful. |
| `by-class/TextInputMenuDialog.md` | Same rectangle-type normalization: `RectBounds`/`const RectBounds&` rather than `RECT *outRect`. Preserve `hasExtraString`, `payload`, and `merchantDialogType`. |
| `by-class/TextMenuDialog.md` | Add source-facing constructor shape if the callback updates support docs: `TextMenuDialog(bool hasExtraString, const RectBounds& bounds, const unsigned char *payload, unsigned char merchantDialogType)`. |
| `by-file/ItemMenuDialogs.md` | Note that [UID:000238] formal factory emits subtype `4/5` creation and that item menu constructor signatures should use `RectBounds`/`menuMode`. No ownership transfer. |
| `by-class/ServerItemMenuDialog.md` and `by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md` | Add/clarify the source constructor shape `ServerItemMenuDialog(const RectBounds& bounds, const unsigned char *payload, unsigned char menuMode)` and preserve the existing `InitializeFromPacket` body as the parser/helper portion, not a separate post-construction call. |
| `by-class/ClientItemMenuDialog.md` and `by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md` | Replace `const Rect& bounds` with `const RectBounds& bounds`, or document `Rect` as a stale alias to be normalized. |
| `by-file/SpellMenuDialogs.md` | Note that [UID:000238] formal factory emits subtype `6/8` creation. No ownership transfer. |
| `by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md` and `by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md` | Replace `const Rect& bounds` with `const RectBounds& bounds`, or document `Rect` as an alias. |
| `by-file/ArgumentedMenuDialogs.md` and `by-class/ArgumentedMenuMenuDialog.md` | Note subtype `10` factory creation through [UID:000238] and source constructor shape using `RectBounds`, but do not change direct owner/emitter away from [UID:0000HI] for the dialog class. |
| `by-file/MerchantDialogPane.md` | Preserve factory/base split: [UID:000238] is adjacent creation/factory code, not base `MerchantDialogPane` method code. |
| `by-type/by-struct/RectBoundsLayout.md` and `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` | No content change required unless adding optional backlink to [UID:000238]. Current docs already resolve `RectBounds` and `InitRectBounds`. |
| vtable/type docs | No required edit; optional note in `MerchantMenuDialogVtableFamily.md` that factory subtype enum names are now documented in [UID:000238]. |

## Rejected Alternatives

| Alternative | Rejection reason |
| --- | --- |
| Keep the informal reconstruction sketch and leave formal block blank. | Violates active formal-code rule; target already clears gate and has an emitter. |
| Emit the old sketch unchanged into the formal block. | It has wrong source type (`DialogPane *` dispatcher), generic `Rect`, no wrappers/raw helper coverage, and `NULL` default behavior not matching the observed ignored-return route. |
| Make dispatcher call the wrapper helpers. | Live component analysis reports no internal call edges; wrappers have zero incoming xrefs. Dispatcher duplicates construction logic. |
| Move source owner/emitter to `ItemMenuDialogs`, `SpellMenuDialogs`, or `ArgumentedMenuDialogs`. | Those are constructor target owners, not the shared packet factory owner. Existing support docs route [UID:000238] to the broader merchant/text menu family. |
| Create `MenuDialogFactory.cpp` now. | Not required for this target; current project structure and owner docs support `TextMenuDialogs.cpp`. Creating a new physical source root is a coordinated supervisor decision, not a blocker. |
| Use `RECT` or generic `Rect` in the target formal block. | Existing `RectBoundsLayout` and `RectGeometryHelpers` docs resolve the project type/helper as `RectBounds`/`InitRectBounds`. |
| Name the third raw helper `InitDlgMerc3Bounds`. | No current doc/resource evidence ties `(160,20,480,420)` to `DLGMERC3`; use descriptive `InitCenteredMerchantDialogBounds`. |
| Treat unsupported subtype as `return NULL`. | Known callers ignore the dispatcher result, and binary default leaves the subtype byte in `EAX`. Source-level `void` with no action is more faithful. |

## Generated And Validator Expectations

No generated files or coverage reports should be edited manually.

Expected after accepted implementation:

- Run file-mode validators for the target and every edited support doc:

> Executable block R001 was removed from this report and preserved verbatim in [000238-MenuDialogFactoryHelpers-source-quality-removed.md](000238-MenuDialogFactoryHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Run additional file-mode validator commands for each support page edited.
- Let validator-owned generated outputs refresh from source metadata. Do not manually edit:
  - `auto-generated/-ag-*`
  - project-level generated files
  - `by-memory/-coverage-report.md`
  - any `-coverage-report.md`
  - validator state/cache

## Report-Only Execution Notes

- No leases were taken during this report-only pass.
- No by-* docs were edited.
- No generated/project-level files, validator state/cache, IDA DB, or coverage reports were edited.
- No validators were run because this was a report-only assignment.
- MCP remained available throughout the report. No `PAUSED_MCP_UNAVAILABLE` condition occurred.

## Implementation Tracking Checklist

Implementation callback proof added by Agent-B010 on 2026-06-28.

- [x] Supervisor accepts this report for implementation. Proof: callback assigned `B010-implement-000238-MenuDialogFactoryHelpers-source-quality-20260628`.
- [x] Lease only the immediate target/support files about to be edited; release leases immediately after each edit/validator batch. Proof: B010 leased only the accepted target/support by-* set for the edit/validator batch. The later `unlease` command reported `Rejected[No active lease]` because the short leases had expired; `tools/leaser/Agents/current_leases.md` then showed no B010 entries.
- [x] Update [UID:000238] metadata to `90/93`, keeping owner/emitter `0000OP`. Proof: `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md` now has `COMPLETION:90`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000OP`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OP`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Insert the exact formal C++ block from this report into [UID:000238]. Proof: the target formal `RECONSTRUCTION_CPP CODE` block now contains `MerchantMenuDialogSubtype`, `CreateMerchantMenuDialog`, retained wrapper helpers, `RectBounds`, and `InitRectBounds` helpers from the accepted insertion text.
- [x] Remove or rewrite the current body-level `## Reconstruction Sketch` code block so no C++ remains outside the formal block. Proof: the old body-only C++ block was replaced with prose explaining that the sketch was incorporated into the formal block.
- [x] Update [UID:000238] prose with the `void` dispatcher decision, ignored default `EAX` artifact, enum names, `RectBounds`/`InitRectBounds`, raw-helper no-xref/no-VA-literal evidence, and TextMenuDialogs source placement. Proof: the target now records `void CreateMerchantMenuDialog`, discarded-return caller evidence, leftover `EAX` as ignored artifact, `MerchantMenuDialogSubtype` names, `RectBounds` helper names/constants, no-xref/no-pointer route evidence, and current `TextMenuDialogs.cpp` placement.
- [x] Update accepted support docs listed above, especially stale `RECT`/`Rect` constructor wording and `ServerItemMenuDialog` constructor shape. Proof: updated `by-file/TextMenuDialogs.md`, `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`, `by-class/TextInputMenuDialog.md`, `by-class/TextMenuDialog.md`, `by-file/ItemMenuDialogs.md`, `by-class/ServerItemMenuDialog.md`, `by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md`, `by-class/ClientItemMenuDialog.md`, `by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md`, `by-file/SpellMenuDialogs.md`, `by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md`, `by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md`, `by-file/ArgumentedMenuDialogs.md`, `by-class/ArgumentedMenuMenuDialog.md`, and `by-file/MerchantDialogPane.md`.
- [x] Preserve rejected alternatives and stale generated-output caveats at target/support detail. Proof: the target still rejects dispatcher-to-wrapper calls, new `MenuDialogFactory.cpp`, item/spell/argumented ownership transfer, generic `Rect`/`RECT`, `InitDlgMerc3Bounds`, and source-level `NULL` return; support docs preserve concrete-class ownership separation.
- [x] Do not edit generated files, project-level generated files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`. Proof: only accepted by-* docs and this Agent-B010 report were manually edited; validators refreshed generated output/tool-owned state.
- [x] Run scoped file-mode validators for every edited by-* file through `tools\validator.py`. Proof: all changed by-* files were validated with `--mode file --apply --queue-timeout 240`; target validator used `--wait-generated`.
- [x] Record validator command IDs/statuses and final touched-file list in the implementation report/checklist proof. Proof: validator command IDs were `000000005112` through `000000005127`, all exit `0`, all `ok=1`; final target command `000000005127` at `2026-06-28T15:11:17-04:00` completed generated refresh and `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp` shows [UID:000238] with code, not an `Empty Emitter Marker`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/000238-MenuDialogFactoryHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/000238-MenuDialogFactoryHelpers-source-quality.md","timestamp":"2026-06-28T15:15:04","uid":"000238"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000238-MenuDialogFactoryHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/000238-MenuDialogFactoryHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000238"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
