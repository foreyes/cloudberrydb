/*-------------------------------------------------------------------------
 *
 * gp_resgroupmap.h
 *	  definition of the system "resource group map" relation (gp_resgroupmap).
 *
 *
 *
 * NOTES
 *	  the genbki.sh script reads this file and generates .bki
 *	  information from the DATA() statements.
 *
 *-------------------------------------------------------------------------
 */
#ifndef GP_RESGROUPMAP_H
#define GP_RESGROUPMAP_H

#include "catalog/genbki.h"
#include "catalog/gp_resgroupmap_d.h"

CATALOG(gp_resgroupmap,6461,ResGroupMapRelationId) BKI_SHARED_RELATION
{
	Oid			roleid;	/* OID of the role  */
	Oid			warehouseid; /* Oid of the warehouse */
	Oid			resgroupid; /* Oid of the corresponding resgroup */
} FormData_gp_resgroupmap;


/* GPDB added foreign key definitions for gpcheckcat. */
FOREIGN_KEY(roleid REFERENCES pg_authid(oid));
FOREIGN_KEY(warehouseid REFERENCES gp_warehouse(oid));
FOREIGN_KEY(resgroupid REFERENCES pg_resgroup(oid));

/* ----------------
 *	Form_gp_resgroupmap corresponds to a pointer to a tuple with
 *	the format of gp_resgroupmap relation.
 * ----------------
 */
typedef FormData_gp_resgroupmap *Form_gp_resgroupmap;

DECLARE_UNIQUE_INDEX(gp_resgroupmap_roleid_warehouseid_index, 6462, on gp_resgroupmap using btree(roleid oid_ops, warehouseid oid_ops));
#define ResGroupMapRoleIdWarehouseIdIndexId 6462

#endif   /* GP_RESGROUPMAP_H */
