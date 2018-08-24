// gcc -I/usr/local/include -L/usr/local/lib/  smi_test.c -o smi_test -lsmi
//.liu ./liu dot3ProviderChannelInfoTable > report2.txt 2>&1
#include <stdio.h>
#include <string.h>
#include <smi.h>

int main(int argc, char *argv[])
{
    SmiNode *smiNode;
    SmiModule *smiModule;
    int i, oidlen, first = 1;
    int result = 0;
    char pPath[256] = {0};
    char pfPath[256] = {0};

    printf("Let's go!!!!\n");
 
    const char *modules[] = {
	// "./LIBSMI-TEST-MIB", 
    NULL
    };

    if (0 == smiInit("smi_test"))
    {
	    fprintf(stderr, "init succ\n");
    }
    else
    {
	    fprintf(stderr, "init fail\n");
    }

    getcwd(pPath, 256);
    strcat(pPath, "/");
    strcat(pPath, "smi.conf");
    printf("filePath: %s\n", pPath);
    if (0 == smiReadConfig(pPath, "test"))
    {
        fprintf(stderr, "read config succ\n");
    }
    else
    {
        fprintf(stderr, "read config fail\n");
    }
    // fprintf(stdout, "path = %s\n\n", smiGetPath());

    for (i = 0; modules[i]; i++) 
    {
        fprintf(stderr, "loading MIB module '%s'\n", modules[i]);
        if (smiLoadModule(modules[i]) == NULL)          // see smi.conf
        {
            fprintf(stderr, "smilint: cannot locate module `%s'\n",
                modules[i]);
            smiExit();
            exit(1);
        }
            fprintf(stderr,"smiLoadModule[%s] ok\n", modules[i]);
    }
    



     // module
    for(smiModule = smiGetFirstModule();smiModule != NULL;\
                    smiModule = smiGetNextModule(smiModule))
    {
        printf("\tModule.name = %s\n", smiModule->name);
        // printf("\tModule.path = %s\n", smiModule->path);
        // printf("\tModule.organization = %s\n", smiModule->organization);
        // printf("\tModule.contactinfo = %s\n", smiModule->contactinfo);
        // printf("\tModule.description = %s\n", smiModule->description);
        // printf("\tModule.reference = %s\n", smiModule->reference);
        // printf("\tModule.language = %d\n", smiModule->language);
        // printf("\tModule.conformance = %d\n", smiModule->conformance);


         // node
        SmiNode *oldNode, *newNode;
        SmiNodekind nodekinds;

        nodekinds =  SMI_NODEKIND_NODE | SMI_NODEKIND_TABLE |
        SMI_NODEKIND_ROW | SMI_NODEKIND_COLUMN | SMI_NODEKIND_SCALAR;
        for(oldNode = smiGetFirstNode(smiModule, nodekinds);
        oldNode;
        oldNode = smiGetNextNode(oldNode, nodekinds))
        {
            printf("oldNode.name = %s\t", oldNode->name);
            printf("oldNode.oid = ");
            for(i = 0;i < (oldNode->oidlen); i++)
            printf(".%d", *(oldNode->oid+i));
            printf("\n");
            newNode = smiGetNodeByOID(oldNode->oidlen, oldNode->oid);
            printf("newNode.name = %s\t", newNode->name);
            printf("newNode.oid = ");
            for(i = 0;i < newNode->oidlen;i++)
            printf(".%d", *(newNode->oid+i));
            printf("\n\n");
        }
    }
    return 0;
    // smiNode = smiGetNode(NULL,argv[1]);
    // printf("\t==>smiNode.name = %s\n",    smiNode->name);
    // printf("\t==>smiNode.oidlen = %d\n",  smiNode->oidlen);
    // printf("\t==>smiNode.oid = %d\n",   *(smiNode->oid));
    // printf("\t==>smiNode.decl = %d\n",    smiNode->decl);
    // printf("\t==>smiNode.access = %d\n",  smiNode->access);
    // printf("\t==>smiNode.status = %d\n",  smiNode->status);
    // printf("\t==>smiNode.format = %s\n",  smiNode->format);
    // printf("\t==>smiNode.description = %s\n",smiNode->description);
    // printf("\t==>smiNode.reference = %s\n",    smiNode->reference);
    // printf("\n*****************************\n");

    smiNode = smiGetNode(NULL, argv[1]);
    SmiModule * smiModule1 = smiGetNodeModule(smiNode);
    {
        printf("\t==>smiModule.name = %s\n",        smiModule1->name);
        printf("\t==>smiModule.path = %s\n",        smiModule1->path);
        printf("\t==>smiModule.organization = %s\n",smiModule1->organization);
        printf("\t==>smiModule.contactinfo = %s\n", smiModule1->contactinfo);
        printf("\t==>smiModule.description = %s\n", smiModule1->description);
        printf("\t==>smiModule.reference = %s\n",   smiModule1->reference);
    }
    SmiType * smiType1 = NULL;
    SmiRange *smiRange1 = NULL;

    smiModule1 = smiGetNodeModule(smiNode);
    if(smiModule1 != NULL)
    {
        printf("\t==>smiModule = %d\n",        smiModule1);
        smiType1 = smiGetNodeType(smiNode);
        if(smiType1 != NULL)
        {
            printf("\t==>smiType = %d\n",        smiType1);
            printf("\t==>smiType.name = %s\n",        smiType1->name);
            printf("\t==>smiType.basetype = %d\n",    smiType1->basetype);
            printf("\t==>smiType.decl = %d\n",        smiType1->decl);
            printf("\t==>smiType.format = %s\n",      smiType1->format);
            printf("\t==>smiType.description = %s\n", smiType1->description);
            printf("\t==>smiType.reference = %s\n",   smiType1->reference);
            printf("\t*****************************\n");

        }
        smiRange1 = smiGetFirstRange(smiNode);
        printf("\t==>smiRange = %d\n",        smiRange1);
        if(smiRange1 != NULL)
        {
            printf("\t==>smiRange = %d\n",    smiRange1);
            printf("\t==>smiRange.minValue = %d\n",    smiRange1->minValue.len);
            printf("\t==>smiRange.maxValue = %d\n",    smiRange1->maxValue.len);
        }                
    }

    for((smiNode = smiGetNode(NULL, argv[1])) &&
	    (oidlen = smiNode->oidlen);
	    smiNode && (first || smiNode->oidlen > oidlen);first = 0)
        {
            printf("\t==>smiNode.name = %s\n",    smiNode->name);
            printf("\t==>smiNode.oidlen = %d\n",  smiNode->oidlen);
            printf("\t==>smiNode.oid = %d\n",   *(smiNode->oid));
            printf("\t==>smiNode.decl = %d\n",    smiNode->decl);
            printf("\t==>smiNode.access = %d\n",  smiNode->access);
            printf("\t==>smiNode.status = %d\n",  smiNode->status);
            printf("\t==>smiNode.format = %s\n",  smiNode->format);
            printf("\t==>smiNode.description = %s\n",smiNode->description);
            printf("\t==>smiNode.reference = %s\n",    smiNode->reference);
            printf("\n\t*****************************\n");

            printf("%*s%-32s\n",
            (smiNode->oidlen - oidlen + 1) * 2, " ",
            smiNode->name ? smiNode->name : "<?>");
            smiNode = smiGetNextNode(smiNode,SMI_NODEKIND_ANY);
        }
    
    // smiNode = smiGetNextNode(smiNode,SMI_NODEKIND_ANY);
    // smiNode = smiGetNodeByOID(smiNode->oidlen, smiNode->oid);
    // printf("\t==>smiNode.name = %s\n",    smiNode->name);
    // printf("\t==>smiNode.oidlen = %d\n",  smiNode->oidlen);
    // printf("\t==>smiNode.oid = %d\n",   *(smiNode->oid));
    // printf("\t==>smiNode.decl = %d\n",    smiNode->decl);
    // printf("\t==>smiNode.access = %d\n",  smiNode->access);
    // printf("\t==>smiNode.status = %d\n",  smiNode->status);
    // printf("\t==>smiNode.format = %s\n",  smiNode->format);
    // printf("\t==>smiNode.description = %s\n",smiNode->description);
    // printf("\t==>smiNode.reference = %s\n",    smiNode->reference);



    exit(0);
}