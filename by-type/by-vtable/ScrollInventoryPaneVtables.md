*** UID:0001YQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollInventoryPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md).
- Source declaration: [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md), finalized as standalone `InventoryScrollPane.h`; the physical tables remain compiler products rather than authored source objects.
- Confidence: strong for vtable bases, constructor-installed object offsets, physical table boundaries, class-specific slot targets, and neighboring `ScrollVolumePane` separation.
- Autogen parent: [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md); final C++ stays blank because the page documents compiler-emitted vtable layout rather than source-ready declarations.
- Rebuild handling: `source-declared/generated-binary`; the source-level `ScrollInventoryPane` declaration and inherited interface order cause the compiler/linker to regenerate these tables. `CANONICAL_OWNER:0000CK` is semantic ownership only; this page is deliberately non-reconstructable, non-emitting, and blank in both formal channels.

## Vtable Bases

| Class view | Base | Constructor store | Notes |
| --- | --- | --- | --- |
| primary | `0x0062402c` | `0x005632b1` | Installed at object offset `+0x00`. |
| secondary `+0xa0` | `0x00624078` | `0x005632b7` | Input/event view installed at object offset `+0xa0` / 160 (Verified with `int_convert.py`). |
| tertiary `+0xa4` | `0x006240a8` | `0x005632c1` | Timer/update-handler view installed at object offset `+0xa4` / 164 (Verified with `int_convert.py`). |

## Physical Table Boundaries

| Span | Interpretation | Boundary evidence |
| --- | --- | --- |
| `0x0062402c-0x00624074` | Primary view slots through the class-specific paint slot at `+0x44` / 68 (Verified with `int_convert.py`). | `get_bytes` shows the paint target `0x005636a0` at `0x00624070`; the following dword at `0x00624074` is transition metadata/data before the secondary view, not another `ScrollInventoryPane` primary virtual. |
| `0x00624078-0x006240a8` | Secondary input/event view as installed at `this + 0xa0`. | Contains the mouse handler at `+0x04` and false-return helper at `+0x08`; the physically following timer target is also reachable as the tertiary view described below. |
| `0x006240a8-0x006240b0` | Tertiary timer/update view as installed at `this + 0xa4`. | Contains two dwords; `+0x04` points to `0x00563660`. The next dword at `0x006240b0` belongs to the neighboring `ScrollVolumePane` vtable cluster metadata, and `0x006240b4` is the next class's primary vtable base. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x0062402c` | `+0x44` / 68 | `0x005636a0` | `OnPaint`, drawing `SLIDEBG`/`SCRBUTT` scrollbar resources (offset verified with `int_convert.py`). |
| secondary `0x00624078` | `+0x04` / 4 | `0x00563460` | Mouse input handler (offset verified with `int_convert.py`). |
| secondary `0x00624078` | `+0x08` / 8 | `0x00563650` | Small false-return virtual adjacent to input/timer handlers (offset verified with `int_convert.py`). |
| secondary/tertiary overlap | physical `0x006240ac` | `0x00563660` | Some table dumps describe this as secondary `+0x34` / 52 because the tables are contiguous; the constructor-installed direct view is tertiary `0x006240a8 + 0x04` / 4 (offsets verified with `int_convert.py`). |
| tertiary `0x006240a8` | `+0x04` / 4 | `0x00563660` | Timer/auto-repeat handler exposed through the tertiary view (offset verified with `int_convert.py`). |

Do not read past `tertiary +0x04` as `ScrollInventoryPane` slots. The next dword at `0x006240b0` is RTTI metadata for the neighboring [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md), not another item-scrollbar virtual.

B003's 2026-06-18 PE scan found no vtable or pointer-table entry for `0x005646b0`. [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) should be modeled as a non-virtual ordinary instance helper; the relevant vtable use inside the body is the inherited Pane invalidation virtual at primary slot `+0x20`, not a route to the reset helper itself.

## Parent And Slot Rationale

[UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) is the semantic type parent because its accepted declaration owns the virtual methods and interface inheritance that regenerate these tables. The class page records the same constructor-installed primary, secondary, and tertiary views, the `0x110` / 272-byte object size (Verified with `int_convert.py`), the complete 19-method inventory-scrollbar map, and the retained raw reset helper.

This vtable page must not emit standalone C++. The accepted source-level requirement is the complete `ScrollInventoryPane` declaration in `InventoryScrollPane.h`; the compiler regenerates the three physical tables. Literal vtable arrays, RTTI/EH records, adjustor thunks, a synthetic destructor, or ownership by `NewInventoryPane.cpp` would confuse compiler products with authored source and are explicitly excluded.

## IDA MCP Evidence

- 2026-06-13 read-only IDA MCP `server_health` reports active `NexusTK.exe`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs` reports the constructor `0x00563260-0x00563301` as `0xa1` / 161 bytes, mouse handler `0x00563460-0x00563641` as `0x1e1` / 481 bytes, false-return helper `0x00563650-0x00563655` as `0x5` / 5 bytes, timer handler `0x00563660-0x00563693` as `0x33` / 51 bytes, paint handler `0x005636a0-0x00563d80` as `0x6e0` / 1760 bytes, and neighboring `ScrollVolumePane` constructor `0x00564710-0x005647b1` as the next scrollbar class start (all decimal values verified with `int_convert.py`).
- Constructor disassembly at `0x005632b1`, `0x005632b7`, and `0x005632c1` installs `0x0062402c`, `0x00624078`, and `0x006240a8`.
- `xrefs_to` each vtable base reports the matching constructor store as the only direct data reference; `xrefs_to 0x006240b4` reports the next constructor store at `0x00564761`, proving the neighboring `ScrollVolumePane` boundary.
- IDA vtable byte reads map the primary paint slot to `0x005636a0` at `0x00624070`, secondary mouse slot to `0x00563460` at `0x0062407c`, secondary false-return slot to `0x00563650` at `0x00624080`, and tertiary timer slot to `0x00563660` at `0x006240ac`.
- `analyze_component` on the class-specific slot targets confirms the mouse handler calls region/drag/timer/invalidation helpers, the false-return helper is a `0x5` / 5-byte leaf (Verified with `int_convert.py`), the timer handler calls the active-state dispatcher and invalidation/update path, and the paint handler calls region/resource/render helpers.
- `get_bytes` confirms the table sequence around `0x0062402c`, `0x00624078`, `0x006240a8`, and `0x006240b0`, including the handoff from the inventory tertiary view to neighboring `ScrollVolumePane` metadata and primary base.
- Historical generated-metadata lead: a stale Wave3 snapshot reported `vtable_count: 0`. Current conclusions use the physical IDA tables and accepted class declaration; obsolete Wave2/Wave3 workflow status is not current authority.
- B003 2026-06-18 source-quality recheck specifically searched for a vtable/pointer-table route to raw reset start `0x005646b0` and found none; two pointer-looking interior hits were rejected as unaligned instruction-byte artifacts, not vtable/data routes. This closes that route as a current owner/reachability hypothesis for [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) without changing the vtable-page score.

## Reconstruction Notes

Model this as the compiler output for the item-inventory instance of the custom inventory scrollbar control. The table layout matches the spell and volume scrollbar siblings, while the authored declaration and all method definitions belong to standalone [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md). NewInventoryPane is a consumer and owner of one instance, not the source owner of these compiler products.

## Score Rationale

| Factor | Current assessment |
| --- | --- |
| Direct parent | Strong: [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) is `89/91`, reconstructable, and routes through standalone [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md) at `90/92`; validator command `000000024570` completed coherent generated CPP/H verification. |
| Vtable ownership | Strong: only the `0x00563260` constructor stores the three bases, and the adjacent `0x006240b4` base is separately stored by the neighboring `ScrollVolumePane` constructor. |
| Slot coverage | Strong for class-specific paint, mouse, false-return, and timer slots, plus inherited/default slots preserved as table entries. |
| Remaining limits | Some inherited Pane slot names are not independently recovered, but they do not require literal vtable source. Standalone placement and the class-specific slots are resolved; formal code remains blank because this page is compiler-output evidence. |

## Changes

- 2026-05-31: Raised completion/confidence from `0/0` to `70/86` and marked the vtable cluster reconstructable.
  - Before: The page contained useful slot notes but was still scored unevaluated.
  - Changed to: Scored as strong-confidence vtable evidence while keeping completion below final audit because inherited pane-interface slot names and final source placement still need broader review.
  - Evidence: IDA MCP `xrefs_to` confirms direct constructor stores to `0x0062402c`, `0x00624078`, and `0x006240a8`; IDA slot mapping ties the class-specific paint, mouse, and timer callbacks to the listed function addresses.
- 2026-06-07: Raised completion from `70` to `74` and attached autogen parent [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md); confidence remains `86`.
  - Before: The page documented the vtable bases and slots but left `AUTOGEN_PARENT_UID` blank.
  - After: The page records the class parent, parent/slot rationale, and no-code policy for this compiler-emitted layout evidence.
  - Evidence: [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) is reconstructable at `80/80`, attached to [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md), and records the same vtable bases, inventory-scrollbar method map, raw reset-helper caveat, and possible fold into [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md).
- 2026-06-13 Agent-A003 Goal 2 type-quality refresh:
  - Before: `COMPLETION:74`, `CONFIDENCE:86`, with correct bases/slots but stale parent-score text and no physical table-boundary audit.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`; parent [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md) retained.
  - Evidence: live read-only IDA MCP reconfirmed constructor stores, sole vtable-base xrefs, class-specific slot targets and sizes, contiguous table bytes, neighboring `ScrollVolumePane` boundary at `0x006240b4`, and support docs now clearing the strict `85/85` gate. Confidence remains below final-audit level because inherited pane-interface slot names and final source-file folding are still open.
- 2026-06-18 B003 support incorporation:
  - Added explicit no-vtable-route note for [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md).
  - Evidence: B003's source-quality pass found no vtable or pointer-table entry to `0x005646b0`; `ResetScrollState` is a non-virtual ordinary instance helper whose body calls the inherited Pane invalidation virtual.
- 2026-08-15 B005 accepted whole-file callback:
  - Raised `86/90` to `94/95`, finalized standalone `InventoryScrollPane.h` as the authored source route, and changed this physical vtable cluster to `RECONSTRUCTABLE:FALSE` with no emitter.
  - Preserved semantic owner [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md), exact bases `0x0062402c/0x00624078/0x006240a8`, constructor stores `0x005632b1/0x005632b7/0x005632c1`, and class-specific slot targets at `0x00624070/0x0062407c/0x00624080/0x006240ac`.
  - Explicitly excluded hand-authored vtable arrays, RTTI/EH, adjustor/destructor inventions, and neighboring `ScrollVolumePane` state; the compiler must regenerate those artifacts from the accepted class declaration.

## Cross-References

- [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md)
- [UID:0001W0][ScrollInventoryPaneLayout](by-type/by-struct/ScrollInventoryPaneLayout.md)
- [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md)
- [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md)
- [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md)
- [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md)
